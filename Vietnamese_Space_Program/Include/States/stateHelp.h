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
    sf::Text* title = nullptr;
    sf::Text* mode = nullptr;
    sf::Text* mode2 = nullptr;
    sf::Text* gamemode2 = nullptr;
    sf::Texture* backgroundTexture = nullptr;
    sf::Texture* enemyFishTexture = nullptr;
    sf::Texture* bossTexture = nullptr;
    sf::Texture* healthPackTexture = nullptr;
    sf::Texture* shieldTexture = nullptr;
    sf::Texture* overheatTexture = nullptr;
    sf::Texture* junkTexture = nullptr;
    sf::Texture* spaceTexture = nullptr;
    sf::Texture* classicTexture = nullptr;

    sf::Sprite* background = nullptr;
    sf::Sprite* enemyFish = nullptr;
    sf::Sprite* boss = nullptr;
    sf::Sprite* healthPack = nullptr;
    sf::Sprite* shield = nullptr;
    sf::Sprite* overheat = nullptr;
    sf::Sprite* junk = nullptr;
    sf::Sprite* space = nullptr;
    sf::Sprite* classic = nullptr;

    sf::Text* asteroid1 = nullptr;
    sf::Text* boss1 = nullptr;
    sf::Text* powerUp = nullptr;
    sf::Text* overheat1 = nullptr;
    sf::Text* garbage = nullptr;


    struct menuTextureStruct
    {
        sf::Texture* buttonNormal = nullptr;
        sf::Texture* buttonMouseOver = nullptr;
        sf::Texture* buttonClicked = nullptr;
    };
    menuTextureStruct buttonTexture;
    sf::Sprite* button = nullptr;

};



#endif //VIETNAMESE_SPACE_PROGRAM_HELP_H
