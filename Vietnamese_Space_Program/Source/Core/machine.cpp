#include "../../Include/Core/machine.h"

Machine::Machine()
{
    this->state = NULL;
    keybindMap = new std::map<const std::string, std::pair<std::string, int>>;
    *keybindMap ={{"up", std::make_pair("W" , sf::Keyboard::W)},
                  {"down",   std::make_pair("S" , sf::Keyboard::S)},
                  {"left",   std::make_pair("A" , sf::Keyboard::A)},
                  {"right",  std::make_pair("D" , sf::Keyboard::D)},
                  {"select", std::make_pair("Return" , sf::Keyboard::Return)},
                  {"back",   std::make_pair("Escape" , sf::Keyboard::Escape)},
                  {"shoot",  std::make_pair("Space" , sf::Keyboard::Space)},
                  {"pause",  std::make_pair("P" , sf::Keyboard::P)}};
}
void Machine::setWindow(sf::RenderWindow *window)
{
    this->window = window;
}
void Machine::setState(States *state)
{
    if(this->state != NULL)
    {
        this->state->destroy(this->window);
    }
    this->state = state;
    if(this->state != NULL)
    {
        this->state->initialize(this->window);
    }
}
void Machine::reinitialize()
{
    if(this->state != NULL)
    {
        this->state->reinitialize(this->window);
    }
}

void Machine::update()
{
    if(this->state != NULL)
    {
        this->state->update(this->window);
    }
}
void Machine::render()
{
    if(this->state != NULL)
    {
        this->state->render(this->window);
    }
}
Machine::~Machine()
{
    if(this->state != NULL)
    {
        this->state->destroy(this->window);
    }
}
void Machine::eventHandler(sf::Event event)
{
    if(this->state != NULL)
    {
        this->state->handleEvent(this->window, event);
    }
}

void Machine::setGameOverScore(int playerScore) {
    Machine::gameOverScore = playerScore;
}

int Machine::getGameOverScore() const {
    return gameOverScore;
}
