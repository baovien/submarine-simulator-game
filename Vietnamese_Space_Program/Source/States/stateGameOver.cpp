#include "../../Include/States/stateGameOver.h"
#include "../../Include/States/stateGameMode1.h"
#include "../../Include/States/stateMainMenu.h"
#include "../../Include/States/stateGameMode2.h"

#include <cstring>

/**
 * Init settingsState.
 * @param window
 */
void StateGameOver::initialize(sf::RenderWindow *window) {

    sf::View newView(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
    window->setView(newView);

    machine.soundLoaderPointer->stopMusic();
    machine.soundLoaderPointer->playMusic(Audio::Music::GAMEOVER);

    this->highscoreOrNAH = false;
    this->boxIsClicked = false;

    this->bgTexture = new sf::Texture();
    this->bgTexture->loadFromFile("Graphics/Sprites/background12.png");

    this->background = new sf::Sprite();
    this->background->setTexture(*this->bgTexture);
    this->background->scale(window->getSize().x / background->getGlobalBounds().width,
                            window->getSize().y / background->getGlobalBounds().height);

    this->textBox = new sf::RectangleShape();
    this->textBox->setOutlineColor(sf::Color::Black);
    this->textBox->setOutlineThickness(2);
    this->textBox->setSize(sf::Vector2f(600, 125));
    this->textBox->setPosition(window->getSize().x / 2.f, window->getSize().y / 1.7f);
    this->textBox->setOrigin(this->textBox->getLocalBounds().width / 2.f, this->textBox->getLocalBounds().height / 2.f);
    this->textBox->scale(window->getSize().x / 1280.f, window->getSize().y / 720.f);

    this->gameOverScore = machine.getGameOverScore();
    this->gameOverText = util.addText((util.translate("Game Over", machine.settingPointer->selectedLanguage)),
                                      75, 2, 2, window->getSize().x / 2.f,
                                      (window->getSize().y / 24.0f),
                                      window, machine.settingPointer->selectedLanguage);

    this->score = util.addText((util.translate("Score: ", machine.settingPointer->selectedLanguage)) + std::to_string(this->gameOverScore),
                               50, 2, 2, window->getSize().x / 2.f,
                               this->gameOverText->getGlobalBounds().height * 2,
                               window, machine.settingPointer->selectedLanguage);

    this->text = util.addText(playerName, 75, 2, 2, window->getSize().x / 2.f,
                              window->getSize().y / 1.95f, window, machine.settingPointer->selectedLanguage);

    this->clickToActivate = util.addText((util.translate("Player", machine.settingPointer->selectedLanguage)),
                                         75, 2, 2, window->getSize().x / 2.f,
                                         window->getSize().y / 1.86f, window, machine.settingPointer->selectedLanguage);

    this->congratulationsText = util.addText((util.translate("Congratulations, after your striking performance",
                                                             machine.settingPointer->selectedLanguage)),
                                             40, 2, 2, window->getSize().x / 2.f,
                                             window->getSize().y / 3.25f,
                                             window, machine.settingPointer->selectedLanguage);
    this->congratulationsText->setOrigin(this->congratulationsText->getLocalBounds().width / 2.f, 0);

    this->congratulationsText2 = util.addText((util.translate("you have been placed on the leaderboard",
                                                              machine.settingPointer->selectedLanguage)),
                                              40, 2, 2, window->getSize().x / 2.f,
                                              window->getSize().y / 2.7f,
                                              window, machine.settingPointer->selectedLanguage);
    this->congratulationsText2->setOrigin(this->congratulationsText2->getLocalBounds().width / 2.f, 0);

    this->whatAShameText = util.addText(util.translate("You did not manage to enter the leaderboard this time"
                                                               "\nmaybe you will next time. Good luck!",
                                                       machine.settingPointer->selectedLanguage),
                                        40, 2, 2, window->getSize().x / 2.f,
                                        window->getSize().y / 2.7f,
                                        window, machine.settingPointer->selectedLanguage);
    this->whatAShameText->setOrigin(this->whatAShameText->getLocalBounds().width / 2.f, 0);


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
    menuButtons[0]->setPosition(window->getSize().x / 2.f, window->getSize().y / 1.2f);

    //Setter posisjonen og skalinga til BACK-button
    menuButtons[1]->scale(window->getSize().x / 5120.f, window->getSize().y / 2880.f);
    menuButtons[1]->setPosition(window->getSize().x * 0.95f, window->getSize().y - window->getSize().y / 10.f);

    util.makeMuteButton(window, machine.mutedPointer);

    this->clickToActivate = util.addText("", 75, 2, 2, window->getSize().x / 2,
                                         window->getSize().y / 1.82f, window,
                                         machine.settingPointer->selectedLanguage);
    this->clickToActivate->setFillColor(sf::Color::Transparent);
    this->clickToActivate->setOutlineColor(sf::Color::Transparent);
}

/**
 * Update on keyevent, navigation through settings
 * @param window
 */
void StateGameOver::update(sf::RenderWindow *window) {
    machine.soundLoaderPointer->updateSounds();
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
    if (!this->boxIsClicked) {
        this->textBox->setFillColor(sf::Color(128, 128, 128, 255));
    }
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
        delete this->menuTextures[i].buttonClicked;
        delete this->menuTextures[i].buttonMouseOver;
        delete this->menuTextures[i].buttonNormal;
    }
    delete this->gameOverText;
    delete this->score;
    delete this->text;
    delete this->textBox;
    delete this->congratulationsText;
    delete this->congratulationsText2;
    delete this->whatAShameText;
    delete this->clickToActivate;
    delete this->background;
    delete this->bgTexture;

}

void StateGameOver::handleEvent(sf::RenderWindow *window, sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        //Back on escapekey hvis tekstboksen ikke er aktiv
        if (event.key.code == machine.keybindMap.find("back")->second.second && !this->boxIsClicked) {
            //Arcade
            if (machine.selectedObjectsPointer->selectedGamemode == 1) {
                saveScoreArcade();
            }
                //Classic
            else if (machine.selectedObjectsPointer->selectedGamemode == 2) {
                saveScoreClassic();
            }
            machine.setState(new StateMainMenu);
            return;
        }
            //Sjekker om brukeren har trykket "back" mens tekstboksen er aktiv.
        else if (event.key.code == machine.keybindMap.find("back")->second.second && this->boxIsClicked) {
            //Gjør navnteksten i boksen til defaultverdi: Player
            this->playerName = "";
            this->text->setString("");
            this->boxIsClicked = false;
        } else //Sjekker om brukeren har trykket "select" mens tekstboksen er aktiv, hvis ja, så skal det som står i tekstboksen lagres.
        if (event.key.code == machine.keybindMap.find("select")->second.second) {
            this->boxIsClicked = false;
        }
    }
    std::cout << this->highscoreOrNAH << " - "  << this->boxIsClicked << std::endl;
    if (this->highscoreOrNAH && this->boxIsClicked) {
        this->textBox->setFillColor(sf::Color::White);
        this->clickToActivate->setFillColor(sf::Color::White);
        this->clickToActivate->setOutlineColor(sf::Color::Black);


        //Sjekker om brukeren skriver noe i tekstfeltet, det som blir skrevet i tekstfeltet dukker opp på skjermen
        if (event.type == event.TextEntered) {
            if (event.text.unicode == '\b' && playerName.size() > 0) {
                playerName = playerName.erase(playerName.size() - 1, -1);
                this->text->setString(playerName);
                this->text->setOrigin(this->text->getLocalBounds().width / 2, 0);

            } else if (event.text.unicode == '\n') {
                playerName = playerName.erase(playerName.size() - 1, -1);
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

        for (unsigned int i = 0; i < (sizeof(menuTextures) / sizeof(*menuTextures)); ++i) {
            if (util.checkMouseclick(menuButtons[i], event)) {
                switch (i) {
                    case 0: //restart knappen er trykket
                        //Arcade
                        if (machine.selectedObjectsPointer->selectedGamemode == 1) {
                            saveScoreArcade();
                            machine.setState(new StateGameMode1());
                            machine.soundLoaderPointer->stopMusic();
                            return;
                        }
                            //Classic
                        else if (machine.selectedObjectsPointer->selectedGamemode == 2) {
                            saveScoreClassic();
                            machine.setState(new StateGameMode2());
                            machine.soundLoaderPointer->stopMusic();
                            return;

                        }
                        return;
                    case 1: //return knappen er trykket
                        // Arcade
                        if (machine.selectedObjectsPointer->selectedGamemode == 1) {
                            saveScoreArcade();
                        }
                            //Classic
                        else if (machine.selectedObjectsPointer->selectedGamemode == 2) {
                            saveScoreClassic();
                        }
                        machine.soundLoaderPointer->stopMusic();
                        machine.setState(new StateMainMenu());
                        return;
                    default:
                        break;
                }
            }
        }
    }
}

void StateGameOver::reinitialize(sf::RenderWindow *window) {
    initialize(window);
}

//funksjon for å sortere vector i descending order.
bool sortDescending(const std::pair<int, std::string> &a, const std::pair<int, std::string> &b) {
    return (a.first > b.first);
}

void StateGameOver::saveScoreArcade() {
    //Sjekker om spillerens sitt navn er blank
    if (this->playerName == "") {
        this->playerName = "Player";
    }
    //Bytter ut det siste objektet i listen med det nye
    machine.arcadeScorePointer->pop_back();
    machine.arcadeScorePointer->push_back(make_pair(this->gameOverScore, this->playerName));

    //Sorterer vektoren i synkende rekkefølge.
    std::sort(machine.arcadeScorePointer->begin(),
              machine.arcadeScorePointer->end(),
              sortDescending);
}

void StateGameOver::saveScoreClassic() {
    //Sjekker om spillerens sitt navn er blank
    if (this->playerName == "") {
        this->playerName = "Player";
    }
    //Bytter ut det siste objektet i listen med det nye
    machine.classicScorePointer->pop_back();
    machine.classicScorePointer->push_back(make_pair(this->gameOverScore, this->playerName));

    //Sorterer vektoren i synkende rekkefølge.
    std::sort(machine.classicScorePointer->begin(),
              machine.classicScorePointer->end(),
              sortDescending);
}