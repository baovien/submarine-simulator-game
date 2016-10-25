#pragma once

#include "player.h"
#ifndef VIETNAMESE_SPACE_PROGRAM_PLAYEROBJECT_H
#define VIETNAMESE_SPACE_PROGRAM_PLAYEROBJECT_H

class PlayerObject : public player
{
public:
    PlayerObject(int playerNumber);
    void update();
protected:
    int playerNumber;
};
#endif //VIETNAMESE_SPACE_PROGRAM_PLAYEROBJECT_H
