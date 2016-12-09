#ifndef VIETNAMESE_SPACE_PROGRAM_HIGHSCORESTATE_H
#define VIETNAMESE_SPACE_PROGRAM_HIGHSCORESTATE_H

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

    sf::Texture *bgTexture;
    sf::Sprite *TableArcade;
    sf::Sprite *TableClassic;
    sf::Sprite *background;

    sf::Text *title;
    sf::Text *titleArcade;
    sf::Text *titleClassic;

    struct buttonTextures
    {
        sf::Texture* buttonNormal;
        sf::Texture* buttonMouseOver;
        sf::Texture* buttonClicked;
    };

    buttonTextures backTexture;
    sf::Sprite* backButton;
    sf::Texture *tableTexture;

    std::vector<std::tuple<std::string, std::string, std::string>> highscoreValues;
    std::vector<sf::Text> tableText;

    Utilities util;
};

#endif //VIETNAMESE_SPACE_PROGRAM_HIGHSCORESTATE_H
