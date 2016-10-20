#pragma once

#include <SFML/Graphics.hpp>
#include <cstdlib>

#ifndef VIETNAMESE_SPACE_PROGRAM_ENEMY_ENTITY_H
#define VIETNAMESE_SPACE_PROGRAM_ENEMY_ENTITY_H

class Enemy_Entity : public sf::Sprite
{
public:
    sf::Vector2f velocity;

    Enemy_Entity()
    {
        this->texture = new sf::Texture();
    }
    void Load(std::string filename)
    {
        this->texture->loadFromFile("Graphics/Sprites/" + filename);
        this->setTexture(*this->texture);
    }
    virtual void UpdateEnemy()
    {
        this->move(this->velocity);
    }

    bool checkCollision(Enemy_Entity* entity)
    {
        return this->getGlobalBounds().intersects(entity->getGlobalBounds());
    }
    ~Enemy_Entity()
    {
        delete this->texture;
    }

protected:
private:
    sf::Texture* texture;

};

#endif //VIETNAMESE_SPACE_PROGRAM_ENEMY_ENTITY_H
