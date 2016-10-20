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
    sf::Text* back;
    sf::Text* play;

    int selected;

    bool upKey, downKey, leftKey, rightKey, enterKey, escKey;
};

#endif //VIETNAMESE_SPACE_PROGRAM_PLAYCONFIG_H
