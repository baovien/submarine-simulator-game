#include "../../Include/States/stateGameMode1.h"
#include "../../Include/States/stateMainMenu.h"
#include "../../Include/States/stateGameOver.h"

void StateGameMode1::initialize(sf::RenderWindow *window) {
    //TODO:
//    machine.soundLoaderPointer->playSound(machine.soundLoaderPointer->SHOOT);
    sf::View newView(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
    window->setView(newView);

    this->manager = new EntityManager();
    this->util = new Utilities;

    this->bgTexture = new sf::Texture();
    this->bgTexture->loadFromFile("Graphics/Sprites/bakgrunn.png");
    this->background = new sf::Sprite();

    this->background->setTexture(*this->bgTexture);
    this->background->scale(window->getSize().x / background->getGlobalBounds().width, window->getSize().y / background->getGlobalBounds().height);
    this->font = new sf::Font();
    this->font->loadFromFile("Graphics/font.ttf");

    this->waveText = new sf::Text("Wave ", *this->font, 75);
    this->waveText->setOrigin(this->waveText->getGlobalBounds().width / 2, this->waveText->getGlobalBounds().height / 2);
    this->waveText->setPosition(window->getSize().x / 2, window->getSize().y / 4);
    this->waveText->setFillColor(sf::Color(255, 255, 255, (sf::Uint8) transparencyValue));

    this->score = new Score(*font, 32U);
    this->score->setPosition(window->getSize().x/10,window->getSize().y/20);

    this->lives = new Lives(*font, 32U);
    this->lives->setPosition(window->getSize().x - window->getSize().x/5, window->getSize().y/20);

    //Init player
    this->player = new Player(machine.keybindMap, this->lives, this->score, this->manager, window->getSize().x / 2, window->getSize().y / 2, window, 1, 2, machine.soundLoaderPointer);
    this->manager->addEntity("ship", this->player);

    this->overBar.loadFromFile("Graphics/Sprites/overheat_border.png");
    this->overBarS.setTexture(this->overBar);
    this->overBarS.setOrigin(this->overBarS.getGlobalBounds().width/2, this->overBarS.getGlobalBounds().height/2);
    this->overBarS.setPosition(window->getSize().x/2, window->getSize().y - this->overBarS.getGlobalBounds().height);
    this->overBarS.setScale(2,2);

    //Init pauseobjekter
    this->pausedText = new sf::Text("Paused\nPress " + machine.keybindMap.find("back")->second.first + " to Quit", *font, 32U);
    this->pausedText->setOrigin(this->pausedText->getGlobalBounds().width / 2, this->pausedText->getGlobalBounds().height / 2);
    this->pausedText->setPosition(window->getSize().x / 2, window->getSize().y / 2);

    this->pausedTexture = new sf::Texture();
    this->pausedTexture->loadFromFile("Graphics/Sprites/overlayPause.png");

    this->pausedBackground = new sf::Sprite();
    this->pausedBackground->setTexture(*this->pausedTexture);
    this->pausedBackground->setOrigin(this->pausedBackground->getGlobalBounds().width / 2, this->pausedBackground->getGlobalBounds().height / 2);
    this->pausedBackground->setPosition(window->getSize().x / 2, window->getSize().y / 2);
}

void StateGameMode1::update(sf::RenderWindow *window) {
    if (!util->paused) //Stopper spillet fra å oppdateres når det pauses
    {

        //Når playerliv blir 0, kommer gameOver splashscreen
        if (this->lives->getValue() <= 0) {
            machine.setGameOverScore(this->score->getValue());
            machine.setState(new StateGameOver);
            return;
        }
        this->manager->updateEntity(window);
        this->score->updateScore();
        this->lives->updateLife();

        //Legger til healthpacks + indestructableObjects utenfor wavessystemet
        this->pauseableClockIndestructableObject.start();
        this->pauseableClockHealthPack.start();

        if (this->pauseableClockIndestructableObject.getElapsedTime().asMicroseconds() > 5000000)   //Sjekker om verdien til clock er mer enn 5 sekunder
        {
            this->manager->addEntity("indestructableObject", new IndestructableObject());   //er clock mer enn 5 sekunder lager jeg en ny astroide
            this->pauseableClockIndestructableObject.restart();                             //restarter clock(nullstiller)
        }

        if (pauseableClockHealthPack.getElapsedTime().asMicroseconds() > 5000000) {         //Sjekker om verdien til clock er mer enn 5 sekunder
            if (rand() % 10 < 3) {                                          //Sjekker om rand() % 10 er mindre enn 3, hvis ikke - så spawnes det ikke healthpack
                healthPack = new HealthPack(this->lives, machine.soundLoaderPointer);
                this->manager->addEntity("healthPack", healthPack);
            }
            pauseableClockHealthPack.restart();     //restarter clock(nullstiller)
        }

        //////////////////////////WAVES
        name = "Enemy";
        int enemiesLeft = 0;
        if(waveNum >= 5) this->mode = 2;
        if(!inWave)
        {
            for (int i = 0; i < 2*waveNum; ++i)
            {
                this->manager->addEntity("Enemy", new EnemyObject(window, this->player, this->manager, this->mode, machine.soundLoaderPointer));

                /*
                //Init boss
                this->bossObject = new BossObject(this->manager, this->player, this->mode);
                this->manager->addEntity("Enemy", this->bossObject);
                 */
                enemyCount++;
            }
            std::cout << "InWave enemies: " << enemyCount << std::endl;
            inWave = true;
        }

        //Teller enemies som er igjen
        for (int j = 0; j < enemyCount; ++j)
        {
            if (j != 0){
                name += "0";
            }

            if(this->manager->getEntity(name) != NULL){
                enemiesLeft++;
            }
        }

        //Wave done
        if(enemiesLeft == 0 || waveNum == 0)
        {
            waveNum++;
            this->transparencyValue = 255;
            this->waveText->setString("Wave " + std::to_string(this->waveNum));
            this->waveText->setOrigin(this->waveText->getGlobalBounds().width / 2, this->waveText->getGlobalBounds().height / 2);
            inWave = false;
            std::cout << "WAVE DONE" << std::endl;
        }

        //Fader waveText
        this->waveText->setFillColor(sf::Color(255, 255, 255, (sf::Uint8) transparencyValue));
        if(transparencyValue > 1) transparencyValue -= 1;
        //////////////////////////END_WAVES

    }else{ //Handle paused game
        this->pauseableClockIndestructableObject.pause();
        this->pauseableClockHealthPack.pause();
        //this->bossObject->pauseableClock.pause();
    }

}

void StateGameMode1::render(sf::RenderWindow *window) {
    window->draw(*this->background);
    this->manager->renderEntity(window);
    window->draw(*this->score);
    window->draw(*this->lives);
    window->draw(this->overBarS);

    if (util->paused) {
        window->draw(*this->pausedBackground);
        window->draw(*this->pausedText);
    }
    window->draw(*this->waveText);

}

void StateGameMode1::destroy(sf::RenderWindow *window) {
    delete this->lives;
    delete this->score;
    delete this->util;
    delete this->pausedText;
    delete this->waveText;
    delete this->font;
    delete this->pausedBackground;
    delete this->background;
    delete this->manager;

}

void StateGameMode1::handleEvent(sf::RenderWindow *window, sf::Event event) {
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

void StateGameMode1::reinitialize(sf::RenderWindow *window) {}
