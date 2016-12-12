#ifndef VIETNAMESE_SPACE_PROGRAM_SHIELDPOWERUP_H
#define VIETNAMESE_SPACE_PROGRAM_SHIELDPOWERUP_H

#include "../Core/entityManager.h"
#include "../Core/entity.h"
#include "../Core/soundLoader.h"
#include "../Core/pauseableClock.h"
#include "../Core/machine.h"
#include "player.h"

class ShieldEntity : public Entity
{
public:
    ShieldEntity(sf::RenderWindow* window, Player* player, SoundLoader* soundLoader);
    void updateEntity(sf::RenderWindow *window);
    virtual void collision(Entity* entity);
private:
    sfuser::PauseableClock clock; // starter clocken
    bool isShieldActive;
    Player* player;
    sfuser::PauseableClock invincibleClock;

    EntityManager* manager;
    SoundLoader* soundLoader;
public:
    bool* isShieldActivePointer = &isShieldActive;
};
#endif //VIETNAMESE_SPACE_PROGRAM_SHIELDPOWERUP_H
