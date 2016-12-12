#include "../../Include/Entities/shieldEntity.h"


ShieldEntity::ShieldEntity(sf::RenderWindow* window, Player* player, SoundLoader* soundLoader)
        : player(player),
          soundLoader(soundLoader)
{
    this->load("shieldPowerUp.png");
    this->active = 1;
    this->groupId = 10;
    this->isShieldActive = false;

    this->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);
    this->scale(window->getSize().x / 1280.0f, window->getSize().y / 720.0f);
    this->setPosition(rand() % window->getSize().x, rand() % window->getSize().y);
}

void ShieldEntity::updateEntity(sf::RenderWindow *window){
    invincibleClock.pause();
    if (isShieldActive){
        this->load("Shield.png");
        this->setPosition(this->player->getPosition().x, this->player->getPosition().y);
        this->setOrigin(this->getGlobalBounds().width / 4, this->getGlobalBounds().height / 4);
        this->setScale(window->getSize().x / 640.0f, window->getSize().y / 360.0f);
        clock.restart();
        invincibleClock.start();
    }
    if(invincibleClock.getElapsedTime().asMicroseconds() > 5000000) { // 5 sekunder invincibility
        this->destroyEntity();
    }
    if(clock.getElapsedTime().asMicroseconds() > 4000000) //Sjekker om verdien til clock er mer enn 4 sekunder
    {
        this->destroyEntity();      //despawnes etter 4 sekunder
        clock.restart();            //restarter clock
    }
    Entity::updateEntity(window);
}

void ShieldEntity::collision(Entity* entity){
    switch(entity->groupID()){
        case 1: //Player
            //this->soundLoader->playEffect(Audio::?????);
            this->isShieldActive = true;
            break;
        case 3:
        case 4:
        case 6:
        case 9:
            if(this->isShieldActive){
                entity->destroyEntity();
            }
    }
}