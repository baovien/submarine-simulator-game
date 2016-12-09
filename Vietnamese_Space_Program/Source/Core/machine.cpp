#include "../../Include/Core/machine.h"

Machine::Machine()
{
    this->state = NULL;
    soundLoaderPointer->initSoundPointers(mutedPointer, mutedMusicPointer);
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
