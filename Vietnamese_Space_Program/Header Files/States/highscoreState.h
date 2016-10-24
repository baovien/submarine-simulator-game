#ifndef VIETNAMESE_SPACE_PROGRAM_HIGHSCORESTATE_H
#define VIETNAMESE_SPACE_PROGRAM_HIGHSCORESTATE_H

#include "../Core/state.h"


class highscoreState : public States{


public:
    void Initialize(sf::RenderWindow* window);

    void Update(sf::RenderWindow* window);

    void Render(sf::RenderWindow* window);

    void Destroy(sf::RenderWindow* window);

private:
    sf::Font* font;
    sf::Text* title;
    sf::Text* back;

    int selected;

    bool enterKey;
};

#endif //VIETNAMESE_SPACE_PROGRAM_HIGHSCORESTATE_H
