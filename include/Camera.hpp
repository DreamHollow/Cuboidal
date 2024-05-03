#ifndef CAMERA_HPP_INCLUDED
#define CAMERA_HPP_INCLUDED 1
#include "Globals.h"
#include "gl_data/OGL.h"

/// @brief Camera used to evaluate player / entity view from a given point.
class Camera
{
public:
    Camera();
    ~Camera();

private:
    // Regular Variables
    float yaw;
    float pitch;
    float roll;

    // Constants
    const glm::vec3 up = glm::vec3(0.f, 1.f, 0.f);

    Debugger camera_debug;
    glm::vec3 position;
    glm::vec3 target;
    glm::vec3 direction; // this is pointed in the opposite direction
    glm::vec3 camera_right;
    glm::vec3 camera_up;
};

#endif
