#ifndef VIETNAMESE_SPACE_PROGRAM_UTIL_H
#define VIETNAMESE_SPACE_PROGRAM_UTIL_H

#include <SFML/Graphics.hpp>

class Utilities {
private:
    sf::Font *font;
public:
    bool paused = false;

    void pauseScreen() {
        //Funksjonen setter og fjerner pause
        paused = !paused;
    }

    //Texture, scale x, scale y, position x, position y, window
    sf::Sprite *addButton(sf::Texture texture, float scaleX, float scaleY, float posX, float posY, sf::RenderWindow *window) {
        sf::Sprite *button = new sf::Sprite();
        button->setTexture(texture);
        button->setOrigin(button->getGlobalBounds().width / 2, button->getGlobalBounds().height / 2);
        // button->scale(window->getSize().x / button->getGlobalBounds().width / scaleX, window->getSize().x / button->getGlobalBounds().width / scaleY);
        button->setPosition(posX, posY);

        return button;
    }

//Text, textsize, origin x, origin y, position x, position y, window
    sf::Text *addText(std::string textContent, unsigned int textSize, int originX, int originY, float posX, float posY, sf::RenderWindow *window) {
        this->font = new sf::Font();
        this->font->loadFromFile("Graphics/Turtles.otf");

        sf::Text *text = new sf::Text(textContent, *this->font, textSize);
        text->setOrigin(text->getGlobalBounds().width / originX, text->getGlobalBounds().height / originY);
        text->setPosition(posX, posY);
        text->scale(window->getSize().x /1280.f, window->getSize().y/720.f);
        return text;
    }

//Tar inn sprite og returnerer true om mouseover
    bool checkMouseover(sf::Sprite *buttonSprite, sf::RenderWindow *window) {

        return sf::Mouse::getPosition(*window).x + buttonSprite->getGlobalBounds().width / 2 > buttonSprite->getPosition().x &&
               sf::Mouse::getPosition(*window).x - buttonSprite->getGlobalBounds().width / 2 < buttonSprite->getPosition().x &&
               sf::Mouse::getPosition(*window).y + buttonSprite->getGlobalBounds().height / 2 > buttonSprite->getPosition().y &&
               sf::Mouse::getPosition(*window).y - buttonSprite->getGlobalBounds().height / 2 < buttonSprite->getPosition().y;
    }

//Tar inn sprite og returnerer true om mouseclick
    bool checkMouseclick(sf::Sprite *buttonSprite, sf::Event event) {
        return event.mouseButton.x + buttonSprite->getGlobalBounds().width / 2 > buttonSprite->getPosition().x &&
               event.mouseButton.x - buttonSprite->getGlobalBounds().width / 2 < buttonSprite->getPosition().x &&
               event.mouseButton.y + buttonSprite->getGlobalBounds().height / 2 > buttonSprite->getPosition().y &&
               event.mouseButton.y - buttonSprite->getGlobalBounds().height / 2 < buttonSprite->getPosition().y;
    }

};

#endif //VIETNAMESE_SPACE_PROGRAM_UTIL_H
