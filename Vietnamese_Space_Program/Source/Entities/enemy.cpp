
#include <iostream>
#include "../../Include/Entities/enemy.h"

//Initiater enemy, koden vår er satt opp for flere spillere så case 0 er spiller 1.
EnemyObject::EnemyObject(sf::RenderWindow* window, Player* player, EntityManager* manager, int mode, SoundLoader* soundLoader)
            : player(player),
              manager(manager),
              mode(mode),
              soundLoader(soundLoader)
{
    this->load("fishCool.png");
    this->active = 1;
    this->groupId = 4;
    this->randomNumber = rand() % 4;
    this->setRotation(2);
    this->easingAmount = 0.00015f;
    this->maxSpeed = 1.5f;

    this->setOrigin(this->getGlobalBounds().height / 2, this->getGlobalBounds().height / 2);
    this->setScale(window->getSize().x/1280.0f, window->getSize().y / 720.0f);
        switch(mode)
        {
            case 1:
                this->health = 2;
                break;
            case 2:
                this->health = 3;
                break;
        }
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

void EnemyObject::updateEntity(sf::RenderWindow *window) {

    // Gjør at enemien følger spilleren vha. pythagoras. Smoothere bevegelse
    this->xDistance = this->player->getPosition().x - this->getPosition().x;
    this->yDistance = this->player->getPosition().y - this->getPosition().y;
    this->distance = sqrtf((this->xDistance * this->xDistance) + (this->yDistance * this->yDistance));

    if (this->distance > 1) {
        this->velocity.x += this->xDistance * this->easingAmount;
        this->velocity.y += this->yDistance * this->easingAmount;

        if (this->velocity.x > maxSpeed) {
            this->velocity.x = maxSpeed;
        }
        if (this->velocity.y > maxSpeed) {
            this->velocity.y = maxSpeed;
        }
        if (this->velocity.x < -maxSpeed) {
            this->velocity.x = -maxSpeed;
        }
        if (this->velocity.y < -maxSpeed) {
            this->velocity.y = -maxSpeed;
        }
        // Destroy enemy hvis den er utenfor skjermen
        if (this->getPosition().x <= -400 || this->getPosition().x >= 1600) {
            this->destroyEntity();
        }
    }
    int randomNumber2;
    randomNumber2 = rand() % 1000;
    if(this->mode == 2 && randomNumber2 < 5)
    {
        int randomNumber3 = rand() % 2;
        if(randomNumber3 == 0)this->soundLoader->playSound(soundLoader->ENEMY_SHOOT1);
        if(randomNumber3 == 1)this->soundLoader->playSound(soundLoader->ENEMY_SHOOT2);
        this->manager->addEntity("bullet", new Bullet(this->getPosition().x, this->getPosition().y, yDistance/100, xDistance/100, 0));
    }
    if(player->getPosition().x < this->getPosition().x){
        int hehe = window->getSize().x/1280;
        hehe *= -1;
        this->setScale(hehe, window->getSize().y / 720);
    }
    else {
        this->setScale(window->getSize().x/1280, window->getSize().y / 720);
    }
    if(this->health == 1){
        this->load("fishFeelsHurt.png");
    }
    else if(this->health <= 0){
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

        case 4:
            this->velocity.x *= -5;
            this->velocity.y *= -5;
            entity->velocity.x = this->velocity.x * -5;
            entity->velocity.y = this->velocity.y * -5;

    }
}