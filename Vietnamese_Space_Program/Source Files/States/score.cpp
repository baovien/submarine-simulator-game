#include "../../Header Files/States/score.h"
#include <iostream>
#include <stdio.h>

using namespace std;

void score::loadScore(){
    file.open("Scorestatus.txt");
    file << "Heihei BAO BAO BAO BAO BAO BAO"<<endl;
    file.close();
    return;
}
