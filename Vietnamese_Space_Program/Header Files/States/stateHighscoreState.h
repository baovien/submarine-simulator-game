#ifndef VIETNAMESE_SPACE_PROGRAM_HIGHSCORESTATE_H
#define VIETNAMESE_SPACE_PROGRAM_HIGHSCORESTATE_H

#include "../Core/state.h"
#include "../../Header Files/Core/machine.h"

class stateHighscoreState : public States{


public:
    void initialize(sf::RenderWindow *window);

    void update(sf::RenderWindow *window);

    void render(sf::RenderWindow *window);

    void destroy(sf::RenderWindow *window);

private:
    sf::Font* font;
    sf::Text* title;
    sf::Text* back;

    int selected;

};

#endif //VIETNAMESE_SPACE_PROGRAM_HIGHSCORESTATE_H
