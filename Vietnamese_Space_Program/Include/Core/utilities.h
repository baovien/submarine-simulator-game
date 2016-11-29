#ifndef VIETNAMESE_SPACE_PROGRAM_UTIL_H
#define VIETNAMESE_SPACE_PROGRAM_UTIL_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Utilities {
private:
    sf::Font *font;
    sf::Sprite *muteButton;

    struct muteTextureStruct{
        sf::Texture* buttonNormal;
        sf::Texture* buttonMouseOver;
        sf::Texture* buttonClicked;
    };
    muteTextureStruct muteTextures[2];


public:
    bool paused = false;

    sf::Sprite *getMuteButton() const;

    void pauseScreen() {
        //Funksjonen setter og fjerner pause
        paused = !paused;
    }

    void makeMuteButton(sf::RenderWindow* window, bool* mutedPointer);
    void checkMuteMouseOver(sf::RenderWindow* window);
    void checkMuteMouseClick(sf::RenderWindow* window, sf::Event event, bool* mutedPointer);

    //Texture, scale x, scale y, position x, position y, window
    sf::Sprite *addButton(sf::Texture texture, float scaleX, float scaleY, float posX, float posY, sf::RenderWindow *window);

    //Text, textsize, origin x, origin y, position x, position y, window
    sf::Text *addText(std::string textContent, unsigned int textSize, int originX, int originY, float posX, float posY, sf::RenderWindow *window);

    //Tar inn sprite og returnerer true om mouseover
    bool checkMouseover(sf::Sprite *buttonSprite, sf::RenderWindow *window);

    //Tar inn sprite og returnerer true om mouseclick
    bool checkMouseclick(sf::Sprite *buttonSprite, sf::Event event);

};

#endif //VIETNAMESE_SPACE_PROGRAM_UTIL_H
