#include "../../Header Files/Entities/enemy.h"

EnemyObject::EnemyObject(float x, float y, float direction)
{

    this->load("ASSteroids_brown.png");
    this->active = 1;
    this->groupId = 3;
    this->setOrigin(this->getGlobalBounds().height/2, this->getGlobalBounds().height/2);
    this->velocity.x = -10;
    this->setPosition(1500,rand() % 500 + 50);

}
void EnemyObject::updateEntity(sf::RenderWindow *window)
{
    if(this->getPosition().x <= 0)
    {
        this->destroyEntity();
    }
    Entity::updateEntity(window);
    this->setRotation(2+rand() % 1);
}
void EnemyObject::collision(Entity* entity)
{
}