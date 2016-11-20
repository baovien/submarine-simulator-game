#include "../../Include/Entities/bullet.h"
#include <iostream>

Bullet::Bullet(Score* score, float x, float y, float direction, float direction2, float angle)
{
    this->active = 1;
    this->groupId = 2;
    this->load("laser.png");
    this->velocity.y = direction;
    this->velocity.x = direction2;
    this->setOrigin(this->getGlobalBounds().width/2, this->getGlobalBounds().height/2);
    this->setPosition(x, y);
    this->setRotation(angle);
    this->score = score;
    this->setScale(1.5,1.5);


}
Bullet::Bullet(float x, float y, float direction, float direction2, float angle)
{
    this->active = 1;
    this->groupId = 6;
    this->load("laserEnemy.png");
    this->velocity.y = direction;
    this->velocity.x = direction2;
    this->setOrigin(this->getGlobalBounds().width/2, this->getGlobalBounds().height/2);
    this->setPosition(x, y);
    this->setRotation(angle);
    this->setScale(3,3);
}
void Bullet::updateEntity(sf::RenderWindow *window)
{
    if(this->getPosition().x < 0 || this->getPosition().x > window->getSize().x||
       this->getPosition().y < 0 || this->getPosition().y > window->getSize().y)
    {
        this->destroyEntity();
    }
    Entity::updateEntity(window);
}

void Bullet::collision(Entity *entity)
{
    if(this->groupId == 2)
    {
        switch (entity->groupID())
        {
            case 3: // Asteroids
                entity->destroyEntity();
                this->destroyEntity();
                this->score->incrementScore();
                break;

            case 4: // Enemy
                this->destroyEntity();
                this->score->incrementScore();
                break;

            case 5: // Boss
                this->destroyEntity();
                this->score->incrementScore();
        }
    }
}

