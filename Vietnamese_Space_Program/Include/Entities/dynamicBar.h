#ifndef VIETNAMESE_SPACE_PROGRAM_DYNAMICBAR_H
#define VIETNAMESE_SPACE_PROGRAM_DYNAMICBAR_H
#include "../Core/entityManager.h"
#include "player.h"
class Bar : public Entity {
public:
    Bar(sf::RenderWindow *window, int overHeatValue);
    ~Bar();
    void updateEntity(sf::RenderWindow *window);
protected:


};
#endif //VIETNAMESE_SPACE_PROGRAM_DYNAMICBAR_H
