#ifndef VIETNAMESE_SPACE_PROGRAM_BOSS1_H
#define VIETNAMESE_SPACE_PROGRAM_BOSS1_H

#include "../Core/entityManager.h"
#include "../Core/pauseableClock.h"
#include "player.h"
#include "../Core/utilities.h"

class BossObject : public Entity
{
public:
    BossObject(EntityManager* manager, Player* player, int mode, sf::RenderWindow* window);
    void updateEntity(sf::RenderWindow *window);
    virtual void collision(Entity* entity);

    sfuser::PauseableClock pauseableClock;
private:
    Player* player;
    Utilities* util;
    Bar* bar;
    int health, randomNumber;
    double angle;

    float xDistance, yDistance, distance, easingAmount, maxSpeed, pi, objectSpeed;
    int bulletSpeed;

    EntityManager* manager;
};
#endif //VIETNAMESE_SPACE_PROGRAM_BOSS1_H
