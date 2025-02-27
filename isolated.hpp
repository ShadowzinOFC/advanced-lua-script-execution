#pragma once
#include <algorithm>

namespace isolated
{
		inline std::vector<uint8_t> isoBytes =
	{
		0x6C, 0x6F, 0x63, 0x61, 0x6C, 0x20, 0x6D, 0x61, 0x67, 0x69, 0x63, 0x5F, 0x63, 0x6F,
		0x64, 0x65, 0x20, 0x3D, 0x20, 0x5B, 0x3D, 0x3D, 0x3D, 0x3D, 0x3D, 0x3D, 0x3D, 0x3D,
		0x3D, 0x3D, 0x3D, 0x3D, 0x5B, 0x72, 0x65, 0x70, 0x6C, 0x7A, 0x5D, 0x3D,
		0x3D, 0x3D, 0x3D, 0x3D, 0x3D, 0x3D, 0x3D, 0x3D, 0x3D, 0x3D, 0x3D, 0x5D, 0x20, 0x6C,
		0x6F, 0x63, 0x61, 0x6C, 0x20, 0x66, 0x75, 0x6E, 0x63, 0x74, 0x69, 0x6F, 0x6E, 0x20,
		0x63, 0x6F, 0x70, 0x79, 0x5F, 0x74, 0x61, 0x62, 0x6C, 0x65, 0x28, 0x74, 0x61, 0x62,
		0x6C, 0x65, 0x29, 0x20, 0x6C, 0x6F, 0x63, 0x61, 0x6C, 0x20, 0x74, 0x20, 0x3D, 0x20,
		0x7B, 0x7D, 0x20, 0x66, 0x6F, 0x72, 0x20, 0x6B, 0x2C, 0x20, 0x76, 0x20, 0x69, 0x6E,
		0x20, 0x70, 0x61, 0x69, 0x72, 0x73, 0x28, 0x74, 0x61, 0x62, 0x6C, 0x65, 0x29, 0x20,
		0x64, 0x6F, 0x20, 0x6C, 0x6F, 0x63, 0x61, 0x6C, 0x20, 0x76, 0x5F, 0x74, 0x79, 0x70,
		0x65, 0x20, 0x3D, 0x20, 0x74, 0x79, 0x70, 0x65, 0x28, 0x76, 0x29, 0x20, 0x69, 0x66,
		0x20, 0x76, 0x5F, 0x74, 0x79, 0x70, 0x65, 0x20, 0x3D, 0x3D, 0x20, 0x22, 0x74, 0x61,
		0x62, 0x6C, 0x65, 0x22, 0x20, 0x61, 0x6E, 0x64, 0x20, 0x74, 0x61, 0x62, 0x6C, 0x65,
		0x20, 0x7E, 0x3D, 0x20, 0x76, 0x20, 0x74, 0x68, 0x65, 0x6E, 0x20, 0x74, 0x5B, 0x6B,
		0x5D, 0x20, 0x3D, 0x20, 0x63, 0x6F, 0x70, 0x79, 0x5F, 0x74, 0x61, 0x62, 0x6C, 0x65,
		0x28, 0x76, 0x29, 0x20, 0x65, 0x6C, 0x73, 0x65, 0x20, 0x74, 0x5B, 0x6B, 0x5D, 0x20,
		0x3D, 0x20, 0x76, 0x20, 0x65, 0x6E, 0x64, 0x20, 0x65, 0x6E, 0x64, 0x20, 0x72, 0x65,
		0x74, 0x75, 0x72, 0x6E, 0x20, 0x74, 0x20, 0x65, 0x6E, 0x64, 0x20, 0x6C, 0x6F, 0x63,
		0x61, 0x6C, 0x20, 0x67, 0x6C, 0x6F, 0x62, 0x61, 0x6C, 0x5F, 0x69, 0x6E, 0x64, 0x65,
		0x78, 0x20, 0x3D, 0x20, 0x67, 0x65, 0x74, 0x6D, 0x65, 0x74, 0x61, 0x74, 0x61, 0x62,
		0x6C, 0x65, 0x28, 0x5F, 0x47, 0x29, 0x2E, 0x5F, 0x5F, 0x69, 0x6E, 0x64, 0x65, 0x78,
		0x20, 0x6C, 0x6F, 0x63, 0x61, 0x6C, 0x20, 0x73, 0x63, 0x72, 0x69, 0x70, 0x74, 0x5F,
		0x65, 0x6E, 0x76, 0x20, 0x3D, 0x20, 0x73, 0x65, 0x74, 0x6D, 0x65, 0x74, 0x61, 0x74,
		0x61, 0x62, 0x6C, 0x65, 0x28, 0x63, 0x6F, 0x70, 0x79, 0x5F, 0x74, 0x61, 0x62, 0x6C,
		0x65, 0x28, 0x5F, 0x47, 0x29, 0x2C, 0x20, 0x7B, 0x5F, 0x5F, 0x69, 0x6E, 0x64, 0x65,
		0x78, 0x20, 0x3D, 0x20, 0x66, 0x75, 0x6E, 0x63, 0x74, 0x69, 0x6F, 0x6E, 0x28, 0x74,
		0x2C, 0x6B, 0x29, 0x20, 0x69, 0x66, 0x20, 0x6B, 0x20, 0x3D, 0x3D, 0x20, 0x22, 0x5F,
		0x47, 0x22, 0x20, 0x74, 0x68, 0x65, 0x6E, 0x20, 0x72, 0x65, 0x74, 0x75, 0x72, 0x6E,
		0x20, 0x74, 0x20, 0x65, 0x6E, 0x64, 0x20, 0x72, 0x65, 0x74, 0x75, 0x72, 0x6E, 0x20,
		0x67, 0x6C, 0x6F, 0x62, 0x61, 0x6C, 0x5F, 0x69, 0x6E, 0x64, 0x65, 0x78, 0x28, 0x74,
		0x2C, 0x6B, 0x29, 0x20, 0x65, 0x6E, 0x64, 0x7D, 0x29, 0x20, 0x20, 0x6C, 0x6F, 0x63,
		0x61, 0x6C, 0x20, 0x66, 0x6E, 0x2C, 0x20, 0x65, 0x72, 0x72, 0x20, 0x3D, 0x20, 0x6C,
		0x6F, 0x61, 0x64, 0x28, 0x6D, 0x61, 0x67, 0x69, 0x63, 0x5F, 0x63, 0x6F, 0x64, 0x65,
		0x2C, 0x20, 0x22, 0x40, 0x46, 0x75, 0x73, 0x65, 0x49, 0x73, 0x6F, 0x6C, 0x61, 0x74,
		0x65, 0x64, 0x2F, 0x53, 0x63, 0x72, 0x69, 0x70, 0x74, 0x2E, 0x6C, 0x75, 0x61, 0x22,
		0x2C, 0x20, 0x6E, 0x69, 0x6C, 0x2C, 0x20, 0x73, 0x63, 0x72, 0x69, 0x70, 0x74, 0x5F,
		0x65, 0x6E, 0x76, 0x29, 0x20, 0x6C, 0x6F, 0x63, 0x61, 0x6C, 0x20, 0x5F, 0x70, 0x72,
		0x69, 0x6E, 0x74, 0x20, 0x3D, 0x20, 0x70, 0x72, 0x69, 0x6E, 0x74, 0x20, 0x69, 0x66,
		0x20, 0x66, 0x6E, 0x20, 0x74, 0x68, 0x65, 0x6E, 0x20, 0x78, 0x70, 0x63, 0x61, 0x6C,
		0x6C, 0x28, 0x66, 0x6E, 0x2C, 0x20, 0x66, 0x75, 0x6E, 0x63, 0x74, 0x69, 0x6F, 0x6E,
		0x28, 0x65, 0x78, 0x29, 0x20, 0x5F, 0x70, 0x72, 0x69, 0x6E, 0x74, 0x28, 0x22, 0x5B,
		0x5E, 0x35, 0x49, 0x53, 0x4F, 0x4C, 0x41, 0x54, 0x45, 0x44, 0x5E, 0x30, 0x5D, 0x20,
		0x5E, 0x31, 0x53, 0x63, 0x72, 0x69, 0x70, 0x74, 0x20, 0x65, 0x72, 0x72, 0x6F, 0x72,
		0x3A, 0x20, 0x22, 0x20, 0x2E, 0x2E, 0x65, 0x78, 0x29, 0x20, 0x65, 0x6E, 0x64, 0x29,
		0x20, 0x65, 0x6C, 0x73, 0x65, 0x20, 0x5F, 0x70, 0x72, 0x69, 0x6E, 0x74, 0x28, 0x22,
		0x5B, 0x5E, 0x35, 0x49, 0x53, 0x4F, 0x4C, 0x41, 0x54, 0x45, 0x44, 0x5E, 0x30, 0x5D,
		0x20, 0x5E, 0x31, 0x45, 0x72, 0x72, 0x6F, 0x72, 0x20, 0x70, 0x61, 0x72, 0x73, 0x69,
		0x6E, 0x67, 0x20, 0x73, 0x63, 0x72, 0x69, 0x70, 0x74, 0x3A, 0x20, 0x22, 0x20, 0x2E,
		0x2E, 0x65, 0x72, 0x72, 0x29, 0x20, 0x65, 0x6E, 0x64
	};


	std::string getInput(const std::string& script)
	{
		auto tempScriptBytes = isoBytes; //Define the temporary iso script bytes object.

		const auto replaceBytes = std::vector<uint8_t>{ 0x72, 0x65, 0x70, 0x6C, 0x7A };

		const auto pos = std::search(tempScriptBytes
			.begin(), tempScriptBytes.end(), replaceBytes.begin(), replaceBytes.end());

		tempScriptBytes.erase(pos, pos + replaceBytes.size()); //Erase the replz bytes.
		tempScriptBytes.insert(pos, script.begin(), script.end()); //Insert the script.

		return std::string(tempScriptBytes.begin(), tempScriptBytes.end()); //Ret buff.
	}
}
