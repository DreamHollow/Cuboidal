#include "states/State.hpp"

State::State()
{

}

State::State(StateData* state_data)
{
    // States pass along data to each other in this format
    // they all intricately understand that the given values
    // are basically just direct references to some specific object.

    this->state_data = state_data;
    this->window = state_data->window;
    //this->renderer = state_data->renderer;
    this->camera = state_data->camera;
    this->mouse = state_data->mouse;
    this->keys = state_data->keys;
    this->states = state_data->states;
    this->quit = false;
    this->paused = false;
}

State::~State()
{

}
