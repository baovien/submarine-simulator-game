
#include "../../Header Files/States/playconfig.h"
#include "../../Header Files/States/gamemode1.h"
#include "../../Header Files/States/menu.h"
#include "iostream"

void playconfig_menu::Initialize(sf::RenderWindow* window)
{
    this->selected = 0;

    this->font = new sf::Font();
    this->font->loadFromFile("graphics/font1.otf");

    this->theme = new sf::Text("Select theme", *this->font, 40U);
    this->theme->setOrigin(this->theme->getGlobalBounds().width / 2, this->theme->getGlobalBounds().height);
    this->theme->setPosition(window->getSize().x / 2, window->getSize().y / 25);

    this->fighter = new sf::Text("Select fighter", *this->font, 40U);
    this->fighter->setOrigin(this->fighter->getGlobalBounds().width / 2, this->theme->getGlobalBounds().height);
    this->fighter->setPosition(window->getSize().x / 2, window->getSize().y / 25 + this->theme->getGlobalBounds().height * 8);

    this->gamemode = new sf::Text("Select gamemode", *this->font, 40U);
    this->gamemode->setOrigin(this->gamemode->getGlobalBounds().width / 2, this->theme->getGlobalBounds().height);
    this->gamemode->setPosition(window->getSize().x / 2, window->getSize().y / 25 + this->theme->getGlobalBounds().height * 16);

    this->play = new sf::Text("Start", *this->font, 40U);
    this->play->setOrigin(this->play->getGlobalBounds().width / 2, this->theme->getGlobalBounds().height);
    this->play->setPosition(window->getSize().x / 3, window->getSize().y / 25 + this->theme->getGlobalBounds().height * 25);

    this->back = new sf::Text("Back", *this->font, 40U);
    this->back->setOrigin(this->back->getGlobalBounds().width / 2, this->theme->getGlobalBounds().height);
    this->back->setPosition(window->getSize().x / 1.5F, window->getSize().y / 25 + this->theme->getGlobalBounds().height * 25);

}

void playconfig_menu::Update(sf::RenderWindow* window)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape) && !this->escKey)
    {
        coreState.SetState(new main_menu);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !this->upKey){
        this->selected -= 1;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !this->downKey){
        this->selected += 1;
    }

    if(this->selected > 4){
        this->selected = 0;
    }

    if(this->selected < 0){
        this->selected = 4;
    }

    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && this->enterKey){
        switch(this->selected){
            case 0: //Theme
                break;
            case 1: //Fighter
                break;
            case 2: //Gamemode
                break;
            case 3: //Back
                coreState.SetState(new main_menu);
                break;
            case 4: //Play
                coreState.SetState(new gamemode1);
        }
    }

    this->escKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape);
    this->enterKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return);
    this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
    this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
}


void playconfig_menu::Render(sf::RenderWindow* window)
{
    this->theme->setFillColor(sf::Color::White);
    this->fighter->setFillColor(sf::Color::White);
    this->gamemode->setFillColor(sf::Color::White);
    this->play->setFillColor(sf::Color::White);
    this->back->setFillColor(sf::Color::White);
    this->theme->setStyle(0);
    this->fighter->setStyle(0);
    this->gamemode->setStyle(0);
    this->play->setStyle(0);
    this->back->setStyle(0);

    switch(this->selected){
        case 0:
            this->theme->setStyle(1<<3);
            break;
        case 1:
            this->fighter->setStyle(1<<3);
            break;
        case 2:
            this->gamemode->setStyle(1<<3);
            break;
        case 3:
            this->back->setStyle(1<<3);
            break;
        case 4:
            this->play->setStyle(1<<3);
            break;
    }

    window->draw(*this->theme);
    window->draw(*this->fighter);
    window->draw(*this->gamemode);
    window->draw(*this->play);
    window->draw(*this->back);

}

void playconfig_menu::Destroy(sf::RenderWindow* window)
{
    delete this->theme;
    delete this->font;
    delete this->fighter;
    delete this->gamemode;
    delete this->play;
    delete this->back;
}