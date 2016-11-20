#ifndef VIETNAMESE_SPACE_PROGRAM_ENTITY_H
#define VIETNAMESE_SPACE_PROGRAM_ENTITY_H
#include <SFML/Graphics.hpp>
#include <cmath>

class Entity : public sf::Sprite
{
public:
    Entity();
    void load(std::string filename);
    virtual void updateEntity(sf::RenderWindow *window);
    bool checkCollision(Entity* entity);
    virtual void collision(Entity* entity);
    int activeEntity();
    int groupID();
    void destroyEntity();

    ~Entity();

    sf::Vector2f velocity;
protected:
    virtual sf::FloatRect getGlobalBoundsAdjusted();
    int active;
    int groupId;

private:
    sf::Texture* texture;
};

#endif //VIETNAMESE_SPACE_PROGRAM_ENTITY_H
