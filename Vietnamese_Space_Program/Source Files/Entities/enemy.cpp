#include "../../Header Files/Entities/enemy.h"
//Initiater enemy, koden vår er satt opp for flere spillere så case 0 er spiller 1.
EnemyObject::EnemyObject(float x, float y)
{

   /* this->load("gold.png");
    this->active = 1;
    this->groupId = 4;

    this->setOrigin(this->getGlobalBounds().height / 2, this->getGlobalBounds().height / 2);

    //Spawner enemy utenfor vinduet
     if (randomNumber == 1) {
        this->setPosition(-200, rand() % 720);
        this->velocity.x = 3;
    } else if (randomNumber == 2) {
        this->setPosition(1480, rand() % 720);
        this->velocity.x = -3;
    } else if (randomNumber == 3) {
        this->setPosition(rand() % 1480, -200);
        this->velocity.y = 3;
    } else {
        this->setPosition(rand() % 1480, 920);
        this->velocity.y = -3;
    }*/
}

void EnemyObject::updateEntity(sf::RenderWindow *window)
{

    if(rand()% 100 < 50){
        this->rotate(rand()% 4+1);
    }
    else{
        this->rotate(-rand()% 4+1);
    }

    if(this->getPosition().x <= -400 || this->getPosition().x >= 1600)
    {
        this->destroyEntity();
    }

    Entity::updateEntity(window);
}

//Her sjekker vi om fienden blir skutt av kuler.
void EnemyObject::collision(Entity* entity)
{
}
