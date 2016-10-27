#include "../Core/entity.h"
#include "enemy.h"
#include "../Core/entityManager.h"

#ifndef VIETNAMESE_SPACE_PROGRAM_BULLET_H
#define VIETNAMESE_SPACE_PROGRAM_BULLET_H
class Bullet : public Entity
{
public:
    Bullet(float x, float y, float direction);
    void updateBullet(sf::RenderWindow *window);
    virtual void collision(Entity* entity);
private:
};
#endif //VIETNAMESE_SPACE_PROGRAM_BULLET_H
