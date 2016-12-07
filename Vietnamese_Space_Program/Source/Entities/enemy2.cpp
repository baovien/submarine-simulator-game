#include <iostream>
#include "../../Include/Entities/enemy2.h"

Enemy2Object::Enemy2Object(int i, int j, sf::RenderWindow *window) {
    this->load("gold.png");
    this->active = 1;
    this->groupId = 4;
    this->health = 2;


    this->setOrigin(this->getGlobalBounds().height / 2, this->getGlobalBounds().height / 2);

    this->setPosition(window->getSize().x / 10 + i * this->getGlobalBounds().width,
                      window->getSize().y / 2 - this->getGlobalBounds().height * 5 +
                      j * this->getGlobalBounds().height);

    this->velocity.x = 2;

}

void Enemy2Object::updateEntity(sf::RenderWindow *window) {

    if (this->health < 2) {       //Destroy
        this->load("explosion.png");
        this->scale(1.5, 1.5);
        this->destroyEntity();
    }

    // Destroy enemy hvis den passerer player
    if (this->getPosition().y > window->getSize().y) {
        this->destroyEntity();
    }

    Entity::updateEntity(window);
}

void Enemy2Object::collision(Entity *entity) {

    switch (entity->groupID()) {
        case 2: // Bullets
            this->health--;
            break;
    }
}

