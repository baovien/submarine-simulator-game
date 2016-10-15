#pragma once

#include "player.h"
#ifndef VIETNAMESE_SPACE_PROGRAM_PLAYEROBJECT_H
#define VIETNAMESE_SPACE_PROGRAM_PLAYEROBJECT_H
class playerObject : public player
{
public:
    playerObject(int playerNumber);
    void Update();
private:
    int playerNumber;
};
#endif //VIETNAMESE_SPACE_PROGRAM_PLAYEROBJECT_H
