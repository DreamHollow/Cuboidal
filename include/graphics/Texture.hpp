#ifndef TEXTURE_HPP_INCLUDED
#define TEXTURE_HPP_INCLUDED 1
#include <string>
#include "gl_data/OGL.h"
#include "files/TextureFile.hpp"

/// @brief Standard texture for mapping to a mesh. Only for one surface, not cubes.
class Texture
{
public:
    Texture() = default;
    Texture(std::string file_data);
    ~Texture();

    void load_image_data(const std::string &file);

private:
    // Variables
    bool loaded = false; // Textures should never delete if not loaded, creates segfaults.
    GLuint ID;

    // Objects
    cbdl::TextureFile texture_file;
    sf::Image* image = nullptr;
};

#endif
