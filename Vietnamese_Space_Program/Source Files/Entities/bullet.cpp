#include "../../Header Files/Entities/bullet.h"
Bullet::Bullet(float x, float y, float direction)
{
    this->active = 1;
    this->groupId = 3;
    this->load("Sprite_ammo.png");
    this->velocity.y = 10;
    this->setPosition(400,400);

}
void Bullet::updateBullet(sf::RenderWindow *window)
{
    if(this->getPosition().x <= 0 || this->getPosition().x + this->getGlobalBounds().width >= window->getSize().x)
    {
        this->destroyEntity();
    }
    Entity::update(window);
}

void Bullet::collision(Entity *entity)
{
    switch(entity->groupID())
    {
        case 3:
            break;
        default:
            this->destroyEntity();
            break;
    }

}

