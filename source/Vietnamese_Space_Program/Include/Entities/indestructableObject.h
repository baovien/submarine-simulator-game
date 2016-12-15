#ifndef VIETNAMESE_SPACE_PROGRAM_ASTEROID_H
#define VIETNAMESE_SPACE_PROGRAM_ASTEROID_H

#include "../Core/entityManager.h"

class IndestructableObject : public Entity
{
public:
    IndestructableObject(float x, float y, float directionX, float directionY, float angle, sf::RenderWindow* window);
    IndestructableObject(sf::RenderWindow* window, int theme);
    void updateEntity(sf::RenderWindow *window);
    virtual void collision(Entity* entity);

private:
    int health;
    int randomNumber;
    int theme;
    int random;
    float maxSpeed;
};

#endif //VIETNAMESE_SPACE_PROGRAM_ASTEROID_H
