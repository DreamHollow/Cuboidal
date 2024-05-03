#include "states/GameState.hpp"

GameState::GameState(StateData* state_data)
{
    this->state_data = state_data;
    this->window = state_data->window;
    //this->renderer = state_data->renderer;
    this->camera = state_data->camera;
    this->mouse = state_data->mouse;
    this->keys = state_data->keys;
    this->states = state_data->states;
    this->quit = false;
    this->paused = false;

    state_debug.debugging = debug;

    state_debug.set_target("GameState");

    std::cout << state_debug.inform("Now in scope.");
}

GameState::~GameState()
{
    std::cout << state_debug.inform("Went out of scope.");

    free_data();
}

void GameState::update(const sf::Time &delta)
{
    world.update(delta);
}

void GameState::handle_keys(const sf::Keyboard::Key &keys, const bool &pressed)
{
    switch(keys)
    {
        case sf::Keyboard::Escape:
        {
            quit = pressed;
            break;
        }
        default:
        {
            break;
        }
    }
}

void GameState::render(sf::Window* window)
{
    // Render in-game stuff here, but Application handles clearing and buffer swaps

    world.render(window);
}

void GameState::free_data()
{

}
