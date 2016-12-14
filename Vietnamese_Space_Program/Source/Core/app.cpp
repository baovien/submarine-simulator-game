#include <cstring>
#include <iostream>
#include <fstream>
#include "../../Include/Core/app.h"

//Tastetrykk som kun skal registreres én gang:
//if(event.key.code == sf::Keyboard::DINTAST){ KODE }
//Dersom tasten du skal bruke kan endres i keybinds skriver du
//if(event.key.code == event.key.code == machine.keybindMap->find("DET DU VIL")->second.second){ KODE }
//der DET DU VIL er navnet på det du ønsker å triggere. Enten up, down, left, right, select, back, shoot eller pause

/**
 * The game's runner.
 */
void App::run() {

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Vietnamese Space Program"); //, sf::Style::Titlebar | sf::Style::Close) FULL HD OMG

    window.setKeyRepeatEnabled(false);

    srand(time(0)); //gir random tall utifra hvor mange sekunder har gått siden 1. jan 1970

    machine.setWindow(&window);
    machine.setState(new StateMainMenu);

    loadSettings();

    window.setFramerateLimit((unsigned int) ((15 * machine.settingPointer->selectedFps * machine.settingPointer->selectedFps) + 15 * machine.settingPointer->selectedFps + 30));
    // 15x^2+15x+30 gir riktig fps utifra selectedFPS 0=30, 1=60, 2=120. Derfor bruker jeg den funksjonen til å sette initialfps
    bool wait = false;
    sf::Clock clock;
    while (window.isOpen()) {
        *machine.deltaTimePointer = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::LostFocus) {
                wait = true;
            }
            if (event.type == sf::Event::GainedFocus) {
                wait = false;
            }
            if (!wait) {
                //Close down window
                if (event.type == sf::Event::Closed) {
                    saveSettings();
                    window.close();
                } else if (event.type == sf::Event::Resized) {
                    machine.reinitialize();
                } else machine.eventHandler(event);
            }
        }

        //window.clear(sf::Color::Black);
        if (!wait) {
            machine.update();
            machine.render();
            window.display();
        }
        if (quitGame) {
            saveSettings();
            window.close();
        }
    }
}

void App::saveSettings() {
    std::ofstream file("highscore.txt");
    if (file.is_open()) {
        //Highscore
        for (int i = 0; i < 8; ++i) {
            if (i < 4 && i != 0) {
                file << std::to_string(machine.arcadeScorePointer->at(i - 1).first) << " " << machine.arcadeScorePointer->at(i - 1).second << std::endl;
            } else if (i > 4) {
                file << std::to_string(machine.classicScorePointer->at(i - 5).first) << " " << machine.classicScorePointer->at(i - 5).second << std::endl;
            }
        }
        file.close();
    } else {
        std::cout << "Unable to open file" << std::endl;
    }
}


void App::loadSettings() {
    std::ifstream file("highscore.txt"); // pass file name as argment

    std::string name;
    int score;
    std::vector<std::pair<int, std::string>> info;

    if (file.is_open()) {
        machine.arcadeScorePointer->clear();
        machine.classicScorePointer->clear();

        //Read settingsfile
        while (file >> score >> name) {
            /* do something with name, var1 etc. */
            info.push_back(std::make_pair(score, name));
        }

        //Load highscore
        for (int i = 0; i < info.size(); ++i) {
            if(i < 3){
                machine.arcadeScorePointer->push_back(info[i]);
            }else{
                machine.classicScorePointer->push_back(info[i]);
            }
        }

        file.close();
    } else {
        std::cout << "Unable to open file" << std::endl;
    }
}

