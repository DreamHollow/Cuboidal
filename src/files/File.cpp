#include "files/File.hpp"

cbdl::File::File(const char* location)
{
    if(location)
    {
        // Do nothing, this isn't configured yet.
    }
}

cbdl::File::~File()
{
    if(file.is_open())
    {
        file.close();

        std::cout << file_debug.inform("went out of scope.");
    }
    else
    {
        std::cout << file_debug.inform("was already closed and going out of scope.");
    }
}
