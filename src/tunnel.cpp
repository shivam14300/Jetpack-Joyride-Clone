#include "tunnel.h"
#include "main.h"
#include<math.h>
Tunnel::Tunnel(float x, float y, color_t color, color_t color1) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0.0;
    this->timer = 0.0;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    
    GLfloat vertex_buffer_data[3250/2];
    
    for(int i=0,x=0;i<90;i++)
    {
        if(i%2 == 0)
        {
            vertex_buffer_data[x++] = 8.0f*cos((2.0*M_PI*(float)i)/(float)180);
            vertex_buffer_data[x++] = 8.0f*sin((2.0*M_PI*(float)i)/(float)180);
            vertex_buffer_data[x++] = 0.0f;
            vertex_buffer_data[x++] = 10.0f*cos((2.0*M_PI*(float)i)/(float)180);
            vertex_buffer_data[x++] = 10.0*sin((2.0*M_PI*(float)i)/(float)180);
            vertex_buffer_data[x++] = 0.0f;
            vertex_buffer_data[x++] = 10.0f*cos((2.0*M_PI*(float)(i+1))/(float)180);
            vertex_buffer_data[x++] = 10.0f*sin((2.0*M_PI*(float)(i+1))/(float)180);
            vertex_buffer_data[x++] = 0.0f;
        }
        else
        {
            vertex_buffer_data[x++] = 10.0f*cos((2.0*M_PI*(float)i)/(float)180);
            vertex_buffer_data[x++] = 10.0f*sin((2.0*M_PI*(float)i)/(float)180);
            vertex_buffer_data[x++] = 0.0f;
            vertex_buffer_data[x++] = 8.0f*cos((2.0*M_PI*(float)i)/(float)180);
            vertex_buffer_data[x++] = 8.0*sin((2.0*M_PI*(float)i)/(float)180);
            vertex_buffer_data[x++] = 0.0f;
            vertex_buffer_data[x++] = 8.0f*cos((2.0*M_PI*(float)(i+1))/(float)180);
            vertex_buffer_data[x++] = 8.0f*sin((2.0*M_PI*(float)(i+1))/(float)180);
            vertex_buffer_data[x++] = 0.0f;
        }
        
    }
//     vertex_buffer_data[x++] = 8.0f*cos((M_PI*(float)i)/(float)180);
//     vertex_buffer_data[x++] = 8.0f*sin((M_PI*(float)i)/(float)180);
//     vertex_buffer_data[x++] = 0.0f;
//     vertex_buffer_data[x++] = 10.0f*cos((M_PI*(float)i)/(float)180);
//     vertex_buffer_data[x++] = 10.0*sin((M_PI*(float)i)/(float)180);
//     vertex_buffer_data[x++] = 0.0f;
//     vertex_buffer_data[x++] = 10.0f*cos((M_PI*(float)(i+1))/(float)180);
//     vertex_buffer_data[x++] = 10.0f*sin((M_PI*(float)(i+1))/(float)180);
//     vertex_buffer_data[x++] = 0.0f;
// // }
//     vertex_buffer_data[x++] = 8.0f*cos((M_PI*(float)i)/(float)180);
//     vertex_buffer_data[x++] = 8.0f*sin((M_PI*(float)i)/(float)180);
//     vertex_buffer_data[x++] = 0.0f;
//     vertex_buffer_data[x++] = 8.0f*cos((M_PI*(float)(i+1))/(float)180);
//     vertex_buffer_data[x++] = 8.0f*sin((M_PI*(float)(i+1))/(float)180);
//     vertex_buffer_data[x++] = 0.0f;
//     vertex_buffer_data[x++] = 10.0f*cos((M_PI*(float)(i+1))/(float)180);
//     vertex_buffer_data[x++] = 10.0f*sin((M_PI*(float)(i+1))/(float)180);
//     vertex_buffer_data[x++] = 0.0f;
    // vertex_buffer_data[0] = 0.6f;vertex_buffer_data[1] = 0.2f;vertex_buffer_data[2] = 0.0f;
    // vertex_buffer_data[3] = 0.4f;vertex_buffer_data[4] = -0.2f;vertex_buffer_data[5] = 0.0f;
    // vertex_buffer_data[6] = 0.2f;vertex_buffer_data[7] = 0.2f;vertex_buffer_data[8] = 0.0f;
    
    // GLfloat vertex_buffer_data1[3250/2];
    
    // for(int i=0;i<180;i++)
    // {
    //     if(i%2 == 0)
    //     {
    //     vertex_buffer_data1[9*i] = 0.0f;
    //     vertex_buffer_data1[9*i+1] = 0.0f;
    //     vertex_buffer_data1[9*i+2] = 0.0f;
    //     vertex_buffer_data1[9*i+3] = 4.0f*cos((M_PI*(float)i)/(float)180);
    //     vertex_buffer_data1[9*i+4] = 4.0*sin((M_PI*(float)i)/(float)180);
    //     vertex_buffer_data1[9*i+5] = 0.0;
    //     vertex_buffer_data1[9*i+6] = 4.0f*cos((M_PI*(float)(i+1))/(float)180);
    //     vertex_buffer_data1[9*i+7] = 4.0f*sin((M_PI*(float)(i+1))/(float)180);
    //     vertex_buffer_data1[9*i+8] = 0.0f;
    // }
    // vertex_buffer_data1[0] = 1.0f;vertex_buffer_data1[1] = 0.2f;vertex_buffer_data1[2] = 0.0f;
    // vertex_buffer_data1[3] = 0.8f;vertex_buffer_data1[4] = -0.2f;vertex_buffer_data1[5] = 0.0f;
    // vertex_buffer_data1[6] = 0.6f;vertex_buffer_data1[7] = 0.2f;vertex_buffer_data1[8] = 0.0f;
    
    
    this->object = create3DObject(GL_TRIANGLES, 90*3, vertex_buffer_data, color, GL_FILL);
    // this->object1 = create3DObject(GL_TRIANGLES, 180*3, vertex_buffer_data1, color1, GL_FILL);
}

void Tunnel::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    // draw3DObject(this->object1);
}

void Tunnel::set_position(float x, float y) 
{
    this->position = glm::vec3(x, y, 0);
}

void Tunnel::tick() 
{
    // if(this->position.y < 3.0f)
    //     this->position.x -= 0.10;
    // this->position.y -= 0.05;
    // this->timer += 0.01;
    // this->rotation += 20.0f;
}

