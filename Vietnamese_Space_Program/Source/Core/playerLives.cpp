#include "../../Include/Core/playerLives.h"

Lives::Lives(sf::Font &font, unsigned int size) : sf::Text("Lives : 3", font, size) {
    this->value = 5;
}
void Lives::decreaseLife() {
    this->value -= 1;
}

void Lives::increaseLife() {
    this->value += 1;
}

void Lives::updateLife(std::string livesText) {
    this->setString(livesText + ": " + std::to_string(this->value));
}

int Lives::getValue() const {
    return value;
}
int Lives::setValue(int life){
    this->value = life;
}

