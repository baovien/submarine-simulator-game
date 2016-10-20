//
// Created by andgh_000 on 20/10/2016.
//

#ifndef VIETNAMESE_SPACE_PROGRAM_UTIL_H
#define VIETNAMESE_SPACE_PROGRAM_UTIL_H
#include <SFML/Graphics.hpp>
class Utilities{
public:
bool paused = false;
bool pReleased = true;

void pauseScreen(){
    //Funksjonen setter og fjerner pause
    if(paused && pReleased)
    {
            paused = false;
            pReleased = false;
    }
    else if(!paused && pReleased)
    {
        pReleased = false;
        paused = true;
    }
}
};
#endif //VIETNAMESE_SPACE_PROGRAM_UTIL_H
