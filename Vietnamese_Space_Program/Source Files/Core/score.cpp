#include "../../Header Files/Core/score.h"

Score::Score(sf::Font &font, unsigned int size) : sf::Text("Score: 0", font, size)
{
    this->value = 0;

}
void Score::incrementScore()
{
    this->value += 1;
}
void Score::updateScore()
{
    this->setString("Score: " + std::to_string(this->value));
}

int Score::getValue() const {

    return value;
}
