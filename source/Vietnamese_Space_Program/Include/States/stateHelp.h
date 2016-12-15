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
    sf::Text* mode;
    sf::Text* mode2;
    sf::Text* gamemode2;
    sf::Texture* backgroundTexture;
    sf::Texture* enemyFishTexture;
    sf::Texture* bossTexture;
    sf::Texture* healthPackTexture;
    sf::Texture* shieldTexture;
    sf::Texture* overheatTexture;
    sf::Texture* junkTexture;
    sf::Texture* spaceTexture;
    sf::Texture* classicTexture;

    sf::Sprite* background;
    sf::Sprite* enemyFish;
    sf::Sprite* boss;
    sf::Sprite* healthPack;
    sf::Sprite* shield;
    sf::Sprite* overheat;
    sf::Sprite* junk;
    sf::Sprite* space;
    sf::Sprite* classic;

    sf::Text* asteroid1;
    sf::Text* boss1;
    sf::Text* powerUp;
    sf::Text* overheat1;
    sf::Text* garbage;


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
