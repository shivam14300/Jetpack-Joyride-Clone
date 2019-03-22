#include "main.h"

#ifndef BALL_H
#define BALL_H


class Ball {
public:
    Ball() {}
    Ball(float x, float y, color_t color,color_t color1);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;
    double speedy;
    int tunnel_flag;
    float tunnel_timer;
    float tunnel_position_x;
    float tunnel_position_y;
    int jumping;
    int falling;
    int sheild;
    float sheild_time;
    int magnet;
    float magnet_time;
    int balloons;
    float jumping_time;
    float falling_time;
private:
    VAO *object;
    VAO *object1;
};

#endif // BALL_H
