#include "../../Include/Core/entity.h"
#include <iostream>
Entity::Entity()
{
    this->texture = new sf::Texture();
    this->active = 1;
    this->groupId = 0;
}
void Entity::load(std::string filename)
{
    this->texture->loadFromFile("Graphics/Sprites/" + filename);
    this->setTexture(*this->texture);
    this->texture->setSmooth(true);
}
void Entity::getDeltaTime(float deltatime){
    this->deltatime = deltatime;
}
void Entity::updateEntity(sf::RenderWindow *window)
{
    this->move(this->velocity.x * deltatime * window->getSize().x / 1280.f, this->velocity.y * deltatime * window->getSize().y / 720.f);
}
bool Entity::checkCollision(Entity* entity)
{
    return this->getGlobalBoundsAdjusted().intersects(entity->getGlobalBoundsAdjusted());
}
void Entity::collision(Entity* entity)
{
}
int Entity::activeEntity()
{
    return this->active;
}
int Entity::groupID()
{
    return this->groupId;
}
void Entity::destroyEntity()
{
    this->active = 0;
}
sf::FloatRect Entity::getGlobalBoundsAdjusted()
{
    sf::FloatRect collisionBounds = this->getGlobalBounds();
    collisionBounds.width *= 0.80f;
    collisionBounds.height *= 0.80f;
    collisionBounds.top *= 1.20f;
    collisionBounds.left *= 1.20f;
    return collisionBounds;
}

Entity::~Entity()
{
    delete this->texture;
}
