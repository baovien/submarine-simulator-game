#include <iostream>
#include <cstring>
#include "../../Include/States/StateHighscore.h"
#include "../../Include/States/stateGameMode1.h"
#include "../../Include/States/stateMainMenu.h"


void StateHighscore::initialize(sf::RenderWindow *window) {
    machine.mouseClick = {-1,-1};

    sf::View newView(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
    window->setView(newView);

    this->bgTexture = new sf::Texture();
    this->bgTexture->loadFromFile("Graphics/Sprites/bg_purple.png");

    this->tbTexture = new sf::Texture();
    this->tbTexture->loadFromFile("Graphics/Sprites/table.png");


    this->background = new sf::Sprite();
    this->background->setTexture(*this->bgTexture);
    this->background->scale(window->getSize().x/background->getGlobalBounds().width,window->getSize().y/background->getGlobalBounds().height);

    this->table = new sf::Sprite();
    this->table->setTexture(*this->tbTexture);
    this->table->setOrigin(this->table->getGlobalBounds().width / 2, this->table->getGlobalBounds().height / 2);
    this->table->scale(1,0.7);
    this->table->setPosition(window->getSize().x/2,window->getSize().y/2);

    this->selected = 0;

    this->font = new sf::Font();
    this->font->loadFromFile("Graphics/font1.otf");

    this->title = new sf::Text("Highscore", *this->font, 70U);
    this->title->setOrigin(this->title->getGlobalBounds().width / 2, this->title->getGlobalBounds().height / 2);
    this->title->setPosition(window->getSize().x / 2, window->getSize().y / 20);

    this->playerText = new sf::Text("Player", *this->font, 35U);
    this->playerText->setOrigin(this->playerText->getGlobalBounds().width / 2, this->playerText->getGlobalBounds().height / 2);
    this->playerText->setPosition(window->getSize().x / 2, window->getSize().y / 4.9);

    this->backText = new sf::Text("Press " + machine.keybindMap.find("back")->second.first + " to go back", *this->font, 16U);
    this->backText->setOrigin(this->backText->getGlobalBounds().width / 2, this->backText->getGlobalBounds().height / 2);
    this->backText->setPosition(window->getSize().x / 2, window->getSize().y / 1.1);

    this->scoreText = new sf::Text("Score", *this->font, 35U);
    this->scoreText->setOrigin(this->scoreText->getGlobalBounds().width / 2, this->scoreText->getGlobalBounds().height / 2);
    this->scoreText->setPosition(window->getSize().x / 1.24, window->getSize().y / 4.9);

    this->place = new sf::Text("#", *this->font, 35U);
    this->place->setOrigin(this->place->getGlobalBounds().width / 2, this->place->getGlobalBounds().height / 2);
    this->place->setPosition(window->getSize().x / 5.3, window->getSize().y / 4.9);
    

    //For-løkke for plasseringstallene i tabellen
    for (int i = 0; i <10 ; ++i) {
        sf::Text* pt;
        placeVector.push_back(pt);
        placeVector[i] = new sf::Text(numbers[i], *this->font, 30);
        placeVector[i]->setOrigin(placeVector[i]->getGlobalBounds().width / 2,placeVector[i]->getGlobalBounds().height / 2);
        placeVector[i]->setPosition(window->getSize().x / 5.2,window->getSize().y / 3.77 - (window->getSize().y / 3.77-window->getSize().y / 3.115)*i);


    }

}

void StateHighscore::update(sf::RenderWindow *window) {

    if (sf::Mouse::getPosition(*window).x + backText->getGlobalBounds().width / 2 > backText->getPosition().x &&
        sf::Mouse::getPosition(*window).x - backText->getGlobalBounds().width / 2 < backText->getPosition().x &&
        sf::Mouse::getPosition(*window).y + backText->getGlobalBounds().height / 2 > backText->getPosition().y &&
        sf::Mouse::getPosition(*window).y - backText->getGlobalBounds().height / 2 < backText->getPosition().y) {
        this->selected = 0;
    } else {
        this->selected = 1;
    }
    if (machine.mouseClick.x + backText->getGlobalBounds().width / 2 > backText->getPosition().x &&
        machine.mouseClick.x - backText->getGlobalBounds().width / 2 < backText->getPosition().x &&
        machine.mouseClick.y + backText->getGlobalBounds().height / 2 > backText->getPosition().y &&
        machine.mouseClick.y - backText->getGlobalBounds().height / 2 < backText->getPosition().y) {
        //Menu
        machine.mouseClick = {-1, -1};
        machine.setState(new StateMainMenu);
        return;
    }
}

void StateHighscore::render(sf::RenderWindow *window) {

    this->title->setFillColor(sf::Color::Cyan);
    this->backText->setFillColor(sf::Color::Cyan);
    this->playerText->setFillColor(sf::Color::Magenta);
    this->scoreText->setFillColor(sf::Color::Magenta);
    this->place->setFillColor(sf::Color::Magenta);
    this->backText->setStyle(0);

    switch(this->selected){
        case 0:
            this->backText->setStyle(1<<3);
            break;
    }
    //Farge for plasseringstallene i tabellen
    for (int i = 0; i <10 ; ++i) {
        this->placeVector[i]->setFillColor(sf::Color::White);

    }
    
    window->draw(*this->background);
    window->draw(*this->table);
    window->draw(*this->playerText);
    window->draw(*this->place);
    window->draw(*this->scoreText);
    window->draw(*this->title);
    window->draw(*this->backText);

    for (int i = 0; i <10 ; ++i) {

        window->draw(*this->placeVector[i]);
    }
   
}

void StateHighscore::destroy(sf::RenderWindow *window) {
    delete this->background;
    delete this->table;
    delete this->font;
    delete this->title;
    delete this->backText;
    delete this->playerText;
    delete this->scoreText;
    delete this->place;

    for (int i = 0; i <10 ; ++i) {

        delete this->placeVector[i];

    }
    
}

void StateHighscore::handleEvent(sf::RenderWindow *window, sf::Event event){
    if(event.key.code == machine.keybindMap.find("back")->second.second) {
        machine.setState(new StateMainMenu);
        return;
    }
}

void StateHighscore::reinitialize(sf::RenderWindow *window) {

}
