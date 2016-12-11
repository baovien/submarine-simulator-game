#include <iostream>
#include "../../Include/Entities/enemy2.h"

Enemy2Object::Enemy2Object(EntityManager *manager, int i, int j, std::string k, sf::RenderWindow *window)
{
    this->load(k);
    this->active = 1;
    this->groupId = 4;
    this->health = 2;
    this->manager = manager;

    this->scale(-1,1);

    this->scale(0.4, 0.4);
    this->setOrigin(this->getGlobalBounds().height / 2, this->getGlobalBounds().height / 2);

    this->setPosition(window->getSize().x / 15 + i * this->getGlobalBounds().width,
                      window->getSize().y / 3 - this->getGlobalBounds().height * 5 +
                      j * this->getGlobalBounds().height);
    this->velocity.x = window->getSize().x/20 * *manager->deltaTime;

}

void Enemy2Object::updateEntity(sf::RenderWindow *window) {

    Entity::updateEntity(window);

    if (this->health < 2) {       //Destroy
        this->load("explosion.png");
        this->scale(5, 5);
        this->destroyEntity();
    }

    // Destroy enemy hvis den passerer player
    if (this->getPosition().y > window->getSize().y)
    {
        this->destroyEntity();
    }

    /*
    int tall = 0;
    for (int i = 0; i < sizeof(Enemylist) / sizeof(*Enemylist); i = i + 5)
    {
        for (int j = 4; j >= 0; j--)
        {
            if (this->manager->getEntity(Enemylist[i + j]) != NULL)
            {
                TheEnemies[tall] = Enemylist[i + j];
                kolonne = true;
            }
        }
        tall++;
    }

    sf::Time elapsed1 = clock.getElapsedTime(); //Tar her her opp verdien som ligger i klokk
    if (elapsed1.asMicroseconds() > 4000000) //Sjekker om verdien til clock er mer enn 3 sekunder
    {
        static bool t = true;
        while (t)
        {
            for (int i = 0; i < sizeof(TheEnemies) / sizeof(*TheEnemies); i++)
            {
                std::cout << TheEnemies[i] << std::endl;
            }
            t = false;
        }
        clock.restart(); //restarter clock(nullstiller)
    }

    // if (this->manager->getEntity(name)->getPosition().x > window->getSize().x)

}

    if(true){
        std::string name = "Enemy";
        for (int j = 0; j < 15 * 5; ++j)
        {
            if (j != 0)
            {
                name += "0";
            }

            if (this->manager->getEntity(name) != NULL)
            {
                if (this->manager->getEntity(name)->getPosition().x < 0)
                {

                    std::string name = "Enemy";
                    for (int j = 0; j < 15 * 5; ++j)
                    {
                        if (j != 0)
                        {
                            name += "0";
                        }
                        Entity* entity = this->manager->getEntity(name);

                        if (entity != nullptr)
                        {
                            entity->velocity.x = 5;
                            entity->setPosition(entity->getPosition().x, entity->getPosition().y + entity->getGlobalBounds().height);
                        }
                    }
                    break;
                }


            }
    }

     sf::Time elapsed1 = clock.getElapsedTime(); //Tar her her opp verdien som ligger i klokk

    if(elapsed1.asMicroseconds() > 2000000) {

        this->manager->addEntity("Bullet", new Bullet(this->getPosition().x, this->getPosition().y + this->getGlobalBounds().height, 5, 0, 0, window));
        clock.restart();
    }*/
    sf::Time elapsed1 = clock.getElapsedTime();
    if(elapsed1.asMicroseconds() >3000000){

    this->manager->addEntity("Bullet", new Bullet(this->getPosition().x, this->getPosition().y,7,0, 0,window));
        clock.restart();
    }
    }

void Enemy2Object::collision(Entity *entity)
{

    switch (entity->groupID())
    {
        case 2: // Bullets
            this->health--;
            break;

    }
}

