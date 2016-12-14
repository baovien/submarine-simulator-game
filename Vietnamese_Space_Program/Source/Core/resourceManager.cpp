#include "../../Include/Core/resourceManager.h"

void ResourceManager::loadFiles() {
    this->bgTexture = new sf::Texture();
    this->bgTexture->loadFromFile("Graphics/Sprites/bakgrunn.png");
    
    //Main menu textures
    for (unsigned int i = 0; i < (sizeof(mainMenuTextures) / sizeof(*mainMenuTextures)); ++i) {
        mainMenuTextures[i].buttonMouseOver = new sf::Texture();
        mainMenuTextures[i].buttonMouseOver->loadFromFile("Graphics/Sprites/MainMenu_buttons/Btn" + std::to_string(i * 3) + ".png");

        mainMenuTextures[i].buttonNormal = new sf::Texture();
        mainMenuTextures[i].buttonNormal->loadFromFile("Graphics/Sprites/MainMenu_buttons/Btn" + std::to_string(i * 3 + 1) + ".png");

        mainMenuTextures[i].buttonClicked = new sf::Texture();
        mainMenuTextures[i].buttonClicked->loadFromFile("Graphics/Sprites/MainMenu_buttons/Btn" + std::to_string(i * 3 + 2) + ".png");
    }
    
    
    //statePlayConfig
    for (unsigned int i = 0; i < sizeof(playConfigMenuTextures) / sizeof(*playConfigMenuTextures); ++i) {
        playConfigMenuTextures[i].buttonMouseOver = new sf::Texture();
        playConfigMenuTextures[i].buttonMouseOver->loadFromFile("Graphics/Sprites/PlayConfig_buttons/Btn" + std::to_string(i * 3) + ".png");

        playConfigMenuTextures[i].buttonNormal = new sf::Texture();
        playConfigMenuTextures[i].buttonNormal->loadFromFile("Graphics/Sprites/PlayConfig_buttons/Btn" + std::to_string(i * 3 + 1) + ".png");

        playConfigMenuTextures[i].buttonClicked = new sf::Texture();
        playConfigMenuTextures[i].buttonClicked->loadFromFile("Graphics/Sprites/PlayConfig_buttons/Btn" + std::to_string(i * 3 + 2) + ".png");

    }
    //Legger til alle bildekanppene
    for (unsigned int i = 0; i < sizeof(playConfigPictureTexture) / sizeof(*playConfigPictureTexture); ++i) {
        playConfigPictureTexture[i].buttonNormal = new sf::Texture();
        playConfigPictureTexture[i].buttonNormal->loadFromFile("Graphics/Sprites/PlayConfig_pictures/PngBtn" + std::to_string(i * 2) + ".png");

        playConfigPictureTexture[i].buttonMouseOver = new sf::Texture();

        playConfigPictureTexture[i].buttonMouseOver->loadFromFile("Graphics/Sprites/PlayConfig_pictures/PngBtn" + std::to_string(i * 2 + 1) + ".png");
        
    }



    //Gameover
    for (unsigned int i = 0; i < sizeof(gameOverMenuTextures) / sizeof(*gameOverMenuTextures); ++i) {
        gameOverMenuTextures[i].buttonMouseOver = new sf::Texture();
        gameOverMenuTextures[i].buttonMouseOver->loadFromFile(
                "Graphics/Sprites/GameOver_buttons/Btn" + std::to_string(i * 3) + ".png");

        gameOverMenuTextures[i].buttonNormal = new sf::Texture();
        gameOverMenuTextures[i].buttonNormal->loadFromFile(
                "Graphics/Sprites/GameOver_buttons/Btn" + std::to_string(i * 3 + 1) + ".png");

        gameOverMenuTextures[i].buttonClicked = new sf::Texture();
        gameOverMenuTextures[i].buttonClicked->loadFromFile(
                "Graphics/Sprites/GameOver_buttons/Btn" + std::to_string(i * 3 + 2) + ".png");
    }



    //Settings
    for (unsigned int i = 0; i < sizeof(settingsFlagTextures) / sizeof(*settingsFlagTextures); ++i) {
        settingsFlagTextures[i] = new sf::Texture();
        settingsFlagTextures[i]->loadFromFile("Graphics/Sprites/Settings_buttons/flag" + std::to_string(i) + ".png");
    }
    //Lager alle knapper og laster inn alle textures til knappene
    for (unsigned int i = 0; i < sizeof(settingsMenuTextures) / sizeof(*settingsMenuTextures); ++i) {
        settingsMenuTextures[i].buttonMouseOver = new sf::Texture();
        settingsMenuTextures[i].buttonMouseOver->loadFromFile("Graphics/Sprites/Settings_buttons/Btn" + std::to_string(i * 3) + ".png");

        settingsMenuTextures[i].buttonNormal = new sf::Texture();
        settingsMenuTextures[i].buttonNormal->loadFromFile("Graphics/Sprites/Settings_buttons/Btn" + std::to_string(i * 3 + 1) + ".png");

        settingsMenuTextures[i].buttonClicked = new sf::Texture();
        settingsMenuTextures[i].buttonClicked->loadFromFile("Graphics/Sprites/Settings_buttons/Btn" + std::to_string(i * 3 + 2) + ".png");
        
    }
    fpsTextures.buttonMouseOver = new sf::Texture();
    fpsTextures.buttonMouseOver->loadFromFile("Graphics/Sprites/Buttons/Button_33.png");
    fpsTextures.buttonNormal = new sf::Texture();
    fpsTextures.buttonNormal->loadFromFile("Graphics/Sprites/Buttons/Button_34.png");
    fpsTextures.buttonClicked = new sf::Texture();
    fpsTextures.buttonClicked->loadFromFile("Graphics/Sprites/Buttons/Button_35.png");

    this->obTexture = new sf::Texture();
    this->obTexture->loadFromFile("Graphics/Sprites/Window/Window_10.png");





    //Keybinds
    this->keyBindTexture = new sf::Texture();
    this->keyBindTexture->loadFromFile("Graphics/Sprites/Buttons/Button_36.png");








    //highscore
    backTexture.buttonMouseOver = new sf::Texture();
    backTexture.buttonMouseOver->loadFromFile("Graphics/Sprites/PlayConfig_buttons/Btn3.png");
    backTexture.buttonNormal = new sf::Texture();
    backTexture.buttonNormal->loadFromFile("Graphics/Sprites/PlayConfig_buttons/Btn4.png");
    backTexture.buttonClicked = new sf::Texture();
    backTexture.buttonClicked->loadFromFile("Graphics/Sprites/PlayConfig_buttons/Btn5.png");

    this->tableTexture = new sf::Texture();
    this->tableTexture->loadFromFile("Graphics/Sprites/tablehighscore.png");





    //help
    this->backgroundTexture = new sf::Texture();
    this->backgroundTexture->loadFromFile("Graphics/Sprites/background12.png");

    this->enemyFishTexture = new sf::Texture();
    this->enemyFishTexture->loadFromFile("Graphics/Sprites/happyfish.png");

    this->bossTexture = new sf::Texture();
    this->bossTexture->loadFromFile("Graphics/Sprites/blowfish.png");

    this->healthPackTexture = new sf::Texture();
    this->healthPackTexture->loadFromFile("Graphics/Sprites/wrench.png");

    this->shieldTexture = new sf::Texture();
    this->shieldTexture->loadFromFile("Graphics/Sprites/shieldPowerUp.png");

    this->overheatTexture = new sf::Texture();
    this->overheatTexture->loadFromFile("Graphics/Sprites/overheat.png");

    this->junkTexture = new sf::Texture();
    this->junkTexture->loadFromFile("Graphics/Sprites/tincan.png");

    this->classicTexture = new sf::Texture();
    this->classicTexture->loadFromFile("Graphics/Sprites/PlayConfig_pictures/PngBtn10.png");


    this->spaceTexture = new sf::Texture();
    this->spaceTexture->loadFromFile("Graphics/Sprites/PlayConfig_pictures/PngBtn0.png");








    //Gamemode 2 and 1
    this->bgTexture = new sf::Texture();
    this->bgTexture->loadFromFile("Graphics/Sprites/background1" + std::to_string(2+machine.selectedObjectsPointer->selectedTheme)+".png");
    this->pausedTexture = new sf::Texture();
    this->pausedTexture->loadFromFile("Graphics/Sprites/overlayPause.png");












}
