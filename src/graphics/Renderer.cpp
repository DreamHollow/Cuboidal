#include "graphics/Renderer.hpp"

Renderer::Renderer(sf::Window* window)
{
    if(window == nullptr)
    {
        throw std::runtime_error("FINAL_RENDERER::INIT_FAILED");
    }

    this->window = window;
}

void Renderer::point_to_window(sf::Window* window)
{
    if(window == nullptr)
    {
        throw std::runtime_error("FINAL_RENDERER::INVALID_WINDOW_PTR");
    }

    this->window = window;
}

/// @brief Rendering operation for clearing SFML window.
void Renderer::clear()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}

void Renderer::render(sf::Window* window)
{
    // First clear the GL window
    clear();

    glEnable(GL_DEPTH_TEST);

    // Then run the sub-renderers - TODO

    // Then display to window
    window->display();
}
