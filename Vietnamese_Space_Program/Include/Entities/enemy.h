#ifndef VIETNAMESE_SPACE_PROGRAM_ENEMY_H
#define VIETNAMESE_SPACE_PROGRAM_ENEMY_H

#include "player.h"
#include "../Core/audioLoader.h"

class EnemyObject : public Entity
{
public:
    EnemyObject(sf::RenderWindow* window, Player* player, EntityManager* manager, int mode, AudioLoader* audioLoader, int theme);
    void updateEntity(sf::RenderWindow *window);
    virtual void collision(Entity* entity);

private:
    AudioLoader* audioLoader = nullptr;
    Player* player = nullptr;
    int health;
    int randomNumber;
    EntityManager* manager = nullptr;
    float mode;
    int theme;

    // avstanden x og y fra enemy til skipet.
    float xDistance, yDistance, distance;
    float easingAmount, maxSpeed;
};

#endif //VIETNAMESE_SPACE_PROGRAM_ENEMY_H
