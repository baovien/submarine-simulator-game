#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "state.h"
#include "menu.h"

game_state coreState;
bool quitGame = false;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Pong"); // FULL HD OMG
    coreState.SetWindow(&window);
    coreState.SetState(new main_menu);

    while(window.isOpen())
    {
        //Make event to prevent crash
        sf::Event event;
        while(window.pollEvent(event))
        {
            //Close down window
            if(event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        coreState.Update();
        coreState.Render();
        window.display();

        if(quitGame)
        {
            window.close();
        }

    }

    return 0;
}