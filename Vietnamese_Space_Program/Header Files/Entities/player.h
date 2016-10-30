#include "../Core/entityManager.h"
#include "../Core/score.h"
#include "../Core/playerLives.h"
#include "bullet.h"
#include "asteroid.h"
#include "enemy.h"
#include <iostream>

#ifndef VIETNAMESE_SPACE_PROGRAM_PLAYER_H
#define VIETNAMESE_SPACE_PROGRAM_PLAYER_H
class Player : public Entity
{
public:
    float speed=0.0f, maxSpeed=8.0f, dec=0.3f, acc=0.6f, angle = 0.0f, turnspeed=0.1f;
    bool up=0,down=0,left=0,right=0;

    Player(Score* score, EntityManager* manager, float x, float y);
    void updateEntity(sf::RenderWindow *window);
    virtual void collision(Entity* entity);

private:
    Score* score;
    Lives* lives;
    EntityManager* manager;
    bool space, nKey, mKey;
};

#endif //VIETNAMESE_SPACE_PROGRAM_PLAYER_H
