#include <iostream>
#include "../../Include/Entities/enemy2.h"

Enemy2Object::Enemy2Object(EntityManager* manager, int i, int j, sf::RenderWindow *window) {
    this->load("gold.png");
    this->active = 1;
    this->groupId = 4;
    this->health = 2;
    this->manager = manager;


    this->setOrigin(this->getGlobalBounds().height / 2, this->getGlobalBounds().height / 2);

    this->setPosition(window->getSize().x / 15 + i * this->getGlobalBounds().width,
                      window->getSize().y / 2 - this->getGlobalBounds().height * 5 +
                      j * this->getGlobalBounds().height);
    this->velocity.x = 5;
}



void Enemy2Object::updateEntity(sf::RenderWindow *window) {

    Entity::updateEntity(window);

    if (this->health < 2) {       //Destroy
        this->load("explosion.png");
        this->scale(1.5, 1.5);
        this->destroyEntity();
    }

    // Destroy enemy hvis den passerer player
    if (this->getPosition().y > window->getSize().y) {
        this->destroyEntity();
    }


     sf::Time elapsed1 = clock.getElapsedTime(); //Tar her her opp verdien som ligger i klokk

    if(elapsed1.asMicroseconds() > 2000000) {

        this->manager->addEntity("Bullet", new Bullet(this->getPosition().x, this->getPosition().y + this->getGlobalBounds().height, 5, 0, 0, window));
        clock.restart();
    }
}

void Enemy2Object::collision(Entity *entity) {

    switch (entity->groupID()) {
        case 2: // Bullets
            this->health--;
            break;

    }
}

