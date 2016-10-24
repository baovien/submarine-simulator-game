#pragma once

#include "../Core/state.h"
#include "../Core/util.h"
#include "../Entities/player.h"
#include "../Entities/playerobject.h"
#include "../Entities/enemy.h"
#include "../Entities/bullet.h"
#ifndef VIETNAMESE_SPACE_PROGRAM_GAMEMODE1_H
#define VIETNAMESE_SPACE_PROGRAM_GAMEMODE1_H

class gamemode1 : public states
{
public:
    void Initialize(sf::RenderWindow* window);
    void Update(sf::RenderWindow* window);
    void Render(sf::RenderWindow* window);
    void Destroy(sf::RenderWindow* window);

protected:
    bullet* bullet1;
    player* player1;
    enemyObject* enemy1;
    sf::Font* font;
    sf::Text* pausedText;
    Utilities* util;
};

#endif //VIETNAMESE_SPACE_PROGRAM_GAMEMODE1_H
