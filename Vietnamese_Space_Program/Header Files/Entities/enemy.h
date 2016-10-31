#include "../Core/entityManager.h"

#ifndef VIETNAMESE_SPACE_PROGRAM_ENEMY_H
#define VIETNAMESE_SPACE_PROGRAM_ENEMY_H

class EnemyObject : public Entity
{
public:
    EnemyObject(float x, float y);
    void updateEntity(sf::RenderWindow *window);
    //void setEnemy(Player* player);
    virtual void collision(Entity* entity);

private:
    int randomNumber = rand()%4;
};

#endif //VIETNAMESE_SPACE_PROGRAM_ENEMY_H
