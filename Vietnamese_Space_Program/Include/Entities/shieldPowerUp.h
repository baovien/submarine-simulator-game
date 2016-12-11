#ifndef VIETNAMESE_SPACE_PROGRAM_ACTIVESHIELD_H
#define VIETNAMESE_SPACE_PROGRAM_ACTIVESHIELD_H

#include "../Core/entity.h"
#include "player.h"
#include "../Core/soundLoader.h"
#include "../Core/pauseableClock.h"

class ShieldPowerUp : public Entity
{
public:
    ShieldPowerUp(sf::RenderWindow* window, Player* player);
    void updateEntity(sf::RenderWindow *window);
    virtual void collision(Entity* entity);

private:
    sfuser::PauseableClock invulnerableClock;
    SoundLoader* soundLoader;
    Player* player;
    int shieldLife;
};


#endif //VIETNAMESE_SPACE_PROGRAM_ACTIVESHIELD_H
