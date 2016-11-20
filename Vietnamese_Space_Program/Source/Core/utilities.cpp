#include <iostream>
#include "../../Include/Core/utilities.h"


void Utilities::makeMuteButton(sf::RenderWindow *window) {
    for (unsigned int i = 0; i < (sizeof(muteTextures) / sizeof(*muteTextures)); ++i) {
        muteTextures[i].buttonMouseOver = new sf::Texture();
        muteTextures[i].buttonMouseOver->loadFromFile("Graphics/Sprites/MainMenu_buttons/Btn" + std::to_string(15 + i * 3) + ".png");

        muteTextures[i].buttonNormal = new sf::Texture();
        muteTextures[i].buttonNormal->loadFromFile("Graphics/Sprites/MainMenu_buttons/Btn" + std::to_string(15 + i * 3 + 1) + ".png");

        muteTextures[i].buttonClicked = new sf::Texture();
        muteTextures[i].buttonClicked->loadFromFile("Graphics/Sprites/MainMenu_buttons/Btn" + std::to_string(15 + i * 3 + 2) + ".png");
    }

    muteButton = new sf::Sprite();
    muteButton->setTexture(*this->muteTextures[0].buttonNormal);
    muteButton->setOrigin(muteButton->getGlobalBounds().width / 2, muteButton->getGlobalBounds().height / 2);
    muteButton->scale(window->getSize().x / 5120.f, window->getSize().y / 2880.f);
    muteButton->setPosition(window->getSize().x - window->getSize().x * 0.95f, window->getSize().y - window->getSize().y / 10);
}

void Utilities::checkMuteMouseOver(sf::RenderWindow *window) {
    if (checkMouseover(muteButton, window)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            muteButton->setTexture(*this->muteTextures[0].buttonClicked);
        }
        else {
            muteButton->setTexture(*this->muteTextures[0].buttonMouseOver);
        }
    } else {
        muteButton->setTexture(*this->muteTextures[0].buttonNormal);
    }
}

void Utilities::checkMuteMouseClick(sf::RenderWindow *window, sf::Event event) {
    if(checkMouseclick(muteButton, event)){
        std::swap(muteTextures[0], muteTextures[1]);
    }
    /*if(MUTED){
        //MÅ MEKKE UNMUTE HER
    }
    else{
        //MÅ MEKKE MUTE HER
    }
     */
}

//Texture, scale x, scale y, position x, position y, window
sf::Sprite *Utilities::addButton(sf::Texture texture, float scaleX, float scaleY, float posX, float posY, sf::RenderWindow *window) {
    sf::Sprite *button = new sf::Sprite();
    button->setTexture(texture);
    button->setOrigin(button->getGlobalBounds().width / 2, button->getGlobalBounds().height / 2);
    // button->scale(window->getSize().x / button->getGlobalBounds().width / scaleX, window->getSize().x / button->getGlobalBounds().width / scaleY);
    button->setPosition(posX, posY);

    return button;
}


//Text, textsize, origin x, origin y, position x, position y, window
sf::Text *Utilities::addText(std::string textContent, unsigned int textSize, int originX, int originY, float posX, float posY, sf::RenderWindow *window) {
    this->font = new sf::Font();
    this->font->loadFromFile("Graphics/Turtles.otf");

    sf::Text *text = new sf::Text(textContent, *this->font, textSize);
    text->setOrigin(text->getGlobalBounds().width / originX, text->getGlobalBounds().height / originY);
    text->setPosition(posX, posY);
    text->scale(window->getSize().x / 1280.f, window->getSize().y / 720.f);
    text->setOutlineThickness(text->getCharacterSize() / 15);
    text->setOutlineColor(sf::Color::Black);
    return text;
}

//Tar inn sprite og returnerer true om mouseover
bool Utilities::checkMouseover(sf::Sprite *buttonSprite, sf::RenderWindow *window) {

    return sf::Mouse::getPosition(*window).x + buttonSprite->getGlobalBounds().width / 2 > buttonSprite->getPosition().x &&
           sf::Mouse::getPosition(*window).x - buttonSprite->getGlobalBounds().width / 2 < buttonSprite->getPosition().x &&
           sf::Mouse::getPosition(*window).y + buttonSprite->getGlobalBounds().height / 2 > buttonSprite->getPosition().y &&
           sf::Mouse::getPosition(*window).y - buttonSprite->getGlobalBounds().height / 2 < buttonSprite->getPosition().y;
}

//Tar inn sprite og returnerer true om mouseclick
bool Utilities::checkMouseclick(sf::Sprite *buttonSprite, sf::Event event) {
    return event.mouseButton.x + buttonSprite->getGlobalBounds().width / 2 > buttonSprite->getPosition().x &&
           event.mouseButton.x - buttonSprite->getGlobalBounds().width / 2 < buttonSprite->getPosition().x &&
           event.mouseButton.y + buttonSprite->getGlobalBounds().height / 2 > buttonSprite->getPosition().y &&
           event.mouseButton.y - buttonSprite->getGlobalBounds().height / 2 < buttonSprite->getPosition().y;
}

sf::Sprite *Utilities::getMuteButton() const {
    return muteButton;
}

Utilities::Utilities() {
    framerate = 60;
}
