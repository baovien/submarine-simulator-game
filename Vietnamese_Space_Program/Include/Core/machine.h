#ifndef VIETNAMESE_SPACE_PROGRAM_MACHINE_H
#define VIETNAMESE_SPACE_PROGRAM_MACHINE_H

#include "state.h"

class Machine {
public:
    Machine();

    ~Machine();

    void setWindow(sf::RenderWindow *window);

    void setState(States *state);

    void update();

    void render();

    //For å beholde tastetrykk/-slipp til pollEventet i App
    bool keyPressed[sf::Keyboard::KeyCount];
    bool keyReleased[sf::Keyboard::KeyCount];

    void setGameOverScore(int playerScore);
    int getGameOverScore() const;

    //For å beholde museklikk til pollEventet i App
    sf::Vector2i mouseClick;

    //Brukes i forbindelse med keybinds
    std::map<const std::string, std::string> keybindMap = {{"up",     "W"},
                                                           {"down",   "S"},
                                                           {"left",   "A"},
                                                           {"right",  "D"},
                                                           {"select", "Return"},
                                                           {"back",   "Escape"},
                                                           {"shoot",  "Space"},
                                                           {"pause",  "P"}};
    std::string keyList[sf::Keyboard::KeyCount] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K",
                                                   "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V",
                                                   "W", "X", "Y", "Z", "Num0", "Num1", "Num2", "Num3", "Num4",
                                                   "Num5", "Num6", "Num7", "Num8", "Num9", "Escape", "LControl",
                                                   "LShift", "LAlt", "LSystem", "RControl", "RShift", "RAlt",
                                                   "RSystem", "Menu", "LBracket", "RBracket", "SemiColon", "Comma",
                                                   "Period", "Quote", "Slash", "BackSlash", "Tilde", "Equal", "Dash",
                                                   "Space", "Return", "BackSpace", "Tab", "PageUp", "PageDown", "End",
                                                   "Home", "Insert", "Delete", "Add", "Subtract", "Multiply", "Divide",
                                                   "Left", "Right", "Up", "Down", "Numpad0", "Numpad1", "Numpad2", "Numpad3",
                                                   "Numpad4", "Numpad5", "Numpad6", "Numpad7", "Numpad8", "Numpad9", "F1",
                                                   "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12",
                                                   "F13", "F14", "F15", "Pause"};
    std::string wordList [8]{"up","down","left","right","select","back","shoot","pause"};
    bool waitingForInput = false;
    bool keyPressedInBinds = true;
    int keyToBind;


private:
    sf::RenderWindow* window;
    States* state;
    int gameOverScore;

};

extern Machine machine;
extern bool quitGame;

#endif //VIETNAMESE_SPACE_PROGRAM_MACHINE_H
