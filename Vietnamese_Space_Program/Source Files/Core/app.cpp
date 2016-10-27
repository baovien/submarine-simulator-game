#include "../../Header Files/Core/app.h"

//Tastetrykk som kun skal registreres én gang:
//if(machine.keyPressed[sf::Keyboard:::DinTast])
// {
//memset(machine.keyPressed, 0, sizeof(machine.keyPressed));
//KODE
//}
//om du skal triggere det på release bruker du bare keyReleased istedet for keyPressed

void App::run(){
    score sc;
    sc.loadScore();

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Vietnamese Space Program"); // FULL HD OMG
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);

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
            if (event.type == sf::Event::KeyPressed)                    //Array som inneholder alle taster.
                machine.keyPressed[event.key.code] = true;              //De er her for å lagre tastetrykk og slipp uten
                                                                        //å måtte ha alt inne i pollEventet.
            if (event.type == sf::Event::KeyReleased)                   //De opprettes i machine.h
                machine.keyReleased[event.key.code] = true;
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
