#ifndef VIETNAMESE_SPACE_PROGRAM_MACHINE_H
#define VIETNAMESE_SPACE_PROGRAM_MACHINE_H

#include "state.h"
#include "soundLoader.h"

class Machine {
public:
    Machine();

    ~Machine();

    void setWindow(sf::RenderWindow *window);

    void setState(States *state);

    void reinitialize();

    void update();

    void render();

    void eventHandler(sf::Event event);

    void setGameOverScore(int playerScore);

    int getGameOverScore() const;

private:

    //Brukes i forbindelse med keybinds
    std::map<const std::string, std::pair<std::string, int>> m_keybindMap = {{"up",     std::make_pair("W", sf::Keyboard::W)},
                                                                           {"down",   std::make_pair("S", sf::Keyboard::S)},
                                                                           {"left",   std::make_pair("A", sf::Keyboard::A)},
                                                                           {"right",  std::make_pair("D", sf::Keyboard::D)},
                                                                           {"select", std::make_pair("Return", sf::Keyboard::Return)},
                                                                           {"back",   std::make_pair("Escape", sf::Keyboard::Escape)},
                                                                           {"shoot",  std::make_pair("Space", sf::Keyboard::Space)},
                                                                           {"pause",  std::make_pair("P", sf::Keyboard::P)}};
    struct settingStruct {
        int selectedFps;
        int selectedLanguage;
    };
    settingStruct settingVariables {1,0};

    struct selectedObjects{
        int selectedGamemode;
        int selectedFighter;
        int selectedTheme;
    };

    selectedObjects selectedObjectsVariable {2,0};

    std::vector<std::pair<int, std::string>> arcadeScore =
            {{std::make_pair(0, "Player")},
             {std::make_pair(0, "Player")},
             {std::make_pair(0, "Player")}};

    std::vector<std::pair<int, std::string>> classicScore =
            {{std::make_pair(0, "Player")},
             {std::make_pair(0, "Player")},
             {std::make_pair(0, "Player")}};

    bool muted = false;
    bool mutedMusic = false;
    SoundLoader soundLoader;
    sf::Image backgroundBehindOverlay;


private:
    float deltaTime;
public:
    sf::Image* backgroundBehindOverlayPointer = &backgroundBehindOverlay;
    float* deltaTimePointer = &deltaTime;
    SoundLoader* soundLoaderPointer = &soundLoader;
    bool* mutedMusicPointer = &mutedMusic;
    bool* mutedPointer = &muted;
    std::map<const std::string, std::pair<std::string, int>>* keybindMap = &m_keybindMap;
    settingStruct* settingPointer = &settingVariables;
    std::vector<std::pair<int, std::string>>* arcadeScorePointer = &arcadeScore;
    std::vector<std::pair<int, std::string>>* classicScorePointer = &classicScore;
    selectedObjects* selectedObjectsPointer = &selectedObjectsVariable;

private:
    sf::RenderWindow *window;
    States *state;
    int gameOverScore;

};

extern Machine machine;
extern bool quitGame;

#endif //VIETNAMESE_SPACE_PROGRAM_MACHINE_H
