#include "../../Include/Entities/dynamicBar.h"

Bar::Bar(sf::RenderWindow *window) {
    this->load("overheat.png");
    this->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);
    this->setPosition(window->getSize().x/2, window->getSize().y - this->getGlobalBounds().height);
    this->setTextureRect(sf::IntRect(0, 0, 12, 20));
    this->setScale(window->getSize().x/640, window->getSize().y/360);
}
Bar::Bar(sf::RenderWindow *window, float x, float y) {
    this->load("overheat.png");
    this->setPosition(x, y);
    this->setScale(window->getSize().x / 1280, window->getSize().y / 720);
    this->setTextureRect(sf::IntRect(0, 0, window->getSize().x * 120 / 1280, window->getSize().y * 20 / 720));
    this->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);
}
void Bar::updateEntity(sf::RenderWindow *window, float overHeatValue)
{
    this->overheatcheck = overHeatValue;
    if(overheatcheck >= 10)overheatcheck=10.3;
    this->setTextureRect(sf::IntRect(0,0,12 * overheatcheck, 20));
    Entity::updateEntity(window);
}
void Bar::updateEntity2(sf::RenderWindow *window, float overHeatValue, float x, float y) {
    this->overheatcheck = overHeatValue;
    this->setPosition(x, y);
    this->setTextureRect(sf::IntRect(0,0,overheatcheck, 20));
    Entity::updateEntity(window);
}