#include "../../Header Files/Entities/player.h"
#include "../../Header Files/Core/app.h"
//Initiater player, koden vår er satt opp for flere spillere så case 0 er spiller 1.
Player::Player(EntityManager* manager, float x, float y)
{
    this->load("Sprite_ship_1.png");
    this->active = 1;
    this->groupId =1;
    this->setOrigin(this->getGlobalBounds().height/2, this->getGlobalBounds().height/2);
    this->setPosition(x, y);
    this->manager = manager;
    this->space = false;

}
//update funksjonen har kontroll på bevegelsen til player.
void Player::update(sf::RenderWindow *window)
{
    up=0,down=0,left=0,right=0;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))left=1;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))right=1;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))up=1;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))down=1;

    //Bevegelse
    if (up && speed < maxSpeed)
    {
        if (speed < 0) speed += dec;
        else speed += acc;
    }
    if (down && speed >-maxSpeed)
    {
        if (speed > 0){
            speed -= dec;
        }else
        {
            speed -= acc;
        }
    }
    if (!up && !down)
    {
        if (speed - dec > 0) speed -= dec;
        else if (speed + dec < 0) speed += dec;
        else speed = 0;
    }
    if (right && speed != 0) angle += turnspeed * speed/maxSpeed;
    if (left && speed != 0) angle -= turnspeed * speed/maxSpeed;
    this->move(sin(angle) * speed, -cos(angle)*speed);
    this->setRotation(angle*180/3.141592);


    // this->velocity.x = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
    if(!this->space && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {
        std::cout << "FUNKER DETTE ????" << std::endl;
        this->manager->addEntity("bullet", new Bullet(this->getPosition().x, this->getPosition().y, -1));
    }

    //Spawne enemy ved å trykke på N knappen
    if(!this->nKey && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::N))
    {
        this->manager->addEntity("enemy", new EnemyObject(this->getPosition().x, this->getPosition().y, -3));
    }

    this->space = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
    this->nKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::N);

    Entity::update(window);

    if(this->getPosition().y - this->getGlobalBounds().height/2 < 0)
    {
        //this->setPosition(this->getPosition().x, 720 + this->getGlobalBounds().height);
        this->speed = 0;
        this->move(0,1);
    }

    if(this->getPosition().y + this->getGlobalBounds().height/2 > window->getSize().y)
    {
        //this->setPosition(this->getPosition().x, 0);
        this->speed = 0;
        this->move(0, -1);
    }
    if(this->getPosition().x - this->getGlobalBounds().width/2 < 0)
    {
        //this->setPosition(1279 + this->getGlobalBounds().width, this->getPosition().y);

        this->speed = 0;
        this->move(1, 0);
    }
    if(this->getPosition().x + this->getGlobalBounds().width/2 > window->getSize().x)
    {
        //this->setPosition(0, this->getPosition().y);
        this->speed = 0;
        this->move(-1, 0);
    }
}
//Her sjekker vi om vårt fly kræsjer med noen andre
void Player::collision(Entity* entity)
{
    switch(entity->groupID())
    {
        case 0:
            break;

    }
}