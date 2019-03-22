#include "main.h"

#ifndef FLOOR_H
#define FLOOR_H


class Floor {
public:
    Floor() {}
    Floor(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
private:
    VAO *object;
};

#endif // Floor_H
