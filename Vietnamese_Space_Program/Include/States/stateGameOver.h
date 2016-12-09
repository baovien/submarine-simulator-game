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
    sf::Text* score;
    sf::Text* congratulationsText;
    sf::Text* congratulationsText2;
    sf::Text* whatAShameText;

    sf::Texture* bgTexture;
    sf::Sprite* background;

    sf::RectangleShape* textBox;

    int selected, gameOverScore;

    std::string playerName;
    sf::Text* text;
    sf::Text* clickToActivate;

    bool showCursor, highscoreOrNAH, boxIsClicked;

    struct menuTextureStruct{
        sf::Texture* buttonNormal;
        sf::Texture* buttonMouseOver;
        sf::Texture* buttonClicked;
    };

    menuTextureStruct menuTextures[2];
    sf::Sprite* menuButtons[2];

};


#endif //VIETNAMESE_SPACE_PROGRAM_STATEGAMEOVER_H
