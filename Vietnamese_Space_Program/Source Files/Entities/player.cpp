#include <iostream>
#include "../../Header Files/Entities/player.h"

Player::Player(Lives* lives, Score* score, EntityManager* manager, float x, float y)
{
    this->load("fighter.png");
    this->active = 1;
    this->groupId = 1;
    this->setOrigin(this->getGlobalBounds().height/2, this->getGlobalBounds().height/2);
    this->setPosition(x, y);
    this->manager = manager;
    this->space = false;
    this->score = score;
    this->lives = lives;
    this->scale(0.5,0.5);
}

//update funksjonen har kontroll på bevegelsen til player.
void Player::updateEntity(sf::RenderWindow *window)
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
    this->setRotation(angle*180/pi);


    // this->velocity.x = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
    if(!this->space && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {
        if(this->overheat < 10) {
            this->manager->addEntity("bullet", new Bullet((this->score),
                                                          (this->getPosition().x + ((this->getGlobalBounds().height) / 2) * sin(angle)),
                                                          (this->getPosition().y - (this->getGlobalBounds().width / 2) * cos(angle)),
                                                          ( -cos(angle) * 15),
                                                          (sin(angle) * 15), (angle*180/pi)));
            this->overheat += 2;
            if(this->overheat > 10)this->overheat = 15;
        }
    }
    this->overheat -= 0.1;
    if(this->overheat < 0)this->overheat = 0;
    this->space = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);

    Entity::updateEntity(window);

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
        case 3: // Asteroid
            entity->destroyEntity();
            this->lives->decreaseLife();
            if(this->lives->getValue() <= 0){
                this->destroyEntity();
            }
            break;
        case 4: // Enemy
            this->lives->decreaseLife();
            if(this->lives->getValue() <= 0){
                this->destroyEntity();
            }
            break;
    }
}