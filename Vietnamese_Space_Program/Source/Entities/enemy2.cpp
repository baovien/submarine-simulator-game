#include <iostream>
#include "../../Include/Entities/enemy2.h"

/**
 *
 * @param manager
 * @param i - iterator from the for loop creating rows and columns. Used to decide starting position.
 * @param j - iterator from the for loop creating rows and columns. Used to decide starting position.
 * @param s - string of the file path of the texture we want to load.
 * @param window
 * @param theme - Current selected theme, deciding what texture to load.
 * @return
 */
    Enemy2Object::Enemy2Object(EntityManager *manager, int i, int j, std::string s, sf::RenderWindow *window, int theme)
{
    this->theme = theme;
    if(theme == 0)this->load(s);
    else this->load(s);
    this->active = 1;
    this->groupId = 4;
    this->health = 2;
    this->manager = manager;

    this->scale(-(window->getSize().x / 3200.f), window->getSize().y / 1800.f);
    this->setOrigin(this->getGlobalBounds().height / 2, this->getGlobalBounds().height / 2.f);

    this->setPosition(window->getSize().x / 15.f + i * this->getGlobalBounds().width,
                      window->getSize().y / 2.8f - this->getGlobalBounds().height * 5 +
                      j * this->getGlobalBounds().height);
    //this->velocity.x = window->getSize().x/20 * *manager->deltaTime;

    this->velocity.x = 100.f;

}

/**
 * sets the texture of the enemy given by it's health
 * @param window
 */
void Enemy2Object::updateEntity(sf::RenderWindow *window) {

    Entity::updateEntity(window);

    if (this->health < 2) {       //Destroy
        this->load("explosion.png");
        this->scale(window->getSize().x / 256.f, window->getSize().y / 144.f);
        this->destroyEntity();
    }

    // Destroy enemy hvis den passerer player
    if (this->getPosition().y > window->getSize().y)
    {
        this->destroyEntity();
    }


}

/**
 * Decides the outcome of a collision between the player and the given entity.
 * @param entity - entity being checked for collision.
 */
void Enemy2Object::collision(Entity *entity)
{

    switch (entity->groupID())
    {
        case 2: // Bullets
            this->health--;
            break;

        default:break;
    }
}

