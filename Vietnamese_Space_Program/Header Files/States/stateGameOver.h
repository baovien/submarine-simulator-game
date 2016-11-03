#include "../Core/state.h"
#include "../Core/util.h"
#include "../../Header Files/Core/machine.h"
#include "../Entities/player.h"
#include "../Entities/enemy.h"
#include "../Core/playerLives.h"
#include "../Core/entityManager.h"
#include "../Core/score.h"

#ifndef VIETNAMESE_SPACE_PROGRAM_STATEGAMEOVER_H
#define VIETNAMESE_SPACE_PROGRAM_STATEGAMEOVER_H

class stateGameOver : public States
{
public:
    void initialize(sf::RenderWindow *window);
    void update(sf::RenderWindow *window);
    void render(sf::RenderWindow *window);
    void destroy(sf::RenderWindow *window);

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
};

#endif //VIETNAMESE_SPACE_PROGRAM_STATEGAMEOVER_H
