#include "../../Include/Core/entity.h"
#include <iostream>

/**
 * Entity's constructor.
 * @return
 */
Entity::Entity()
{
    this->texture = new sf::Texture();
    this->active = 1;
    this->groupId = 0;
}

/**
 * loads a texture to the Entity, given the name of the file inside a path.
 * @param filename - Name of file to load inside the path.
 */
void Entity::load(std::string filename)
{
    this->texture->loadFromFile("Graphics/Sprites/" + filename);
    this->setTexture(*this->texture);
    this->texture->setSmooth(true);
}

/**
 * Getter for deltaTime, used to move objects relative to time.
 * @param deltatime
 */
void Entity::getDeltaTime(float deltatime){
    this->deltatime = deltatime;
}

/**
 * Moves the Entity relative to time, window size and it's velocity.
 * @param window
 */
void Entity::updateEntity(sf::RenderWindow *window)
{
    this->move(this->velocity.x * deltatime * window->getSize().x / 1280.f, this->velocity.y * deltatime * window->getSize().y / 720.f);
}

/**
 * checks the collision between the entity and a given entity.
 * @param entity - Given entity
 * @return - Whether they collide or not given by a bool.
 */
bool Entity::checkCollision(Entity* entity)
{
    return this->getGlobalBoundsAdjusted().intersects(entity->getGlobalBoundsAdjusted());
}

/**
 * Causes the collision results specified in the entities that inherit the Entity class.
 * @param entity - Entity it collided with.
 */
void Entity::collision(Entity* entity)
{
}

/**
 * Getter for if it's active.
 * @return - active
 */
int Entity::activeEntity()
{
    return this->active;
}

/**
 * Getter for the group ID of the Entity
 * @return - GroupID
 */
int Entity::groupID()
{
    return this->groupId;
}

/**
 * Sets active to 0, which will eventually in another function cause it to be deleted.
 */
void Entity::destroyEntity()
{
    this->active = 0;
}

/**
 * Adjusts the size of the collision rectangle, to make collision a bit smaller. An easy alternative to perfect collision.
 * @return - rectangle to use in the collison check.
 */
sf::FloatRect Entity::getGlobalBoundsAdjusted()
{
    sf::FloatRect collisionBounds = this->getGlobalBounds();
    collisionBounds.width *= 0.80f;
    collisionBounds.height *= 0.80f;
    collisionBounds.top *= 1.20f;
    collisionBounds.left *= 1.20f;
    return collisionBounds;
}

/**
 * Entity deconstructor
 */
Entity::~Entity()
{
    delete this->texture;
}
