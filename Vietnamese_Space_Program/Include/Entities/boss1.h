#include "../Core/entityManager.h"
#include "bullet.h"

#ifndef VIETNAMESE_SPACE_PROGRAM_BOSS1_H
#define VIETNAMESE_SPACE_PROGRAM_BOSS1_H
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
    int randomNumber;
    EntityManager* manager;
};
#endif //VIETNAMESE_SPACE_PROGRAM_BOSS1_H
