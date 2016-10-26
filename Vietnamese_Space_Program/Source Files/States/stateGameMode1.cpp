#include <cstring>
#include "../../Header Files/States/stateGameMode1.h"
#include "../../Header Files/States/stateMainMenu.h"

void stateGameMode1::initialize(sf::RenderWindow *window) {

    memset(machine.keyPressed, 0, sizeof(machine.keyPressed)); //For at tastetrykk gjort i andre states ikke skal beholdes

    util = new Utilities;
    this->enemy1 = new EnemyObject;
    this->enemy1->setPosition(rand()%window->getSize().x, rand()%window->getSize().x);

    this->font = new sf::Font();
    this->font->loadFromFile("Graphics/font.ttf");

    this->player1 = new PlayerObject(0);
    this->player1->setPosition(window->getPosition().x/2, window->getPosition().y/2);
    this->player1->setOrigin(this->player1->getGlobalBounds().width / 2, this->player1->getGlobalBounds().height / 2);
    this->bullet1 = new bullet;
    this->bullet1->setPosition(player1->getPosition().x, player1->getPosition().y - player1->getGlobalBounds().height / 2);
    this->bullet1->setOrigin(this->bullet1->getGlobalBounds().width / 2, this->bullet1->getGlobalBounds().height / 2);

    this->enemy1->setPosition(rand()%1920, rand()%1080);

    this->pausedText = new sf::Text("Paused\nPress Escape to Quit", *font, 32U);
    this->pausedText->setOrigin(this->pausedText->getGlobalBounds().width / 2, this->pausedText->getGlobalBounds().height / 2);
    this->pausedText->setPosition(window->getSize().x / 2, window->getSize().y / 2);
}

void stateGameMode1::update(sf::RenderWindow *window)
{
    if (!util->paused) //Stopper spillet fra å oppdateres når det pauses
    {
        this->player1->update();
        this->bullet1->bulletUpdate(player1->getPosition().x, player1->getPosition().y - player1->getGlobalBounds().height / 2);
        this->enemy1->updateEnemy(window);
        this->enemy1->reset(window);

    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        machine.setState(new stateMainMenu());


    if (machine.keyPressed[sf::Keyboard::P])
    {
        memset(machine.keyPressed, 0, sizeof(machine.keyPressed));
        util->pauseScreen();                        //Kaller pausefunksjonen
    }
}

void stateGameMode1::render(sf::RenderWindow *window) {
    window->draw(*this->bullet1);
    window->draw(*this->player1);
    window->draw(*this->enemy1);

    if (util->paused)
    {
        window->draw(*this->pausedText);
    }
}

void stateGameMode1::destroy(sf::RenderWindow *window) {
    delete this->bullet1;
    delete this->player1;
    delete this->enemy1;
}