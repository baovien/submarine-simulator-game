#pragma once
#include "../Core/entityManager.h"
#include "../Core/playerLives.h"

#ifndef VIETNAMESE_SPACE_PROGRAM_ENEMY_H
#define VIETNAMESE_SPACE_PROGRAM_ENEMY_H

class EnemyObject : public Entity
{
public:
    EnemyObject(Lives* lives,float x, float y);
    void updateEntity(sf::RenderWindow *window);
    //void setEnemy(Player* player);
    virtual void collision(Entity* entity);

private:
    EntityManager* manager;
    int randomNumber = rand()%4;
    Lives* lives;
};

#endif //VIETNAMESE_SPACE_PROGRAM_ENEMY_H
