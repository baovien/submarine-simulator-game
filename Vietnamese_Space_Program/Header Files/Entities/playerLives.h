#pragma once

#ifndef VIETNAMESE_SPACE_PROGRAM_PLAYERLIVES_H
#define VIETNAMESE_SPACE_PROGRAM_PLAYERLIVES_H

#include <SFML/Graphics.hpp>

class PlayerLives : public sf::Text
{
public:
    PlayerLives(sf::Font &font, unsigned int size);
    void incrementLife();
    void decreaseLife();
    void updateLife();
private:
    int lifeValue;
};
#endif //VIETNAMESE_SPACE_PROGRAM_PLAYERLIVES_H
