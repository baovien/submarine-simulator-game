
#include <iostream>
#include "../../Include/Entities/enemy.h"

//Initiater enemy, koden vår er satt opp for flere spillere så case 0 er spiller 1.
EnemyObject::EnemyObject() {

    //this->player = player;
    this->load("fighter3_green_big_test.png");
    this->active = 1;
    this->groupId = 4;
    this->health = 2;
    this->randomNumber = rand() % 4;
    this->scale(0.4, 0.4);

    this->setOrigin(this->getGlobalBounds().height / 2, this->getGlobalBounds().height / 2);

    //Spawner enemy utenfor vinduet
    if (randomNumber == 1) {
        this->setPosition(-200, rand() % 720);
    } else if (randomNumber == 2) {
        this->setPosition(1480, rand() % 720);
    } else if (randomNumber == 3) {
        this->setPosition(rand() % 1480, -200);
    } else {
        this->setPosition(rand() % 1480, 920);
    }

}


void EnemyObject::setEnemy(Player *player) {
    this->player = player;
}

void EnemyObject::updateEntity(sf::RenderWindow *window) {
    //roterer objektet slik at den facer mot direction
    angle = 3.141592653599 / 180;


    // Gjør at enemien følger spilleren vha. pythagoras. Smoothere bevegelse
    this->xDistance = this->player->getPosition().x - this->getPosition().x;
    this->yDistance = this->player->getPosition().y - this->getPosition().y;
    this->distance = sqrtf((this->xDistance * this->xDistance) + (this->yDistance * this->yDistance));

    if (this->distance > 1) {
        this->velocity.x += this->xDistance * this->easingAmount;
        this->velocity.y += this->yDistance * this->easingAmount;

        if (this->velocity.x > maxSpeed) {
            this->velocity.x = maxSpeed;
            this->rotate(sin(angle));
        }
        if (this->velocity.y > maxSpeed) {
            this->velocity.y = maxSpeed;
            this->rotate(cos(angle));
        }
        if (this->velocity.x < -maxSpeed) {
            this->velocity.x = -maxSpeed;
            this->rotate(-sin(angle));
        }
        if (this->velocity.y < -maxSpeed) {
            this->velocity.y = -maxSpeed;
            this->rotate(-cos(angle));
        }

        //Endre sprites i forhold til health
        if (this->health <= 0) {       //Destroy
            this->load("explosion.png");
            this->scale(1.5, 1.5);
            this->destroyEntity();
        } else if (this->health == 1) { //Damaged
            this->load("goldDamaged.png");
        }
    }
    // Destroy enemy hvis den er utenfor skjermen
    if (this->getPosition().x < -400 || this->getPosition().x >= window->getSize().x + 400 ||
        this->getPosition().y < -400 || this->getPosition().y >= window->getSize().y + 400) {
        this->destroyEntity();
    }

    Entity::updateEntity(window);

}

//Her sjekker vi om fienden blir skutt av kuler.
void EnemyObject::collision(Entity *entity) {
    switch (entity->groupID()) {
        case 2: // Bullets
            this->health--;
            break;
    }
}