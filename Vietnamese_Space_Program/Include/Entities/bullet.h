#include "../Core/entityManager.h"
#include "../Core/score.h"

#ifndef VIETNAMESE_SPACE_PROGRAM_BULLET_H
#define VIETNAMESE_SPACE_PROGRAM_BULLET_H
class Bullet : public Entity
{
public:
    Bullet(Score* score, float x, float y, float direction, float direction2, float angle);
    Bullet(float x, float y, float direction, float direction2, float angle);
    void updateEntity(sf::RenderWindow *window);
    virtual void collision(Entity* entity);
private:
    Score* score;
};
#endif //VIETNAMESE_SPACE_PROGRAM_BULLET_H
