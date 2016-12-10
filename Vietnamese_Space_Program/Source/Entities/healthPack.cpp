#include "../../Include/Entities/healthPack.h"

HealthPack::HealthPack(Lives* lives, SoundLoader* soundLoader, sf::RenderWindow* window)
        : soundLoader(soundLoader)
{
    this->load("wrench.png");
    this->active = 1;
    this->groupId = 7;
    this->lives = lives;
    this->setOrigin(this->getGlobalBounds().height/2, this->getGlobalBounds().height/2);
    this->setScale(window->getSize().x/1280, window->getSize().y/720);
    this->setPosition(rand() % 1280, rand() % 720);
}
void HealthPack::updateEntity(sf::RenderWindow *window)
{
    sf::Time elapsed1 = clock.getElapsedTime(); //Tar her her opp verdien som ligger i klokk
    if(elapsed1.asMicroseconds() > 4000000) //Sjekker om verdien til clock er mer enn 4 sekunder
    {
        this->destroyEntity();
        clock.restart(); //restarter clock(nullstiller)
    }
}
void HealthPack::collision(Entity* entity)
{
    switch(entity->groupID())
    {
        case 1:
            this->soundLoader->playEffect(Audio::REPAIR);
            this->destroyEntity();
            this->lives->increaseLife();
            break;
    }
}