#ifndef VIETNAMESE_SPACE_PROGRAM_BOSS1_H
#define VIETNAMESE_SPACE_PROGRAM_BOSS1_H

#include "../Core/entityManager.h"
#include "../Core/pauseableClock.h"
#include "player.h"
#include "../Core/utilities.h"

class BossObject : public Entity
{
public:
    BossObject(EntityManager* manager, Player* player, sf::RenderWindow* window, int theme, int bossWave);
    void updateEntity(sf::RenderWindow *window);
    virtual void collision(Entity* entity);

    sfuser::PauseableClock pauseableClock;
private:
    Player* player = nullptr;
    Utilities* util = nullptr;
    Bar* bar  = nullptr;
    int health, randomNumber;
    double angle;
    int theme;
    int bossWave;
    float xDistance, yDistance, distance, easingAmount, maxSpeed, pi, objectSpeed;
    float bulletSpeed;

    EntityManager* manager = nullptr;
};
#endif //VIETNAMESE_SPACE_PROGRAM_BOSS1_H
