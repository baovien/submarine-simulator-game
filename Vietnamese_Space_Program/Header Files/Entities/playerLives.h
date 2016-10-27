#pragma once

#ifndef VIETNAMESE_SPACE_PROGRAM_PLAYERLIVES_H
#define VIETNAMESE_SPACE_PROGRAM_PLAYERLIVES_H

#include <SFML/Graphics.hpp>

class Lives : public sf::Text
{
public:
    Lives(sf::Font &font, unsigned int size);
    void decreaseLife();
    void incrementLife();
    void updateLife();
    int value;
private:
};

#endif //VIETNAMESE_SPACE_PROGRAM_PLAYERLIVES_H
