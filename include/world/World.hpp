#ifndef WORLD_HPP_INCLUDED
#define WORLD_HPP_INCLUDED 1
#include "entities/Triangle.hpp"
#include "WorldGenerator.hpp"

class World
{
public:
    World();
    ~World();

    void update(const sf::Time &delta);
    void render(sf::Window* window = nullptr);

private:
    // Memory
    void free_data();

    // Objects
    Debugger world_debug;
    Triangle* triangle = nullptr;
    Player player;
};

#endif
