#ifndef VIETNAMESE_SPACE_PROGRAM_ENEMY_H
#define VIETNAMESE_SPACE_PROGRAM_ENEMY_H

#include "player.h"

class EnemyObject : public Entity
{
public:
    EnemyObject(sf::RenderWindow* window, Player* player, EntityManager* manager, int mode);
    void updateEntity(sf::RenderWindow *window);
    virtual void collision(Entity* entity);

private:
    Player* player;
    int health;
    int randomNumber;
    EntityManager* manager;
    int mode;

    // avstanden x og y fra enemy til skipet.
    float xDistance, yDistance, distance;
    double angle;
    float easingAmount, maxSpeed;
};

#endif //VIETNAMESE_SPACE_PROGRAM_ENEMY_H
