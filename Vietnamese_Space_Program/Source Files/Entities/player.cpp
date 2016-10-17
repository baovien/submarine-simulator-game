#include "../../Header Files/Entities/playerobject.h"

playerObject::playerObject(int playerNumber)
{
    this->playerNumber  = playerNumber;
    switch(this->playerNumber)
    {
        case 0:
            this->Load("ball.png");
            break;
        default:
            break;
    }
}
void playerObject::Update()
{
    switch(this->playerNumber)
    {
        case 0:
            this->velocity.y = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
            this->velocity.x = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A);
            break;
        default:
            break;
    }
    Entity::Update();
    if(this->getPosition().y < 0)
    {
        this->move(0, 1.0f);
    }
    if(this->getPosition().y + this->getGlobalBounds().height > 1080)
    {
        this->move(0, -1.0f);
    }
    if(this->getPosition().x < 0)
    {
        this->move(1.0f, 0);
    }
    if(this->getPosition().x + this->getGlobalBounds().height > 1920)
    {
        this->move(-1.0f, 0);
    }
}