#include "../../Header Files/Entities/playerobject.h"
#include "../../Header Files/Entities/bullet.h"
//Initiater player, koden vår er satt opp for flere spillere så case 0 er spiller 1.
PlayerObject::PlayerObject(int playerNumber)
{
    this->playerNumber  = playerNumber;

    switch(this->playerNumber)
    {
        case 0:
            this->load("Sprite_ship_1.png");
            break;
        default:
            break;
    }
}
//update funksjonen har kontroll på bevegelsen til player 1.
void PlayerObject::update()
{
    bool up=0, down=0, left=0, right=0;
    //Siden koden er laget for flere spillere må man spesifisere hvilken av spillerne som skal oppdateres. Case 0 er fortsatt player 1.
    switch(this->playerNumber) {
        case 0:
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))left=1;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))right=1;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))up=1;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))down=1;

            //Bevegelse
            if (up && speed < maxSpeed) {
                if (speed < 0) speed += dec;
                else speed += acc;
            }
            if (down && speed >-maxSpeed) {
                if (speed > 0){
                    speed -= dec;
                }else {
                    speed -= acc;
                }
            }
            if (!up && !down){
                if (speed - dec > 0) speed -= dec;
                else if (speed + dec < 0) speed += dec;
                else speed = 0;
            }
            if (right && speed != 0) angle += turnspeed * speed/maxSpeed;
            if (left && speed != 0) angle -= turnspeed * speed/maxSpeed;

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
            {
                //spawn bullet
            }


        default:
            break;

    }
    //Denne funksjonen passer på at flyet ikke kan fly ut av vinduet.
    Entity::update();

    if(this->getPosition().y - this->getGlobalBounds().height/2 < 0)
    {
        this->move(0, speed);
    }
    if(this->getPosition().y + this->getGlobalBounds().height/2 > 600)
    {
        this->move(0, -speed);
    }
    if(this->getPosition().x - this->getGlobalBounds().width/2 < 0)
    {
        this->move(speed, 0);
    }
    if(this->getPosition().x + this->getGlobalBounds().width/2 > 800)
    {
        this->move(-speed, 0);
    }
}