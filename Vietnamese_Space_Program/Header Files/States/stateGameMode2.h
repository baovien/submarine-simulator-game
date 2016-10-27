#pragma once

#include "../Core/state.h"
#include "../Core/util.h"
#include "../../Header Files/Core/machine.h"
#include "../Entities/player.h"
#include "../Entities/playerLives.h"

#ifndef VIETNAMESE_SPACE_PROGRAM_STATEGAMEMODE2_H
#define VIETNAMESE_SPACE_PROGRAM_STATEGAMEMODE2_H

class stateGameMode2 : public States{

public:
    void initialize(sf::RenderWindow *window);
    void update(sf::RenderWindow *window);
    void render(sf::RenderWindow *window);
    void destroy(sf::RenderWindow *window);

protected:
    sf::Font* font;
    sf::Text* pausedText;
    Utilities* util;
    Lives* lives;
};

#endif //VIETNAMESE_SPACE_PROGRAM_STATEGAMEMODE2_H
