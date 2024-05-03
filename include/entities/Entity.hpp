#ifndef ENTITY_HPP_INCLUDED
#define ENTITY_HPP_INCLUDED 1
#include "graphics/Shader.hpp"
#include "Camera.hpp"

/// @brief Entity class for non-block entities.
class Entity
{
public:
    Entity();
    virtual ~Entity();

private:
    Camera camera;
};

#endif
