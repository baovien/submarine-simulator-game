#include <cstring>
#include "../../Header Files/States/stateGameMode1.h"
#include "../../Header Files/States/stateMainMenu.h"
#include "../../Header Files/States/stateGameOver.h"

void stateGameMode1::initialize(sf::RenderWindow *window) {

    memset(machine.keyPressed, 0, sizeof(machine.keyPressed)); //For at tastetrykk gjort i andre states ikke skal beholdes

    this->bgTexture = new sf::Texture();
    this->bgTexture->loadFromFile("Graphics/Sprites/bg_purple.png");

    this->background = new sf::Sprite();
    this->background->setTexture(*this->bgTexture);
    this->background->scale(window->getSize().x/background->getGlobalBounds().width,window->getSize().y/background->getGlobalBounds().height);

    util = new Utilities;
    this->font = new sf::Font();
    this->font->loadFromFile("Graphics/font.ttf");

    this->score = new Score(*font, 32U);
    this->score->setPosition(20, 5);

    this->lives = new Lives(*font, 32U);
    this->lives->setPosition(window->getSize().x - this->lives->getGlobalBounds().width - 20, 5);

    manager = new EntityManager();
    this->manager->addEntity("ship", new Player(this->lives, this->score, this->manager, window->getSize().x /2, window->getSize().y/2));

    this->pausedText = new sf::Text("Paused\nPress Escape to Quit", *font, 32U);
    this->pausedText->setOrigin(this->pausedText->getGlobalBounds().width / 2, this->pausedText->getGlobalBounds().height / 2);
    this->pausedText->setPosition(window->getSize().x / 2, window->getSize().y / 2);
}

void stateGameMode1::update(sf::RenderWindow *window)
{
    if (!util->paused) //Stopper spillet fra å oppdateres når det pauses
    {
        this->manager->updateEntity(window);
        this->score->updateScore();
        this->lives->updateLife();
    }
    else if(machine.keyPressed[sf::Keyboard::Escape])
        machine.setState(new stateMainMenu());

    if (machine.keyPressed[sf::Keyboard::P])
    {
        memset(machine.keyPressed, 0, sizeof(machine.keyPressed));
        util->pauseScreen();                        //Kaller pausefunksjonen
    }

    if(this->lives->getValue() <= 0){
        machine.setState(new stateGameOver);

    }

    //Spawn enemies and asteroids randomly
    if(rand() % 1000 < 20){
        this->manager->addEntity("enemy", new EnemyObject(32,32));
    }
    if(rand() % 1000 < 20){
        this->manager->addEntity("asteroid", new AsteroidObject(32,32));

    }

}

void stateGameMode1::render(sf::RenderWindow *window)
{
    window->draw(*this->background);
    window->draw(*this->score);
    window->draw(*this->lives);
    this->manager->renderEntity(window);

    if (util->paused)
    {
        window->draw(*this->pausedText);
    }
}

void stateGameMode1::destroy(sf::RenderWindow *window)
{
    delete this->lives;
    delete this->score;
    delete this->util;
    delete this->pausedText;
    delete this->font;
    delete this->background;
    delete this->manager;
}