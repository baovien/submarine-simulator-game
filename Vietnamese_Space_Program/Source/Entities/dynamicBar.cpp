#include "../../Include/Entities/dynamicBar.h"

Bar::Bar(sf::RenderWindow *window) {
    this->load("overheat.png");
    this->setOrigin(this->getGlobalBounds().width/2, this->getGlobalBounds().height/2);
    this->setPosition(window->getSize().x/2, window->getSize().y - this->getGlobalBounds().height);
    this->setTextureRect(sf::IntRect(0,0,window->getSize().x * 12/1280,window->getSize().y * 20/720));
    this->setScale(window->getSize().x/640,window->getSize().y/360);
}
void Bar::updateEntity(sf::RenderWindow *window, float overHeatValue)
{
    this->overheatcheck = overHeatValue;
    if(overheatcheck > 10)overheatcheck=10;
    this->setTextureRect(sf::IntRect(0,0,(window->getSize().x*12/1280) * overheatcheck, window->getSize().y*20/720));
    Entity::updateEntity(window);
}
Bar::~Bar() {
    this->destroyEntity();
}