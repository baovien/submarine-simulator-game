#ifndef VIETNAMESE_SPACE_PROGRAM_STATEKEYBINDINGS_H
#define VIETNAMESE_SPACE_PROGRAM_STATEKEYBINDINGS_H


#include "../Core/state.h"
#include "../../Header Files/Core/machine.h"

class stateKeybindings : public States{
public:
    void initialize(sf::RenderWindow *window);

    void update(sf::RenderWindow *window);

    void render(sf::RenderWindow *window);

    void destroy(sf::RenderWindow *window);

private:
    sf::RenderWindow* window;

    sf::Font* font;
    sf::Text* movementText;
    sf::Text* menuNavigationText;
    sf::Text* gameplayText;

    sf::Texture* ballTexture;
    sf::Texture* bgTexture;
    sf::Sprite* background;


    sf::Sprite* upKeySquare;
    sf::Sprite* downKeySquare;
    sf::Sprite* leftKeySquare;
    sf::Sprite* rightKeySquare;
    sf::Sprite* selectKeySquare;
    sf::Sprite* backKeySquare;
    sf::Sprite* shootKeySquare;
    sf::Sprite* pauseKeySquare;

    //sf::Sprite* keySquares[];

    sf::Text* upText;
    sf::Text* downText;
    sf::Text* leftText;
    sf::Text* rightText;
    sf::Text* selectText;
    sf::Text* backText;
    sf::Text* shootText;
    sf::Text* pauseText;

    sf::Text* upKeyText;

    int selected;
    unsigned int textSize = 32U;

};

#endif //VIETNAMESE_SPACE_PROGRAM_STATEKEYBINDINGS_H
