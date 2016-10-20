#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../Header Files/Core/state.h"
#include "../Header Files/States/menu.h"

game_state coreState;
bool quitGame = false;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Pong"); // FULL HD OMG
    coreState.SetWindow(&window);
    coreState.SetState(new main_menu);

    sf::Clock timer;
    sf::Time elapsed;

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

        /**
         * Vi vil at den skal kjøre med nøyaktighet på 1/60 sekund. 1/60 sekunder = 16666 mikrosekunder.
         * Dette tilsvarer ca. 60 fps..
         */
        elapsed = timer.getElapsedTime();
        if(elapsed.asMicroseconds() > 16666){
            window.clear(sf::Color::Black);
            coreState.Update();
            coreState.Render();
            window.display();

            if(quitGame)
            {
                window.close();
            }

            timer.restart();
        }

    }

    return 0;
}