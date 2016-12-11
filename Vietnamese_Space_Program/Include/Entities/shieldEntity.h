#ifndef VIETNAMESE_SPACE_PROGRAM_SHIELDPOWERUP_H
#define VIETNAMESE_SPACE_PROGRAM_SHIELDPOWERUP_H

#include "../Core/entityManager.h"
#include "../Entities/player.h"
#include "../Core/soundLoader.h"
#include "../Core/pauseableClock.h"
#include "../Core/machine.h"
#include "shieldPowerUp.h"

class ShieldEntity : public Entity
{
public:
    ShieldEntity(sf::RenderWindow* window, Player* player, SoundLoader* soundLoader);
    void updateEntity(sf::RenderWindow *window);
    virtual void collision(Entity* entity);
private:
    bool isShieldActive;
    Player* player;
    ShieldPowerUp* shieldPowerUp;

    EntityManager* manager;
    sfuser::PauseableClock clock; // starter clocken
    SoundLoader* soundLoader;
};
#endif //VIETNAMESE_SPACE_PROGRAM_SHIELDPOWERUP_H
