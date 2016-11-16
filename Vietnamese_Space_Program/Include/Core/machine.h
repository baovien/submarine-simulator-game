#ifndef VIETNAMESE_SPACE_PROGRAM_MACHINE_H
#define VIETNAMESE_SPACE_PROGRAM_MACHINE_H

#include "state.h"
#include "../../Include/Entities/buttons.h"

class Machine {
public:
    Machine();

    ~Machine();

    void setWindow(sf::RenderWindow *window);

    void setState(States *state);

    void reinitialize();

    void update();

    void render();

    void eventHandler(sf::Event event);

    void setGameOverScore(int playerScore);
    int getGameOverScore() const;

    //For å beholde museklikk til pollEventet i App
    sf::Vector2i mouseClick;

    //Brukes i forbindelse med keybinds
    std::map<const std::string, std::pair<std::string, int>> *keybindMap;



private:
    sf::RenderWindow* window;
    States* state;
    int gameOverScore;

};
extern Machine machine;
extern bool quitGame;

#endif //VIETNAMESE_SPACE_PROGRAM_MACHINE_H
