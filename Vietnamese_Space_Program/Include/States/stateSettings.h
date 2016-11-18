#ifndef VIETNAMESE_SPACE_PROGRAM_SETTINGSSTATE_H
#define VIETNAMESE_SPACE_PROGRAM_SETTINGSSTATE_H

#include "../Core/state.h"
#include "../Core/machine.h"
#include "../Core/utilities.h"

class StateSettings : public States{
public:
    void initialize(sf::RenderWindow *window);

    void update(sf::RenderWindow *window);

    void render(sf::RenderWindow *window);

    void destroy(sf::RenderWindow *window);

    void handleEvent(sf::RenderWindow *window , sf::Event event);

    void reinitialize(sf::RenderWindow *window);
private:
    Utilities util;
    sf::Font* font;

    sf::Text* title;
    sf::Text* screenRes;
    sf::Text* res1;
    sf::Text* res2;
    sf::Text* res3;
    sf::Text* volume;
    sf::Text* keybinds;
    sf::Text* apply;
    sf::Text* back;

    sf::Texture* settingsFlagTextures[4];
    sf::Sprite* settingsFlagSprites[4];

    sf::Vector2u resChoice;

    sf::Texture* bgTexture;
    sf::Sprite* background;

    int selected, selectedRes;
    unsigned int textSize = 32U;

};

#endif //VIETNAMESE_SPACE_PROGRAM_SETTINGSSTATE_H
