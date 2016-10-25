#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../Header Files/Core/state.h"
#include "../Header Files/States/menu.h"
#include "../Header Files/States/Score.h"

#include <fstream>

game_state coreState;
bool quitGame = false;

int main() {

    Score sc;
    sc.loadScore();

    sf::RenderWindow window(sf::VideoMode(800, 600), "Vietnamese Space Program"); // FULL HD OMG
    window.setVerticalSyncEnabled(true);

    coreState.setWindow(&window);
    coreState.setState(new MainMenu);

    sf::Clock timer;
    sf::Time elapsed;

    while(window.isOpen())
    {
        //Make event to prevent crash
        sf::Event event;

        while(window.pollEvent(event))
        {
            //Close down window
            if(event.type == sf::Event::Closed){
                window.close();
            }

            if(event.type == sf::Event::Resized){
                window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
            }
        }

        /**
         * Vi vil at den skal kjøre med nøyaktighet på 1/60 sekund. 1/60 sekunder = 16666 mikrosekunder.
         * Dette tilsvarer ca. 60 fps..
         */
        elapsed = timer.getElapsedTime();
        if(elapsed.asMicroseconds() > 16666){
            window.clear(sf::Color::Black);
            coreState.update();
            coreState.render();
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
