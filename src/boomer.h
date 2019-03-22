#include "main.h"

#ifndef BOOMER_H
#define BOOMER_H


class Boomer {
public:
    Boomer() {}
    Boomer(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    float timer;
    float x;
    float y;
private:
    VAO *object;
};

#endif // BOOMER_H
