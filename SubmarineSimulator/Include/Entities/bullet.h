#ifndef SUBMARINESIMULATORBULLET_H
#define SUBMARINESIMULATORBULLET_H

#include "../Core/score.h"
#include "../Core/entityManager.h"
#include "../Core/audioLoader.h"

class Bullet : public Entity
{
public:
    Bullet(Score* score, float x, float y, float direction, float direction2, float angle, AudioLoader* audioLoader, sf::RenderWindow* window, int fighter);
    Bullet(float x, float y, float direction, float direction2, float angle, sf::RenderWindow* window, int theme);
    void updateEntity(sf::RenderWindow *window);
    virtual void collision(Entity* entity);
private:
    int fighter;
    int theme;
    AudioLoader* audioLoader = nullptr;
    Score* score;
};
#endif //SUBMARINESIMULATORBULLET_H
