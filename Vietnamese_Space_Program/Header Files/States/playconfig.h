#pragma once
#ifndef VIETNAMESE_SPACE_PROGRAM_PLAYCONFIG_H
#define VIETNAMESE_SPACE_PROGRAM_PLAYCONFIG_H

#include "../Core/state.h"

class playconfig_menu : public states{
public:
    void Initialize(sf::RenderWindow* window);

    void Update(sf::RenderWindow* window);

    void Render(sf::RenderWindow* window);

    void Destroy(sf::RenderWindow* window);

private:
    sf::Font* font;
    sf::Text* theme;
    sf::Text* fighter;
    sf::Text* gamemode;

    sf::Text* theme_1;
    sf::Text* theme_2;
    sf::Text* theme_3;

    sf::Text* fighter_1;
    sf::Text* fighter_2;
    sf::Text* fighter_3;

    sf::Text* gamemode_1;
    sf::Text* gamemode_2;
    sf::Text* gamemode_3;


    sf::Text* back;
    sf::Text* play;

    int selected, selected_Theme, selected_Fighter, selected_Gamemode;
    unsigned int textSize = 20U;
    bool upKey, downKey, leftKey, rightKey, enterKey, escKey;
};

#endif //VIETNAMESE_SPACE_PROGRAM_PLAYCONFIG_H
