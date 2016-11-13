#include "../../Include/Core/entity.h"
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
}
void Entity::updateEntity(sf::RenderWindow *window)
{
    this->move(this->velocity);
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
    collisionBounds.width *= 0.8;
    collisionBounds.height *= 0.8;
    collisionBounds.top *= 1.2;
    collisionBounds.left *= 1.2;
    return collisionBounds;
}

Entity::~Entity()
{
    delete this->texture;
}
