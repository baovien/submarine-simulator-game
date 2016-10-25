#include "../../Header Files/Core/app.h"

void App::run(){
    score sc;
    sc.loadScore();

    sf::RenderWindow window(sf::VideoMode(800, 600), "Vietnamese Space Program"); // FULL HD OMG
    window.setVerticalSyncEnabled(true);

    machine.setWindow(&window);
    machine.setState(new stateMainMenu);

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
            machine.update();
            machine.render();
            window.display();

            if(quitGame)
            {
                window.close();
            }

            timer.restart();
        }

    }
}