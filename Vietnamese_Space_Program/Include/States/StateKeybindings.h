#ifndef VIETNAMESE_SPACE_PROGRAM_STATEKEYBINDINGS_H
#define VIETNAMESE_SPACE_PROGRAM_STATEKEYBINDINGS_H

#include "../Core/state.h"
#include "../Core/machine.h"

class StateKeybindings : public States{
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

    struct keySquares{
        sf::Text* keyText;
        sf::Text* titleText;
        sf::Sprite* keySquare;
    };
    std::vector<keySquares> keyVector;
    std::vector<sf::Vector2f> positionList;
};

#endif //VIETNAMESE_SPACE_PROGRAM_STATEKEYBINDINGS_H
