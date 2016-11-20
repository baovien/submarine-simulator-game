#ifndef VIETNAMESE_SPACE_PROGRAM_ENEMY_H
#define VIETNAMESE_SPACE_PROGRAM_ENEMY_H

#include "player.h"

class EnemyObject : public Entity
{
public:
    EnemyObject();
    void setEnemy(Player* player);
    void updateEntity(sf::RenderWindow *window);
    virtual void collision(Entity* entity);

private:
    Player* player;
    int health;
    int randomNumber;

    // avstanden x og y fra enemy til skipet.
    float xDistance, yDistance, distance;
    double angle;
    float easingAmount = 0.00015f;
    float maxSpeed = 1.5f;
};

#endif //VIETNAMESE_SPACE_PROGRAM_ENEMY_H
