#include "Application.hpp"

Application::Application()
{
    init_vars();
    init_window();
    init_states();
}

Application::~Application()
{
    free_data();
}

/// @brief Initializes configurations, mostly.
void Application::init_vars()
{
    app_debug.debugging = debug;

    app_debug.set_target("Application");

    // Debug Configurations don't work right now,
    // so being verbose is global. Sorry!

    //cbdl::ConfigFile debug_config("debug.cfg");
    //std::string key;

    //debug_config.close();

    cbdl::ConfigFile context_config("context.cfg");
    std::string key;

    // This basically just iterates through.
    while(context_config.file >> key)
    {
        if(key == "antialiasingLevel")
        {
            context_config.file >> config.OGLantiAliasingLevel;
        }
        else if(key == "stencilBits")
        {
            context_config.file >> config.OGLstencilBits;
        }
    }

    std::cout << app_debug.inform("Window configurations done.");

    context_config.close();

    cbdl::ConfigFile window_config("window.cfg");

    while(window_config.file >> key)
    {
        if(key =="window_width")
        {
            window_config.file >> config.window_width;
        }
        else if(key == "window_height")
        {
            window_config.file >> config.window_height;
        }
        else if(key == "fullscreen")
        {
            window_config.file >> config.fullscreen;
        }
        else if(key == "field_of_view")
        {
            window_config.file >> config.field_of_view;
        }
    }

    std::cout << app_debug.inform("Window configurations done.");

    mode.width = config.window_width;
    mode.height = config.window_height;
    mode.bitsPerPixel = config.window_bits;

    window_settings.antialiasingLevel = config.OGLantiAliasingLevel;
    window_settings.majorVersion = config.OGLmajorVersion;
    window_settings.minorVersion = config.OGLminorVersion;
    window_settings.stencilBits = config.OGLstencilBits;

    std::string aliasing = std::to_string(window_settings.antialiasingLevel);
    std::string major = std::to_string(window_settings.majorVersion);
    std::string minor = std::to_string(window_settings.minorVersion);
    std::string stencil = std::to_string(window_settings.stencilBits);

    std::cout << app_debug.inform("=== DEBUG STATEMENT ===");
    std::cout << app_debug.inform("Anti-Aliasing is at level " + aliasing);
    std::cout << app_debug.inform("Using OpenGL Major version " + major);
    std::cout << app_debug.inform("Using OpenGL Minor version " + minor);
    std::cout << app_debug.inform("Stencil bits are set to " + stencil);
    std::cout << app_debug.inform("=== END DEBUG STATEMENT ===");

    window_config.close();
}

void Application::init_window()
{
    if(!mode.isValid())
    {
        std::cout << app_debug.warn("Main application had invalid VideoMode settings.");

        throw std::runtime_error("ERROR::WINDOW::INVALID_VIDEOMODE");
    }

    if(config.fullscreen == true)
    {
        window.create(sf::VideoMode::getDesktopMode(), "Cuboidal",
            sf::Style::Fullscreen, window_settings);
        //window = new sf::Window(sf::VideoMode::getDesktopMode(), "Cuboidal",
            //sf::Style::Fullscreen, window_settings);
    }
    else
    {
        //window = new sf::Window(mode, "Cuboidal", sf::Style::Default, window_settings);
        window.create(mode, "Cuboidal", sf::Style::Default, window_settings);
    }

    /*
    if(window == nullptr)
    {
        std::cout << app_debug.warn("Application window failed to allocate to heap.");

        throw std::runtime_error("ERROR::WINDOW::ALLOCATION_FAILURE");
    }
    */

    // GLAD must start AFTER the window, not before.
    if(!gladLoadGL())
    {
        std::cout << app_debug.warn("Application couldn't initialize GLAD properly.");

        throw std::runtime_error("ERROR::OPENGL::GLAD_FAILED");
    }

    sf::Vector2i window_pos = sf::Vector2i(
        sf::VideoMode::getDesktopMode().width / 3.5,
        sf::VideoMode::getDesktopMode().height / 4
    );

    glViewport(0, 0, window.getSize().x, window.getSize().y);

    std::cout << app_debug.inform("glViewport was assigned to window traits.");

    window.setPosition(window_pos);
}

void Application::init_states()
{
    state_data.window = &this->window;
    state_data.camera = &this->main_camera;
    state_data.keys = this->keys;
    state_data.mouse = this->mouse;
    state_data.states = &this->states;

    states.push(new GameState(&this->state_data));

    if(states.top() == nullptr)
    {
        std::cout << app_debug.warn("The top state wasn't valid; it was a nullptr.");

        free_data();

        throw std::runtime_error("CUBOIDAL::GAMESTATE::FAILED_PUSH");
    }
}

void Application::update_events()
{
    while(window.pollEvent(w_event))
    {
        switch(w_event.type)
        {
            case sf::Event::Closed:
            {
                window.close();
                break;
            }
            case sf::Event::KeyPressed:
            {
                states.top()->handle_keys(w_event.key.code, true);
                break;
            }
            case sf::Event::KeyReleased:
            {
                states.top()->handle_keys(w_event.key.code, false);
                break;
            }
            default: // Any unhandled event
            {
                break;
            }
        }
    }
}

void Application::update(const sf::Time &dt)
{
    if(!states.empty())
    {
        if(window.hasFocus())
        {
            states.top()->update(delta_time);

            if(states.top()->quitting())
            {
                delete this->states.top();
                states.pop();
            }
        }
    }
    else
    {
        window.close();
    }
}

void Application::render()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    glEnable(GL_DEPTH_TEST);

    if(!states.empty())
    {
        states.top()->render(&window);
    }

    window.display();
}

void Application::run()
{
    sf::Clock delta_clock;
    sf::Time time_since_update = sf::Time::Zero;

    while(window.isOpen())
    {
        update_events();
        time_since_update += delta_clock.restart();
        while(time_since_update > time_per_frame)
        {
            time_since_update -= time_per_frame;
            update_events();
            delta_time = time_since_update;
            update(delta_time);
        }

        render();
    }
}

void Application::free_data()
{
    while(!states.empty())
    {
        delete this->states.top();
        states.pop();
    }

    std::cout << app_debug.inform("State stack was cleared.");
}
