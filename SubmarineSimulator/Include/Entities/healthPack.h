#ifndef SUBMARINESIMULATORHEALTHPACK_H
#define SUBMARINESIMULATORHEALTHPACK_H

#include "../Core/entityManager.h"
#include "../Core/playerLives.h"
#include "../Core/audioLoader.h"
#include "../Core/pauseableClock.h"

class HealthPack : public Entity
{
public:
    HealthPack(Lives* lives, AudioLoader* audioLoader, sf::RenderWindow* window);
    void updateEntity(sf::RenderWindow *window);
    virtual void collision(Entity* entity);
private:
    sfuser::PauseableClock clock; // starter clocken
    Lives* lives = nullptr;
    AudioLoader* audioLoader = nullptr;
};
#endif //SUBMARINESIMULATORHEALTHPACK_H
