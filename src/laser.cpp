#include "laser.h"
#include "main.h"
#include<math.h>

Laser::Laser(float x, float y, color_t color,color_t color1) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->start = 0;
    this->flag = 1.0;
    this->x = this->position.x;
    this->y = this->position.y;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    GLfloat vertex_buffer_data[50];

    vertex_buffer_data[0] = 5.0f;vertex_buffer_data[1] = 0.05f;vertex_buffer_data[2] = 0.0f;
    vertex_buffer_data[3] = 5.0f;vertex_buffer_data[4] = -0.05f;vertex_buffer_data[5] = 0.0f;
    vertex_buffer_data[6] = -5.0f;vertex_buffer_data[7] = -0.05f;vertex_buffer_data[8] = 0.0f;
    
    vertex_buffer_data[9] = 5.0f;vertex_buffer_data[10] = 0.05f;vertex_buffer_data[11] = 0.0f;
    vertex_buffer_data[12] = -5.0f;vertex_buffer_data[13] = 0.05f;vertex_buffer_data[14] = 0.0f;
    vertex_buffer_data[15] = -5.0f;vertex_buffer_data[16] = -0.05f;vertex_buffer_data[17] = 0.0f;

    GLfloat vertex_buffer_data1[50];

    vertex_buffer_data1[0]  =  5.0f;vertex_buffer_data1[1] = 0.00f;vertex_buffer_data1[2] = 0.0f;
    vertex_buffer_data1[3] =  6.0f;vertex_buffer_data1[4] = 1.00f;vertex_buffer_data1[5] = 0.0f;
    vertex_buffer_data1[6] =  6.0f;vertex_buffer_data1[7] =-1.00f;vertex_buffer_data1[8] = 0.0f;

    vertex_buffer_data1[9]  = -5.0f;vertex_buffer_data1[10] = 0.00f;vertex_buffer_data1[11] = 0.0f;
    vertex_buffer_data1[12] = -6.0f;vertex_buffer_data1[13] = 1.00f;vertex_buffer_data1[14] = 0.0f;
    vertex_buffer_data1[15] = -6.0f;vertex_buffer_data1[16] =-1.00f;vertex_buffer_data1[17] = 0.0f;

    this->object = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_data, color, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_data1, color1, GL_FILL);
}

void Laser::draw(glm::mat4 VP, float timer) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    if(timer > 2.0)
        draw3DObject(this->object);
}
void Laser::tick(float timer) {
    if(timer > 2.0)
        this->rotation += 5.0f;
}

