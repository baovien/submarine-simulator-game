#ifndef VIETNAMESE_SPACE_PROGRAM_STATEGAMEMODE1_H
#define VIETNAMESE_SPACE_PROGRAM_STATEGAMEMODE1_H

#include "../Core/state.h"
#include "../Core/utilities.h"
#include "../Core/machine.h"
#include "../Entities/player.h"
#include "../Entities/enemy.h"
#include "../Entities/indestructableObject.h"
#include "../Entities/boss1.h"
#include "../Core/playerLives.h"
#include "../Core/entityManager.h"
#include "../Core/score.h"
#include "../Entities/healthPack.h"
#include "../Core/soundLoader.h"
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
    Lives* lives;
    Score* score;
    ShieldEntity* shieldEntity;
    BossObject* bossObject;
    sf::Font* font;
    sf::Text* pausedText;
    sf::Text* waveText;
    Utilities* util;
    EntityManager* manager;
    sf::Texture* bgTexture;
    sf::Sprite* background;
    Player* player;
    HealthPack* healthPack;
    sf::Texture* pausedTexture;
    sf::Sprite* pausedBackground;
    sfuser::PauseableClock pauseableClockIndestructableObject;
    sfuser::PauseableClock pauseableClockHealthPack;
    sfuser::PauseableClock pauseableClockShieldEntity;

    //Branch: Waves
    int mode = 1;
    int enemyCount = 0;
    int transparencyValue = 0;
    int waveNum = 0;
    bool inWave = false;

    void gameOverScreen();

    void spawnObjects();

    void spawnWave(sf::RenderWindow* window);

    //Spawned entities
    int spawnedHealthPacks, spawnedShieldPacks;
};


#endif //VIETNAMESE_SPACE_PROGRAM_STATEGAMEMODE1_H
