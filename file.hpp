#pragma once

#include <string>
#include <Windows.h>

namespace win32
{
    class File
    {
    private:

        std::string fileName = nullptr;

    public:

        ~File() = default;
        File(const std::string& fileName) : fileName(fileName) {}

    public:

        bool Read(std::string& content)
        {
            auto fileHandle = HANDLE(); //Define the file handle obj.

            if (!this->GetFileHandle(OPEN_ALWAYS, fileHandle))
            {
                return false; //Return false since handle is invalid.
            }

            const auto fileSize = GetFileSize( //Retrieve file size.
                fileHandle, nullptr);

            auto buffer = new char[fileSize]; //Setup the buffer ptr.

            auto bytesRead = DWORD(); //Define readed bytes size obj.

            const auto result = ReadFile(fileHandle, buffer,
                fileSize, &bytesRead, nullptr);

            CloseHandle(fileHandle); //Close the created file handle.

            if (result != 0) //Check if the readed results were valid.
            {
                content.assign(buffer, fileSize); //Assign buf to str.
            }

            delete[] buffer; //Delete the assigned buffer for content.

            return result != 0; //Check if the file results are valid.
        }

        bool Write(const std::string& content)
        {
            auto fileHandle = HANDLE(); //Define the file handle obj.

            if (!this->GetFileHandle(CREATE_ALWAYS, fileHandle))
            {
                return false; //Return false since handle is invalid.
            }

            auto bytesWritten = DWORD(); //Define written bytes object.

            const auto result = WriteFile(fileHandle,
                content.c_str(), content.size(), &bytesWritten, NULL);

            CloseHandle(fileHandle); //Close the created file handle.

            return result != 0; //Check if the file results are valid.
        }

    private:

        bool GetFileHandle(DWORD flag, HANDLE& handle)
        {
            handle = CreateFileA(this->fileName.c_str(), 0xc0000000,
                0, nullptr, flag, FILE_ATTRIBUTE_NORMAL, nullptr);

            if (handle == INVALID_HANDLE_VALUE) //Validate the handle.
            {
                return false; //Return false the handle is not valid.
            }

            return true; //Return true since all went as we expected.
        }
    };


    inline bool FileExists(const std::string& path)
    {
        const auto attributes = GetFileAttributesA(path.data()); //Get.

        return (attributes != INVALID_FILE_ATTRIBUTES)
            && !(attributes & FILE_ATTRIBUTE_DIRECTORY); //Check file.
    }

    inline bool DirectoryExists(const std::string& path)
    {
        const auto attributes = GetFileAttributesA(path.data()); //Get.

        if (attributes == INVALID_FILE_ATTRIBUTES) //Validate file att.
        {
            return false; //Return false since invalid file attributes.
        }

        return (attributes & FILE_ATTRIBUTE_DIRECTORY); //Check direct.
    }

    inline bool CreateNewDirectory(
        const std::string& path, bool createAlways = false)
    {
        if (DirectoryExists(path.data()) && createAlways == 0) //Check.
        {
            return true; //Return false since the directory is active.
        }

        return CreateDirectoryA(path.c_str(), nullptr) != 0; //Make it.
    }
    inline void delay(int milliseconds)
    {
        Sleep(milliseconds);
    }

    inline void clear()
    {
        system("cls");
    }

    inline void pause()
    {
        system("pause");
    }
}
