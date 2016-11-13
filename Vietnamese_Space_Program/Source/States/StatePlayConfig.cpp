
#include <cstring>
#include "../../Include/States/StatePlayConfig.h"
#include "../../Include/States/StateGameMode1.h"
#include "../../Include/States/StateMainMenu.h"
#include "../../Include/States/StateGameMode2.h"
#include "../../Include/States/StateSettings.h"


void StatePlayConfig::initialize(sf::RenderWindow *window) {

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
    this->font->loadFromFile("graphics/font1.otf");

/**
 * HOVEDVALGENE.
 * VELG MELLOM DE FORSKJELLIGE THEMENE, FIGHTERENE OG GAMEMODENE
 */

    this->theme = new sf::Text("Select theme", *this->font, textSize + 10);
    this->theme->setOrigin(this->theme->getGlobalBounds().width / 2, this->theme->getGlobalBounds().height);
    this->theme->setPosition(window->getSize().x / 2, window->getSize().y / 25);

    this->fighter = new sf::Text("Select fighter", *this->font, textSize + 10);
    this->fighter->setOrigin(this->fighter->getGlobalBounds().width / 2, this->theme->getGlobalBounds().height);
    this->fighter->setPosition(window->getSize().x / 2, window->getSize().y / 25 + this->theme->getGlobalBounds().height * 8);

    this->gamemode = new sf::Text("Select gamemode", *this->font, textSize + 10);
    this->gamemode->setOrigin(this->gamemode->getGlobalBounds().width / 2, this->theme->getGlobalBounds().height);
    this->gamemode->setPosition(window->getSize().x / 2, window->getSize().y / 25 + this->theme->getGlobalBounds().height * 16);

/**
 * THEME PLASSERING.
 * UNDER HER PLASSERES DE FORSKJELLIGE THEMES.
 */

    this->theme_1 = new sf::Text("THEME 1", *this->font, textSize);
    this->theme_1->setOrigin(this->theme_1->getGlobalBounds().width / 2, this->theme->getGlobalBounds().height);
    this->theme_1->setPosition(window->getSize().x / 3, window->getSize().y / 25 + this->theme->getGlobalBounds().height * 4);

    this->theme_2 = new sf::Text("THEME 2", *this->font, textSize);
    this->theme_2->setOrigin(this->theme_2->getGlobalBounds().width / 2, this->theme->getGlobalBounds().height);
    this->theme_2->setPosition(window->getSize().x / 2, window->getSize().y / 25 + this->theme->getGlobalBounds().height * 4);

    this->theme_3 = new sf::Text("THEME 3", *this->font, textSize);
    this->theme_3->setOrigin(this->theme_2->getGlobalBounds().width / 2, this->theme->getGlobalBounds().height);
    this->theme_3->setPosition(window->getSize().x / 1.5F, window->getSize().y / 25 + this->theme->getGlobalBounds().height * 4);

/**
 * FIGHTER PLASSERING.
 * UNDER HER PLASSERES DE FORSKJELLIGE FIGHTERENE.
 */

    this->fighter_1 = new sf::Text("FIGHTER 1", *this->font, textSize);
    this->fighter_1->setOrigin(this->fighter_1->getGlobalBounds().width / 2, this->theme->getGlobalBounds().height);
    this->fighter_1->setPosition(window->getSize().x / 3, window->getSize().y / 25 + this->fighter->getGlobalBounds().height * 12);

    this->fighter_2 = new sf::Text("FIGHTER 2", *this->font, textSize);
    this->fighter_2->setOrigin(this->fighter_2->getGlobalBounds().width / 2, this->theme->getGlobalBounds().height);
    this->fighter_2->setPosition(window->getSize().x / 2, window->getSize().y / 25 + this->fighter->getGlobalBounds().height * 12);

    this->fighter_3 = new sf::Text("FIGHTER 3", *this->font, textSize);
    this->fighter_3->setOrigin(this->fighter_3->getGlobalBounds().width / 2, this->theme->getGlobalBounds().height);
    this->fighter_3->setPosition(window->getSize().x / 1.5F, window->getSize().y / 25 + this->fighter->getGlobalBounds().height * 12);

/**
 * GAMEMODE PLASSERING.
 * UNDER HER PLASSERES DE FORSKJELLIGE GAMEMODENE.
 */
    this->gamemode_1 = new sf::Text("MODE 1", *this->font, textSize);
    this->gamemode_1->setOrigin(this->fighter_1->getGlobalBounds().width / 2, this->theme->getGlobalBounds().height);
    this->gamemode_1->setPosition(window->getSize().x / 3, window->getSize().y / 25 + this->fighter->getGlobalBounds().height * 20);

    this->gamemode_2 = new sf::Text("MODE 2", *this->font, textSize);
    this->gamemode_2->setOrigin(this->fighter_2->getGlobalBounds().width / 2, this->theme->getGlobalBounds().height);
    this->gamemode_2->setPosition(window->getSize().x / 2, window->getSize().y / 25 + this->fighter->getGlobalBounds().height * 20);

    this->gamemode_3 = new sf::Text("MODE 3", *this->font, textSize);
    this->gamemode_3->setOrigin(this->fighter_3->getGlobalBounds().width / 2, this->theme->getGlobalBounds().height);
    this->gamemode_3->setPosition(window->getSize().x / 1.5F, window->getSize().y / 25 + this->fighter->getGlobalBounds().height * 20);


    this->play = new sf::Text("Start", *this->font, textSize + 10);
    this->play->setOrigin(this->play->getGlobalBounds().width / 2, this->theme->getGlobalBounds().height);
    this->play->setPosition(window->getSize().x / 3, window->getSize().y / 25 + this->theme->getGlobalBounds().height * 25);

    this->back = new sf::Text("Back", *this->font, textSize + 10);
    this->back->setOrigin(this->back->getGlobalBounds().width / 2, this->theme->getGlobalBounds().height);
    this->back->setPosition(window->getSize().x / 1.5F, window->getSize().y / 25 + this->theme->getGlobalBounds().height * 25);

}

void StatePlayConfig::update(sf::RenderWindow *window) {
    if (this->selected > 4) {
        this->selected = 0;
    }

    if (this->selected < 0) {
        this->selected = 4;
    }
}

void StatePlayConfig::render(sf::RenderWindow *window) {
    this->theme->setFillColor(sf::Color::White);
    this->fighter->setFillColor(sf::Color::White);
    this->gamemode->setFillColor(sf::Color::White);
    this->play->setFillColor(sf::Color::White);
    this->back->setFillColor(sf::Color::White);

    this->theme->setStyle(0);
    this->fighter->setStyle(0);
    this->gamemode->setStyle(0);
    this->play->setStyle(0);
    this->back->setStyle(0);

    switch (this->selected) {
        case 0:
            this->theme_1->setFillColor(sf::Color::White);
            this->theme_2->setFillColor(sf::Color::White);
            this->theme_3->setFillColor(sf::Color::White);

            this->theme->setFillColor(sf::Color::Magenta);
            if (this->selected_Theme == 0) {
                this->theme_1->setFillColor(sf::Color::Yellow);
            }
            if (this->selected_Theme == 1) {
                this->theme_2->setFillColor(sf::Color::Yellow);
            }
            if (this->selected_Theme == 2) {
                this->theme_3->setFillColor(sf::Color::Yellow);
            }
            break;
        case 1:
            this->fighter_1->setFillColor(sf::Color::White);
            this->fighter_2->setFillColor(sf::Color::White);
            this->fighter_3->setFillColor(sf::Color::White);

            this->fighter->setFillColor(sf::Color::Magenta);
            if (this->selected_Fighter == 0) {
                this->fighter_1->setFillColor(sf::Color::Yellow);
            }
            if (this->selected_Fighter == 1) {
                this->fighter_2->setFillColor(sf::Color::Yellow);
            }
            if (this->selected_Fighter == 2) {
                this->fighter_3->setFillColor(sf::Color::Yellow);
            }
            break;
        case 2:
            this->gamemode_1->setFillColor(sf::Color::White);
            this->gamemode_2->setFillColor(sf::Color::White);
            this->gamemode_3->setFillColor(sf::Color::White);

            this->gamemode->setFillColor(sf::Color::Magenta);
            if (this->selected_Gamemode == 0) {
                this->gamemode_1->setFillColor(sf::Color::Yellow);
            }
            if (this->selected_Gamemode == 1) {
                this->gamemode_2->setFillColor(sf::Color::Yellow);
            }
            if (this->selected_Gamemode == 2) {
                this->gamemode_3->setFillColor(sf::Color::Yellow);
            }
            break;
        case 3:
            this->play->setFillColor(sf::Color::Magenta);
            break;
        case 4:
            this->back->setFillColor(sf::Color::Magenta);
            break;
    }

    window->draw(*this->background);

    window->draw(*this->theme);
    window->draw(*this->fighter);
    window->draw(*this->gamemode);
    window->draw(*this->play);
    window->draw(*this->back);

    window->draw(*this->theme_1);
    window->draw(*this->theme_2);
    window->draw(*this->theme_3);

    window->draw(*this->fighter_1);
    window->draw(*this->fighter_2);
    window->draw(*this->fighter_3);

    window->draw(*this->gamemode_1);
    window->draw(*this->gamemode_2);
    window->draw(*this->gamemode_3);

}

void StatePlayConfig::destroy(sf::RenderWindow *window) {
    delete this->theme;
    delete this->font;
    delete this->fighter;
    delete this->gamemode;
    delete this->play;
    delete this->back;

    delete this->theme_1;
    delete this->theme_2;
    delete this->theme_3;

    delete this->fighter_1;
    delete this->fighter_2;
    delete this->fighter_3;

    delete this->gamemode_1;
    delete this->gamemode_2;
    delete this->gamemode_3;

    delete this->background;

}

void StatePlayConfig::handleEvent(sf::RenderWindow *window, sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        // Trykk Escape for å komme til mainmenu
        if (event.key.code == machine.keybindMap.find("back")->second.second) {
            machine.setState(new StateMainMenu);
        }

        if (selected == 0) { // Ikke mulig a gå opp når du velger theme
            if (event.key.code == sf::Keyboard::Up) {
                this->selected = 0;
            }
        }
        if (selected != 4) {
            if (event.key.code == sf::Keyboard::Up) {
                this->selected -= 1;
            }
        }
        if (this->selected < 3) {
            if (event.key.code == sf::Keyboard::Down) {
                this->selected += 1;
            }
        }
        if (this->selected == 3) { // Start
            if (event.key.code == sf::Keyboard::Right) {
                this->selected += 1;
            }
        }
        if (this->selected == 4) { // Back
            if (event.key.code == sf::Keyboard::Left) {
                this->selected -= 1;
            }
            if (event.key.code == sf::Keyboard::Up) {
                this->selected = 2;
            }

        }
        if (this->selected == 0) { //Theme
            if (event.key.code == sf::Keyboard::Left) {
                this->selected_Theme -= 1;
            }
            if (event.key.code == sf::Keyboard::Right) {
                this->selected_Theme += 1;
            }
            if (this->selected_Theme > 2) {
                this->selected_Theme = 2;
            }
            if (this->selected_Theme < 0) {
                this->selected_Theme = 0;
            }
        }

        if (this->selected == 1) { //Fighter
            if (event.key.code == sf::Keyboard::Left) {
                this->selected_Fighter -= 1;
            }
            if (event.key.code == sf::Keyboard::Right) {
                this->selected_Fighter += 1;
            }
            if (this->selected_Fighter < 0) {
                this->selected_Fighter = 0;
            }
            if (this->selected_Fighter > 2) {
                this->selected_Fighter = 2;
            }
        }
        if (this->selected == 2) { //Gamemode
            if (event.key.code == sf::Keyboard::Left) {
                this->selected_Gamemode -= 1;
            }
            if (event.key.code == sf::Keyboard::Right) {
                this->selected_Gamemode += 1;
            }
            if (this->selected_Gamemode < 0) {
                this->selected_Gamemode = 0;
            }
            if (this->selected_Gamemode > 2) {
                this->selected_Gamemode = 2;
            }
        }


        if (event.key.code == machine.keybindMap.find("select")->second.second) {
            if (this->selected == 3) { //Start
                if (this->selected_Gamemode == 0) {
                    machine.setState(new StateGameMode1);
                    return;
                } else if (this->selected_Gamemode == 1) {
                    machine.setState(new StateGameMode2);
                    return;
                } else if (this->selected_Gamemode == 2) {
                    machine.setState(new StateSettings);
                    return;
                }
            }
            if (this->selected == 4) { //Back
                machine.setState(new StateMainMenu);
                return;
            }
        }
    }
}

void StatePlayConfig::reinitialize(sf::RenderWindow *window) {

}
