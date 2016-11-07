#ifndef VIETNAMESE_SPACE_PROGRAM_HIGHSCORESTATE_H
#define VIETNAMESE_SPACE_PROGRAM_HIGHSCORESTATE_H

#include "../Core/state.h"
#include "../../Header Files/Core/machine.h"

class stateHighscoreState : public States{


public:
    void initialize(sf::RenderWindow *window);

    void update(sf::RenderWindow *window);

    void render(sf::RenderWindow *window);

    void destroy(sf::RenderWindow *window);

private:
    sf::Font* font;
    sf::Text* title;
    sf::Text* playerText;
    sf::Text* playerPlace;
    sf::Text* scoreText;
    sf::Text* backText;
    sf::Texture* bgTexture;
    sf::Texture* tbTexture;
    sf::Sprite* background;
    sf::Sprite* table;

#define mellomromIHoyde window->getSize().x / 5.2;

    sf::Text* playerPlace1;
    sf::Text* playerPlace2;
    sf::Text* playerPlace3;
    sf::Text* playerPlace4;
    sf::Text* playerPlace5;
    sf::Text* playerPlace6;
    sf::Text* playerPlace7;
    sf::Text* playerPlace8;
    sf::Text* playerPlace9;
    sf::Text* playerPlace10;


    int selected;

};

#endif //VIETNAMESE_SPACE_PROGRAM_HIGHSCORESTATE_H
