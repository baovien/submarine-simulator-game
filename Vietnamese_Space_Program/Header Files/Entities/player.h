#pragma once

#include "../Core/entityManager.h"
#include "bullet.h"

#ifndef VIETNAMESE_SPACE_PROGRAM_PLAYER_H
#define VIETNAMESE_SPACE_PROGRAM_PLAYER_H
class Player : public Entity
{
public:
    float speed=0, maxSpeed=8, dec=0.3, acc=0.6, angle = 0, turnspeed=0.1;
    bool up=0,down=0,left=0,right=0;

    Player(EntityManager* manager, float x, float y);
    void update(sf::RenderWindow *window);
    virtual void collision(Entity* entity);

private:
    EntityManager* manager;
    bool space, nKey;
};

#endif //VIETNAMESE_SPACE_PROGRAM_PLAYER_H
