#include <iostream>
#include <cstring>
#include "../../Header Files/States/stateHighscoreState.h"
#include "../../Header Files/States/stateGameMode1.h"
#include "../../Header Files/States/stateMainMenu.h"

void stateHighscoreState::initialize(sf::RenderWindow *window) {

    memset(machine.keyPressed, 0, sizeof(machine.keyPressed)); //For at tastetrykk gjort i andre states ikke skal beholdes

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

    if(machine.keyPressed[sf::Keyboard::Return]){
        machine.setState(new stateMainMenu);
        memset(machine.keyPressed, 0, sizeof(machine.keyPressed));
    }
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

