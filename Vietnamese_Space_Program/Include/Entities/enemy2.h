#include "../Core/entityManager.h"
#include "../Core/score.h"
#include "bullet.h"


#ifndef VIETNAMESE_SPACE_PROGRAM_ENEMY2_H
#define VIETNAMESE_SPACE_PROGRAM_ENEMY2_H


class Enemy2Object : public Entity
{
public:
    Enemy2Object(EntityManager* manager, int i, int j, std::string k, sf::RenderWindow* window);
    void updateEntity(sf::RenderWindow *window);
    virtual void collision(Entity* entity);
    sf::Clock clock;
private:

    int health;
    EntityManager* manager;
    int bulletSpeed = 2;
    //std::string Enemylist[75];
    //bool kolonne = false;
   //std::string TheEnemies[15];

};


#endif //VIETNAMESE_SPACE_PROGRAM_ENEMY2_H
