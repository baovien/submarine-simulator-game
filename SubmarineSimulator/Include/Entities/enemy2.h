#include "../Core/entityManager.h"
#include "../Core/score.h"
#include "bullet.h"


#ifndef SUBMARINESIMULATORENEMY2_H
#define SUBMARINESIMULATORENEMY2_H


class Enemy2Object : public Entity
{
public:
    Enemy2Object(EntityManager* manager, int i, int j, std::string k, sf::RenderWindow* window, int theme);
    void updateEntity(sf::RenderWindow *window);
    virtual void collision(Entity* entity);
private:
    int theme;
    int health;
    EntityManager* manager = nullptr;

};


#endif //SUBMARINESIMULATORENEMY2_H
