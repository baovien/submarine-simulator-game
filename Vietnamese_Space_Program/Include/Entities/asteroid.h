#include "../Core/entityManager.h"

#ifndef VIETNAMESE_SPACE_PROGRAM_ASTEROID_H
#define VIETNAMESE_SPACE_PROGRAM_ASTEROID_H

class AsteroidObject : public Entity
{
public:
    AsteroidObject(float x, float y);
    void updateEntity(sf::RenderWindow *window);
    virtual void collision(Entity* entity);

private:
    int randomNumber = rand()%4;
};

#endif //VIETNAMESE_SPACE_PROGRAM_ASTEROID_H
