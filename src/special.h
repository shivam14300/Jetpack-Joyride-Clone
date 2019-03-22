#include "main.h"

#ifndef SPECIAL_H
#define SPECIAL_H


class Special {
public:
    Special() {}
    Special(float x, float y, color_t color,int flag);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    float timer;
    int flag;
    int occupied;
    float occupied_time;
    int type;
private:
    VAO *object;
    VAO *object1;
    VAO *object2;
};

#endif // SPECIAL_H
