#ifndef VIETNAMESE_SPACE_PROGRAM_BOSS1_H
#define VIETNAMESE_SPACE_PROGRAM_BOSS1_H

#include "../Core/entityManager.h"
#include "bullet.h"
#include "player.h"

class BossObject : public Entity
{
public:
    BossObject(EntityManager* manager, Player* player);
    void updateEntity(sf::RenderWindow *window);
    virtual void collision(Entity* entity);
    sf::Clock clock;
private:
    Player* player;
    Score* score;
    int health;
    double angle;

    float xDistance, yDistance, distance, easingAmount, maxSpeed, pi;
    int bulletSpeed;

    EntityManager* manager;
};
#endif //VIETNAMESE_SPACE_PROGRAM_BOSS1_H
