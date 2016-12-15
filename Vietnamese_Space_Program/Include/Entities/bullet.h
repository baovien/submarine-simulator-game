#ifndef VIETNAMESE_SPACE_PROGRAM_BULLET_H
#define VIETNAMESE_SPACE_PROGRAM_BULLET_H

#include "../Core/score.h"
#include "../Core/entityManager.h"
#include "../Core/soundLoader.h"

class Bullet : public Entity
{
public:
    Bullet(Score* score, float x, float y, float direction, float direction2, float angle, SoundLoader* soundLoader, sf::RenderWindow* window, int fighter);
    Bullet(float x, float y, float direction, float direction2, float angle, sf::RenderWindow* window, int theme);
    void updateEntity(sf::RenderWindow *window);
    virtual void collision(Entity* entity);
private:
    int fighter;
    int theme;
    SoundLoader* soundLoader = nullptr;
    Score* score;
};
#endif //VIETNAMESE_SPACE_PROGRAM_BULLET_H
