#ifndef FINAL_RENDERER_HPP_INCLUDED
#define FINAL_RENDERER_HPP_INCLUDED 1
#include "gl_data/OGL.h"

class Renderer
{
public:
    Renderer(sf::Window* window = nullptr);

    void point_to_window(sf::Window* window = nullptr);
    void clear();
    void render(sf::Window* window = nullptr);

    sf::Window* window = nullptr;
};

#endif
