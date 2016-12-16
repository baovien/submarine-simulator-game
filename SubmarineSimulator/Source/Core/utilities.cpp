#include <iostream>
#include "../../Include/Core/utilities.h"

/**
 * Utility constructor. Utility contains many functions that are not always connected to one another.
 * Splitting this into more classes divided by their connection to eachother would reduce unnecessary passing of data.
 * @return
 */
Utilities::Utilities() {
    this->font = new sf::Font();
    this->font->loadFromFile("Graphics/Turtles.otf");

    for (unsigned int i = 0; i < (sizeof(muteTextures) / sizeof(*muteTextures)); ++i) {
        muteTextures[i].buttonMouseOver = new sf::Texture();
        muteTextures[i].buttonMouseOver->loadFromFile("Graphics/Sprites/MainMenu_buttons/Btn" + std::to_string(15 + i * 3) + ".png");

        muteTextures[i].buttonNormal = new sf::Texture();
        muteTextures[i].buttonNormal->loadFromFile("Graphics/Sprites/MainMenu_buttons/Btn" + std::to_string(15 + i * 3 + 1) + ".png");

        muteTextures[i].buttonClicked = new sf::Texture();
        muteTextures[i].buttonClicked->loadFromFile("Graphics/Sprites/MainMenu_buttons/Btn" + std::to_string(15 + i * 3 + 2) + ".png");
    }
}

/**
 * Creates a mute button for the state to implement.
 * @param window
 * @param mutedPointer - Points to whether the game is muted or not. Variable pointed to lies in machine.
 */
void Utilities::makeMuteButton(sf::RenderWindow *window, bool *mutedPointer) {

    if (*mutedPointer) { //Sjekker om det er muta når jeg lager knappen og bytter til muteversjonen av knappen om de er det.
        std::swap(muteTextures[0], muteTextures[1]);
    }
    muteButton = new sf::Sprite();
    muteButton->setTexture(*this->muteTextures[0].buttonNormal);
    muteButton->setOrigin(muteButton->getGlobalBounds().width / 2, muteButton->getGlobalBounds().height / 2);
    muteButton->scale(window->getSize().x / 5120.f, window->getSize().y / 2880.f);
    muteButton->setPosition(window->getSize().x - window->getSize().x * 0.95f, window->getSize().y - window->getSize().y / 10);
}

/**
 * Checks if the mutebutton is being mouseovered, clicked or untouched changes texture depending on that.
 * @param window
 */
void Utilities::checkMuteMouseOver(sf::RenderWindow *window) {
    if (checkMouseover(muteButton, window)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            muteButton->setTexture(*this->muteTextures[0].buttonClicked);
        } else {
            muteButton->setTexture(*this->muteTextures[0].buttonMouseOver);
        }
    } else {
        muteButton->setTexture(*this->muteTextures[0].buttonNormal);
    }
}

/**
 * Checks if the button has been clicked and the button has been released.
 * Flips the mute bool if so, muting or unmuting the game.
 * @param window
 * @param event
 * @param mutedPointer - Points to whether the game is muted or not. Variable pointed to lies in machine.
 */
void Utilities::checkMuteMouseClick(sf::RenderWindow *window, sf::Event event, bool *mutedPointer) {
    if (checkMouseclick(muteButton, event)) {
        *mutedPointer = !*mutedPointer;
        std::swap(muteTextures[0], muteTextures[1]);
    }
}


/**
 * A factory for making sprites, supposed to reduce the possibility of doing things in the wrong order,
 * scaling incorrectly, etc.
 * Is not in use due to it being bugged when it was implemented and fixed at a stage in which most of
 * the sprites were already made without using the factory.
 * @param texture - a pointer to the texture to be loaded.
 * @param scaleX - What to divide window's x size on to scale.
 * @param scaleY - What to divide window's y size on to scale.
 * @param posX - X position.
 * @param posY - Y position.
 * @param window
 * @return
 */
sf::Sprite *Utilities::addButton(sf::Texture *texture, float scaleX, float scaleY, float posX, float posY, sf::RenderWindow *window) {

    sf::Sprite *button = new sf::Sprite();
    button->setTexture(*texture);
    button->setOrigin(button->getGlobalBounds().width / 2, button->getGlobalBounds().height / 2);
    button->scale(window->getSize().x / scaleX, window->getSize().y / scaleY);
    button->setPosition(posX, posY);

    return button;
}


//Text, textsize, origin x, origin y, position x, position y, window

/**
 * A factory for adding text. Currently does translation, correct scaling and sets the right font and border.
 * @param textContent - The text's string
 * @param textSize
 * @param originX - How you'd like the origin to be. 0 will leave the origin in x = 0.
 * @param originY - How you'd like the origin to be. 0 will leave the origin in y = 0.
 * @param posX - X position.
 * @param posY  - Y position.
 * @param window
 * @param language - Current selected language.
 * @return
 */
sf::Text *Utilities::addText(sf::String textContent, unsigned int textSize, int originX, int originY, float posX, float posY, sf::RenderWindow *window, int language) {

    sf::Text *text = new sf::Text(textContent, *this->font, textSize);
    std::transform(textContent.begin(), textContent.end(), textContent.begin(), ::tolower);

    if (languageMap.find(textContent) != languageMap.end()) {
        switch (language) {
            case 1:
                text->setString(std::get<0>(languageMap.find(textContent)->second));
                break;
            case 2:
                text->setString(std::get<1>(languageMap.find(textContent)->second));
                break;
            case 3:
                text->setString(std::get<2>(languageMap.find(textContent)->second));
                break;
            default:
                break;
        }
    }
    if (originX != 0 && originY != 0)
        text->setOrigin(text->getGlobalBounds().width / originX, text->getGlobalBounds().height / originY);
    text->setPosition(posX, posY);
    text->scale(window->getSize().x / 1280.f, window->getSize().y / 720.f);
    text->setOutlineThickness(text->getCharacterSize() / 15);
    text->setOutlineColor(sf::Color::Black);
    return text;
}

/**
 * Checks mouseover of the given sprite and returns result.
 * @param buttonSprite -  Sprite to check.
 * @param window
 * @return - result
 */
bool Utilities::checkMouseover(sf::Sprite *buttonSprite, sf::RenderWindow *window) {

    return sf::Mouse::getPosition(*window).x + buttonSprite->getGlobalBounds().width / 2 > buttonSprite->getPosition().x &&
           sf::Mouse::getPosition(*window).x - buttonSprite->getGlobalBounds().width / 2 < buttonSprite->getPosition().x &&
           sf::Mouse::getPosition(*window).y + buttonSprite->getGlobalBounds().height / 2 > buttonSprite->getPosition().y &&
           sf::Mouse::getPosition(*window).y - buttonSprite->getGlobalBounds().height / 2 < buttonSprite->getPosition().y;
}


/**
 * Checks if a given sprite has been clicked and returns the result.
 * @param buttonSprite - Sprite to check.
 * @param event
 * @return - result
 */
bool Utilities::checkMouseclick(sf::Sprite *buttonSprite, sf::Event event) {
    return event.mouseButton.x + buttonSprite->getGlobalBounds().width / 2 > buttonSprite->getPosition().x &&
           event.mouseButton.x - buttonSprite->getGlobalBounds().width / 2 < buttonSprite->getPosition().x &&
           event.mouseButton.y + buttonSprite->getGlobalBounds().height / 2 > buttonSprite->getPosition().y &&
           event.mouseButton.y - buttonSprite->getGlobalBounds().height / 2 < buttonSprite->getPosition().y;
}

/**
 * Returns the mutebutton
 * @return - mutebutton
 */
sf::Sprite *Utilities::getMuteButton() const {
    return muteButton;
}

/**
 * Receives a string and current language, checks if there's a translation and translates if so and returns the result
 * @param wordToTranslate
 * @param language - Current selected language
 * @return - translated word
 */
sf::String Utilities::translate(sf::String wordToTranslate, int language) {
    std::transform(wordToTranslate.begin(), wordToTranslate.end(), wordToTranslate.begin(), ::tolower);
    if (languageMap.find(wordToTranslate) != languageMap.end()) {
        switch (language) {
            case 1:
                return std::get<0>(languageMap.find(wordToTranslate)->second);
            case 2:
                return std::get<1>(languageMap.find(wordToTranslate)->second);
            case 3:
                return std::get<2>(languageMap.find(wordToTranslate)->second);
            default:
                return wordToTranslate;
        }
    } else return wordToTranslate;
}

Utilities::~Utilities() {
    delete this->font;
    delete this->muteButton;
    for (int i = 0; i < 2; ++i) {
        delete this->muteTextures[i].buttonClicked;
        delete this->muteTextures[i].buttonMouseOver;
        delete this->muteTextures[i].buttonNormal;
    }
}

