//
// Created by andgh_000 on 20/10/2016.
//

#ifndef VIETNAMESE_SPACE_PROGRAM_UTIL_H
#define VIETNAMESE_SPACE_PROGRAM_UTIL_H
#include <SFML/Graphics.hpp>
class Utilities{
public:
bool paused = false;

void pauseScreen(){
    //Funksjonen setter og fjerner pause
    paused = !paused;
}
};
#endif //VIETNAMESE_SPACE_PROGRAM_UTIL_H
