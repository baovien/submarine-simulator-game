#include <iostream>
#include "../../Include/States/stateMainMenu.h"
#include "../../Include/States/stateHelp.h"


void stateHelp::initialize(sf::RenderWindow *window) {

    sf::View newView(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
    window->setView(newView);

    this->backgroundTexture = new sf::Texture();
    this->backgroundTexture->loadFromFile("Graphics/Sprites/background12.png");

    this->enemyFishTexture = new sf::Texture();
    this->enemyFishTexture->loadFromFile("Graphics/Sprites/happyfish.png");

    this->bossTexture = new sf::Texture();
    this->bossTexture->loadFromFile("Graphics/Sprites/blowfish.png");

    this->healthPackTexture = new sf::Texture();
    this->healthPackTexture->loadFromFile("Graphics/Sprites/wrench.png");

    this->shieldTexture = new sf::Texture();
    this->shieldTexture->loadFromFile("Graphics/Sprites/shieldPowerUp.png");

    this->overheatTexture = new sf::Texture();
    this->overheatTexture->loadFromFile("Graphics/Sprites/overheat.png");

    this->junkTexture = new sf::Texture();
    this->junkTexture->loadFromFile("Graphics/Sprites/tincan.png");

    this->classicTexture = new sf::Texture();
    this->classicTexture->loadFromFile("Graphics/Sprites/PlayConfig_pictures/PngBtn10.png");


    this->spaceTexture = new sf::Texture();
    this->spaceTexture->loadFromFile("Graphics/Sprites/PlayConfig_pictures/PngBtn0.png");

    this->background = new sf::Sprite();
    this->background->setTexture(*this->backgroundTexture);
    this->background->scale(window->getSize().x / background->getGlobalBounds().width, window->getSize().y / background->getGlobalBounds().height);

    this->enemyFish = new sf::Sprite();
    this->enemyFish->setTexture(*this->enemyFishTexture);
    this->enemyFish->setOrigin(this->enemyFish->getGlobalBounds().width/2.f, this->enemyFish->getGlobalBounds().height/2.f);
    this->enemyFish->scale(window->getSize().x / 3840.0f, window->getSize().y / 2160.0f);
    this->enemyFish->setPosition(window->getSize().x/35.f,window->getSize().y/4.45f);

    this->boss = new sf::Sprite();
    this->boss->setTexture(*this->bossTexture);
    this->boss->setOrigin(this->boss->getGlobalBounds().width / 2.f, this->boss->getGlobalBounds().height / 2.f);
    this->boss->scale(window->getSize().x / 5248.0f, window->getSize().y / 2952.0f);
    this->boss->setPosition(window->getSize().x / 35.f, window->getSize().y / 3.f);

    this->healthPack = new sf::Sprite();
    this->healthPack->setTexture(*this->healthPackTexture);
    this->healthPack->setOrigin(this->healthPack->getGlobalBounds().width / 2, this->healthPack->getGlobalBounds().height / 2.f);
    this->healthPack->scale(window->getSize().x / 2560.0f, window->getSize().y / 1440.0f);
    this->healthPack->setPosition(window->getSize().x / 35.f, window->getSize().y / 2.4f);

    this->shield = new sf::Sprite();
    this->shield->setTexture(*this->shieldTexture);
    this->shield->setOrigin(this->shield->getGlobalBounds().width / 2.f, this->shield->getGlobalBounds().height / 2.f);
    this->shield->scale(window->getSize().x / 2560.0f, window->getSize().y / 1440.0f);
    this->shield->setPosition(window->getSize().x / 35.f, window->getSize().y / 2.15f);

    this->overheat = new sf::Sprite();
    this->overheat->setTexture(*this->overheatTexture);
    this->overheat->setOrigin(this->overheat->getGlobalBounds().width / 2.f, this->overheat->getGlobalBounds().height / 2.f);
    this->overheat->scale(window->getSize().x / 2944.0f, window->getSize().y / 1656.0f);
    this->overheat->setPosition(window->getSize().x / 35.f, window->getSize().y / 1.9f);

    this->junk = new sf::Sprite();
    this->junk->setTexture(*this->junkTexture);
    this->junk->setOrigin(this->junk->getGlobalBounds().width / 2.f, this->junk->getGlobalBounds().height / 2.f);
    this->junk->scale(window->getSize().x / 3072.0f, window->getSize().y / 1728.0f);
    this->junk->setPosition(window->getSize().x / 35.f, window->getSize().y / 1.6f);

    /*this->underwater = new sf::Sprite();
    this->underwater->setTexture(*this->underwaterTexture);
    this->underwater->setOrigin(this->underwater->getGlobalBounds().width / 2, this->underwater->getGlobalBounds().height / 2);
    this->underwater->scale(window->getSize().x / 12800.0f, window->getSize().y / 7200.0f);
    this->underwater->setPosition(window->getSize().x / 35, window->getSize().y / 1.35f);*/

    this->classic = new sf::Sprite();
    this->classic->setTexture(*this->classicTexture);
    this->classic->setOrigin(this->classic->getGlobalBounds().width / 2.f, this->classic->getGlobalBounds().height / 2.f);
    this->classic->scale(window->getSize().x / 10240.0f, window->getSize().y / 5760.0f);
    this->classic->setPosition(window->getSize().x / 35.f, window->getSize().y / 1.3f);

    util.makeMuteButton(window, machine.mutedPointer);

    title = util.addText("Help", 65, 2, 2, window->getSize().x / 2.0f, window->getSize().y / 24.0f, window, machine.settingPointer->selectedLanguage);

    mode = util.addText("Gamemode 1", 30 , 2, 2,window->getSize().x / 2.0f, window->getSize().y / 7.0f, window, machine.settingPointer->selectedLanguage);
    mode->setFillColor(sf::Color(140,255,75));

    mode2 = util.addText("Gamemode 2", 30 , 2, 2,window->getSize().x / 2.0f, window->getSize().y / 1.5f, window, machine.settingPointer->selectedLanguage);
    mode2->setFillColor(sf::Color(140,255,75));
    gamemode2 = util.addText((util.translate("This is the classic arcade space shooter game where the player only can move horizontally at the bottom of the screen.\n"
                                                     "The goal is to defeat the enemies by shooting them, while they move horizontally back and forth across the screen as\n"
                                                     "they advance towards the bottom of the screen."
                                                     " The enemies can kill the player by either shooting it \nor by colliding into it."
                                                     " The default keybind for shooting is space.", machine.settingPointer->selectedLanguage)),
                             18 , 0, 0,window->getSize().x / 16.5f, window->getSize().y / 1.4f, window, machine.settingPointer->selectedLanguage);

    asteroid1 = util.addText("Enemy spawn in waves. They chase you and will shoot at you after the first boss. The number of enemies \ndepend on the wave. Running into"
                                     " the enemy will destroy it and damage you, unless you are shielded.",
                             18, 2, 2, window->getSize().x / 16.5f,
                             window->getSize().y / 5.1f, window, machine.settingPointer->selectedLanguage);
    this->asteroid1->setOrigin(0, 0);

    boss1 = util.addText((util.translate("Every fifth wave, the boss will spawn. Running into it will kill you.\nThe default key to shoot the boss and enemies is space.", machine.settingPointer->selectedLanguage)),
                         18, 2, 2, window->getSize().x / 16.5f,
                         window->getSize().y / 3.32f, window, machine.settingPointer->selectedLanguage);
    this->boss1->setOrigin(0, 0);

    powerUp = util.addText("There are two powerups. One will give you +1 lives, and the other one will grant you immunity for a short duration.",
                            18, 2, 2, window->getSize().x / 16.5f,
                            window->getSize().y / 2.38f, window, machine.settingPointer->selectedLanguage);
    this->powerUp->setOrigin(0, 0);

    overheat1 = util.addText("The overheatbar is a function that keeps the player from shooting too much within a short period of time.\n"
                                     "If the player overheats, the player has to wait till it cools down before the player can start shooting again",
                             18, 2, 2, window->getSize().x / 16.5f,
                             window->getSize().y / 2.0f, window, machine.settingPointer->selectedLanguage);
    this->overheat1->setOrigin(0, 0);


    garbage = util.addText("Indestructable junk will periodically fly through the screen, damaging everything in its path.",
                         18, 2, 2, window->getSize().x / 16.5f,
                         window->getSize().y / 1.63f, window, machine.settingPointer->selectedLanguage);
    this->garbage->setOrigin(0, 0);

    buttonTexture.buttonMouseOver = new sf::Texture();
    buttonTexture.buttonMouseOver->loadFromFile("Graphics/Sprites/PlayConfig_buttons/Btn3.png");

    buttonTexture.buttonNormal = new sf::Texture();
    buttonTexture.buttonNormal->loadFromFile("Graphics/Sprites/PlayConfig_buttons/Btn4.png");

    buttonTexture.buttonClicked = new sf::Texture();
    buttonTexture.buttonClicked->loadFromFile("Graphics/Sprites/PlayConfig_buttons/Btn5.png");

    button = new sf::Sprite();
    button->setTexture(*this->buttonTexture.buttonNormal);
    button->setOrigin(button->getGlobalBounds().width / 2.f, button->getGlobalBounds().height / 2.f);
    button->scale(window->getSize().x / 5120.f, window->getSize().y / 2880.f);
    button->setPosition(window->getSize().x * 0.95f, window->getSize().y - window->getSize().y / 10.f);
}

void stateHelp::update(sf::RenderWindow *window) {

    util.checkMuteMouseOver(window);
    machine.soundLoaderPointer->updateSounds();

    if (util.checkMouseover(button, window)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            button->setTexture(*this->buttonTexture.buttonClicked);
        } else {
            button->setTexture(*this->buttonTexture.buttonMouseOver);
        }
    } else {
        button->setTexture(*this->buttonTexture.buttonNormal);
    }

}

void stateHelp::render(sf::RenderWindow *window) {

    window->draw(*this->background);
    window->draw(*this->title);
    window->draw(*this->mode);
    window->draw(*this->mode2);
    window->draw(*this->gamemode2);
    window->draw(*this->enemyFish);
    window->draw(*this->asteroid1);
    window->draw(*this->boss);
    window->draw(*this->boss1);
    window->draw(*this->healthPack);
    window->draw(*this->shield);
    window->draw(*this->powerUp);
    window->draw(*this->overheat);
    window->draw(*this->overheat1);
    window->draw(*this->junk);
    window->draw(*this->garbage);
    window->draw(*this->classic);

    window->draw(*this->button);

    window->draw(*util.getMuteButton());


}

void stateHelp::destroy(sf::RenderWindow *window) {

    delete this->title;
    delete this->mode;
    delete this->mode2;
    delete this->gamemode2;
    delete this->backgroundTexture;
    delete this->enemyFishTexture;
    delete this->bossTexture;
    delete this->healthPack;
    delete this->shield;
    delete this->overheatTexture;
    delete this->junkTexture;
    delete this->spaceTexture;
    delete this->classicTexture;

    delete this->background;
    delete this->enemyFish;
    delete this->boss;
    delete this->overheat;
    delete this->junk;
    delete this->space;

    delete this->asteroid1;
    delete this->boss1;
    delete this->powerUp;
    delete this->overheat1;
    delete this->garbage;
    delete this->classic;

    delete this->button;
    delete this->buttonTexture.buttonClicked;
    delete this->buttonTexture.buttonNormal;
    delete this->buttonTexture.buttonMouseOver;

}

void stateHelp::handleEvent(sf::RenderWindow *window, sf::Event event) {

    if (event.type == event.KeyPressed) {
        if (event.key.code == machine.keybindMap->find("back")->second.second) {
            machine.setState(new StateMainMenu);
            return;
        }

    }

    if (event.type == sf::Event::MouseButtonReleased) {
        util.checkMuteMouseClick(window, event, machine.mutedPointer);
        if (util.checkMouseclick(button, event)) {
            machine.setState(new StateMainMenu);
            return;
        }
    }
}

void stateHelp::reinitialize(sf::RenderWindow *window) {
    destroy(window);
    initialize(window);
}
