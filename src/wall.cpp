#include "wall.h"
#include "main.h"
#include<math.h>
Wall::Wall(float x, float y, color_t color,int r) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->timer = 0.0f;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    GLfloat vertex_buffer_data[4000];
    for(int i=0,x=0;i<200;i++)
    {
        vertex_buffer_data[x++] = (float)i;vertex_buffer_data[x++] = 100.0f;vertex_buffer_data[x++] = 0.0f;
        vertex_buffer_data[x++] = (float)i;vertex_buffer_data[x++] = -100.0f;vertex_buffer_data[x++] = 0.0f;
        vertex_buffer_data[x++] = (float)(i-1);vertex_buffer_data[x++] = 100.0f;vertex_buffer_data[x++] = 0.0f;
        
        vertex_buffer_data[x++] =  (float)(i-1.0);vertex_buffer_data[x++] = -100.0f;vertex_buffer_data[x++] = 0.0f;
        vertex_buffer_data[x++] = (float)i;vertex_buffer_data[x++] = -100.0f;vertex_buffer_data[x++] = 0.0f;
        vertex_buffer_data[x++] = (float)(i-1.0);vertex_buffer_data[x++] = 100.0f;vertex_buffer_data[x++] = 0.0f;
    }
    GLfloat vertex_color_data[4000];
    if(r == 0){
        for(int i=0,x=0;i<400;i++)
        {
            vertex_color_data[x++] = (255.0-(1.275*((float)i)))/256.0;vertex_color_data[x++] = (255.0-(0.415*((float)i)))/256.0;vertex_color_data[x++] = (255.0-(0.1875*((float)i)))/256.0;
            vertex_color_data[x++] = (255.0-(1.275*((float)i)))/256.0;vertex_color_data[x++] = (255.0-(0.415*((float)i)))/256.0;vertex_color_data[x++] = (255.0-(0.1875*((float)i)))/256.0;
            vertex_color_data[x++] = (255.0-(1.275*((float)i)))/256.0;vertex_color_data[x++] = (255.0-(0.415*((float)i)))/256.0;vertex_color_data[x++] = (255.0-(0.1875*((float)i)))/256.0;
        }
    }
    else{
        for(int i=0,x=0;i<400;i++)
        {
            vertex_color_data[x++] = (0.0+(1.275*((float)i)))/256.0;vertex_color_data[x++] = (89.0+(0.415*((float)i)))/256.0;vertex_color_data[x++] = (180.0+(0.1875*((float)i)))/256.0;
            vertex_color_data[x++] = (0.0+(1.275*((float)i)))/256.0;vertex_color_data[x++] = (89.0+(0.415*((float)i)))/256.0;vertex_color_data[x++] = (180.0+(0.1875*((float)i)))/256.0;
            vertex_color_data[x++] = (0.0+(1.275*((float)i)))/256.0;vertex_color_data[x++] = (89.0+(0.415*((float)i)))/256.0;vertex_color_data[x++] = (180.0+(0.1875*((float)i)))/256.0;
        }
    }
    this->object = create3DObject(GL_TRIANGLES, 400*3, vertex_buffer_data, vertex_color_data, GL_FILL);
}

void Wall::draw(glm::mat4 VP) {
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

void Wall::set_position(float x, float y) 
{
    this->position = glm::vec3(x, y, 0);
}

void Wall::tick() 
{

}

