#pragma once
#include "../Entities/enemy_entity.h"

#ifndef VIETNAMESE_SPACE_PROGRAM_ENEMY_H
#define VIETNAMESE_SPACE_PROGRAM_ENEMY_H

class EnemyObject : public EnemyEntity
{
public:
    EnemyObject();
    void UpdateEnemy(sf::RenderWindow* window);
    void Reset(sf::RenderWindow* window);
    ~EnemyObject();
};

#endif //VIETNAMESE_SPACE_PROGRAM_ENEMY_H
