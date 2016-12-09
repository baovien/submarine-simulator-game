#ifndef VIETNAMESE_SPACE_PROGRAM_BULLET_H
#define VIETNAMESE_SPACE_PROGRAM_BULLET_H

#include "../Core/score.h"
#include "../Core/entityManager.h"
#include "../Core/soundLoader.h"

class Bullet : public Entity
{
public:
    Bullet(Score* score, float x, float y, float direction, float direction2, float angle, SoundLoader* soundLoader);
    Bullet(float x, float y, float direction, float direction2, float angle);
    void updateEntity(sf::RenderWindow *window);
    virtual void collision(Entity* entity);
private:
    SoundLoader* soundLoader;
    Score* score;
};
#endif //VIETNAMESE_SPACE_PROGRAM_BULLET_H
