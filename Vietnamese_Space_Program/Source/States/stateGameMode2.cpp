#include <cstring>
#include "../../Include/States/stateGameMode2.h"
#include "../../Include/States/stateMainMenu.h"

void StateGameMode2::initialize(sf::RenderWindow *window) {

    sf::View newView(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
    window->setView(newView);

    this->bgTexture = new sf::Texture();
    this->bgTexture->loadFromFile("Graphics/Sprites/bg_purple.png");

    this->background = new sf::Sprite();
    this->background->setTexture(*this->bgTexture);
    this->background->scale(1.5, 1.5);

    util = new Utilities();

    manager = new EntityManager();
    this->player =  new Player(this->lives, this->score, this->manager, window->getSize().x/2, window->getSize().y, window, 2);
    this->manager->addEntity("ship", this->player);

    this->font = new sf::Font();
    this->font->loadFromFile("Graphics/font.ttf");

    this->pausedText = new sf::Text("Paused\nPress " + machine.keybindMap.find("back")->second.first + " to Quit", *font, 32U);
    this->pausedText->setOrigin(this->pausedText->getGlobalBounds().width / 2, this->pausedText->getGlobalBounds().height / 2);
    this->pausedText->setPosition(window->getSize().x / 2, window->getSize().y / 2);
}

void StateGameMode2::update(sf::RenderWindow *window) {

    if (!util->paused) //Stopper spillet fra å oppdateres når det pauses
    {
        this->manager->updateEntity(window);

    }
}
void StateGameMode2::render(sf::RenderWindow *window){
    window->draw(*this->background);
    this->manager->renderEntity(window);
    if (util->paused)
    {
        window->draw(*this->pausedText);
    }
}

void StateGameMode2::destroy(sf::RenderWindow *window) {
    delete this->util;
    delete this->font;
    delete this->pausedText;
    delete this->background;
}

void StateGameMode2::handleEvent(sf::RenderWindow *window, sf::Event event) {
    if (event.type == event.KeyPressed) {
        if (event.key.code == machine.keybindMap.find("back")->second.second && util->paused) {
            machine.setState(new StateMainMenu());
            return;
        }
        if (event.key.code == machine.keybindMap.find("pause")->second.second) {
            util->pauseScreen();                        //Kaller pausefunksjonen
        }
    }
}

void StateGameMode2::reinitialize(sf::RenderWindow *window) {

}
