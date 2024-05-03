#ifndef SHADER_HPP_INCLUDED
#define SHADER_HPP_INCLUDED 1
#include <stack>
#include <fstream>
#include <sstream>
#include "gl_data/OGL.h"
#include "files/ConfigFile.hpp"
#include "Globals.h"

/// @brief Compiled shader using data from vertex and fragment data.
class Shader
{
public:
    Shader() = default;
    Shader(const char* vertexPath, const char *fragmentPath);
    virtual ~Shader();

    // Variables
    unsigned int ID;

    // Functions
    void use();
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void setVector2F(const std::string &name, float x, float y) const;
    void setVector3F(const std::string &name, float x, float y, float z) const;
    void setVector4F(const std::string &name, float x, float y, float z, float a) const;
    void setMatrix4(const std::string &name, const glm::mat4 &matrix) const;

private:
    Debugger shader_debug;
};

#endif
