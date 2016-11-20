#include <iostream>
#include "../../Include/Entities/boss1.h"

BossObject::BossObject(EntityManager* manager, Player* player) {
    this->load("gold.png");
    this->active = 1;
    this->groupId = 5;
    this->health = 10;
    //this->setRotation(1);
    this->setOrigin(this->getGlobalBounds().height / 2, this->getGlobalBounds().height / 2);
    this->setScale(3, 3);
    this->setPosition(-50, 300);
    this->manager = manager;
    this->player = player;
    this->velocity.x = 0.5;
    this->score = score;
}

void BossObject::updateEntity(sf::RenderWindow *window) {
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

        this->rotate(1);
        //Endre sprites i forhold til health
        if (this->health <= 0) {   //Destroy
            this->load("explosion.png");
            this->scale(3, 3);
            this->destroyEntity();
        } else if (this->health <= 4) { //Damaged
            this->load("goldDamaged.png");
            this->setScale(3, 3);
        }
        // Destroy enemy hvis den er utenfor skjermen
        sf::Time elapsed1 = clock.getElapsedTime(); //Tar her her opp verdien som ligger i klokk

        if (elapsed1.asMicroseconds() > 1350000) {
            angle = (rand()%720 - 360) * pi / 180;
            std::cout << angle << std::endl;

            this->manager->addEntity("Bullet", new Bullet(
                    (this->getPosition().x + (this->getGlobalBounds().width / 2) * sin(angle)),
                    (this->getPosition().y - (this->getGlobalBounds().height / 2) * cos(angle)),
                    (-cos(angle) * bulletSpeed),
                    (sin(angle) * bulletSpeed),
                    (angle * 180 / pi)));
            
            this->manager->addEntity("Bullet", new Bullet(
                    (this->getPosition().x - (this->getGlobalBounds().width / 2) * sin(angle)),//Setter posisjon i x
                    (this->getPosition().y + (this->getGlobalBounds().height / 2) * cos(angle)),//Setter posisjon i y
                    (cos(angle) * bulletSpeed), //Setter fart i x
                    (-sin(angle) * bulletSpeed), //Setter fart i y
                    ((angle + pi) * 180 / pi))); //Setter vinkel på kula

            this->manager->addEntity("Bullet", new Bullet(
                    (this->getPosition().x - (this->getGlobalBounds().width / 2) * cos(angle)),//Setter posisjon i x
                    (this->getPosition().y - (this->getGlobalBounds().height / 2) * sin(angle)),//Setter posisjon i y
                    (-sin(angle) * bulletSpeed), //Setter fart i x
                    (-cos(angle) * bulletSpeed), //Setter fart i y
                    (((angle + ((pi / 2) * 3)) * 180 / pi)))); //Setter vinkel på kula

            this->manager->addEntity("Bullet", new Bullet(
                    (this->getPosition().x + (this->getGlobalBounds().width / 2) * cos(angle)), //Setter posisjon i x
                    (this->getPosition().y + (this->getGlobalBounds().height / 2) * sin(angle)),//Setter posisjon i y
                    (sin(angle) * bulletSpeed), //Setter fart i x
                    (cos(angle) * bulletSpeed), //Setter fart i y
                    (((angle + (pi / 2)) * 180 / pi)))); //Setter vinkel på kula

            clock.restart(); //restarter clock(nullstiller)
            velocity.x = 2;

        }


        Entity::updateEntity(window);
    }
}

void BossObject::collision(Entity *entity) {
    switch (entity->groupID()) {
        case 2: // Bullets
            this->health--;
            break;
    }
}