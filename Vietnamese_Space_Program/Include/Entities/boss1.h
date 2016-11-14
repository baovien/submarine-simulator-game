#ifndef VIETNAMESE_SPACE_PROGRAM_BOSS1_H
#define VIETNAMESE_SPACE_PROGRAM_BOSS1_H

#include "../Core/entityManager.h"
#include "bullet.h"

class Boss : public Entity
{
public:
    Boss(EntityManager* manager);
    void updateEntity(sf::RenderWindow *window);
    virtual void collision(Entity* entity);
    ~Boss();
    sf::Clock clock;
private:
    Score* score;
    int health;
    int x,y,height,width,angle;
    bool lok;
    int bulletSpeed = 7;

    EntityManager* manager;
};
#endif //VIETNAMESE_SPACE_PROGRAM_BOSS1_H
