#include "../../Include/States/stateSettings.h"
#include "../../Include/States/stateMainMenu.h"
#include "../../Include/States/stateKeybindings.h"



void StateSettings::initialize(sf::RenderWindow *window) {
    sf::View newView( sf::FloatRect( 0, 0, window->getSize().x, window->getSize().y ) );
    window->setView(newView);

    this->bgTexture = new sf::Texture();
    this->bgTexture->loadFromFile("Graphics/Sprites/bakgrunn.png");

    this->background = new sf::Sprite();
    this->background->setTexture(*this->bgTexture);
    this->background->scale(window->getSize().x/background->getGlobalBounds().width, window->getSize().y/background->getGlobalBounds().height);

    this->selected = 0;

    //Lager alle flagknappene og laster inn alle textures til flaggene.
    for (int i = 0; i < sizeof(settingsFlagTextures) / sizeof(*settingsFlagTextures) ; ++i) {
        settingsFlagTextures[i] = new sf::Texture();
        settingsFlagTextures[i]->loadFromFile("Graphics/Sprites/Settings_buttons/flag" + std::to_string(i) + ".png");

        settingsFlagButtons[i] = new sf::Sprite();
        settingsFlagButtons[i]->setTexture(*this->settingsFlagTextures[i]);
        settingsFlagButtons[i]->setOrigin(settingsFlagButtons[i]->getGlobalBounds().width / 2, settingsFlagButtons[i]->getGlobalBounds().height / 2);
        settingsFlagButtons[i]->scale(window->getSize().x/4800.f,  window->getSize().y/2700.f);

    }
    //Lager alle knapper og laster inn alle textures til knappene
    for (int i = 0; i < sizeof(settingsTextures) / sizeof(*settingsTextures) ; ++i){
        settingsTextures[i].buttonMouseOver = new sf::Texture();
        settingsTextures[i].buttonMouseOver->loadFromFile("Graphics/Sprites/Settings_buttons/Btn" + std::to_string(i * 3) + ".png");

        settingsTextures[i].buttonNormal = new sf::Texture();
        settingsTextures[i].buttonNormal->loadFromFile("Graphics/Sprites/Settings_buttons/Btn" + std::to_string(i * 3 + 1) + ".png");

        settingsTextures[i].buttonClicked = new sf::Texture();
        settingsTextures[i].buttonClicked->loadFromFile("Graphics/Sprites/Settings_buttons/Btn" + std::to_string(i * 3 + 2) + ".png");

        settingsButtons[i] = new sf::Sprite();
        settingsButtons[i]->setTexture(*this->settingsTextures[i].buttonNormal);
        settingsButtons[i]->setOrigin(settingsButtons[i]->getGlobalBounds().width / 2, settingsButtons[i]->getGlobalBounds().height / 2);
        settingsButtons[i]->scale(window->getSize().x/1280.f,  window->getSize().y/720.f);
    }

    //Siden posisjonene er så varierende setter jeg dem utenfor for-løkken.
    settingsButtons[0]->setPosition(window->getSize().x / 7, window->getSize().y/2 - window->getSize().y / 6);
    settingsButtons[1]->setPosition(window->getSize().x / 3, window->getSize().y/2 - window->getSize().y / 6);
    settingsButtons[2]->setPosition(window->getSize().x / 7, window->getSize().y/2 + window->getSize().y / 6);
    settingsButtons[3]->setPosition(window->getSize().x / 3, window->getSize().y/2 + window->getSize().y / 6);
    settingsButtons[4]->setPosition(window->getSize().x * 0.95f, window->getSize().y - window->getSize().y / 10);
    settingsButtons[4]->scale(window->getSize().x/5120.f,  window->getSize().y/2880.f);
    settingsFlagButtons[0]->setPosition((5 *window->getSize().x) / 6, window->getSize().y / 4.f);
    settingsFlagButtons[1]->setPosition((4 * window->getSize().x) / 6, window->getSize().y / 4.f);
    settingsFlagButtons[2]->setPosition((5 * window->getSize().x) / 6, (1.75f * window->getSize().y) / 4.f);
    settingsFlagButtons[3]->setPosition((4 * window->getSize().x) / 6, (1.75f * window->getSize().y) / 4.f);

    FPStexture = new sf::Texture();
    FPStexture->loadFromFile("Graphics/Sprites/Window/Window_10.png");


    //Lager tekstene som skal komme når man mouser over de 4 store knappene. Tekstene er lagret i wordListarrayet.
    for (int i = 0; i < sizeof(mouseOverText) / sizeof(*mouseOverText) ; ++i){
    mouseOverText[i] = util.addText(wordList[i], 30, 2, 2, settingsButtons[i]->getPosition().x, (settingsButtons[i]->getPosition().y - settingsButtons[i]->getGlobalBounds().height / 1.5f), window);
    }
    //Text, textsize, origin x, origin y, position x, position y, window
    this->title = util.addText("Settings", 100, 2, 2, window->getSize().x/2.f, window->getSize().y/40.f, window);

    FPSbutton = new sf::Sprite();
    FPSbutton->setTexture(*this->FPStexture);
    FPSbutton->setOrigin(FPSbutton->getGlobalBounds().width / 2, FPSbutton->getGlobalBounds().height / 2);
    FPSbutton->scale(window->getSize().x/4800.f,  window->getSize().y/2700.f);
    FPSbutton->setPosition((4.5f * window->getSize().x) / 6, (3.f * window->getSize().y) / 4.f);

    this->FPStext = util.addText("FPS Cap", 50, 2, 2, FPSbutton->getPosition().x, (FPSbutton->getPosition().y - FPSbutton->getGlobalBounds().height / 1.25f), window);
    this->FPS = util.addText(std::to_string(util.getFramerate()), 50, 2, 2, FPSbutton->getPosition().x, FPSbutton->getPosition().y, window);
}
void StateSettings::update(sf::RenderWindow *window) {
    //Sjekker mouseover på flagg og gjør dem mindre transparent om de er mouseovera
    for (int i = 0; i < sizeof(settingsFlagTextures) / sizeof(*settingsFlagTextures) ; ++i){
    if(util.checkMouseover(settingsFlagButtons[i], window)){
        settingsFlagButtons[i]->setColor(sf::Color(255, 255, 255, 255));
    }
        else
        settingsFlagButtons[i]->setColor(sf::Color(255, 255, 255, 125));
    }
    //Sjekker mouseover og klikk på knapper og setter fargen utifra det.
    for (unsigned int i = 0; i < sizeof(settingsTextures) / sizeof(*settingsTextures); ++i) {
        if (util.checkMouseover(settingsButtons[i], window)) {
            if(i<4)
                mouseOverText[i]->setFillColor(sf::Color(255, 255, 255, 255));
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                settingsButtons[i]->setTexture(*this->settingsTextures[i].buttonClicked);
            } else {
                settingsButtons[i]->setTexture(*this->settingsTextures[i].buttonMouseOver);
            }
        } else {
            if(i<4)
                mouseOverText[i]->setFillColor(sf::Color(255, 255, 255, 0));
            settingsButtons[i]->setTexture(*this->settingsTextures[i].buttonNormal);
        }
    }
}
void StateSettings::render(sf::RenderWindow *window) {
    window->draw(*this->background);
    for (int i = 0; i < sizeof(settingsFlagTextures) / sizeof(*settingsFlagTextures); ++i){
        window->draw(*this->settingsFlagButtons[i]);
    }
    for (unsigned int i = 0; i < sizeof(settingsTextures) / sizeof(*settingsTextures); ++i) {
        window->draw(*this->settingsButtons[i]);
    }
    for (unsigned int i = 0; i < sizeof(mouseOverText) / sizeof(*mouseOverText); ++i) {
        window->draw(*this->mouseOverText[i]);
    }
    window->draw(*this->title);
    window->draw(*this->FPStext);
    window->draw(*this->FPSbutton);
    window->draw(*this->FPS);
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
    delete this->FPStext;
    delete this->FPSbutton;
    delete this->FPS;
}
void StateSettings::handleEvent(sf::RenderWindow *window , sf::Event event){
  if (event.type == sf::Event::KeyPressed) {
//Back on escapekey

      if (event.key.code == machine.keybindMap.find("back")->second.second) {
          machine.setState(new StateMainMenu);
          return;
      }
      if (event.key.code == machine.keybindMap.find("select")->second.second) {
          machine.setState(new StateKeybindings);
          return;
      }
  }
    if (event.type == sf::Event::MouseButtonReleased) {
        for (unsigned int i = 0; i < (sizeof(settingsTextures) / sizeof(*settingsTextures)); ++i)
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
}

void StateSettings::reinitialize(sf::RenderWindow *window) {

}
