#ifndef VIETNAMESE_SPACE_PROGRAM_SCORE_H
#define VIETNAMESE_SPACE_PROGRAM_SCORE_H

#include <string>
#include <SFML/Graphics.hpp>


class Score : public sf::Text
{
public:
    Score(sf::Font &font, unsigned int size);
    void incrementScore();
    void updateScore();
    int getValue() const;
private:
    int value;
};

#endif //VIETNAMESE_SPACE_PROGRAM_SCORE_H
