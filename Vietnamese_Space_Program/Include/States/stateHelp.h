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
    sf::Texture* backgroundTexture;
    sf::Texture* enemyFishTexture;
    sf::Texture* bossTexture;
    sf::Texture* classicTexture;
    sf::Texture* arcadeTexture;
    sf::Texture* overheatTexture;
    sf::Texture* underwaterTexture;
    sf::Texture* spaceTexture;

    sf::Sprite* background;
    sf::Sprite* enemyFish;
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
    menuTextureStruct buttonTexture;
    sf::Sprite* button;

};



#endif //VIETNAMESE_SPACE_PROGRAM_HELP_H
