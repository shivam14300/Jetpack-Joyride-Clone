#include "balloon.h"
#include "main.h"
#include<math.h>
Balloon::Balloon(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0.0;
    this->timer = 0.0;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    
    GLfloat vertex_buffer_data[2*3250];
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
        vertex_buffer_data[9*i] = 0.0f;
        vertex_buffer_data[9*i+1] = 0.0f;
        vertex_buffer_data[9*i+2] = 0.0f;
        vertex_buffer_data[9*i+3] = 0.1f*cos((M_PI*(float)i)/(float)180);
        vertex_buffer_data[9*i+4] = 0.1f*sin((M_PI*(float)i)/(float)180);
        vertex_buffer_data[9*i+5] = 0.0f;
        vertex_buffer_data[9*i+6] = 0.1f*cos((M_PI*(float)(i+1))/(float)180);
        vertex_buffer_data[9*i+7] = 0.1f*sin((M_PI*(float)(i+1))/(float)180);
        vertex_buffer_data[9*i+8] = 0.0f;
    }
    vertex_buffer_data[3240] = 0.0f;vertex_buffer_data[3241] = 0.3f;vertex_buffer_data[3242] = 0.0f;
    vertex_buffer_data[3243] = 0.1f;vertex_buffer_data[3244] = 0.5f;vertex_buffer_data[3245] = 0.0f;
    vertex_buffer_data[3246] = -0.1f;vertex_buffer_data[3247] = 0.5f;vertex_buffer_data[3248] = 0.0f;

    this->object = create3DObject(GL_TRIANGLES, 361*3, vertex_buffer_data, color, GL_FILL);
}

void Balloon::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Balloon::set_position(float x, float y) 
{
    this->position = glm::vec3(x, y, 0);
}

void Balloon::tick() 
{
    this->timer += 0.06;
    this->position.x += 0.65;
    this->position.y -= 0.5*(this->timer*this->timer);
    this->rotation -= 30.0; 
}
