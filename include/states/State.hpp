#ifndef STATE_HPP_INCLUDED
#define STATE_HPP_INCLUDED 1
#include "world/World.hpp"

struct StateData;

class State
{
public:
    State();
    State(StateData* state_data);
    virtual ~State();

    //virtual void update_mouse() = 0;
    virtual void update(const sf::Time &delta) = 0;
    virtual void handle_keys(const sf::Keyboard::Key &keys, const bool &pressed) = 0;
    virtual void render(sf::Window* window = nullptr) = 0;

    const bool& quitting() const { return this->quit; };

protected:
    // Variables
    bool quit;
    bool paused;
    bool pressed;

    sf::Window* window = nullptr;
    //Renderer* renderer;
    sf::Keyboard::Key keys;
    sf::Mouse mouse;
    Camera* camera;
    StateData* state_data;
    std::stack<State*>* states; // stack of states being pointed to
};

struct StateData
{
    StateData(){};

    bool quit;
    bool paused;
    bool pressed;

    sf::Window* window;
    //Renderer* renderer;
    sf::Keyboard::Key keys;
    sf::Mouse mouse;
    Camera* camera;
    std::stack<State*>* states;
};

#endif
