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

    this->keySquare = new sf::Sprite();
    this->keySquare->setTexture(*this->ballTexture);
    this->keySquare->setOrigin(this->keySquare->getGlobalBounds().width / 2, this->keySquare->getGlobalBounds().height / 2);
    this->keySquare->scale(window->getSize().x/background->getGlobalBounds().width/15,window->getSize().x/background->getGlobalBounds().width/15);
    this->keySquare->setPosition(((window->getSize().x / 2) - this->background->getGlobalBounds().width/4) , (window->getSize().y / 2) - this->background->getGlobalBounds().height/5);

    this->font = new sf::Font();
    this->font->loadFromFile("Graphics/font1.otf");

    this->gameKeybinds = new sf::Text("Game", *this->font, textSize);
    this->gameKeybinds->setOrigin(this->gameKeybinds->getGlobalBounds().width / 2, this->gameKeybinds->getGlobalBounds().height / 2);
    this->gameKeybinds->setPosition(((window->getSize().x / 2) - this->background->getGlobalBounds().width/4) , (window->getSize().y / 2) - this->background->getGlobalBounds().height/2.25);

    this->menuKeybinds = new sf::Text("Menu", *this->font, textSize);
    this->menuKeybinds->setOrigin(this->menuKeybinds->getGlobalBounds().width / 2, this->gameKeybinds->getGlobalBounds().height / 2);
    this->menuKeybinds->setPosition(((window->getSize().x / 2) + this->background->getGlobalBounds().width/4) , (window->getSize().y / 2) - this->background->getGlobalBounds().height/2.25);

    this->movementText = new sf::Text("movement", *this->font, 20U);
    this->movementText->setOrigin(this->movementText->getGlobalBounds().width / 2, this->gameKeybinds->getGlobalBounds().height / 2);
    this->movementText->setPosition(((window->getSize().x / 2) - this->background->getGlobalBounds().width/4) , (window->getSize().y / 2) - this->background->getGlobalBounds().height/3);

    this->navigationText = new sf::Text("navigation", *this->font, 20U);
    this->navigationText->setOrigin(this->navigationText->getGlobalBounds().width / 2, this->gameKeybinds->getGlobalBounds().height / 2);
    this->navigationText->setPosition(((window->getSize().x / 2) + this->background->getGlobalBounds().width/4) , (window->getSize().y / 2) - this->background->getGlobalBounds().height/3);

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
    window->draw(*this->keySquare);
    window->draw(*this->gameKeybinds);
    window->draw(*this->menuKeybinds);
    window->draw(*this->movementText);
    window->draw(*this->navigationText);
}

void stateKeybindings::destroy(sf::RenderWindow *window) {
    delete this->bgTexture;
    delete this->keySquare;
    delete this->background;
    delete this->gameKeybinds;
    delete this->menuKeybinds;
    delete this->movementText;
    delete this->navigationText;
}

