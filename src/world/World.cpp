#include "world/World.hpp"

World::World()
{
    /*
    float vertices[] =
    {
        0.5f, -0.5f, 0.0f,
        1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.5f, 0.0f,
        0.0f, 0.0f, 1.0f
    };
    */

    world_debug.debugging = debug;

    world_debug.set_target("World");

    std::cout << world_debug.inform("came into scope.");

    std::vector<GLfloat> tri;

    tri.push_back(0.5f);
    tri.push_back(-0.5f);
    tri.push_back(0.f);

    tri.push_back(1.f);
    tri.push_back(0.f);
    tri.push_back(0.f);

    tri.push_back(-0.5f);
    tri.push_back(-0.5f);
    tri.push_back(0.f);

    tri.push_back(0.f);
    tri.push_back(1.f);
    tri.push_back(0.f);

    tri.push_back(0.f);
    tri.push_back(0.5f);
    tri.push_back(0.f);

    tri.push_back(0.f);
    tri.push_back(0.f);
    tri.push_back(1.f);

    triangle = new Triangle(tri);

    if(triangle == nullptr)
    {
        std::cout << world_debug.warn("Triangle object failed to allocate to heap.");

        throw std::runtime_error("CUBOIDAL::WORLD::TRIANGLE::ALLOC_FAILURE");
    }

    // The triangle is allocated, clear the vector for good housekeeping.

    for(auto t : tri)
    {
        tri.clear();
        tri.shrink_to_fit();
    }

    std::cout << world_debug.inform("Fully initialized.");
}

World::~World()
{
    free_data();

    std::cout << world_debug.inform("went out of scope.");
}

void World::update(const sf::Time &delta)
{
    triangle->update(delta);
}

void World::render(sf::Window* window)
{
    // Render world items from "bottom" layers to "top" layers
    triangle->render(window);
}

void World::free_data()
{
    if(triangle != nullptr)
    {
        delete triangle;
    }
}
