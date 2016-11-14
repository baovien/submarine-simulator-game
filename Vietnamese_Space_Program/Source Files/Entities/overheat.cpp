
#include "../../Header Files/Entities/overheat.h"

Overheat::Overheat(sf::RenderWindow *window)
{
    this->load("overheat.png");
    this->setOrigin(this->getGlobalBounds().width/2, this->getGlobalBounds().height/2);
    this->setPosition((window->getSize().x/2), window->getSize().y - this->getGlobalBounds().height);
    this->setScale(2,2);
    this->setTextureRect(sf::IntRect(0, 0, 12, 20));

}
void Overheat::updateEntity(int overheat)
{
    this->setTextureRect(sf::IntRect(0, 0, 12*overheat, 20));
}