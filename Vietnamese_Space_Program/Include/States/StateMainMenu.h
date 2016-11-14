#ifndef VIETNAMESE_SPACE_PROGRAM_MENU_H
#define VIETNAMESE_SPACE_PROGRAM_MENU_H

#include "../Core/machine.h"
#include "../Core/state.h"
#include "../Core/soundLoader.h"

class StateMainMenu : public States{
public:
    void initialize(sf::RenderWindow *window);

    void update(sf::RenderWindow *window);

    void render(sf::RenderWindow *window);

    void destroy(sf::RenderWindow *window);

    void handleEvent(sf::RenderWindow *window , sf::Event event);

    void reinitialize(sf::RenderWindow *window);

private:
    SoundLoader sl;
    sf::Font* font;
    sf::Text* title;
    sf::Text* title2;
    sf::Text* play;
    sf::Text* options;
    sf::Text* highscore;
    sf::Text* quit;
    sf::Texture* bgTexture;
    sf::Sprite* background;


    std::vector<sf::Text*> menuTexts;


    int selected;
    unsigned int textSize = 32U;
};
#endif //VIETNAMESE_SPACE_PROGRAM_MENU_H
