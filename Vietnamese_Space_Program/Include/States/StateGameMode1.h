#ifndef VIETNAMESE_SPACE_PROGRAM_STATEGAMEMODE1_H
#define VIETNAMESE_SPACE_PROGRAM_STATEGAMEMODE1_H

#include "../Core/state.h"
#include "../Core/util.h"
#include "../Core/machine.h"
#include "../Entities/player.h"
#include "../Entities/enemy.h"
#include "../Entities/asteroid.h"
#include "../Entities/boss1.h"
#include "../Core/playerLives.h"
#include "../Core/entityManager.h"
#include "../Core/score.h"
#include "../Entities/healthPack.h"
#include "../Core/soundLoader.h"
#include "../Entities/asteroid.h"

class StateGameMode1 : public States
{
public:
    void initialize(sf::RenderWindow *window);
    void update(sf::RenderWindow *window);
    void render(sf::RenderWindow *window);
    void destroy(sf::RenderWindow *window);
    sf::Clock clockAsteroid;    // starter clocken for asteroid
    sf::Clock clockBoss;        // starter clocken for boss
    sf::Clock clockEnemy;       // starter clocken for enemy
    sf::Clock clockHealthPack;  // starter clocken for healthpack

protected:
    SoundLoader sl;
    Boss* boss;
    Lives* lives;
    Score* score;
    sf::Font* font;
    sf::Text* pausedText;
    Utilities* util;
    EntityManager* manager;
    sf::Texture* bgTexture;
    sf::Sprite* background;
    Player* player;
    EnemyObject* enemyObject;
    HealthPack* healthPack;
    sf::Texture* pausedTexture;
    sf::Sprite* pausedBackground;
};

#endif //VIETNAMESE_SPACE_PROGRAM_STATEGAMEMODE1_H
