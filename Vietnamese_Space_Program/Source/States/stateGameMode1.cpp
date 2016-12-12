#include "../../Include/States/stateGameMode1.h"
#include "../../Include/States/stateMainMenu.h"
#include "../../Include/States/stateGameOver.h"

void StateGameMode1::initialize(sf::RenderWindow *window) {
    //TODO:

    sf::View newView(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
    window->setView(newView);

    machine.soundLoaderPointer->stopMusic();
    machine.soundLoaderPointer->playMusic(Audio::Music::ARCADE);

    this->manager = new EntityManager();
    this->util = new Utilities;

    this->bgTexture = new sf::Texture();
    this->bgTexture->loadFromFile("Graphics/Sprites/background12.png");
    this->background = new sf::Sprite();

    this->background->setTexture(*this->bgTexture);
    this->background->scale(window->getSize().x / background->getGlobalBounds().width, window->getSize().y / background->getGlobalBounds().height);
    this->font = new sf::Font();
    this->font->loadFromFile("Graphics/font.ttf");

    this->waveText = util->addText("Wave: ", 75, 2, 2, window->getSize().x / 2, window->getSize().y / 4, window, machine.settingPointer->selectedLanguage);
    this->waveText->setFillColor(sf::Color(255, 255, 255, (sf::Uint8) transparencyValue));
    this->waveText->setOutlineColor(sf::Color(0, 0, 0, (sf::Uint8) transparencyValue));

    this->score = new Score(*font, 32U);
    this->score->setPosition(window->getSize().x/10,window->getSize().y/20);
    this->score->setScale(window->getSize().x/1280, window->getSize().y/720);

    this->lives = new Lives(*font, 32U);
    this->lives->setPosition(window->getSize().x - window->getSize().x/5, window->getSize().y/20);
    this->lives->setScale(window->getSize().x/1280, window->getSize().y/720);

    //Init player
    this->player = new Player(machine.keybindMap, this->lives, this->score, this->manager, window->getSize().x / 2, window->getSize().y / 2, window, 1, 2, machine.soundLoaderPointer);
    this->manager->addEntity("ship", this->player);

    //Init entities
    this->shieldEntity = new ShieldEntity(window, this->player, machine.soundLoaderPointer);
    this->healthPack = new HealthPack(this->lives, machine.soundLoaderPointer, window);
    //this->bossObject = new BossObject(this->manager, this->player, this->mode, window);

    this->overBar.loadFromFile("Graphics/Sprites/overheat_border.png");
    this->overBarS.setTexture(this->overBar);
    this->overBarS.setOrigin(this->overBarS.getGlobalBounds().width/2, this->overBarS.getGlobalBounds().height/2);
    this->overBarS.setPosition(window->getSize().x/2, window->getSize().y - this->overBarS.getGlobalBounds().height);
    this->overBarS.setScale(window->getSize().x/640,window->getSize().y/360);

    //Init pauseobjekter
    //Text, textsize, origin x, origin y, position x, position y, window, language int

    this->pausedText = util->addText(util->translate("Paused. Press", machine.settingPointer->selectedLanguage) + "\n" + machine.keybindMap.find("back")->second.first + util->translate(" to quit", machine.settingPointer->selectedLanguage), 32, 2, 2, window->getSize().x / 2, window->getSize().y / 2, window, machine.settingPointer->selectedLanguage);

    this->pausedTexture = new sf::Texture();
    this->pausedTexture->loadFromFile("Graphics/Sprites/overlayPause.png");

    this->pausedBackground = new sf::Sprite();
    this->pausedBackground->setTexture(*this->pausedTexture);
    this->pausedBackground->setOrigin(this->pausedBackground->getGlobalBounds().width / 2, this->pausedBackground->getGlobalBounds().height / 2);
    this->pausedBackground->setPosition(window->getSize().x / 2, window->getSize().y / 2);
}

void StateGameMode1::update(sf::RenderWindow *window) {
    machine.soundLoaderPointer->updateSounds();

    if (!util->paused) //Stopper spillet fra å oppdateres når det pauses
    {

        this->manager->updateEntity(window, machine.deltaTimePointer);
        this->score->updateScore(util->translate("Score", machine.settingPointer->selectedLanguage));
        this->lives->updateLife(util->translate("Lives", machine.settingPointer->selectedLanguage));

        //Når playerliv blir 0, kommer gameOver splashscreen
        if (this->lives->getValue() <= 0) {
            machine.setGameOverScore(this->score->getValue());
            machine.soundLoaderPointer->stopMusic();
            machine.setState(new StateGameOver);
            return;
        }

        if (enemyList.size() == 0 && bossList.size() == 0) {
            machine.soundLoaderPointer->playEffect(Audio::Effect::WAVEDONE);
            waveNum++;
            spawnWave(window);
            updateWaveText(window, true);
        }

        //spawnObjects(window);
        updateEnemyList(window);
        updateWaveText(window, false);

    }else{
        this->pauseableClockIndestructableObject.pause();
        this->pauseableClockHealthPack.pause();
        this->healthPack->clock.pause();
        this->shieldEntity->clock.pause();
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
    delete this->bgTexture;
    delete this->pausedTexture;
}

void StateGameMode1::handleEvent(sf::RenderWindow *window, sf::Event event) {
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

void StateGameMode1::reinitialize(sf::RenderWindow *window) {}

void StateGameMode1::spawnObjects(sf::RenderWindow *window) {

    //Legger til healthpacks + indestructableObjects utenfor wavessystemet
    this->pauseableClockIndestructableObject.start();
    this->pauseableClockHealthPack.start();

    this->healthPack->clock.start();
    this->shieldEntity->clock.start();

    if (this->pauseableClockIndestructableObject.getElapsedTime().asMicroseconds() > 5000000)   //Sjekker om verdien til clock er mer enn 5 sekunder
    {
        this->manager->addEntity("indestructableObject", new IndestructableObject(window));   //er clock mer enn 5 sekunder lager jeg en ny astroide
        this->pauseableClockIndestructableObject.restart();                             //restarter clock(nullstiller)
    }

    if (pauseableClockShieldEntity.getElapsedTime().asMicroseconds() > 1000000) {
        if (rand() % 10 < 2) {
            spawnedShieldPacks++;
            if (spawnedShieldPacks <= waveNum){
                this->shieldEntity = new ShieldEntity(window, this->player, machine.soundLoaderPointer);
                this->manager->addEntity("shieldEntity", this->shieldEntity);
                this->shieldEntity->clock.restart();
            }
        }
        pauseableClockShieldEntity.restart();
    }
    if (pauseableClockHealthPack.getElapsedTime().asMicroseconds() > 5000000) {         //Sjekker om verdien til clock er mer enn 5 sekunder
        if (rand() % 10 < 3) {
            spawnedHealthPacks++;
            if (spawnedHealthPacks <= waveNum){
                //Init entities
                this->healthPack = new HealthPack(this->lives, machine.soundLoaderPointer, window);
                this->manager->addEntity("healthPack", this->healthPack);
                this->healthPack->clock.restart();
            }
        }
        pauseableClockHealthPack.restart();     //restarter clock(nullstiller)
    }

}

void StateGameMode1::spawnWave(sf::RenderWindow *window) {
    if (waveNum > 5) this->mode = 2;

    if (waveNum % 5 == 0) { //BOSS HVER 5. WAVE
        bossObject = new BossObject(this->manager, this->player, this->mode, window);
        this->manager->addEntity("Boss", bossObject);
        bossList.push_back(bossObject);

    } else {                  //ENEMYSPAWN
        for (int i = 0; i < waveNum; ++i) {
            enemyObject = new EnemyObject(window, this->player, this->manager, this->mode, machine.soundLoaderPointer);
            this->manager->addEntity("Enemy", enemyObject);
            enemyList.push_back(enemyObject);
        }
    }
}

void StateGameMode1::updateEnemyList(sf::RenderWindow *window) {

    //Sjekker enemies
    for (int i = 0; i < enemyList.size(); i++) {
        if (enemyList.size() == 0) {
            enemyList.erase(enemyList.begin() + i);
            break;
        }

        if (enemyList.at((unsigned long) i)->activeEntity() == 0) {
            enemyList.erase(enemyList.begin() + i);
            break;

        }
    }

    //Sjekker boss
    for (int i = 0; i < bossList.size(); i++) {
        if (bossList.size() == 0) {
            bossList.erase(bossList.begin() + i);
            break;
        }

        if (bossList.at((unsigned long) i)->activeEntity() == 0) {
            bossList.erase(bossList.begin() + i);
            break;

        }
    }
}

void StateGameMode1::updateWaveText(sf::RenderWindow *window, bool choice) {

    if(choice){
        this->transparencyValue = 255;
        if(waveNum % 5 == 0) this->waveText = util->addText(util->translate("Boss", machine.settingPointer->selectedLanguage), 75, 2, 2, window->getSize().x / 2, window->getSize().y / 4, window, machine.settingPointer->selectedLanguage);
        else this->waveText = util->addText(util->translate("Wave: ", machine.settingPointer->selectedLanguage) + std::to_string(waveNum), 75, 2, 2, window->getSize().x / 2, window->getSize().y / 4, window, machine.settingPointer->selectedLanguage);
    }else{
        //Fader waveText
        this->waveText->setFillColor(sf::Color(255, 255, 255, (sf::Uint8) transparencyValue));
        this->waveText->setOutlineColor(sf::Color(0, 0, 0, (sf::Uint8) transparencyValue));
        if (transparencyValue > 1) transparencyValue -= 1;
    }
}
