#include "state.h"

#ifndef VIETNAMESE_SPACE_PROGRAM_MACHINE_H
#define VIETNAMESE_SPACE_PROGRAM_MACHINE_H


class Machine
{
public:
    Machine();
    ~Machine();

    void setWindow(sf::RenderWindow *window);
    void setState(States *state);
    void update();
    void render();

    bool keyPressed[sf::Keyboard::KeyCount];    //For å beholde tastetrykk til pollEventet i App
    bool keyReleased[sf::Keyboard::KeyCount];

    std::map<const std::string, sf::Keyboard::Key> keybindMap = {{"up", sf::Keyboard::W},
    {"down", sf::Keyboard::S}, {"left", sf::Keyboard::A},{"right", sf::Keyboard::D},{"select", sf::Keyboard::Return},
    {"back", sf::Keyboard::Escape},{"shoot", sf::Keyboard::Space},{"pause", sf::Keyboard::P}};
//    std::map<const std::string, sf::Keyboard::Key>::iterator keybindIterator;

private:
    sf::RenderWindow* window;
    States* state;
};

extern Machine machine;
extern bool quitGame;

#endif //VIETNAMESE_SPACE_PROGRAM_MACHINE_H
