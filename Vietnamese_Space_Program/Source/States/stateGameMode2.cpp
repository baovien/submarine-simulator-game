#include <cstring>
#include "../../Include/States/stateGameMode2.h"
#include "../../Include/States/stateMainMenu.h"
#include "../../Include/States/stateGameOver.h"

void StateGameMode2::initialize(sf::RenderWindow *window) {

    this->manager = new EntityManager();

    sf::View newView(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
    window->setView(newView);

    machine.soundLoaderPointer->stopMusic();
    machine.soundLoaderPointer->playMusic(Audio::Music::CLASSIC);

    this->bgTexture = new sf::Texture();
    this->bgTexture->loadFromFile("Graphics/Sprites/bg_purple.png");

    this->background = new sf::Sprite();
    this->background->setTexture(*this->bgTexture);
    this->background->scale(1.5, 1.5);

    util = new Utilities();

    this->font = new sf::Font();
    this->font->loadFromFile("Graphics/font.ttf");

    this->score = new Score(*font, 32U);
    this->score->setPosition(20, 5);

    this->lives = new Lives(*font, 32U);
    this->lives->setPosition(window->getSize().x - this->lives->getGlobalBounds().width - 20, 5);

    manager = new EntityManager();
    this->player = new Player(machine.keybindMap, this->lives, this->score, this->manager, window->getSize().x / 2, window->getSize().y, window, 2, 2, machine.soundLoaderPointer);
    this->manager->addEntity("ship", this->player);


    this->pausedText = new sf::Text("Paused\nPress " + machine.keybindMap.find("back")->second.first + " to Quit", *font, 32U);
    this->pausedText->setOrigin(this->pausedText->getGlobalBounds().width / 2,
                                this->pausedText->getGlobalBounds().height / 2);
    this->pausedText->setPosition(window->getSize().x / 2, window->getSize().y / 2);


}

void StateGameMode2::update(sf::RenderWindow *window) {
    machine.soundLoaderPointer->checkMuteMusic();

    if (!util->paused) //Stopper spillet fra å oppdateres når det pauses
    {
        this->manager->updateEntity(window, machine.deltaTimePointer);
        this->score->updateScore(util->translate("Score", machine.settingPointer->selectedLanguage));
        this->lives->updateLife(util->translate("Lives", machine.settingPointer->selectedLanguage));
        if (this->lives->getValue() <= 0) {
            machine.setGameOverScore(this->score->getValue());
            machine.setState(new StateGameOver);
            return;
    }

        if (spawna) {
            for (int i = 0; i < 15; ++i) {

                for (int j = 0; j < 5; ++j) {
                    //enemies[i,j];
                    enemy2Object = new Enemy2Object(manager,i, j, window);
                    this->manager->addEntity("Enemy", enemy2Object);
                }

            }
            spawna = false;

        }
        if (!rightCollision) {
            std::string name = "Enemy";
            for (int j = 0; j < 15 * 5; ++j) {
                if (j != 0) {
                    name += "0";
                }
                if (this->manager->getEntity(name) != NULL) {
                    if (this->manager->getEntity(name)->getPosition().x > window->getSize().x) {
                        rightCollision = true;
                        leftCollision = false;
                        std::string name = "Enemy";
                        for (int j = 0; j < 15 * 5; ++j) {
                            if (j != 0) {
                                name += "0";
                            }
                            Entity* entity = this->manager->getEntity(name);
                            if (entity != nullptr)
                            {
                                entity->velocity.x = -5;
                                entity->setPosition(entity->getPosition().x, entity->getPosition().y + entity->getGlobalBounds().height);
                            }
                        }
                        break;
                    }
                }
            }
        }
        if (!leftCollision) {
            std::string name = "Enemy";
            for (int j = 0; j < 15 * 5; ++j) {
                if (j != 0) {
                    name += "0";
                }

                if (this->manager->getEntity(name) != NULL) {
                    if (this->manager->getEntity(name)->getPosition().x < 0) {
                        rightCollision = false;
                        leftCollision = true;
                        std::string name = "Enemy";
                        for (int j = 0; j < 15 * 5; ++j) {
                            if (j != 0) {
                                name += "0";
                            }
                            Entity* entity = this->manager->getEntity(name);
                            if (entity != nullptr)
                            {
                                entity->velocity.x = 5;
                                entity->setPosition(entity->getPosition().x, entity->getPosition().y + entity->getGlobalBounds().height);
                            }
                        }
                        break;
                    }


                }
            }
        }
    }
}

void StateGameMode2::render(sf::RenderWindow *window) {
    window->draw(*this->background);
    window->draw(*this->score);
    window->draw(*this->lives);

    this->manager->renderEntity(window);
    if (util->paused) {
        window->draw(*this->pausedText);


    }
}

void StateGameMode2::destroy(sf::RenderWindow *window) {

    delete this->lives;
    delete this->score;
    delete this->util;
    delete this->font;
    delete this->pausedText;
    delete this->background;
    delete this->manager;
    delete this->bgTexture;

}

void StateGameMode2::handleEvent(sf::RenderWindow *window, sf::Event event){
    if (event.type == event.KeyPressed) {
        if (event.key.code == machine.keybindMap.find("back")->second.second && util->paused) {
            machine.soundLoaderPointer->stopMusic();
            machine.setState(new StateMainMenu());
            return;
        }
        if (event.key.code == machine.keybindMap.find("pause")->second.second) {
            util->pauseScreen();                        //Kaller pausefunksjonen
        }
    }
}

void StateGameMode2::reinitialize(sf::RenderWindow *window){

}