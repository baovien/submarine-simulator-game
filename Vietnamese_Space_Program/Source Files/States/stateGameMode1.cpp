#include <iostream>
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
    this->player =  new Player(this->lives, this->score, this->manager, window->getSize().x /2, window->getSize().y/2);
    this->manager->addEntity("ship", this->player);

    this->pausedText = new sf::Text("Paused\nPress Q to Quit", *font, 32U);
    this->pausedText->setOrigin(this->pausedText->getGlobalBounds().width / 2, this->pausedText->getGlobalBounds().height / 2);
    this->pausedText->setPosition(window->getSize().x / 2, window->getSize().y / 2);

    this->pausedTexture = new sf::Texture();
    this->pausedTexture->loadFromFile("Graphics/Sprites/overlayPause.png");

    this->pausedBackground = new sf::Sprite();
    this->pausedBackground->setTexture(*this->pausedTexture);
    this->pausedBackground->setOrigin(this->pausedBackground->getGlobalBounds().width / 2, this->pausedBackground->getGlobalBounds().height / 2);
    this->pausedBackground->setPosition(window->getSize().x / 2, window->getSize().y / 2);
}

void stateGameMode1::update(sf::RenderWindow *window)
{
    if (!util->paused) //Stopper spillet fra å oppdateres når det pauses
    {
        this->manager->updateEntity(window);
        this->score->updateScore();
        this->lives->updateLife();

        if(this->lives->getValue() <= 0) {
            machine.setState(new stateGameOver);
        }
        //Spawn enemies and asteroids randomly
        sf::Time elapsedAsteroid = clockAsteroid.getElapsedTime(); //Tar her her opp verdien som ligger i klokk
        sf::Time elapsedEnemy = clockEnemy.getElapsedTime();
        sf::Time elapsedHealthPack = clockHealthPack.getElapsedTime();

        if(elapsedEnemy.asMicroseconds() > 5000000) //Sjekker om verdien til clock er mer enn 5 sekunder
        {
            enemyObject = new EnemyObject();
            this->manager->addEntity("enemy", enemyObject);
            this->enemyObject->setEnemy(this->player);
            clockEnemy.restart();
        }

        if(elapsedAsteroid.asMicroseconds() > 3000000) //Sjekker om verdien til clock er mer enn 3 sekunder
        {
            this->manager->addEntity("asteroid", new AsteroidObject(32, 32)); //er clock mer enn 3 sekunder lager jeg en ny astroide
            clockAsteroid.restart(); //restarter clock(nullstiller)
        }

        if(elapsedHealthPack.asMicroseconds() > 5000000) // Hvert 5. sekund sjekkes det om rand()%10 er mindre eller lik 3, hvis ja - så spawnes det en healthpack.
        {
            if(rand()%10 <= 3){
                healthPack = new HealthPack(this->lives);
                this->manager->addEntity("healthPack", healthPack);
                clockHealthPack.restart();
            }
            else{
                clockHealthPack.restart();
            }
        }

    }
    else if(machine.keyPressed[sf::Keyboard::Q])
        machine.setState(new stateMainMenu());

    if (machine.keyPressed[sf::Keyboard::P] || machine.keyPressed[sf::Keyboard::Escape])
    {
        memset(machine.keyPressed, 0, sizeof(machine.keyPressed));
        util->pauseScreen();                        //Kaller pausefunksjonen
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
        window->draw(*this->pausedBackground);
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
    delete this->pausedBackground;
}