#include <cstring>
#include "../../Header Files/States/StateGameMode2.h"
#include "../../Header Files/States/StateMainMenu.h"

void StateGameMode2::initialize(sf::RenderWindow *window){

    sf::View newView( sf::FloatRect( 0, 0, window->getSize().x, window->getSize().y ) );
    window->setView(newView);

    memset(machine.keyPressed, 0, sizeof(machine.keyPressed)); //For at tastetrykk gjort i andre states ikke skal beholdes

    this->bgTexture = new sf::Texture();
    this->bgTexture->loadFromFile("Graphics/Sprites/bg_purple.png");

    this->background = new sf::Sprite();
    this->background->setTexture(*this->bgTexture);
    this->background->scale(1.5,1.5);

    util = new Utilities();

    manager = new EntityManager();
    this->manager->addEntity("ship", new Player(this->lives, this->score, this->manager, window->getSize().x /2, window->getSize().y/2));

    this->font = new sf::Font();
    this->font->loadFromFile("Graphics/font.ttf");

    this->pausedText = new sf::Text("Paused\nPress Q to Quit", *font, 32U);
    this->pausedText->setOrigin(this->pausedText->getGlobalBounds().width / 2, this->pausedText->getGlobalBounds().height / 2);
    this->pausedText->setPosition(window->getSize().x / 2, window->getSize().y / 2);
}
void StateGameMode2::update(sf::RenderWindow *window){

    if (!util->paused) //Stopper spillet fra å oppdateres når det pauses
    {
        this->manager->updateEntity(window);

    }
    else if(machine.keyPressed[sf::Keyboard::Q]){
        machine.setState(new StateMainMenu());
    }
    if (machine.keyPressed[sf::Keyboard::P] || machine.keyPressed[sf::Keyboard::Escape])
    {
        memset(machine.keyPressed, 0, sizeof(machine.keyPressed));
        util->pauseScreen();                        //Kaller pausefunksjonen
    }
}
void StateGameMode2::render(sf::RenderWindow *window){
    window->draw(*this->background);

    if (util->paused)
    {
        window->draw(*this->pausedText);
    }
}
void StateGameMode2::destroy(sf::RenderWindow *window){
    delete this->util;
    delete this->font;
    delete this->pausedText;
    delete this->background;

}