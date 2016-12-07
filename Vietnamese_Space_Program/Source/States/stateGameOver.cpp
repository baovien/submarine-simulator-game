#include "../../Include/States/stateGameOver.h"
#include "../../Include/States/stateGameMode1.h"
#include "../../Include/States/stateMainMenu.h"

#include <cstring>

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

    this->bgTexture = new sf::Texture();
    this->bgTexture->loadFromFile("Graphics/Sprites/background12.png");

    this->background = new sf::Sprite();
    this->background->setTexture(*this->bgTexture);

    this->textBox = new sf::RectangleShape();
    this->textBox->setFillColor(sf::Color::White);
    this->textBox->setOutlineColor(sf::Color::Black);
    this->textBox->setOutlineThickness(2);
    this->textBox->setSize(sf::Vector2f(600 * (window->getSize().x / this->background->getGlobalBounds().width),
                                        125 * (window->getSize().y / this->background->getGlobalBounds().height)));
    this->textBox->setPosition(window->getSize().x / 2, window->getSize().y / 1.7f);
    this->textBox->setOrigin(this->textBox->getLocalBounds().width / 2, this->textBox->getLocalBounds().height / 2);

    this->gameOverScore = machine.getGameOverScore();
    this->gameOverText = util.addText("Game Over", 75, 2, 2, window->getSize().x / 2,
                                      (window->getSize().y / 2 - this->background->getGlobalBounds().height / 2.25),
                                      window, machine.settingPointer->selectedLanguage);

    this->score = util.addText("Score: " + std::to_string(this->gameOverScore), 50, 2, 2, window->getSize().x / 2,
                               this->gameOverText->getGlobalBounds().height * 2,
                               window, machine.settingPointer->selectedLanguage);


    this->menuText = util.addText("Back to menu", 25, 2, 2, window->getSize().x / 2.5f, window->getSize().y / 1.5f,
                                  window, machine.settingPointer->selectedLanguage);

    this->restartText = util.addText("Restart", 25, 2, 2, window->getSize().x / 1.5f, window->getSize().y / 1.5f,
                                    window, machine.settingPointer->selectedLanguage);

    this->text = util.addText(playerName, 75, 2, 2, window->getSize().x / 2,
                              window->getSize().y / 1.95f, window, machine.settingPointer->selectedLanguage);

    this->congratulationsText = util.addText("Congratulations, after your striking performance \n you have been placed # on the leaderboards",
                                             30, 2, 2, window->getSize().x / 2,
                                             this->score->getPosition().y * 2,
                                             window, machine.settingPointer->selectedLanguage);
}

/**
 * Update on keyevent, navigation through settings
 * @param window
 */
void StateGameOver::update(sf::RenderWindow *window) {
    if (this->selected > 1) {
        this->selected = 0;
    }

    if (this->selected < 0) {
        this->selected = 1;
    }
}

/**
 *
 * @param window
 */
void StateGameOver::render(sf::RenderWindow *window) {
    this->gameOverText->setFillColor(sf::Color::White);
    this->menuText->setFillColor(sf::Color::White);
    this->restartText->setFillColor(sf::Color::White);
    this->score->setFillColor(sf::Color::White);
    this->text->setFillColor(sf::Color::White);

    this->menuText->setStyle(0);
    this->restartText->setStyle(0);

    switch (selected) {
        case 0: // Back to menu
            this->menuText->setStyle(1 << 3);
            break;

        case 1: // Restart
            this->restartText->setStyle(1 << 3);
            break;
    }
    window->draw(*this->background);
    window->draw(*this->score);
    for(int i = 0; i < machine.arcadeScorePointer->size(); i++){
        if(gameOverScore > machine.arcadeScorePointer->at(i).second){
            this->highscoreOrNAH = true;
            this->congratulationsText->setFillColor(sf::Color::White);
            window->draw(*this->congratulationsText);
            window->draw(*this->textBox);
        }
    }
    window->draw(*this->gameOverText);
    window->draw(*this->menuText);
    window->draw(*this->text);
    window->draw(*this->restartText);
}

void StateGameOver::destroy(sf::RenderWindow *window) {

    delete this->gameOverText;
    delete this->menuText;
    delete this->restartText;
    delete this->score;
    delete this->text;
    delete this->congratulationsText;
    delete this->background;
}

void StateGameOver::handleEvent(sf::RenderWindow *window, sf::Event event) {
    if (event.type == event.KeyPressed) {
        if (event.key.code == sf::Keyboard::Left) {
            this->selected += 1;
        }

        if (event.key.code == sf::Keyboard::Right) {
            this->selected -= 1;
        }
        if (event.key.code == machine.keybindMap.find("select")->second.second) {
            switch (this->selected) {
                case 0: //Back
                    machine.setState(new StateMainMenu);
                    break;

                case 1: //Restart
                    machine.setState(new StateGameMode1);
                    break;

            }
        }
        //Back on escapekey
        if (event.key.code == machine.keybindMap.find("back")->second.second) {
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
    if(highscoreOrNAH){
        if (event.type == event.TextEntered){

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
}

void StateGameOver::reinitialize(sf::RenderWindow *window) {

}
