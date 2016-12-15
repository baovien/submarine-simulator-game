#include <cstring>
#include <iostream>
#include <fstream>
#include "../../Include/json/json.h"
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

    srand((unsigned int) time(0)); //gir random tall utifra hvor mange sekunder har gått siden 1. jan 1970

    machine.setWindow(&window);
    machine.setState(new StateMainMenu);

    validateJson();
    loadJson();

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
                    saveJson();
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
            saveJson();
            window.close();
        }
    }
}


/**
 * Validate
 */
void App::validateJson(){
    std::ifstream infile("config.json");
    Json::Value root;
    infile >> root;
    infile.close();

    std::ofstream os("config.json", std::ofstream::trunc); //Overskriver eksisterende fil.
    Json::StyledStreamWriter writer;


    //Feilsjekk for fps og språk. Setter default value
    if(!root["settings"]["fps"].isInt()) root["settings"]["fps"] = 1;
    if(!root["settings"]["language"].isInt()) root["settings"]["language"] = 0;
    if(!root["settings"]["mute"].isBool()) root["settings"]["mute"] = false;
    if(!root["settings"]["muteMusic"].isBool()) root["settings"]["muteMusic"] = false;
    if(root["settings"]["fps"].asInt() > 2 || root["settings"]["fps"].asInt() < 0) root["settings"]["fps"] = 1;
    if(root["settings"]["language"].asInt() > 3 || root["settings"]["language"].asInt() < 0) root["settings"]["language"] = 0;

    writer.write(os, root);

    os.close();
}

/**
 * Save data to config.json
 */
void App::saveJson() {

    std::ifstream infile("config.json");
    if (!infile.is_open()) {
        std::cout << "Creating new config.json" << std::endl;
    }
    infile.close();

    std::ofstream os("config.json", std::ofstream::trunc); //Overskriver eksisterende fil.
    Json::StyledStreamWriter writer;
    Json::Value root;

    ////////////SAVE DATA////////////

    //Highscore
    for (int i = 0; i < 3; ++i) {
        root["highscore"]["arcade"][i]["name"] = machine.arcadeScorePointer->at(i).second;
        root["highscore"]["arcade"][i]["score"] = machine.arcadeScorePointer->at(i).first;
    }
    for (int i = 0; i < 3; ++i) {
        root["highscore"]["classic"][i]["name"] = machine.classicScorePointer->at(i).second;
        root["highscore"]["classic"][i]["score"] = machine.classicScorePointer->at(i).first;
    }

    //Settings
    root["settings"]["muteMusic"] = *machine.mutedMusicPointer;
    root["settings"]["mute"] = *machine.mutedPointer;
    root["settings"]["language"] = machine.settingPointer->selectedLanguage;
    root["settings"]["fps"] = machine.settingPointer->selectedFps;

    //Keybindings
    for (auto elem : *machine.keybindMap) {
        root["settings"]["keybinds"][elem.first].append(elem.second.first);
        root["settings"]["keybinds"][elem.first].append(elem.second.second);
    }

    /////////////////////////////////

    writer.write(os, root);

    os.close();
}

/**
 * Load data from config.json.
 */
void App::loadJson() {
    std::ifstream in("config.json");
    Json::Value root;
    in >> root;

    if (in.is_open()) {
        ///////////LOAD DATA////////////

        //Fjerner verdiene i vectorene.
        machine.arcadeScorePointer->clear();
        machine.classicScorePointer->clear();

        //Laster inn highscores for arcade og classic
        for (Json::Value::iterator it = root["highscore"]["arcade"].begin(); it != root["highscore"]["arcade"].end(); ++it) {
            machine.arcadeScorePointer->push_back(std::make_pair((*it)["score"].asInt(), (*it)["name"].asString()));
        }
        for (Json::Value::iterator it = root["highscore"]["classic"].begin(); it != root["highscore"]["classic"].end(); ++it) {
            machine.classicScorePointer->push_back(std::make_pair((*it)["score"].asInt(), (*it)["name"].asString()));
        }

        //Henter settings
        *machine.mutedMusicPointer = root["settings"]["muteMusic"].asBool();
        *machine.mutedPointer = root["settings"]["mute"].asBool();
        machine.settingPointer->selectedLanguage = root["settings"]["language"].asInt();
        machine.settingPointer->selectedFps = root["settings"]["fps"].asInt();

        //Keybinds

        for (Json::Value::iterator it = root["settings"]["keybinds"].begin(); it != root["settings"]["keybinds"].end(); ++it) {

            machine.keybindMap->find(it.name())->second.first = (*it)[0].asString();
            machine.keybindMap->find(it.name())->second.second = (*it)[1].asInt();

        }

        ///////////////////////////////

        in.close();
    } else {
        std::cout << "Could not find config.json. Applying default values" << std::endl;
    }

}

