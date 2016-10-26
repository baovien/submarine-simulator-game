#pragma once

#include "../Core/entity.h"
#ifndef VIETNAMESE_SPACE_PROGRAM_PLAYER_H
#define VIETNAMESE_SPACE_PROGRAM_PLAYER_H
class Player : public Entity
{
public:
    Player(float x, float y);
    void updatePlayer();
    virtual void collision(Entity* entity);
private:
    int playerNumber;
};

#endif //VIETNAMESE_SPACE_PROGRAM_PLAYER_H
