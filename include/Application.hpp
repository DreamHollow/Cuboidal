#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED 1
#include "states/GameState.hpp"

class Application
{
public:
    Application();
    ~Application();

    void run();

private:
    // Variables
    bool quit;
    bool fullscreen;
    bool pressed;

    // Constants
    const sf::Time time_per_frame = sf::seconds(1.f / 60.f);

    // Init
    void init_vars();
    void init_window();
    void init_states();

    // Update
    void update_events();
    void update(const sf::Time &dt);

    // Render
    void render();

    // Memory Safety
    void free_data();

    // Debugging

    // Objects
    Debugger app_debug;
    sf::Window window;
    sf::ContextSettings window_settings;
    Camera main_camera; // This doesn't work as well for multiplayer
    sf::VideoMode mode;
    sf::Event w_event;
    sf::Time delta_time = sf::Time::Zero;
    sf::Keyboard::Key keys;
    sf::Mouse mouse;
    StateData state_data;
    std::stack<State*> states;
};

#endif
