#pragma once

#ifndef VIETNAMESE_SPACE_PROGRAM_STATE_H
#define VIETNAMESE_SPACE_PROGRAM_STATE_H
#include <SFML/Graphics.hpp>

class States
{
public:
    virtual void initialize(sf::RenderWindow *window)
    {

    }
    virtual void update(sf::RenderWindow *window)
    {

    }
    virtual void render(sf::RenderWindow *window)
    {

    }
    virtual void destroy(sf::RenderWindow *window)
    {

    }
    ~States()
    {

    }
};

class game_state
{
public:
    game_state()
    {
        this->state = NULL;
    }
    void setWindow(sf::RenderWindow *window)
    {
        this->window = window;
    }
    void setState(States *state)
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

    void update()
    {
        if(this->state != NULL)
        {
            this->state->update(this->window);
        }
    }
    void render()
    {
        if(this->state != NULL)
        {
            this->state->render(this->window);
        }
    }
    ~game_state()
    {
        if(this->state != NULL)
        {
            this->state->destroy(this->window);
        }
    }
private:
    sf::RenderWindow* window;
    States* state;
};

extern game_state coreState;
extern bool quitGame;

#endif //VIETNAMESE_SPACE_PROGRAM_STATE_H
