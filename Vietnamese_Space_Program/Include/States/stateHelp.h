#ifndef VIETNAMESE_SPACE_PROGRAM_HELP_H
#define VIETNAMESE_SPACE_PROGRAM_HELP_H

#include "../Core/state.h"
#include "../Core/machine.h"
#include "../Core/utilities.h"


class stateHelp : public States{

public:
    void initialize(sf::RenderWindow *window);

    void update(sf::RenderWindow *window);

    void render(sf::RenderWindow *window);

    void destroy(sf::RenderWindow *window);

    void handleEvent(sf::RenderWindow *window, sf::Event event);

    void reinitialize(sf::RenderWindow *window);


private:
    Utilities util;
    sf::Text* title;
    sf::Texture* bgTexture;
    sf::Texture* asTexture;
    sf::Texture* boTexture;
    sf::Texture* clTexture;
    sf::Texture* arTexture;
    sf::Texture* Texture;
    sf::Texture* ohTexture;
    sf::Texture* uwTexture;
    sf::Texture* spTexture;

    sf::Sprite* background;
    sf::Sprite* asteroid;
    sf::Sprite* boss;
    sf::Sprite* classic;
    sf::Sprite* arcade;
    sf::Sprite* overheat;
    sf::Sprite* underwater;
    sf::Sprite* space;


    sf::Text* asteroid1;
    sf::Text* boss1;
    sf::Text* gamemode;
    sf::Text* overheat1;
    sf::Text* theme;


    struct menuTextureStruct
    {
        sf::Texture* buttonNormal;
        sf::Texture* buttonMouseOver;
        sf::Texture* buttonClicked;
    };
    menuTextureStruct PictureTexture[1];
    sf::Sprite* PictureButtons[1];

};



#endif //VIETNAMESE_SPACE_PROGRAM_HELP_H
