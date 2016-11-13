#include <SFML/Graphics.hpp>

#ifndef VIETNAMESE_SPACE_PROGRAM_UTIL_H
#define VIETNAMESE_SPACE_PROGRAM_UTIL_H

class Utilities {
public:
    bool paused = false;

    void pauseScreen() {
        //Funksjonen setter og fjerner pause
        paused = !paused;
    }
};

#endif //VIETNAMESE_SPACE_PROGRAM_UTIL_H
