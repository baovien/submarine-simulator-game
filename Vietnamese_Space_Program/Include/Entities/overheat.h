#ifndef VIETNAMESE_SPACE_PROGRAM_OVERHEAT_H
#define VIETNAMESE_SPACE_PROGRAM_OVERHEAT_H
#include "../Core/entityManager.h"

class Overheat : public Entity
{
public:
    Overheat(sf::RenderWindow *window);
    void updateEntity(int overheat);

protected:
    float overheat=0;
};


#endif //VIETNAMESE_SPACE_PROGRAM_OVERHEAT_H
