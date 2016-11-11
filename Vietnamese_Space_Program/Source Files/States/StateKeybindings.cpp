#include "../../Header Files/States/StateKeybindings.h"

#include <cstring>
#include <iostream>

/**
 * Init settingsState.
 * @param window
 */
void StateKeybindings::initialize(sf::RenderWindow *window) {
    machine.mouseClick = {-1,
                          -1}; //Resetter mouseClick slik at museklikk fra tidligere states ikke triggerer if-sjekker.
    memset(machine.keyPressed, 0,
           sizeof(machine.keyPressed)); //For at tastetrykk gjort i andre states ikke skal beholdes

    this->bgTexture = new sf::Texture();
    this->bgTexture->loadFromFile("Graphics/Sprites/bg_purple.png");

    this->ballTexture = new sf::Texture();
    this->ballTexture->loadFromFile("Graphics/Sprites/blackbackground.png");

    this->background = new sf::Sprite();
    this->background->setTexture(*this->bgTexture);
    this->background->setOrigin(this->background->getGlobalBounds().width / 2,
                                this->background->getGlobalBounds().height / 2);
    this->background->scale(window->getSize().x / background->getGlobalBounds().width / 2,
                            window->getSize().y / background->getGlobalBounds().height / 2);
    this->background->setPosition(window->getSize().x / 2, window->getSize().y / 2);

    this->font = new sf::Font();
    this->font->loadFromFile("Graphics/font1.otf");

    this->movementText = new sf::Text("Movement", *this->font, 25);
    this->movementText->setOrigin(this->movementText->getGlobalBounds().width / 2,
                                  this->movementText->getGlobalBounds().height / 2);
    this->movementText->setPosition(((window->getSize().x / 2) - this->background->getGlobalBounds().width / 4),
                                    (float) ((window->getSize().y / 2) -
                                             this->background->getGlobalBounds().height / 2.25));

    this->gameplayText = new sf::Text("Gameplay", *this->font, 25);
    this->gameplayText->setOrigin(this->gameplayText->getGlobalBounds().width / 2,
                                  this->gameplayText->getGlobalBounds().height / 2);
    this->gameplayText->setPosition(((window->getSize().x / 2) + this->background->getGlobalBounds().width / 4),
                                    (window->getSize().y / 2));

    this->menuNavigationText = new sf::Text("Menu navigation", *this->font, 25);
    this->menuNavigationText->setOrigin(this->menuNavigationText->getGlobalBounds().width / 2,
                                        this->movementText->getGlobalBounds().height / 2);
    this->menuNavigationText->setPosition(((window->getSize().x / 2) + this->background->getGlobalBounds().width / 4),
                                          movementText->getPosition().y);

    positionList.push_back(sf::Vector2f((window->getSize().x / 2) - this->background->getGlobalBounds().width / 4,
                                        (window->getSize().y / 2) - this->background->getGlobalBounds().height / 6));
    positionList.push_back(sf::Vector2f(positionList[0].x,
                                        (window->getSize().y / 2) + this->background->getGlobalBounds().height / 7));
    positionList.push_back(
            sf::Vector2f((float) ((window->getSize().x / 2) - this->background->getGlobalBounds().width / 2.4),
                         positionList[1].y));
    positionList.push_back(sf::Vector2f(
            (float) ((window->getSize().x / 2) - this->background->getGlobalBounds().width / 2 +
                     this->background->getGlobalBounds().width / 2.4), positionList[1].y));
    positionList.push_back(sf::Vector2f(((window->getSize().x / 2) + this->background->getGlobalBounds().width / 4 +
                                         this->background->getGlobalBounds().width / 10), positionList[0].y));
    positionList.push_back(sf::Vector2f((window->getSize().x / 2) + this->background->getGlobalBounds().width / 4 -
                                        this->background->getGlobalBounds().width / 10, positionList[4].y));
    positionList.push_back(sf::Vector2f(positionList[4].x, (float) ((window->getSize().y / 2) +
                                                                    this->background->getGlobalBounds().height / 3.5)));
    positionList.push_back(sf::Vector2f(positionList[5].x, (float) ((window->getSize().y / 2) +
                                                                    this->background->getGlobalBounds().height / 3.5)));

    for (int i = 0; i < 8; ++i) {
        keySquares ks = StateKeybindings::keySquares();
        keyVector.push_back(ks);
        keyVector[i].keySquare = new sf::Sprite();
        keyVector[i].keySquare->setTexture(*this->ballTexture);
        keyVector[i].keySquare->setOrigin(keyVector[i].keySquare->getGlobalBounds().width / 2,
                                          keyVector[i].keySquare->getGlobalBounds().height / 2);
        keyVector[i].keySquare->scale(window->getSize().x / background->getGlobalBounds().width / 8,
                                      window->getSize().x / background->getGlobalBounds().width / 8);
        keyVector[i].keySquare->setPosition(positionList[i].x, positionList[i].y);

        keyVector[i].titleText = new sf::Text(machine.wordList[i], *this->font, 15);
        keyVector[i].titleText->setOrigin(keyVector[i].titleText->getGlobalBounds().width / 2,
                                          keyVector[i].titleText->getGlobalBounds().height / 2);
        keyVector[i].titleText->setPosition(keyVector[i].keySquare->getPosition().x,
                                            (float) (keyVector[i].keySquare->getPosition().y -
                                                     keyVector[i].keySquare->getGlobalBounds().height / 1.5));

        keyVector[i].keyText = new sf::Text("" + machine.keybindMap.find(machine.wordList[i])->second, *this->font, 20);
        keyVector[i].keyText->setPosition(keyVector[i].keySquare->getPosition().x,
                                          keyVector[i].keySquare->getPosition().y);
        if (keyVector[i].keyText->getGlobalBounds().width * 2 > keyVector[i].keySquare->getGlobalBounds().width) {
            keyVector[i].keyText->setCharacterSize(12);
        } else {
            keyVector[i].keyText->setCharacterSize(22);
        }
        keyVector[i].keyText->setOrigin(keyVector[i].keyText->getGlobalBounds().width / 2,
                                        keyVector[i].keyText->getGlobalBounds().height / 2);
    }
}

/**
 * Update on keyevent, navigation through settings
 * @param window
 */
void StateKeybindings::update(sf::RenderWindow *window) {
    std::cout << "waitingForInput(bool): " << machine.waitingForInput << std::endl <<
              "escape pressed(bool): " << machine.keyPressed[sf::Keyboard::Key::Escape] << std::endl;


    for (int i = 0; i < 8; ++i) {
        if (sf::Mouse::getPosition(*window).x + keyVector[i].keySquare->getGlobalBounds().width / 2 >
            keyVector[i].keySquare->getPosition().x &&
            sf::Mouse::getPosition(*window).x - keyVector[i].keySquare->getGlobalBounds().width / 2 <
            keyVector[i].keySquare->getPosition().x &&
            sf::Mouse::getPosition(*window).y + keyVector[i].keySquare->getGlobalBounds().height / 2 >
            keyVector[i].keySquare->getPosition().y &&
            sf::Mouse::getPosition(*window).y - keyVector[i].keySquare->getGlobalBounds().height / 2 <
            keyVector[i].keySquare->getPosition().y) {
            keyVector[i].keySquare->setColor(sf::Color(255, 255, 255, 125));
        } else {
            keyVector[i].keySquare->setColor(sf::Color(255, 255, 255, 255));
        }
        if (machine.mouseClick.x + keyVector[i].keySquare->getGlobalBounds().width / 2 >
            keyVector[i].keySquare->getPosition().x &&
            machine.mouseClick.x - keyVector[i].keySquare->getGlobalBounds().width / 2 <
            keyVector[i].keySquare->getPosition().x &&
            machine.mouseClick.y + keyVector[i].keySquare->getGlobalBounds().height / 2 >
            keyVector[i].keySquare->getPosition().y &&
            machine.mouseClick.y - keyVector[i].keySquare->getGlobalBounds().height / 2 <
            keyVector[i].keySquare->getPosition().y) {
            if (machine.keyPressedInBinds) {
                machine.keyPressedInBinds = false;
                machine.waitingForInput = true;
                machine.keybindMap.find(machine.wordList[i])->second = "";
                keyVector[i].keyText->setString(machine.keybindMap.find(machine.wordList[i])->second);
                keyVector[i].keyText->setCharacterSize(22);
            }
        }
        if (machine.keybindMap.find(machine.wordList[i])->second == "" && !machine.waitingForInput) {
            machine.keybindMap.find(machine.wordList[i])->second = machine.keyList[machine.keyToBind];
            keyVector[i].keyText->setString("" + machine.keybindMap.find(machine.wordList[i])->second);
            if (keyVector[i].keyText->getGlobalBounds().width * 2 > keyVector[i].keySquare->getGlobalBounds().width) {
                keyVector[i].keyText->setCharacterSize(12);
            } else {
                keyVector[i].keyText->setCharacterSize(22);
            }
            keyVector[i].keyText->setOrigin(keyVector[i].keyText->getGlobalBounds().width / 2,
                                            keyVector[i].keyText->getGlobalBounds().height / 2);

            /*  std::cout << "waitingForInput(bool): " << machine.waitingForInput << std::endl <<
                        "key: " << machine.keyList[machine.keyToBind] << std::endl <<
                        "waitingForInput(bool): " << machine.waitingForInput << std::endl <<
                        "x pos keyText: " << keyVector[i].keyText->getPosition().x << std::endl <<
                        "y pos keyText: " << keyVector[i].keyText->getPosition().y << std::endl <<
                        "x origin keyText: " << keyVector[i].keyText->getOrigin().x << std::endl <<
                        "y origin keyText: " << keyVector[i].keyText->getOrigin().y << std::endl <<
                        "x bound keyText: " << keyVector[i].keyText->getGlobalBounds().width << std::endl <<
                        "x bound keyText: " << keyVector[i].keyText->getGlobalBounds().height << std::endl << std::endl;*/
        }


    }
    // std::cout << keyList[machine.keyToBind] << " " << machine.waitingForInput<< " " << machine.waitingForInput<< " " << machine.waitingForInput << std::endl;

    machine.mouseClick = {-1, -1};

}

/**
 *
 * @param window
 */
void StateKeybindings::render(sf::RenderWindow *window) {
    window->draw(*this->background);

    window->draw(*this->movementText);
    window->draw(*this->menuNavigationText);
    window->draw(*this->gameplayText);

    for (int i = 0; i < 8; ++i) {
        window->draw(*this->keyVector[i].keySquare);
        window->draw(*this->keyVector[i].titleText);
        window->draw(*this->keyVector[i].keyText);
    }


}

void StateKeybindings::destroy(sf::RenderWindow *window) {

    for (int i = 0; i < 8; ++i) {
        delete this->keyVector[i].keyText;
        delete this->keyVector[i].titleText;
        delete this->keyVector[i].keySquare;
    }

    delete this->font;
    delete this->gameplayText;
    delete this->menuNavigationText;
    delete this->movementText;

    delete this->ballTexture;
    delete this->bgTexture;
    delete this->background;

    machine.waitingForInput = false;
    machine.keyPressedInBinds = true;
}


