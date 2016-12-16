#ifndef SUBMARINESIMULATORENTITY_H
#define SUBMARINESIMULATORENTITY_H
#include <SFML/Graphics.hpp>
#include <cmath>
class Entity : public sf::Sprite
{
public:
    Entity();
    void load(std::string filename);
    virtual void getDeltaTime(float deltatime);
    virtual void updateEntity(sf::RenderWindow *window);
    bool checkCollision(Entity* entity);
    virtual void collision(Entity* entity);
    int activeEntity();
    int groupID();
    void destroyEntity();
    virtual ~Entity();

    sf::Vector2f velocity;
protected:
    virtual sf::FloatRect getGlobalBoundsAdjusted();
    int active;
    int groupId;
    float deltatime;
private:
    sf::Texture* texture = nullptr;
};

#endif //SUBMARINESIMULATORENTITY_H
