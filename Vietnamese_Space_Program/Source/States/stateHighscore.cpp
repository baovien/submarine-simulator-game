#include <iostream>
#include "../../Include/States/stateHighscore.h"
#include "../../Include/States/stateGameMode1.h"
#include "../../Include/States/stateMainMenu.h"


void StateHighscore::initialize(sf::RenderWindow *window) {
    //Resetter view
    sf::View newView(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
    window->setView(newView);

    this->bgTexture = new sf::Texture();
    this->bgTexture->loadFromFile("Graphics/Sprites/bakgrunn.png");

    this->background = new sf::Sprite();
    this->background->setTexture(*this->bgTexture);
    this->background->scale(window->getSize().x / background->getGlobalBounds().width, window->getSize().y / background->getGlobalBounds().height);

    this->tableTexture = new sf::Texture();
    this->tableTexture->loadFromFile("Graphics/Sprites/gautesTable.png");

    //Plassering og konfigurasjon av Arcade-tabell
    TableArcade = new sf::Sprite();
    TableArcade->setTexture(*this->tableTexture);
    TableArcade->setOrigin(TableArcade->getGlobalBounds().width / 2, TableArcade->getGlobalBounds().height / 2);
    TableArcade->setScale(window->getSize().x / 1408.0f, window->getSize().y / 792.0f);
    TableArcade->setPosition(window->getSize().x / 2, window->getSize().y / 2.5f);

    //Plassering og konfigurasjon av Classic-tabell
    TableClassic = new sf::Sprite();
    TableClassic->setTexture(*this->tableTexture);
    TableClassic->setOrigin(TableClassic->getGlobalBounds().width / 2, TableClassic->getGlobalBounds().height / 2);
    TableClassic->setScale(window->getSize().x / 1408.0f, window->getSize().y / 792.0f);
    TableClassic->setPosition(window->getSize().x / 2, window->getSize().y / 1.2f);

    //Legger til tekster
    this->title = util.addText("HIGHSCORE", 75, 2, 2, window->getSize().x / 2.0f, window->getSize().y / 24.0f, window, machine.settingPointer->selectedLanguage);
    this->titleArcade = util.addText("ARCADE", 40, 2, 2, window->getSize().x / 2.0f, window->getSize().y / 6.0f, window, machine.settingPointer->selectedLanguage);
    this->titleClassic = util.addText("CLASSIC", 40, 2, 2, window->getSize().x / 2.0f, window->getSize().y / 1.67f, window, machine.settingPointer->selectedLanguage);

    //Loader de tre versjonene av backknapper
    backTexture.buttonMouseOver = new sf::Texture();
    backTexture.buttonMouseOver->loadFromFile("Graphics/Sprites/PlayConfig_buttons/Btn3.png");
    backTexture.buttonNormal = new sf::Texture();
    backTexture.buttonNormal->loadFromFile("Graphics/Sprites/PlayConfig_buttons/Btn4.png");
    backTexture.buttonClicked = new sf::Texture();
    backTexture.buttonClicked->loadFromFile("Graphics/Sprites/PlayConfig_buttons/Btn5.png");
    //Lager backknappen
    backButton = new sf::Sprite();
    backButton->setTexture(*this->backTexture.buttonNormal);
    backButton->setOrigin(backButton->getGlobalBounds().width / 2, backButton->getGlobalBounds().height / 2);
    backButton->scale(window->getSize().x / 5120.f, window->getSize().y / 2880.f);
    backButton->setPosition(window->getSize().x * 0.95f, window->getSize().y - window->getSize().y / 10);

    //Lager muteknappen
    util.makeMuteButton(window, machine.mutedPointer);

    //Lager en vector som inneholder alle tekster
    for (int i = 0; i < 8; ++i) {
        if (i == 0 || i == 4) {
            highscoreValues.push_back(std::make_tuple("#", "Player", "Score"));
        } else if (i < 4) {
            highscoreValues.push_back(std::make_tuple(std::to_string(i), machine.arcadeScorePointer->at(i - 1).second, std::to_string(machine.arcadeScorePointer->at(i - 1).first)));
        } else {
            highscoreValues.push_back(std::make_tuple(std::to_string(i),machine.classicScorePointer->at(i - 5).second, std::to_string(machine.classicScorePointer->at(i - 5).first)));
        }
    }
    //Lager sf::Text til alle tekstene, plasserer de og alt
    for (int i = 0; i < 8; ++i) {
            if (i < 4) {
                tableText.push_back(*util.addText(std::get<0>(highscoreValues.at(i)), 30, 0, 0, window->getSize().x / 4.1f, window->getSize().y / 3.9f + (i) * window->getSize().y / 17.25f, window, machine.settingPointer->selectedLanguage));
                tableText.push_back(*util.addText(std::get<1>(highscoreValues.at(i)), 30, 0, 0, window->getSize().x / 3.6f, (window->getSize().y / 3.9f)  + (i) * window->getSize().y / 17.25f, window, machine.settingPointer->selectedLanguage));
                tableText.push_back(*util.addText(std::get<2>(highscoreValues.at(i)), 30, 0, 0, window->getSize().x / 1.73f, (window->getSize().y / 3.9f) + (i) * window->getSize().y / 17.25f, window, machine.settingPointer->selectedLanguage));
            } else {
                tableText.push_back(*util.addText(std::get<0>(highscoreValues.at(i)), 30, 0, 0, window->getSize().x / 4.1f, window->getSize().y / 1.45f + (i-4) * window->getSize().y / 17.25f, window, machine.settingPointer->selectedLanguage));
                tableText.push_back(*util.addText(std::get<1>(highscoreValues.at(i)), 30, 0, 0, window->getSize().x / 3.6f, window->getSize().y / 1.45f + (i-4) * window->getSize().y / 17.25f, window, machine.settingPointer->selectedLanguage));
                tableText.push_back(*util.addText(std::get<2>(highscoreValues.at(i)), 30, 0, 0, window->getSize().x / 1.73f, window->getSize().y / 1.45f + (i-4) * window->getSize().y / 17.25f, window, machine.settingPointer->selectedLanguage));
            }
    }
}

void StateHighscore::update(sf::RenderWindow *window) {

    util.checkMuteMouseOver(window);


    if (util.checkMouseover(backButton, window)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            backButton->setTexture(*this->backTexture.buttonClicked);
        } else {
            backButton->setTexture(*this->backTexture.buttonMouseOver);
        }
    } else {
        backButton->setTexture(*this->backTexture.buttonNormal);
    }


}

void StateHighscore::render(sf::RenderWindow *window) {

    window->draw(*this->background);
    window->draw(*this->title);
    window->draw(*this->TableArcade);
    window->draw(*this->TableClassic);
    window->draw(*this->titleArcade);
    window->draw(*this->titleClassic);
    window->draw(*this->backButton);
    //Tegner mutebutton fra funkjson i Utilities
    window->draw(*util.getMuteButton());

    for (int i = 0; i < 8 * 3; ++i) {
        window->draw(this->tableText.at(i));
    }


}

void StateHighscore::destroy(sf::RenderWindow *window) {

    delete this->title;
    delete this->TableArcade;
    delete this->TableClassic;
    delete this->background;
    delete this->titleArcade;
    delete this->titleClassic;
    delete this->tableTexture;
    delete this->bgTexture;
}

void StateHighscore::handleEvent(sf::RenderWindow *window, sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        //Back on escapekey
        if (event.key.code == machine.keybindMap.find("back")->second.second) {
            machine.setState(new StateMainMenu);
            return;
        }
    }

    if (event.type == sf::Event::MouseButtonReleased) {
        //Sjekker backknappklikk
        if (util.checkMouseclick(backButton, event)) {
            machine.setState(new StateMainMenu);
            return;
        }
        //Sjekker muteknappklikk
        util.checkMuteMouseClick(window, event, machine.mutedPointer);
    }

}

void StateHighscore::reinitialize(sf::RenderWindow *window) {
    initialize(window);
}

