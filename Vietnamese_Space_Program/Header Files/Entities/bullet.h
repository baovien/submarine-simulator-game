#pragma once

#include <SFML/Graphics.hpp>

#ifndef VIETNAMESE_SPACE_PROGRAM_BULLET_H
#define VIETNAMESE_SPACE_PROGRAM_BULLET_H

class Bullet : public sf::Sprite {
public:
    float x, y;
    sf::Vector2f speed;

    Bullet()
    {
        this->texture = new sf::Texture();
    }

    void Load(std::string filename)
    {
        this->texture->loadFromFile("Graphics/Sprites/" + filename);
        this->setTexture(*this->texture);
    }

    virtual void Updatebullet()
    {
        this->move(this->speed);
    }

    bool checkCollision(Bullet *entity)
    {
        return this->getGlobalBounds().intersects(entity->getGlobalBounds());
    }

    ~Bullet()
    {
        delete this->texture;
    }

protected:
    sf::Texture *texture;

};

#endif //VIETNAMESE_SPACE_PROGRAM_BULLET_H
