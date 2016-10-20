#pragma once
#include <iostream>
#include <fstream>
#include <string>
#ifndef VIETNAMESE_SPACE_PROGRAM_SCORE_H
#define VIETNAMESE_SPACE_PROGRAM_SCORE_H

class score {
public:
    void loadScore();

protected:
    std::ofstream file;
};

#endif //VIETNAMESE_SPACE_PROGRAM_SCORE_H
