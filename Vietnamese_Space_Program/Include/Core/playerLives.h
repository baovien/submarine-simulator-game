#ifndef VIETNAMESE_SPACE_PROGRAM_PLAYERLIVES_H
#define VIETNAMESE_SPACE_PROGRAM_PLAYERLIVES_H

#include <SFML/Graphics.hpp>

class Lives : public sf::Text
{
public:
    Lives(sf::Font &font, unsigned int size);
    void increaseLife();
    void decreaseLife();
    void instaKill();
    void updateLife(std::string livesText);
    int getValue() const;

    virtual ~Lives();

private:
    int value;
};
#endif //VIETNAMESE_SPACE_PROGRAM_PLAYERLIVES_H
