#include "../../Include/States/stateKeybindings.h"
#include "../../Include/States/stateSettings.h"

/**
 * Init settingsState.
 * @param window
 */
void StateKeybindings::initialize(sf::RenderWindow *window) {
    sf::View newView(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
    window->setView(newView);

    this->bgTexture = new sf::Texture();
    this->bgTexture->loadFromFile("Graphics/Sprites/Window/Window_10.png");

    this->ballTexture = new sf::Texture();
    this->ballTexture->loadFromFile("Graphics/Sprites/Buttons/Button_36.png");

    this->background = new sf::Sprite();
    this->background->setTexture(*this->bgTexture);
    this->background->setOrigin(this->background->getGlobalBounds().width / 2, this->background->getGlobalBounds().height / 2);
    this->background->scale(window->getSize().x / background->getGlobalBounds().width / 2, window->getSize().y / background->getGlobalBounds().height / 2);
    this->background->setPosition(window->getSize().x / 2, window->getSize().y / 2);

    this->font = new sf::Font();
    this->font->loadFromFile("Graphics/Turtles.otf");

    this->keyFont = new sf::Font();
    this->keyFont->loadFromFile("Graphics/font1.otf");

    this->alreadyBoundText = new sf::Text("Key already bound", *this->font, 25);
    this->alreadyBoundText->setOrigin(this->alreadyBoundText->getGlobalBounds().width / 2, this->alreadyBoundText->getGlobalBounds().height / 2);
    this->alreadyBoundText->setPosition(window->getSize().x / 2, window->getSize().y / 1.4f);
    this->alreadyBoundText->setFillColor(sf::Color(255, 0, 0, (sf::Uint8) transparencyValue));

    this->movementText = new sf::Text("Movement", *this->font, 25);
    this->movementText->setOrigin(this->movementText->getGlobalBounds().width / 2, this->movementText->getGlobalBounds().height / 2);
    this->movementText->setPosition(((window->getSize().x / 2) - this->background->getGlobalBounds().width / 4), ((window->getSize().y / 2) - this->background->getGlobalBounds().height / 2.25f));

    this->gameplayText = new sf::Text("Gameplay", *this->font, 25);
    this->gameplayText->setOrigin(this->gameplayText->getGlobalBounds().width / 2, this->gameplayText->getGlobalBounds().height / 2);
    this->gameplayText->setPosition(((window->getSize().x / 2) + this->background->getGlobalBounds().width / 4), (window->getSize().y / 2));

    this->menuNavigationText = new sf::Text("Menu navigation", *this->font, 25);
    this->menuNavigationText->setOrigin(this->menuNavigationText->getGlobalBounds().width / 2, this->movementText->getGlobalBounds().height / 2);
    this->menuNavigationText->setPosition(((window->getSize().x / 2) + this->background->getGlobalBounds().width / 4), movementText->getPosition().y);

    positionList.push_back(sf::Vector2f((window->getSize().x / 2) - this->background->getGlobalBounds().width / 4, (window->getSize().y / 2) - this->background->getGlobalBounds().height / 6));
    positionList.push_back(sf::Vector2f(positionList[0].x, (window->getSize().y / 2) + this->background->getGlobalBounds().height / 7));
    positionList.push_back(sf::Vector2f(((window->getSize().x / 2) - this->background->getGlobalBounds().width / 2.4f), positionList[1].y));
    positionList.push_back(sf::Vector2f(((window->getSize().x / 2) - this->background->getGlobalBounds().width / 2 + this->background->getGlobalBounds().width / 2.4f), positionList[1].y));
    positionList.push_back(sf::Vector2f(((window->getSize().x / 2) + this->background->getGlobalBounds().width / 4 + this->background->getGlobalBounds().width / 10), positionList[0].y));
    positionList.push_back(sf::Vector2f((window->getSize().x / 2) + this->background->getGlobalBounds().width / 4 - this->background->getGlobalBounds().width / 10, positionList[4].y));
    positionList.push_back(sf::Vector2f(positionList[4].x, ((window->getSize().y / 2) + this->background->getGlobalBounds().height / 3.5f)));
    positionList.push_back(sf::Vector2f(positionList[5].x, ((window->getSize().y / 2) + this->background->getGlobalBounds().height / 3.5f)));

    for (unsigned int i = 0; i < sizeof(wordList)/ sizeof(*wordList); ++i) {
        keySquares ks = StateKeybindings::keySquares();
        keyVector.push_back(ks);
        keyVector[i].keySquare = new sf::Sprite();
        keyVector[i].keySquare->setTexture(*this->ballTexture);
        keyVector[i].keySquare->setOrigin(keyVector[i].keySquare->getGlobalBounds().width / 2, keyVector[i].keySquare->getGlobalBounds().height / 2);
        keyVector[i].keySquare->scale(window->getSize().x / background->getGlobalBounds().width / 4.5f, window->getSize().x / background->getGlobalBounds().width / 4.5f);
        keyVector[i].keySquare->setPosition(positionList[i].x, positionList[i].y);
        //keyVector[i].keySquare->setColor(sf::Color(255,0,0, 50));

        keyVector[i].titleText = new sf::Text(wordList[i], *this->font, 15);
        keyVector[i].titleText->setOrigin(keyVector[i].titleText->getGlobalBounds().width / 2, keyVector[i].titleText->getGlobalBounds().height / 2);
        keyVector[i].titleText->setPosition(keyVector[i].keySquare->getPosition().x, (keyVector[i].keySquare->getPosition().y - keyVector[i].keySquare->getGlobalBounds().height / 1.5f));

        keyVector[i].keyText = new sf::Text("" + machine.keybindMap.find(wordList[i])->second.first, *this->keyFont, 20);
        keyVector[i].keyText->setPosition(keyVector[i].keySquare->getPosition().x, keyVector[i].keySquare->getPosition().y);
        if (keyVector[i].keyText->getGlobalBounds().width * 2 > keyVector[i].keySquare->getGlobalBounds().width) {
            keyVector[i].keyText->setCharacterSize(12);
        } else {
            keyVector[i].keyText->setCharacterSize(22);
        }
        keyVector[i].keyText->setOrigin(keyVector[i].keyText->getGlobalBounds().width / 2, keyVector[i].keyText->getGlobalBounds().height / 2);
    }
}


void StateKeybindings::update(sf::RenderWindow *window) {

    for (int i = 0; i < 8; ++i) {
        if (util.checkMouseover(keyVector[i].keySquare, window)) {
            keyVector[i].keySquare->setColor(sf::Color(255, 255, 255, 125));
        } else {
            keyVector[i].keySquare->setColor(sf::Color(255, 255, 255, 255));
        }
        if (machine.keybindMap.find(wordList[i])->second.first == "" && !waitingForInput) {

            machine.keybindMap.find(wordList[i])->second.first = keyList[keyToBind];
            machine.keybindMap.find(wordList[i])->second.second = keyToBind;

            keyVector[i].keyText->setString("" + machine.keybindMap.find(wordList[i])->second.first);

            if (keyVector[i].keyText->getGlobalBounds().width * 2 > keyVector[i].keySquare->getGlobalBounds().width) {
                keyVector[i].keyText->setCharacterSize(12);
            } else {
                keyVector[i].keyText->setCharacterSize(22);
            }
            keyVector[i].keyText->setOrigin(keyVector[i].keyText->getGlobalBounds().width / 2, keyVector[i].keyText->getGlobalBounds().height / 2);
        }
    }

    this->alreadyBoundText->setFillColor(sf::Color(255, 50, 50, (sf::Uint8) transparencyValue));
    if(transparencyValue>3)
    transparencyValue-=3;
}


void StateKeybindings::render(sf::RenderWindow *window) {
    window->draw(*this->background);

    window->draw(*this->movementText);
    window->draw(*this->menuNavigationText);
    window->draw(*this->gameplayText);

    for (unsigned int i = 0; i < sizeof(wordList)/ sizeof(*wordList); ++i) {
        window->draw(*this->keyVector[i].keySquare);
        window->draw(*this->keyVector[i].titleText);
        window->draw(*this->keyVector[i].keyText);
    }
    window->draw(*this->alreadyBoundText);


}

void StateKeybindings::destroy(sf::RenderWindow *window) {

    for (unsigned int i = 0; i < sizeof(wordList)/ sizeof(*wordList); ++i) {
        delete this->keyVector[i].keyText;
        delete this->keyVector[i].titleText;
        delete this->keyVector[i].keySquare;
    }

    delete this->font;
    delete this->gameplayText;
    delete this->menuNavigationText;
    delete this->movementText;
    delete this->alreadyBoundText;

    delete this->ballTexture;
    delete this->bgTexture;
    delete this->background;
}

void StateKeybindings::handleEvent(sf::RenderWindow *window, sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == machine.keybindMap.find("back")->second.second) {
            if (!waitingForInput) {
                machine.setState(new StateSettings);
                return;
            }
        }


        if (waitingForInput && event.key.code != -1) {
            bool exists = false;
            for (int i = 0; i < 8; ++i) {
                if (machine.keybindMap.find(wordList[i])->second.first != keyList[event.key.code]) {
                    exists = false;
                } else {
                    exists = true;
                    transparencyValue=255;
                    break;
                }
            }
            if (!exists) {
                keyPressedInBinds = true;
                waitingForInput = false;
                keyToBind = event.key.code;
            }
        }
    }
    if (event.type == sf::Event::MouseButtonPressed) {
        for (unsigned int i = 0; i < sizeof(wordList)/ sizeof(*wordList); ++i) {

            if (util.checkMouseclick(keyVector[i].keySquare, event)) {
                if (keyPressedInBinds) {
                    keyPressedInBinds = false;
                    waitingForInput = true;
                    machine.keybindMap.find(wordList[i])->second.first = "";
                    keyVector[i].keyText->setString(machine.keybindMap.find(wordList[i])->second.first);
                    keyVector[i].keyText->setCharacterSize(22);
                }
            }
        }
    }
}

void StateKeybindings::reinitialize(sf::RenderWindow *window) {

}
