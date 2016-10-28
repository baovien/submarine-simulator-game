#include "../Core/entityManager.h"
#include "asteroid.h"
#include "enemy.h"

#ifndef VIETNAMESE_SPACE_PROGRAM_BULLET_H
#define VIETNAMESE_SPACE_PROGRAM_BULLET_H
class Bullet : public Entity
{
public:
    Bullet(float x, float y, float direction, float direction2);
    void updateEntity(sf::RenderWindow *window);
    virtual void collision(Entity* entity);
private:
};
#endif //VIETNAMESE_SPACE_PROGRAM_BULLET_H
