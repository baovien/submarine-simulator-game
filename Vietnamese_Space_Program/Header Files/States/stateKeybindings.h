#ifndef VIETNAMESE_SPACE_PROGRAM_STATEKEYBINDINGS_H
#define VIETNAMESE_SPACE_PROGRAM_STATEKEYBINDINGS_H


#include "../Core/state.h"
#include "../../Header Files/Core/machine.h"

class stateKeybindings : public States{
public:
    void initialize(sf::RenderWindow *window);

    void update(sf::RenderWindow *window);

    void render(sf::RenderWindow *window);

    void destroy(sf::RenderWindow *window);


private:
    sf::RenderWindow* window;

    sf::Font* font;
    sf::Text* movementText;
    sf::Text* menuNavigationText;
    sf::Text* gameplayText;

    sf::Texture* ballTexture;
    sf::Texture* bgTexture;
    sf::Sprite* background;


    sf::Text* upText;
    sf::Text* downText;
    sf::Text* leftText;
    sf::Text* rightText;
    sf::Text* selectText;
    sf::Text* backText;
    sf::Text* shootText;
    sf::Text* pauseText;

    sf::Sprite* upKeySquare;
    sf::Sprite* downKeySquare;
    sf::Sprite* leftKeySquare;
    sf::Sprite* rightKeySquare;
    sf::Sprite* selectKeySquare;
    sf::Sprite* backKeySquare;
    sf::Sprite* shootKeySquare;
    sf::Sprite* pauseKeySquare;

    sf::Sprite* keySquares[8];


    sf::Text* upKeyText;
    sf::Text* downKeyText;
    sf::Text* leftKeyText;
    sf::Text* rightKeyText;
    sf::Text* selectKeyText;
    sf::Text* backKeyText;
    sf::Text* shootKeyText;
    sf::Text* pauseKeyText;

    std::string keyList[sf::Keyboard::KeyCount] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K",
                                                   "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V",
                                                   "W", "X", "Y", "Z", "Num0", "Num1", "Num2", "Num3", "Num4",
                                                   "Num5", "Num6", "Num7", "Num8", "Num9","Escape", "LControl",
                                                   "LShift", "LAlt", "LSystem", "RControl", "RShift", "RAlt",
                                                   "RSystem","Menu", "LBracket", "RBracket", "SemiColon", "Comma",
                                                   "Period", "Quote", "Slash", "BackSlash", "Tilde", "Equal", "Dash",
                                                   "Space", "Return", "BackSpace", "Tab", "PageUp", "PageDown", "End",
                                                   "Home", "Insert", "Delete", "Add", "Subtract", "Multiply", "Divide",
                                                   "Left", "Right", "Up", "Down", "Numpad0", "Numpad1", "Numpad2", "Numpad3",
                                                   "Numpad4", "Numpad5", "Numpad6", "Numpad7", "Numpad8", "Numpad9", "F1",
                                                   "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12",
                                                   "F13", "F14", "F15", "Pause"};

    int selected;
    unsigned int textSize = 32U;

};

#endif //VIETNAMESE_SPACE_PROGRAM_STATEKEYBINDINGS_H
