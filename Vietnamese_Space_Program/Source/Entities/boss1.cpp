#include <iostream>
#include "../../Include/Entities/boss1.h"
Boss::Boss(EntityManager* manager)
{
    this->load("gold.png");
    this->active = 1;
    this->groupId = 5;
    this->health = 10;
    //this->setRotation(1);
    this->setOrigin(this->getGlobalBounds().height / 2, this->getGlobalBounds().height / 2);
    this->setScale(3,3);
    this->setPosition(-50,300);
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
    else if(this->health <= 4)
    { //Damaged
        this->load("goldDamaged.png");
        this->setScale(3,3);
    }
    // Destroy enemy hvis den er utenfor skjermen
    sf::Time elapsed1 = clock.getElapsedTime(); //Tar her her opp verdien som ligger i klokk

    /*if(elapsed1.asMicroseconds() > 1000000)
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


        this->manager->addEntity("Bullet", new Bullet(this->getPosition().x - this->getGlobalBounds().width/2, this->getPosition().y - this->getGlobalBounds().height/2, -5.0f, -5.0f, 315));
        this->manager->addEntity("Bullet", new Bullet(this->getPosition().x, this->getPosition().y - this->getGlobalBounds().height/2, 0.0f, -5.0f, 0));
        this->manager->addEntity("Bullet", new Bullet(this->getPosition().x + this->getGlobalBounds().width/2, this->getPosition().y - this->getGlobalBounds().height/2 , 5.0f, -5.0f, 45));
        this->manager->addEntity("Bullet", new Bullet(this->getPosition().x +  this->getGlobalBounds().width/2, this->getPosition().y, 5.0f, 0.0f, 90));
        this->manager->addEntity("Bullet", new Bullet(this->getPosition().x + this->getGlobalBounds().width/2, this->getPosition().y + this->getGlobalBounds().height/2 , 5.0f, 5.0f, 135));
        this->manager->addEntity("Bullet", new Bullet(this->getPosition().x, this->getPosition().y + this->getGlobalBounds().height/2, 0.0f, 5.0f, 180));
        this->manager->addEntity("Bullet", new Bullet(this->getPosition().x - this->getGlobalBounds().width/2, this->getPosition().y + this->getGlobalBounds().height/2, -5.0f, 5.0f, 225));

        clock.restart(); //restarter clock(nullstiller)

    */


       if(elapsed1.asMicroseconds() > 1350000)
       {
           x = this->getPosition().x;
           y = this->getPosition().y;
           height = this->getGlobalBounds().height;
           width = this->getGlobalBounds().width;
           angle = this->getRotation() * 3.141592653599 / 180;

           this->manager->addEntity("Bullet", new Bullet((x + (width / 2) * sin(angle)),
                                                         (y - (height / 2) * cos(angle)),
                                                         (-cos(angle) * bulletSpeed),
                                                         (sin(angle) * bulletSpeed), (angle * 180 / 3.141592653599)));

           this->manager->addEntity("Bullet", new Bullet((x - (width / 2) * sin(angle)),//Setter posisjon i x
                                                         (y + (height / 2) * cos(angle)),//Setter posisjon i y
                                                         (cos(angle) * bulletSpeed), //Setter fart i x
                                                         (-sin(angle) * bulletSpeed), //Setter fart i y
                                                         ((angle + 3.141592653599) * 180 /
                                                          3.141592653599))); //Setter vinkel på kula*/

           this->manager->addEntity("Bullet", new Bullet((x - (width / 2) * cos(angle)),//Setter posisjon i x
                                                         (y - (height / 2) * sin(angle)),//Setter posisjon i y
                                                         (-sin(angle) * bulletSpeed), //Setter fart i x
                                                         (-cos(angle) * bulletSpeed), //Setter fart i y
                                                         (((angle + ((3.141592653599 / 2) * 3)) * 180 /
                                                           3.141592653599)))); //Setter vinkel på kula*/

           this->manager->addEntity("Bullet", new Bullet((x + (width / 2) * cos(angle)),//Setter posisjon i x
                                                         (y + (height / 2) * sin(angle)),//Setter posisjon i y
                                                         (sin(angle) * bulletSpeed), //Setter fart i x
                                                         (cos(angle) * bulletSpeed), //Setter fart i y
                                                         (((angle + (3.141592653599 / 2)) * 180 /
                                                           3.141592653599)))); //Setter vinkel på kula*/

           clock.restart(); //restarter clock(nullstiller)
           velocity.x = 2;


           if (lok == true)
           {
               velocity.y = 2;
               lok = false;
           } else
           {
               velocity.y = -2;
               lok = true;
           }

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

