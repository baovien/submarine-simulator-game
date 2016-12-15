#ifndef VIETNAMESE_SPACE_PROGRAM_HEALTHPACK_H
#define VIETNAMESE_SPACE_PROGRAM_HEALTHPACK_H

#include "../Core/entityManager.h"
#include "../Core/playerLives.h"
#include "../Core/soundLoader.h"
#include "../Core/pauseableClock.h"

class HealthPack : public Entity
{
public:
    HealthPack(Lives* lives, SoundLoader* soundLoader, sf::RenderWindow* window);
    void updateEntity(sf::RenderWindow *window);
    virtual void collision(Entity* entity);
private:
    sfuser::PauseableClock clock; // starter clocken
    Lives* lives = nullptr;
    SoundLoader* soundLoader = nullptr;
};
#endif //VIETNAMESE_SPACE_PROGRAM_HEALTHPACK_H
