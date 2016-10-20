#include "../../Header Files/States/gamemode1.h"
#include "../../Header Files/States/menu.h"

void gamemode1::Initialize(sf::RenderWindow *window) {
    util = new Utilities;
    this->bullet = new bulletObject;
    this->enemy1 = new enemyObject;
    this->enemy1->setPosition(rand()%1920, rand()%1080);


    this->font = new sf::Font();
    this->font->loadFromFile("Graphics/font.ttf");

    this->player1 = new playerObject(0);
    this->player1->setPosition(500, 500);
    this->player1->setOrigin(this->player1->getGlobalBounds().width / 2, this->player1->getGlobalBounds().height / 2);
    this->enemy1->setPosition(rand()%1920, rand()%1080);

    this->pausedText = new sf::Text("Paused\nPress Escape to Quit", *font, 32U);
    this->pausedText->setOrigin(this->pausedText->getGlobalBounds().width / 2, this->pausedText->getGlobalBounds().height / 2);
    this->pausedText->setPosition(window->getSize().x / 2, window->getSize().y / 2);
}

void gamemode1::Update(sf::RenderWindow* window)
{
    this->player1->Update();
    this->enemy1->UpdateEnemy(window);
    this->enemy1->Reset(window);

    if (util->paused && (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)))
    {   //Hvis spillet er pauset og escape trykkes går man til menyen
        coreState.SetState(new main_menu());
    }
    if (!util->paused)
    {                                                //Stopper spillet fra å oppdateres når det pauses
        this->player1->Update();
        this->bullet->Updatebullet();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
    {
        util->pauseScreen();                                                      //Kaller pausefunksjonen
    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P) && util->pReleased == false)
    { //Sjekker når P slippes, slik at man ikke toggler pause når man holder P inne
        util->pReleased = true;
    }
}

void gamemode1::Render(sf::RenderWindow *window) {
    window->draw(*this->bullet);
    window->draw(*this->player1);
    window->draw(*this->enemy1);

    if (util->paused)
    {
        window->draw(*this->pausedText);
    }
}

void gamemode1::Destroy(sf::RenderWindow *window) {
    delete this->bullet;
    delete this->player1;
    delete this->enemy1;
}