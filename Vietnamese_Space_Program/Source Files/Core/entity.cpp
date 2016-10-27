#include "../../Header Files/Core/entity.h"
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
    return this->getGlobalBounds().intersects(entity->getGlobalBounds());
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

Entity::~Entity()
{
    delete this->texture;
}
