#include <cstring>
#include "../../Include/States/stateGameMode2.h"
#include "../../Include/States/stateMainMenu.h"
#include "../../Include/States/stateGameOver.h"


void StateGameMode2::initialize(sf::RenderWindow *window)
{

    this->manager = new EntityManager();

    sf::View newView(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
    window->setView(newView);

    machine.soundLoaderPointer->stopMusic();
    machine.soundLoaderPointer->playMusic(Audio::Music::CLASSIC);

    this->bgTexture = new sf::Texture();
    this->bgTexture->loadFromFile("Graphics/Sprites/background12.png");

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
    this->player = new Player(machine.keybindMap, this->lives, this->score, this->manager, window->getSize().x / 2,
                              window->getSize().y, window, 2, 2, machine.soundLoaderPointer);
    this->manager->addEntity("ship", this->player);


    this->pausedText = new sf::Text("Paused\nPress " + machine.keybindMap.find("back")->second.first + " to Quit",
                                    *font, 32U);
    this->pausedText->setOrigin(this->pausedText->getGlobalBounds().width / 2,
                                this->pausedText->getGlobalBounds().height / 2);
    this->pausedText->setPosition(window->getSize().x / 2, window->getSize().y / 2);

}

void StateGameMode2::update(sf::RenderWindow *window)
{
    machine.soundLoaderPointer->checkMuteMusic();

    if (!util->paused) //Stopper spillet fra å oppdateres når det pauses
    {
        this->manager->updateEntity(window, machine.deltaTimePointer);
        this->score->updateScore(util->translate("Score", machine.settingPointer->selectedLanguage));
        this->lives->updateLife(util->translate("Lives", machine.settingPointer->selectedLanguage));

        if (this->lives->getValue() <= 0)
        {
            machine.setGameOverScore(this->score->getValue());
            machine.setState(new StateGameOver);
            return;
        }
        if (enemyList.size() == 0)
        {
            spawnEnemies(window);
        }
        updateEnemyList();
        turnEnemies(window);
        enemyShoot(window);

    }
}

void StateGameMode2::render(sf::RenderWindow *window)
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

void StateGameMode2::destroy(sf::RenderWindow *window)
{
    delete this->lives;
    delete this->score;
    delete this->util;
    delete this->font;
    delete this->pausedText;
    delete this->background;
    delete this->manager;
}

void StateGameMode2::handleEvent(sf::RenderWindow *window, sf::Event event)
{
    if (event.type == event.KeyPressed)
    {
        if (event.key.code == machine.keybindMap.find("back")->second.second && util->paused)
        {
            machine.soundLoaderPointer->stopMusic();
            machine.setState(new StateMainMenu());
            return;
        }

        if (event.key.code == machine.keybindMap.find("pause")->second.second)
        {
            util->pauseScreen();                        //Kaller pausefunksjonen
            for (int i = 0; i < enemyList.size(); ++i)
            {
                std::cout << " ROW" + std::to_string(i) + " :";
                for (int j = 0; j < enemyList.at(i).size(); ++j)
                {
                    std::cout << enemyList.at(i).at(j)->activeEntity() << "     ";
                }
                std::cout << std::endl;
            }
            std::cout << "--------------------------------------" << std::endl;
        }
    }
}

void StateGameMode2::reinitialize(sf::RenderWindow *window)
{

}

void StateGameMode2::spawnEnemies(sf::RenderWindow *window)
{
    for (int i = 0; i < 5; ++i)
    {
        std::vector<Enemy2Object *> tempList;
        enemyList.push_back(tempList);
        for (int j = 0; j < 5; ++j)
        {
            enemy2Object = new Enemy2Object(manager, i, j, "fishis_0" + std::to_string(j + 1) + ".png", window);
            this->manager->addEntity("Enemy", enemy2Object);
            enemyList.at(i).push_back(enemy2Object);
        }
    }
}

void StateGameMode2::turnEnemies(sf::RenderWindow *window)
{
    for (int i = 0; i < enemyList.size(); ++i)
    {
        if (enemyList.at(i).front()->getPosition().x > window->getSize().x ||
            enemyList.at(i).front()->getPosition().x < 0)
        {
            for (int j = 0; j < enemyList.size(); ++j)
            {
                for (int k = 0; k < enemyList.at(j).size(); ++k)
                {
                    enemyList.at(j).at(k)->velocity.x = enemyList.at(j).at(k)->velocity.x * -1;
                    enemyList.at(j).at(k)->setPosition(enemyList.at(j).at(k)->getPosition().x,
                                                       enemyList.at(j).at(k)->getPosition().y +
                                                       enemyList.at(j).at(k)->getGlobalBounds().height);
                    enemyList.at(j).at(k)->scale(-1.f, 1.f);
                }
            }
            break;
        }
    }
}

void StateGameMode2::updateEnemyList()
{
    for (int i = 0; i < enemyList.size(); ++i)
    {
        if (enemyList.at(i).size() == 0)
        {
            enemyList.erase(enemyList.begin() + i);
            break;
        }
        for (int j = 0; j < enemyList.at(i).size(); ++j)
        {
            if (enemyList.at(i).at(j)->activeEntity() == 0)
            {
                enemyList.at(i).erase(enemyList.at(i).begin() + j);
                break;
            }
        }
    }
}

void StateGameMode2::enemyShoot(sf::RenderWindow *window)
{
    sf::Time elapsed1 = clock.getElapsedTime();
    if (elapsed1.asMicroseconds() > 1000000)
    {
        int randint = rand() % enemyList.size();
        this->manager->addEntity("Bullet", new Bullet(enemyList.at(randint).back()->getPosition().x,
                                                      enemyList.at(randint).back()->getPosition().y
                                                      + enemyList.at(randint).back()->getGlobalBounds().height,
                                                      window->getSize().x / 320, 0, 0, window));
        clock.restart();
    }

}