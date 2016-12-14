#include "../../Include/Entities/shieldEntity.h"

/**
 * Constructor for the spawning power-up
 * @param window
 * @param player
 * @param soundLoader
 * @return
 */
ShieldEntity::ShieldEntity(sf::RenderWindow* window, Player* player, SoundLoader* soundLoader)
        : player(player),
          soundLoader(soundLoader)
{
    this->isShieldActivePointer = player->isShieldActivePointer;
    this->load("shieldPowerUp.png");
    this->active = 1;
    this->groupId = 10;
    this->setOrigin(this->getGlobalBounds().width / 2.f, this->getGlobalBounds().height / 2.f);
    this->scale(window->getSize().x / 1280.0f, window->getSize().y / 720.0f);
    this->setPosition(rand() % window->getSize().x, rand() % window->getSize().y);
}

/**
 * Deletes the shield power-up after 5 seconds.
 * @param window
 */
void ShieldEntity::updateEntity(sf::RenderWindow *window){
    if(clock.getElapsedTime().asSeconds() > 5)
    {
        this->destroyEntity();
    }
    Entity::updateEntity(window);
}

/**
 * Decides the outcome of a collision between the player and the given entity.
 * @param entity - entity being checked for collision.
 */
void ShieldEntity::collision(Entity* entity){
    switch(entity->groupID()){
        case 1: //Player
            //this->soundLoader->playEffect(Audio::?????);
            *this->isShieldActivePointer = true;
            this->destroyEntity();
            break;

        default:break;
    }
}