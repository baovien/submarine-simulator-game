#include "../../Header Files/Entities/playerLives.h"

Lives::Lives(sf::Font &font, unsigned int size) : sf::Text("Lives : 3", font, size){
    this->value = 3;
}
void Lives::decreaseLife(){
    this->value -= 1;
}
void Lives::incrementLife(){
    this->value += 1;
}
void Lives::updateLife(){
    this->setString("Lives : " + std::to_string(this->value));
}