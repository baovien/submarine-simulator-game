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

    sf::Text* theme = nullptr;
    sf::Text* fighter = nullptr;
    sf::Text* gamemode = nullptr;
    sf::Text* WaterTheme = nullptr;
    sf::Text* SpaceTheme = nullptr;
    sf::Text* Submarine = nullptr;
    sf::Text* Spaceship = nullptr;
    sf::Text* Arcade = nullptr;
    sf::Text* Classic = nullptr;

    sf::Texture* bgTexture = nullptr;
    sf::Sprite* background = nullptr;



    //Play- og backbutton
    struct menuTextureStruct
    {
        sf::Texture* buttonNormal = nullptr;
        sf::Texture* buttonMouseOver = nullptr;
        sf::Texture* buttonClicked = nullptr;
    };
    menuTextureStruct menuTextures[2];
    sf::Sprite* menuButtons[2];

    //Alle bildene i playconfig
    struct PictureTextureStruct
    {
        sf::Texture *buttonNormal = nullptr;
        sf::Texture *buttonMouseOver = nullptr;
    };
    PictureTextureStruct PictureTexture[6];
    sf::Sprite* PictureButtons[6];

   /* Indexen til hvert bilde i playconfig:
    *
   *  0 = SPACETHEME
   *  1 = WATERTHEME
   *  2 = SPACEFIGHTER
   *  3 = SUBMARINE
   *  4 = ARCADE
   *  5 = CLASSIC
   */

    Utilities util;

    //Velger hvem som skal være valgt som standard

    int selected_Theme = 0;
    int selected_Fighter = 2;
    int selected_Gamemode = 4;
};

#endif //VIETNAMESE_SPACE_PROGRAM_PLAYCONFIG_H
