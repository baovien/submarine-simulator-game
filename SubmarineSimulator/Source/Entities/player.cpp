#include <iostream>
#include "../../Include/Entities/player.h"
/**
 * The player's constructor
 * @param keybindMap - A map with the current keybinds.
 * @param lives - The player's lives..
 * @param score - The player's score.
 * @param manager - The entitymanager.
 * @param x - Starting x position.
 * @param y - Starting y position.
 * @param window
 * @param gamemode - An integer keeping track of what game mode you are in.
 * @param fighter - An integer keeping track of what fighter you have selected.
 * @param audioLoader
 * @return
 */
Player::Player(std::map<const std::string, std::pair<std::string, int>>* keybindMap, Lives *lives, Score *score, EntityManager *manager, float x, float y, sf::RenderWindow *window, int gamemode, int fighter, AudioLoader *audioLoader)
        : keybindMap(*keybindMap),
          fighter(fighter),
          manager(manager),
          gamemode(gamemode),
          score(score),
          lives(lives),
          audioLoader(audioLoader) {
    this->active = 1;
    this->groupId = 1;
    switch (gamemode) {
        case 1:
            if (fighter == 0)this->load("ubat1.png");
            else this->load("fighter.png");

            this->setOrigin(this->getGlobalBounds().width / 2.f, this->getGlobalBounds().height / 2.f);
            this->space = false;
            this->setPosition(x, y);
            this->setScale(window->getSize().x / 1280.0f, window->getSize().y / 720.0f);
            this->bar = new Bar(window);
            this->manager->addEntity("bar", this->bar);
            this->overheatValue = 1.0f;
            break;
        case 2:
            if (fighter == 0)this->load("ubat1.png");
            else this->load("fighter.png");

            this->setOrigin(this->getGlobalBounds().width / 2.f, this->getGlobalBounds().height / 2.f);
            this->setScale(window->getSize().x / 2560.0f, window->getSize().y / 1440.0f);
            this->space = false;
            this->setPosition(x - this->getGlobalBounds().width, y - this->getGlobalBounds().height / 1.5f);
            break;
        default:
            break;
    }
}


/**
 * Updates player's position
 * @param window
 */
void Player::updateEntity(sf::RenderWindow *window) {
    Entity::updateEntity(window);
    up = 0, down = 0, left = 0, right = 0;
    if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key) keybindMap.find("left")->second.second))left = 1;
    if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key) keybindMap.find("right")->second.second))right = 1;
    if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key) keybindMap.find("up")->second.second))up = 1;
    if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key) keybindMap.find("down")->second.second))down = 1;

    //Spritebytte for skadet player.
    if (this->lives->getValue() <= 0) {
        this->load("explosion.png");
    }


    switch (this->gamemode) {
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /////////////////                                         GAME MODE 1 UPDATE                                  /////////////////
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case 1:
            ///////////////////////////////////////////////////////////////////////////////////////////////
            this->setRotation(angle * 180 / pi);                                                       ////
            if (right) angle += turnspeed * (*machine.deltaTimePointer);                               ////
            if (left) angle -= turnspeed * (*machine.deltaTimePointer);                                ////
            if (up && speed < maxSpeed) {                                                              ////
                if (speed < 0) speed += dec;                                                           ////
                else speed += acc;                                                                     ////
            }                                                                                          ////
            if (down && speed > -maxSpeed) {                                                           ////
                if (speed > 0) {                                                                       ////
                    speed -= dec;                                                                      ////
                } else {                                                                               ////
                    speed -= acc;                                                                      ////
                }                                                                                      ////
            }                                                                                          ////
            if (!up && !down) {                                                                        ////
                if (speed - dec > 0) speed -= dec;                                                     ////
                else if (speed + dec < 0) speed += dec;                                                ////
                else speed = 0;                                                                        ////
            }                                                                                          ////
            this->velocity.x = sin(angle) * speed;                                                     ////
            this->velocity.y = -cos(angle) * speed;                                                    ////
            ///////////////////////////////////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////////
            ////        Flipper player om han krysser y-aksen               ////
            ////////////////////////////////////////////////////////////////////
            if (this->getRotation() < 360 && this->getRotation() > 180) {
                float turn = window->getSize().x / 2560.0f;
                turn *= -1;
                this->setScale(turn, this->getScale().y);
            } else {
                this->setScale(window->getSize().x / 2560.0f, window->getSize().y / 1440.0f);
            }

            /////////////////////////////////////////////////////////////////////
            ////        Skyte bullet om ikke overheata                       ////
            /////////////////////////////////////////////////////////////////////
            if (!this->space &&
                sf::Keyboard::isKeyPressed((sf::Keyboard::Key) keybindMap.find("shoot")->second.second)) {
                if (this->overheatValue < 10) {
                    this->overheatValue += 1;
                    if(machine.selectedObjectsPointer->selectedFighter == 0){
                        this->audioLoader->playEffect(Audio::Effect::PLAYER_SHOOT1);
                    }else{
                        this->audioLoader->playEffect(Audio::Effect::PLAYER_SHOOT2);
                    }
                    this->manager->addEntity("bullet", new Bullet((this->score),
                                                                  (this->getPosition().x + (this->getGlobalBounds().width / 2) * sin(angle)),
                                                                  (this->getPosition().y - (this->getGlobalBounds().height / 2) * cos(angle)),
                                                                  (-cos(angle)),
                                                                  (sin(angle)),
                                                                  (angle * 180 / pi),
                                                                  this->audioLoader,
                                                                  window, machine.selectedObjectsPointer->selectedFighter));
                } else if (this->overheatValue > 10) {
                    this->overheatValue = 15;
                    audioLoader->playEffect(Audio::OVERHEAT);
                }
            }
            this->bar->updateEntity(window, this->overheatValue);
            this->overheatValue = this->overheatValue - (1.25f * *manager->deltaTime);
            if (this->overheatValue < 1)this->overheatValue = 1;
            this->space = sf::Keyboard::isKeyPressed((sf::Keyboard::Key) keybindMap.find("shoot")->second.second);



            ////////////////////////////////////////////////////////////////////
            ////        Setter texture avhengig av om shield er active      ////
            ////////////////////////////////////////////////////////////////////
            if (*this->isShieldActivePointer) {                             ////
                clock.start();                                              ////
                if (clock.getElapsedTime().asSeconds() > 5) {               ////
                    *this->isShieldActivePointer = false;                   ////
                }                                                           ////
                if (firstTimeLoading) {                                     ////
                    if (fighter == 0)this->load("ubatShield.png");          ////
                    else this->load("fighterShield.png");                   ////
                    firstTimeLoading = false;                               ////
                }                                                           ////
            }                                                               ////
            if (!*this->isShieldActivePointer) {                            ////
                if (!firstTimeLoading) {                                    ////
                    if (fighter == 0)this->load("ubat1.png");               ////
                    else this->load("fighter.png");                         ////
                    firstTimeLoading = true;                                ////
                }                                                           ////
                clock.restart();                                            ////
            }                                                               ////
            ////////////////////////////////////////////////////////////////////
            break;

            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            /////////////////                                         GAME MODE 2 UPDATE                                  /////////////////
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case 2:
            ////////////////////////////////////////////////////////////////////
            ////                  Players bevegelse                         ////
            ////////////////////////////////////////////////////////////////////
            if (left) this->velocity.x = -400;
            else if (right) this->velocity.x = 400;
            else this->velocity.x = 0;

            ////////////////////////////////////////////////////////////////////
            ////        Skyte bullet om ingen andre eksisterer              ////
            ////////////////////////////////////////////////////////////////////
            if (manager->getEntity("bullet") == NULL) {
                if (!this->space &&
                    sf::Keyboard::isKeyPressed((sf::Keyboard::Key) keybindMap.find("shoot")->second.second)) {
                    if(machine.selectedObjectsPointer->selectedFighter == 0){
                        this->audioLoader->playEffect(Audio::Effect::PLAYER_SHOOT1);
                    }else{
                        this->audioLoader->playEffect(Audio::Effect::PLAYER_SHOOT2);
                    }
                    this->manager->addEntity("bullet", new Bullet((this->score),
                                                                  (this->getPosition().x),
                                                                  (this->getPosition().y - this->getGlobalBounds().height / 2.f),
                                                                  (-1),
                                                                  (0),
                                                                   0,
                                                                  this->audioLoader,
                                                                  window,
                                                                  machine.selectedObjectsPointer->selectedFighter));
                }
                this->space = sf::Keyboard::isKeyPressed((sf::Keyboard::Key) keybindMap.find("shoot")->second.second);
            }
            break;
        default:
            break;
    }
    switch (this->gamemode) {
        ////////////////////////////////////////////////////////////////////
        ////        Vindukantkollisjon i gamemode 1                     ////
        ////////////////////////////////////////////////////////////////////
        case 1:
            //Sjekker for kollisjon med vindukantene.
            if (this->getPosition().y + this->getGlobalBounds().height / 2.f < 0) {
                this->setPosition(this->getPosition().x, window->getSize().y + this->getGlobalBounds().height / 2.1f);
                //this->speed = 0;
                //this->move(-sin(angle) * speed, cos(angle) * speed);
            }
            if (this->getPosition().y - this->getGlobalBounds().height / 2.f > window->getSize().y) {
                this->setPosition(this->getPosition().x, 0 - this->getGlobalBounds().height / 2.1f);
                //this->speed = 0;
                //this->move(-sin(angle) * speed, cos(angle) * speed);
            }
            if (this->getPosition().x + this->getGlobalBounds().width / 2.f < 0) {
                this->setPosition(window->getSize().x + this->getGlobalBounds().width / 2.1f, this->getPosition().y);
                //this->speed = 0;
                //this->move(-sin(angle) * speed, cos(angle) * speed);
            }
            if (this->getPosition().x - this->getGlobalBounds().width / 2.f > window->getSize().x) {
                this->setPosition(0 - this->getGlobalBounds().width / 2.1f, this->getPosition().y);
                //this->speed = 0;
                //this->move(-sin(angle) * speed, cos(angle) * speed);
            }
            break;
        case 2:
            ////////////////////////////////////////////////////////////////////
            ////        Vindukantkollisjon i gamemode 2                     ////
            ////////////////////////////////////////////////////////////////////
            if (this->getPosition().x + this->getGlobalBounds().width / 2.f > window->getSize().x) this->move(-5, 0);
            if (this->getPosition().x - this->getGlobalBounds().width / 2.f < 0) this->move(5, 0);
            break;
        default:
            break;
    }
    ////////////////////////////////////////////////////////////////////
    ////        Slett player om lives er 0                          ////
    ////////////////////////////////////////////////////////////////////
    if (this->lives->getValue() <= 0) {
        this->destroyEntity();
    }
}

/**
 * Decides the outcome of a collision between the player and the given entity.
 * @param entity - entity being checked for collision.
 */
void Player::collision(Entity *entity) {
    switch (entity->groupID()) {
        case 3: // Indestructable Object nr 1
            entity->destroyEntity();
            if (!*this->isShieldActivePointer) {
                this->lives->decreaseLife();
            }
            break;
        case 4: // Enemy
            entity->destroyEntity();
            if (!*this->isShieldActivePointer) {
                this->lives->decreaseLife();
            }
            break;
        case 5: // Boss
            if (!*this->isShieldActivePointer) {
                //Skal vi lage en delay her?
                this->lives->instaKill();
            }
            break;
        case 6: //Boss bullet
            entity->destroyEntity();
            if (!*this->isShieldActivePointer) {
                this->lives->decreaseLife();
            }
            break;
        case 9: // Indestructable Object nr 2
            entity->destroyEntity();
            if (!*this->isShieldActivePointer) {
                this->lives->decreaseLife();
            }
        default:
            break;
    }
}
/**
 * A function for pausing and restarting the clock in player. Used to keep track of the shield duration.
 * @param pause A bool deciding wether to pause or restart the clock.
 */
void Player::pauseClock(bool pause) {
    if (pause) {
        clock.pause();
    } else clock.start();
}
