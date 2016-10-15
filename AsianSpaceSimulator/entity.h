#pragma once
#include <SFML/Graphics.hpp>
#ifndef VIETNAMESE_SPACE_PROGRAM_ENTITY_H
#define VIETNAMESE_SPACE_PROGRAM_ENTITY_H

class Entity : public sf::Sprite
{
public:
    sf::Vector2f velocity;
    Entity()
    {
        this->texture = new sf::Texture();
    }
    void Load(std::string filename)
    {
        this->texture->loadFromFile("Graphics/Sprites/" + filename);
        this->setTexture(*this->texture);
    }
    virtual void Update()
    {
        this->move(this->velocity);
    }
    bool checkCollision(Entity* entity)
    {
        return this->getGlobalBounds().intersects(entity->getGlobalBounds());
    }
    ~Entity()
    {
        delete this->texture;
    }

protected:

private:
    sf::Texture* texture;
};

#endif //VIETNAMESE_SPACE_PROGRAM_ENTITY_H
