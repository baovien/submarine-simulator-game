#include <iostream>
#include "../../Header Files/States/stateHighscoreState.h"
#include "../../Header Files/States/stateGameMode1.h"
#include "../../Header Files/States/stateMenu.h"

void stateHighscoreState::initialize(sf::RenderWindow *window) {

    this->selected = 0;

    this->font = new sf::Font();
    this->font->loadFromFile("Graphics/font1.otf");

    this->title = new sf::Text("Highscore", *this->font, 70U);
    this->title->setOrigin(this->title->getGlobalBounds().width / 2, this->title->getGlobalBounds().height / 0.3);
    this->title->setPosition(window->getSize().x / 2, window->getSize().y / 4);
    
    this->back = new sf::Text("Press enter to go back", *this->font, 16U);
    this->back->setOrigin(this->back->getGlobalBounds().width / 2, this->back->getGlobalBounds().height / 2);
    this->back->setPosition(window->getSize().x / 1.1, window->getSize().y / 1.1);

}

void stateHighscoreState::update(sf::RenderWindow *window) {

    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && this->enterKey){
        machine.setState(new stateMainMenu);
    }

    this->enterKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return);
}

void stateHighscoreState::render(sf::RenderWindow *window) {

    this->title->setFillColor(sf::Color::Blue);
    this->back->setFillColor(sf::Color::Red);


    window->draw(*this->title);
    window->draw(*this->back);
}

void stateHighscoreState::destroy(sf::RenderWindow *window) {
    delete this->font;
    delete this->title;
    delete this->back;
}

