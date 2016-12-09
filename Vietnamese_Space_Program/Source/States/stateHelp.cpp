#include <iostream>
#include "../../Include/States/stateMainMenu.h"
#include "../../Include/States/stateHelp.h"


void stateHelp::initialize(sf::RenderWindow *window) {

    sf::View newView(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
    window->setView(newView);

    this->bgTexture = new sf::Texture();
    this->bgTexture->loadFromFile("Graphics/Sprites/bakgrunn.png");

    this->asTexture = new sf::Texture();
    this->asTexture->loadFromFile("Graphics/Sprites/asteroid.png");

    this->boTexture = new sf::Texture();
    this->boTexture->loadFromFile("Graphics/Sprites/gold.png");

    this->arTexture = new sf::Texture();
    this->arTexture->loadFromFile("Graphics/Sprites/Picture_buttons/PngBtn10.png");

    this->clTexture = new sf::Texture();
    this->clTexture->loadFromFile("Graphics/Sprites/Picture_buttons/PngBtn12.png");

    this->ohTexture = new sf::Texture();
    this->ohTexture->loadFromFile("Graphics/Sprites/overheat.png");

    this->uwTexture = new sf::Texture();
    this->uwTexture->loadFromFile("Graphics/Sprites/Picture_buttons/PngBtn2.png");

    this->spTexture = new sf::Texture();
    this->spTexture->loadFromFile("Graphics/Sprites/Picture_buttons/PngBtn0.png");




    this->background = new sf::Sprite();
    this->background->setTexture(*this->bgTexture);
    this->background->scale(window->getSize().x/background->getGlobalBounds().width,window->getSize().y/background->getGlobalBounds().height);

    this->asteroid = new sf::Sprite();
    this->asteroid->setTexture(*this->asTexture);
    this->asteroid->setOrigin(this->asteroid->getGlobalBounds().width/2, this->asteroid->getGlobalBounds().height/2);
    this->asteroid->scale(1,1);
    this->asteroid->setPosition(window->getSize().x/40,window->getSize().y/4.5);

    this->boss = new sf::Sprite();
    this->boss->setTexture(*this->boTexture);
    this->boss->setOrigin(this->boss->getGlobalBounds().width/2, this->boss->getGlobalBounds().height/2);
    this->boss->scale(1.3,1.3);
    this->boss->setPosition(window->getSize().x/35,window->getSize().y/3);

    this->classic = new sf::Sprite();
    this->classic->setTexture(*this->clTexture);
    this->classic->setOrigin(this->classic->getGlobalBounds().width/2, this->classic->getGlobalBounds().height/2);
    this->classic->scale(0.1,0.1);
    this->classic->setPosition(window->getSize().x/35,window->getSize().y/2.2);

    this->arcade = new sf::Sprite();
    this->arcade->setTexture(*this->arTexture);
    this->arcade->setOrigin(this->arcade->getGlobalBounds().width/2, this->arcade->getGlobalBounds().height/2);
    this->arcade->scale(0.1,0.1);
    this->arcade->setPosition(window->getSize().x/35,window->getSize().y/1.95);

    this->overheat = new sf::Sprite();
    this->overheat->setTexture(*this->ohTexture);
    this->overheat->setOrigin(this->overheat->getGlobalBounds().width/2, this->overheat->getGlobalBounds().height/2);
    this->overheat->scale(0.5,0.5);
    this->overheat->setPosition(window->getSize().x/35,window->getSize().y/1.655);

    this->underwater = new sf::Sprite();
    this->underwater->setTexture(*this->uwTexture);
    this->underwater->setOrigin(this->underwater->getGlobalBounds().width/2, this->underwater->getGlobalBounds().height/2);
    this->underwater->scale(0.1,0.1);
    this->underwater->setPosition(window->getSize().x/35,window->getSize().y/1.45);

    this->space = new sf::Sprite();
    this->space->setTexture(*this->spTexture);
    this->space->setOrigin(this->space->getGlobalBounds().width/2, this->space->getGlobalBounds().height/2);
    this->space->scale(0.1,0.1);
    this->space->setPosition(window->getSize().x/35,window->getSize().y/1.345);

    util.makeMuteButton(window, machine.mutedPointer);

    title = util.addText("Tutorial", 80, 2, 2, window->getSize().x / 2.0f, window->getSize().y / 24.0f, window, machine.settingPointer->selectedLanguage);

    asteroid1 = util.addText(" You will find this enemy in gamemode 1. It flies around randomly,\n and can not be destroyd by the player."
                                     " But it can damage the player.",
                             18, 2, 2, window->getSize().x / 3.05f, window->getSize().y / 4.4f, window, machine.settingPointer->selectedLanguage);

    boss1 = util.addText("  This enemy is called boss and appers in gamemode 1. The player can kill it,\n  and it can kill the player. "
                                 "The boss has the ability to shoot.",
                        18, 2, 2, window->getSize().x / 2.9f, window->getSize().y / 3.0f, window, machine.settingPointer->selectedLanguage);


    gamemode = util.addText("   You can choose between two gameodes. Classic and arcade. In classic mode the player \n   is at the bottom of the window"
                                    " and can only move right and left, while enemies are falling \n   down while they move to left and right."
                                    "The point is to shoot the enemies. \n"
                                    "   In arcade the player moves around freely, while enemies come in waves. The player get points by killing the enemies.",
                         18, 2, 2, window->getSize().x / 2.0f, window->getSize().y / 2.1f, window, machine.settingPointer->selectedLanguage);

    overheat1 = util.addText("  Overheat keeps the player from shooting uncotrolled much.",
                            18, 2, 2, window->getSize().x / 3.5f, window->getSize().y / 1.67f, window, machine.settingPointer->selectedLanguage);

    theme = util.addText("You can choose between two themes. Underwater and space.\nIn the underwater-theme the player is a submarine,"
                                 " \nand in the space-theme the player is a spaceship",
                             18, 2, 2, window->getSize().x / 3.4f, window->getSize().y / 1.41f, window, machine.settingPointer->selectedLanguage);


    PictureTexture[0].buttonMouseOver = new sf::Texture();
    PictureTexture[0].buttonMouseOver->loadFromFile("Graphics/Sprites/PlayConfig_buttons/Btn3.png");

    PictureTexture[0].buttonNormal = new sf::Texture();
    PictureTexture[0].buttonNormal->loadFromFile("Graphics/Sprites/PlayConfig_buttons/Btn4.png");

    PictureTexture[0].buttonClicked = new sf::Texture();
    PictureTexture[0].buttonClicked->loadFromFile("Graphics/Sprites/PlayConfig_buttons/Btn5.png");

    PictureButtons[0] = new sf::Sprite();
    PictureButtons[0]->setTexture(*this->PictureTexture[0].buttonNormal);
    PictureButtons[0]->setOrigin(PictureButtons[0]->getGlobalBounds().width / 2, PictureButtons[0]->getGlobalBounds().height / 2);
    PictureButtons[0]->scale(window->getSize().x / 5120.f, window->getSize().y / 2880.f);
    PictureButtons[0]->setPosition(window->getSize().x * 0.95f, window->getSize().y - window->getSize().y / 10);
}

void stateHelp::update(sf::RenderWindow *window) {

    util.checkMuteMouseOver(window);

    for (unsigned int i = 0; i < sizeof(PictureTexture) / sizeof(*PictureTexture); ++i)
    {
        if (util.checkMouseover(PictureButtons[i], window))
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                PictureButtons[i]->setTexture(*this->PictureTexture[i].buttonClicked);
            } else
            {
                PictureButtons[i]->setTexture(*this->PictureTexture[i].buttonMouseOver);
            }
        } else
        {
            PictureButtons[i]->setTexture(*this->PictureTexture[i].buttonNormal);
        }
    }

}

void stateHelp::render(sf::RenderWindow *window) {

    window->draw(*this->background);
    window->draw(*this->title);
    window->draw(*this->asteroid);
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

    window->draw(*this->PictureButtons[0]);

    window->draw(*util.getMuteButton());


}
void stateHelp::destroy(sf::RenderWindow *window) {

    delete this->background;
    delete this->bgTexture;
    delete this->title;
    delete this->asteroid;
    delete this->asteroid1;
    delete this->boss;
    delete this->boss1;
    delete this->classic;
    delete this->arcade;
    delete this->gamemode;
    delete this->overheat;
    delete this->overheat1;
    delete this->underwater;
    delete this->space;
    delete this->theme;
    delete this->PictureButtons[0];

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
        if (util.checkMouseclick(PictureButtons[0], event)) {

            switch (0) {
                //playknappen trykket
                case 0:
                    machine.setState(new StateMainMenu);
                    return;
                default:
                    return;

            }
        }
    }

}

    void stateHelp::reinitialize(sf::RenderWindow *window) {
                           //Returnknappen trykket


                       }
