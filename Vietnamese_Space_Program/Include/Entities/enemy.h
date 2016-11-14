#include "../Core/entityManager.h"
#include "player.h"

#ifndef VIETNAMESE_SPACE_PROGRAM_ENEMY_H
#define VIETNAMESE_SPACE_PROGRAM_ENEMY_H

class EnemyObject : public Entity
{
public:
    EnemyObject();
    void updateEntity(sf::RenderWindow *window);
    void setEnemy(Player* player);
    virtual void collision(Entity* entity);

private:
    Player* player;
    int health;
    int randomNumber;

    // avstanden x og y fra enemy til skipet.
    float xDistance;
    float yDistance;
    float distance;
    float easingAmount = 0.00015f;
    float maxSpeed = 1.5f;
};

#endif //VIETNAMESE_SPACE_PROGRAM_ENEMY_H
