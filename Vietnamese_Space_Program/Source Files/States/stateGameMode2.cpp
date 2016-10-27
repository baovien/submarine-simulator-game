#include "../../Header Files/States/stateGameMode2.h"
#include "../../Header Files/States/stateMainMenu.h"

void stateGameMode2::initialize(sf::RenderWindow *window){

    util = new Utilities();
    this->pausedText = new sf::Text("Paused\nPress Escape to Quit", *font, 32U);
    this->pausedText->setOrigin(this->pausedText->getGlobalBounds().width / 2, this->pausedText->getGlobalBounds().height / 2);
    this->pausedText->setPosition(window->getSize().x / 2, window->getSize().y / 2);
}
void stateGameMode2::update(sf::RenderWindow *window){

    if (!util->paused) //Stopper spillet fra å oppdateres når det pauses
    {

    }
    else if(machine.keyPressed[sf::Keyboard::Escape]){
        machine.setState(new stateMainMenu());
    }

    if (machine.keyPressed[sf::Keyboard::P])
    {
        memset(machine.keyPressed, 0, sizeof(machine.keyPressed));
        util->pauseScreen();                        //Kaller pausefunksjonen
    }
}
void stateGameMode2::render(sf::RenderWindow *window){
    window->draw(*this->lives);

    if (util->paused)
    {
        window->draw(*this->pausedText);
    }
}
void stateGameMode2::destroy(sf::RenderWindow *window){
    delete this->util;
    delete this->font;
    delete this->pausedText;
    delete this->lives;

}