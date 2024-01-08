#ifndef CUBE_H
#define CUBE_H
#include "entity.h"

struct Cube : Entity {
    Cube();
    virtual ~Cube();

    void render();
};

#endif
