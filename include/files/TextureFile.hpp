#ifndef TEXTURE_FILE_HPP
#define TEXTURE_FILE_HPP 1
#include "File.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

namespace cbdl
{
    /// @brief Actual texture file data being loaded in.
    class TextureFile : public File
    {
    public:
        TextureFile();
        TextureFile(const char* location);

        void close();
        void load_image_file(const std::string file);

        sf::Image image;

    private:
        // Variables
        const std::string res_folder = "assets/textures/";
        std::string file_data;

        // Objects
        //Debugger texfile_debug;
    };
}

#endif
