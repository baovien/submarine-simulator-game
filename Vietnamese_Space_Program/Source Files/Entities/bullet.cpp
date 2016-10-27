#include "../../Header Files/Entities/bullet.h"
#include <iostream>
Bullet::Bullet(float x, float y, float direction, float direction2)
{
    this->active = 1;
    this->groupId = 3;
    this->load("Sprite_ammo.png");
    this->velocity.y = direction;
    this->velocity.x = direction2;
    this->setPosition(x - this->getGlobalBounds().width/2, y - this->getGlobalBounds().height/2);
    // this->setScale(0.5,0.5);


}
void Bullet::updateEntity(sf::RenderWindow *window)
{
    if(this->getPosition().x < 0 || this->getPosition().x > window->getSize().x || this->getPosition().y < 0 || this->getPosition().y > window->getSize().y)
    {
        std::cout << "Helo helo" << std::endl;
        this->destroyEntity();
    }
    Entity::updateEntity(window);
}

void Bullet::collision(Entity *entity)
{
    switch(entity->groupID())
    {
        case 4: //Enemies
            this->destroyEntity();
        std::cout << "Bullet destroyed";
            break;
        default:
            // this->destroyEntity();
            break;
    }

}

