#include "../../Header Files/Entities/enemy.h"


EnemyObject::EnemyObject()
{
    this->load("ASSteroids_brown.png");
    this->velocity.x = 5.0f;
    this->velocity.y = 5.0f;
}

void EnemyObject::updateEnemy(sf::RenderWindow *window)
{


    if(this->getPosition().y - this->getGlobalBounds().height/2 < 0)
    {
        this->velocity.y *= -1;
    }
    if(this->getPosition().y + this->getGlobalBounds().height/2 > 600)
    {
        this->velocity.y *= -1;
    }
    if(this->getPosition().x - this->getGlobalBounds().width/2 < 0)
    {
        this->velocity.x *= -1;
    }
    if(this->getPosition().x + this->getGlobalBounds().width/2 > 800)
    {
        this->velocity.x *= -1;
    }

    this->rotate(2 + rand()% 1);
    EnemyEntity::updateEnemy();

}

void EnemyObject::reset(sf::RenderWindow *window)
{
}

EnemyObject::~EnemyObject()
{
}