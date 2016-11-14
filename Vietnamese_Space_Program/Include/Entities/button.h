//
// Created by Anders on 14.11.2016.
//

#ifndef VIETNAMESE_SPACE_PROGRAM_BUTTON_H
#define VIETNAMESE_SPACE_PROGRAM_BUTTON_H

#include <SFML/Graphics.hpp>

class Button{
public:
    sf::Sprite* addButton();
    sf::Text* addText();

    sf::Sprite* editButton();
    sf::Text* editText();
private:

};

#endif //VIETNAMESE_SPACE_PROGRAM_BUTTON_H
