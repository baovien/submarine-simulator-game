#include "../../Header Files/States/Score.h"
#include <iostream>
#include <stdio.h>

using namespace std;

void Score::loadScore(){
    file.open("Scorestatus.txt");
    file << "Heihei BAO BAO BAO BAO BAO BAO"<<endl;
    file.close();
    return;
}
