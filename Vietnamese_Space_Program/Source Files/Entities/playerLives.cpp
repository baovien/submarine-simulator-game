#include "../../Header Files/Entities/playerLives.h"

PlayerLives::PlayerLives(sf::Font &font, unsigned int size) : sf::Text("Lives: 3", font, size){
    this->lifeValue = 3;
}
void PlayerLives::incrementLife(){
    this->lifeValue += 1;
}
void PlayerLives::decreaseLife(){
    this->lifeValue -= 1;
}
void PlayerLives::updateLife(){
    this->setString("Lives: " + std::to_string(this->lifeValue));
}
