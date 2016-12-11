#include "../../Include/Entities/shieldEntity.h"


ShieldEntity::ShieldEntity(sf::RenderWindow* window, Player* player, SoundLoader* soundLoader)
        : player(player),
          soundLoader(soundLoader)
{
    this->load("shieldPowerUp.png");
    this->active = 1;
    this->groupId = 10;
    this->isShieldActive = false;
    this->manager = new EntityManager();
    this->player = player;

    this->setOrigin(this->getGlobalBounds().height / 2, this->getGlobalBounds().width / 2);
    this->scale(window->getSize().x / 1280.0f, window->getSize().y / 720.0f);
    this->setPosition(rand() % window->getSize().x, rand() % window->getSize().y);
}

void ShieldEntity::updateEntity(sf::RenderWindow *window){

    if (isShieldActive){
        shieldPowerUp = new ShieldPowerUp(window, this->player);
        this->manager->addEntity("shieldPowerUp", shieldPowerUp);
        this->destroyEntity();
    }
    /*if(*this->isShieldActivePointer){
        this->manager->addEntity("shieldPowerUp", new ShieldPowerUp(window, this->player));
    }*/
    sf::Time elapsed1 = clock.getElapsedTime();
    if(elapsed1.asMicroseconds() > 4000000) //Sjekker om verdien til clock er mer enn 4 sekunder
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
    }
}