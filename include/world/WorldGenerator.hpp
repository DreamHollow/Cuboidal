#ifndef WORLD_GENERATOR_HPP_INCLUDED
#define WORLD_GENERATOR_HPP_INCLUDED 1
#include "Block.hpp"
#include "entities/Player.hpp"

/// @brief Generates a world structure based on parameters like noise,
/// otherwise generates a generic flat world.
class WorldGenerator
{
public:
    WorldGenerator() = default;
    ~WorldGenerator();
};

#endif
