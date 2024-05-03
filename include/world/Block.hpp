#ifndef BLOCK_HPP_INCLUDED
#define BLOCK_HPP_INCLUDED 1
#include "gl_data/OGL.h"

/// @brief Any block type. Textures and properties may vary.
class Block
{
public:
    Block();
    ~Block();

    int integrity; // sort of like "health", determines when a block breaks
private:
    sf::Vector2f position;
};

#endif
