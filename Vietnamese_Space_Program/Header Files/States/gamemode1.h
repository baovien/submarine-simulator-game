#pragma once

#include "../Core/state.h"
#include "../Core/util.h"
#include "../Entities/Player.h"
#include "../Entities/playerobject.h"
#include "../Entities/enemy.h"
#include "../Entities/Bullet.h"
#ifndef VIETNAMESE_SPACE_PROGRAM_GAMEMODE1_H
#define VIETNAMESE_SPACE_PROGRAM_GAMEMODE1_H

class Gamemode1 : public States
{
public:
    void Initialize(sf::RenderWindow* window);
    void Update(sf::RenderWindow* window);
    void Render(sf::RenderWindow* window);
    void Destroy(sf::RenderWindow* window);

protected:
    Bullet* bullet1;
    Player* player1;
    EnemyObject* enemy1;
    sf::Font* font;
    sf::Text* pausedText;
    Utilities* util;
};

#endif //VIETNAMESE_SPACE_PROGRAM_GAMEMODE1_H
