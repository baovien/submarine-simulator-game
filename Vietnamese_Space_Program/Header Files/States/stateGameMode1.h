#pragma once

#include "../Core/state.h"
#include "../Core/util.h"
#include "../../Header Files/Core/machine.h"
#include "../Entities/player.h"
#include "../Entities/enemy.h"
#include "../Core/entityManager.h"
#ifndef VIETNAMESE_SPACE_PROGRAM_GAMEMODE1_H
#define VIETNAMESE_SPACE_PROGRAM_GAMEMODE1_H

class stateGameMode1 : public States
{
public:
    void initialize(sf::RenderWindow *window);
    void update(sf::RenderWindow *window);
    void render(sf::RenderWindow *window);
    void destroy(sf::RenderWindow *window);

protected:
    EnemyObject* enemy1;
    sf::Font* font;
    sf::Text* pausedText;
    Utilities* util;
    EntityManager manager;
};

#endif //VIETNAMESE_SPACE_PROGRAM_GAMEMODE1_H
