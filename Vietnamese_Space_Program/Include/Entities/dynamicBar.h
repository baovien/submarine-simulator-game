#ifndef VIETNAMESE_SPACE_PROGRAM_DYNAMICBAR_H
#define VIETNAMESE_SPACE_PROGRAM_DYNAMICBAR_H
#include "../Core/entityManager.h"
class Bar : public Entity
{
public:
    Bar(sf::RenderWindow *window);
    void updateEntity(sf::RenderWindow *window, float overHeatValue);

protected:
    float overheatcheck;
    sf::Font* font;
    sf::Text* overheatWarning;

};
#endif //VIETNAMESE_SPACE_PROGRAM_DYNAMICBAR_H
