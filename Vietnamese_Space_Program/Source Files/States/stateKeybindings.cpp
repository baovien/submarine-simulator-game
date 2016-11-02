#include "../../Header Files/States/stateKeybindings.h"

#include <cstring>
#include <iostream>

/**
 * Init settingsState.
 * @param window
 */
void stateKeybindings::initialize(sf::RenderWindow *window) {

    memset(machine.keyPressed, 0, sizeof(machine.keyPressed)); //For at tastetrykk gjort i andre states ikke skal beholdes

    this->bgTexture = new sf::Texture();
    this->bgTexture->loadFromFile("Graphics/Sprites/bg_purple.png");

    this->ballTexture = new sf::Texture();
    this->ballTexture->loadFromFile("Graphics/Sprites/blackbackground.png");

    this->background = new sf::Sprite();
    this->background->setTexture(*this->bgTexture);
    this->background->setOrigin(this->background->getGlobalBounds().width / 2, this->background->getGlobalBounds().height / 2);
    this->background->scale(window->getSize().x/background->getGlobalBounds().width/2,window->getSize().y/background->getGlobalBounds().height/2);
    this->background->setPosition(window->getSize().x/2, window->getSize().y/2);

    this->upKeySquare = new sf::Sprite();
    this->upKeySquare->setTexture(*this->ballTexture);
    this->upKeySquare->setOrigin(this->upKeySquare->getGlobalBounds().width / 2, this->upKeySquare->getGlobalBounds().height / 2);
    this->upKeySquare->scale(window->getSize().x/background->getGlobalBounds().width/8,window->getSize().x/background->getGlobalBounds().width/8);
    this->upKeySquare->setPosition(((window->getSize().x / 2) - this->background->getGlobalBounds().width/4) , (window->getSize().y / 2) - this->background->getGlobalBounds().height/6);

    this->downKeySquare = new sf::Sprite();
    this->downKeySquare->setTexture(*this->ballTexture);
    this->downKeySquare->setOrigin(this->downKeySquare->getGlobalBounds().width / 2, this->downKeySquare->getGlobalBounds().height / 2);
    this->downKeySquare->scale(window->getSize().x/background->getGlobalBounds().width/8,window->getSize().x/background->getGlobalBounds().width/8);
    this->downKeySquare->setPosition(((window->getSize().x / 2) - this->background->getGlobalBounds().width/4) , (window->getSize().y / 2) + this->background->getGlobalBounds().height/7);

    this->leftKeySquare = new sf::Sprite();
    this->leftKeySquare->setTexture(*this->ballTexture);
    this->leftKeySquare->setOrigin(this->leftKeySquare->getGlobalBounds().width / 2, this->leftKeySquare->getGlobalBounds().height / 2);
    this->leftKeySquare->scale(window->getSize().x/background->getGlobalBounds().width/8,window->getSize().x/background->getGlobalBounds().width/8);
    this->leftKeySquare->setPosition(((window->getSize().x / 2) - this->background->getGlobalBounds().width/2.4) , (window->getSize().y / 2) + this->background->getGlobalBounds().height/7);

    this->rightKeySquare = new sf::Sprite();
    this->rightKeySquare->setTexture(*this->ballTexture);
    this->rightKeySquare->setOrigin(this->rightKeySquare->getGlobalBounds().width / 2, this->rightKeySquare->getGlobalBounds().height / 2);
    this->rightKeySquare->scale(window->getSize().x/background->getGlobalBounds().width/8,window->getSize().x/background->getGlobalBounds().width/8);
    this->rightKeySquare->setPosition(((window->getSize().x / 2) - this->background->getGlobalBounds().width/2 + this->background->getGlobalBounds().width/2.4) , (window->getSize().y / 2) + this->background->getGlobalBounds().height/7);


    this->backKeySquare = new sf::Sprite();
    this->backKeySquare->setTexture(*this->ballTexture);
    this->backKeySquare->setOrigin(this->backKeySquare->getGlobalBounds().width / 2, this->backKeySquare->getGlobalBounds().height / 2);
    this->backKeySquare->scale(window->getSize().x/background->getGlobalBounds().width/8,window->getSize().x/background->getGlobalBounds().width/8);
    this->backKeySquare->setPosition((window->getSize().x / 2) - this->background->getGlobalBounds().width/4));


    this->font = new sf::Font();
    this->font->loadFromFile("Graphics/font1.otf");

    this->gameKeybinds = new sf::Text("Movement", *this->font, 25);
    this->gameKeybinds->setOrigin(this->gameKeybinds->getGlobalBounds().width / 2, this->gameKeybinds->getGlobalBounds().height / 2);
    this->gameKeybinds->setPosition(((window->getSize().x / 2) - this->background->getGlobalBounds().width/4) , (window->getSize().y / 2) - this->background->getGlobalBounds().height/2.25);

    this->menuNavigationText = new sf::Text("Menu navigation", *this->font, 25);
    this->menuNavigationText->setOrigin(this->menuNavigationText->getGlobalBounds().width / 2, this->gameKeybinds->getGlobalBounds().height / 2);
    this->menuNavigationText->setPosition(((window->getSize().x / 2) + this->background->getGlobalBounds().width/4) , (window->getSize().y / 2) - this->background->getGlobalBounds().height/2.25);

    this->navigationText = new sf::Text("Gameplay", *this->font, 25);
    this->navigationText->setOrigin(this->navigationText->getGlobalBounds().width / 2, this->gameKeybinds->getGlobalBounds().height / 2);
    this->navigationText->setPosition(((window->getSize().x / 2) + this->background->getGlobalBounds().width/4) , (window->getSize().y / 2));

}
/**
 * Update on keyevent, navigation through settings
 * @param window
 */
void stateKeybindings::update(sf::RenderWindow *window) {

}
/**
 *
 * @param window
 */
void stateKeybindings::render(sf::RenderWindow *window) {
    this->gameKeybinds->setFillColor(sf::Color::White);
    this->gameKeybinds->setStyle(0);

    window->draw(*this->background);
    window->draw(*this->upKeySquare);
    window->draw(*this->downKeySquare);
    window->draw(*this->leftKeySquare);

    window->draw(*this->rightKeySquare);
    window->draw(*this->gameKeybinds);
    window->draw(*this->menuNavigationText);
    window->draw(*this->navigationText);
}

void stateKeybindings::destroy(sf::RenderWindow *window) {
    delete this->bgTexture;
    delete this->upKeySquare;
    delete this->downKeySquare;

    delete this->rightKeySquare;
    delete this->leftKeySquare;
    delete this->background;
    delete this->gameKeybinds;
    delete this->menuNavigationText;
    delete this->navigationText;
}

