
#ifndef VIETNAMESE_SPACE_PROGRAM_MENU_H
#define VIETNAMESE_SPACE_PROGRAM_MENU_H
#include "../../Header Files/Core/machine.h"
#include "../Core/state.h"

class stateMainMenu : public States{
public:
    void initialize(sf::RenderWindow *window);

    void update(sf::RenderWindow *window);

    void render(sf::RenderWindow *window);

    void destroy(sf::RenderWindow *window);

private:
    sf::Font* font;
    sf::Text* title;
    sf::Text* title2;
    sf::Text* play;
    sf::Text* options;
    sf::Text* highscore;
    sf::Text* quit;
    sf::Texture* bgTexture;
    sf::Sprite* background;

    int selected;
    unsigned int textSize = 32U;
};
#endif //VIETNAMESE_SPACE_PROGRAM_MENU_H
