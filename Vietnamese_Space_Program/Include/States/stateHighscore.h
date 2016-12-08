#ifndef VIETNAMESE_SPACE_PROGRAM_HIGHSCORESTATE_H
#define VIETNAMESE_SPACE_PROGRAM_HIGHSCORESTATE_H

#include "../Core/state.h"
#include "../Core/machine.h"
#include <vector>

class StateHighscore : public States{

public:
    void initialize(sf::RenderWindow *window);

    void update(sf::RenderWindow *window);

    void render(sf::RenderWindow *window);

    void destroy(sf::RenderWindow *window);

    void handleEvent(sf::RenderWindow *window, sf::Event event);

    void reinitialize(sf::RenderWindow *window);
private:
    sf::Font* font;
    sf::Text* title;
    sf::Text* playerText;
    sf::Text* scoreText;
    sf::Text* backText;
    sf::Texture* bgTexture;
    sf::Texture* tbTexture;
    sf::Sprite* background;
    sf::Sprite* table;
    sf::Text* place;

    std::vector<sf::Text*> placeVector;
    std::string numbers [10]{"1.","2.","3.","4.","5.","6.","7.","8.","9.","10."};

    int selected;


};

#endif //VIETNAMESE_SPACE_PROGRAM_HIGHSCORESTATE_H
