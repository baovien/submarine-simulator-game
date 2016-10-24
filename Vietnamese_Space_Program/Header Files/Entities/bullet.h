#include "bullet_entity.h"
#ifndef VIETNAMESE_SPACE_PROGRAM_BULLET_H
#define VIETNAMESE_SPACE_PROGRAM_BULLET_H
class bullet : public bullet_entity
{
public:
    bullet();
    void bulletUpdate(float x, float y);
    float speed = 10;
    float x=0, y=0;

protected:
};
#endif //VIETNAMESE_SPACE_PROGRAM_BULLET_H
