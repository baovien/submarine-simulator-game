#include "../../Header Files/Entities/playerobject.h"
//Initiater player, koden vår er satt opp for flere spillere så case 0 er spiller 1.
playerObject::playerObject(int playerNumber)
{
    this->playerNumber  = playerNumber;

    switch(this->playerNumber)
    {
        case 0:
            this->Load("Sprite_ship_1.png");
            break;
        default:
            break;
    }
}
//Update funksjonen har kontroll på bevegelsen til player 1.
void playerObject::Update()
{
    bool up, down, left, right;
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
        default:
            break;

    }
    //Denne funksjonen passer på at flyet ikke kan fly ut av vinduet.
    Entity::Update();

    if(this->getPosition().y < 0)
    {
        this->move(0, 2.5f);
    }
    if(this->getPosition().y + this->getGlobalBounds().height > 1080)
    {
        this->move(0, -2.5f);
    }
    if(this->getPosition().x < 0)
    {
        this->move(2.5f, 0);
    }
    if(this->getPosition().x + this->getGlobalBounds().width > 1920)
    {
        this->move(-2.5f, 0);
    }
}