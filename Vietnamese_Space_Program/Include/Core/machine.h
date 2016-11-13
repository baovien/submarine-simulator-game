#ifndef VIETNAMESE_SPACE_PROGRAM_MACHINE_H
#define VIETNAMESE_SPACE_PROGRAM_MACHINE_H

#include "state.h"

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
    std::map<const std::string, std::pair<std::string, int>> keybindMap = {{"up", std::make_pair("W" , sf::Keyboard::W)},
                                                           {"down",   std::make_pair("S" , sf::Keyboard::S)},
                                                           {"left",   std::make_pair("A" , sf::Keyboard::A)},
                                                           {"right",  std::make_pair("D" , sf::Keyboard::D)},
                                                           {"select", std::make_pair("Return" , sf::Keyboard::Return)},
                                                           {"back",   std::make_pair("Escape" , sf::Keyboard::Escape)},
                                                           {"shoot",  std::make_pair("Space" , sf::Keyboard::Space)},
                                                           {"pause",  std::make_pair("P" , sf::Keyboard::P)}};
private:
    sf::RenderWindow* window;
    States* state;
    int gameOverScore;

};

extern Machine machine;
extern bool quitGame;

#endif //VIETNAMESE_SPACE_PROGRAM_MACHINE_H
