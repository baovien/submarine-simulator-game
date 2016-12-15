#include "../../Include/States/stateSettings.h"
#include "../../Include/States/stateMainMenu.h"
#include "../../Include/States/stateKeybindings.h"


void StateSettings::initialize(sf::RenderWindow *window) {
    sf::View newView(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
    window->setView(newView);

    this->bgTexture = new sf::Texture();
    this->bgTexture->loadFromFile("Graphics/Sprites/bakgrunn.png");

    this->background = new sf::Sprite();
    this->background->setTexture(*this->bgTexture);
    this->background->scale(window->getSize().x / background->getGlobalBounds().width, window->getSize().y / background->getGlobalBounds().height);

    this->obTexture = new sf::Texture();
    this->obTexture->loadFromFile("Graphics/Sprites/Window/Window_10.png");

    this->overlayBackground = new sf::Sprite();
    this->overlayBackground->setTexture(*this->obTexture);
    this->overlayBackground->setOrigin(this->overlayBackground->getGlobalBounds().width / 2, this->overlayBackground->getGlobalBounds().height / 2);
    this->overlayBackground->scale(window->getSize().x / overlayBackground->getGlobalBounds().width / 2, window->getSize().y / overlayBackground->getGlobalBounds().height / 2);
    this->overlayBackground->setPosition(window->getSize().x / 2, window->getSize().y / 2);

    //Lager alle flagknappene og laster inn alle textures til flaggene.
    for (unsigned int i = 0; i < sizeof(settingsFlagTextures) / sizeof(*settingsFlagTextures); ++i) {
        settingsFlagTextures[i] = new sf::Texture();
        settingsFlagTextures[i]->loadFromFile("Graphics/Sprites/Settings_buttons/flag" + std::to_string(i) + ".png");

        settingsFlagButtons[i] = new sf::Sprite();
        settingsFlagButtons[i]->setTexture(*this->settingsFlagTextures[i]);
        settingsFlagButtons[i]->setOrigin(settingsFlagButtons[i]->getGlobalBounds().width / 2, settingsFlagButtons[i]->getGlobalBounds().height / 2);
        settingsFlagButtons[i]->scale(window->getSize().x / 4800.f, window->getSize().y / 2700.f);
        if (i == (unsigned) machine.settingPointer->selectedLanguage) {
            settingsFlagButtons[i]->setColor(sf::Color(255, 255, 255, 255));
        } else
            settingsFlagButtons[i]->setColor(sf::Color(255, 255, 255, 125));
    }
    //Lager alle knapper og laster inn alle textures til knappene
    for (unsigned int i = 0; i < sizeof(settingsTextures) / sizeof(*settingsTextures); ++i) {
        settingsTextures[i].buttonMouseOver = new sf::Texture();
        settingsTextures[i].buttonMouseOver->loadFromFile("Graphics/Sprites/Settings_buttons/Btn" + std::to_string(i * 3) + ".png");

        settingsTextures[i].buttonNormal = new sf::Texture();
        settingsTextures[i].buttonNormal->loadFromFile("Graphics/Sprites/Settings_buttons/Btn" + std::to_string(i * 3 + 1) + ".png");

        settingsTextures[i].buttonClicked = new sf::Texture();
        settingsTextures[i].buttonClicked->loadFromFile("Graphics/Sprites/Settings_buttons/Btn" + std::to_string(i * 3 + 2) + ".png");
        //Siden jeg laster inn textures som det ikke skal lages sprite av gjør jeg det ikke for den siste loopen.
        if (i < sizeof(settingsTextures) / sizeof(*settingsTextures) - 1) {
            settingsButtons[i] = new sf::Sprite();
            settingsButtons[i]->setTexture(*this->settingsTextures[i].buttonNormal);
            settingsButtons[i]->setOrigin(settingsButtons[i]->getGlobalBounds().width / 2, settingsButtons[i]->getGlobalBounds().height / 2);
            if (i != 4) //Returnknappen har egen størrelse, så vi scaler den etterpå
                settingsButtons[i]->scale(window->getSize().x / 1280.f, window->getSize().y / 720.f);
        }
    }

    if (*machine.mutedMusicPointer) {
        std::swap(settingsTextures[0], settingsTextures[sizeof(settingsTextures) / sizeof(*settingsTextures) - 1]);
        settingsButtons[0]->setTexture(*this->settingsTextures[0].buttonNormal);
    }
    fpsTextures.buttonMouseOver = new sf::Texture();
    fpsTextures.buttonMouseOver->loadFromFile("Graphics/Sprites/Buttons/Button_33.png");
    fpsTextures.buttonNormal = new sf::Texture();
    fpsTextures.buttonNormal->loadFromFile("Graphics/Sprites/Buttons/Button_34.png");
    fpsTextures.buttonClicked = new sf::Texture();
    fpsTextures.buttonClicked->loadFromFile("Graphics/Sprites/Buttons/Button_35.png");

    for (int i = 0; i < 3; ++i) {
        fpsButtons[i] = new sf::Sprite();
        fpsButtons[i]->setTexture(*this->fpsTextures.buttonNormal);
        fpsButtons[i]->setOrigin(fpsButtons[i]->getGlobalBounds().width / 2, fpsButtons[i]->getGlobalBounds().height / 2);
        fpsButtons[i]->scale(window->getSize().x / 2560.f, window->getSize().y / 1440.f);
        fpsButtons[i]->setPosition(((4 + i * 0.5f) * window->getSize().x) / 6.f, (3 * window->getSize().y) / 4.f);
        if (i == machine.settingPointer->selectedFps) {
            fpsButtons[i]->setTexture(*this->fpsTextures.buttonClicked);
        }

        fpsNumbers[i] = util.addText(fpsWordList[i], 30, 2, 2, fpsButtons[i]->getPosition().x, fpsButtons[i]->getPosition().y - fpsButtons[i]->getGlobalBounds().height / 8, window, machine.settingPointer->selectedLanguage);
    }

    //Siden posisjonene er så varierende setter jeg dem utenfor for-løkken.
    settingsButtons[0]->setPosition(window->getSize().x / 7, window->getSize().y / 2 - window->getSize().y / 6);
    settingsButtons[1]->setPosition(window->getSize().x / 3, window->getSize().y / 2 - window->getSize().y / 6);
    settingsButtons[2]->setPosition(window->getSize().x / 7, window->getSize().y / 2 + window->getSize().y / 6);
    settingsButtons[3]->setPosition(window->getSize().x / 3, window->getSize().y / 2 + window->getSize().y / 6);
    settingsButtons[4]->setPosition(window->getSize().x * 0.95f, window->getSize().y - window->getSize().y / 10);
    settingsButtons[4]->scale(window->getSize().x / 5120.f, window->getSize().y / 2880.f);
    settingsButtons[5]->setPosition(window->getSize().x / 2 - window->getSize().x / 10, window->getSize().y / 2);
    settingsButtons[6]->setPosition(window->getSize().x / 2 + window->getSize().x / 10, window->getSize().y / 2);
    settingsFlagButtons[0]->setPosition((5 * window->getSize().x) / 6, window->getSize().y / 4.f);
    settingsFlagButtons[1]->setPosition((4 * window->getSize().x) / 6, window->getSize().y / 4.f);
    settingsFlagButtons[2]->setPosition((5 * window->getSize().x) / 6, (1.75f * window->getSize().y) / 4.f);
    settingsFlagButtons[3]->setPosition((4 * window->getSize().x) / 6, (1.75f * window->getSize().y) / 4.f);


    //Lager tekstene som skal komme når man mouser over de 4 store knappene. Tekstene er lagret i wordListarrayet.
    for (unsigned int i = 0; i < sizeof(mouseOverText) / sizeof(*mouseOverText); ++i) {
        mouseOverText[i] = util.addText(wordList[i], 30, 2, 2, settingsButtons[i]->getPosition().x, (settingsButtons[i]->getPosition().y - settingsButtons[i]->getGlobalBounds().height / 1.5f), window, machine.settingPointer->selectedLanguage);
        mouseOverText[i]->setFillColor(sf::Color(255, 255, 255, 0));
        mouseOverText[i]->setOutlineColor((sf::Color::Transparent));
    }
    //Text, textsize, origin x, origin y, position x, position y, window
    this->title = util.addText("Settings", 100, 2, 2, window->getSize().x / 2.f, window->getSize().y / 40.f, window, machine.settingPointer->selectedLanguage);
    this->fpsText = util.addText("FPS Cap", 50, 2, 2, (4.5f * window->getSize().x) / 6, (2.5f * window->getSize().y) / 4.f, window, machine.settingPointer->selectedLanguage);
    this->overlayText = util.addText("Are you sure?", 50, 2, 2, window->getSize().x / 2, ((window->getSize().y / 2) - this->overlayBackground->getGlobalBounds().height / 2.25f), window, machine.settingPointer->selectedLanguage);

    util.makeMuteButton(window, machine.mutedPointer);
}

void StateSettings::update(sf::RenderWindow *window) {
    //Sjekker mutedMusicpointer er satt
    machine.soundLoaderPointer->updateSounds();

    if (!inOverlay) {
        util.checkMuteMouseOver(window);
    }
    //Sjekker mouseover på flagg og gjør dem mindre transparent om de er mouseovera
    if (!inOverlay) {
        for (unsigned int i = 0; i < sizeof(settingsFlagTextures) / sizeof(*settingsFlagTextures); ++i) {
            if (util.checkMouseover(settingsFlagButtons[i], window)) {
                settingsFlagButtons[i]->setColor(sf::Color(255, 255, 255, 255));
            } else {
                settingsFlagButtons[i]->setColor(sf::Color(255, 255, 255, 125));
            }
            if (i == (unsigned) machine.settingPointer->selectedLanguage) {
                settingsFlagButtons[i]->setColor(sf::Color(255, 255, 255, 255));
            }
        }
    }
    //Sjekker mouseover og klikk på knapper og setter fargen utifra det.
    for (unsigned int i = 0; i < sizeof(settingsTextures) / sizeof(*settingsTextures) - 1; ++i) {
        if (!inOverlay || (inOverlay && i > 4)) {
            if (util.checkMouseover(settingsButtons[i], window)) {
                if (i < 4) {
                    mouseOverText[i]->setFillColor(sf::Color(255, 255, 255, 255));
                    mouseOverText[i]->setOutlineColor((sf::Color::Black));
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    settingsButtons[i]->setTexture(*this->settingsTextures[i].buttonClicked);
                } else {
                    settingsButtons[i]->setTexture(*this->settingsTextures[i].buttonMouseOver);
                }
            } else {
                if (i < 4) {
                    mouseOverText[i]->setFillColor(sf::Color(255, 255, 255, 0));
                    mouseOverText[i]->setOutlineColor((sf::Color::Transparent));
                }
                settingsButtons[i]->setTexture(*this->settingsTextures[i].buttonNormal);
            }
        }
    }
    //sjekker mouseover og klikk på fpsknapper og setter fargen utifra. Setter alltid valgte fps til buttonClicked.
    if (!inOverlay) {
        for (int i = 0; i < 3; ++i) {
            if (util.checkMouseover(fpsButtons[i], window)) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    fpsButtons[i]->setTexture(*this->fpsTextures.buttonClicked);
                } else {
                    fpsButtons[i]->setTexture(*this->fpsTextures.buttonMouseOver);
                }
            } else {
                fpsButtons[i]->setTexture(*this->fpsTextures.buttonNormal);
            }
            if (i == machine.settingPointer->selectedFps)
                fpsButtons[i]->setTexture(*this->fpsTextures.buttonClicked);
        }
    }
}

void StateSettings::render(sf::RenderWindow *window) {
    window->draw(*this->background);
    for (unsigned int i = 0; i < sizeof(settingsFlagTextures) / sizeof(*settingsFlagTextures); ++i) {
        window->draw(*this->settingsFlagButtons[i]);
    }
    for (unsigned int i = 0; i < sizeof(settingsTextures) / sizeof(*settingsTextures) - 3; ++i) {
        window->draw(*this->settingsButtons[i]);
    }
    for (unsigned int i = 0; i < sizeof(mouseOverText) / sizeof(*mouseOverText); ++i) {
        window->draw(*this->mouseOverText[i]);
    }
    for (int i = 0; i < 3; ++i) {
        window->draw(*this->fpsButtons[i]);
        window->draw(*this->fpsNumbers[i]);
    }
    window->draw(*this->title);
    window->draw(*this->fpsText);
    window->draw(*util.getMuteButton());
    if (inOverlay) {
        window->draw(*this->overlayBackground);
        window->draw(*this->overlayText);
        for (unsigned int i = 5; i < sizeof(settingsTextures) / sizeof(*settingsTextures) - 1; ++i) {
            window->draw(*this->settingsButtons[i]);
        }
    }
}

void StateSettings::destroy(sf::RenderWindow *window) {
    //Destroyer i motsatt rekkefølge av draws
    for (int i = (sizeof(settingsFlagButtons) / sizeof(*settingsFlagButtons)) - 1; i >= 0; --i) {
        delete this->settingsFlagButtons[i];
        delete this->settingsFlagTextures[i];
    }
    for (int i = (sizeof(settingsTextures) / sizeof(*settingsTextures)) - 1; i >= 0; --i) {
        //Ligger en ekstra slot for textures der, så fjerner en mindre knapp
        if (i != (sizeof(settingsTextures) / sizeof(*settingsTextures)) - 1) {
            delete this->settingsButtons[i];
        }
        delete this->settingsTextures[i].buttonClicked;
        delete this->settingsTextures[i].buttonMouseOver;
        delete this->settingsTextures[i].buttonNormal;
    }
    for (int i = (sizeof(mouseOverText) / sizeof(*mouseOverText)) - 1; i >= 0; --i) {
        delete this->mouseOverText[i];
    }
    for (int i = 0; i < 3; ++i) {
        delete this->fpsButtons[i];
        delete this->fpsNumbers[i];
    }
    delete this->fpsTextures.buttonClicked;
    delete this->fpsTextures.buttonNormal;
    delete this->fpsTextures.buttonMouseOver;

    delete this->background;
    delete this->overlayBackground;
    delete this->obTexture;
    delete this->title;
    delete this->fpsText;
    delete this->overlayText;
    delete this->bgTexture;
}

void StateSettings::handleEvent(sf::RenderWindow *window, sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {

        //Back on escapekey
        if (event.key.code == machine.keybindMap->find("back")->second.second) {
            if (inOverlay) {
                inOverlay = false;
            } else {
                machine.setState(new StateMainMenu);
                return;
            }
            return;
        }
    }
    if (event.type == sf::Event::MouseButtonReleased) {
        if (!inOverlay)
            util.checkMuteMouseClick(window, event, machine.mutedPointer);

        if (!inOverlay) {
            for (unsigned int i = 0; i < (sizeof(settingsTextures) / sizeof(*settingsTextures)) - 1; ++i) { //Sjekker knappene i settings uten overlay
                if (util.checkMouseclick(settingsButtons[i], event)) {
                    switch (i) {

                        //Musikknappen trykket
                        case 0:
                            *machine.mutedMusicPointer = !*machine.mutedMusicPointer;
                            std::swap(settingsTextures[0], settingsTextures[sizeof(settingsTextures) / sizeof(*settingsTextures) - 1]);
                            /* if(*machine.mutedMusicPointer){
                                 //HER MÅ VI SKRU AV MUSIKK
                             }
                             else{
                                 //HER MÅ VI SKRU PÅ MUSIKK
                             }*/
                            return;

                            //controlsknappen trykket
                        case 1:
                            bgTexture->create(window->getSize().x, window->getSize().y);
                            bgTexture->update(*window);
                            *machine.backgroundBehindOverlayPointer = bgTexture->copyToImage();
                            machine.setState(new StateKeybindings());
                            return;

                            //reset highscore trykket
                        case 2:
                            bindsOrScore = false;
                            inOverlay = true;
                            return;

                            //reset keybinds trykket
                        case 3:
                            bindsOrScore = true;
                            inOverlay = true;
                            return;

                            //backknappen trykket
                        case 4:
                            machine.setState(new StateMainMenu());
                            return;
                        default:break;
                    }
                }
            }
        }

        //Sjekker overlayknappene (Are you sure? Yes/no). Må sjekke de separat siden den ene knappen overlapper 2 i settings.
        if (inOverlay) {
            for (unsigned int i = (sizeof(settingsTextures) / sizeof(*settingsTextures)) - 3; i < (sizeof(settingsTextures) / sizeof(*settingsTextures)) - 1; ++i) {
                if (util.checkMouseclick(settingsButtons[i], event)) {
                    switch (i) {
                        case 5:
                            if (bindsOrScore) {
                                //RESET BINDS
                                machine.keybindMap->find("up")->second = std::make_pair("W", sf::Keyboard::W);
                                machine.keybindMap->find("down")->second = std::make_pair("S", sf::Keyboard::S);
                                machine.keybindMap->find("left")->second = std::make_pair("A", sf::Keyboard::A);
                                machine.keybindMap->find("right")->second = std::make_pair("D", sf::Keyboard::D);
                                machine.keybindMap->find("select")->second = std::make_pair("Return", sf::Keyboard::Return);
                                machine.keybindMap->find("back")->second = std::make_pair("Escape", sf::Keyboard::Escape);
                                machine.keybindMap->find("shoot")->second = std::make_pair("Space", sf::Keyboard::Space);
                                machine.keybindMap->find("pause")->second = std::make_pair("P", sf::Keyboard::P);

                            } else {
                                for (unsigned int j = 0; j < machine.classicScorePointer->size(); j++){
                                    machine.arcadeScorePointer->clear();
                                    machine.classicScorePointer->clear();

                                    machine.arcadeScorePointer->push_back(std::make_pair(0, "player"));
                                    machine.arcadeScorePointer->push_back(std::make_pair(0, "player"));
                                    machine.arcadeScorePointer->push_back(std::make_pair(0, "player"));

                                    machine.classicScorePointer->push_back(std::make_pair(0, "player"));
                                    machine.classicScorePointer->push_back(std::make_pair(0, "player"));
                                    machine.classicScorePointer->push_back(std::make_pair(0, "player"));
                                }
                            }
                            inOverlay = false;
                            return;
                        case 6:
                            inOverlay = false;
                            return;
                        default:break;
                    }
                }
            }
        }
        if (!inOverlay) {
            for (unsigned int i = 0; i < 3; ++i) {
                if (util.checkMouseclick(fpsButtons[i], event)) {
                    machine.settingPointer->selectedFps = i;
                    switch (i) {
                        case 0:
                            window->setFramerateLimit(30);
                            break;
                        case 1:
                            window->setFramerateLimit(60);
                            break;
                        case 2:
                            window->setFramerateLimit(120);
                            break;
                        default:break;
                    }
                }

            }
        }
        if (!inOverlay) {
            for (unsigned int i = 0; i < (sizeof(settingsFlagButtons) / sizeof(*settingsFlagButtons)); ++i) {
                if (util.checkMouseclick(settingsFlagButtons[i], event)) {
                    if (i != (unsigned) machine.settingPointer->selectedLanguage) {
                        machine.settingPointer->selectedLanguage = i;
                        initialize(window);
                    }

                }
            }
        }
    }
}

void StateSettings::reinitialize(sf::RenderWindow *window) {
    destroy(window);
    initialize(window);
}
