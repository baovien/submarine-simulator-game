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

    //Lager alle flagknappene og laster inn alle textures til flaggene.
    for (unsigned int i = 0; i < sizeof(settingsFlagTextures) / sizeof(*settingsFlagTextures); ++i) {
        settingsFlagTextures[i] = new sf::Texture();
        settingsFlagTextures[i]->loadFromFile("Graphics/Sprites/Settings_buttons/flag" + std::to_string(i) + ".png");

        settingsFlagButtons[i] = new sf::Sprite();
        settingsFlagButtons[i]->setTexture(*this->settingsFlagTextures[i]);
        settingsFlagButtons[i]->setOrigin(settingsFlagButtons[i]->getGlobalBounds().width / 2, settingsFlagButtons[i]->getGlobalBounds().height / 2);
        settingsFlagButtons[i]->scale(window->getSize().x / 4800.f, window->getSize().y / 2700.f);

    }
    //Lager alle knapper og laster inn alle textures til knappene
    for (unsigned int i = 0; i < sizeof(settingsTextures) / sizeof(*settingsTextures); ++i) {
        settingsTextures[i].buttonMouseOver = new sf::Texture();
        settingsTextures[i].buttonMouseOver->loadFromFile("Graphics/Sprites/Settings_buttons/Btn" + std::to_string(i * 3) + ".png");

        settingsTextures[i].buttonNormal = new sf::Texture();
        settingsTextures[i].buttonNormal->loadFromFile("Graphics/Sprites/Settings_buttons/Btn" + std::to_string(i * 3 + 1) + ".png");

        settingsTextures[i].buttonClicked = new sf::Texture();
        settingsTextures[i].buttonClicked->loadFromFile("Graphics/Sprites/Settings_buttons/Btn" + std::to_string(i * 3 + 2) + ".png");

        settingsButtons[i] = new sf::Sprite();
        settingsButtons[i]->setTexture(*this->settingsTextures[i].buttonNormal);
        settingsButtons[i]->setOrigin(settingsButtons[i]->getGlobalBounds().width / 2, settingsButtons[i]->getGlobalBounds().height / 2);
        settingsButtons[i]->scale(window->getSize().x / 1280.f, window->getSize().y / 720.f);
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
        fpsButtons[i]->setPosition(((4 + i * 0.5f) * window->getSize().x) / 6, (3 * window->getSize().y) / 4.f);

        fpsNumbers[i] = util.addText(fpsWordList[i], 30, 2, 2, fpsButtons[i]->getPosition().x, fpsButtons[i]->getPosition().y - fpsButtons[i]->getGlobalBounds().height / 8, window);
    }

    //Siden posisjonene er så varierende setter jeg dem utenfor for-løkken.
    settingsButtons[0]->setPosition(window->getSize().x / 7, window->getSize().y / 2 - window->getSize().y / 6);
    settingsButtons[1]->setPosition(window->getSize().x / 3, window->getSize().y / 2 - window->getSize().y / 6);
    settingsButtons[2]->setPosition(window->getSize().x / 7, window->getSize().y / 2 + window->getSize().y / 6);
    settingsButtons[3]->setPosition(window->getSize().x / 3, window->getSize().y / 2 + window->getSize().y / 6);
    settingsButtons[4]->setPosition(window->getSize().x * 0.95f, window->getSize().y - window->getSize().y / 10);
    settingsButtons[4]->scale(window->getSize().x / 5120.f, window->getSize().y / 2880.f);
    settingsFlagButtons[0]->setPosition((5 * window->getSize().x) / 6, window->getSize().y / 4.f);
    settingsFlagButtons[1]->setPosition((4 * window->getSize().x) / 6, window->getSize().y / 4.f);
    settingsFlagButtons[2]->setPosition((5 * window->getSize().x) / 6, (1.75f * window->getSize().y) / 4.f);
    settingsFlagButtons[3]->setPosition((4 * window->getSize().x) / 6, (1.75f * window->getSize().y) / 4.f);


    //Lager tekstene som skal komme når man mouser over de 4 store knappene. Tekstene er lagret i wordListarrayet.
    for (unsigned int i = 0; i < sizeof(mouseOverText) / sizeof(*mouseOverText); ++i) {
        mouseOverText[i] = util.addText(wordList[i], 30, 2, 2, settingsButtons[i]->getPosition().x, (settingsButtons[i]->getPosition().y - settingsButtons[i]->getGlobalBounds().height / 1.5f), window);
    }
    //Text, textsize, origin x, origin y, position x, position y, window
    this->title = util.addText("Settings", 100, 2, 2, window->getSize().x / 2.f, window->getSize().y / 40.f, window);
    this->fpsText = util.addText("FPS Cap", 50, 2, 2, (4.5f * window->getSize().x) / 6, (2.5f * window->getSize().y) / 4.f, window);

    util.makeMuteButton(window);
}

void StateSettings::update(sf::RenderWindow *window) {
    util.checkMuteMouseOver(window);

    //Sjekker mouseover på flagg og gjør dem mindre transparent om de er mouseovera
    for (unsigned int i = 0; i < sizeof(settingsFlagTextures) / sizeof(*settingsFlagTextures); ++i) {
        if (util.checkMouseover(settingsFlagButtons[i], window)) {
            settingsFlagButtons[i]->setColor(sf::Color(255, 255, 255, 255));
        } else {
            settingsFlagButtons[i]->setColor(sf::Color(255, 255, 255, 125));
        }
        if(i == selectedLanguage) {
            settingsFlagButtons[i]->setColor(sf::Color(255, 255, 255, 255));
        }
    }
    //Sjekker mouseover og klikk på knapper og setter fargen utifra det.
    for (unsigned int i = 0; i < sizeof(settingsTextures) / sizeof(*settingsTextures); ++i) {
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
    //sjekker mouseover og klikk på fpsknapper og setter fargen utifra. Setter alltid valgte fps til buttonClicked.
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
        if (i == selectedfps)
            fpsButtons[i]->setTexture(*this->fpsTextures.buttonClicked);
    }

}

void StateSettings::render(sf::RenderWindow *window) {
    window->draw(*this->background);
    for (unsigned int i = 0; i < sizeof(settingsFlagTextures) / sizeof(*settingsFlagTextures); ++i) {
        window->draw(*this->settingsFlagButtons[i]);
    }
    for (unsigned int i = 0; i < sizeof(settingsTextures) / sizeof(*settingsTextures); ++i) {
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
}

void StateSettings::destroy(sf::RenderWindow *window) {
    //Destroyer i motsatt rekkefølge av draws
    for (int i = (sizeof(settingsFlagButtons) / sizeof(*settingsFlagButtons)) - 1; i >= 0; --i) {
        delete this->settingsFlagButtons[i];
    }
    for (int i = (sizeof(settingsTextures) / sizeof(*settingsTextures)) - 1; i >= 0; --i) {
        delete this->settingsButtons[i];
    }
    for (int i = (sizeof(mouseOverText) / sizeof(*mouseOverText)) - 1; i >= 0; --i) {
        delete this->mouseOverText[i];
    }
    delete this->background;
    delete this->title;
    delete this->fpsText;
}

void StateSettings::handleEvent(sf::RenderWindow *window, sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
//Back on escapekey

        if (event.key.code == machine.keybindMap.find("back")->second.second) {
            machine.setState(new StateMainMenu);
            return;
        }
    }
    if (event.type == sf::Event::MouseButtonReleased) {
        util.checkMuteMouseClick(window, event);

        for (unsigned int i = 0; i < (sizeof(settingsTextures) / sizeof(*settingsTextures)); ++i){
            if (util.checkMouseclick(settingsButtons[i], event)) {
                switch (i) {
                    //Musikknappen trykket
                    case 0:
                        //HER MÅ VI SKRU AV MUSIKK
                        return;
                        //controlsknappen trykket
                    case 1:
                        machine.setState(new StateKeybindings());
                        return;
                        //reset highscore trykket
                    case 2:
                        //HER MÅ VI RESETTE HIGHSCORES
                        return;
                        //reset keybinds trykket
                    case 3:
                        //HER MÅ VI RESETTE BINDS
                        return;
                        //backknappen trykket
                    case 4:
                        machine.setState(new StateMainMenu());
                        return;
                }
            }
        }
        for (unsigned int i = 0; i < 3; ++i){
            if (util.checkMouseclick(fpsButtons[i], event)){
                selectedfps = i;
                switch (i){
                    case 0:
                        util.setFramerate(30);
                        break;
                    case 1:
                        util.setFramerate(60);
                        break;
                    case 2:
                        util.setFramerate(120);
                        break;
                }
            }
        }
        for (unsigned int i = 0; i < (sizeof(settingsFlagButtons) / sizeof(*settingsFlagButtons)); ++i){
            if (util.checkMouseclick(settingsFlagButtons[i], event)){
                selectedLanguage = i;
                switch (i){
                    case 0:
                        //SET LANGUAGE TO ENGLISH
                        break;
                    case 1:
                        //SET LANGUAGE TO NORWEGIAN
                        break;
                    case 2:
                        //SET LANGUAGE TO SERBIAN
                        break;
                    case 3:
                        //SET LANGUAGE TO RUSSIAN
                        break;
                }
            }
        }
    }
}

void StateSettings::reinitialize(sf::RenderWindow *window) {

}