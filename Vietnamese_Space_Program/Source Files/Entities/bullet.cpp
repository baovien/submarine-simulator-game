#include "../../Header Files/Entities/bullet.h"
#include <iostream>

Bullet::Bullet(Score* score, float x, float y, float direction, float direction2)
{
    this->active = 1;
    this->groupId = 2;
    this->load("Sprite_ammo.png");
    this->velocity.y = direction;
    this->velocity.x = direction2;
    this->setOrigin(this->getGlobalBounds().width/2, this->getGlobalBounds().height/2);
    this->setPosition(x, y);
    this->score = score;
    // this->setScale(0.5,0.5);


}
void Bullet::updateEntity(sf::RenderWindow *window)
{
    if(this->getPosition().x < 0 || this->getPosition().x > window->getSize().x || this->getPosition().y < 0 || this->getPosition().y > window->getSize().y)
    {
        this->destroyEntity();
    }
    Entity::updateEntity(window);
}

void Bullet::collision(Entity *entity)
{
    switch(entity->groupID())
    {
        case 0:
            break;

        case 1: // Player
            break;

        case 3: // Asteroids
            entity->destroyEntity();
            this->destroyEntity();
            this->score->incrementScore();
            break;

        case 4: // Enemy
            entity->destroyEntity();
            this->destroyEntity();
            this->score->incrementScore();
            break;
    }
}

