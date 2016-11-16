//
// Created by Anders on 14.11.2016.
//

#ifndef VIETNAMESE_SPACE_PROGRAM_BUTTON_H
#define VIETNAMESE_SPACE_PROGRAM_BUTTON_H

#include <SFML/Graphics.hpp>

class Buttons{
public:
    //Texture, scale x, scale y, position x, position y
    sf::Sprite* addButton(sf::Texture, float, float, float, float, sf::RenderWindow *window);

    //Text, textsize, origin x, origin y, position x, position y
    sf::Text* addText(std::string, unsigned int, int, int, float, float);

    //Tar inn sprite og returnerer true om mouseover
    bool checkMouseover(sf::Sprite*, sf::RenderWindow*);

    //Tar inn sprite og returnerer true om mouseclick
    bool checkMouseclick(sf::Sprite*, sf::Event event);

private:
    sf::Font* font;

};

#endif //VIETNAMESE_SPACE_PROGRAM_BUTTON_H
