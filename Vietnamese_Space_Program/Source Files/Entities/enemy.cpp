#include "../../Header Files/Entities/enemy.h"


EnemyObject::EnemyObject()
{
    this->load("enemy.png");

    this->velocity.x = 5.0f;
    this->velocity.y = 5.0f;
}

void EnemyObject::updateEnemy(sf::RenderWindow *window)
{

    if (this->getPosition().y < 0 || this->getPosition().y + this->getGlobalBounds().height > window->getSize().y)
    {
        this->velocity.y *= -1;
    }

    if (this->getPosition().x < 0 || this->getPosition().x + this->getGlobalBounds().width > window->getSize().x)
    {
        this->velocity.x *= -1;
    }

    if(this->getPosition().y + this->getGlobalBounds().height > window->getSize().y)
    {
        this->move(0, -1.0f);
    }
    if(this->getPosition().y < 0)
    {
        this->move(0, 1.0f);
    }
    if(this->getPosition().x < 0)
    {
        this->move(1.0f, 0);
    }
    if(this->getPosition().x + this->getGlobalBounds().width > window->getSize().x)
    {
        this->move(-1.0f, 0);
    }

    EnemyEntity::updateEnemy();
}

void EnemyObject::reset(sf::RenderWindow *window)
{
}

EnemyObject::~EnemyObject()
{
}