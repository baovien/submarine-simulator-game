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
    this->bgTexture->loadFromFile("Graphics/Sprites/background12.png");

    this->background = new sf::Sprite();
    this->background->setTexture(*this->bgTexture);
    this->background->scale(window->getSize().x / background->getGlobalBounds().width,
                            window->getSize().y / background->getGlobalBounds().height);

    util = new Utilities();

    this->font = new sf::Font();
    this->font->loadFromFile("Graphics/font.ttf");

    this->score = new Score(*font, 32U);
    this->score->setPosition(window->getSize().x / 40, window->getSize().y / 60);
    this->score->setScale(window->getSize().x / 1280.f, window->getSize().y / 720.f);

    this->lives = new Lives(*font, 32U);
    this->lives->setPosition(window->getSize().x - window->getSize().x / 10, window->getSize().y / 60);
    this->lives->setScale(window->getSize().x / 1280.f, window->getSize().y / 720.f);

    manager = new EntityManager();

    this->player = new Player(machine.keybindMap, this->lives, this->score, this->manager, window->getSize().x / 2,
                              window->getSize().y, window, 2, 2, machine.soundLoaderPointer);
    this->manager->addEntity("ship", this->player);


    this->pausedText = util->addText(util->translate("Paused. Press", machine.settingPointer->selectedLanguage) + "\n" + machine.keybindMap.find("back")->second.first + util->translate(" to quit", machine.settingPointer->selectedLanguage), 32, 2, 2,
                                     window->getSize().x / 2, window->getSize().y / 2, window, machine.settingPointer->selectedLanguage);

    this->pausedTexture = new sf::Texture();
    this->pausedTexture->loadFromFile("Graphics/Sprites/overlayPause.png");


    this->pausedBackground = new sf::Sprite();
    this->pausedBackground->setTexture(*this->pausedTexture);
    this->pausedBackground->setOrigin(this->pausedBackground->getGlobalBounds().width / 2, this->pausedBackground->getGlobalBounds().height / 2);
    this->pausedBackground->setPosition(window->getSize().x / 2, window->getSize().y / 2);

    util->makeMuteButton(window, machine.mutedPointer);
}

void StateGameMode2::update(sf::RenderWindow *window) {
    machine.soundLoaderPointer->updateSounds();

    if (!util->paused) //Stopper spillet fra å oppdateres når det pauses
    {
        enemyClock.start();
        this->manager->updateEntity(window, machine.deltaTimePointer);
        this->score->updateScore(util->translate("Score", machine.settingPointer->selectedLanguage));
        this->lives->updateLife(util->translate("Lives", machine.settingPointer->selectedLanguage));

        if (this->lives->getValue() <= 0) {
            machine.setGameOverScore(this->score->getValue());
            machine.setState(new StateGameOver);
            return;
        }



        //std::cout << "size:  " << enemyList.size() << "time: " << enemyClock.getElapsedTime().asSeconds() << std::endl;
        if (enemyList.size() == 0 && enemyClock.getElapsedTime().asSeconds() > 1.5) {
            clockenemy.restart();
            spawnEnemies(window);
            wave++;
        }
        updateEnemyList();
        turnEnemies(window);
        enemyShoot(window);


    } else{
        enemyClock.pause();
        util->checkMuteMouseOver(window);
    }

}

void StateGameMode2::render(sf::RenderWindow *window) {
    window->draw(*this->background);
    window->draw(*this->score);
    window->draw(*this->lives);

    this->manager->renderEntity(window);
    if (util->paused) {
        window->draw(*this->pausedBackground);
        window->draw(*this->pausedText);
        window->draw(*util->getMuteButton());

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
    delete this->pausedTexture;
    delete this->pausedBackground;

}

void StateGameMode2::handleEvent(sf::RenderWindow *window, sf::Event event) {
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
    if (event.type == sf::Event::MouseButtonReleased) {
        if (util->paused) {
            util->checkMuteMouseClick(window, event, machine.mutedPointer);
        }
    }
}

void StateGameMode2::reinitialize(sf::RenderWindow *window) {

}

void StateGameMode2::spawnEnemies(sf::RenderWindow *window) {
    for (int i = 0; i < 7; ++i) {
        std::vector<Enemy2Object *> tempList;
        enemyList.push_back(tempList);
        for (int j = 0; j < 5; ++j) {
            enemy2Object = new Enemy2Object(manager, i, j, "fishis_0" + std::to_string(j + 1) + ".png", window,
                                            machine.selectedObjectsPointer->selectedTheme);
            this->manager->addEntity("Enemy", enemy2Object);
            enemyList.at(i).push_back(enemy2Object);
        }
    }
}

void StateGameMode2::turnEnemies(sf::RenderWindow *window) {
    if (nextCollissionRight) {
        for (int i = 0; i < enemyList.size(); ++i) {
            if (enemyList.at(i).front()->getPosition().x > window->getSize().x) {
                nextCollissionRight = !nextCollissionRight;
                for (int j = 0; j < enemyList.size(); ++j) {
                    for (int k = 0; k < enemyList.at(j).size(); ++k) {
                        if (enemyList.at(j).at(k) != nullptr) {
                            enemyList.at(j).at(k)->velocity.x = enemyList.at(j).at(k)->velocity.x * -1.2f;
                            enemyList.at(j).at(k)->setPosition(enemyList.at(j).at(k)->getPosition().x,
                                                               enemyList.at(j).at(k)->getPosition().y +
                                                               enemyList.at(j).at(k)->getGlobalBounds().height);

                            enemyList.at(j).at(k)->scale(-1.0f, 1.0f);
                        }
                    }
                }
                break;
            }
        }

    } else {
        for (int i = 0; i < enemyList.size(); ++i) {
            if (enemyList.at(i).front()->getPosition().x < 0) {
                nextCollissionRight = !nextCollissionRight;
                for (int j = 0; j < enemyList.size(); ++j) {
                    for (int k = 0; k < enemyList.at(j).size(); ++k) {
                        if (enemyList.at(j).at(k) != nullptr) {
                            enemyList.at(j).at(k)->velocity.x = enemyList.at(j).at(k)->velocity.x * -1.2f;
                            enemyList.at(j).at(k)->setPosition(enemyList.at(j).at(k)->getPosition().x,
                                                               enemyList.at(j).at(k)->getPosition().y +
                                                               enemyList.at(j).at(k)->getGlobalBounds().height);

                            enemyList.at(j).at(k)->scale(-1.0f, 1.0f);
                        }
                    }
                }
                break;
            }
        }
    }
}

void StateGameMode2::updateEnemyList() {
    for (int i = 0; i < enemyList.size(); ++i) {
        if (enemyList.at(i).size() == 0) {
            enemyClock.restart();
            enemyList.erase(enemyList.begin() + i);
            break;
        }
        for (int j = 0; j < enemyList.at(i).size(); ++j) {
            if (enemyList.at(i).at(j) != nullptr) {
                if (enemyList.at(i).at(j)->activeEntity() == 0) {
                    enemyList.at(i).erase(enemyList.at(i).begin() + j);
                    break;
                }
            }
        }
    }
}

void StateGameMode2::enemyShoot(sf::RenderWindow *window) {
    //random int fra 0 til size of enemyList
    //hvert halve sekund
    //spawn kule med posisjon enemyList.at(randomInt).back().getposx og y - en halv enemyList.at(randomInt).back().getGlobalbounds.height
    int random;

    if (enemyList.size() > 1) {
        random = rand() % (enemyList.size() - 1);
    } else random = 0;


    sf::Time elapsed1 = clockenemy.getElapsedTime();

    if (elapsed1.asSeconds() > (4.f / (wave + 1)) && enemyList.size() > 0) {
        if (enemyList.at(random).back() != nullptr) {
            this->manager->addEntity("Bullet", new Bullet(enemyList.at(random).back()->getPosition().x,
                                                          enemyList.at(random).back()->getPosition().y
                                                          + enemyList.at(random).back()->getGlobalBounds().height,
                                                          (0.75f), 0, 0, window,
                                                          machine.selectedObjectsPointer->selectedTheme));

            clockenemy.restart();
        }

    }

}
