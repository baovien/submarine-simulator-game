#pragma once

#include <SFML/Graphics.hpp>
#include <cstdlib>

#ifndef VIETNAMESE_SPACE_PROGRAM_ENEMY_ENTITY_H
#define VIETNAMESE_SPACE_PROGRAM_ENEMY_ENTITY_H

class EnemyEntity : public sf::Sprite
{
public:
    sf::Vector2f velocity;

    EnemyEntity()
    {
        this->texture = new sf::Texture();
    }
    void load(std::string filename)
    {
        this->texture->loadFromFile("Graphics/Sprites/" + filename);
        this->setTexture(*this->texture);
    }
    virtual void updateEnemy()
    {
        this->move(this->velocity);


    }

    bool checkCollision(EnemyEntity* entity)
    {
        return this->getGlobalBounds().intersects(entity->getGlobalBounds());
    }
    ~EnemyEntity()
    {
        delete this->texture;
    }

protected:
private:
    sf::Texture* texture;

};

#endif //VIETNAMESE_SPACE_PROGRAM_ENEMY_ENTITY_H
