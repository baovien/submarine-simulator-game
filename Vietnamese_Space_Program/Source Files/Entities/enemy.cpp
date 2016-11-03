
#include <iostream>
#include "../../Header Files/Entities/enemy.h"

//Initiater enemy, koden vår er satt opp for flere spillere så case 0 er spiller 1.
EnemyObject::EnemyObject()
{

    this->player = player;
    this->load("gold.png");
    this->active = 1;
    this->groupId = 4;
    this->health = 2;

    this->setOrigin(this->getGlobalBounds().height / 2, this->getGlobalBounds().height / 2);

    //Spawner enemy utenfor vinduet
    if (randomNumber == 1) {
        this->setPosition(-200, rand() % 720);
        this->velocity.x = 3;
    }
    else if (randomNumber == 2) {
        this->setPosition(1480, rand() % 720);
        this->velocity.x = -3;
    }
    else if (randomNumber == 3) {
        this->setPosition(rand() % 1480, -200);
        this->velocity.y = 3;
    }
    else {
        this->setPosition(rand() % 1480, 920);
        this->velocity.y = -3;
    }
}
void EnemyObject::setEnemy(Player *player) {
    this->player = player;
}

void EnemyObject::updateEntity(sf::RenderWindow *window)
{

    if (this->getPosition().y + this->getGlobalBounds().height / 2 < player->getPosition().y) {
        this->velocity.y = 2;
    }
    if (this->getPosition().y + this->getGlobalBounds().height / 2 > player->getPosition().y) {
        this->velocity.y = -2;
    }
    if (this->getPosition().x + this->getGlobalBounds().height / 2 < player->getPosition().x) {
        this->velocity.x = 2;
    }
    if (this->getPosition().x + this->getGlobalBounds().height / 2 > player->getPosition().x) {
        this->velocity.x = -2;
    }


    if(this->health <= 0){
        this->destroyEntity();
    }

    this->rotate(-(2+rand() % 4));

    // Destroy enemy hvis den er utenfor skjermen
    if(this->getPosition().x <= -400 || this->getPosition().x >= 1600)
    {
        this->destroyEntity();
    }

    Entity::updateEntity(window);
}

//Her sjekker vi om fienden blir skutt av kuler.
void EnemyObject::collision(Entity* entity)
{
    switch (entity->groupID())
    {
        case 2:
            entity->destroyEntity();
            this->health -= 1;
            break;
        case 1:
            this->health -= 1;
            break;
    }
}