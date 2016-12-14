#include <iostream>
#include "../../Include/Entities/boss1.h"
/**
 * The boss' constructor.
 * @param manager - The entitymanager.
 * @param player
 * @param mode - The current selected gamemode.
 * @param window
 * @param theme - The current selected theme.
 * @return
 */
BossObject::BossObject(EntityManager* manager, Player* player, sf::RenderWindow* window, int theme, int bossWave)
    : player(player),
      bossWave(bossWave),
      theme(theme)
{
    if(theme == 0)this->load("blowfish.png");
    else this->load("Spacestation.png");
    this->active = 1;
    this->groupId = 5;
    this->health = 10 + (10 * bossWave);
    //this->setRotation(1);
    this->setOrigin(this->getGlobalBounds().height/2.f, this->getGlobalBounds().height/2.f);
    this->setScale((window->getSize().x/1600.f), (window->getSize().y/900.f));

    this->manager = manager;
    this->player = player;
    this->velocity.x = 30.f + (30.f* bossWave/4.f);
    this->easingAmount = 0.05f;
    this->maxSpeed = 60.f + (30.f* bossWave/4.f);
    this->pi = 3.141592653599f;
    this->bulletSpeed = 1;
    this->objectSpeed = 1;

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
    
    this->bar = new Bar(window, this->getPosition().x, this->getPosition().y + this->getGlobalBounds().height, this->health);
    this->bar->setColor(sf::Color::Red);
    this->manager->addEntity("HpBar", this->bar);
}
/**
 * Controls the boss' movement, shooting and healthbar.
 * @param window
 */
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
            this->load("explosion.png");
            this->scale(window->getSize().x/426.6f, window->getSize().y/240.f);
            this->destroyEntity();

            this->manager->addEntity("IndestructableObject", new IndestructableObject(
                    (this->getPosition().x),
                    (this->getPosition().y),
                    (sin(angle) * objectSpeed),
                    (-cos(angle) * objectSpeed),
                    (angle * 180 / pi), window));

            this->manager->addEntity("IndestructableObject", new IndestructableObject(
                    (this->getPosition().x), //Setter posisjon i x
                    (this->getPosition().y), //Setter posisjon i y
                    (-sin(angle) * objectSpeed), //Setter fart i x
                    (cos(angle) * objectSpeed), //Setter fart i y
                    ((angle + pi) * 180 / pi), window)); //Setter vinkel på kula

            this->manager->addEntity("IndestructableObject", new IndestructableObject(
                    (this->getPosition().x), //Setter posisjon i x
                    (this->getPosition().y), //Setter posisjon i y
                    (-cos(angle) * objectSpeed), //Setter fart i x
                    (-sin(angle) * objectSpeed), //Setter fart i y
                    (((angle + ((pi / 2) * 3)) * 180 / pi)), window)); //Setter vinkel på kula

            this->manager->addEntity("IndestructableObject", new IndestructableObject(
                    (this->getPosition().x), //Setter posisjon i x
                    (this->getPosition().y),//Setter posisjon i y
                    (cos(angle) * objectSpeed), //Setter fart i x
                    (sin(angle) * objectSpeed), //Setter fart i y
                    (((angle + (pi / 2)) * 180 / pi)),window)); //Setter vinkel på kula

        }

        this->pauseableClock.start();   //starter klokka
        if (this->pauseableClock.getElapsedTime().asMicroseconds() > 3000000/bossWave) {
            angle = (rand()% window->getSize().y - this->getGlobalBounds().height) * pi / 180;

            this->manager->addEntity("Bullet", new Bullet(
                    (this->getPosition().x + (this->getGlobalBounds().width / 2) * sin(angle)),
                    (this->getPosition().y - (this->getGlobalBounds().height / 2) * cos(angle)),
                    (-cos(angle) * bulletSpeed),
                    (sin(angle) * bulletSpeed),
                    ((angle * 180 / pi)+180), window, machine.selectedObjectsPointer->selectedTheme));

            this->manager->addEntity("Bullet", new Bullet(
                    (this->getPosition().x - (this->getGlobalBounds().width / 2) * sin(angle)),//Setter posisjon i x
                    (this->getPosition().y + (this->getGlobalBounds().height / 2) * cos(angle)),//Setter posisjon i y
                    (cos(angle) * bulletSpeed), //Setter fart i x
                    (-sin(angle) * bulletSpeed), //Setter fart i y
                    (((angle + pi)*180/pi)+180 ), window, machine.selectedObjectsPointer->selectedTheme)); //Setter vinkel på kula

            this->manager->addEntity("Bullet", new Bullet(
                    (this->getPosition().x - (this->getGlobalBounds().width / 2) * cos(angle)),//Setter posisjon i x
                    (this->getPosition().y - (this->getGlobalBounds().height / 2) * sin(angle)),//Setter posisjon i y
                    (-sin(angle) * bulletSpeed), //Setter fart i x
                    (-cos(angle) * bulletSpeed), //Setter fart i y
                    (((angle + ((pi / 2) * 3)) * 180 / pi)+180), window, machine.selectedObjectsPointer->selectedTheme)); //Setter vinkel på kula

            this->manager->addEntity("Bullet", new Bullet(
                    (this->getPosition().x + (this->getGlobalBounds().width / 2) * cos(angle)), //Setter posisjon i x
                    (this->getPosition().y + (this->getGlobalBounds().height / 2) * sin(angle)),//Setter posisjon i y
                    (sin(angle) * bulletSpeed), //Setter fart i x
                    (cos(angle) * bulletSpeed), //Setter fart i y
                    (((angle + (pi / 2)) * 180 / pi)+180), window,machine.selectedObjectsPointer->selectedTheme)); //Setter vinkel på kula

            this->pauseableClock.restart(); //restarter clock(nullstiller)
        }
        this->bar->updateEntity2(window, this->health , this->getPosition().x, this->getPosition().y + this->getGlobalBounds().height/2.1f);
        if(player->getPosition().x < this->getPosition().x) {
            float turn = window->getSize().x/1600.f;
            turn *= -1;
            this->setScale(turn, this->getScale().y);
        }
        else
            this->setScale((window->getSize().x/1600.f), (window->getSize().y/900.f));
        Entity::updateEntity(window);
    }
}

/**
 * Decides the outcome of a collision between the player and the given entity.
 * @param entity - entity being checked for collision.
 */
void BossObject::collision(Entity *entity) {
    switch (entity->groupID()) {
        case 2: // Bullets
            this->health--;
            break;
        case 1: // Player
            this->velocity.x *= -500;
            this->velocity.y *= -500;
            break;
    }
}