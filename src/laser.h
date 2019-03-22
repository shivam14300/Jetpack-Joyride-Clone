#include "main.h"

#ifndef LASER_H
#define LASER_H


class Laser {
public:
    Laser() {}
    Laser(float x, float y, color_t color, color_t color1);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP, float timer);
    void tick(float timer);
    int start;
    float x,y;
    float flag;
    float starting_time;
private:
    VAO *object;
    VAO *object1;
};

#endif // Laser_H
