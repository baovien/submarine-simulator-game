#include "../../Include/States/stateGameOver.h"
#include "../../Include/States/stateGameMode1.h"
#include "../../Include/States/stateMainMenu.h"

#include <cstring>

/**
 * Init settingsState.
 * @param window
 */
void StateGameOver::initialize(sf::RenderWindow *window) {

    sf::View newView(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
    window->setView(newView);

    this->selected = 1;

    this->bgTexture = new sf::Texture();
    this->bgTexture->loadFromFile("Graphics/Sprites/bg_purple.png");

    this->font = new sf::Font();
    this->font->loadFromFile("Graphics/font1.otf");

    this->background = new sf::Sprite();
    this->background->setTexture(*this->bgTexture);
    this->background->setOrigin(this->background->getGlobalBounds().width / 2, this->background->getGlobalBounds().height / 2);
    this->background->scale(window->getSize().x / background->getGlobalBounds().width / 2, window->getSize().y / background->getGlobalBounds().height / 2);
    this->background->setPosition(window->getSize().x / 2, window->getSize().y / 2);

    this->score = new sf::Text("Score: " + std::to_string(machine.getGameOverScore()), *font, 25);
    this->score->setOrigin(this->score->getGlobalBounds().width / 2, this->score->getGlobalBounds().height / 2);
    this->score->setPosition(window->getSize().x / 2, window->getSize().y / 2);

    this->gameOverText = new sf::Text("Game Over", *this->font, 25);
    this->gameOverText->setOrigin(this->gameOverText->getGlobalBounds().width / 2, this->gameOverText->getGlobalBounds().height / 2);
    this->gameOverText->setPosition(window->getSize().x / 2, (window->getSize().y / 2) - this->background->getGlobalBounds().height / 2.25);

    this->menuText = new sf::Text("Back to menu", *this->font, 25);
    this->menuText->setOrigin(this->menuText->getGlobalBounds().width / 2, this->gameOverText->getGlobalBounds().height / 2);
    this->menuText->setPosition(window->getSize().x / 2.5, window->getSize().y / 1.5);

    this->restartText = new sf::Text("Restart", *this->font, 25);
    this->restartText->setOrigin(this->menuText->getGlobalBounds().width / 2, this->gameOverText->getGlobalBounds().height / 2);
    this->restartText->setPosition(window->getSize().x / 1.5, window->getSize().y / 1.5);

}

/**
 * Update on keyevent, navigation through settings
 * @param window
 */
void StateGameOver::update(sf::RenderWindow *window) {
    if (this->selected > 1) {
        this->selected = 0;
    }

    if (this->selected < 0) {
        this->selected = 1;
    }
}

/**
 *
 * @param window
 */
void StateGameOver::render(sf::RenderWindow *window) {
    this->gameOverText->setFillColor(sf::Color::White);
    this->menuText->setFillColor(sf::Color::White);
    this->restartText->setFillColor(sf::Color::White);
    this->score->setFillColor(sf::Color::White);

    this->menuText->setStyle(0);
    this->restartText->setStyle(0);

    switch (selected) {

        case 0: // Back to menu
            this->menuText->setStyle(1 << 3);
            break;

        case 1: // Restart
            this->restartText->setStyle(1 << 3);
            break;
    }

    window->draw(*this->background);
    window->draw(*this->score);
    window->draw(*this->gameOverText);
    window->draw(*this->menuText);
    window->draw(*this->restartText);
}

void StateGameOver::destroy(sf::RenderWindow *window) {

    delete this->gameOverText;
    delete this->menuText;
    delete this->restartText;
    delete this->score;
    delete this->background;
}

void StateGameOver::handleEvent(sf::RenderWindow *window, sf::Event event) {
    if (event.type == event.KeyPressed) {
        if (event.key.code == sf::Keyboard::Left) {
            this->selected += 1;
        }

        if (event.key.code == sf::Keyboard::Right) {
            this->selected -= 1;
        }
        if (event.key.code == machine.keybindMap.find("select")->second.second) {
            switch (this->selected) {
                case 0: //Back
                    machine.setState(new StateMainMenu);
                    break;

                case 1: //Restart
                    machine.setState(new StateGameMode1);
                    break;

            }
        }
    }
}

void StateGameOver::reinitialize(sf::RenderWindow *window) {

}
