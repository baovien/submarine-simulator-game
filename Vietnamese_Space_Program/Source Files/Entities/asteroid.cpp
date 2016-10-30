#include "../../Header Files/Entities/asteroid.h"

//Initiater asteroid, koden vår er satt opp for flere spillere så case 0 er spiller 1.
AsteroidObject::AsteroidObject(float x, float y, float direction)
{

    this->load("ASSteroids_brown.png");
    this->active = 1;
    this->groupId = 3;
    this->velocity.x = -3;
    this->setOrigin(this->getGlobalBounds().height/2, this->getGlobalBounds().height/2);
    this->setPosition(1500,rand() % 500 + 50);


}
//update funksjonen har kontroll på bevegelsen til player.
void AsteroidObject::updateEntity(sf::RenderWindow *window)
{
    if(this->getPosition().x <= 0)
    {
        this->destroyEntity();
    }
    Entity::updateEntity(window);
    this->setRotation(2+rand() % 10);
}
//Her sjekker vi om fienden blir skutt av kuler.
void AsteroidObject::collision(Entity* entity)
{
    switch(entity->groupID())
    {
        case 3: //Bullets
            this->destroyEntity();
            break;
    }
}