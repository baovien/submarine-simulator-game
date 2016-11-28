#ifndef VIETNAMESE_SPACE_PROGRAM_ASTEROID_H
#define VIETNAMESE_SPACE_PROGRAM_ASTEROID_H

#include "../Core/entityManager.h"

class AsteroidObject : public Entity
{
public:
    AsteroidObject();
    void updateEntity(sf::RenderWindow *window);
    virtual void collision(Entity* entity);

private:
    int health;
    int randomNumber = rand()%4;
};

#endif //VIETNAMESE_SPACE_PROGRAM_ASTEROID_H
