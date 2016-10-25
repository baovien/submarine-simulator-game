#include "../../Header Files/Entities/bullet.h"
bullet::bullet()
{
    this->load("Sprite_ammo.png");
}

void bullet::bulletUpdate(float x, float y)
{
    this->setPosition(x, y);

}


