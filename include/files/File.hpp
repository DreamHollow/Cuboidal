#ifndef FILE_HPP_INCLUDED
#define FILE_HPP_INCLUDED 1
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <sstream>
#include "Globals.h"

namespace cbdl
{
    class File
    {
    public:
        File() = default;
        File(const char* location);
        virtual ~File();

        virtual void close() = 0;

        std::fstream file; // made public so it's easier to interact with

    protected:
        Debugger file_debug;
    };
}

#endif
