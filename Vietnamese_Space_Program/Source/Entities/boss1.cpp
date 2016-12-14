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
BossObject::BossObject(EntityManager* manager, Player* player, int mode, sf::RenderWindow* window, int theme)
    : player(player)
{
    this->theme = theme;
    if(theme == 0)this->load("blowfish.png");
    else this->load("Spacestation.png");
    this->active = 1;
    this->groupId = 5;
    this->health = 10;
    //this->setRotation(1);
    this->setOrigin(this->getGlobalBounds().height/2.f, this->getGlobalBounds().height/2.f);
    this->setScale((window->getSize().x/1280.f), (window->getSize().y/720.f));

    this->manager = manager;
    this->player = player;
    this->velocity.x = (window->getSize().x/1280.f)*100;

    this->easingAmount = 0.05f;
    this->maxSpeed = (window->getSize().x/1280.f)*100;
    this->pi = 3.141592653599f;
    this->bulletSpeed = (window->getSize().x/1280.f);
    this->objectSpeed = (window->getSize().x/1280.f);

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
            //this->load("explosion.png");
            //this->scale(3, 3);
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
        if (this->pauseableClock.getElapsedTime().asMicroseconds() > 3000000) {
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

        this->bar->updateEntity2(window, 12*this->health , this->getPosition().x, this->getPosition().y + this->getGlobalBounds().height/2.1f);
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
        case 5: // Boss
            this->velocity.x *= -500;
            this->velocity.y *= -500;
            entity->velocity.x *= -this->velocity.x;
            entity->velocity.y *= -this->velocity.y;
            break;
    }
}