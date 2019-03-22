#include "main.h"

#ifndef BLUEBALLS_H
#define BLUEBALLS_H


class Blueballs {
public:
    Blueballs() {}
    Blueballs(float x, float y, color_t color, float r);
    glm::vec3 position;
    float rotation;
    float timer;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick(float x, float y);
private:
    VAO *object;
};

#endif // BLUEBALLS_H
