#include "../Core/entityManager.h"
#include "../Core/score.h"
#include "bullet.h"
#ifndef VIETNAMESE_SPACE_PROGRAM_ENEMY2_H
#define VIETNAMESE_SPACE_PROGRAM_ENEMY2_H


class Enemy2Object : public Entity
{
public:
    Enemy2Object(int i, int j, sf::RenderWindow* window);
    void updateEntity(sf::RenderWindow *window);
    virtual void collision(Entity* entity);

private:
    int health;
    EntityManager* manager;

};


#endif //VIETNAMESE_SPACE_PROGRAM_ENEMY2_H
