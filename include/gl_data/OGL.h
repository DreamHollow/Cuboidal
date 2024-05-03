#ifndef OPENGL_RENDER_DATA_H_INCLUDED
#define OPENGL_RENDER_DATA_H_INCLUDED 1
#include "glad/glad.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

namespace OGL
{
    struct Data
    {
        Data(){};

        GLuint VAO;
        GLuint VBO;
        GLuint EBO;

        void reset()
        {
            VAO = 0;
            VBO = 0;
            EBO = 0;
        }
    };
}

#endif
