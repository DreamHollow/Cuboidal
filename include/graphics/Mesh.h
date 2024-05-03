#ifndef MESH_H_INCLUDED
#define MESH_H_INCLUDED 1
#include "gl_data/OGL.h"

/// @brief Mesh structure in it's simplest form.
struct Mesh
{
    std::vector<GLfloat> vertex_pos;
    std::vector<GLfloat> texture_coords;
    std::vector<GLuint> indices;
};

#endif
