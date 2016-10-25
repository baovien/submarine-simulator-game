#include <iostream>
#include "../../Header Files/States/stateMenu.h"
#include "../../Header Files/States/stateHighscoreState.h"
#include "../../Header Files/States/statePlayConfig.h"
#include "../../Header Files/States/stateSettings.h"

void MainMenu::initialize(sf::RenderWindow *window) {

    this->selected = 0;

    this->font = new sf::Font();
    this->font->loadFromFile("Graphics/font1.otf");

    this->title = new sf::Text("SPACE", *this->font, textSize+30);
    this->title->setOrigin(this->title->getGlobalBounds().width / 2, this->title->getGlobalBounds().height / 2);
    this->title->setPosition(window->getSize().x / 2, window->getSize().y / 4);

    this->title2 = new sf::Text("SIMULATOR", *this->font, textSize+30);
    this->title2->setOrigin(this->title2->getGlobalBounds().width / 2, this->title2->getGlobalBounds().height / 2);
    this->title2->setPosition(window->getSize().x / 2, window->getSize().y / 4 + this->title2->getGlobalBounds().height);

    this->play = new sf::Text("Play", *this->font, textSize);
    this->play->setOrigin(this->play->getGlobalBounds().width / 2, this->play->getGlobalBounds().height / 2);
    this->play->setPosition(window->getSize().x / 2, window->getSize().y / 2);

    this->highscore = new sf::Text("Highscore", *this->font, textSize);
    this->highscore->setOrigin(this->highscore->getGlobalBounds().width / 2, this->highscore->getGlobalBounds().height / 2);
    this->highscore->setPosition(window->getSize().x / 2, window->getSize().y /2 + this->highscore->getGlobalBounds().height*1.5);

    this->options = new sf::Text("Options", *this->font, textSize);
    this->options->setOrigin(this->options->getGlobalBounds().width / 2, this->options->getGlobalBounds().height / 2);
    this->options->setPosition(window->getSize().x / 2, window->getSize().y /2 + this->options->getGlobalBounds().height*3);

    this->quit = new sf::Text("Exit", *this->font, textSize);
    this->quit->setOrigin(this->quit->getGlobalBounds().width / 2, this->quit->getGlobalBounds().height / 2);
    this->quit->setPosition(window->getSize().x / 2, window->getSize().y /2 + this->quit->getGlobalBounds().height*4.5);

}

void MainMenu::update(sf::RenderWindow *window) {
    //Vertical selection
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !this->upKey){
        this->selected -= 1;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !this->downKey){
        this->selected += 1;
    }
    //Vertical selection bounds
    if(this->selected > 3){
        this->selected = 0;
    }

    if(this->selected < 0){
        this->selected = 3;
    }
    //Stateswitch on enter
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && !this->enterKey){
        switch(this->selected){
            case 0: //Play
                machine.setState(new PlayConfigMenu);
                break;
            case 1: //Highscore
                machine.setState(new stateHighscoreState);
                break;
            case 2: //Options
                machine.setState(new stateSettings);
                break;
            case 3: //Exit
                quitGame = true;
                break;
        }
    }

    this->enterKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return);
    this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
    this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
    this->enterKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return);
}

void MainMenu::render(sf::RenderWindow *window) {

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

void MainMenu::destroy(sf::RenderWindow *window) {
    delete this->font;
    delete this->title;
    delete this->title2;
    delete this->play;
    delete this->highscore;
    delete this->options;
    delete this->quit;
}

