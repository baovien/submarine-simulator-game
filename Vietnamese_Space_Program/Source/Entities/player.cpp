#include <iostream>
#include "../../Include/Entities/player.h"

Player::Player(std::map<const std::string, std::pair<std::string, int>> keybindMap, Lives *lives, Score *score, EntityManager *manager, float x, float y, sf::RenderWindow *window, int gamemode, int mode, SoundLoader* soundLoader)
        : keybindMap(keybindMap),
          mode(mode),
          manager(manager),
          gamemode(gamemode),
          score(score),
          lives(lives),
          soundLoader(soundLoader)
{
    this->active = 1;
    this->groupId = 1;

    switch (gamemode) {
        case 1:
            this->load("ubat1.png");
            this->setOrigin(this->getGlobalBounds().width/2, this->getGlobalBounds().height/2);
            this->space = false;
            this->setPosition(x, y);
            this->setScale(window->getSize().x/1280.0f, window->getSize().y/720.0f);
            this->bar = new Bar(window);
            this->manager->addEntity("bar", this->bar);
            this->overheatValue = 1.0f;
            break;
        case 2:
            this->load("ubat1.png");
            this->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);
            this->setScale(window->getSize().x/2560.0f, window->getSize().y/1440.0f);
            this->space = false;
            this->setPosition(x - this->getGlobalBounds().width, y - this->getGlobalBounds().height / 1.5);
            break;
        default:
            break;
    }
}

//update funksjonen har kontroll på bevegelsen til player.
void Player::updateEntity(sf::RenderWindow *window){
    Entity::updateEntity(window);
    up = 0, down = 0, left = 0, right = 0;
    if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key) keybindMap.find("left")->second.second))left = 1;
    if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key) keybindMap.find("right")->second.second))right = 1;
    if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key) keybindMap.find("up")->second.second))up = 1;
    if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key) keybindMap.find("down")->second.second))down = 1;

    //Spritebytte for skadet player.
    if(this->lives->getValue() <= 0 ){
        this->load("explosion.png");
    }
    switch (this->gamemode) {
        case 1:
            this->setRotation(angle * 180 / pi);
            switch (this->mode) {
                case 1:
                    //Bevegelse
                    if (right && speed != 0) angle += turnspeed * speed / maxSpeed;
                    if (left && speed != 0) angle -= turnspeed * speed / maxSpeed;

                    if (up && speed < maxSpeed) {
                        if (speed < 0) speed += dec;
                        else speed += acc;
                    }
                    if (down) {
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
                    this->move((sin(angle) * speed) * *machine.deltaTimePointer, (-cos(angle) * speed)* *machine.deltaTimePointer);
                    break;

                case 2:
                    if (right) angle += turnspeed * (*machine.deltaTimePointer);
                    if (left) angle -= turnspeed * (*machine.deltaTimePointer);

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
                    this->move((sin(angle) * speed) * (*machine.deltaTimePointer) * window->getSize().x / 1280, (-cos(angle) * speed) * (*machine.deltaTimePointer) * window->getSize().y / 720);
                    break;
                default:
                    break;
            }
            if(this->getRotation() < 360 && this->getRotation() > 180) {
                float turn = window->getSize().x/2560.0f;
                turn *= -1;
                this->setScale(turn, this->getScale().y);
            }
            else{
                this->setScale(window->getSize().x/2560.0f, window->getSize().y/1440.0f);
            }

            //skyte bullet
            if (!this->space && sf::Keyboard::isKeyPressed((sf::Keyboard::Key) keybindMap.find("shoot")->second.second))
            {
                if(this->overheatValue < 10) {
                    this->overheatValue += 1;
                    this->soundLoader->playEffect(Audio::Effect::PLAYER_SHOOT);
                    this->manager->addEntity("bullet", new Bullet((this->score),
                                                                  (this->getPosition().x + (this->getGlobalBounds().width / 2) * sin(angle)),
                                                                  (this->getPosition().y - (this->getGlobalBounds().height / 2) * cos(angle)),
                                                                  (-cos(angle)),
                                                                  (sin(angle)),
                                                                  (angle * 180 / pi),
                                                                  this->soundLoader,
                                                                  window));
                }
                else if(this->overheatValue > 10) {
                    this->overheatValue = 15;
                    soundLoader->playEffect(Audio::OVERHEAT);
                }
            }
            this->bar->updateEntity(window, this->overheatValue);
            this->overheatValue = this->overheatValue - 0.05f;
            if(this->overheatValue < 1)this->overheatValue = 1;
            this->space = sf::Keyboard::isKeyPressed((sf::Keyboard::Key) keybindMap.find("shoot")->second.second);
            break;


        case 2:
            if (right)this->move(10, 0);
            if (left)this->move(-10, 0);
            if (!this->space && sf::Keyboard::isKeyPressed((sf::Keyboard::Key) keybindMap.find("shoot")->second.second)) {
                this->manager->addEntity("bullet", new Bullet((this->score),
                                                              (this->getPosition().x),
                                                              (this->getPosition().y - this->getGlobalBounds().height/2),
                                                              (-1),
                                                              (0),
                                                              0,
                                                              this->soundLoader,
                                                              window));
            }
            this->space = sf::Keyboard::isKeyPressed((sf::Keyboard::Key) keybindMap.find("shoot")->second.second);
            break;
        default:
            break;
    }
    switch (this->gamemode) {
        case 1:
            //Sjekker for kollisjon med vindukantene.
            if (this->getPosition().y + this->getGlobalBounds().height/2 < 0) {
                this->setPosition(this->getPosition().x, window->getSize().y + this->getGlobalBounds().height/2.1);
                //this->speed = 0;
                //this->move(-sin(angle) * speed, cos(angle) * speed);
            }
            if (this->getPosition().y - this->getGlobalBounds().height/2 > window->getSize().y) {
                this->setPosition(this->getPosition().x, 0 - this->getGlobalBounds().height/2.1);
                //this->speed = 0;
                //this->move(-sin(angle) * speed, cos(angle) * speed);
            }
            if (this->getPosition().x + this->getGlobalBounds().width/2 < 0) {
                this->setPosition(window->getSize().x + this->getGlobalBounds().width/2.1, this->getPosition().y);
                //this->speed = 0;
                //this->move(-sin(angle) * speed, cos(angle) * speed);
            }
            if (this->getPosition().x - this->getGlobalBounds().width/2 > window->getSize().x) {
                this->setPosition(0 - this->getGlobalBounds().width/2.1, this->getPosition().y);
                //this->speed = 0;
                //this->move(-sin(angle) * speed, cos(angle) * speed);
            }
            break;
        case 2:
            if (this->getPosition().x + this->getGlobalBounds().width / 2 > window->getSize().x) this->move(-5, 0);
            if (this->getPosition().x - this->getGlobalBounds().width / 2 < 0) this->move(5, 0);
            break;
    }
    if (this->lives->getValue() <= 0) {
        this->destroyEntity();
    }
}
//Her sjekker vi om vårt fly kræsjer med noe annet
void Player::collision(Entity *entity) {
    switch (entity->groupID()) {
        case 3: // Indestructable Object nr 1
            entity->destroyEntity();
            this->lives->decreaseLife();
            break;
        case 4: // Enemy
            entity->destroyEntity();
            this->lives->decreaseLife();
            break;
        case 5: // Boss
            break;
        case 6: //Boss bullet
            entity->destroyEntity();
            this->lives->decreaseLife();
            break;
        case 9: // Indestructable Object nr 2
            entity->destroyEntity();
            this->lives->decreaseLife();
    }
}
