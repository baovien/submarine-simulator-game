#include "../../Include/Core/score.h"

/**
 * Score's constructor
 * @param font
 * @param size - Font size
 * @return
 */
Score::Score(sf::Font &font, unsigned int size) : sf::Text("Score: 0", font, size)
{
    this->value = 0;

}

/**
 * Increments the current score
 */
void Score::incrementScore()
{
    this->value += 1;
}

/**
 * Set's the score's text to the current score
 * @param scoreText - receives the current text.
 */
void Score::updateScore(std::string scoreText)
{
    this->setString(scoreText + ": " + std::to_string(this->value));
}

/**
 * getter for score value
 * @return - score
 */
int Score::getValue() const
{

    return value;
}
