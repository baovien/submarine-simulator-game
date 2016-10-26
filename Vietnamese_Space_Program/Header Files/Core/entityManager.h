#include "entity.h"
#include <unordered_map>
#include <vector>

#ifndef VIETNAMESE_SPACE_PROGRAM_ENTITYMANAGER_H
#define VIETNAMESE_SPACE_PROGRAM_ENTITYMANAGER_H

class EntityManager
{
public:
    EntityManager();
    ~EntityManager();

    Entity* getEntity(std::string name);
    void addEntity(std::string name, Entity* entity);
    void updateEntity(sf::RenderWindow *window);
    void renderEntity(sf::RenderWindow *window);


protected:
    std::unordered_map<std::string, Entity*> entities;
};
#endif //VIETNAMESE_SPACE_PROGRAM_ENTITYMANAGER_H
