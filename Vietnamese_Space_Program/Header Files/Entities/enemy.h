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
};

#endif //VIETNAMESE_SPACE_PROGRAM_ENEMY_H
