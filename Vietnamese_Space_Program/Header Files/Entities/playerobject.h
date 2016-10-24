#pragma once

#include "Player.h"
#ifndef VIETNAMESE_SPACE_PROGRAM_PLAYEROBJECT_H
#define VIETNAMESE_SPACE_PROGRAM_PLAYEROBJECT_H

class PlayerObject : public Player
{
public:
    PlayerObject(int playerNumber);
    void Update();
protected:
    int playerNumber;
};
#endif //VIETNAMESE_SPACE_PROGRAM_PLAYEROBJECT_H
