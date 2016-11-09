#include <iostream>
#include <cstring>
#include "../../Header Files/States/stateHighscoreState.h"
#include "../../Header Files/States/stateGameMode1.h"
#include "../../Header Files/States/stateMainMenu.h"

void stateHighscoreState::initialize(sf::RenderWindow *window) {

    memset(machine.keyPressed, 0, sizeof(machine.keyPressed)); //For at tastetrykk gjort i andre states ikke skal beholdes

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
    this->playerText->setPosition(window->getSize().x / 2, window->getSize().y / 5.2);
    
    this->backText = new sf::Text("Press enter to go back", *this->font, 16U);
    this->backText->setOrigin(this->backText->getGlobalBounds().width / 2, this->backText->getGlobalBounds().height / 2);
    this->backText->setPosition(window->getSize().x / 2, window->getSize().y / 1.1);

    this->scoreText = new sf::Text("Score", *this->font, 35U);
    this->scoreText->setOrigin(this->scoreText->getGlobalBounds().width / 2, this->scoreText->getGlobalBounds().height / 2);
    this->scoreText->setPosition(window->getSize().x / 1.24, window->getSize().y / 5.2);

    this->playerPlace = new sf::Text("#", *this->font, 35U);
    this->playerPlace->setOrigin(this->playerPlace->getGlobalBounds().width / 2, this->playerPlace->getGlobalBounds().height / 2);
    this->playerPlace->setPosition(window->getSize().x / 5.3, window->getSize().y / 5.2);

    this->playerPlace1 = new sf::Text("1.", *this->font, 35U);
    this->playerPlace1->setOrigin(this->playerPlace1->getGlobalBounds().width / 2, this->playerPlace1->getGlobalBounds().height / 2);
    this->playerPlace1->setPosition(window->getSize().x / 5.2, window->getSize().y / 3.92);

    this->playerPlace2 = new sf::Text("2.", *this->font, 35U);
    this->playerPlace2->setOrigin(this->playerPlace2->getGlobalBounds().width / 2, this->playerPlace2->getGlobalBounds().height / 2);
    this->playerPlace2->setPosition(window->getSize().x / 5.2, window->getSize().y / 3.2);

    this->playerPlace3 = new sf::Text("3.", *this->font, 35U);
    this->playerPlace3->setOrigin(this->playerPlace3->getGlobalBounds().width / 2, this->playerPlace3->getGlobalBounds().height / 2);
    this->playerPlace3->setPosition(window->getSize().x / 5.2, window->getSize().y / 2.7);

    this->playerPlace4 = new sf::Text("4.", *this->font, 35U);
    this->playerPlace4->setOrigin(this->playerPlace4->getGlobalBounds().width / 2, this->playerPlace4->getGlobalBounds().height / 2);
    this->playerPlace4->setPosition(window->getSize().x / 5.2, window->getSize().y / 2.33);

    this->playerPlace5 = new sf::Text("5.", *this->font, 35U);
    this->playerPlace5->setOrigin(this->playerPlace5->getGlobalBounds().width / 2, this->playerPlace5->getGlobalBounds().height / 2);
    this->playerPlace5->setPosition(window->getSize().x / 5.2, window->getSize().y / 2.05);

    this->playerPlace6 = new sf::Text("6.", *this->font, 35U);
    this->playerPlace6->setOrigin(this->playerPlace6->getGlobalBounds().width / 2, this->playerPlace6->getGlobalBounds().height / 2);
    this->playerPlace6->setPosition(window->getSize().x / 5.2, window->getSize().y / 1.83);

    this->playerPlace7 = new sf::Text("7.", *this->font, 35U);
    this->playerPlace7->setOrigin(this->playerPlace7->getGlobalBounds().width / 2, this->playerPlace7->getGlobalBounds().height / 2);
    this->playerPlace7->setPosition(window->getSize().x / 5.2, window->getSize().y / 1.65);

    this->playerPlace8 = new sf::Text("8.", *this->font, 35U);
    this->playerPlace8->setOrigin(this->playerPlace8->getGlobalBounds().width / 2, this->playerPlace8->getGlobalBounds().height / 2);
    this->playerPlace8->setPosition(window->getSize().x / 5.2, window->getSize().y / 1.51);

    this->playerPlace9 = new sf::Text("9.", *this->font, 35U);
    this->playerPlace9->setOrigin(this->playerPlace9->getGlobalBounds().width / 2, this->playerPlace9->getGlobalBounds().height / 2);
    this->playerPlace9->setPosition(window->getSize().x / 5.2, window->getSize().y / 1.39);

    this->playerPlace10 = new sf::Text("10.", *this->font, 35U);
    this->playerPlace10->setOrigin(this->playerPlace10->getGlobalBounds().width / 2, this->playerPlace10->getGlobalBounds().height / 2);
    this->playerPlace10->setPosition(window->getSize().x / 5.2, window->getSize().y / 1.29);

}

void stateHighscoreState::update(sf::RenderWindow *window) {

    if(machine.keyPressed[sf::Keyboard::Return]){
        machine.setState(new stateMainMenu);
        memset(machine.keyPressed, 0, sizeof(machine.keyPressed));
    }
}

void stateHighscoreState::render(sf::RenderWindow *window) {

    this->title->setFillColor(sf::Color::Blue);
    this->backText->setFillColor(sf::Color::Red);
    this->playerText->setFillColor(sf::Color::White);
    this->scoreText->setFillColor(sf::Color::White);
    this->playerPlace->setFillColor(sf::Color::White);

    this->playerPlace1->setFillColor(sf::Color::White);
    this->playerPlace2->setFillColor(sf::Color::White);
    this->playerPlace3->setFillColor(sf::Color::White);
    this->playerPlace4->setFillColor(sf::Color::White);
    this->playerPlace5->setFillColor(sf::Color::White);
    this->playerPlace6->setFillColor(sf::Color::White);
    this->playerPlace7->setFillColor(sf::Color::White);
    this->playerPlace8->setFillColor(sf::Color::White);
    this->playerPlace9->setFillColor(sf::Color::White);
    this->playerPlace10->setFillColor(sf::Color::White);

    window->draw(*this->background);
    window->draw(*this->table);
    window->draw(*this->playerText);
    window->draw(*this->playerPlace);
    window->draw(*this->scoreText);
    window->draw(*this->title);
    window->draw(*this->backText);

    window->draw(*this->playerPlace1);
    window->draw(*this->playerPlace2);
    window->draw(*this->playerPlace3);
    window->draw(*this->playerPlace4);
    window->draw(*this->playerPlace5);
    window->draw(*this->playerPlace6);
    window->draw(*this->playerPlace7);
    window->draw(*this->playerPlace8);
    window->draw(*this->playerPlace9);
    window->draw(*this->playerPlace10);

}

void stateHighscoreState::destroy(sf::RenderWindow *window) {
    delete this->background;
    delete this->table;
    delete this->font;
    delete this->title;
    delete this->backText;
    delete this->playerText;
    delete this->playerPlace;
    delete this->scoreText;

    delete this->playerPlace1;
    delete this->playerPlace2;
    delete this->playerPlace3;
    delete this->playerPlace4;
    delete this->playerPlace5;
    delete this->playerPlace6;
    delete this->playerPlace7;
    delete this->playerPlace8;
    delete this->playerPlace9;
    delete this->playerPlace10;


}

