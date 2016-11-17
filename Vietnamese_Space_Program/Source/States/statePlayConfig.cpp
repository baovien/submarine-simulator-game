#include "../../Include/States/statePlayConfig.h"
#include "../../Include/States/stateGameMode1.h"
#include "../../Include/States/stateMainMenu.h"
#include "../../Include/States/stateGameMode2.h"
#include "../../Include/States/stateSettings.h"


void StatePlayConfig::initialize(sf::RenderWindow *window) {

    machine.mouseClick = {-1, -1}; //Resetter mouseClick slik at museklikk fra tidligere states ikke triggerer if-sjekker.

    sf::View newView(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
    window->setView(newView);

    machine.mouseClick = {-1, -1};
    this->bgTexture = new sf::Texture();
    this->bgTexture->loadFromFile("Graphics/Sprites/bg_purple.png");

    this->background = new sf::Sprite();
    this->background->setTexture(*this->bgTexture);
    this->background->scale(window->getSize().x / background->getGlobalBounds().width, window->getSize().y / background->getGlobalBounds().height);

    this->selected = 0;
    this->selected_Theme = 0;
    this->selected_Fighter = 0;
    this->selected_Gamemode = 0;

    this->font = new sf::Font();
    this->font->loadFromFile("Graphics/font1.otf");

    DIAZ.loadFromFile("fighter.png");


/**
 * HOVEDVALGENE.
 * VELG MELLOM DE FORSKJELLIGE THEMENE, FIGHTERENE OG GAMEMODENE
 */
    this->theme = buttons.addText("SELECT THEME", 25, 2, 2,window->getSize().x / 2, window->getSize().y / 25);
    this->fighter = buttons.addText("SELECT FIGHTER", 25, 2, 2,window->getSize().x / 2, window->getSize().y / 25 + this->theme->getGlobalBounds().height * 8);
    this->gamemode = buttons.addText("SELECT GAMEMODE", 25, 2, 2,window->getSize().x / 2, window->getSize().y / 25 + this->theme->getGlobalBounds().height * 16);

/**
 * THEME PLASSERING.
 * UNDER HER PLASSERES DE FORSKJELLIGE THEMES.
 */
    this->SpaceTheme = buttons.addText("SPACE", 25, 2, 2,window->getSize().x / 3, window->getSize().y / 25 + this->theme->getGlobalBounds().height * 4);
    this->PaperTheme = buttons.addText("PAPER", 25, 2, 2,window->getSize().x / 1.5F, window->getSize().y / 25 + this->theme->getGlobalBounds().height * 4);

/**
 * FIGHTER PLASSERING.
 * UNDER HER PLASSERES DE FORSKJELLIGE FIGHTERENE.
 */
    this->fighter_1 = buttons.addText("ALVAREZ", 25, 2, 2, window->getSize().x / 3, window->getSize().y / 25 + this->fighter->getGlobalBounds().height * 12);
    this->fighter_2 = buttons.addText("MCGREGOR", 25, 2, 2, window->getSize().x / 2, window->getSize().y / 25 + this->fighter->getGlobalBounds().height * 12);
    this->fighter_3 = buttons.addText("DIAZ", 25, 2, 2, window->getSize().x / 1.5F, window->getSize().y / 25 + this->fighter->getGlobalBounds().height * 12);

/**
 * GAMEMODE PLASSERING.
 * UNDER HER PLASSERES DE FORSKJELLIGE GAMEMODENE.
 */
    this->Arcade = buttons.addText("ARCADE", 25, 2, 2, window->getSize().x / 3, window->getSize().y / 25 + this->fighter->getGlobalBounds().height * 20);

    this->Classic = buttons.addText("CLASSIC", 25, 2, 2, window->getSize().x / 1.5F, window->getSize().y / 25 + this->fighter->getGlobalBounds().height * 20 );
}

void StatePlayConfig::update(sf::RenderWindow *window)
{
    if (this->selected > 4)
    {
        this->selected = 0;
    }

    if (this->selected < 0)
    {
        this->selected = 4;
    }
}

void StatePlayConfig::render(sf::RenderWindow *window)
{
    this->theme->setFillColor(sf::Color::White);
    this->fighter->setFillColor(sf::Color::White);
    this->gamemode->setFillColor(sf::Color::White);

    this->theme->setStyle(0);
    this->fighter->setStyle(0);
    this->gamemode->setStyle(0);


    switch (this->selected) {
        case 0:
            this->SpaceTheme->setFillColor(sf::Color::White);
            this->PaperTheme->setFillColor(sf::Color::White);

            this->theme->setFillColor(sf::Color::Magenta);
            if (this->selected_Theme == 0)
            {
                this->SpaceTheme->setFillColor(sf::Color::Yellow);
            }
            if (this->selected_Theme == 1)
            {
                this->PaperTheme->setFillColor(sf::Color::Yellow);
            }
            break;

        case 1:
            this->fighter_1->setFillColor(sf::Color::White);
            this->fighter_2->setFillColor(sf::Color::White);
            this->fighter_3->setFillColor(sf::Color::White);

            this->fighter->setFillColor(sf::Color::Magenta);
            if (this->selected_Fighter == 0)
            {
                this->fighter_1->setFillColor(sf::Color::Yellow);
            }
            if (this->selected_Fighter == 1)
            {
                this->fighter_2->setFillColor(sf::Color::Yellow);
            }
            if (this->selected_Fighter == 2)
            {
                this->fighter_3->setFillColor(sf::Color::Yellow);
            }
            break;

        case 2:
            this->Arcade->setFillColor(sf::Color::White);

            this->Classic->setFillColor(sf::Color::White);

            this->gamemode->setFillColor(sf::Color::Magenta);
            if (this->selected_Gamemode == 0)
            {
                this->Arcade->setFillColor(sf::Color::Yellow);
            }
            if (this->selected_Gamemode == 1)
            {
                this->Classic->setFillColor(sf::Color::Yellow);
            }
            break;
    }

    window->draw(*this->background);

    window->draw(*this->theme);
    window->draw(*this->fighter);
    window->draw(*this->gamemode);

    window->draw(*this->SpaceTheme);
    window->draw(*this->PaperTheme);

    window->draw(*this->fighter_1);
    window->draw(*this->fighter_2);
    window->draw(*this->fighter_3);

    window->draw(*this->Arcade);
    window->draw(*this->Classic);
}

void StatePlayConfig::destroy(sf::RenderWindow *window)
{
    delete this->theme;
    delete this->font;
    delete this->fighter;
    delete this->gamemode;

    delete this->SpaceTheme;
    delete this->PaperTheme;

    delete this->fighter_1;
    delete this->fighter_2;
    delete this->fighter_3;

    delete this->Arcade;
    delete this->Classic;

    delete this->background;
}

void StatePlayConfig::handleEvent(sf::RenderWindow *window, sf::Event event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        // Trykk Escape for å komme til mainmenu
        if (event.key.code == machine.keybindMap->find("back")->second.second)
        {
            machine.setState(new StateMainMenu);
        }

        if (selected == 0)
        { // Ikke mulig a gå opp når du velger theme
            if (event.key.code == sf::Keyboard::Up)
            {
                this->selected = 0;
            }
        }
        if (selected != 4)
        {
            if (event.key.code == sf::Keyboard::Up)
            {
                this->selected -= 1;
            }
        }
        if (this->selected < 3)
        {
            if (event.key.code == sf::Keyboard::Down)
            {
                this->selected += 1;
            }
        }
        if (this->selected == 3)
        { // Start
            if (event.key.code == sf::Keyboard::Right)
            {
                this->selected += 1;
            }
        }
        if (this->selected == 4)
        { // Back
            if (event.key.code == sf::Keyboard::Left)
            {
                this->selected -= 1;
            }
            if (event.key.code == sf::Keyboard::Up)
            {
                this->selected = 2;
            }

        }
        if (this->selected == 0)
        { //Theme
            if (event.key.code == sf::Keyboard::Left)
            {
                this->selected_Theme -= 1;
            }
            if (event.key.code == sf::Keyboard::Right)
            {
                this->selected_Theme += 1;
            }
            if (this->selected_Theme > 2)
            {
                this->selected_Theme = 2;
            }
            if (this->selected_Theme < 0)
            {
                this->selected_Theme = 0;
            }
        }

        if (this->selected == 1)
        { //Fighter
            if (event.key.code == sf::Keyboard::Left)
            {
                this->selected_Fighter -= 1;
            }
            if (event.key.code == sf::Keyboard::Right)
            {
                this->selected_Fighter += 1;
            }
            if (this->selected_Fighter < 0)
            {
                this->selected_Fighter = 0;
            }
            if (this->selected_Fighter > 2)
            {
                this->selected_Fighter = 2;
            }
        }
        if (this->selected == 2)
        { //Gamemode
            if (event.key.code == sf::Keyboard::Left)
            {
                this->selected_Gamemode -= 1;
            }
            if (event.key.code == sf::Keyboard::Right)
            {
                this->selected_Gamemode += 1;
            }
            if (this->selected_Gamemode < 0)
            {
                this->selected_Gamemode = 0;
            }
            if (this->selected_Gamemode > 2)
            {
                this->selected_Gamemode = 2;
            }
        }


        if (event.key.code == machine.keybindMap->find("select")->second.second)
        {
            if (this->selected == 3)
            { //Start
                if (this->selected_Gamemode == 0)
                {
                    machine.setState(new StateGameMode1);
                    return;

                }
                else if (this->selected_Gamemode == 1)
                {
                    machine.setState(new StateGameMode2);
                    return;

                }
                else if (this->selected_Gamemode == 2)
                {
                    machine.setState(new StateSettings);
                    return;
                }
            }

            if (this->selected == 4)
            { //Back
                machine.setState(new StateMainMenu);
                return;
            }
        }
    }
}

void StatePlayConfig::reinitialize(sf::RenderWindow *window) {

}
