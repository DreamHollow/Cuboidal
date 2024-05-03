#ifndef CUBE_TEXTURE_HPP_INCLUDED
#define CUBE_TEXTURE_HPP_INCLUDED 1
#include "Texture.hpp"

class CubeTexture
{
public:
    CubeTexture() = default;
    ~CubeTexture();

private:
    bool loaded = false;
};

#endif
