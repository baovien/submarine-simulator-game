#include "../../Header Files/Entities/Bullet.h"
Bullet::Bullet()
{
    this->load("Sprite_ammo.png");
}

void Bullet::bulletUpdate(float x, float y)
{
    this->setPosition(x, y);

}


