#include "../../Include/Entities/healthPack.h"

/**
 * Healthpack's constructor
 * @param lives - The player's lives.
 * @param soundLoader
 * @param window
 * @return
 */
HealthPack::HealthPack(Lives* lives, SoundLoader* soundLoader, sf::RenderWindow* window)
        : soundLoader(soundLoader)
{
    this->load("wrench.png");
    this->active = 1;
    this->groupId = 7;
    this->lives = lives;

    this->setOrigin(this->getGlobalBounds().height/2.f, this->getGlobalBounds().height/2.f);
    this->setScale(window->getSize().x/1280.f, window->getSize().y/720.f);
    this->setPosition(rand() % 1280, rand() % 720);
}

/**
 * Deletes the entity after 4 seconds.
 * @param window
 */
void HealthPack::updateEntity(sf::RenderWindow *window)
{
    //Tar her her opp verdien som ligger i klokk
    if(clock.getElapsedTime().asMicroseconds() > 4000000) //Sjekker om verdien til clock er mer enn 4 sekunder
    {
        this->destroyEntity();
        clock.restart(); //restarter clock(nullstiller)
    }
}

/**
 * Decides the outcome of a collision between the player and the given entity.
 * @param entity - entity being checked for collision.
 */
void HealthPack::collision(Entity* entity)
{
    switch(entity->groupID())
    {
        case 1:
            this->soundLoader->playEffect(Audio::REPAIR);
            this->destroyEntity();
            this->lives->increaseLife();
            break;
        default:break;
    }
}