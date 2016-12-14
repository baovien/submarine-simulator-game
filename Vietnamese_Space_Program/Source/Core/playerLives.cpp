#include "../../Include/Core/playerLives.h"

/**
 * Lives' constructor
 * @param font - Font for the text.
 * @param size - Text size.
 * @return
 */
Lives::Lives(sf::Font &font, unsigned int size) : sf::Text("Lives :", font, size) {
    this->value = 5;
}

/**
 * Decrements lives
 */
void Lives::decreaseLife() {
    this->value -= 1;
}

/**
 * Increments lives
 */
void Lives::increaseLife() {
    this->value += 1;
}

/**
 * Updates the livestext shown in the game modes.
 * @param livesText - Text
 */
void Lives::updateLife(std::string livesText) {
    this->setString(livesText + ": " + std::to_string(this->value));
}

/**
 * Getter for lives value.
 * @return - lives value.
 */
int Lives::getValue() const {
    return value;
}

