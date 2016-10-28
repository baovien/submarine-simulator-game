#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>

#ifndef VIETNAMESE_SPACE_PROGRAM_SCORE_H
#define VIETNAMESE_SPACE_PROGRAM_SCORE_H

class Score : public sf::Text
{
public:
    Score();
    void IncrementScore();
    void Update();

protected:
    int Value;
};

#endif //VIETNAMESE_SPACE_PROGRAM_SCORE_H
