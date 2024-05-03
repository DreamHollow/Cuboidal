#include "files/ConfigFile.hpp"

cbdl::ConfigFile::ConfigFile(const char* file_location)
{
    if(debug)
    {
        file_debug.debugging = debug;
    }

    file_debug.set_target("ConfigFile");

    std::string system_path;
    std::string append_path = "/config/";

    // First determine if installed to system
    #ifdef _WIN32
    std::filesystem::path cwd = std::filesystem::current_path();
    system_path = cwd.string();
    #endif

    #ifdef __linux__
    system_path = std::filesystem::current_path();
    #endif

    // Check if installed - TODO

    system_path += append_path;

    // Check if config folder actually exists.
    if(!std::filesystem::is_directory(system_path)) // fix this - TODO
    {
        std::cout << file_debug.warn("== BEGIN WARNING ==");
        std::cout << file_debug.warn("Cuboidal said it was pointing to this dir:");
        std::cout << file_debug.warn(system_path);
        std::cout << file_debug.warn("== END WARNING ==");

        std::cout << "Cuboidal failed to find an important configuration file.\n";

        throw std::invalid_argument("ERROR::CONFIGURATIONS::INVALID_DIR");
    }

    // Now append the actual file destination
    system_path += file_location;

    if(!std::filesystem::exists(system_path))
    {
        std::cout << file_debug.warn("== BEGIN WARNING ==");
        std::cout << file_debug.warn("Cuboidal found the configuration directory,");
        std::cout << file_debug.warn("but the requested configuration file was not there.");
        std::cout << file_debug.warn(system_path);
        std::cout << file_debug.warn("== END WARNING ==");

        std::cout << "Cuboidal failed to load an important configuration file.\n";

        throw std::runtime_error("ERROR::CONFIGURATIONS::MISSING_FILE");
    }

    file.open(system_path, std::ios::in);

    if(file.fail() || file.bad())
    {
        std::cout << file_debug.warn("Configuration file failed to load.");

        std::cout << "Cuboidal failed to load in a configuration file for some reason.\n";

        throw std::runtime_error("ERROR::CONFIGURATIONS::LOAD_FAILURE");
    }
}

/// @brief If used in public declaration, forces the file to close.
void cbdl::ConfigFile::close()
{
    if(file.is_open())
    {
        file.close();

        std::cout << file_debug.inform("Configuration file closed.");
    }
}
