#include "../../Include/States/statePlayConfig.h"
#include "../../Include/States/stateGameMode1.h"
#include "../../Include/States/stateMainMenu.h"
#include "../../Include/States/stateGameMode2.h"


void StatePlayConfig::initialize(sf::RenderWindow *window) {
    sf::View newView(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
    window->setView(newView);

    this->bgTexture = new sf::Texture();
    this->bgTexture->loadFromFile("Graphics/Sprites/bakgrunn.png");
    this->background = new sf::Sprite();
    this->background->setTexture(*this->bgTexture);
    this->background->scale(window->getSize().x / background->getGlobalBounds().width, window->getSize().y / background->getGlobalBounds().height);

    for (unsigned int i = 0; i < sizeof(menuTextures) / sizeof(*menuTextures); ++i) {
        menuTextures[i].buttonMouseOver = new sf::Texture();
        menuTextures[i].buttonMouseOver->loadFromFile("Graphics/Sprites/PlayConfig_buttons/Btn" + std::to_string(i * 3) + ".png");

        menuTextures[i].buttonNormal = new sf::Texture();
        menuTextures[i].buttonNormal->loadFromFile("Graphics/Sprites/PlayConfig_buttons/Btn" + std::to_string(i * 3 + 1) + ".png");

        menuTextures[i].buttonClicked = new sf::Texture();
        menuTextures[i].buttonClicked->loadFromFile("Graphics/Sprites/PlayConfig_buttons/Btn" + std::to_string(i * 3 + 2) + ".png");

        menuButtons[i] = new sf::Sprite();
        menuButtons[i]->setTexture(*this->menuTextures[i].buttonNormal);
        menuButtons[i]->setOrigin(menuButtons[i]->getGlobalBounds().width / 2, menuButtons[i]->getGlobalBounds().height / 2);
    }

    for (unsigned int i = 0; i < sizeof(PictureTexture) / sizeof(*PictureTexture); ++i) {
        PictureTexture[i].buttonNormal = new sf::Texture();
        PictureTexture[i].buttonNormal->loadFromFile("Graphics/Sprites/Picture_buttons/PngBtn" + std::to_string(i * 2) + ".png");

        PictureTexture[i].buttonMouseOver = new sf::Texture();

        PictureTexture[i].buttonMouseOver->loadFromFile("Graphics/Sprites/Picture_buttons/PngBtn" + std::to_string(i * 2 + 1) + ".png");
        PictureButtons[i] = new sf::Sprite();
        PictureButtons[i]->setTexture(*this->PictureTexture[i].buttonNormal);
        PictureButtons[i]->setOrigin(PictureButtons[i]->getGlobalBounds().width / 2, PictureButtons[i]->getGlobalBounds().height / 2);
    }

    //THEME
    this->theme = util.addText("SELECT THEME", 35, 2, 2, window->getSize().x / 6.0f, window->getSize().y / 24.0f, window, machine.settingPointer->selectedLanguage);
    //SpaceTheme

    PictureButtons[0]->scale(window->getSize().x / 3456.0f, window->getSize().y / 1944.f);
    PictureButtons[0]->setPosition(window->getSize().x / 6.0f, window->getSize().y / 4.5f);
    this->SpaceTheme = util.addText("SPACE", 30, 2, 2, window->getSize().x / 6.0f, window->getSize().y / 4.5f + window->getSize().y/9.5f, window, machine.settingPointer->selectedLanguage);

    //WaterTheme
    PictureButtons[1]->scale(window->getSize().x / 3456.0f, window->getSize().y / 1944.0f);
    PictureButtons[1]->setPosition(window->getSize().x / 6.0f, window->getSize().y / 2.1f);
    this->WaterTheme = util.addText("WATER", 30, 2, 2, window->getSize().x / 6.0f, window->getSize().y / 2.1f + window->getSize().y/9.5f, window, machine.settingPointer->selectedLanguage);

    //GAMEMODE
    this->gamemode = util.addText("SELECT GAMEMODE", 35, 2, 2, window->getSize().x / 2.0f, window->getSize().y / 24.0f, window, machine.settingPointer->selectedLanguage);
    //Arcade
    PictureButtons[5]->scale(window->getSize().x / 3456.0f, window->getSize().y / 1944.0f);
    PictureButtons[5]->setPosition(window->getSize().x / 2.0f, window->getSize().y / 4.5f);
    this->Arcade = util.addText("ARCADE", 30, 2, 2, window->getSize().x / 2.0f, window->getSize().y / 4.5f + window->getSize().y/9.5f, window, machine.settingPointer->selectedLanguage);

    //Classic
    PictureButtons[6]->scale(window->getSize().x / 3456.0f, window->getSize().y / 1944.0f);
    PictureButtons[6]->setPosition(window->getSize().x / 2.0f, window->getSize().y / 2.1f);
    this->Classic = util.addText("CLASSIC", 30, 2, 2, window->getSize().x / 2.0f, window->getSize().y / 2.1f + window->getSize().y/9.5f, window, machine.settingPointer->selectedLanguage);

    //FIGHTER
    this->fighter = util.addText("SELECT FIGHTER", 35, 2, 2, window->getSize().x - window->getSize().x / 6, window->getSize().y / 24.0f, window, machine.settingPointer->selectedLanguage);

    //Fighter 1
    PictureButtons[4]->scale(window->getSize().x / 1536.0f, window->getSize().y / 864.0f);
    PictureButtons[4]->rotate(90);
    PictureButtons[4]->setPosition(window->getSize().x - window->getSize().x / 6, window->getSize().y / 4.5f);
    this->fighter_1 = util.addText("ALVAREZ", 30, 2, 2, window->getSize().x - window->getSize().x / 6, window->getSize().y / 4.5f + window->getSize().y/9.5f, window, machine.settingPointer->selectedLanguage);

    //Fighter 2
    PictureButtons[3]->scale(window->getSize().x / 1536.0f, window->getSize().y / 864.0f);
    PictureButtons[3]->rotate(90);
    PictureButtons[3]->setPosition(window->getSize().x - window->getSize().x / 6, window->getSize().y / 2.1f);
    this->fighter_2 = util.addText("MCGREGOR", 30, 2, 2, window->getSize().x - window->getSize().x / 6, window->getSize().y / 2.1f + window->getSize().y/9.5f, window, machine.settingPointer->selectedLanguage);

    //Fighter 3
    PictureButtons[2]->scale(window->getSize().x / 1536.0f, window->getSize().y / 864.0f);
    PictureButtons[2]->rotate(90);
    PictureButtons[2]->setPosition(window->getSize().x - window->getSize().x / 6, window->getSize().y / 1.4f);
    this->fighter_3 = util.addText("DIAZ", 30, 2, 2, window->getSize().x - window->getSize().x / 6, window->getSize().y / 1.4f + window->getSize().y/9.5f, window, machine.settingPointer->selectedLanguage);

    //Setter posisjonen og skalinga til PLAY-button
    menuButtons[0]->scale(window->getSize().x / 1536.0f, window->getSize().y / 864.0f);
    menuButtons[0]->setPosition(window->getSize().x / 2, window->getSize().y / 1.2f);

    //Setter posisjonen og skalinga til BACK-button
    menuButtons[1]->scale(window->getSize().x / 5120.f, window->getSize().y / 2880.f);
    menuButtons[1]->setPosition(window->getSize().x * 0.95f, window->getSize().y - window->getSize().y / 10);

    util.makeMuteButton(window, machine.mutedPointer);
}

void StatePlayConfig::update(sf::RenderWindow *window) {
    util.checkMuteMouseOver(window);

    for (unsigned int i = 0; i < sizeof(menuTextures) / sizeof(*menuTextures); ++i) {
        if (util.checkMouseover(menuButtons[i], window)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                menuButtons[i]->setTexture(*this->menuTextures[i].buttonClicked);
            } else {
                menuButtons[i]->setTexture(*this->menuTextures[i].buttonMouseOver);
            }
        } else {
            menuButtons[i]->setTexture(*this->menuTextures[i].buttonNormal);
        }
    }

    for (unsigned int i = 0; i < sizeof(PictureTexture) / sizeof(*PictureTexture); ++i) {
        if (util.checkMouseover(PictureButtons[i], window))
            PictureButtons[i]->setTexture(*this->PictureTexture[i].buttonMouseOver);
        else {
            PictureButtons[i]->setTexture(*this->PictureTexture[i].buttonNormal);
        }
        if (i == selected_Fighter)
            PictureButtons[i]->setTexture(*this->PictureTexture[i].buttonMouseOver);
        if (i == selected_Theme)
            PictureButtons[i]->setTexture(*this->PictureTexture[i].buttonMouseOver);
        if (i == selected_Gamemode)
            PictureButtons[i]->setTexture(*this->PictureTexture[i].buttonMouseOver);

    }

}

void StatePlayConfig::render(sf::RenderWindow *window) {
    window->draw(*this->background);

    for (unsigned int i = 0; i < sizeof(menuTextures) / sizeof(*menuTextures); ++i) {
        window->draw(*this->menuButtons[i]);
    }
    for (unsigned int i = 0; i < sizeof(PictureTexture) / sizeof(*PictureTexture); ++i) {
        window->draw(*this->PictureButtons[i]);
    }

    window->draw(*this->theme);
    window->draw(*this->fighter);
    window->draw(*this->gamemode);

    window->draw(*this->WaterTheme);
    window->draw(*this->SpaceTheme);

    window->draw(*this->fighter_1);
    window->draw(*this->fighter_2);
    window->draw(*this->fighter_3);

    window->draw(*this->Arcade);
    window->draw(*this->Classic);

    window->draw(*util.getMuteButton());
}

void StatePlayConfig::destroy(sf::RenderWindow *window) {
    delete this->theme;
    delete this->font;
    delete this->fighter;
    delete this->gamemode;

    delete this->WaterTheme;
    delete this->SpaceTheme;

    delete this->fighter_1;
    delete this->fighter_2;
    delete this->fighter_3;

    delete this->Arcade;
    delete this->Classic;

    for (int i = sizeof(PictureTexture) / sizeof(*PictureTexture) - 1; i > 0; --i) {
        delete this->PictureButtons[i];
    }
    for (int i = sizeof(menuTextures) / sizeof(*menuTextures) - 1; i > 0; --i) {
        delete this->menuButtons[i];
    }

    delete this->background;
}

void StatePlayConfig::handleEvent(sf::RenderWindow *window, sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        //Back on escapekey
        if (event.key.code == machine.keybindMap.find("back")->second.second) {
            machine.setState(new StateMainMenu);
            return;
        }
    }

    if (event.type == sf::Event::MouseButtonReleased) {
        util.checkMuteMouseClick(window, event, machine.mutedPointer);
        for (unsigned int i = 0; i < sizeof(menuTextures) / sizeof(*menuTextures); ++i)
            if (util.checkMouseclick(menuButtons[i], event)) {
                switch (i) {
                    //playknappen trykket
                    case 0:
                        if (selected_Gamemode == 5) {
                            machine.setState(new StateGameMode1);
                            return;
                        } else {
                            machine.setState(new StateGameMode2);
                            return;
                        }

                    case 1:
                        machine.setState(new StateMainMenu);
                        return;
                        //Returnknappen trykket
                }
            }
        for (unsigned int i = 0; i < sizeof(PictureTexture) / sizeof(*PictureTexture); ++i)
            if (util.checkMouseclick(PictureButtons[i], event)) {
                switch (i) {
                    case 0:
                        selected_Theme = i;
                        break;
                    case 1:
                        selected_Theme = i;
                        break;
                    case 2:
                        selected_Fighter = i;
                        break;
                    case 3:
                        selected_Fighter = i;
                        break;
                    case 4:
                        selected_Fighter = i;
                        break;
                    case 5:
                        selected_Gamemode = i;
                        break;
                    case 6:
                        selected_Gamemode = i;
                        break;
                }
            }
    }
}

void StatePlayConfig::reinitialize(sf::RenderWindow *window) {
    initialize(window);
}
