#pragma once

#ifndef VIETNAMESE_SPACE_PROGRAM_SETTINGSSTATE_H
#define VIETNAMESE_SPACE_PROGRAM_SETTINGSSTATE_H

#include "../Core/state.h"

class settingsState : public states{
public:
    void Initialize(sf::RenderWindow* window);

    void Update(sf::RenderWindow* window);

    void Render(sf::RenderWindow* window);

    void Destroy(sf::RenderWindow* window);

private:
    sf::Font* font;
    sf::Text* title;
    sf::Text* screenRes;

    sf::Text* res1;
    sf::Text* res2;
    sf::Text* res3;

    sf::Text* volume;
    sf::Text* apply;
    sf::Text* back;
    sf::Vector2u resChoice;

    int selected, selectedRes;

    bool upKey, downKey, leftKey, rightKey, enterKey;
};

#endif //VIETNAMESE_SPACE_PROGRAM_SETTINGSSTATE_H
