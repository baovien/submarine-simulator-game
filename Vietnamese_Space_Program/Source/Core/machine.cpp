#include "../../Include/Core/machine.h"

/**
 * Machine's constructor.
 * @return
 */
Machine::Machine()
{
    this->state = NULL;
    audioLoaderPointer->initSoundPointers(mutedPointer, mutedMusicPointer);

}

/**
 * Sets the window as our window. The pointer is passed to all states.
 * @param window
 */
void Machine::setWindow(sf::RenderWindow *window)
{
    this->window = window;
}

/**
 * Sets the state to the given state
 * @param state - State to switch to
 */
void Machine::setState(States *state)
{
    if(this->state != NULL)
    {
        this->state->destroy(this->window);
        delete this->state;
    }
    this->state = state;
    if(this->state != NULL)
    {
        this->state->initialize(this->window);
    }
}

/**
 * Calls the reinitialize function of the current state.
 */
void Machine::reinitialize()
{
    if(this->state != NULL)
    {
        this->state->reinitialize(this->window);
    }
}

/**
 * Calls the current state's update function
 */
void Machine::update()
{
    if(this->state != NULL)
    {
        this->state->update(this->window);
    }
}

/**
 * Calls the current state's render function.
 */
void Machine::render()
{
    if(this->state != NULL)
    {
        this->state->render(this->window);
    }
}

/**
 * Machine's deconstructor
 */
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
/**
 * Setter for player's score.
 * @param playerScore
 */
void Machine::setGameOverScore(int playerScore) {
    Machine::gameOverScore = playerScore;
}
/**
 * Getter for player's score.
 * @return
 */
int Machine::getGameOverScore() const {
    return gameOverScore;
}
