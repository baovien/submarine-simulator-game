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
    sf::Font* font;
    sf::Text* gameKeybinds;
    sf::Text* menuKeybinds;
    sf::Text* movementText;
    sf::Text* navigationText;

    sf::Texture* ballTexture;
    sf::Texture* bgTexture;
    sf::Sprite* background;
    sf::Sprite* keySquare;
    int selected;
    unsigned int textSize = 32U;

};

#endif //VIETNAMESE_SPACE_PROGRAM_STATEKEYBINDINGS_H
