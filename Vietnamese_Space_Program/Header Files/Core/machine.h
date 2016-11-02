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


private:
    sf::RenderWindow* window;
    States* state;
};

extern Machine machine;
extern bool quitGame;

#endif //VIETNAMESE_SPACE_PROGRAM_MACHINE_H
