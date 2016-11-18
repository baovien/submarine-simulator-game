#include "../../Include/States/statePlayConfig.h"
#include "../../Include/States/stateGameMode1.h"
#include "../../Include/States/stateMainMenu.h"
#include "../../Include/States/stateGameMode2.h"
#include "../../Include/States/stateSettings.h"


void StatePlayConfig::initialize(sf::RenderWindow *window) {

    machine.mouseClick = {-1, -1}; //Resetter mouseClick slik at museklikk fra tidligere states ikke triggerer if-sjekker.

    sf::View newView(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
    window->setView(newView);

    this->bgTexture = new sf::Texture();
    this->bgTexture->loadFromFile("Graphics/Sprites/bakgrunn.png");

    this->background = new sf::Sprite();
    this->background->setTexture(*this->bgTexture);
    this->background->scale(window->getSize().x / background->getGlobalBounds().width, window->getSize().y / background->getGlobalBounds().height);

    this->selected = 0;

    this->selected_Theme = 0;
    this->selected_Fighter = 0;
    this->selected_Gamemode = 0;

    this->font = new sf::Font();
    this->font->loadFromFile("Graphics/font1.otf");


    for (unsigned int i = 0; i < sizeof(menuTextures) / sizeof(*menuTextures); ++i)
    {
        menuTextures[i].buttonNormal = new sf::Texture();
        menuTextures[i].buttonNormal->loadFromFile("Graphics/Sprites/PlayConfig_buttons/Btn" + std::to_string(i * 3) + ".png");

        menuTextures[i].buttonMouseOver = new sf::Texture();
        menuTextures[i].buttonMouseOver->loadFromFile("Graphics/Sprites/PlayConfig_buttons/Btn" + std::to_string(i * 3 + 1) + ".png");

        menuTextures[i].buttonClicked = new sf::Texture();
        menuTextures[i].buttonClicked->loadFromFile("Graphics/Sprites/PlayConfig_buttons/Btn" + std::to_string(i * 3 + 2) + ".png");


        menuButtons[i] = new sf::Sprite();
        menuButtons[i]->setTexture(*this->menuTextures[i].buttonNormal);
        menuButtons[i]->setOrigin(menuButtons[i]->getGlobalBounds().width / 2, menuButtons[i]->getGlobalBounds().height / 2);
    }

    for(unsigned int i = 0; i < sizeof(PictureTexture) / sizeof(*PictureTexture); ++i)
    {
        PictureTexture[i].buttonNormal = new sf::Texture();
        PictureTexture[i].buttonNormal->loadFromFile("Graphics/Sprites/Picture_buttons/PngBtn" + std::to_string(i * 2)+ ".png");

        PictureTexture[i].buttonMouseOver = new sf::Texture();
        PictureTexture[i].buttonMouseOver->loadFromFile("Graphics/Sprites/Picture_buttons/PngBtn" + std::to_string(i * 2 + 1)+ ".png");

        PictureButtons[i] = new sf::Sprite();
        PictureButtons[i]->setTexture(*this->PictureTexture[i].buttonNormal);
        PictureButtons[i]->setOrigin(PictureButtons[i]->getGlobalBounds().width / 2, PictureButtons[i]->getGlobalBounds().height / 2);
    }

    //THEME
    this->theme = util.addText("SELECT THEME", 25, 2, 2,window->getSize().x / 2.0f, window->getSize().y / 72.0f);
    //SpaceTheme
    PictureButtons[0]->scale(window->getSize().x / background->getGlobalBounds().width /3.5f, window->getSize().x / background->getGlobalBounds().width / 3.5f);
    PictureButtons[0]->setPosition(window->getSize().x - window->getSize().x / 3, window->getSize().y / 8);
    this->SpaceTheme = util.addText("SPACE", 25, 2, 2,window->getSize().x - window->getSize().x / 3, window->getSize().y / 8 + 55);

    //WaterTheme
    PictureButtons[1]->scale(window->getSize().x / background->getGlobalBounds().width /3.5f, window->getSize().x / background->getGlobalBounds().width / 3.5f);
    PictureButtons[1]->setPosition(window->getSize().x / 3, window->getSize().y / 8);
    this->WaterTheme = util.addText("WATER", 25, 2, 2,window->getSize().x / 3, window->getSize().y / 8 + 55);

    //FIGHTER
    this->fighter = util.addText("SELECT FIGHTER", 25, 2, 2,window->getSize().x / 2.0f, window->getSize().y / 4.1143f);

    //Fighter 1
    PictureButtons[2]->scale(window->getSize().x / background->getGlobalBounds().width /2.0f, window->getSize().x / background->getGlobalBounds().width /2.0f);
    PictureButtons[2]->rotate(90);
    PictureButtons[2]->setPosition(window->getSize().x - window->getSize().x / 1.5f ,window->getSize().y - window->getSize().y /1.5f);
    this->fighter_1 = util.addText("ALVAREZ", 25, 2, 2, window->getSize().x - window->getSize().x / 1.5f , window->getSize().y - window->getSize().y /1.65f);

    //Fighter 2
    PictureButtons[3]->scale(window->getSize().x / background->getGlobalBounds().width /2.0f, window->getSize().x / background->getGlobalBounds().width /2.0f);
    PictureButtons[3]->rotate(90);
    PictureButtons[3]->setPosition(window->getSize().x/2,window->getSize().y - window->getSize().y /1.5f);
    this->fighter_2 = util.addText("MCGREGOR", 25, 2, 2, window->getSize().x / 2, window->getSize().y - window->getSize().y /1.65f);

    //Fighter3
    PictureButtons[4]->scale(window->getSize().x / background->getGlobalBounds().width /2.0f, window->getSize().x / background->getGlobalBounds().width /2.0f);
    PictureButtons[4]->rotate(90);
    PictureButtons[4]->setPosition(window->getSize().x - window->getSize().x /3.00706f,window->getSize().y - window->getSize().y /1.5f);
    this->fighter_3 = util.addText("DIAZ", 25, 2, 2, window->getSize().x / 1.5f, window->getSize().y - window->getSize().y /1.65f);

    std::cout << window->getSize().y / 72.0f << std::endl;
    std::cout << window->getSize().y / 4.1143f << std::endl;
    std::cout <<window->getSize().y - window->getSize().y /1.8947f << std::endl;

    //GAMEMODE
    this->gamemode = util.addText("SELECT GAMEMODE", 25, 2, 2,window->getSize().x / 2.0f, window->getSize().y - window->getSize().y /1.8947f);
    //Arcade
    PictureButtons[5]->scale(window->getSize().x / background->getGlobalBounds().width /3.5f, window->getSize().x / background->getGlobalBounds().width / 3.5f);
    PictureButtons[5]->setPosition(window->getSize().x - window->getSize().x / 3,window->getSize().y/1.71428f);
    this->Arcade = util.addText("ARCADE", 25, 2, 2, window->getSize().x - window->getSize().x / 3, window->getSize().y/1.71428f + 55);

    //Classic
    PictureButtons[6]->scale(window->getSize().x / background->getGlobalBounds().width /3.5f, window->getSize().x / background->getGlobalBounds().width / 3.5f);
    PictureButtons[6]->setPosition(window->getSize().x / 3,window->getSize().y/1.71428f);
    this->Classic = util.addText("CLASSIC", 25, 2, 2, window->getSize().x / 3,window->getSize().y/1.71428f + 55);

    //Setter posisjonen og skalinga til PLAY-button
    menuButtons[0]->scale(window->getSize().x / background->getGlobalBounds().width / 1.2f, window->getSize().x / background->getGlobalBounds().width / 1.2f);
    menuButtons[0]->setPosition(window->getSize().x / 2, window->getSize().y / 1.2f);

    //Setter posisjonen og skalinga til LYD-button
    menuButtons[1]->scale(window->getSize().x / background->getGlobalBounds().width / 4.5f, window->getSize().x / background->getGlobalBounds().width / 4.5f);
    menuButtons[1]->setPosition(window->getSize().x - window->getSize().x * 0.95f, window->getSize().y - window->getSize().y / 10);

    //Setter posisjonen og skalinga til BACK-button
    menuButtons[2]->scale(window->getSize().x / background->getGlobalBounds().width / 4.5f, window->getSize().x / background->getGlobalBounds().width / 4.5f);
    menuButtons[2]->setPosition(window->getSize().x * 0.95f, window->getSize().y - window->getSize().y / 10);
}

void StatePlayConfig::update(sf::RenderWindow *window)
{
    for (unsigned int i = 0; i < sizeof(menuTextures) / sizeof(*menuTextures); ++i)
    {
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

    for (unsigned int i = 0; i < sizeof(PictureTexture) / sizeof(*PictureTexture); ++i)
    {
        if (util.checkMouseover(PictureButtons[i], window)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                PictureButtons[i]->setTexture(*this->PictureTexture[i].buttonMouseOver);
            } else {
                PictureButtons[i]->setTexture(*this->PictureTexture[i].buttonMouseOver);
            }
        } else {
            PictureButtons[i]->setTexture(*this->PictureTexture[i].buttonNormal);
        }
    }

}

void StatePlayConfig::render(sf::RenderWindow *window)
{
    window->draw(*this->background);

    for (unsigned int i = 0; i < sizeof(menuTextures) / sizeof(*menuTextures); ++i) {
        window->draw(*this->menuButtons[i]);
    }
    for (unsigned int i = 0; i < sizeof(PictureTexture) / sizeof(*PictureTexture); ++i) {
        window->draw(*this->PictureButtons[i]);
    }

    this->theme->setFillColor(sf::Color::Red);
    this->fighter->setFillColor(sf::Color::Red);
    this->gamemode->setFillColor(sf::Color::Red);
    this->WaterTheme->setFillColor(sf::Color::Black);
    this->SpaceTheme->setFillColor(sf::Color::Black);
    this->fighter_1->setFillColor(sf::Color::Black);
    this->fighter_2->setFillColor(sf::Color::Black);
    this->fighter_3->setFillColor(sf::Color::Black);
    this->Arcade->setFillColor(sf::Color::Black);
    this->Classic->setFillColor(sf::Color::Black);

    this->theme->setStyle(0);
    this->fighter->setStyle(0);
    this->gamemode->setStyle(0);




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

}

void StatePlayConfig::destroy(sf::RenderWindow *window)
{
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

void StatePlayConfig::handleEvent(sf::RenderWindow *window, sf::Event event)
{
    if (event.type == sf::Event::MouseButtonReleased) {
        for (unsigned int i = 0; i < sizeof(menuTextures) / sizeof(*menuTextures); ++i)
            if (util.checkMouseclick(menuButtons[i], event)) {
                switch (i) {
                    //playknappen trykket
                    case 0:
                        machine.setState(new StateGameMode1);
                        return;
                        //Playknappen trykket
                    case 1:

                        return;
                        //Lydknappen trykket
                    case 2:
                       machine.setState(new StateMainMenu);
                        return;
                        //Returnknappen trykket
                    case 3:
                        //Her må vi mekke tutorial
                        return;
                        //exitknappen trykket
                    case 4:
                        quitGame = true;
                        return;
                        //volumknappen trykket
                    case 5:
                        //Her må vi mekke mute/unmute
                        return;
                }
            }
    }
}

void StatePlayConfig::reinitialize(sf::RenderWindow *window) {

}
