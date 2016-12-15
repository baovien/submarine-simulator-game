#ifndef VIETNAMESE_SPACE_PROGRAM_ENTITYMANAGER_H
#define VIETNAMESE_SPACE_PROGRAM_ENTITYMANAGER_H

#include "entity.h"
#include <unordered_map>
#include <vector>

class EntityManager
{
public:
    EntityManager();
    ~EntityManager();

    Entity* getEntity(std::string name);
    void addEntity(std::string name, Entity* entity);
    void updateEntity(sf::RenderWindow *window, float* deltaTime);
    void renderEntity(sf::RenderWindow *window);
    float* deltaTime = nullptr;
protected:
    std::unordered_map<std::string, Entity*> entities;
public:
    std::unordered_map<std::string, Entity*>* entitiesPointer = &entities;
};
#endif //VIETNAMESE_SPACE_PROGRAM_ENTITYMANAGER_H
