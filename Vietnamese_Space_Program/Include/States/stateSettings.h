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

    sf::Text* title;
    struct settingsTextureStruct{
        sf::Texture* buttonNormal;
        sf::Texture* buttonMouseOver;
        sf::Texture* buttonClicked;
    };
    settingsTextureStruct settingsTextures[5];
    sf::Sprite* settingsButtons[5];

    sf::Texture* settingsFlagTextures[4];
    sf::Sprite* settingsFlagButtons[4];

    settingsTextureStruct fpsTextures;
    sf::Sprite* fpsButtons[3];
    sf::Text* fpsText;
    sf::Text* fpsNumbers[3];
    std::string fpsWordList[3] = {"30", "60", "120"};
    int selectedfps = 1;
    int selectedLanguage = 0;

    std::string wordList[4] = {"Music", "Controls", "Reset highscore", "Reset controls"};
    sf::Text* mouseOverText[4];
    sf::Texture* bgTexture;
    sf::Sprite* background;
};

#endif //VIETNAMESE_SPACE_PROGRAM_SETTINGSSTATE_H
