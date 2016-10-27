#include "../../Header Files/Entities/enemy.h"

//Initiater player, koden vår er satt opp for flere spillere så case 0 er spiller 1.
EnemyObject::EnemyObject(float x, float y, float direction)
{

    this->load("enemy.png");
    this->active = 1;
    this->groupId = 4;
    this->setOrigin(this->getGlobalBounds().height/2, this->getGlobalBounds().height/2);
    this->velocity.x = -3;
    this->setPosition(1500,rand() % 500 + 50);

}
//update funksjonen har kontroll på bevegelsen til player.
void EnemyObject::updateEnemy(sf::RenderWindow *window)
{
    if(this->getPosition().x <= 0)
    {
        this->destroyEntity();
    }
    Entity::update(window);
    this->setRotation(2+rand() % 1);
}
//Her sjekker vi om fienden blir skutt av kuler.
void EnemyObject::collision(Entity* entity)
{
    switch(entity->groupID())
    {
        case 0:
            break;
        case 3:
            this->destroyEntity();
            break;
    }
}