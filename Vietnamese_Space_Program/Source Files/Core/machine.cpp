#include "../../Header Files/Core/machine.h"

Machine::Machine()
{
    this->state = NULL;
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