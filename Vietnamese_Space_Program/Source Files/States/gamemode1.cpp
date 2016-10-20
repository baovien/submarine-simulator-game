#include "../../Header Files/States/gamemode1.h"
#include "../../Header Files/States/menu.h"

void gamemode1::Initialize(sf::RenderWindow* window)
{
    this->bullet = new bulletObject;
    this->font = new sf::Font();
    this->font->loadFromFile("Graphics/font.ttf");
    this->player1 = new playerObject(0);
    this->player1->setPosition(500,500);
    this->player1->setOrigin(this->player1->getGlobalBounds().width /2, this->player1->getGlobalBounds().height/2);
}
void gamemode1::Update(sf::RenderWindow* window)
{
    this->player1->Update();
    this->bullet->Updatebullet();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
    {
        coreState.SetState(new main_menu());
    }
}
void gamemode1::Render(sf::RenderWindow* window)
{
    window->draw(*this->bullet);
    window->draw(*this->player1);
}
void gamemode1::Destroy(sf::RenderWindow* window)
{
    delete this->bullet;
    delete this->player1;
}