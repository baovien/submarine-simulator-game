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
    this->bossTexture->loadFromFile("Graphics/Sprites/gold.png");

    this->arcadeTexture = new sf::Texture();
    this->arcadeTexture->loadFromFile("Graphics/Sprites/Picture_buttons/PngBtn8.png");

    this->classicTexture = new sf::Texture();
    this->classicTexture->loadFromFile("Graphics/Sprites/Picture_buttons/PngBtn10.png");

    this->overheatTexture = new sf::Texture();
    this->overheatTexture->loadFromFile("Graphics/Sprites/overheat.png");

    this->underwaterTexture = new sf::Texture();
    this->underwaterTexture->loadFromFile("Graphics/Sprites/Picture_buttons/PngBtn2.png");

    this->spaceTexture = new sf::Texture();
    this->spaceTexture->loadFromFile("Graphics/Sprites/Picture_buttons/PngBtn0.png");

    this->background = new sf::Sprite();
    this->background->setTexture(*this->backgroundTexture);
    this->background->scale(window->getSize().x / background->getGlobalBounds().width, window->getSize().y / background->getGlobalBounds().height);

    this->enemyFish = new sf::Sprite();
    this->enemyFish->setTexture(*this->enemyFishTexture);
    this->enemyFish->setOrigin(this->enemyFish->getGlobalBounds().width/2, this->enemyFish->getGlobalBounds().height/2);
    this->enemyFish->scale(window->getSize().x / 3200.0f, window->getSize().y / 1800.0f);
    this->enemyFish->setPosition(window->getSize().x/35,window->getSize().y/4.45f);

    this->boss = new sf::Sprite();
    this->boss->setTexture(*this->bossTexture);
    this->boss->setOrigin(this->boss->getGlobalBounds().width / 2, this->boss->getGlobalBounds().height / 2);
    this->boss->scale(window->getSize().x / 984.6f, window->getSize().y / 553.8f);
    this->boss->setPosition(window->getSize().x / 35, window->getSize().y / 3);

    this->classic = new sf::Sprite();
    this->classic->setTexture(*this->classicTexture);
    this->classic->setOrigin(this->classic->getGlobalBounds().width / 2, this->classic->getGlobalBounds().height / 2);
    this->classic->scale(window->getSize().x / 12800.0f, window->getSize().y / 7200.0f);
    this->classic->setPosition(window->getSize().x / 35, window->getSize().y / 2.15f);

    this->arcade = new sf::Sprite();
    this->arcade->setTexture(*this->arcadeTexture);
    this->arcade->setOrigin(this->arcade->getGlobalBounds().width / 2, this->arcade->getGlobalBounds().height / 2);
    this->arcade->scale(window->getSize().x / 12800.0f, window->getSize().y / 7200.0f);
    this->arcade->setPosition(window->getSize().x / 35, window->getSize().y / 1.77f);

    this->overheat = new sf::Sprite();
    this->overheat->setTexture(*this->overheatTexture);
    this->overheat->setOrigin(this->overheat->getGlobalBounds().width / 2, this->overheat->getGlobalBounds().height / 2);
    this->overheat->scale(window->getSize().x / 2560.0f, window->getSize().y / 1440.0f);
    this->overheat->setPosition(window->getSize().x / 35, window->getSize().y / 1.56f);

    this->underwater = new sf::Sprite();
    this->underwater->setTexture(*this->underwaterTexture);
    this->underwater->setOrigin(this->underwater->getGlobalBounds().width / 2, this->underwater->getGlobalBounds().height / 2);
    this->underwater->scale(window->getSize().x / 12800.0f, window->getSize().y / 7200.0f);
    this->underwater->setPosition(window->getSize().x / 35, window->getSize().y / 1.35f);

    this->space = new sf::Sprite();
    this->space->setTexture(*this->spaceTexture);
    this->space->setOrigin(this->space->getGlobalBounds().width / 2, this->space->getGlobalBounds().height / 2);
    this->space->scale(window->getSize().x / 12800.0f, window->getSize().y / 7200.0f);
    this->space->setPosition(window->getSize().x / 35, window->getSize().y / 1.25f);

    util.makeMuteButton(window, machine.mutedPointer);

    title = util.addText("Help", 80, 2, 2, window->getSize().x / 2.0f, window->getSize().y / 24.0f, window, machine.settingPointer->selectedLanguage);

    asteroid1 = util.addText("This object is exclusive to gamemode 1. It will move around randomly on the map, \n"
                                     "and it can not be destroyed by the player, it will however damage the player if the player touches it.",
                             18, 2, 2, window->getSize().x / 14.5f,
                             window->getSize().y / 5.0f, window, machine.settingPointer->selectedLanguage);
    this->asteroid1->setOrigin(0, 0);

    boss1 = util.addText("This object is also exclusive to gamemode 1. This object is what we call the Boss. The player can kill it, and it can"
                                 "\nkill the player. The Boss also has the ability to shoot. You will encounter this enemy as you progress.",
                         18, 2, 2, window->getSize().x / 14.5f,
                         window->getSize().y / 3.35f, window, machine.settingPointer->selectedLanguage);
    this->boss1->setOrigin(0, 0);

    gamemode = util.addText("You can choose between two gameodes. Classic and Arcade. In Classic, the player is at the bottom of the window\n"
                                    "and can only move right or left. The enemies are moving from side to side, and as they are about to go out of the screen,\n"
                                    "they will drop down towards the player. The goal of this gamemode is to destroy the enemies before they reach you.\n\n"
                                    "In Arcade, the player moves around freely, while enemies come in waves. The player get points by killing the enemies.",
                            18, 2, 2, window->getSize().x / 14.5f,
                            window->getSize().y / 2.4f, window, machine.settingPointer->selectedLanguage);
    this->gamemode->setOrigin(0, 0);

    overheat1 = util.addText("The overheatbar is a function in gamemode 1 that keeps the player from shooting too much within a short period of time.\n"
                                     "If the player overheats the player has to wait until it cools down before the player can start shooting again.",
                             18, 2, 2, window->getSize().x / 14.5f,
                             window->getSize().y / 1.63f, window, machine.settingPointer->selectedLanguage);
    this->overheat1->setOrigin(0, 0);

    theme = util.addText("You have the freedom to choose between two different themes. Underwater or space.\n"
                                 "The only difference between the two is the change of background.",
                         18, 2, 2, window->getSize().x / 14.5f,
                         window->getSize().y / 1.34f, window, machine.settingPointer->selectedLanguage);
    this->theme->setOrigin(0, 0);

    buttonTexture.buttonMouseOver = new sf::Texture();
    buttonTexture.buttonMouseOver->loadFromFile("Graphics/Sprites/PlayConfig_buttons/Btn3.png");

    buttonTexture.buttonNormal = new sf::Texture();
    buttonTexture.buttonNormal->loadFromFile("Graphics/Sprites/PlayConfig_buttons/Btn4.png");

    buttonTexture.buttonClicked = new sf::Texture();
    buttonTexture.buttonClicked->loadFromFile("Graphics/Sprites/PlayConfig_buttons/Btn5.png");

    button = new sf::Sprite();
    button->setTexture(*this->buttonTexture.buttonNormal);
    button->setOrigin(button->getGlobalBounds().width / 2, button->getGlobalBounds().height / 2);
    button->scale(window->getSize().x / 5120.f, window->getSize().y / 2880.f);
    button->setPosition(window->getSize().x * 0.95f, window->getSize().y - window->getSize().y / 10);
}

void stateHelp::update(sf::RenderWindow *window) {

    util.checkMuteMouseOver(window);

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
    window->draw(*this->enemyFish);
    window->draw(*this->asteroid1);
    window->draw(*this->boss);
    window->draw(*this->boss1);
    window->draw(*this->classic);
    window->draw(*this->arcade);
    window->draw(*this->gamemode);
    window->draw(*this->overheat);
    window->draw(*this->overheat1);
    window->draw(*this->underwater);
    window->draw(*this->space);
    window->draw(*this->theme);

    window->draw(*this->theme);

    window->draw(*this->button);

    window->draw(*util.getMuteButton());


}

void stateHelp::destroy(sf::RenderWindow *window) {

    delete this->title;
    delete this->backgroundTexture;
    delete this->enemyFishTexture;
    delete this->bossTexture;
    delete this->classicTexture;
    delete this->arcadeTexture;
    delete this->overheatTexture;
    delete this->underwaterTexture;
    delete this->spaceTexture;

    delete this->background;
    delete this->enemyFish;
    delete this->boss;
    delete this->classic;
    delete this->arcade;
    delete this->overheat;
    delete this->underwater;
    delete this->space;

    delete this->asteroid1;
    delete this->boss1;
    delete this->gamemode;
    delete this->overheat1;
    delete this->theme;

    delete this->button;
    delete this->buttonTexture.buttonClicked;
    delete this->buttonTexture.buttonNormal;
    delete this->buttonTexture.buttonMouseOver;

}

void stateHelp::handleEvent(sf::RenderWindow *window, sf::Event event) {

    if (event.type == event.KeyPressed) {
        if (event.key.code == machine.keybindMap.find("back")->second.second) {
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
    initialize(window);
}
