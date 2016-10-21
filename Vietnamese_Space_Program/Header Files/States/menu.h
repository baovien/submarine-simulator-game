#pragma once

#ifndef VIETNAMESE_SPACE_PROGRAM_MENU_H
#define VIETNAMESE_SPACE_PROGRAM_MENU_H
#include "../Core/state.h"

class main_menu : public states{
public:
    void Initialize(sf::RenderWindow* window);

    void Update(sf::RenderWindow* window);

    void Render(sf::RenderWindow* window);

    void Destroy(sf::RenderWindow* window);

private:
    sf::Font* font;
    sf::Text* title;
    sf::Text* title2;
    sf::Text* play;
    sf::Text* options;
    sf::Text* highscore;
    sf::Text* quit;

    int selected;
    unsigned int textSize = 32U;

    bool upKey, downKey, enterKey;
};
#endif //VIETNAMESE_SPACE_PROGRAM_MENU_H
