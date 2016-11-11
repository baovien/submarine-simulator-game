#include <iostream>
#include "../../Header Files/Entities/boss1.h"
Boss::Boss(EntityManager* manager)
{
    this->load("gold.png");
    this->active = 1;
    this->groupId = 5;
    this->health = 25;
    this->setRotation(2);
    this->setOrigin(this->getGlobalBounds().height / 2, this->getGlobalBounds().height / 2);
    this->setScale(3,3);
    this->setPosition(300,300);
    this->manager = manager;
    this->velocity.x = 0.5;
    this->score = score;

}
void Boss::updateEntity(sf::RenderWindow *window)
{
    this->rotate(1);
    //Endre sprites i forhold til health
    if(this->health <= 0)
    {   //Destroy
        this->load("explosion.png");
        this->scale(3,3);
        this->destroyEntity();
    }
    else if(this->health <= 8)
    { //Damaged
        this->load("goldDamaged.png");
    }
    // Destroy enemy hvis den er utenfor skjermen
    sf::Time elapsed1 = clock.getElapsedTime(); //Tar her her opp verdien som ligger i klokk
    if(elapsed1.asMicroseconds() > 1000000)
    {
        this->manager->addEntity("Bullet", new Bullet((this->getPosition().x + (this->getGlobalBounds().width / 2) * sin(this->getRotation()*3.141592/180)),
                                                      (this->getPosition().y - (this->getGlobalBounds().height / 2) * cos(this->getRotation()*3.141592/180)),
                                                      (-cos(this->getRotation()*3.141592/180) * 5),
                                                      (sin(this->getRotation()*3.141592/180) * 5),
                                                      (this->getRotation())));
        this->manager->addEntity("Bullet", new Bullet((this->getPosition().x - (this->getGlobalBounds().width / 2) * sin(this->getRotation()*3.141592/180)),
                                                      (this->getPosition().y + (this->getGlobalBounds().height / 2) * cos(this->getRotation()*3.141592/180)),
                                                      (cos(this->getRotation()*3.141592/180) * 5),
                                                      (-sin(this->getRotation()*3.141592/180) * 5),
                                                      (this->getRotation())));
        this->manager->addEntity("Bullet", new Bullet((this->getPosition().x - (this->getGlobalBounds().width / 2) * sin(this->getRotation()*3.141592/180)),
                                                      (this->getPosition().y),
                                                      (cos(this->getRotation()*3.141592/180) * 5),
                                                      (-sin(this->getRotation()*3.141592/180) * 5),
                                                      (this->getRotation())));


        /*this->manager->addEntity("Bullet", new Bullet(this->getPosition().x - this->getGlobalBounds().width/2, this->getPosition().y - this->getGlobalBounds().height/2, -5.0f, -5.0f, 315));
        this->manager->addEntity("Bullet", new Bullet(this->getPosition().x, this->getPosition().y - this->getGlobalBounds().height/2, 0.0f, -5.0f, 0));
        this->manager->addEntity("Bullet", new Bullet(this->getPosition().x + this->getGlobalBounds().width/2, this->getPosition().y - this->getGlobalBounds().height/2 , 5.0f, -5.0f, 45));
        this->manager->addEntity("Bullet", new Bullet(this->getPosition().x +  this->getGlobalBounds().width/2, this->getPosition().y, 5.0f, 0.0f, 90));
        this->manager->addEntity("Bullet", new Bullet(this->getPosition().x + this->getGlobalBounds().width/2, this->getPosition().y + this->getGlobalBounds().height/2 , 5.0f, 5.0f, 135));
        this->manager->addEntity("Bullet", new Bullet(this->getPosition().x, this->getPosition().y + this->getGlobalBounds().height/2, 0.0f, 5.0f, 180));
        this->manager->addEntity("Bullet", new Bullet(this->getPosition().x - this->getGlobalBounds().width/2, this->getPosition().y + this->getGlobalBounds().height/2, -5.0f, 5.0f, 225));
        */
        clock.restart(); //restarter clock(nullstiller)
    }

    Entity::updateEntity(window);
}
void Boss::collision(Entity* entity)
{
    switch(entity->groupID())
    {
        case 2: // Bullets
            this->health--;
            break;
    }
}
Boss::~Boss()
{
    this->destroyEntity();
}

