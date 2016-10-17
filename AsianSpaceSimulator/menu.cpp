#include <iostream>
#include "gamemode1.h"
#include "menu.h"

void main_menu::Initialize(sf::RenderWindow *window) {

    this->selected = 0;

    this->font = new sf::Font();
    this->font->loadFromFile("graphics/font1.otf");

    this->title = new sf::Text("SPACE", *this->font, 86U);
    this->title->setOrigin(this->title->getGlobalBounds().width / 2, this->title->getGlobalBounds().height / 2);
    this->title->setPosition(window->getSize().x / 2, window->getSize().y / 4);

    this->title2 = new sf::Text("SIMULATOR", *this->font, 86U);
    this->title2->setOrigin(this->title2->getGlobalBounds().width / 2, this->title2->getGlobalBounds().height / 2);
    this->title2->setPosition(window->getSize().x / 2, window->getSize().y / 4 + this->title2->getGlobalBounds().height);

    this->play = new sf::Text("Play", *this->font, 64U);
    this->play->setOrigin(this->play->getGlobalBounds().width / 2, this->play->getGlobalBounds().height / 2);
    this->play->setPosition(window->getSize().x / 2, window->getSize().y / 2);

    this->highscore = new sf::Text("Highscore", *this->font, 64U);
    this->highscore->setOrigin(this->highscore->getGlobalBounds().width / 2, this->highscore->getGlobalBounds().height / 2);
    this->highscore->setPosition(window->getSize().x / 2, window->getSize().y /2 + this->highscore->getGlobalBounds().height);

    this->options = new sf::Text("Options", *this->font, 64U);
    this->options->setOrigin(this->options->getGlobalBounds().width / 2, this->options->getGlobalBounds().height / 2);
    this->options->setPosition(window->getSize().x / 2, window->getSize().y /2 + this->options->getGlobalBounds().height*2);

    this->quit = new sf::Text("Exit", *this->font, 64U);
    this->quit->setOrigin(this->quit->getGlobalBounds().width / 2, this->quit->getGlobalBounds().height / 2);
    this->quit->setPosition(window->getSize().x / 2, window->getSize().y /2 + this->quit->getGlobalBounds().height*3);

}

void main_menu::Update(sf::RenderWindow *window) {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !this->upKey){
        this->selected -= 1;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !this->downKey){
        this->selected += 1;
    }

    if(this->selected > 3){
        this->selected = 0;
    }

    if(this->selected < 0){
        this->selected = 3;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)){
        switch(this->selected){
            case 0: //Play
                coreState.SetState(new gamemode1);
                break;
            case 1: //Highscore
                break;
            case 2: //Options
                break;
            case 3: //Exit
                quitGame = true;
                break;
        }
    }

    this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
    this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
}

void main_menu::Render(sf::RenderWindow *window) {

    this->play->setFillColor(sf::Color::White);
    this->highscore->setFillColor(sf::Color::White);
    this->options->setFillColor(sf::Color::White);
    this->quit->setFillColor(sf::Color::White);
    this->play->setStyle(0);
    this->highscore->setStyle(0);
    this->options->setStyle(0);
    this->quit->setStyle(0);



    switch(this->selected){
        case 0:
            this->play->setStyle(1<<3);
            break;
        case 1:
            this->highscore->setStyle(1<<3);
            break;
        case 2:
            this->options->setStyle(1<<3);
            break;
        case 3:
            this->quit->setStyle(1<<3);
            break;
    }
    window->draw(*this->title);
    window->draw(*this->title2);
    window->draw(*this->play);
    window->draw(*this->highscore);
    window->draw(*this->options);
    window->draw(*this->quit);
}

void main_menu::Destroy(sf::RenderWindow *window) {
    delete this->font;
    delete this->title;
    delete this->title2;
    delete this->play;
    delete this->highscore;
    delete this->options;
    delete this->quit;
}

