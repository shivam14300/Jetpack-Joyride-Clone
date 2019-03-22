#include "main.h"

#ifndef EMENY1_H
#define EMENY1_H


class Enemy1 {
public:
    Enemy1() {}
    Enemy1(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
private:
    VAO *object;
};

#endif // ENEMY1_H
