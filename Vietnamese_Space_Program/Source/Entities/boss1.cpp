#include <iostream>
#include "../../Include/Entities/boss1.h"

BossObject::BossObject(EntityManager* manager, Player* player, int mode, sf::RenderWindow* window)
    : player(player)
{
    this->load("blowfish.png");
    this->active = 1;
    this->groupId = 5;
    this->health = 10;
    //this->setRotation(1);
    this->setOrigin(this->getGlobalBounds().height/2, this->getGlobalBounds().height/2);
    this->setScale(window->getSize().x/1280, window->getSize().y/720);

    this->manager = manager;
    this->player = player;
    this->velocity.x = window->getSize().x/853;

    this->easingAmount = 0.000015f;
    this->maxSpeed = window->getSize().x/853;
    this->pi = 3.141592653599;
    this->bulletSpeed = window->getSize().x/256;
    this->objectSpeed = window->getSize().x/853;

    this->randomNumber = rand()%4;
    if (randomNumber == 1) {
        this->setPosition(0 - this->getGlobalBounds().width * 2, rand() % window->getSize().y);
    } else if (randomNumber == 2) {
        this->setPosition(window->getSize().x + this->getGlobalBounds().width * 2, rand() % window->getSize().y);
    } else if (randomNumber == 3) {
        this->setPosition(rand() % window->getSize().x + this->getGlobalBounds().width* 2, 0 - this->getGlobalBounds().height * 2);
    } else {
        this->setPosition(rand() % window->getSize().x + this->getGlobalBounds().width * 2, window->getSize().y + this->getGlobalBounds().height * 2);
    }
    
    this->bar = new Bar(window, this->getPosition().x, this->getPosition().y + this->getGlobalBounds().height);
    this->manager->addEntity("HpBar", this->bar);
}

void BossObject::updateEntity(sf::RenderWindow *window) {

    // Gjør at bossen følger spilleren vha. pythagoras. Smoothere bevegelse
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
        //Endre sprites i forhold til health
        if (this->health <= 0) {   //Destroy
            //this->load("explosion.png");
            //this->scale(3, 3);
            this->destroyEntity();

            this->manager->addEntity("IndestructableObject", new IndestructableObject(
                    (this->getPosition().x),
                    (this->getPosition().y),
                    (sin(angle) * objectSpeed),
                    (-cos(angle) * objectSpeed),
                    (angle * 180 / pi)));

            this->manager->addEntity("IndestructableObject", new IndestructableObject(
                    (this->getPosition().x), //Setter posisjon i x
                    (this->getPosition().y), //Setter posisjon i y
                    (-sin(angle) * objectSpeed), //Setter fart i x
                    (cos(angle) * objectSpeed), //Setter fart i y
                    ((angle + pi) * 180 / pi))); //Setter vinkel på kula

            this->manager->addEntity("IndestructableObject", new IndestructableObject(
                    (this->getPosition().x), //Setter posisjon i x
                    (this->getPosition().y), //Setter posisjon i y
                    (-cos(angle) * objectSpeed), //Setter fart i x
                    (-sin(angle) * objectSpeed), //Setter fart i y
                    (((angle + ((pi / 2) * 3)) * 180 / pi)))); //Setter vinkel på kula

            this->manager->addEntity("IndestructableObject", new IndestructableObject(
                    (this->getPosition().x), //Setter posisjon i x
                    (this->getPosition().y),//Setter posisjon i y
                    (cos(angle) * objectSpeed), //Setter fart i x
                    (sin(angle) * objectSpeed), //Setter fart i y
                    (((angle + (pi / 2)) * 180 / pi)))); //Setter vinkel på kula

        }

        this->pauseableClock.start();   //starter klokka
        if (this->pauseableClock.getElapsedTime().asMicroseconds() > 3000000) {
            angle = (rand()% window->getSize().y - this->getGlobalBounds().height) * pi / 180;

            this->manager->addEntity("Bullet", new Bullet(
                    (this->getPosition().x + (this->getGlobalBounds().width / 2) * sin(angle)),
                    (this->getPosition().y - (this->getGlobalBounds().height / 2) * cos(angle)),
                    (-cos(angle) * bulletSpeed),
                    (sin(angle) * bulletSpeed),
                    (angle * 180 / pi), window));

            this->manager->addEntity("Bullet", new Bullet(
                    (this->getPosition().x - (this->getGlobalBounds().width / 2) * sin(angle)),//Setter posisjon i x
                    (this->getPosition().y + (this->getGlobalBounds().height / 2) * cos(angle)),//Setter posisjon i y
                    (cos(angle) * bulletSpeed), //Setter fart i x
                    (-sin(angle) * bulletSpeed), //Setter fart i y
                    ((angle + pi) * 180 / pi), window)); //Setter vinkel på kula

            this->manager->addEntity("Bullet", new Bullet(
                    (this->getPosition().x - (this->getGlobalBounds().width / 2) * cos(angle)),//Setter posisjon i x
                    (this->getPosition().y - (this->getGlobalBounds().height / 2) * sin(angle)),//Setter posisjon i y
                    (-sin(angle) * bulletSpeed), //Setter fart i x
                    (-cos(angle) * bulletSpeed), //Setter fart i y
                    (((angle + ((pi / 2) * 3)) * 180 / pi)), window)); //Setter vinkel på kula

            this->manager->addEntity("Bullet", new Bullet(
                    (this->getPosition().x + (this->getGlobalBounds().width / 2) * cos(angle)), //Setter posisjon i x
                    (this->getPosition().y + (this->getGlobalBounds().height / 2) * sin(angle)),//Setter posisjon i y
                    (sin(angle) * bulletSpeed), //Setter fart i x
                    (cos(angle) * bulletSpeed), //Setter fart i y
                    (((angle + (pi / 2)) * 180 / pi)), window)); //Setter vinkel på kula

            this->pauseableClock.restart(); //restarter clock(nullstiller)
        }

        this->bar->updateEntity2(window, 12*this->health , this->getPosition().x, this->getPosition().y + this->getGlobalBounds().height/2.1);
        Entity::updateEntity(window);
    }
}

void BossObject::collision(Entity *entity) {
    switch (entity->groupID()) {
        case 2: // Bullets
            this->health--;
            break;
        case 1: // Player
            this->velocity.x *= -5;
            this->velocity.y *= -5;
            break;
        case 5: // Boss
            this->velocity.x *= -5;
            this->velocity.y *= -5;
            entity->velocity.x *= -this->velocity.x;
            entity->velocity.y *= -this->velocity.y;
            break;
    }
}