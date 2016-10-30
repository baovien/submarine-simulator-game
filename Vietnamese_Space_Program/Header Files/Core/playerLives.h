
#include <SFML/Graphics.hpp>

#ifndef VIETNAMESE_SPACE_PROGRAM_PLAYERLIVES_H
#define VIETNAMESE_SPACE_PROGRAM_PLAYERLIVES_H

class Lives : public sf::Text
{
public:
    Lives(sf::Font &font, unsigned int size);
    void increaseLife();
    void decreaseLife();
    void updateLife();
    int value;
private:
};
#endif //VIETNAMESE_SPACE_PROGRAM_PLAYERLIVES_H
