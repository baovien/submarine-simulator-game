#include <cstring>
#include "../../Header Files/States/stateGameMode1.h"
#include "../../Header Files/States/stateMainMenu.h"

void stateGameMode1::initialize(sf::RenderWindow *window) {

    memset(machine.keyPressed, 0, sizeof(machine.keyPressed)); //For at tastetrykk gjort i andre states ikke skal beholdes

    this->bgTexture = new sf::Texture();
    this->bgTexture->loadFromFile("Graphics/Sprites/bg_purple.png");

    this->background = new sf::Sprite();
    this->background->setTexture(*this->bgTexture);
    this->background->scale(1.5,1.5);

    util = new Utilities;
    this->manager.addEntity("ship", new Player(&this->manager, window->getSize().x /2, window->getSize().y/2));

    this->font = new sf::Font();
    this->font->loadFromFile("Graphics/font.ttf");

    this->lives = new PlayerLives(*font, 32U);
    this->lives->setPosition(window->getSize().x - this->lives->getGlobalBounds().width, 0);


    this->pausedText = new sf::Text("Paused\nPress Escape to Quit", *font, 32U);
    this->pausedText->setOrigin(this->pausedText->getGlobalBounds().width / 2, this->pausedText->getGlobalBounds().height / 2);
    this->pausedText->setPosition(window->getSize().x / 2, window->getSize().y / 2);
}

void stateGameMode1::update(sf::RenderWindow *window)
{
    if (!util->paused) //Stopper spillet fra å oppdateres når det pauses
    {
        this->manager.updateEntity(window);
    }
    else if(machine.keyPressed[sf::Keyboard::Escape])
        machine.setState(new stateMainMenu());

    if (machine.keyPressed[sf::Keyboard::P])
    {
        memset(machine.keyPressed, 0, sizeof(machine.keyPressed));
        util->pauseScreen();                        //Kaller pausefunksjonen
    }
}

void stateGameMode1::render(sf::RenderWindow *window)
{
    window->draw(*this->background);
    window->draw(*this->lives);
    this->manager.renderEntity(window);


    if (util->paused)
    {
        window->draw(*this->pausedText);
    }
}

void stateGameMode1::destroy(sf::RenderWindow *window) {
    delete this->util;
    delete this->pausedText;
    delete this->font;
    delete this->background;
    delete this->lives;
}