#ifndef VIETNAMESE_SPACE_PROGRAM_STATE_H
#define VIETNAMESE_SPACE_PROGRAM_STATE_H

#include <SFML/Graphics.hpp>

class States
{
public:
    /**
     * Initializes the variables in a state.
     * @param window
     */
    virtual void initialize(sf::RenderWindow *window)
    {

    }

    /**
     * In case of resize reinitializes the window. In the game modes initialize is not called, but the values of all the variables
     * are adjusted according to the resized window.
     * In menu states destroy and intialize are simply called in that order. This is fine since it takes no time to initialize a
     * state in this game and never will.
     * @param window
     */
    virtual void reinitialize(sf::RenderWindow *window)
    {

    }

    /**
     * Updates whatever needs to be updated inside of the state. This varies a lot, but will generally be mouseovers and
     * all other non-event needed updates.
     * @param window
     */
    virtual void update(sf::RenderWindow *window)
    {

    }

    /**
     * Draws the variables to the window.
     * @param window
     */
    virtual void render(sf::RenderWindow *window)
    {

    }

    /**
     * Destroys pointers in the state. A deconstructor for the state.
     * @param window
     */
    virtual void destroy(sf::RenderWindow *window)
    {

    }

    /**
     * handles an event inside the state. Is called whenever there is an event.
     * @param window
     * @param event - The entire event.
     */
    virtual void handleEvent(sf::RenderWindow *window, sf::Event event)
    {

    }

    /**
     * Deconstructor for States.
     */
    ~States()
    {

    }
};
#endif //VIETNAMESE_SPACE_PROGRAM_STATE_H
