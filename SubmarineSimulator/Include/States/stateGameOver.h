#ifndef SUBMARINESIMULATORSTATEGAMEOVER_H
#define SUBMARINESIMULATORSTATEGAMEOVER_H

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

private:

    void saveScoreArcade();
    void saveScoreClassic();

    Utilities util;
    sf::Text* gameOverText = nullptr;
    sf::Text* score = nullptr;
    sf::Text* congratulationsText = nullptr;
    sf::Text* congratulationsText2 = nullptr;
    sf::Text* whatAShameText = nullptr;

    sf::Texture* bgTexture = nullptr;
    sf::Sprite* background = nullptr;

    sf::RectangleShape* textBox;

    int gameOverScore;

    std::string playerName;
    sf::Text* text = nullptr;
    sf::Text* clickToActivate = nullptr;

    bool highscoreOrNAH, boxIsClicked;

    struct menuTextureStruct{
        sf::Texture* buttonNormal = nullptr;
        sf::Texture* buttonMouseOver = nullptr;
        sf::Texture* buttonClicked = nullptr;
    };

    menuTextureStruct menuTextures[2];
    sf::Sprite* menuButtons[2];
};


#endif //SUBMARINESIMULATORSTATEGAMEOVER_H
