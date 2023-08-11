#pragma once

#include <map>
#include <sstream>

#include "file.hpp"

namespace pIni
{
    class Section
    {
    private:

        std::map<std::string, std::string> m_data;

    public:

        const std::map<std::string, std::string>& GetData() const
        {
            return this->m_data; //Return the desired data content.
        }

    public:

        std::string& operator[](const std::string& key)
        {
            return this->m_data[key]; //Return the desired content.
        }
    };

    class Archive
    {
    private:

        struct
        {
            std::string m_fileName;

            std::map<std::string, Section> m_sections;
        };

    public:

        Archive(const std::string& filename) : m_fileName(filename)
        {
            auto content = std::string(); //Define the content obj.

            auto file = win32::File(filename); //Define file object.

            if (!file.Read(content)) //Check if process can read it.
            {
                return; //Return since it couldn't read the content.
            }

            auto line = std::string(); //Define the line string obj.

            auto section = std::string(); //Define section str obj.

            auto contentStream = std::istringstream(content); //ISS.

            while (std::getline(contentStream, line)) //Loop lines.
            {
                if (line.empty()) //Check if the current line empty.
                {
                    continue; //Ignore line since this one is empty.
                }

                if (line[0] == '[' && line.back() == ']') //Section.
                {
                    section = line.substr(1, line.size() - 2);
                }
                else //The line was not a section but has str saved. 
                {
                    auto delimiterPos = line.find('='); //Find char.

                    if (delimiterPos != std::string::npos) //Vaidate.
                    {
                        this->m_sections[section][line.substr(0, 
                            delimiterPos)] =line.substr(delimiterPos
                                + 1);
                    }
                }
            }
        }

    public:

        void Save()
        {
            auto contentStream = std::ostringstream(); //SS content.

            for (const auto& section : this->m_sections) //Loop all.
            {
                contentStream << "[" << section.first << "]\n";

                for (const auto& entry : section.second.GetData())
                {
                    contentStream << 
                        entry.first << "=" << entry.second << "\n";
                }

                contentStream << "\n"; //Write the escape sequence.
            }

            auto file = win32::File(this->m_fileName); //Set file.

            file.Write(contentStream.str()); //Save changes to file.
        }

        bool Exist(const std::string& section)
        {
            if (this->m_sections.find(
                section) != this->m_sections.end()) //Find section.
            {
                return true; //Return true since the section exists.
            }

            return false; //Return false since section isnt in vec.
        }

    public:

        Section& operator[](const std::string& section)
        {
            return this->m_sections[section]; //Return sect content.
        }
    };
}
