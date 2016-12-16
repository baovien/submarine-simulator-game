#ifndef SUBMARINESIMULATORHIGHSCORESTATE_H
#define SUBMARINESIMULATORHIGHSCORESTATE_H

#include "../Core/state.h"
#include "../Core/machine.h"
#include "../Core/utilities.h"
#include <fstream>
#include <vector>

class StateHighscore : public States
{
public:
    void initialize(sf::RenderWindow *window);

    void update(sf::RenderWindow *window);

    void render(sf::RenderWindow *window);

    void destroy(sf::RenderWindow *window);

    void handleEvent(sf::RenderWindow *window, sf::Event event);

    void reinitialize(sf::RenderWindow *window);

private:

    sf::Texture *bgTexture = nullptr;
    sf::Sprite *TableArcade = nullptr;
    sf::Sprite *TableClassic = nullptr;
    sf::Sprite *background = nullptr;

    sf::Text *title = nullptr;
    sf::Text *titleArcade = nullptr;
    sf::Text *titleClassic = nullptr;

    struct buttonTextures
    {
        sf::Texture* buttonNormal = nullptr;
        sf::Texture* buttonMouseOver = nullptr;
        sf::Texture* buttonClicked = nullptr;
    };

    buttonTextures backTexture;
    sf::Sprite* backButton = nullptr;
    sf::Texture *tableTexture = nullptr;

    std::vector<std::tuple<std::string, std::string, std::string>> highscoreValues;
    std::vector<sf::Text> tableText;

    Utilities util;
};

#endif //SUBMARINESIMULATORHIGHSCORESTATE_H
