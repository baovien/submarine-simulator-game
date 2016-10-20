#pragma once
#include "../Entities/enemy_entity.h"

#ifndef VIETNAMESE_SPACE_PROGRAM_ENEMY_H
#define VIETNAMESE_SPACE_PROGRAM_ENEMY_H

class enemyObject : public Enemy_Entity
{
public:
    enemyObject();
    void UpdateEnemy(sf::RenderWindow* window);
    void Reset(sf::RenderWindow* window);
    ~enemyObject();
};

#endif //VIETNAMESE_SPACE_PROGRAM_ENEMY_H
