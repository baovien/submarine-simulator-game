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

    std::map<const std::string, std::tuple<std::string, std::string, std::string>> languageMap =
            {{"Submarine Simulator", std::make_tuple("Ubåtsimulator" , "podmornica simulator", "симулятор подводной лодки")},
             {"Wave: ", std::make_tuple("Bølge: " , "talas: ", "Волна: ")},
             {"Settings", std::make_tuple("1" , "2", "3")},
             {"Music", std::make_tuple("1" , "2", "3")},
             {"Controls", std::make_tuple("1" , "2", "3")},
             {"Reset highscore", std::make_tuple("1" , "2", "3")},
             {"Reset controls", std::make_tuple("1" , "2", "3")},
             {"Movement", std::make_tuple("1" , "2", "3")},
             {"Menu navigation", std::make_tuple("1" , "2", "3")},
             {"Up", std::make_tuple("1" , "2", "3")},
             {"Down", std::make_tuple("1" , "2", "3")},
             {"Left", std::make_tuple("1" , "2", "3")},
             {"Right", std::make_tuple("1" , "2", "3")},
             {"Back", std::make_tuple("1" , "2", "3")},
             {"Select", std::make_tuple("1" , "2", "3")},
             {"Pause", std::make_tuple("1" , "2", "3")},
             {"Shoot", std::make_tuple("1" , "2", "3")},
             {"Key already bound", std::make_tuple("1" , "2", "3")},
             {"Highscore", std::make_tuple("1" , "2", "3")},
             {"Arcade", std::make_tuple("1" , "2", "3")},
             {"Classic", std::make_tuple("1" , "2", "3")},
             {"Player", std::make_tuple("1" , "2", "3")},
             {"How to play", std::make_tuple("1" , "2", "3")},
             {"Select theme", std::make_tuple("1" , "2", "3")},
             {"Select gamemode", std::make_tuple("1" , "2", "3")},
             {"Select fighter", std::make_tuple("1" , "2", "3")},
             {"Space", std::make_tuple("1" , "2", "3")},
             {"Water", std::make_tuple("1" , "2", "3")},
             {"Submarine", std::make_tuple("1" , "2", "3")},
             {"Spaceship", std::make_tuple("1" , "2", "3")},
             {"Lives: ", std::make_tuple("1" , "2", "3")},
             {"Score: ", std::make_tuple("1" , "2", "3")},
             {"Game over", std::make_tuple("1" , "2", "3")},
             {"Score", std::make_tuple("1" , "2", "3")},
             {"Score", std::make_tuple("1" , "2", "3")},
             {"Score", std::make_tuple("1" , "2", "3")},
             {"Score", std::make_tuple("1" , "2", "3")},
             {"Score", std::make_tuple("1" , "2", "3")},
             {"Score", std::make_tuple("1" , "2", "3")},
             {"Score", std::make_tuple("1" , "2", "3")},
             {"Score", std::make_tuple("1" , "2", "3")},
             {"Score", std::make_tuple("1" , "2", "3")}
            };


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
    sf::Sprite *addButton(sf::Texture* texture, float scaleX, float scaleY, float posX, float posY, sf::RenderWindow *window);

    //Text, textsize, origin x, origin y, position x, position y, window, language int
    sf::Text *addText(std::string textContent, unsigned int textSize, int originX, int originY, float posX, float posY, sf::RenderWindow *window, int language);

    //Tar inn sprite og returnerer true om mouseover
    bool checkMouseover(sf::Sprite *buttonSprite, sf::RenderWindow *window);

    //Tar inn sprite og returnerer true om mouseclick
    bool checkMouseclick(sf::Sprite *buttonSprite, sf::Event event);

};

#endif //VIETNAMESE_SPACE_PROGRAM_UTIL_H
