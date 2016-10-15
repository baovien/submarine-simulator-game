#include "gamemode1.h"
#include "menu.h"

void gamemode1::Initialize(sf::RenderWindow* window)
{
    this->font = new sf::Font();
    this->font->loadFromFile("Graphics/font.ttf");
    this->player1 = new playerObject(0);
}
void gamemode1::Update(sf::RenderWindow* window)
{
    this->player1->Update();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
    {
        coreState.SetState(new main_menu());
    }
}
void gamemode1::Render(sf::RenderWindow* window)
{
    window->draw(*this->player1);
}
void gamemode1::Destroy(sf::RenderWindow* window)
{
    delete this->player1;
}