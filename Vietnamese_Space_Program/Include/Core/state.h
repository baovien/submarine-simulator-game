#ifndef VIETNAMESE_SPACE_PROGRAM_STATE_H
#define VIETNAMESE_SPACE_PROGRAM_STATE_H

#include <SFML/Graphics.hpp>
#include <SFGUI/Widget.hpp>
#include <SFGUI/SFGUI.hpp>

class States
{
public:
    virtual void initialize(sf::RenderWindow *window)
    {

    }
    virtual void reinitialize(sf::RenderWindow *window)
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
    virtual void handleEvent(sf::RenderWindow *window, sf::Event event)
    {

    }
    ~States()
    {

    }
};
#endif //VIETNAMESE_SPACE_PROGRAM_STATE_H
