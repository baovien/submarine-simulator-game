
#include <iostream>
#include <cstring>
#include "../../Include/Core/app.h"
#include "../../Include/States/StateSettings.h"


//Tastetrykk som kun skal registreres én gang:
//if(machine.keyPressed[sf::Keyboard:::DinTast])
//{
//memset(machine.keyPressed, 0, sizeof(machine.keyPressed));
//KODE
//}
//om du skal triggere det på release bruker du bare keyReleased istedet for keyPressed
#include "../../Include/Core/app.h"

void App::run(){

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Vietnamese Space Program"); //, sf::Style::Titlebar | sf::Style::Close) FULL HD OMG
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);


    machine.setWindow(&window);
    machine.setState(new StateMainMenu);

    sf::Clock timer;
    sf::Time elapsed;

    while (window.isOpen()) {
        //Make event to prevent crash
        sf::Event event;

        while (window.pollEvent(event)) {
            //Close down window
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::Resized) {
//                window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
            }
            if (event.type == sf::Event::KeyPressed) {                   //Array som inneholder alle taster.
                machine.keyPressed[event.key.code] = true; //Lagrer tastetrykk i et array for senere bruk. Husk å bruke memset etter å ha brukt arrayet


                if (machine.keyPressed[sf::Keyboard::Key::Escape]) {
                    if (!machine.waitingForInput) {
                        memset(machine.keyPressed, 0, sizeof(machine.keyPressed));
                        machine.setState(new StateSettings);
                        break;
                    }
                }


                if (machine.waitingForInput && event.key.code != -1) {
                    bool exists;
                    for (int i = 0; i < 8; ++i) {
                        if (machine.keybindMap.find(machine.wordList[i])->second != machine.keyList[event.key.code]) {
                            exists = false;
                        } else {
                            exists = true;
                            std::cout << "Key already bound" << std::endl;
                            break;
                        }
                    }
                    for (int i = 0; i < 8; ++i) {
                        std::cout << i << ": " << machine.keybindMap.find(machine.wordList[i])->second << std::endl;
                    }
                    if (!exists) {
                        machine.keyPressedInBinds = true;
                        machine.waitingForInput = false;
                        machine.keyToBind = event.key.code;
                    }
                }
            }
            if (event.type == sf::Event::KeyReleased)
                machine.keyReleased[event.key.code] = true;
            if (event.type == sf::Event::MouseButtonPressed)
                machine.mouseClick = sf::Mouse::getPosition(
                        window);          //beholder posisjonen til museklikk som kan sjekkes i andre states
        }

        /**
         * Vi vil at den skal kjøre med nøyaktighet på 1/60 sekund. 1/60 sekunder = 16666 mikrosekunder.
         * Dette tilsvarer ca. 60 fps..
         */
        elapsed = timer.getElapsedTime();
        if (elapsed.asMicroseconds() > 16666) {
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
}
