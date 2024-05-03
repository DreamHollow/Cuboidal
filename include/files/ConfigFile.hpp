#ifndef CONFIG_FILE_HPP_INCLUDED
#define CONFIG_FILE_HPP_INCLUDED 1
#include "File.hpp"

namespace cbdl
{
    /// @brief Read-only filetype that just loads in config data.
    class ConfigFile : public File
    {
    public:
        ConfigFile(const char* location);

        void close();

        //std::ifstream file; // This can be public since it makes file operations easier.

    private:
        // Functions
        //bool is_installed();

        // Objects
        Debugger file_debug;
    };
}

#endif
