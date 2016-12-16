#ifndef SUBMARINESIMULATORPLAYERLIVES_H
#define SUBMARINESIMULATORPLAYERLIVES_H

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
#endif //SUBMARINESIMULATORPLAYERLIVES_H
