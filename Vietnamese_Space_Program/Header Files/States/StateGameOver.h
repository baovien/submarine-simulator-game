#ifndef VIETNAMESE_SPACE_PROGRAM_STATEGAMEOVER_H
#define VIETNAMESE_SPACE_PROGRAM_STATEGAMEOVER_H

#include "../Core/state.h"
#include "../../Header Files/Core/machine.h"
#include "../Core/score.h"

class StateGameOver : public States{
public:
    void initialize(sf::RenderWindow *window);

    void update(sf::RenderWindow *window);

    void render(sf::RenderWindow *window);

    void destroy(sf::RenderWindow *window);

private:
    sf::Font* font;
    sf::Text* gameOverText;
    sf::Text* menuText;
    sf::Text* restartText;
    sf::Text* score;

    sf::Texture* bgTexture;
    sf::Sprite* background;

    int selected;

};


#endif //VIETNAMESE_SPACE_PROGRAM_STATEGAMEOVER_H
