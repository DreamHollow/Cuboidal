#ifndef CONFIGURATIONS_H_INCLUDED
#define CONFIGURATIONS_H_INCLUDED 1
#include <iostream>

struct Config
{
    Config()
    {
        fullscreen = false;
        window_width = 800;
        window_height = 600;
        field_of_view = 45;
    }

    // Binary
    bool fullscreen;
    uint32_t window_width;
    uint32_t window_height;
    const uint32_t window_bits = 32;
    uint32_t field_of_view;
    uint32_t OGLantiAliasingLevel;
    const uint32_t OGLmajorVersion = 4;
    const uint32_t OGLminorVersion = 6;
    uint32_t OGLstencilBits;

    // Debugging
    //bool verbose = false; // disabled for now
};

#endif
