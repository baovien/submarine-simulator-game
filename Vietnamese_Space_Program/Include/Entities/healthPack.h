#ifndef VIETNAMESE_SPACE_PROGRAM_HEALTHPACK_H
#define VIETNAMESE_SPACE_PROGRAM_HEALTHPACK_H

#include "../Core/entityManager.h"
#include "../Core/playerLives.h"
#include "../Core/soundLoader.h"

class HealthPack : public Entity
{
public:
    HealthPack(Lives* lives, SoundLoader* soundLoader);
    void updateEntity(sf::RenderWindow *window);
    virtual void collision(Entity* entity);
    sf::Clock clock; // starter clocken
private:
    Lives* lives;
    SoundLoader* soundLoader;
};
#endif //VIETNAMESE_SPACE_PROGRAM_HEALTHPACK_H
