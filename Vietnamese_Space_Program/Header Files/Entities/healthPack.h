#include "../Core/entityManager.h"
#include "../Core/playerLives.h"

#ifndef VIETNAMESE_SPACE_PROGRAM_HEALTHPACK_H
#define VIETNAMESE_SPACE_PROGRAM_HEALTHPACK_H

class HealthPack : public Entity
{
public:
    HealthPack(Lives* lives);
    void updateEntity(sf::RenderWindow *window);
    virtual void collision(Entity* entity);
    sf::Clock clock; // starter clocken
private:
    Lives* lives;
};
#endif //VIETNAMESE_SPACE_PROGRAM_HEALTHPACK_H
