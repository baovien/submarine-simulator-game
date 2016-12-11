#include "../../Include/Entities/shieldPowerUp.h"


ShieldPowerUp::ShieldPowerUp(sf::RenderWindow* window, Player* player)
        : player(player)
{
    this->load("Shield.png");
    this->active = 1;
    this->groupId = 11;
    this->shieldLife = 3;
    this->setOrigin(this->getGlobalBounds().height/2, this->getGlobalBounds().height/2);
    this->setScale(window->getSize().x/1280.0f, window->getSize().y/740.0f);
}
void ShieldPowerUp::updateEntity(sf::RenderWindow *window){
    this->setPosition(this->player->getPosition().x, this->player->getPosition().y);
    Entity::updateEntity(window);
}
void ShieldPowerUp::collision(Entity* entity){
    switch(entity->groupID()){
        case 3:
        case 4:
        case 6:
        case 9:
            entity->destroyEntity();
            shieldLife--;
            break;
    }

}