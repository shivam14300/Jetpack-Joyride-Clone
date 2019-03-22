#include "main.h"

#ifndef JET_H
#define JET_H


class Jet {
public:
    Jet() {}
    Jet(float x, float y, color_t color, color_t color1);
    glm::vec3 position;
    float rotation;
    float timer;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick(float x, float y);
private:
    VAO *object;
    VAO *object1;
};

#endif // JET_H
