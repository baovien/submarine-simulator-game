#include <iostream>
#include "../../Include/States/stateHighscore.h"
#include "../../Include/States/stateGameMode1.h"
#include "../../Include/States/stateMainMenu.h"


void StateHighscore::initialize(sf::RenderWindow *window) {

    sf::View newView(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
    window->setView(newView);

    this->bgTexture = new sf::Texture();
    this->bgTexture->loadFromFile("Graphics/Sprites/bakgrunn.png");
    this->background = new sf::Sprite();
    this->background->setTexture(*this->bgTexture);
    this->background->scale(window->getSize().x/background->getGlobalBounds().width,window->getSize().y/background->getGlobalBounds().height);

    this->TableTexture = new sf::Texture();
    this->TableTexture->loadFromFile("Graphics/Sprites/gautesTable.png");

    //Legger til knappen for back
     {
         PictureTexture[0].buttonMouseOver = new sf::Texture();
         PictureTexture[0].buttonMouseOver->loadFromFile("Graphics/Sprites/PlayConfig_buttons/Btn3.png");

         PictureTexture[0].buttonNormal = new sf::Texture();
         PictureTexture[0].buttonNormal->loadFromFile("Graphics/Sprites/PlayConfig_buttons/Btn4.png");

         PictureTexture[0].buttonClicked = new sf::Texture();
         PictureTexture[0].buttonClicked->loadFromFile("Graphics/Sprites/PlayConfig_buttons/Btn5.png");

         PictureButtons[0] = new sf::Sprite();
         PictureButtons[0]->setTexture(*this->PictureTexture[0].buttonNormal);
         PictureButtons[0]->setOrigin(PictureButtons[0]->getGlobalBounds().width / 2, PictureButtons[0]->getGlobalBounds().height / 2);
         PictureButtons[0]->scale(window->getSize().x / 5120.f, window->getSize().y / 2880.f);
         PictureButtons[0]->setPosition(window->getSize().x * 0.95f, window->getSize().y - window->getSize().y / 10);
    }

    //Plassering og konfigurasjon av Arcade-tabell
    this->titleArcade = util.addText("ARCADE MODE", 40, 2, 2, window->getSize().x / 2.0f, window->getSize().y / 6.0f, window);
    TableArcade = new sf::Sprite();
    TableArcade->setTexture(*this->TableTexture);
    TableArcade->setOrigin(TableArcade->getGlobalBounds().width/2, TableArcade->getGlobalBounds().height/2);
    TableArcade->setScale(window->getSize().x /1408.0f, window->getSize().y / 792.0f);
    TableArcade->setPosition(window->getSize().x/2, window->getSize().y / 2.5f);

    //Plassering og konfigurasjon av Classic-tabell
    this->titleClassic = util.addText("CLASSIC MODE", 40, 2, 2, window->getSize().x / 2.0f, window->getSize().y / 1.67f, window);
    TableClassic = new sf::Sprite();
    TableClassic->setTexture(*this->TableTexture);
    TableClassic->setOrigin(TableClassic->getGlobalBounds().width/2, TableClassic->getGlobalBounds().height/2);
    TableClassic->setScale(window->getSize().x /1408.0f, window->getSize().y / 792.0f);
    TableClassic->setPosition(window->getSize().x/2, window->getSize().y / 1.2f);

    //Legge tekst i tabellen

    Texturetext[0].Number = util.addText("#", 30,2,2,window->getSize().x/3.97f,window->getSize().y/3.7f,window);
    Texturetext[0].Player = util.addText("PLAYER", 30,2,2,window->getSize().x/3.1f,window->getSize().y/3.7f,window);
    Texturetext[0].Score =  util.addText("SCORE", 30,2,2,window->getSize().x/1.62f,window->getSize().y/3.7f,window);

    Texturetext[1].Number = util.addText("1", 30,2,2,window->getSize().x/3.97f,window->getSize().y/3.02f,window);
    Texturetext[2].Number = util.addText("2", 30,2,2,window->getSize().x/3.97f,window->getSize().y/(3.02f - 0.44f),window);
    Texturetext[3].Number = util.addText("3", 30,2,2,window->getSize().x/3.97f,window->getSize().y/(3.02f - 0.78f),window);

    this->selected = 0;

    this->title = util.addText("HIGHSCORE", 75, 2, 2, window->getSize().x / 2.0f, window->getSize().y / 24.0f, window);
//Legger til backbuttton og mutebutton

    back = new sf::Sprite();
    backTexture = new sf::Texture();

    util.makeMuteButton(window);


    //Forsøk på filskriving
    std::ofstream myfile;
    myfile.open ("example.txt");
    myfile << "Writing this to a file.\n";
    myfile.close();


}
void StateHighscore::update(sf::RenderWindow *window) {
    util.checkMuteMouseOver(window);

    for (unsigned int i = 0; i < sizeof(PictureTexture) / sizeof(*PictureTexture); ++i) {
        if (util.checkMouseover(PictureButtons[i], window)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                PictureButtons[i]->setTexture(*this->PictureTexture[i].buttonClicked);
            } else {
                PictureButtons[i]->setTexture(*this->PictureTexture[i].buttonMouseOver);
            }
        } else {
            PictureButtons[i]->setTexture(*this->PictureTexture[i].buttonNormal);
        }
    }

}

void StateHighscore::render(sf::RenderWindow *window) {

    window->draw(*this->background);
    window->draw(*this->title);
    window->draw(*this->TableArcade);
    window->draw(*this->TableClassic);
    window->draw(*this->titleArcade);
    window->draw(*this->titleClassic);
    window->draw(*this->Texturetext[0].Score);
    for(int i = 0; i < sizeof(Texturetext)/ sizeof(*Texturetext);i++)
    {
        window->draw(*this->Texturetext[i].Number);
    }
    window->draw(*this->PictureButtons[0]);
    window->draw(*this->Texturetext[0].Player);
    window->draw(*util.getMuteButton());
}

void StateHighscore::destroy(sf::RenderWindow *window) {

    delete this->title;
    delete this->TableArcade;
    delete this->TableClassic;
    delete this->background;
    delete this->titleArcade;
    delete this->titleClassic;
    delete this->Texturetext[0].Score;
    delete this->Texturetext[0].Player;
    delete this->PictureButtons[0];

    for(int i = 0; i < sizeof(Texturetext) / sizeof(*Texturetext);i++)
    {
        delete this->Texturetext[i].Number;
    }

}

void StateHighscore::handleEvent(sf::RenderWindow *window, sf::Event event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        //Back on escapekey
        if (event.key.code == machine.keybindMap.find("back")->second.second)
        {
            machine.setState(new StateMainMenu);
            return;
        }
    }

    if (event.type == sf::Event::MouseButtonReleased)
    {
        util.checkMuteMouseClick(window, event);
        if (util.checkMouseclick(PictureButtons[0], event))
        {
            switch (0)
            {
                //playknappen trykket
                case 0:
                    machine.setState(new StateMainMenu);
                    return;
                default:
                    return;
                    //Returnknappen trykket

            }
        }
    }
    if()
}

void StateHighscore::reinitialize(sf::RenderWindow *window) {

}

