#ifndef VIETNAMESE_SPACE_PROGRAM_PLAYCONFIG_H
#define VIETNAMESE_SPACE_PROGRAM_PLAYCONFIG_H

#include "../Core/state.h"
#include "../Core/machine.h"
#include "../Core/utilities.h"

class StatePlayConfig : public States{
public:
    void initialize(sf::RenderWindow *window);

    void update(sf::RenderWindow *window);

    void render(sf::RenderWindow *window);

    void destroy(sf::RenderWindow *window);

    void handleEvent(sf::RenderWindow *window, sf::Event event);

    void reinitialize(sf::RenderWindow *window);

private:
    sf::Font* font;
    sf::Text* theme;
    sf::Text* fighter;
    sf::Text* gamemode;

    void load(std::string filename);

    sf::Text* SpaceTheme;
    sf::Text* PaperTheme;

    sf::Text* fighter_1;
    sf::Text* fighter_2;
    sf::Text* fighter_3;

    sf::Text* Arcade;
    sf::Text* Classic;

    std::vector<sf::Vector2f> positionList;

    sf::Texture* bgTexture;
    sf::Sprite* background;

    Utilities util;

    int selected, selected_Theme, selected_Fighter, selected_Gamemode;
    unsigned int textSize = 20U;
};

#endif //VIETNAMESE_SPACE_PROGRAM_PLAYCONFIG_H
