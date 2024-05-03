#ifndef TRIANGLE_HPP_INCLUDED
#define TRIANGLE_HPP_INCLUDED 1
#include "Entity.hpp"

/// @brief The actual rendering information for a triangle.
class Triangle
{
public:
    Triangle();
    Triangle(std::vector<GLfloat> points);
    ~Triangle();

    void update(const sf::Time &delta);
    void render(sf::Window* window = nullptr);

    Shader* shader = nullptr;
    OGL::Data data;

private:
    // Variables
    //float rotation_speed = 0.f;

    // Memory
    void free_data();

    // Objects
    Debugger data_debug;
    glm::vec3 vec; //(0.f, 0.f, 1.f);
    glm::mat4 trans = glm::mat4(1.f);
};
#endif
