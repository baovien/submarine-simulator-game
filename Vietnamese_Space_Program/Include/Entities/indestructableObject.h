#ifndef VIETNAMESE_SPACE_PROGRAM_ASTEROID_H
#define VIETNAMESE_SPACE_PROGRAM_ASTEROID_H

#include "../Core/entityManager.h"

class IndestructableObject : public Entity
{
public:
    IndestructableObject(float x, float y, float directionX, float directionY, float angle);
    IndestructableObject();
    void updateEntity(sf::RenderWindow *window);
    virtual void collision(Entity* entity);

private:
    int health, randomNumber;
    float maxSpeed;
};

#endif //VIETNAMESE_SPACE_PROGRAM_ASTEROID_H
