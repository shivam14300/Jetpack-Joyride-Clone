#include "main.h"

#ifndef TUNNEL_H
#define TUNNEL_H


class Tunnel {
public:
    Tunnel() {}
    Tunnel(float x, float y, color_t color, color_t color1);
    glm::vec3 position;
    float rotation;
    float timer;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
private:
    VAO *object;
    VAO *object1;
};

#endif // TUNNNEL_H
