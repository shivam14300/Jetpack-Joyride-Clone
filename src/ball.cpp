#include "ball.h"
#include "main.h"
#include<math.h>

Ball::Ball(float x, float y, color_t color, color_t color1) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    speed = 0.00;
    speedy = 0.00;
    jumping = 0;
    balloons = 30;
    this->sheild = 0;
    this->magnet = 0;
    this->sheild_time = 0.0;
    this->magnet_time = 0.0;
    this->tunnel_flag = 0;
    this->tunnel_timer = 180.0;
    jumping_time = 0.0;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    GLfloat vertex_buffer_data[3250];
    for(int i=0;i<360;i++)
    {
        vertex_buffer_data[9*i]  =  0.0f;
        vertex_buffer_data[9*i+1] = 0.0f;
        vertex_buffer_data[9*i+2] = 0.0f;
        vertex_buffer_data[9*i+3] = 1.0f*cos((M_PI*(float)i)/(float)180);
        vertex_buffer_data[9*i+4] = 1.0f*sin((M_PI*(float)i)/(float)180);
        vertex_buffer_data[9*i+5] = 0.0f;
        vertex_buffer_data[9*i+6] = 1.0f*cos((M_PI*(float)(i+1))/(float)180);
        vertex_buffer_data[9*i+7] = 1.0f*sin((M_PI*(float)(i+1))/(float)180);
        vertex_buffer_data[9*i+8] = 0.0f;
    }
    x = 0;
    GLfloat vertex_buffer_data1[3250];
    for(int i=0,x=0;i<360;i++)
    {
        if(i%20 < 10)
        {
            vertex_buffer_data1[x++] = 0.0f;
            vertex_buffer_data1[x++] = 0.0f;
            vertex_buffer_data1[x++] = 0.0f;
            vertex_buffer_data1[x++] = ((float)i/(360))*cos((M_PI*(float)i)/(float)180);
            vertex_buffer_data1[x++] = ((float)i/(360))*sin((M_PI*(float)i)/(float)180);
            vertex_buffer_data1[x++] = 0.0f;
            vertex_buffer_data1[x++] = ((float)i/(360))*cos((M_PI*(float)(i+1))/(float)180);
            vertex_buffer_data1[x++] = ((float)i/(360))*sin((M_PI*(float)(i+1))/(float)180);
            vertex_buffer_data1[x++] = 0.0f;
        }
    }
    this->object = create3DObject(GL_TRIANGLES, 360*3, vertex_buffer_data, color, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 180*3, vertex_buffer_data1, color1, GL_FILL);
}

void Ball::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object1);
}

void Ball::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Ball::tick() {
    if(this->tunnel_flag == 1)
    {
        // this->tunnel_timer -= 1.0;
        this->position.x = this->tunnel_position_x + 9.0*cos((this->tunnel_timer*M_PI)/180.0);
        this->position.y = this->tunnel_position_y + 9.0*sin((this->tunnel_timer*M_PI)/180.0);
        if(this->tunnel_timer < 0.0f || this->tunnel_timer > 180.0f)
        {
            this->tunnel_flag = 0;
            this->tunnel_timer = 180.0;
        }
    }
    else
    {
        if(this->position.y <= -3.95f)
        this->rotation += 100.0*(speed);
        this->position.x -= speed;
        if(this->position.y > 7.5f)this->position.y = 7.5f;
        if(this->position.y < -4.5f)this->position.y = -4.5f;
    }
    
    
}
