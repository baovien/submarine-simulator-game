#ifndef SUBMARINESIMULATORSTATEGAMEMODE1_H
#define SUBMARINESIMULATORSTATEGAMEMODE1_H

#include "../Core/state.h"
#include "../Core/utilities.h"
#include "../Core/machine.h"
#include "../Entities/player.h"
#include "../Entities/enemy.h"
#include "../Entities/indestructableObject.h"
#include "../Entities/boss.h"
#include "../Core/playerLives.h"
#include "../Core/entityManager.h"
#include "../Core/score.h"
#include "../Entities/healthPack.h"
#include "../Core/audioLoader.h"
#include "../Entities/indestructableObject.h"
#include "../Core/pauseableClock.h"
#include "../Entities/shieldEntity.h"

class StateGameMode1 : public States
{
public:

    void initialize(sf::RenderWindow *window);
    void update(sf::RenderWindow *window);
    void render(sf::RenderWindow *window);
    void destroy(sf::RenderWindow *window);
    void handleEvent(sf::RenderWindow *window, sf::Event event);
    void reinitialize(sf::RenderWindow *window);

protected:
    sf::Texture overBar;
    sf::Sprite overBarS;
    Lives* lives = nullptr;
    Score* score = nullptr;
    sf::Font* font = nullptr;
    sf::Text* pausedText = nullptr;
    sf::Text* waveText = nullptr;
    Utilities* util = nullptr;
    EntityManager* manager = nullptr;
    sf::Texture* bgTexture = nullptr;
    sf::Sprite* background = nullptr;
    Player* player = nullptr;
    EnemyObject* enemyObject = nullptr;
    BossObject* bossObject = nullptr;
    sf::Texture* pausedTexture = nullptr;
    sf::Sprite* pausedBackground = nullptr;
    sfuser::PauseableClock clock;
    sf::Vector2u currentWindowSize;

    bool waveDone = false;
    float powerUpTime = 0;
    float junkTime = 0;
    sfuser::PauseableClock waveClock;

    void updateWaveText(sf::RenderWindow* window, bool choice);

    //Branch: Waves
    int bossWave = 0;
    int transparencyValue = 0;
    int waveNum = 0;

    std::vector<EnemyObject*> enemyList;

    std::vector<BossObject*> bossList;

    void spawnObjects(sf::RenderWindow* window);

    void spawnWave(sf::RenderWindow* window);

    void updateEnemyList(sf::RenderWindow* window);

};


#endif //SUBMARINESIMULATORSTATEGAMEMODE1_H
