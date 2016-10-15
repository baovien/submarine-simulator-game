#pragma once

#ifndef VIETNAMESE_SPACE_PROGRAM_MENU_H
#define VIETNAMESE_SPACE_PROGRAM_MENU_H
#include "state.h"
class main_menu : public states
{
public:
    void Initialize(sf::RenderWindow* window);
    void Update(sf::RenderWindow* window);
    void Render(sf::RenderWindow* window);
    void Destroy(sf::RenderWindow* window);
private:
    sf::Font* font;
    sf::Text* title;
    sf::Text* play;
    sf::Text* quit;

    int selected;
    bool upKey; bool downKey;
};
#endif //VIETNAMESE_SPACE_PROGRAM_MENU_H
