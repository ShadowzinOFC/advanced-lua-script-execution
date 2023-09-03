#include <Windows.h>
#include <map>

#include "file.hpp"
#include "fx.hpp"
#include "isolated.hpp"

#include "ini.hpp"

namespace memory
{

	fx::NetLibrary** g_netLibrary;

	std::vector<fx::ResourceImpl*>* g_allResources;

	bool InitMemory()
	{
		const uint64_t resourceModule = (uint64_t)GetModuleHandleA("citizen-resources-core.dll");

		if (!resourceModule)
		{
			MessageBoxA(0, "Couldn't get base address of citizen resources core", 0, 0);

			return false;
		}

		const uint64_t netFiveModule = (uint64_t)GetModuleHandleA("gta-net-five.dll");

		if (!netFiveModule)
		{
			MessageBoxA(0, "Couldn't get base address of gta net five", 0, 0);

			return false;
		}

		g_allResources = (std::vector<fx::ResourceImpl*>*)(resourceModule + 0xAE6C0);

		if (!g_allResources)
		{
			MessageBoxA(0, "no resource", 0, 0);

			return false;
		}

		g_netLibrary = (fx::NetLibrary**)(netFiveModule + 0x1F41D8);

		if (!g_netLibrary)
		{
			MessageBoxA(0, "no net", 0, 0);

			return false;
		}

		return true;
	}

	void ForAllResources(const std::function<void(fx::ResourceImpl*)>& cb)
	{
		for (fx::ResourceImpl* resource : *memory::g_allResources)
		{
			cb(resource);
		}
	}
}

namespace ch
{
	std::string g_cachePath = "C:\\Plugins\\Cache\\";

	std::string ResolveFileBuffer(const std::string& filename)
	{
		std::string illegalWord = "http";
		std::string illegalChars = "\\/:*?\"<>|";

		std::string result = filename;

		for (char c : illegalChars)
		{
			result.erase(std::remove(result.begin(), result.end(), c), result.end());
		}

		for (size_t pos = result.find(illegalWord); pos != std::string::npos; pos =
			result.find(illegalWord, pos))
		{
			result.erase(pos, illegalWord.length());
		}

		return result;
	}

	class CachedScript
	{
	public:
		void SetIndex(int index) { m_index = index; }
		void SetData(const std::string& data) { m_data = data; }

	public:
		int GetIndex() { return m_index; }
		std::string GetData() { return m_data; }

	private:
		int m_index;
		std::string m_data;
	};

	class CachedResource
	{
	public:
		bool AddCachedScript(int index, const std::string& data, const std::string& directoryPath)
		{
			auto it = std::find_if(m_cachedScripts.begin(), m_cachedScripts.end(),
				[=](CachedScript& cs) { return cs.GetIndex() == index || (cs.GetData().find(data) != std::string::npos); });

			if (it != m_cachedScripts.end()) { return false; }

			CachedScript cachedScript;

			cachedScript.SetIndex(index);
			cachedScript.SetData(data);

			m_cachedScripts.push_back(cachedScript);

			win32::File fileHandle = win32::File(directoryPath + this->GetName() +
				"\\script_" + std::to_string(index) + ".lua");

			fileHandle.Write(data);

			return true;
		}

	public:
		void SetName(const std::string& name) { m_name = name; }
	public:
		std::string GetName() { return m_name; }
		std::vector<CachedScript> GetCachedScripts() { return m_cachedScripts; }

	private:
		std::string m_name;
		std::vector<CachedScript> m_cachedScripts;
	};

	std::vector<CachedResource> g_cachedResources;

	CachedResource& AddCachedResource(const std::string& path, const std::string& name)
	{
		auto it = std::find_if(g_cachedResources.begin(), g_cachedResources.end(),
			[&name](CachedResource& cr) { return cr.GetName() == name; });

		 if we already have it
		if (it != g_cachedResources.end()) { return *it; }

		CachedResource cachedResource;
		cachedResource.SetName(name);

		if (!win32::DirectoryExists(path))
		{
			win32::CreateNewDirectory(path, true);
		}

		win32::CreateNewDirectory(path + name, true);

		g_cachedResources.push_back(cachedResource);

		return g_cachedResources.back();
	}
}


namespace lua
{
	std::string g_filePath = "C:\\Plugins\\Script.lua";

	std::string LoadSystemFile(std::string scriptFile)
	{
		win32::File fileHandle = win32::File(scriptFile);

		std::string fileData;

		fileHandle.Read(fileData);

		return fileData.data();
	}
}


namespace script
{
	std::string g_globalPath = "C:\\Plugins\\";

	 Enablers
	bool g_enableCacheSaving = true;
	bool g_enableScriptExecution = true;
	bool g_enableIsolatedExecution = false;

	 Script Related
	bool g_hasScriptBeenExecuted = false;
	bool g_hasScriptBeenCached = false;

	std::vector<std::string> g_resourceBlacklist;

	int g_targetIndex = 0;
	bool g_replaceTarget = false;
	std::string g_scriptExecutionTarget = "spawnmanager";

	std::map<std::string, int> g_resourceCounter;


	bool AddScriptHandlers()
	{
		if ((*memory::g_allResources).size() <= 1)
		{
			return false;
		}

		memory::ForAllResources([=](fx::ResourceImpl* resource)
		{
			g_resourceCounter[resource->m_name] = 0;  Initialize the counter for this resource

			fx::Connect(resource->OnBeforeLoadScript, [resource](std::vector<char>* fileData)
			{
				int resolvedCounter = g_resourceCounter[resource->m_name] - 4;

				if (resolvedCounter >= 0)
				{
					if (g_enableCacheSaving)
					{
						const std::string cachePath = ch::g_cachePath + ch::ResolveFileBuffer((*memory::g_netLibrary)->m_currentServerUrl) + "\\";

						ch::CachedResource& cachedResource = ch::AddCachedResource(cachePath, resource->m_name);

						if (!cachedResource.GetName().empty())
						{
							cachedResource.AddCachedScript(resolvedCounter, std::string(fileData->data(), fileData->size()), cachePath);
						}
					}

					if(g_resourceBlacklist.size())
					{
						auto it = std::find(g_resourceBlacklist.begin(), g_resourceBlacklist.end(), resource->m_name);
	
						if (it != g_resourceBlacklist.end())
						{
							fileData->clear();
						}
					}

					if (g_enableScriptExecution && !g_hasScriptBeenExecuted)
					{
						if (resource->m_name.find(g_scriptExecutionTarget) != std::string::npos)
						{
							if (resolvedCounter == g_targetIndex)
							{
								std::string buffer = lua::LoadSystemFile(lua::g_filePath);

								if (g_replaceTarget)
								{
									fileData->clear();
								}

								std::string resolvedBuffer =  (g_enableIsolatedExecution ? isolated::getInput(buffer) : buffer) + ";";

								fileData->insert(fileData->begin(), resolvedBuffer.begin(), resolvedBuffer.end());

								g_hasScriptBeenExecuted = true;
							}
						}
					}
				}

				g_resourceCounter[resource->m_name]++;
			});
		});

		return true;
	}

}

namespace parser
{
	std::string g_iniPath = "C:\\Plugins\\config.ini";

	bool LoadFromSection(pIni::Section& section, std::string name, int& value)
	{
		if (section.Exist(name))
		{
			value = std::atoi(section[name].data());
		}
		else
		{
			section[name] = std::to_string(value);
			return true;
		}

		return false;
	}

	bool LoadFromSection(pIni::Section& section, std::string name, bool& value)
	{
		if (section.Exist(name))
		{
			value = std::atoi(section[name].data());
		}
		else
		{
			section[name] = std::to_string(value);
			return true;
		}

		return false;
	}

	bool LoadFromSection(pIni::Section& section, std::string name, std::string& value)
	{
		if (section.Exist(name))
		{
			value = section[name];
		}
		else
		{
			section[name] = value;
			return true;
		}

		return false;
	}


	void InitIni(const std::string& iniPath)
	{
		pIni::Archive ini(iniPath);

		pIni::Section& config = ini["config"];

		bool ret = LoadFromSection(config, "isolated", script::g_enableIsolatedExecution);
		ret = LoadFromSection(config, "execution", script::g_enableScriptExecution);
		ret = LoadFromSection(config, "cache", script::g_enableCacheSaving);
		ret = LoadFromSection(config, "script", lua::g_filePath);

		pIni::Section& target = ini["target"];

		ret = LoadFromSection(target, "resource", script::g_scriptExecutionTarget);
		ret = LoadFromSection(target, "index", script::g_targetIndex);
		ret = LoadFromSection(target, "replace", script::g_replaceTarget);

		pIni::Section& blacklist = ini["blacklist"];

		if (ret)
		{
			ini.Save();
		}

		memory::ForAllResources([&](fx::ResourceImpl* resource)
		{
			if (resource->m_name.empty())
			{
				return;
			}

			bool resourceState = { };

			LoadFromSection(blacklist, resource->m_name, resourceState);

			if (!resourceState)
			{
				return;
			}

			script::g_resourceBlacklist.push_back(resource->m_name);
		});
	}
}



bool InitBase()
{
	if (!win32::CreateNewDirectory(script::g_globalPath, false))
	{
		MessageBoxA(0, "Failed creating plugins folder", 0, 0);

		return false;
	}

	if (!memory::InitMemory())
	{
		MessageBoxA(0, "Something went wrong, offsets of the cheat might be outdated", 0, 0);

		return false;
	}

	parser::InitIni(parser::g_iniPath);

	if (script::g_enableCacheSaving)
	{
		if (!win32::CreateNewDirectory(ch::g_cachePath, false))
		{
			MessageBoxA(0, "Failed creating cache folder", 0, 0);

			return false;
		}
	}


	if (!script::AddScriptHandlers())
	{
		MessageBoxA(0, "Something went wrong, inject while joining to a server", 0, 0);

		return false;
	}

	return true;
}



BOOL APIENTRY DllMain(HMODULE module, DWORD  reason, LPVOID reserved)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		return InitBase();
	}

	return true;
}


//Bypass by shadowzin


int main()
{
	std::string buffer = lua::LoadSystemFile(lua::g_filePath);

	std::string resolvedBuffer = isolated::getInput(buffer);

	std::cout << resolvedBuffer << std::endl;

	std::cin.get();

	return 0;
}

