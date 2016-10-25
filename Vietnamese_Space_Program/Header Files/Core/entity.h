#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#ifndef VIETNAMESE_SPACE_PROGRAM_ENTITY_H
#define VIETNAMESE_SPACE_PROGRAM_ENTITY_H


class Entity : public sf::Sprite
{
public:
    float speed = 0, angle = 0;
    float maxSpeed = 8;
    float turnspeed = 0.2;
    float acc = 0.6, dec = 0.3;
    float x=1, y=1;

    Entity()
    {
        this->texture = new sf::Texture();
    }
    void load(std::string filename)
    {
        this->texture->loadFromFile("Graphics/Sprites/" + filename);
        this->setTexture(*this->texture);
    }
    virtual void update()
    {
        this->move(sin(angle) * speed, -cos(angle)*speed);
        this->setRotation(angle*180/3.141592);
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
