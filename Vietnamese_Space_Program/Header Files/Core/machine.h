#ifndef VIETNAMESE_SPACE_PROGRAM_MACHINE_H
#define VIETNAMESE_SPACE_PROGRAM_MACHINE_H

#include "state.h"

class Machine
{
public:
    Machine();
    ~Machine();

    void setWindow(sf::RenderWindow *window);
    void setState(States *state);
    void update();
    void render();
private:
    sf::RenderWindow* window;
    States* state;
};

extern Machine machine;
extern bool quitGame;

#endif //VIETNAMESE_SPACE_PROGRAM_MACHINE_H
