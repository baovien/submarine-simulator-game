#include <iostream>
#include "../../Header Files/States/stateMainMenu.h"
#include "../../Header Files/States/StateHighscore.h"
#include "../../Header Files/States/statePlayConfig.h"
#include "../../Header Files/States/stateSettings.h"
#include "../../Header Files/States/stateGameOver.h"

void stateMainMenu::initialize(sf::RenderWindow *window) {

    sf::View newView( sf::FloatRect( 0, 0, window->getSize().x, window->getSize().y ) );
    window->setView(newView);

    memset(machine.keyPressed, 0, sizeof(machine.keyPressed)); //For at tastetrykk gjort i andre states ikke skal beholdes
    machine.mouseClick = {-1,-1};

    this->bgTexture = new sf::Texture();
    this->bgTexture->loadFromFile("Graphics/Sprites/bg_purple.png");

    this->background = new sf::Sprite();
    this->background->setTexture(*this->bgTexture);
    this->background->scale(window->getSize().x/background->getGlobalBounds().width,window->getSize().y/background->getGlobalBounds().height);

    this->selected = 0;

    this->font = new sf::Font();
    this->font->loadFromFile("Graphics/font1.otf");

    this->title = new sf::Text("SPACE", *this->font, textSize+30);
    this->title->setOrigin(this->title->getGlobalBounds().width / 2, this->title->getGlobalBounds().height / 2);
    this->title->setPosition(window->getSize().x / 2, window->getSize().y / 4);
    this->menuTexts.push_back(this->title);

    this->title2 = new sf::Text("SIMULATOR", *this->font, textSize+30);
    this->title2->setOrigin(this->title2->getGlobalBounds().width / 2, this->title2->getGlobalBounds().height / 2);
    this->title2->setPosition(window->getSize().x / 2, window->getSize().y / 4 + this->title2->getGlobalBounds().height);
    this->menuTexts.push_back(this->title2);

    this->play = new sf::Text("Play", *this->font, textSize);
    this->play->setOrigin(this->play->getGlobalBounds().width / 2, this->play->getGlobalBounds().height / 2);
    this->play->setPosition(window->getSize().x / 2, window->getSize().y / 2);
    this->menuTexts.push_back(this->play);

    this->highscore = new sf::Text("Highscore", *this->font, textSize);
    this->highscore->setOrigin(this->highscore->getGlobalBounds().width / 2, this->highscore->getGlobalBounds().height / 2);
    this->highscore->setPosition(window->getSize().x / 2, window->getSize().y /2 + this->highscore->getGlobalBounds().height*1.5);
    this->menuTexts.push_back(this->highscore);

    this->options = new sf::Text("Options", *this->font, textSize);
    this->options->setOrigin(this->options->getGlobalBounds().width / 2, this->options->getGlobalBounds().height / 2);
    this->options->setPosition(window->getSize().x / 2, window->getSize().y /2 + this->options->getGlobalBounds().height*3);
    this->menuTexts.push_back(this->options);

    this->quit = new sf::Text("Exit", *this->font, textSize);
    this->quit->setOrigin(this->quit->getGlobalBounds().width / 2, this->quit->getGlobalBounds().height / 2);
    this->quit->setPosition(window->getSize().x / 2, window->getSize().y /2 + this->quit->getGlobalBounds().height*4.5);
    this->menuTexts.push_back(this->quit);

}

void stateMainMenu::update(sf::RenderWindow *window) {
    //Vertical selection
    if (machine.keyPressed[sf::Keyboard::Up]) {
        this->selected -= 1;
        memset(machine.keyPressed, 0, sizeof(machine.keyPressed));
    }

    if (machine.keyPressed[sf::Keyboard::Down]) {
        this->selected += 1;
        memset(machine.keyPressed, 0, sizeof(machine.keyPressed));
    }

    //Midlertidig// Testing purposes
    if (machine.keyPressed[sf::Keyboard::M]) {
        memset(machine.keyPressed, 0, sizeof(machine.keyPressed));
        machine.setState(new stateGameOver);
        return;
    }

    //Vertical selection bounds
    if (this->selected > 3) {
        this->selected = 0;
    }

    if (this->selected < 0) {
        this->selected = 3;
    }
    //Stateswitch on enter
    if (machine.keyPressed[sf::Keyboard::Return]) {
        memset(machine.keyPressed, 0, sizeof(machine.keyPressed));
        switch (this->selected) {
            case 0: //Play
                machine.setState(new statePlayConfig);
                return;
            case 1: //Highscore
                machine.setState(new StateHighscore);
                return;
            case 2: //Options
                machine.setState(new stateSettings);
                return;
            case 3: //Exit
                quitGame = true;
                break;
        }
    }

    if (sf::Mouse::getPosition(*window).x + play->getGlobalBounds().width / 2 > play->getPosition().x &&
        sf::Mouse::getPosition(*window).x - play->getGlobalBounds().width / 2 < play->getPosition().x &&
        sf::Mouse::getPosition(*window).y + play->getGlobalBounds().height / 2 > play->getPosition().y &&
        sf::Mouse::getPosition(*window).y - play->getGlobalBounds().height / 2 < play->getPosition().y) {
        this->selected = 0;

    }
    if (sf::Mouse::getPosition(*window).x + highscore->getGlobalBounds().width / 2 > highscore->getPosition().x &&
        sf::Mouse::getPosition(*window).x - highscore->getGlobalBounds().width / 2 < highscore->getPosition().x &&
        sf::Mouse::getPosition(*window).y + highscore->getGlobalBounds().height / 2 > highscore->getPosition().y &&
        sf::Mouse::getPosition(*window).y - highscore->getGlobalBounds().height / 2 < highscore->getPosition().y) {
        this->selected = 1;
    }
    if (sf::Mouse::getPosition(*window).x + options->getGlobalBounds().width / 2 > options->getPosition().x &&
        sf::Mouse::getPosition(*window).x - options->getGlobalBounds().width / 2 < options->getPosition().x &&
        sf::Mouse::getPosition(*window).y + options->getGlobalBounds().height / 2 > options->getPosition().y &&
        sf::Mouse::getPosition(*window).y - options->getGlobalBounds().height / 2 < options->getPosition().y) {
        this->selected = 2;

    }
    if (sf::Mouse::getPosition(*window).x + quit->getGlobalBounds().width / 2 > quit->getPosition().x &&
        sf::Mouse::getPosition(*window).x - quit->getGlobalBounds().width / 2 < quit->getPosition().x &&
        sf::Mouse::getPosition(*window).y + quit->getGlobalBounds().height / 2 > quit->getPosition().y &&
        sf::Mouse::getPosition(*window).y - quit->getGlobalBounds().height / 2 < quit->getPosition().y) {
        this->selected = 3;
    }

    if (machine.mouseClick.x + play->getGlobalBounds().width / 2 > play->getPosition().x &&
        machine.mouseClick.x - play->getGlobalBounds().width / 2 < play->getPosition().x &&
        machine.mouseClick.y + play->getGlobalBounds().height / 2 > play->getPosition().y &&
        machine.mouseClick.y - play->getGlobalBounds().height / 2 < play->getPosition().y) {
        //Play
        machine.mouseClick = {-1, -1};
        machine.setState(new statePlayConfig);
        return;
    }
    if (machine.mouseClick.x + highscore->getGlobalBounds().width / 2 > highscore->getPosition().x &&
        machine.mouseClick.x - highscore->getGlobalBounds().width / 2 < highscore->getPosition().x &&
        machine.mouseClick.y + highscore->getGlobalBounds().height / 2 > highscore->getPosition().y &&
        machine.mouseClick.y - highscore->getGlobalBounds().height / 2 < highscore->getPosition().y) {
        //highscore
        machine.mouseClick = {-1, -1};
        machine.setState(new StateHighscore);
        return;

    }
    if (machine.mouseClick.x + options->getGlobalBounds().width / 2 > options->getPosition().x &&
        machine.mouseClick.x - options->getGlobalBounds().width / 2 < options->getPosition().x &&
        machine.mouseClick.y + options->getGlobalBounds().height / 2 > options->getPosition().y &&
        machine.mouseClick.y - options->getGlobalBounds().height / 2 < options->getPosition().y) {
        //options
        machine.mouseClick = {-1, -1};
        machine.setState(new stateSettings);
        return;
    }
    if (machine.mouseClick.x + quit->getGlobalBounds().width / 2 > quit->getPosition().x &&
        machine.mouseClick.x - quit->getGlobalBounds().width / 2 < quit->getPosition().x &&
        machine.mouseClick.y + quit->getGlobalBounds().height / 2 > quit->getPosition().y &&
        machine.mouseClick.y - quit->getGlobalBounds().height / 2 < quit->getPosition().y) {
        //exit
        machine.mouseClick = {-1, -1};
        quitGame=true;
        return;
    }
}
void stateMainMenu::render(sf::RenderWindow *window) {

    //NUllstille textstil på alle texts i menutexts
    for(sf::Text* text: menuTexts)
        text->setStyle(0);

    //Setter en strek over valgt text
    menuTexts[selected + 2 ]->setStyle(1<<3);

    //Tegne opp background
    window->draw(*this->background);
    //Tegne opp alle texts i menuTexts
    for(const sf::Text* text: menuTexts)
        window->draw(*text);

}

void stateMainMenu::destroy(sf::RenderWindow *window) {

    std::reverse(menuTexts.begin(), menuTexts.end());
    for(sf::Text* text: menuTexts)
        delete text;
}

