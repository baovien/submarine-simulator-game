#ifndef VIETNAMESE_SPACE_PROGRAM_STATEGAMEOVER_H
#define VIETNAMESE_SPACE_PROGRAM_STATEGAMEOVER_H

#include "../Core/state.h"
#include "../Core/machine.h"
#include "../Core/score.h"
#include "../Core/utilities.h"
#include <map>

class StateGameOver : public States{
public:
    void initialize(sf::RenderWindow *window);

    void update(sf::RenderWindow *window);

    void render(sf::RenderWindow *window);

    void destroy(sf::RenderWindow *window);

    void handleEvent(sf::RenderWindow *window, sf::Event event);

    void reinitialize(sf::RenderWindow *window);
    sf::Clock clock;

private:

    Utilities util;
    sf::Text* gameOverText;
    sf::Text* menuText;
    sf::Text* restartText;
    sf::Text* score;
    sf::Text* congratulationsText;

    sf::Texture* bgTexture;
    sf::Sprite* background;

    sf::RectangleShape* textBox;

    int selected, gameOverScore;

    std::string playerName;
    sf::Text* text;
    bool showCursor, highscoreOrNAH;



};


#endif //VIETNAMESE_SPACE_PROGRAM_STATEGAMEOVER_H
