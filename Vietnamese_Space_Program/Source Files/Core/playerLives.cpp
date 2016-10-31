#include "../../Header Files/Core/playerLives.h"

Lives::Lives(sf::Font &font, unsigned int size) : sf::Text("Lives : 3", font, size) {
    this->value = 999;
}

void Lives::decreaseLife() {
    this->value--;
    if (this->value < 0) this->value = 0;
}

void Lives::increaseLife() {
    this->value++;
}

void Lives::updateLife() {
    this->setString("Lives: " + std::to_string(this->value));
}

int Lives::getValue() const {
    return value;
}

