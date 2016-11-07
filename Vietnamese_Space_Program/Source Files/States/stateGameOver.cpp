#include "../../Header Files/States/stateGameOver.h"
#include "../../Header Files/States/stateGameMode1.h"
#include "../../Header Files/States/stateMainMenu.h"

#include <cstring>
#include <iostream>

/**
 * Init settingsState.
 * @param window
 */
void stateGameOver::initialize(sf::RenderWindow *window) {

    memset(machine.keyPressed, 0, sizeof(machine.keyPressed)); //For at tastetrykk gjort i andre states ikke skal beholdes

    this->selected = 1;

    this->bgTexture = new sf::Texture();
    this->bgTexture->loadFromFile("Graphics/Sprites/bg_purple.png");

    this->font = new sf::Font();
    this->font->loadFromFile("Graphics/font1.otf");

    this->score = new Score(*font, 32U);
    this->score->setOrigin(this->score->getGlobalBounds().width/2, this->score->getGlobalBounds().height/2);
    this->score->setPosition(window->getSize().x/2, window->getSize().y/2);

    this->background = new sf::Sprite();
    this->background->setTexture(*this->bgTexture);
    this->background->setOrigin(this->background->getGlobalBounds().width / 2, this->background->getGlobalBounds().height / 2);
    this->background->scale(window->getSize().x/background->getGlobalBounds().width/2,window->getSize().y/background->getGlobalBounds().height/2);
    this->background->setPosition(window->getSize().x/2, window->getSize().y/2);

    this->gameOverText = new sf::Text("Game Over", *this->font, 25);
    this->gameOverText->setOrigin(this->gameOverText->getGlobalBounds().width / 2, this->gameOverText->getGlobalBounds().height / 2);
    this->gameOverText->setPosition(window->getSize().x / 2 , (window->getSize().y / 2) - this->background->getGlobalBounds().height/2.25);

    this->menuText = new sf::Text("Back to menu", *this->font, 25);
    this->menuText->setOrigin(this->menuText->getGlobalBounds().width / 2, this->gameOverText->getGlobalBounds().height / 2);
    this->menuText->setPosition(window->getSize().x/2.5, window->getSize().y/1.5);

    this->restartText = new sf::Text("Restart", *this->font, 25);
    this->restartText->setOrigin(this->menuText->getGlobalBounds().width / 2, this->gameOverText->getGlobalBounds().height / 2);
    this->restartText->setPosition(window->getSize().x/1.5, window->getSize().y/1.5);

}
/**
 * Update on keyevent, navigation through settings
 * @param window
 */
void stateGameOver::update(sf::RenderWindow *window) {

    if(machine.keyPressed[sf::Keyboard::Left]){
        memset(machine.keyPressed, 0, sizeof(machine.keyPressed));
        this->selected += 1;
    }

    if(machine.keyPressed[sf::Keyboard::Right]){
        memset(machine.keyPressed, 0, sizeof(machine.keyPressed));
        this->selected -= 1;
    }

    if(this->selected > 1){
        this->selected = 0;
    }

    if(this->selected < 0){
        this->selected = 1;
    }

    if(machine.keyPressed[sf::Keyboard::Return]){
        memset(machine.keyPressed, 0, sizeof(machine.keyPressed));
        switch(this->selected){
            case 0: //Back
                machine.setState(new stateMainMenu);
                break;

            case 1: //Restart
                machine.setState(new stateGameMode1);
                break;

        }
    }
}
/**
 *
 * @param window
 */
void stateGameOver::render(sf::RenderWindow *window) {
    this->gameOverText->setFillColor(sf::Color::White);
    this->menuText->setFillColor(sf::Color::White);
    this->restartText->setFillColor(sf::Color::White);
    this->score->setFillColor(sf::Color::White);

    this->menuText->setStyle(0);
    this->restartText->setStyle(0);

    switch(selected){

        case 0: // Back to menu
            this->menuText->setStyle(1<<3);
            break;

        case 1: // Restart
            this->restartText->setStyle(1<<3);
            break;
    }

    window->draw(*this->background);
    window->draw(*this->score);
    window->draw(*this->gameOverText);
    window->draw(*this->menuText);
    window->draw(*this->restartText);
}

void stateGameOver::destroy(sf::RenderWindow *window) {

    delete this->gameOverText;
    delete this->menuText;
    delete this->restartText;
    delete this->score;
    delete this->background;
}
