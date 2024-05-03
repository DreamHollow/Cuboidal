#include "graphics/Texture.hpp"

Texture::Texture(std::string file_data)
{
    texture_file.load_image_file(file_data);

    this->image = &texture_file.image; // Point the local image to the actual file.
}

Texture::~Texture()
{
    if(loaded)
    {
        glDeleteTextures(1, &ID);
    }
}

void Texture::load_image_data(const std::string &file)
{
    // Generate the textures to the ID,
    // then start using the ID immediately.
    glGenTextures(1, &ID);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, ID);

    // The image needs parameters so we give it these
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->getSize().x,
        image->getSize().y, 0, GL_RGBA, GL_UNSIGNED_BYTE, image->getPixelsPtr());
    glGenerateMipmap(GL_TEXTURE_2D); // for optimization
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
        GL_NEAREST_MIPMAP_NEAREST);

    // Wrap and CLAMP the image
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 1);

    loaded = true;
}
