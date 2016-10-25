#include "../../Header Files/States/Gamemode1.h"
#include "../../Header Files/States/menu.h"

void Gamemode1::initialize(sf::RenderWindow *window) {

    util = new Utilities;
    this->enemy1 = new EnemyObject;
    this->enemy1->setPosition(rand()%window->getSize().x, rand()%window->getSize().x);

    this->font = new sf::Font();
    this->font->loadFromFile("Graphics/font.ttf");

    this->player1 = new PlayerObject(0);
    this->player1->setPosition(window->getPosition().x/2, window->getPosition().y/2);
    this->player1->setOrigin(this->player1->getGlobalBounds().width / 2, this->player1->getGlobalBounds().height / 2);
    this->bullet1 = new Bullet;
    this->bullet1->setPosition(player1->getPosition().x, player1->getPosition().y - player1->getGlobalBounds().height / 2);
    this->bullet1->setOrigin(this->bullet1->getGlobalBounds().width / 2, this->bullet1->getGlobalBounds().height / 2);

    this->enemy1->setPosition(rand()%1920, rand()%1080);

    this->pausedText = new sf::Text("Paused\nPress Escape to Quit", *font, 32U);
    this->pausedText->setOrigin(this->pausedText->getGlobalBounds().width / 2, this->pausedText->getGlobalBounds().height / 2);
    this->pausedText->setPosition(window->getSize().x / 2, window->getSize().y / 2);
}

void Gamemode1::update(sf::RenderWindow *window)
{
    if (util->paused && (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)))
    {   //Hvis spillet er pauset og escape trykkes går man til menyen
        coreState.setState(new MainMenu());
    }
    if (!util->paused) //Stopper spillet fra å oppdateres når det pauses
    {
        this->player1->update();
        this->bullet1->bulletUpdate(player1->getPosition().x, player1->getPosition().y - player1->getGlobalBounds().height / 2);
        this->enemy1->updateEnemy(window);
        this->enemy1->reset(window);

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
    {
        util->pauseScreen();                        //Kaller pausefunksjonen
    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P) && util->pReleased == false)
    { //Sjekker når P slippes, slik at man ikke toggler pause når man holder P inne
        util->pReleased = true;
    }
}

void Gamemode1::render(sf::RenderWindow *window) {
    window->draw(*this->bullet1);
    window->draw(*this->player1);
    window->draw(*this->enemy1);

    if (util->paused)
    {
        window->draw(*this->pausedText);
    }
}

void Gamemode1::destroy(sf::RenderWindow *window) {
    delete this->bullet1;
    delete this->player1;
    delete this->enemy1;
}