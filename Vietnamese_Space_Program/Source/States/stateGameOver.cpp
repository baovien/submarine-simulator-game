#include "../../Include/States/stateGameOver.h"
#include "../../Include/States/stateGameMode1.h"
#include "../../Include/States/stateMainMenu.h"

#include <cstring>

//funksjon for å sortere vector i descending order.
bool SortDescending(const std::pair<int, std::string> &a, const std::pair<int, std::string> &b) {
    return (a.first > b.first);
}

/**
 * Init settingsState.
 * @param window
 */
void StateGameOver::initialize(sf::RenderWindow *window) {

    sf::View newView(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
    window->setView(newView);

    this->selected = 1;
    this->showCursor = false;
    this->highscoreOrNAH = false;
    this->boxIsClicked = false;

    this->bgTexture = new sf::Texture();
    this->bgTexture->loadFromFile("Graphics/Sprites/background12.png");

    this->background = new sf::Sprite();
    this->background->setTexture(*this->bgTexture);

    this->textBox = new sf::RectangleShape();
    this->textBox->setFillColor(sf::Color(128, 128, 128, 255));
    this->textBox->setOutlineColor(sf::Color::Black);
    this->textBox->setOutlineThickness(2);
    this->textBox->setSize(sf::Vector2f(600, 125));
    this->textBox->setPosition(window->getSize().x / 2, window->getSize().y / 1.7f);
    this->textBox->setOrigin(this->textBox->getLocalBounds().width / 2, this->textBox->getLocalBounds().height / 2);

    this->gameOverScore = machine.getGameOverScore();
    this->gameOverText = util.addText("Game Over", 75, 2, 2, window->getSize().x / 2,
                                      (window->getSize().y / 2 - this->background->getGlobalBounds().height / 2.25f),
                                      window, machine.settingPointer->selectedLanguage);

    this->score = util.addText("Score: " + std::to_string(this->gameOverScore), 50, 2, 2, window->getSize().x / 2,
                               this->gameOverText->getGlobalBounds().height * 2,
                               window, machine.settingPointer->selectedLanguage);

    this->text = util.addText(playerName, 75, 2, 2, window->getSize().x / 2,
                              window->getSize().y / 1.95f, window, machine.settingPointer->selectedLanguage);

    this->clickToActivate = util.addText("Click to type", 75, 2, 2, window->getSize().x / 2,
                                         window->getSize().y / 1.82f, window, machine.settingPointer->selectedLanguage);

    this->congratulationsText = util.addText("Congratulations, after your striking performance",
                                             30, 2, 2, window->getSize().x / 2,
                                             this->score->getPosition().y * 1.75f,
                                             window, machine.settingPointer->selectedLanguage);
    this->congratulationsText->setOrigin(this->congratulationsText->getLocalBounds().width / 2, 0);

    this->congratulationsText2 = util.addText("you have been placed on the leaderboard",
                                              30, 2, 2, window->getSize().x / 2,
                                              this->congratulationsText->getPosition().y +
                                              this->congratulationsText->getGlobalBounds().height,
                                              window, machine.settingPointer->selectedLanguage);
    this->congratulationsText2->setOrigin(this->congratulationsText2->getLocalBounds().width / 2, 0);

    this->whatAShameText = util.addText(
            "You did not manage to enter the leaderboard this time\nmaybe you will next time. Good luck!",
            40, 2, 2, window->getSize().x / 2,
            this->score->getPosition().y * 2,
            window, machine.settingPointer->selectedLanguage);
    this->whatAShameText->setOrigin(this->whatAShameText->getLocalBounds().width / 2, 0);


    //loader alle knapper og versjoner av knapper. Finnes 3 versjoner av hver (vanlig, mouseover og clicked).
    //Ganger med 3 fordi jeg kun vil få hver 3. knapp
    for (unsigned int i = 0; i < sizeof(menuTextures) / sizeof(*menuTextures); ++i) {
        menuTextures[i].buttonMouseOver = new sf::Texture();
        menuTextures[i].buttonMouseOver->loadFromFile(
                "Graphics/Sprites/GameOver_buttons/Btn" + std::to_string(i * 3) + ".png");

        menuTextures[i].buttonNormal = new sf::Texture();
        menuTextures[i].buttonNormal->loadFromFile(
                "Graphics/Sprites/GameOver_buttons/Btn" + std::to_string(i * 3 + 1) + ".png");

        menuTextures[i].buttonClicked = new sf::Texture();
        menuTextures[i].buttonClicked->loadFromFile(
                "Graphics/Sprites/GameOver_buttons/Btn" + std::to_string(i * 3 + 2) + ".png");

        menuButtons[i] = new sf::Sprite();
        menuButtons[i]->setTexture(*this->menuTextures[i].buttonNormal);
        menuButtons[i]->setOrigin(menuButtons[i]->getGlobalBounds().width / 2,
                                  menuButtons[i]->getGlobalBounds().height / 2);
    }

    //Setter posisjonen og skalinga til RESTART-button
    menuButtons[0]->scale(window->getSize().x / 1536.0f, window->getSize().y / 864.0f);
    menuButtons[0]->setPosition(window->getSize().x / 2, window->getSize().y / 1.2f);

    //Setter posisjonen og skalinga til BACK-button
    menuButtons[1]->scale(window->getSize().x / 5120.f, window->getSize().y / 2880.f);
    menuButtons[1]->setPosition(window->getSize().x * 0.95f, window->getSize().y - window->getSize().y / 10);

    util.makeMuteButton(window, machine.mutedPointer);
}

/**
 * Update on keyevent, navigation through settings
 * @param window
 */
void StateGameOver::update(sf::RenderWindow *window) {
    //Sjekker mouseover for hver knapp og endrer texture om den er mouseovera eller trykket
    util.checkMuteMouseOver(window);
    for (unsigned int i = 0; i < (sizeof(menuTextures) / sizeof(*menuTextures)); ++i) {
        if (util.checkMouseover(menuButtons[i], window)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                menuButtons[i]->setTexture(*this->menuTextures[i].buttonClicked);
            } else {
                menuButtons[i]->setTexture(*this->menuTextures[i].buttonMouseOver);
            }
        } else {
            menuButtons[i]->setTexture(*this->menuTextures[i].buttonNormal);
        }
    }
}


/**
 *
 * @param window
 */
void StateGameOver::render(sf::RenderWindow *window) {
    this->gameOverText->setFillColor(sf::Color::White);
    this->score->setFillColor(sf::Color::White);
    this->text->setFillColor(sf::Color::White);
    this->clickToActivate->setFillColor(sf::Color(255, 255, 255, 225));

    window->draw(*this->background);
    window->draw(*this->score);

    //Itererer gjennom vektoren for å sjekke om scoren spilleren fikk er høyere enn noen av highscoresa
    //Forskjellige ting drawes utifra om spilleren har fått highscore eller ikke
    for (int i = 0; i < machine.arcadeScorePointer->size(); i++) {
        if (gameOverScore > machine.arcadeScorePointer->at(i).first) {
            this->highscoreOrNAH = true;
            this->congratulationsText->setFillColor(sf::Color::White);
            this->congratulationsText2->setFillColor(sf::Color::White);
            window->draw(*this->congratulationsText);
            window->draw(*this->congratulationsText2);
            window->draw(*this->textBox);
            window->draw(*this->clickToActivate);
        }
        if (!this->highscoreOrNAH) {
            this->whatAShameText->setFillColor(sf::Color::White);
            window->draw(*this->whatAShameText);
        }
    }
    for (unsigned int i = 0; i < (sizeof(menuTextures) / sizeof(*menuTextures)); ++i) {
        window->draw(*this->menuButtons[i]);
    }
    window->draw(*util.getMuteButton());
    window->draw(*this->gameOverText);
    window->draw(*this->text);
}

void StateGameOver::destroy(sf::RenderWindow *window) {
    //Destroyer i motsatt rekkefølge av draws
    for (int i = (sizeof(menuTextures) / sizeof(*menuTextures)) - 1; i >= 0; --i) {
        delete this->menuButtons[i];
    }
    delete this->gameOverText;
    delete this->score;
    delete this->text;
    delete this->congratulationsText;
    delete this->congratulationsText2;
    delete this->whatAShameText;
    delete this->clickToActivate;
    delete this->background;
}

void StateGameOver::handleEvent(sf::RenderWindow *window, sf::Event event) {
    if (event.type == event.KeyPressed) {
        //Back on escapekey
        if (event.key.code == machine.keybindMap.find("back")->second.second) {
            //Gir spilleren en default name = "Player" når spilleren går vekk fra gameoverscreen uten å skrive inn navn
            if (this->playerName == "") {
                this->playerName = "Player";
            }

            //Bytter ut det siste objektet i listen med det nye
            machine.arcadeScorePointer->pop_back();
            machine.arcadeScorePointer->push_back(make_pair(this->gameOverScore, this->playerName));

            //Sorterer vektoren i synkende rekkefølge.
            std::sort(machine.arcadeScorePointer->begin(),
                      machine.arcadeScorePointer->end(),
                      SortDescending);

            for(int i = 0; i < machine.arcadeScorePointer->size(); i++){
                std::cout << i+1 << ". place: " << machine.arcadeScorePointer->at(i).second
                          << ", " << machine.arcadeScorePointer->at(i).first << std::endl;
            }
            machine.setState(new StateMainMenu);
        }
    }
    /*
    if(elapsedTimeCursor.asMicroseconds() > 1000000) { //hvert sekunder
        std::cout << elapsedTimeCursor.asMicroseconds() << std::endl;
        clock.restart();
        showCursor = !showCursor;
        if(showCursor){
            this->text->setString("hello world_");
        } else
            this->text->setString("hello world");
    }
     */
    if (highscoreOrNAH && boxIsClicked) {
        this->textBox->setFillColor(sf::Color::White);
        this->clickToActivate = util.addText("", 75, 2, 2, window->getSize().x / 2,
                                             window->getSize().y / 1.82f, window,
                                             machine.settingPointer->selectedLanguage);

        //Sjekker om brukeren skriver noe i tekstfeltet, det som blir skrevet i tekstfeltet dukker opp på skjermen
        if (event.type == event.TextEntered) {
            if (event.text.unicode == '\b' && playerName.size() > 0) {
                playerName = playerName.erase(playerName.size() - 1, -1);
                this->text->setString(playerName);
                this->text->setOrigin(this->text->getLocalBounds().width / 2, 0);

            } else if (event.text.unicode == '\b' && playerName.size() == 0) {
                playerName = "";
                this->text->setString(playerName);

            } else if (event.text.unicode < 128 && playerName.size() <= 10) {
                playerName += static_cast<char>(event.text.unicode);
                this->text->setString(playerName);
                this->text->setOrigin(this->text->getLocalBounds().width / 2, 0);
            }
        }
    }
    if (event.type == sf::Event::MouseButtonPressed) {  //Sjekker om spilleren trykker inni boksen slik at tekstfeltet blir aktivert
        if ((event.mouseButton.button == sf::Mouse::Button::Left) &&
            (sf::Mouse::getPosition(*window).x > (this->textBox->getPosition().x - this->textBox->getSize().x / 2)) &&
            (sf::Mouse::getPosition(*window).x < (this->textBox->getPosition().x + this->textBox->getSize().x / 2)) &&
            (sf::Mouse::getPosition(*window).y > (this->textBox->getPosition().y - this->textBox->getSize().y / 2)) &&
            (sf::Mouse::getPosition(*window).y < (this->textBox->getPosition().y + this->textBox->getSize().y / 2))) {
            this->boxIsClicked = true;
        }
    }

    if (event.type == sf::Event::MouseButtonReleased) {
        util.checkMuteMouseClick(window, event, machine.mutedPointer);

        for (unsigned int i = 0; i < (sizeof(menuTextures) / sizeof(*menuTextures)); ++i)
            if (util.checkMouseclick(menuButtons[i], event)) {
                switch (i) {
                    case 0: //restart knappen er trykket
                        //Gir spilleren en default name = "Player" når spilleren går vekk fra gameoverscreen uten å skrive inn navn
                        if (this->playerName == "") {
                            this->playerName = "Player";
                        }

                        //Bytter ut det siste objektet i listen med det nye
                        machine.arcadeScorePointer->pop_back();
                        machine.arcadeScorePointer->push_back(make_pair(this->gameOverScore, this->playerName));

                        //Sorterer vektoren i synkende rekkefølge.
                        std::sort(machine.arcadeScorePointer->begin(),
                                  machine.arcadeScorePointer->end(),
                                  SortDescending);

                        for(int i = 0; i < machine.arcadeScorePointer->size(); i++){
                            std::cout << i+1 << ". place: " << machine.arcadeScorePointer->at(i).second
                                      << ", " << machine.arcadeScorePointer->at(i).first << std::endl;
                        }

                        machine.setState(new StateGameMode1());
                        return;
                    case 1: //return knappen er trykket
                        //Gir spilleren en default name = "Player" når spilleren går vekk fra gameoverscreen uten å skrive inn navn
                        if (this->playerName == "") {
                            this->playerName = "Player";
                        }

                        //Bytter ut det siste objektet i listen med det nye
                        machine.arcadeScorePointer->pop_back();
                        machine.arcadeScorePointer->push_back(make_pair(this->gameOverScore, this->playerName));

                        //Sorterer vektoren i synkende rekkefølge.
                        std::sort(machine.arcadeScorePointer->begin(),
                                  machine.arcadeScorePointer->end(),
                                  SortDescending);

                        for(int i = 0; i < machine.arcadeScorePointer->size(); i++){
                            std::cout << i+1 << ". place: " << machine.arcadeScorePointer->at(i).second
                                      << ", " << machine.arcadeScorePointer->at(i).first << std::endl;
                        }

                        machine.setState(new StateMainMenu());
                        return;
                }
            }
    }
}

void StateGameOver::reinitialize(sf::RenderWindow *window) {

}
