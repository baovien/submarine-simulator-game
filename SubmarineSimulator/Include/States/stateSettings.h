#ifndef SUBMARINESIMULATORSETTINGSSTATE_H
#define SUBMARINESIMULATORSETTINGSSTATE_H

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

    sf::Text* title = nullptr;
    struct settingsTextureStruct{
        sf::Texture* buttonNormal = nullptr;
        sf::Texture* buttonMouseOver = nullptr;
        sf::Texture* buttonClicked = nullptr;
    };
    settingsTextureStruct settingsTextures[8];
    sf::Sprite* settingsButtons[7];

    sf::Texture* settingsFlagTextures[4];
    sf::Sprite* settingsFlagButtons[4];

    settingsTextureStruct fpsTextures;
    sf::Sprite* fpsButtons[3];
    sf::Text* fpsText = nullptr;
    sf::Text* fpsNumbers[3];
    std::string fpsWordList[3] = {"30", "60", "120"};

    std::string wordList[4] = {"Music", "Controls", "Reset highscore", "Reset controls"};
    sf::Text* mouseOverText[4];
    sf::Texture* bgTexture = nullptr;
    sf::Sprite* background = nullptr;

    sf::Text* overlayText = nullptr;
    sf::Texture* obTexture = nullptr;
    sf::Sprite* overlayBackground = nullptr;
    bool inOverlay = false;
    bool bindsOrScore = false; //binds er true, score er false. Denne bruker vi til å sjekke om det er binds eller score som skal resettes
};

#endif //SUBMARINESIMULATORSETTINGSSTATE_H
