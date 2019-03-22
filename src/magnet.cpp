#include "magnet.h"
#include "main.h"
#include<math.h>
Magnet::Magnet(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->timer = 0.0f;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    GLfloat vertex_buffer_data[100];
    // for(int i=0,x=0;i<360;i++)
    // {
    //     if(i%40 < 20){
    //         vertex_buffer_data[x++] = 0.5f*cos((M_PI*(float)i)/(float)180);
    //         vertex_buffer_data[x++] = 0.5f*sin((M_PI*(float)i)/(float)180);
    //         vertex_buffer_data[x++] = 0.0f;
    //         vertex_buffer_data[x++] = 1.0f*cos((M_PI*(float)i)/(float)180);
    //         vertex_buffer_data[x++] = 1.0*sin((M_PI*(float)i)/(float)180);
    //         vertex_buffer_data[x++] = 0.0f;
    //         vertex_buffer_data[x++] = 1.0f*cos((M_PI*(float)(i+1))/(float)180);
    //         vertex_buffer_data[x++] = 1.0f*sin((M_PI*(float)(i+1))/(float)180);
    //         vertex_buffer_data[x++] = 0.0f;
    //         vertex_buffer_data[x++] = 0.5f*cos((M_PI*(float)i)/(float)180);
    //         vertex_buffer_data[x++] = 0.5f*sin((M_PI*(float)i)/(float)180);
    //         vertex_buffer_data[x++] = 0.0f;
    //         vertex_buffer_data[x++] = 0.5f*cos((M_PI*(float)(i+1))/(float)180);
    //         vertex_buffer_data[x++] = 0.5f*sin((M_PI*(float)(i+1))/(float)180);
    //         vertex_buffer_data[x++] = 0.0f;
    //         vertex_buffer_data[x++] = 1.0f*cos((M_PI*(float)(i+1))/(float)180);
    //         vertex_buffer_data[x++] = 1.0f*sin((M_PI*(float)(i+1))/(float)180);
    //         vertex_buffer_data[x++] = 0.0f;
    //     }
    // }
    vertex_buffer_data[0] = 0.5f;vertex_buffer_data[1] = 0.5f;vertex_buffer_data[2] = 0.0f;
    vertex_buffer_data[3] = 0.5f;vertex_buffer_data[4] = -0.25f;vertex_buffer_data[5] = 0.0f;
    vertex_buffer_data[6] = 0.25f;vertex_buffer_data[7] = -0.25f;vertex_buffer_data[8] = 0.0f;
    
    vertex_buffer_data[9] = 0.5f;vertex_buffer_data[10] = 0.5f;vertex_buffer_data[11] = 0.0f;
    vertex_buffer_data[12] = 0.25f;vertex_buffer_data[13] = -0.25f;vertex_buffer_data[14] = 0.0f;
    vertex_buffer_data[15] = 0.25f;vertex_buffer_data[16] = 0.25f;vertex_buffer_data[17] = 0.0f;
    
    vertex_buffer_data[18] = 0.5f;vertex_buffer_data[19] = 0.5f;vertex_buffer_data[20] = 0.0f;
    vertex_buffer_data[21] = 0.25f;vertex_buffer_data[22] = 0.25f;vertex_buffer_data[23] = 0.0f;
    vertex_buffer_data[24] = -0.5f;vertex_buffer_data[25] = 0.5f;vertex_buffer_data[26] = 0.0f;
    
    vertex_buffer_data[27] = -0.5f;vertex_buffer_data[28] = 0.5f;vertex_buffer_data[29] = 0.0f;
    vertex_buffer_data[30] = -0.25f;vertex_buffer_data[31] = 0.25f;vertex_buffer_data[32] = 0.0f;
    vertex_buffer_data[33] = 0.25f;vertex_buffer_data[34] = 0.25f;vertex_buffer_data[35] = 0.0f;
    
    vertex_buffer_data[36] = -0.5f;vertex_buffer_data[37] = 0.5f;vertex_buffer_data[38] = 0.0f;
    vertex_buffer_data[39] = -0.25f;vertex_buffer_data[40] = -0.25f;vertex_buffer_data[41] = 0.0f;
    vertex_buffer_data[42] = -0.5f;vertex_buffer_data[43] = -0.25f;vertex_buffer_data[44] = 0.0f;
    
    vertex_buffer_data[45] = -0.5f;vertex_buffer_data[46] = 0.5f;vertex_buffer_data[47] = 0.0f;
    vertex_buffer_data[48] = -0.25f;vertex_buffer_data[49] = 0.25f;vertex_buffer_data[50] = 0.0f;
    vertex_buffer_data[51] = -0.25f;vertex_buffer_data[52] = -0.25f;vertex_buffer_data[53] = 0.0f;
    
    this->object = create3DObject(GL_TRIANGLES, 6*3, vertex_buffer_data, color, GL_FILL);
}

void Magnet::draw(glm::mat4 VP) {
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

void Magnet::set_position(float x, float y) 
{
    this->position = glm::vec3(x, y, 0);
}

void Magnet::tick() 
{

}

