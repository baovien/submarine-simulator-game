#include "../../Header Files/Entities/bulletObject.h"
bulletObject::bulletObject()
{
    this->Load("Sprite_ammo.png");
}
void bulletObject::Updatebullet()
{
    this->move(+1, +1);
}