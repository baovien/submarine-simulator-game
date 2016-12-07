#ifndef VIETNAMESE_SPACE_PROGRAM_PLAYCONFIG_H
#define VIETNAMESE_SPACE_PROGRAM_PLAYCONFIG_H

#include "../Core/state.h"
#include "../Core/machine.h"
#include "../Core/utilities.h"
#include <vector>
class StatePlayConfig : public States{
public:
    void initialize(sf::RenderWindow *window);

    void update(sf::RenderWindow *window);

    void render(sf::RenderWindow *window);

    void destroy(sf::RenderWindow *window);

    void handleEvent(sf::RenderWindow *window, sf::Event event);

    void reinitialize(sf::RenderWindow *window);

private:

    sf::Text* theme;
    sf::Text* fighter;
    sf::Text* gamemode;
    sf::Text* WaterTheme;
    sf::Text* SpaceTheme;
    sf::Text* fighter_1;
    sf::Text* fighter_2;
    sf::Text* fighter_3;
    sf::Text* Arcade;
    sf::Text* Classic;

    sf::Texture* bgTexture;
    sf::Sprite* background;

    struct menuTextureStruct
    {
        sf::Texture* buttonNormal;
        sf::Texture* buttonMouseOver;
        sf::Texture* buttonClicked;
    };
    menuTextureStruct menuTextures[2];
    sf::Sprite* menuButtons[2];

    struct PictureTextureStruct
    {
        sf::Texture *buttonNormal;
        sf::Texture *buttonMouseOver;
    };
    PictureTextureStruct PictureTexture[7];
    sf::Sprite* PictureButtons[7];

    Utilities util;

    int selected, selected_Theme, selected_Fighter, selected_Gamemode;
    unsigned int textSize = 20U;
};

#endif //VIETNAMESE_SPACE_PROGRAM_PLAYCONFIG_H
