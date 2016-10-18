#include "../../Header Files/States/settingsState.h"
#include "../../Header Files/States/menu.h"

#include <iostream>
/**
 * Init settingsState.
 * @param window
 */
void settingsState::Initialize(sf::RenderWindow *window) {

    this->selected = 0;

    this->font = new sf::Font();
    this->font->loadFromFile("Graphics/font1.otf");

    this->title = new sf::Text("SETTINGS", *this->font, 86U);
    this->title->setOrigin(this->title->getGlobalBounds().width / 2, this->title->getGlobalBounds().height / 2);
    this->title->setPosition(window->getSize().x / 2, this->title->getGlobalBounds().height);

    this->screenRes = new sf::Text("ScreenRes", *this->font, 64U);
    this->screenRes->setOrigin(this->screenRes->getGlobalBounds().width / 2, this->screenRes->getGlobalBounds().height / 2);
    this->screenRes->setPosition(window->getSize().x / 2, this->screenRes->getGlobalBounds().height*4);

    this->res1 = new sf::Text("1920x1080", *this->font, 64U);
    this->res1->setOrigin(this->res1->getGlobalBounds().width / 2, this->res1->getGlobalBounds().height / 2);
    this->res1->setPosition(window->getSize().x / 4, this->res1->getGlobalBounds().height*6);

    this->res2 = new sf::Text("1280x720", *this->font, 64U);
    this->res2->setOrigin(this->res2->getGlobalBounds().width / 2, this->res2->getGlobalBounds().height / 2);
    this->res2->setPosition(window->getSize().x / 2, this->res2->getGlobalBounds().height*6);

    this->res3 = new sf::Text("640x360", *this->font, 64U);
    this->res3->setOrigin(this->res3->getGlobalBounds().width / 2, this->res3->getGlobalBounds().height / 2);
    this->res3->setPosition(window->getSize().x / 2 +  window->getSize().x / 4, this->res3->getGlobalBounds().height*6);

    this->volume = new sf::Text("Volume", *this->font, 64U);
    this->volume->setOrigin(this->volume->getGlobalBounds().width / 2, this->volume->getGlobalBounds().height / 2);
    this->volume->setPosition(window->getSize().x / 2, this->volume->getGlobalBounds().height*8);

    this->apply = new sf::Text("Apply", *this->font, 64U);
    this->apply->setOrigin(this->apply->getGlobalBounds().width / 2, this->apply->getGlobalBounds().height / 2);
    this->apply->setPosition(window->getSize().x / 2, window->getSize().y - this->apply->getGlobalBounds().height*5);

    this->back = new sf::Text("Back", *this->font, 64U);
    this->back->setOrigin(this->back->getGlobalBounds().width / 2, this->back->getGlobalBounds().height / 2);
    this->back->setPosition(window->getSize().x / 2, window->getSize().y - this->back->getGlobalBounds().height*3);

}
/**
 * Update on keyevent, navigation through settings
 * @param window
 */
void settingsState::Update(sf::RenderWindow *window) {

    //Vertical selection
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !this->upKey){
        this->selected -= 1;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !this->downKey){
        this->selected += 1;
    }

    if(this->selected > 3){
        this->selected = 0;
    }

    if(this->selected < 0){
        this->selected = 3;
    }
    
    //Horizontal selection resolution
    
    if(this->selected == 0){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !this->leftKey){
            this->selectedRes -= 1;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && !this->rightKey){
            this->selectedRes += 1;
        }

        if(this->selectedRes > 2){
            this->selectedRes = 0;
        }

        if(this->selectedRes < 0){
            this->selectedRes = 2;
        }
    }
    
    //Selection on returnkey

    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && this->enterKey){
        switch(this->selected){
            case 0: //Screenres
                break;
            case 1: //Volume
                break;
            case 2: //Apply
                window->setSize(resChoice);
                this->Initialize(window);
                break;
            case 3: //Back
                coreState.SetState(new main_menu);
                break;
        }
    }

    this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
    this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
    this->leftKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
    this->rightKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
    this->enterKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return);
}

void settingsState::Render(sf::RenderWindow *window) {

    this->screenRes->setFillColor(sf::Color::White);
    this->res1->setFillColor(sf::Color::White);
    this->res2->setFillColor(sf::Color::White);
    this->res3->setFillColor(sf::Color::White);
    this->volume->setFillColor(sf::Color::White);
    this->apply->setFillColor(sf::Color::White);
    this->back->setFillColor(sf::Color::White);

    this->screenRes->setStyle(0);
    this->volume->setStyle(0);
    this->apply->setStyle(0);
    this->back->setStyle(0);

    switch(this->selected){
        case 0: //ScrRes selected, left right to choose res.
            this->res1->setStyle(0);
            this->res2->setStyle(0);
            this->res3->setStyle(0);

            this->screenRes->setStyle(1<<3);

            switch (this->selectedRes){
                case 0:
                    resChoice.x = 1920;
                    resChoice.y = 1080;
                    this->res1->setStyle(1<<3);
                    break;
                case 1:
                    resChoice.x = 1280;
                    resChoice.y = 720;
                    this->res2->setStyle(1<<3);
                    break;
                case 2:
                    resChoice.x = 640;
                    resChoice.y = 360;
                    this->res3->setStyle(1<<3);
                    break;
            }

            break;
        case 1:
            this->volume->setStyle(1<<3);
            break;
        case 2:
            this->apply->setStyle(1<<3);
            break;
        case 3:
            this->back->setStyle(1<<3);
            break;
    }

    window->draw(*this->title);
    window->draw(*this->screenRes);
    window->draw(*this->res1);
    window->draw(*this->res2);
    window->draw(*this->res3);
    window->draw(*this->volume);
    window->draw(*this->apply);
    window->draw(*this->back);
}

void settingsState::Destroy(sf::RenderWindow *window) {
    delete this->font;
    delete this->title;
    delete this->screenRes;
    delete this->res1;
    delete this->res2;
    delete this->res3;
    delete this->volume;
    delete this->apply;
    delete this->back;
}

