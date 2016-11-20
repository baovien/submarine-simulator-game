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

    float xDistance, yDistance, distance;
    float easingAmount = 0.00015f;
    float maxSpeed = 0.5f;
    float pi = 3.141592653599;
    int bulletSpeed = 7;

    EntityManager* manager;
};
#endif //VIETNAMESE_SPACE_PROGRAM_BOSS1_H
