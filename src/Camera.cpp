#include "Camera.hpp"

// Camera data needs a way to be passed from it's starting point to the main app!!!
// MASSIVE TODO

Camera::Camera()
{
    camera_debug.debugging = debug;
    camera_debug.set_target("Camera");

    std::cout << camera_debug.inform("Initialized.");

    position = glm::vec3(0.f, 0.f, 3.f);
    target = glm::vec3(0.f, 0.f, 0.f);
    direction = glm::normalize(position - target);
    camera_right = glm::normalize(glm::cross(up, direction));
    camera_up = glm::cross(direction, camera_right);
}

Camera::~Camera()
{
    std::cout << camera_debug.inform("went out of scope.");
}
