
#include <iostream>
#include "../../Include/Core/app.h"
#include "../../Include/Core/utilities.h"

//Tastetrykk som kun skal registreres én gang:
//if(event.key.code == sf::Keyboard::DINTAST){ KODE }
//Dersom tasten du skal bruke kan endres i keybinds skriver du
//if(event.key.code == event.key.code == machine.keybindMap->find("DET DU VIL")->second.second){ KODE }
//der DET DU VIL er navnet på det du ønsker å triggere. Enten up, down, left, right, select, back, shoot eller pause

void App::run() {

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Vietnamese Space Program"); //, sf::Style::Titlebar | sf::Style::Close) FULL HD OMG

    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);
    Utilities util;

    machine.setWindow(&window);
    machine.setState(new StateMainMenu);

    sf::Clock timer;
    sf::Time deltaTime;
    while (window.isOpen()) {
        //Make event to prevent crash
        window.setFramerateLimit(util.getFramerate());
        sf::Event event;

        while (window.pollEvent(event)) {
            //Close down window
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::Resized) {
                machine.reinitialize();
//                window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
            } else machine.eventHandler(event);
        }

        /**
         * Vi vil at den skal kjøre med nøyaktighet på 1/60 sekund. 1/60 sekunder = 16666 mikrosekunder.
         * Dette tilsvarer ca. 60 fps..
         */
        deltaTime = timer.getElapsedTime();
        //window.clear(sf::Color::Black);
        machine.update();
        machine.render();
        window.display();

        if (quitGame) {
            window.close();
        }
        timer.restart();
    }
}
