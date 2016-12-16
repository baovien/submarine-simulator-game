#ifndef VIETNAMESE_SPACE_PROGRAM_STATECREDITS_H
#define VIETNAMESE_SPACE_PROGRAM_STATECREDITS_H

#include "../Core/machine.h"
#include "../Core/state.h"

class StateCredits : public States{
public:
    void initialize(sf::RenderWindow *window);

    void update(sf::RenderWindow *window);

    void render(sf::RenderWindow *window);

    void destroy(sf::RenderWindow *window);

    void handleEvent(sf::RenderWindow *window, sf::Event event);

    void reinitialize(sf::RenderWindow *window);

private:
    bool introOver;
    int transparency;
    sf::Clock clock;
    sf::Texture* bgTexture = nullptr;
    sf::Sprite* background = nullptr;
};
#endif //VIETNAMESE_SPACE_PROGRAM_STATECREDITS_H
