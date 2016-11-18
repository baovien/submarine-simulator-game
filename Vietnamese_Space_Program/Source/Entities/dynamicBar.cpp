#include "../../Include/Entities/dynamicBar.h"

Bar::Bar(sf::RenderWindow *window) {
    this->load("overheat.png");
    this->setOrigin(this->getGlobalBounds().width/2, this->getGlobalBounds().height/2);
    this->setPosition(window->getSize().x/2, window->getSize().y - this->getGlobalBounds().height);
    this->setTextureRect(sf::IntRect(0,0,12,20));
    this->setScale(2,2);

    /*this->font = new sf::Font();
    this->font->loadFromFile("Graphics/font.ttf");
    this->overheatWarning = new sf::Text("OVERHEATED!", *font, 8U);
    this->overheatWarning->setOrigin(this->overheatWarning->getGlobalBounds().width/2, this->overheatWarning->getGlobalBounds().height/2);
    this->overheatWarning->setPosition(window->getSize().x/2 + this->getGlobalBounds().width/2 , window->getSize().y - 100); */

}
void Bar::updateEntity(sf::RenderWindow *window, float overHeatValue)
{
    this->setTextureRect(sf::IntRect(0,0,12*overHeatValue, 20));
    Entity::updateEntity(window);
}
Bar::~Bar() {
    this->destroyEntity();
}