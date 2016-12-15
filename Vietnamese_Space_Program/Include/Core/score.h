#ifndef VIETNAMESE_SPACE_PROGRAM_SCORE_H
#define VIETNAMESE_SPACE_PROGRAM_SCORE_H

#include <string>
#include <SFML/Graphics.hpp>
#include "utilities.h"

class Score : public sf::Text
{
public:
    virtual ~Score();

    Score(sf::Font &font, unsigned int size);
    void incrementScore();
    void updateScore(std::string scoreText);
    int getValue() const;
private:
    Utilities util;
    int value;
};

#endif //VIETNAMESE_SPACE_PROGRAM_SCORE_H
