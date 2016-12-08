#ifndef VIETNAMESE_SPACE_PROGRAM_STATEGAMEMODE2_H
#define VIETNAMESE_SPACE_PROGRAM_STATEGAMEMODE2_H

#include "../Core/state.h"
#include "../Core/utilities.h"
#include "../Core/machine.h"
#include "../Entities/player.h"
#include "../Core/playerLives.h"
#include "../Core/entityManager.h"
#include "../Core/score.h"
#include "../Entities/bullet.h"
#include "../Entities/enemy2.h"


class StateGameMode2 : public States{

public:
    void initialize(sf::RenderWindow *window);

    void update(sf::RenderWindow *window);

    void render(sf::RenderWindow *window);

    void destroy(sf::RenderWindow *window);

    void handleEvent(sf::RenderWindow *window, sf::Event event);

    void reinitialize(sf::RenderWindow *window);

    sf::Clock clock; // starter clocken
    sf::Clock enemyclock;
protected:
    Lives* lives;
    Score* score;
    sf::Font* font;
    sf::Text* pausedText;
    Utilities* util;
    EntityManager* manager;
    sf::Texture* bgTexture;
    sf::Sprite* background;
    Player* player;
    Enemy2Object* enemy2Object;



    bool spawna = true;
    bool rightCollision = false;
    bool leftCollision = true;
};

#endif //VIETNAMESE_SPACE_PROGRAM_STATEGAMEMODE2_H
