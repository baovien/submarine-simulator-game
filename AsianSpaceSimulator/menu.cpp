#include "menu.h"
#include "gamemode1.h"
void main_menu::Initialize(sf::RenderWindow* window)
{
    this->selected = 0;
    this->font = new sf::Font();
    this->font->loadFromFile("Graphics/font.ttf");
    this->title = new sf::Text("LETSGO", *this->font, 200U);
    this->title->setOrigin(this->title->getGlobalBounds().width / 2, this->title->getGlobalBounds().height / 2);
    this->title->setPosition(window->getSize().x / 2, window->getSize().y / 8);

    this->play = new sf::Text("Play", *this->font, 64U);
    this->play->setOrigin(this->play->getGlobalBounds().width / 2, this->play->getGlobalBounds().height / 2);
    this->play->setPosition(window->getSize().x / 2, window->getSize().y / 2.1);

    this->quit = new sf::Text("Quit", *this->font, 64U);
    this->quit->setOrigin(this->quit->getGlobalBounds().width / 2, this->quit->getGlobalBounds().height / 2);
    this->quit->setPosition(window->getSize().x / 2, window->getSize().y - 100);

}
void main_menu::Update(sf::RenderWindow* window)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !this->upKey)
    {
        this->selected += 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !this->downKey)
    {
        this->selected -= 1;
    }
    if(this->selected > 1)
    {
        this->selected = 0;
    }
    if(this->selected < 0)
    {
        this->selected = 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
    {
        switch(this->selected)
        {
            case 0:
                coreState.SetState(new gamemode1());
                break;
            case 1:
                quitGame = true;
                break;
            case 2:
                // flere menyvalg
                break;

        }
    }
    this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
    this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
}
void main_menu::Render(sf::RenderWindow* window)
{
    this->play->setFillColor(sf::Color::White);
    this->quit->setFillColor(sf::Color::White);


    switch(this->selected)
    {
        case 0:
            this->play->setFillColor(sf::Color::Green);
            break;
        case 1:
            this->quit->setFillColor(sf::Color::Green);
            break;
        case 2:
            //når vi har flere menyvalg er det er vi fyller inn fargen på valget når den er "selected" XD
            break;
    }
    window->draw(*this->title);
    window->draw(*this->play);
    window->draw(*this->quit);
}
void main_menu::Destroy(sf::RenderWindow* window)
{
    delete this->font;
    delete this->title;
    delete this->play;
    delete this->quit;
}