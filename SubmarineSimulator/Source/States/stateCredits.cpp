#include "../../Include/States/stateCredits.h"
#include "../../Include/States/stateMainMenu.h"

void StateCredits::initialize(sf::RenderWindow *window) {
    sf::View newView(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
    window->setView(newView);

    this->bgTexture = new sf::Texture();
    this->bgTexture->loadFromFile("Graphics/Sprites/intro.png");

    this->background = new sf::Sprite();
    this->background->setTexture(*this->bgTexture);
    this->background->scale(window->getSize().x / background->getGlobalBounds().width, window->getSize().y / background->getGlobalBounds().height);

    introOver = false;
    transparency = 255;
}

void StateCredits::update(sf::RenderWindow *window) {
    if(clock.getElapsedTime().asSeconds() > 5){
        introOver = true;
        clock.restart();
    }
    if(clock.getElapsedTime().asMilliseconds() > 50 && introOver){
        transparency -= 3;
        background->setColor(sf::Color(255,255,255,transparency));
        clock.restart();
    }

    if(transparency < 3){
        machine.setState(new StateMainMenu);
        return;
    }
}

void StateCredits::render(sf::RenderWindow *window) {
    window->clear(sf::Color::Black);
    window->draw(*this->background);
}

void StateCredits::destroy(sf::RenderWindow *window) {
    delete this->background;
    delete this->bgTexture;
}

void StateCredits::handleEvent(sf::RenderWindow *window, sf::Event event) {
    if(event.type == sf::Event::KeyPressed){
        machine.setState(new StateMainMenu);
        return;
    }
}

void StateCredits::reinitialize(sf::RenderWindow *window) {
    sf::View newView(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
    window->setView(newView);

    this->background->scale(window->getSize().x / background->getGlobalBounds().width, window->getSize().y / background->getGlobalBounds().height);
}
