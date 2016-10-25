#include <SFML/Graphics.hpp>
#ifndef VIETNAMESE_SPACE_PROGRAM_BULLET_ENTITY_H
#define VIETNAMESE_SPACE_PROGRAM_BULLET_ENTITY_H

class BulletEntity : public sf::Sprite
{
public:
    sf::Vector2f movement;
    BulletEntity()
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
        this->move(this->movement);
    }

    bool checkCollision(BulletEntity* entity)
    {
        return this->getGlobalBounds().intersects(entity->getGlobalBounds());
    }
    ~BulletEntity()
    {
        delete this->texture;
    }

protected:

private:
    sf::Texture* texture;
};
#endif //VIETNAMESE_SPACE_PROGRAM_BULLET_ENTITY_H
