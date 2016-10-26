#include "../Core/entity.h"
#ifndef VIETNAMESE_SPACE_PROGRAM_BULLET_H
#define VIETNAMESE_SPACE_PROGRAM_BULLET_H
class Bullet : public Entity
{
public:
    Bullet(float x, float y, float direction);
    void updateBullet(sf::RenderWindow *window);
    virtual void collision(Entity* entity);
private:
    int playerNumber;
};
#endif //VIETNAMESE_SPACE_PROGRAM_BULLET_H
