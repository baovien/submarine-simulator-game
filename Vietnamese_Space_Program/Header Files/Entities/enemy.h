#pragma once
#include "enemyEntity.h"
#include "playerLives.h"

#ifndef VIETNAMESE_SPACE_PROGRAM_ENEMY_H
#define VIETNAMESE_SPACE_PROGRAM_ENEMY_H

class EnemyObject : public EnemyEntity
{
public:
    EnemyObject();
    void updateEnemy(sf::RenderWindow *window);
    void reset(sf::RenderWindow *window);
    ~EnemyObject();

};

#endif //VIETNAMESE_SPACE_PROGRAM_ENEMY_H
