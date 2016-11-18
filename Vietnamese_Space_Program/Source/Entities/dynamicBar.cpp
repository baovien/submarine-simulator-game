#include "../../Include/Entities/dynamicBar.h"

Bar::Bar(sf::RenderWindow *window, int overHeatValue) {
    this->load("overheat.png");
    this->setOrigin(this->getGlobalBounds().width/2, this->getGlobalBounds().height/2);
    this->setPosition(window->getSize().x/2, window->getSize().y - this->getGlobalBounds().height);
    this->setTextureRect(sf::IntRect(0,0,12,20));

}
void Bar::updateEntity(sf::RenderWindow *window) {
    this->move(0,-1);
    Entity::updateEntity(window);
}
Bar::~Bar() {
    this->destroyEntity();
}