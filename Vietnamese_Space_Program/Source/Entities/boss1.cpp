#include <iostream>
#include "../../Include/Entities/boss1.h"

BossObject::BossObject(EntityManager* manager, Player* player, int mode)
    : player(player)
{
    this->load("blowfish.png");
    this->active = 1;
    this->groupId = 5;
    this->health = 10;
    //this->setRotation(1);
    this->setOrigin(this->getGlobalBounds().height / 2, this->getGlobalBounds().height / 2);
    this->setScale(3, 3);

    this->manager = manager;
    this->player = player;
    this->velocity.x = 0.5;

    this->easingAmount = 0.000015f;
    this->maxSpeed = 0.5f;
    this->pi = 3.141592653599;
    this->bulletSpeed = 7;
    this->objectSpeed = 1.5f;
    this->randomNumber = rand()%4;

    this->score = score;

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

        this->rotate(1);
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

        } else if (this->health <= 4) { //Damaged
            this->load("goldDamaged.png");
            this->setScale(3, 3);
        }
        // Destroy enemy hvis den er utenfor skjermen
        this->pauseableClock.start();   //Tar her her opp verdien som ligger i clock

        if (this->pauseableClock.getElapsedTime().asMicroseconds() > 3000000) {
            angle = (rand()%720 - 360) * pi / 180;

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