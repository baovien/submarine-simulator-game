#include "../Core/entityManager.h"
#include "player.h"

#ifndef VIETNAMESE_SPACE_PROGRAM_ENEMY_H
#define VIETNAMESE_SPACE_PROGRAM_ENEMY_H

class EnemyObject : public Entity
{
public:
    EnemyObject();
    void setEnemy(Player* player);
    void updateEntity(sf::RenderWindow *window);
    virtual void (collision(Entity* entity));

private:
    Player* player;
    int randomNumber = rand()%4;
};

#endif //VIETNAMESE_SPACE_PROGRAM_ENEMY_H
