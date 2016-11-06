#include "../../Header Files/States/stateKeybindings.h"

#include <cstring>
#include <iostream>

/**
 * Init settingsState.
 * @param window
 */
void stateKeybindings::initialize(sf::RenderWindow *window) {

    memset(machine.keyPressed, 0, sizeof(machine.keyPressed)); //For at tastetrykk gjort i andre states ikke skal beholdes

    this->bgTexture = new sf::Texture();
    this->bgTexture->loadFromFile("Graphics/Sprites/bg_purple.png");

    this->ballTexture = new sf::Texture();
    this->ballTexture->loadFromFile("Graphics/Sprites/blackbackground.png");

    this->background = new sf::Sprite();
    this->background->setTexture(*this->bgTexture);
    this->background->setOrigin(this->background->getGlobalBounds().width / 2, this->background->getGlobalBounds().height / 2);
    this->background->scale(window->getSize().x/background->getGlobalBounds().width/2,window->getSize().y/background->getGlobalBounds().height/2);
    this->background->setPosition(window->getSize().x/2, window->getSize().y/2);

    this->upKeySquare = new sf::Sprite();
    this->upKeySquare->setTexture(*this->ballTexture);
    this->upKeySquare->setOrigin(this->upKeySquare->getGlobalBounds().width / 2, this->upKeySquare->getGlobalBounds().height / 2);
    this->upKeySquare->scale(window->getSize().x/background->getGlobalBounds().width/8,window->getSize().x/background->getGlobalBounds().width/8);
    this->upKeySquare->setPosition(((window->getSize().x / 2) - this->background->getGlobalBounds().width/4) , (window->getSize().y / 2) - this->background->getGlobalBounds().height/6);

    this->downKeySquare = new sf::Sprite();
    this->downKeySquare->setTexture(*this->ballTexture);
    this->downKeySquare->setOrigin(this->downKeySquare->getGlobalBounds().width / 2, this->downKeySquare->getGlobalBounds().height / 2);
    this->downKeySquare->scale(window->getSize().x/background->getGlobalBounds().width/8,window->getSize().x/background->getGlobalBounds().width/8);
    this->downKeySquare->setPosition(upKeySquare->getPosition().x , (window->getSize().y / 2) + this->background->getGlobalBounds().height/7);

    this->leftKeySquare = new sf::Sprite();
    this->leftKeySquare->setTexture(*this->ballTexture);
    this->leftKeySquare->setOrigin(this->leftKeySquare->getGlobalBounds().width / 2, this->leftKeySquare->getGlobalBounds().height / 2);
    this->leftKeySquare->scale(window->getSize().x/background->getGlobalBounds().width/8,window->getSize().x/background->getGlobalBounds().width/8);
    this->leftKeySquare->setPosition(((window->getSize().x / 2) - this->background->getGlobalBounds().width/2.4) , downKeySquare->getPosition().y);

    this->rightKeySquare = new sf::Sprite();
    this->rightKeySquare->setTexture(*this->ballTexture);
    this->rightKeySquare->setOrigin(this->rightKeySquare->getGlobalBounds().width / 2, this->rightKeySquare->getGlobalBounds().height / 2);
    this->rightKeySquare->scale(window->getSize().x/background->getGlobalBounds().width/8,window->getSize().x/background->getGlobalBounds().width/8);
    this->rightKeySquare->setPosition(((window->getSize().x / 2) - this->background->getGlobalBounds().width/2 + this->background->getGlobalBounds().width/2.4) , downKeySquare->getPosition().y);

    this->backKeySquare = new sf::Sprite();
    this->backKeySquare->setTexture(*this->ballTexture);
    this->backKeySquare->setOrigin(this->backKeySquare->getGlobalBounds().width / 2, this->backKeySquare->getGlobalBounds().height / 2);
    this->backKeySquare->scale(window->getSize().x/background->getGlobalBounds().width/8,window->getSize().x/background->getGlobalBounds().width/8);
    this->backKeySquare->setPosition(((window->getSize().x / 2) + this->background->getGlobalBounds().width/4 + this->background->getGlobalBounds().width/10) , upKeySquare->getPosition().y);

    this->selectKeySquare = new sf::Sprite();
    this->selectKeySquare->setTexture(*this->ballTexture);
    this->selectKeySquare->setOrigin(this->selectKeySquare->getGlobalBounds().width / 2, this->selectKeySquare->getGlobalBounds().height / 2);
    this->selectKeySquare->scale(window->getSize().x/background->getGlobalBounds().width/8,window->getSize().x/background->getGlobalBounds().width/8);
    this->selectKeySquare->setPosition(((window->getSize().x / 2) + this->background->getGlobalBounds().width/4) - this->background->getGlobalBounds().width/10 , backKeySquare->getPosition().y);

    this->shootKeySquare = new sf::Sprite();
    this->shootKeySquare->setTexture(*this->ballTexture);
    this->shootKeySquare->setOrigin(this->shootKeySquare->getGlobalBounds().width / 2, this->shootKeySquare->getGlobalBounds().height / 2);
    this->shootKeySquare->scale(window->getSize().x/background->getGlobalBounds().width/8,window->getSize().x/background->getGlobalBounds().width/8);
    this->shootKeySquare->setPosition(selectKeySquare->getPosition().x , (window->getSize().y / 2) + this->background->getGlobalBounds().height/3.5);

    this->pauseKeySquare = new sf::Sprite();
    this->pauseKeySquare->setTexture(*this->ballTexture);
    this->pauseKeySquare->setOrigin(this->pauseKeySquare->getGlobalBounds().width / 2, this->pauseKeySquare->getGlobalBounds().height / 2);
    this->pauseKeySquare->scale(window->getSize().x/background->getGlobalBounds().width/8,window->getSize().x/background->getGlobalBounds().width/8);
    this->pauseKeySquare->setPosition(backKeySquare->getPosition().x, (window->getSize().y / 2) + this->background->getGlobalBounds().height/3.5);
    //this->pauseKeySquare->setColor(sf::Color(255, 255, 255, 125));

    this->font = new sf::Font();
    this->font->loadFromFile("Graphics/font1.otf");

    this->movementText = new sf::Text("Movement", *this->font, 25);
    this->movementText->setOrigin(this->movementText->getGlobalBounds().width / 2, this->movementText->getGlobalBounds().height / 2);
    this->movementText->setPosition(((window->getSize().x / 2) - this->background->getGlobalBounds().width/4) , (window->getSize().y / 2) - this->background->getGlobalBounds().height/2.25);

    this->menuNavigationText = new sf::Text("Menu navigation", *this->font, 25);
    this->menuNavigationText->setOrigin(this->menuNavigationText->getGlobalBounds().width / 2, this->movementText->getGlobalBounds().height / 2);
    this->menuNavigationText->setPosition(((window->getSize().x / 2) + this->background->getGlobalBounds().width/4) , movementText->getPosition().y);

    this->gameplayText = new sf::Text("Gameplay", *this->font, 25);
    this->gameplayText->setOrigin(this->gameplayText->getGlobalBounds().width / 2, this->gameplayText->getGlobalBounds().height / 2);
    this->gameplayText->setPosition(((window->getSize().x / 2) + this->background->getGlobalBounds().width/4) , (window->getSize().y / 2));

    this->upText = new sf::Text("up", *this->font, 15);
    this->upText->setOrigin(this->upText->getGlobalBounds().width / 2, this->upText->getGlobalBounds().height / 2);
    this->upText->setPosition(upKeySquare->getPosition().x,upKeySquare->getPosition().y - upKeySquare->getGlobalBounds().height/1.5);

    this->downText = new sf::Text("down", *this->font, 15);
    this->downText->setOrigin(this->downText->getGlobalBounds().width / 2, this->downText->getGlobalBounds().height / 2);
    this->downText->setPosition(downKeySquare->getPosition().x,downKeySquare->getPosition().y - downKeySquare->getGlobalBounds().height/1.5);

    this->leftText = new sf::Text("left", *this->font, 15);
    this->leftText->setOrigin(this->leftText->getGlobalBounds().width / 2, this->leftText->getGlobalBounds().height / 2);
    this->leftText->setPosition(leftKeySquare->getPosition().x,leftKeySquare->getPosition().y - leftKeySquare->getGlobalBounds().height/1.5);

    this->rightText = new sf::Text("right", *this->font, 15);
    this->rightText->setOrigin(this->rightText->getGlobalBounds().width / 2, this->rightText->getGlobalBounds().height / 2);
    this->rightText->setPosition(rightKeySquare->getPosition().x,rightKeySquare->getPosition().y - rightKeySquare->getGlobalBounds().height/1.5);

    this->selectText = new sf::Text("select", *this->font, 15);
    this->selectText->setOrigin(this->selectText->getGlobalBounds().width / 2, this->selectText->getGlobalBounds().height / 2);
    this->selectText->setPosition(selectKeySquare->getPosition().x,selectKeySquare->getPosition().y - selectKeySquare->getGlobalBounds().height/1.5);

    this->backText = new sf::Text("back", *this->font, 15);
    this->backText->setOrigin(this->backText->getGlobalBounds().width / 2, this->backText->getGlobalBounds().height / 2);
    this->backText->setPosition(backKeySquare->getPosition().x,backKeySquare->getPosition().y - backKeySquare->getGlobalBounds().height/1.5);

    this->shootText = new sf::Text("shoot", *this->font, 15);
    this->shootText->setOrigin(this->shootText->getGlobalBounds().width / 2, this->shootText->getGlobalBounds().height / 2);
    this->shootText->setPosition(shootKeySquare->getPosition().x,shootKeySquare->getPosition().y - shootKeySquare->getGlobalBounds().height/1.5);

    this->pauseText = new sf::Text("pause", *this->font, 15);
    this->pauseText->setOrigin(this->pauseText->getGlobalBounds().width / 2, this->pauseText->getGlobalBounds().height / 2);
    this->pauseText->setPosition(pauseKeySquare->getPosition().x,pauseKeySquare->getPosition().y - pauseKeySquare->getGlobalBounds().height/1.5);

    this->upKeyText = new sf::Text("" + machine.keybindMap.find("up")->second, *this->font, 15);
    this->upKeyText->setOrigin(this->upKeyText->getGlobalBounds().width / 2, this->upKeyText->getGlobalBounds().height / 2);
    this->upKeyText->setPosition(upKeySquare->getPosition().x,upKeySquare->getPosition().y);



}
/**
 * Update on keyevent, navigation through settings
 * @param window
 */
void stateKeybindings::update(sf::RenderWindow *window) {
    sf::Sprite* keySquares[] = {
            upKeySquare,
            downKeySquare,
            leftKeySquare,
            rightKeySquare,
            selectKeySquare,
            backKeySquare,
            shootKeySquare,
            pauseKeySquare
    };
    for (int i = 0; i < 8 ; ++i) {
        if(sf::Mouse::getPosition(*window).x + keySquares[i]->getGlobalBounds().width /2 > keySquares[i]->getPosition().x &&
                sf::Mouse::getPosition(*window).x - keySquares[i]->getGlobalBounds().width /2 < keySquares[i]->getPosition().x &&
                sf::Mouse::getPosition(*window).y + keySquares[i]->getGlobalBounds().height /2 > keySquares[i]->getPosition().y &&
                sf::Mouse::getPosition(*window).y - keySquares[i]->getGlobalBounds().height /2 < keySquares[i]->getPosition().y)
        {
            keySquares[i]->setColor(sf::Color(255,255,255,125));
        }
        else{
            keySquares[i]->setColor(sf::Color(255,255,255,255));
        }

    }

}
/**
 *
 * @param window
 */
void stateKeybindings::render(sf::RenderWindow *window) {
    this->movementText->setFillColor(sf::Color::White);
    this->movementText->setStyle(0);
    window->draw(*this->background);

    window->draw(*this->upKeySquare);
    window->draw(*this->downKeySquare);
    window->draw(*this->leftKeySquare);
    window->draw(*this->pauseKeySquare);
    window->draw(*this->shootKeySquare);
    window->draw(*this->selectKeySquare);
    window->draw(*this->backKeySquare);
    window->draw(*this->rightKeySquare);

    window->draw(*this->movementText);
    window->draw(*this->menuNavigationText);
    window->draw(*this->gameplayText);

    window->draw(*this->upText);
    window->draw(*this->downText);
    window->draw(*this->rightText);
    window->draw(*this->leftText);
    window->draw(*this->selectText);
    window->draw(*this->backText);
    window->draw(*this->shootText);
    window->draw(*this->pauseText);

    window->draw(*this->upKeyText);

}

void stateKeybindings::destroy(sf::RenderWindow *window) {
    delete this->upKeyText;

    delete this->movementText;
    delete this->menuNavigationText;
    delete this->gameplayText;
    delete this->upText;
    delete this->downText;
    delete this->leftText;
    delete this->rightText;
    delete this->selectText;
    delete this->backText;
    delete this->shootText;
    delete this->pauseText;


    delete this->upKeySquare;
    delete this->downKeySquare;
    delete this->pauseKeySquare;
    delete this->shootKeySquare;
    delete this->selectKeySquare;
    delete this->backKeySquare;
    delete this->rightKeySquare;
    delete this->leftKeySquare;

    delete this->bgTexture;
    delete this->background;
}

