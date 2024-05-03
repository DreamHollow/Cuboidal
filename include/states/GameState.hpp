#ifndef GAMESTATE_HPP_INCLUDED
#define GAMESTATE_HPP_INCLUDED 1
#include "State.hpp"

class GameState : public State
{
public:
    GameState(StateData* state_data);
    ~GameState() override;

    void update(const sf::Time &delta);
    void render(sf::Window* window = nullptr) override;
    void handle_keys(const sf::Keyboard::Key &keys, const bool &pressed);

private:
    // Memory
    void free_data();

    // Objects
    Debugger state_debug;
    World world;
};

#endif
