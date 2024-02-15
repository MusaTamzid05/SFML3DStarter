#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "entity.h"


struct Rectangle : Entity {
    Rectangle();
    virtual ~Rectangle();

    void render();
    void update();

    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;



};

#endif
