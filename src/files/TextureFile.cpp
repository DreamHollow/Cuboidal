#include "files/TextureFile.hpp"

/// @brief Texture file initialized with no expected parameters.
cbdl::TextureFile::TextureFile()
{
    file_debug.debugging = debug;

    file_debug.set_target("TextureFile");
    file_debug.inform("Not pointing to any file on construction.");
}

/// @brief Points to a file name then loads the file based on resource data.
/// @param image_file
cbdl::TextureFile::TextureFile(const char* location)
{
    this->file_data = res_folder + location;

    file_debug.debugging = debug;

    file_debug.set_target("TextureFile");
    std::cout << file_debug.inform("Texture data pointing at location:");
    std::cout << file_debug.inform(file_data.c_str());

    if(!image.loadFromFile(file_data))
    {
        std::cout << file_debug.warn("The file being pointed to failed to load.");

        throw std::runtime_error("CUBOIDAL::TEXTUREFILE::LOAD_FAILURE");
    }
}

void cbdl::TextureFile::close()
{
    if(file.is_open())
    {
        file.close();

        file_debug.inform("was closed.");
    }
}

/// @brief This must be called soon after using TextureFile or Image will be empty.
/// @param file
void cbdl::TextureFile::load_image_file(const std::string file)
{
    this->file_data = res_folder + file;

    std::cout << file_debug.inform("File set to");
    std::cout << file_debug.inform(file_data.c_str());

    if(!image.loadFromFile(file_data))
    {
        std::cout << file_debug.warn("The file that was being pointed to failed to load.");

        throw std::runtime_error("CUBOIDAL::TEXTUREFILE::LOAD_FAILURE");
    }
}
