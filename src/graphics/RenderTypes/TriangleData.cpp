#include "graphics/RenderTypes/TriangleData.hpp"

TriangleData::TriangleData()
{
    data_debug.debugging = debug;
    data_debug.set_target("TriangleData");

    data_debug.inform("Data allocated with no arguments.");

    shader = new Shader("shaders/triangle.vert", "shaders/triangle.frag");

    if(shader == nullptr)
    {
        data_debug.warn("The shader allocation for this object failed.");

        free_data();

        throw std::runtime_error("RENDERTYPE::TRIANGLEDATA::SHADER::NULL");
    }

    float vertices[] =
    {
        0.5f, -0.5f, 0.0f,
        1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.5f, 0.0f,
        0.0f, 0.0f, 1.0f
    };

    glGenVertexArrays(1, &data.VAO); // Generate an array of vertices bound to address of VAO
    glGenBuffers(1, &data.VBO); // Returns buffer object names in *buffers*
    // This call guarantees none of the returned name was not already in use beforehand
    // Directly bound to address of VBO

    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(data.VAO);

    // Bind a named buffer object using the data provided in VBO - GL_ARRAY_BUFFER means vertices
    glBindBuffer(GL_ARRAY_BUFFER, data.VBO);
    // Creates and initializes a buffer object's data store
    // Calls the array buffer from before, gets the vertices data and size, then declares usage.
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // Draw the result

    // position attribute
    // Defines an array of generic vertex attribute data
    // index, size, type, normalized, stride, void * pointer
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    // Enable or disable server-side GL capabilities
    // cap
    glEnableVertexAttribArray(0);

    // color attribute
    // Defines an array of generic vertex attribute data, but with colors
    // Same parameters
    // Void pointer is assigned to (void*)(3 * sizeof(float)) instead of regular (void*)0
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    // GL capabilites cap is set to 1 here
    glEnableVertexAttribArray(1);

    vec = glm::vec3(0.f, 0.f, 1.f);
}

TriangleData::TriangleData(std::vector<GLfloat> points)
{
    data_debug.debugging = debug;
    data_debug.set_target("TriangleData");

    std::cout << data_debug.inform("Object is allocated with vector arguments.");

    shader = new Shader("shaders/triangle.vert", "shaders/triangle.frag");

    if(shader == nullptr)
    {
        std::cout << data_debug.warn("Failed to allocate shader to heap during initialization.");

        throw std::runtime_error("CUBOIDAL::TRIANGLE::SHADER_NULL");
    }

    const uint32_t limit = 18;

    float vertices[18];

    for(size_t i = 0; i < 18; i++)
    {
        vertices[i] = points.at(i);
    }

    // Because the vector is passed as an arg, it doesn't need to clear here.

    glGenVertexArrays(1, &data.VAO); // Generate an array of vertices bound to address of VAO
    glGenBuffers(1, &data.VBO); // Returns buffer object names in *buffers*

    glBindVertexArray(data.VAO);

    glBindBuffer(GL_ARRAY_BUFFER, data.VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // Draw the result

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // color attribute and such
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    vec = glm::vec3(0.f, 0.f, 1.f);
}

TriangleData::~TriangleData()
{
    std::cout << data_debug.inform("went out of scope.");

    free_data();
}

void TriangleData::update(const sf::Time &delta)
{
    //std::cout << "Last delta time: " << time << "\n";

    //glm::vec3 vec(0.f, 0.f, 1.f);
    //glm::mat4 trans = glm::mat4(1.f);
    //trans = glm::rotate(trans, rotation_speed * glm::radians(90.f), vec);
    //trans = glm::rotate(trans, time, glm::vec3(0.f, 0.f, 1.0f));

    shader->setMatrix4("transform", trans);
    //shader->setVector3F("", vec.x, vec.y, vec.z);
}

void TriangleData::render(sf::Window* window)
{
    if(window == nullptr)
    {
        free_data();

        throw std::runtime_error("RENDERTYPE::TRIANGLE_DATA::NO_PTR_TO_WINDOW");
    }

    shader->use();

    glBindVertexArray(data.VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void TriangleData::free_data()
{
    glDeleteVertexArrays(1, &data.VAO);
    glDeleteBuffers(1, &data.VBO);

    if(shader != nullptr)
    {
        delete shader;
    }
}
