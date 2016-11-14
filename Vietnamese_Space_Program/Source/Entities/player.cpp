#include <iostream>
#include "../../Include/Entities/player.h"


Player::Player(Lives *lives, Score *score, EntityManager *manager, float x, float y, sf::RenderWindow *window, int gamemode)
{
    this->manager = manager;
    this->gamemode = gamemode;
    this->overheat = overheat;
    this->score = score;
    this->lives = lives;
    this->active = 1;
    this->groupId = 1;
    switch (gamemode) {
        case 1:
            this->load("fighter3_green_big_test.png");
            this->setOrigin(this->getGlobalBounds().height / 2, this->getGlobalBounds().height / 2);
            this->space = false;
            this->setPosition(x, y);
            this->manager->addEntity("Overheat", new Overheat(window));
            this->scale(0.4, 0.4);
            break;
        case 2:
            this->load("fighter2_blue_big.png");
            this->setOrigin(this->getGlobalBounds().height / 2, this->getGlobalBounds().height / 2);
            this->space = false;
            this->setPosition(x - this->getGlobalBounds().width, y - this->getGlobalBounds().height / 2);
            break;
        default:
            break;
    }
}

//update funksjonen har kontroll på bevegelsen til player.
void Player::updateEntity(sf::RenderWindow *window)
{
    int overheatValue = 0;
    up = 0, down = 0, left = 0, right = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))left = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))right = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))up = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))down = 1;

    switch (this->gamemode)
    {
        case 1:
            //Bevegelse
            if (right && speed != 0) angle += turnspeed * speed / maxSpeed;
            if (left && speed != 0) angle -= turnspeed * speed / maxSpeed;

            if (up && speed < maxSpeed) {
                if (speed < 0) speed += dec;
                else speed += acc;
            }
            if (down && speed > -maxSpeed) {
                if (speed > 0) {
                    speed -= dec;
                } else {
                    speed -= acc;
                }
            }
            if (!up && !down) {
                if (speed - dec > 0) speed -= dec;
                else if (speed + dec < 0) speed += dec;
                else speed = 0;
            }
            this->move(sin(angle) * speed, -cos(angle) * speed);
            this->setRotation(angle * 180 / pi);

            if (!this->space && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
                this->manager->addEntity("bullet", new Bullet((this->score),
                                                              (this->getPosition().x +
                                                               (this->getGlobalBounds().width / 2) * sin(angle)),
                                                              (this->getPosition().y -
                                                               (this->getGlobalBounds().height / 2) * cos(angle)),
                                                              (-cos(angle) * 15),
                                                              (sin(angle) * 15), (angle * 180 / pi)));
            }
            this->space = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
            break;

        case 2:
            if (right)this->move(5, 0);
            if (left)this->move(-5, 0);
            if (!this->space && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
                this->manager->addEntity("bullet", new Bullet((this->score),
                                                              (this->getPosition().x),
                                                              (this->getPosition().y -
                                                               (this->getGlobalBounds().height / 2)),
                                                              (-10),
                                                              (0), 0));
            }
            this->space = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
            break;
        default:
            break;
    }
    Entity::updateEntity(window);

    switch (this->gamemode)
    {
        case 1:
            if (this->getPosition().y - this->getGlobalBounds().height / 2 < 0) {
                //this->setPosition(this->getPosition().x, 720 + this->getGlobalBounds().height);
                //this->speed = 0;
                this->move(-sin(angle) * speed, cos(angle) * speed);
            }

            if (this->getPosition().y + this->getGlobalBounds().height / 2 > window->getSize().y) {
                //this->setPosition(this->getPosition().x, 0);
                //this->speed = 0;
                this->move(-sin(angle) * speed, cos(angle) * speed);
            }
            if (this->getPosition().x - this->getGlobalBounds().width / 2 < 0) {
                //this->setPosition(1279 + this->getGlobalBounds().width, this->getPosition().y);
                //this->speed = 0;
                this->move(-sin(angle) * speed, cos(angle) * speed);
            }
            if (this->getPosition().x + this->getGlobalBounds().width / 2 > window->getSize().x) {
                //this->setPosition(0, this->getPosition().y);
                //this->speed = 0;
                this->move(-sin(angle) * speed, cos(angle) * speed);
            }
            break;
        case 2:
            if (this->getPosition().x + this->getGlobalBounds().width / 2 > window->getSize().x) this->move(-5, 0);
            if (this->getPosition().x - this->getGlobalBounds().width / 2 < 0) this->move(5, 0);
                break;
    }

}


//Her sjekker vi om vårt fly kræsjer med noen andre
void Player::collision(Entity *entity) {
    switch (entity->groupID()) {
        case 3: // Asteroid
            entity->destroyEntity();
            this->lives->decreaseLife();
            if (this->lives->getValue() <= 0) {
                this->destroyEntity();
            }
            break;
        case 4: // Enemy
            entity->destroyEntity();
            this->lives->decreaseLife();
            if (this->lives->getValue() <= 0) {
                this->destroyEntity();

            }
            break;
        case 6: //Boss bullet
            this->lives->decreaseLife();
            break;
    }
}