#ifndef VIETNAMESE_SPACE_PROGRAM_RESOURCEMANAGER_H
#define VIETNAMESE_SPACE_PROGRAM_RESOURCEMANAGER_H

#include <SFML/Graphics/Texture.hpp>

class ResourceManager
{
public:
    void loadFiles(int fighter, int gameMode, int theme);
    sf::Texture* bgTexture; /////////////////////////////////////////////////////////////////////

private:

    struct menuTextureStruct{
        sf::Texture buttonNormal;
        sf::Texture buttonMouseOver;
        sf::Texture buttonClicked;
    };

    struct PictureTextureStruct
    {
        sf::Texture *buttonNormal;
        sf::Texture *buttonMouseOver;
    };

public:
    menuTextureStruct mainMenuTextures[5]; //main menu
    menuTextureStruct* mainMenuTexturesPointer = mainMenuTextures;



    menuTextureStruct playConfigMenuTextures[2]; //playconfig

    PictureTextureStruct playConfigPictureTexture[6]; //settings






    menuTextureStruct gameOverMenuTextures[2]; //Gameover





    menuTextureStruct settingsMenuTextures[8]; //settings

    sf::Texture* settingsFlagTextures[4]; //settings

    menuTextureStruct fpsTextures; //settings

    sf::Texture* obTexture; //settings






    sf::Texture* keyBindTexture; //keybinds





    menuTextureStruct backTexture; //highscore

    sf::Texture *tableTexture; //highscore






    //menuTextureStruct backTexture; //help

    sf::Texture* backgroundTexture;
    sf::Texture* enemyFishTexture;
    sf::Texture* bossTexture;
    sf::Texture* healthPackTexture;
    sf::Texture* shieldTexture;
    sf::Texture* overheatTexture;
    sf::Texture* junkTexture;
    sf::Texture* spaceTexture;
    sf::Texture* classicTexture;




    sf::Texture* pausedTexture; //Gamemode 2
    sf::Texture overBar;        //Gamemode 1


    //sf::Texture* pausedTexture;

};
#endif //VIETNAMESE_SPACE_PROGRAM_RESOURCEMANAGER_H
