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
    void initialize(sf::RenderWindow *window);
    void update(sf::RenderWindow *window);
    void render(sf::RenderWindow *window);
    void destroy(sf::RenderWindow *window);

protected:
    Bullet* bullet1;
    Player* player1;
    EnemyObject* enemy1;
    sf::Font* font;
    sf::Text* pausedText;
    Utilities* util;
};

#endif //VIETNAMESE_SPACE_PROGRAM_GAMEMODE1_H
