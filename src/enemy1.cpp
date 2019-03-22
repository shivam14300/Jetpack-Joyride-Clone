#include "enemy1.h"
#include "main.h"
#include<math.h>

Enemy1::Enemy1(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    GLfloat vertex_buffer_data[2*3250 + 20];
    for(int i=0;i<360;i++)
    {
        vertex_buffer_data[9*i] = 0.0f;
        vertex_buffer_data[9*i+1] = 0.0f;
        vertex_buffer_data[9*i+2] = 0.0f;
        vertex_buffer_data[9*i+3] = 0.3f*cos((M_PI*(float)i)/(float)180);
        vertex_buffer_data[9*i+4] = 0.3f*sin((M_PI*(float)i)/(float)180);
        vertex_buffer_data[9*i+5] = 0.0f;
        vertex_buffer_data[9*i+6] = 0.3f*cos((M_PI*(float)(i+1))/(float)180);
        vertex_buffer_data[9*i+7] = 0.3f*sin((M_PI*(float)(i+1))/(float)180);
        vertex_buffer_data[9*i+8] = 0.0f;
    }
    for(int i=360;i<720;i++)
    {
        vertex_buffer_data[9*i] = 1.0f+0.0f;
        vertex_buffer_data[9*i+1] = 1.0f+0.0f;
        vertex_buffer_data[9*i+2] = 0.0f;
        vertex_buffer_data[9*i+3] = 1.0f+0.3f*cos((M_PI*(float)i)/(float)180);
        vertex_buffer_data[9*i+4] = 1.0f+0.3f*sin((M_PI*(float)i)/(float)180);
        vertex_buffer_data[9*i+5] = 0.0f;
        vertex_buffer_data[9*i+6] = 1.0f+0.3f*cos((M_PI*(float)(i+1))/(float)180);
        vertex_buffer_data[9*i+7] = 1.0f+0.3f*sin((M_PI*(float)(i+1))/(float)180);
        vertex_buffer_data[9*i+8] = 0.0f;
    }
    vertex_buffer_data[6480] = 0.9f;vertex_buffer_data[6481] = 1.1f;vertex_buffer_data[6482] = 0.0f;
    vertex_buffer_data[6483] = 0.1f;vertex_buffer_data[6484] = -0.1f;vertex_buffer_data[6485] = 0.0f;
    vertex_buffer_data[6486] = -0.1f;vertex_buffer_data[6487] = 0.1f;vertex_buffer_data[6488] = 0.0f;
    vertex_buffer_data[6489] = 0.9f;vertex_buffer_data[6490] = 1.1f;vertex_buffer_data[6491] = 0.0f;
    vertex_buffer_data[6492] = 0.1f;vertex_buffer_data[6493] = -0.1f;vertex_buffer_data[6494] = 0.0f;
    vertex_buffer_data[6495] = 1.1f;vertex_buffer_data[6496] = 0.9f;vertex_buffer_data[6497] = 0.0f;

    this->object = create3DObject(GL_TRIANGLES, 722*3, vertex_buffer_data, color, GL_FILL);
}

void Enemy1::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}
