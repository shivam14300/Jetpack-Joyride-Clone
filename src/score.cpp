#include "score.h"
#include "main.h"
#include<math.h>
Score::Score(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0.0;
    this->timer = 0.0;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    GLfloat vertex_buffer_data[200];
    this->x = 0;

    //a
    vertex_buffer_data[this->x++] =  0.25f;vertex_buffer_data[this->x++] = 0.00f;vertex_buffer_data[this->x++] = 0.0f;
    vertex_buffer_data[this->x++] =  0.30f;vertex_buffer_data[this->x++] = 0.00f;vertex_buffer_data[this->x++] = 0.0f;
    vertex_buffer_data[this->x++] =  0.30f;vertex_buffer_data[this->x++] = 0.50f;vertex_buffer_data[this->x++] = 0.0f;
    
    vertex_buffer_data[this->x++] =  0.25f;vertex_buffer_data[this->x++] = 0.00f;vertex_buffer_data[this->x++] = 0.0f;
    vertex_buffer_data[this->x++] =  0.25f;vertex_buffer_data[this->x++] = 0.50f;vertex_buffer_data[this->x++] = 0.0f;
    vertex_buffer_data[this->x++] =  0.30f;vertex_buffer_data[this->x++] = 0.50f;vertex_buffer_data[this->x++] = 0.0f;
    //b
    vertex_buffer_data[this->x++] =  0.25f;vertex_buffer_data[this->x++] = 0.50f;vertex_buffer_data[this->x++] = 0.0f;
    vertex_buffer_data[this->x++] =  0.25f;vertex_buffer_data[this->x++] = 0.55f;vertex_buffer_data[this->x++] = 0.0f;
    vertex_buffer_data[this->x++] = -0.25f;vertex_buffer_data[this->x++] = 0.50f;vertex_buffer_data[this->x++] = 0.0f;
    
    vertex_buffer_data[this->x++] = -0.25f;vertex_buffer_data[this->x++] = 0.55f;vertex_buffer_data[this->x++] = 0.0f;
    vertex_buffer_data[this->x++] =  0.25f;vertex_buffer_data[this->x++] = 0.55f;vertex_buffer_data[this->x++] = 0.0f;
    vertex_buffer_data[this->x++] = -0.25f;vertex_buffer_data[this->x++] = 0.50f;vertex_buffer_data[this->x++] = 0.0f;
    //c
    vertex_buffer_data[this->x++] = -0.25f;vertex_buffer_data[this->x++] = 0.00f;vertex_buffer_data[this->x++] = 0.0f;
    vertex_buffer_data[this->x++] = -0.25f;vertex_buffer_data[this->x++] = 0.50f;vertex_buffer_data[this->x++] = 0.0f;
    vertex_buffer_data[this->x++] = -0.30f;vertex_buffer_data[this->x++] = 0.00f;vertex_buffer_data[this->x++] = 0.0f;
    
    vertex_buffer_data[this->x++] = -0.30f;vertex_buffer_data[this->x++] = 0.50f;vertex_buffer_data[this->x++] = 0.0f;
    vertex_buffer_data[this->x++] = -0.25f;vertex_buffer_data[this->x++] = 0.50f;vertex_buffer_data[this->x++] = 0.0f;
    vertex_buffer_data[this->x++] = -0.30f;vertex_buffer_data[this->x++] = 0.00f;vertex_buffer_data[this->x++] = 0.0f;
    //d
    vertex_buffer_data[this->x++] = -0.25f;vertex_buffer_data[this->x++] =  0.00f;vertex_buffer_data[this->x++] = 0.0f;
    vertex_buffer_data[this->x++] = -0.30f;vertex_buffer_data[this->x++] =  0.00f;vertex_buffer_data[this->x++] = 0.0f;
    vertex_buffer_data[this->x++] = -0.25f;vertex_buffer_data[this->x++] = -0.50f;vertex_buffer_data[this->x++] = 0.0f;
    
    vertex_buffer_data[this->x++] = -0.30f;vertex_buffer_data[this->x++] = -0.50f;vertex_buffer_data[this->x++] = 0.0f;
    vertex_buffer_data[this->x++] = -0.30f;vertex_buffer_data[this->x++] =  0.00f;vertex_buffer_data[this->x++] = 0.0f;
    vertex_buffer_data[this->x++] = -0.25f;vertex_buffer_data[this->x++] = -0.50f;vertex_buffer_data[this->x++] = 0.0f;
    //e
    vertex_buffer_data[this->x++] = -0.25f;vertex_buffer_data[this->x++] = -0.55f;vertex_buffer_data[this->x++] = 0.0f;
    vertex_buffer_data[this->x++] = -0.25f;vertex_buffer_data[this->x++] = -0.50f;vertex_buffer_data[this->x++] = 0.0f;
    vertex_buffer_data[this->x++] =  0.25f;vertex_buffer_data[this->x++] = -0.55f;vertex_buffer_data[this->x++] = 0.0f;
    
    vertex_buffer_data[this->x++] =  0.25f;vertex_buffer_data[this->x++] = -0.50f;vertex_buffer_data[this->x++] = 0.0f;
    vertex_buffer_data[this->x++] = -0.25f;vertex_buffer_data[this->x++] = -0.50f;vertex_buffer_data[this->x++] = 0.0f;
    vertex_buffer_data[this->x++] =  0.25f;vertex_buffer_data[this->x++] = -0.55f;vertex_buffer_data[this->x++] = 0.0f;
    //f
    vertex_buffer_data[this->x++] =  0.25f;vertex_buffer_data[this->x++] =  0.00f;vertex_buffer_data[this->x++] = 0.0f;
    vertex_buffer_data[this->x++] =  0.30f;vertex_buffer_data[this->x++] =  0.00f;vertex_buffer_data[this->x++] = 0.0f;
    vertex_buffer_data[this->x++] =  0.25f;vertex_buffer_data[this->x++] = -0.50f;vertex_buffer_data[this->x++] = 0.0f;
    
    vertex_buffer_data[this->x++] =  0.30f;vertex_buffer_data[this->x++] = -0.50f;vertex_buffer_data[this->x++] = 0.0f;
    vertex_buffer_data[this->x++] =  0.30f;vertex_buffer_data[this->x++] =  0.00f;vertex_buffer_data[this->x++] = 0.0f;
    vertex_buffer_data[this->x++] =  0.25f;vertex_buffer_data[this->x++] = -0.50f;vertex_buffer_data[this->x++] = 0.0f;
    
    GLfloat vertex_buffer_data1[200];
    this->x = 0;
    
    //a
    vertex_buffer_data1[this->x++] =  0.25f;vertex_buffer_data1[this->x++] = 0.00f;vertex_buffer_data1[this->x++] = 0.0f;
    vertex_buffer_data1[this->x++] =  0.30f;vertex_buffer_data1[this->x++] = 0.00f;vertex_buffer_data1[this->x++] = 0.0f;
    vertex_buffer_data1[this->x++] =  0.30f;vertex_buffer_data1[this->x++] = 0.50f;vertex_buffer_data1[this->x++] = 0.0f;
    
    vertex_buffer_data1[this->x++] =  0.25f;vertex_buffer_data1[this->x++] = 0.00f;vertex_buffer_data1[this->x++] = 0.0f;
    vertex_buffer_data1[this->x++] =  0.25f;vertex_buffer_data1[this->x++] = 0.50f;vertex_buffer_data1[this->x++] = 0.0f;
    vertex_buffer_data1[this->x++] =  0.30f;vertex_buffer_data1[this->x++] = 0.50f;vertex_buffer_data1[this->x++] = 0.0f;
    //f
    vertex_buffer_data1[this->x++] =  0.25f;vertex_buffer_data1[this->x++] =  0.00f;vertex_buffer_data1[this->x++] = 0.0f;
    vertex_buffer_data1[this->x++] =  0.30f;vertex_buffer_data1[this->x++] =  0.00f;vertex_buffer_data1[this->x++] = 0.0f;
    vertex_buffer_data1[this->x++] =  0.25f;vertex_buffer_data1[this->x++] = -0.50f;vertex_buffer_data1[this->x++] = 0.0f;
    
    vertex_buffer_data1[this->x++] =  0.30f;vertex_buffer_data1[this->x++] = -0.50f;vertex_buffer_data1[this->x++] = 0.0f;
    vertex_buffer_data1[this->x++] =  0.30f;vertex_buffer_data1[this->x++] =  0.00f;vertex_buffer_data1[this->x++] = 0.0f;
    vertex_buffer_data1[this->x++] =  0.25f;vertex_buffer_data1[this->x++] = -0.50f;vertex_buffer_data1[this->x++] = 0.0f;
    
    GLfloat vertex_buffer_data2[200];
    this->x = 0;
    
    //a
    vertex_buffer_data2[this->x++] =  0.25f;vertex_buffer_data2[this->x++] = 0.00f;vertex_buffer_data2[this->x++] = 0.0f;
    vertex_buffer_data2[this->x++] =  0.30f;vertex_buffer_data2[this->x++] = 0.00f;vertex_buffer_data2[this->x++] = 0.0f;
    vertex_buffer_data2[this->x++] =  0.30f;vertex_buffer_data2[this->x++] = 0.50f;vertex_buffer_data2[this->x++] = 0.0f;
    
    vertex_buffer_data2[this->x++] =  0.25f;vertex_buffer_data2[this->x++] = 0.00f;vertex_buffer_data2[this->x++] = 0.0f;
    vertex_buffer_data2[this->x++] =  0.25f;vertex_buffer_data2[this->x++] = 0.50f;vertex_buffer_data2[this->x++] = 0.0f;
    vertex_buffer_data2[this->x++] =  0.30f;vertex_buffer_data2[this->x++] = 0.50f;vertex_buffer_data2[this->x++] = 0.0f;
    //b
    vertex_buffer_data2[this->x++] =  0.25f;vertex_buffer_data2[this->x++] = 0.50f;vertex_buffer_data2[this->x++] = 0.0f;
    vertex_buffer_data2[this->x++] =  0.25f;vertex_buffer_data2[this->x++] = 0.55f;vertex_buffer_data2[this->x++] = 0.0f;
    vertex_buffer_data2[this->x++] = -0.25f;vertex_buffer_data2[this->x++] = 0.50f;vertex_buffer_data2[this->x++] = 0.0f;
    
    vertex_buffer_data2[this->x++] = -0.25f;vertex_buffer_data2[this->x++] = 0.55f;vertex_buffer_data2[this->x++] = 0.0f;
    vertex_buffer_data2[this->x++] =  0.25f;vertex_buffer_data2[this->x++] = 0.55f;vertex_buffer_data2[this->x++] = 0.0f;
    vertex_buffer_data2[this->x++] = -0.25f;vertex_buffer_data2[this->x++] = 0.50f;vertex_buffer_data2[this->x++] = 0.0f;
    //d
    vertex_buffer_data2[this->x++] = -0.25f;vertex_buffer_data2[this->x++] =  0.00f;vertex_buffer_data2[this->x++] = 0.0f;
    vertex_buffer_data2[this->x++] = -0.30f;vertex_buffer_data2[this->x++] =  0.00f;vertex_buffer_data2[this->x++] = 0.0f;
    vertex_buffer_data2[this->x++] = -0.25f;vertex_buffer_data2[this->x++] = -0.50f;vertex_buffer_data2[this->x++] = 0.0f;
    
    vertex_buffer_data2[this->x++] = -0.30f;vertex_buffer_data2[this->x++] = -0.50f;vertex_buffer_data2[this->x++] = 0.0f;
    vertex_buffer_data2[this->x++] = -0.30f;vertex_buffer_data2[this->x++] =  0.00f;vertex_buffer_data2[this->x++] = 0.0f;
    vertex_buffer_data2[this->x++] = -0.25f;vertex_buffer_data2[this->x++] = -0.50f;vertex_buffer_data2[this->x++] = 0.0f;
    //e
    vertex_buffer_data2[this->x++] = -0.25f;vertex_buffer_data2[this->x++] = -0.55f;vertex_buffer_data2[this->x++] = 0.0f;
    vertex_buffer_data2[this->x++] = -0.25f;vertex_buffer_data2[this->x++] = -0.50f;vertex_buffer_data2[this->x++] = 0.0f;
    vertex_buffer_data2[this->x++] =  0.25f;vertex_buffer_data2[this->x++] = -0.55f;vertex_buffer_data2[this->x++] = 0.0f;
    
    vertex_buffer_data2[this->x++] =  0.25f;vertex_buffer_data2[this->x++] = -0.50f;vertex_buffer_data2[this->x++] = 0.0f;
    vertex_buffer_data2[this->x++] = -0.25f;vertex_buffer_data2[this->x++] = -0.50f;vertex_buffer_data2[this->x++] = 0.0f;
    vertex_buffer_data2[this->x++] =  0.25f;vertex_buffer_data2[this->x++] = -0.55f;vertex_buffer_data2[this->x++] = 0.0f;
    //g
    vertex_buffer_data2[this->x++] =  0.25f;vertex_buffer_data2[this->x++] =  0.00f;vertex_buffer_data2[this->x++] = 0.0f;
    vertex_buffer_data2[this->x++] =  0.25f;vertex_buffer_data2[this->x++] =  0.05f;vertex_buffer_data2[this->x++] = 0.0f;
    vertex_buffer_data2[this->x++] = -0.25f;vertex_buffer_data2[this->x++] =  0.00f;vertex_buffer_data2[this->x++] = 0.0f;
    
    vertex_buffer_data2[this->x++] = -0.25f;vertex_buffer_data2[this->x++] =  0.05f;vertex_buffer_data2[this->x++] = 0.0f;
    vertex_buffer_data2[this->x++] =  0.25f;vertex_buffer_data2[this->x++] =  0.05f;vertex_buffer_data2[this->x++] = 0.0f;
    vertex_buffer_data2[this->x++] = -0.25f;vertex_buffer_data2[this->x++] =  0.00f;vertex_buffer_data2[this->x++] = 0.0f;
    
    GLfloat vertex_buffer_data3[200];
    this->x = 0;
    
    //a
    vertex_buffer_data3[this->x++] =  0.25f;vertex_buffer_data3[this->x++] = 0.00f;vertex_buffer_data3[this->x++] = 0.0f;
    vertex_buffer_data3[this->x++] =  0.30f;vertex_buffer_data3[this->x++] = 0.00f;vertex_buffer_data3[this->x++] = 0.0f;
    vertex_buffer_data3[this->x++] =  0.30f;vertex_buffer_data3[this->x++] = 0.50f;vertex_buffer_data3[this->x++] = 0.0f;
    
    vertex_buffer_data3[this->x++] =  0.25f;vertex_buffer_data3[this->x++] = 0.00f;vertex_buffer_data3[this->x++] = 0.0f;
    vertex_buffer_data3[this->x++] =  0.25f;vertex_buffer_data3[this->x++] = 0.50f;vertex_buffer_data3[this->x++] = 0.0f;
    vertex_buffer_data3[this->x++] =  0.30f;vertex_buffer_data3[this->x++] = 0.50f;vertex_buffer_data3[this->x++] = 0.0f;
    //b
    vertex_buffer_data3[this->x++] =  0.25f;vertex_buffer_data3[this->x++] = 0.50f;vertex_buffer_data3[this->x++] = 0.0f;
    vertex_buffer_data3[this->x++] =  0.25f;vertex_buffer_data3[this->x++] = 0.55f;vertex_buffer_data3[this->x++] = 0.0f;
    vertex_buffer_data3[this->x++] = -0.25f;vertex_buffer_data3[this->x++] = 0.50f;vertex_buffer_data3[this->x++] = 0.0f;
    
    vertex_buffer_data3[this->x++] = -0.25f;vertex_buffer_data3[this->x++] = 0.55f;vertex_buffer_data3[this->x++] = 0.0f;
    vertex_buffer_data3[this->x++] =  0.25f;vertex_buffer_data3[this->x++] = 0.55f;vertex_buffer_data3[this->x++] = 0.0f;
    vertex_buffer_data3[this->x++] = -0.25f;vertex_buffer_data3[this->x++] = 0.50f;vertex_buffer_data3[this->x++] = 0.0f;
    //e
    vertex_buffer_data3[this->x++] = -0.25f;vertex_buffer_data3[this->x++] = -0.55f;vertex_buffer_data3[this->x++] = 0.0f;
    vertex_buffer_data3[this->x++] = -0.25f;vertex_buffer_data3[this->x++] = -0.50f;vertex_buffer_data3[this->x++] = 0.0f;
    vertex_buffer_data3[this->x++] =  0.25f;vertex_buffer_data3[this->x++] = -0.55f;vertex_buffer_data3[this->x++] = 0.0f;
    
    vertex_buffer_data3[this->x++] =  0.25f;vertex_buffer_data3[this->x++] = -0.50f;vertex_buffer_data3[this->x++] = 0.0f;
    vertex_buffer_data3[this->x++] = -0.25f;vertex_buffer_data3[this->x++] = -0.50f;vertex_buffer_data3[this->x++] = 0.0f;
    vertex_buffer_data3[this->x++] =  0.25f;vertex_buffer_data3[this->x++] = -0.55f;vertex_buffer_data3[this->x++] = 0.0f;
    //f
    vertex_buffer_data3[this->x++] =  0.25f;vertex_buffer_data3[this->x++] =  0.00f;vertex_buffer_data3[this->x++] = 0.0f;
    vertex_buffer_data3[this->x++] =  0.30f;vertex_buffer_data3[this->x++] =  0.00f;vertex_buffer_data3[this->x++] = 0.0f;
    vertex_buffer_data3[this->x++] =  0.25f;vertex_buffer_data3[this->x++] = -0.50f;vertex_buffer_data3[this->x++] = 0.0f;
    
    vertex_buffer_data3[this->x++] =  0.30f;vertex_buffer_data3[this->x++] = -0.50f;vertex_buffer_data3[this->x++] = 0.0f;
    vertex_buffer_data3[this->x++] =  0.30f;vertex_buffer_data3[this->x++] =  0.00f;vertex_buffer_data3[this->x++] = 0.0f;
    vertex_buffer_data3[this->x++] =  0.25f;vertex_buffer_data3[this->x++] = -0.50f;vertex_buffer_data3[this->x++] = 0.0f;
    //g
    vertex_buffer_data3[this->x++] =  0.25f;vertex_buffer_data3[this->x++] =  0.00f;vertex_buffer_data3[this->x++] = 0.0f;
    vertex_buffer_data3[this->x++] =  0.25f;vertex_buffer_data3[this->x++] =  0.05f;vertex_buffer_data3[this->x++] = 0.0f;
    vertex_buffer_data3[this->x++] = -0.25f;vertex_buffer_data3[this->x++] =  0.00f;vertex_buffer_data3[this->x++] = 0.0f;
    
    vertex_buffer_data3[this->x++] = -0.25f;vertex_buffer_data3[this->x++] =  0.05f;vertex_buffer_data3[this->x++] = 0.0f;
    vertex_buffer_data3[this->x++] =  0.25f;vertex_buffer_data3[this->x++] =  0.05f;vertex_buffer_data3[this->x++] = 0.0f;
    vertex_buffer_data3[this->x++] = -0.25f;vertex_buffer_data3[this->x++] =  0.00f;vertex_buffer_data3[this->x++] = 0.0f;
    
    GLfloat vertex_buffer_data4[200];
    this->x = 0;
    
    //a
    vertex_buffer_data4[this->x++] =  0.25f;vertex_buffer_data4[this->x++] = 0.00f;vertex_buffer_data4[this->x++] = 0.0f;
    vertex_buffer_data4[this->x++] =  0.30f;vertex_buffer_data4[this->x++] = 0.00f;vertex_buffer_data4[this->x++] = 0.0f;
    vertex_buffer_data4[this->x++] =  0.30f;vertex_buffer_data4[this->x++] = 0.50f;vertex_buffer_data4[this->x++] = 0.0f;
    
    vertex_buffer_data4[this->x++] =  0.25f;vertex_buffer_data4[this->x++] = 0.00f;vertex_buffer_data4[this->x++] = 0.0f;
    vertex_buffer_data4[this->x++] =  0.25f;vertex_buffer_data4[this->x++] = 0.50f;vertex_buffer_data4[this->x++] = 0.0f;
    vertex_buffer_data4[this->x++] =  0.30f;vertex_buffer_data4[this->x++] = 0.50f;vertex_buffer_data4[this->x++] = 0.0f;
    //c
    vertex_buffer_data4[this->x++] = -0.25f;vertex_buffer_data4[this->x++] = 0.00f;vertex_buffer_data4[this->x++] = 0.0f;
    vertex_buffer_data4[this->x++] = -0.25f;vertex_buffer_data4[this->x++] = 0.50f;vertex_buffer_data4[this->x++] = 0.0f;
    vertex_buffer_data4[this->x++] = -0.30f;vertex_buffer_data4[this->x++] = 0.00f;vertex_buffer_data4[this->x++] = 0.0f;
    
    vertex_buffer_data4[this->x++] = -0.30f;vertex_buffer_data4[this->x++] = 0.50f;vertex_buffer_data4[this->x++] = 0.0f;
    vertex_buffer_data4[this->x++] = -0.25f;vertex_buffer_data4[this->x++] = 0.50f;vertex_buffer_data4[this->x++] = 0.0f;
    vertex_buffer_data4[this->x++] = -0.30f;vertex_buffer_data4[this->x++] = 0.00f;vertex_buffer_data4[this->x++] = 0.0f;
    //f
    vertex_buffer_data4[this->x++] =  0.25f;vertex_buffer_data4[this->x++] =  0.00f;vertex_buffer_data4[this->x++] = 0.0f;
    vertex_buffer_data4[this->x++] =  0.30f;vertex_buffer_data4[this->x++] =  0.00f;vertex_buffer_data4[this->x++] = 0.0f;
    vertex_buffer_data4[this->x++] =  0.25f;vertex_buffer_data4[this->x++] = -0.50f;vertex_buffer_data4[this->x++] = 0.0f;
    
    vertex_buffer_data4[this->x++] =  0.30f;vertex_buffer_data4[this->x++] = -0.50f;vertex_buffer_data4[this->x++] = 0.0f;
    vertex_buffer_data4[this->x++] =  0.30f;vertex_buffer_data4[this->x++] =  0.00f;vertex_buffer_data4[this->x++] = 0.0f;
    vertex_buffer_data4[this->x++] =  0.25f;vertex_buffer_data4[this->x++] = -0.50f;vertex_buffer_data4[this->x++] = 0.0f;
    //g
    vertex_buffer_data4[this->x++] =  0.25f;vertex_buffer_data4[this->x++] =  0.00f;vertex_buffer_data4[this->x++] = 0.0f;
    vertex_buffer_data4[this->x++] =  0.25f;vertex_buffer_data4[this->x++] =  0.05f;vertex_buffer_data4[this->x++] = 0.0f;
    vertex_buffer_data4[this->x++] = -0.25f;vertex_buffer_data4[this->x++] =  0.00f;vertex_buffer_data4[this->x++] = 0.0f;
    
    vertex_buffer_data4[this->x++] = -0.25f;vertex_buffer_data4[this->x++] =  0.05f;vertex_buffer_data4[this->x++] = 0.0f;
    vertex_buffer_data4[this->x++] =  0.25f;vertex_buffer_data4[this->x++] =  0.05f;vertex_buffer_data4[this->x++] = 0.0f;
    vertex_buffer_data4[this->x++] = -0.25f;vertex_buffer_data4[this->x++] =  0.00f;vertex_buffer_data4[this->x++] = 0.0f;
    
    GLfloat vertex_buffer_data5[200];
    this->x = 0;
    
    //b
    vertex_buffer_data5[this->x++] =  0.25f;vertex_buffer_data5[this->x++] = 0.50f;vertex_buffer_data5[this->x++] = 0.0f;
    vertex_buffer_data5[this->x++] =  0.25f;vertex_buffer_data5[this->x++] = 0.55f;vertex_buffer_data5[this->x++] = 0.0f;
    vertex_buffer_data5[this->x++] = -0.25f;vertex_buffer_data5[this->x++] = 0.50f;vertex_buffer_data5[this->x++] = 0.0f;
    
    vertex_buffer_data5[this->x++] = -0.25f;vertex_buffer_data5[this->x++] = 0.55f;vertex_buffer_data5[this->x++] = 0.0f;
    vertex_buffer_data5[this->x++] =  0.25f;vertex_buffer_data5[this->x++] = 0.55f;vertex_buffer_data5[this->x++] = 0.0f;
    vertex_buffer_data5[this->x++] = -0.25f;vertex_buffer_data5[this->x++] = 0.50f;vertex_buffer_data5[this->x++] = 0.0f;
    //c
    vertex_buffer_data5[this->x++] = -0.25f;vertex_buffer_data5[this->x++] = 0.00f;vertex_buffer_data5[this->x++] = 0.0f;
    vertex_buffer_data5[this->x++] = -0.25f;vertex_buffer_data5[this->x++] = 0.50f;vertex_buffer_data5[this->x++] = 0.0f;
    vertex_buffer_data5[this->x++] = -0.30f;vertex_buffer_data5[this->x++] = 0.00f;vertex_buffer_data5[this->x++] = 0.0f;
    
    vertex_buffer_data5[this->x++] = -0.30f;vertex_buffer_data5[this->x++] = 0.50f;vertex_buffer_data5[this->x++] = 0.0f;
    vertex_buffer_data5[this->x++] = -0.25f;vertex_buffer_data5[this->x++] = 0.50f;vertex_buffer_data5[this->x++] = 0.0f;
    vertex_buffer_data5[this->x++] = -0.30f;vertex_buffer_data5[this->x++] = 0.00f;vertex_buffer_data5[this->x++] = 0.0f;
    //e
    vertex_buffer_data5[this->x++] = -0.25f;vertex_buffer_data5[this->x++] = -0.55f;vertex_buffer_data5[this->x++] = 0.0f;
    vertex_buffer_data5[this->x++] = -0.25f;vertex_buffer_data5[this->x++] = -0.50f;vertex_buffer_data5[this->x++] = 0.0f;
    vertex_buffer_data5[this->x++] =  0.25f;vertex_buffer_data5[this->x++] = -0.55f;vertex_buffer_data5[this->x++] = 0.0f;
    
    vertex_buffer_data5[this->x++] =  0.25f;vertex_buffer_data5[this->x++] = -0.50f;vertex_buffer_data5[this->x++] = 0.0f;
    vertex_buffer_data5[this->x++] = -0.25f;vertex_buffer_data5[this->x++] = -0.50f;vertex_buffer_data5[this->x++] = 0.0f;
    vertex_buffer_data5[this->x++] =  0.25f;vertex_buffer_data5[this->x++] = -0.55f;vertex_buffer_data5[this->x++] = 0.0f;
    //f
    vertex_buffer_data5[this->x++] =  0.25f;vertex_buffer_data5[this->x++] =  0.00f;vertex_buffer_data5[this->x++] = 0.0f;
    vertex_buffer_data5[this->x++] =  0.30f;vertex_buffer_data5[this->x++] =  0.00f;vertex_buffer_data5[this->x++] = 0.0f;
    vertex_buffer_data5[this->x++] =  0.25f;vertex_buffer_data5[this->x++] = -0.50f;vertex_buffer_data5[this->x++] = 0.0f;
    
    vertex_buffer_data5[this->x++] =  0.30f;vertex_buffer_data5[this->x++] = -0.50f;vertex_buffer_data5[this->x++] = 0.0f;
    vertex_buffer_data5[this->x++] =  0.30f;vertex_buffer_data5[this->x++] =  0.00f;vertex_buffer_data5[this->x++] = 0.0f;
    vertex_buffer_data5[this->x++] =  0.25f;vertex_buffer_data5[this->x++] = -0.50f;vertex_buffer_data5[this->x++] = 0.0f;
    //g
    vertex_buffer_data5[this->x++] =  0.25f;vertex_buffer_data5[this->x++] =  0.00f;vertex_buffer_data5[this->x++] = 0.0f;
    vertex_buffer_data5[this->x++] =  0.25f;vertex_buffer_data5[this->x++] =  0.05f;vertex_buffer_data5[this->x++] = 0.0f;
    vertex_buffer_data5[this->x++] = -0.25f;vertex_buffer_data5[this->x++] =  0.00f;vertex_buffer_data5[this->x++] = 0.0f;
    
    vertex_buffer_data5[this->x++] = -0.25f;vertex_buffer_data5[this->x++] =  0.05f;vertex_buffer_data5[this->x++] = 0.0f;
    vertex_buffer_data5[this->x++] =  0.25f;vertex_buffer_data5[this->x++] =  0.05f;vertex_buffer_data5[this->x++] = 0.0f;
    vertex_buffer_data5[this->x++] = -0.25f;vertex_buffer_data5[this->x++] =  0.00f;vertex_buffer_data5[this->x++] = 0.0f;
    
    GLfloat vertex_buffer_data6[200];
    this->x = 0;
    
    //b
    vertex_buffer_data6[this->x++] =  0.25f;vertex_buffer_data6[this->x++] = 0.50f;vertex_buffer_data6[this->x++] = 0.0f;
    vertex_buffer_data6[this->x++] =  0.25f;vertex_buffer_data6[this->x++] = 0.55f;vertex_buffer_data6[this->x++] = 0.0f;
    vertex_buffer_data6[this->x++] = -0.25f;vertex_buffer_data6[this->x++] = 0.50f;vertex_buffer_data6[this->x++] = 0.0f;
    
    vertex_buffer_data6[this->x++] = -0.25f;vertex_buffer_data6[this->x++] = 0.55f;vertex_buffer_data6[this->x++] = 0.0f;
    vertex_buffer_data6[this->x++] =  0.25f;vertex_buffer_data6[this->x++] = 0.55f;vertex_buffer_data6[this->x++] = 0.0f;
    vertex_buffer_data6[this->x++] = -0.25f;vertex_buffer_data6[this->x++] = 0.50f;vertex_buffer_data6[this->x++] = 0.0f;
    //c
    vertex_buffer_data6[this->x++] = -0.25f;vertex_buffer_data6[this->x++] = 0.00f;vertex_buffer_data6[this->x++] = 0.0f;
    vertex_buffer_data6[this->x++] = -0.25f;vertex_buffer_data6[this->x++] = 0.50f;vertex_buffer_data6[this->x++] = 0.0f;
    vertex_buffer_data6[this->x++] = -0.30f;vertex_buffer_data6[this->x++] = 0.00f;vertex_buffer_data6[this->x++] = 0.0f;
    
    vertex_buffer_data6[this->x++] = -0.30f;vertex_buffer_data6[this->x++] = 0.50f;vertex_buffer_data6[this->x++] = 0.0f;
    vertex_buffer_data6[this->x++] = -0.25f;vertex_buffer_data6[this->x++] = 0.50f;vertex_buffer_data6[this->x++] = 0.0f;
    vertex_buffer_data6[this->x++] = -0.30f;vertex_buffer_data6[this->x++] = 0.00f;vertex_buffer_data6[this->x++] = 0.0f;
    //d
    vertex_buffer_data6[this->x++] = -0.25f;vertex_buffer_data6[this->x++] =  0.00f;vertex_buffer_data6[this->x++] = 0.0f;
    vertex_buffer_data6[this->x++] = -0.30f;vertex_buffer_data6[this->x++] =  0.00f;vertex_buffer_data6[this->x++] = 0.0f;
    vertex_buffer_data6[this->x++] = -0.25f;vertex_buffer_data6[this->x++] = -0.50f;vertex_buffer_data6[this->x++] = 0.0f;
    
    vertex_buffer_data6[this->x++] = -0.30f;vertex_buffer_data6[this->x++] = -0.50f;vertex_buffer_data6[this->x++] = 0.0f;
    vertex_buffer_data6[this->x++] = -0.30f;vertex_buffer_data6[this->x++] =  0.00f;vertex_buffer_data6[this->x++] = 0.0f;
    vertex_buffer_data6[this->x++] = -0.25f;vertex_buffer_data6[this->x++] = -0.50f;vertex_buffer_data6[this->x++] = 0.0f;
    //e
    vertex_buffer_data6[this->x++] = -0.25f;vertex_buffer_data6[this->x++] = -0.55f;vertex_buffer_data6[this->x++] = 0.0f;
    vertex_buffer_data6[this->x++] = -0.25f;vertex_buffer_data6[this->x++] = -0.50f;vertex_buffer_data6[this->x++] = 0.0f;
    vertex_buffer_data6[this->x++] =  0.25f;vertex_buffer_data6[this->x++] = -0.55f;vertex_buffer_data6[this->x++] = 0.0f;
    
    vertex_buffer_data6[this->x++] =  0.25f;vertex_buffer_data6[this->x++] = -0.50f;vertex_buffer_data6[this->x++] = 0.0f;
    vertex_buffer_data6[this->x++] = -0.25f;vertex_buffer_data6[this->x++] = -0.50f;vertex_buffer_data6[this->x++] = 0.0f;
    vertex_buffer_data6[this->x++] =  0.25f;vertex_buffer_data6[this->x++] = -0.55f;vertex_buffer_data6[this->x++] = 0.0f;
    //f
    vertex_buffer_data6[this->x++] =  0.25f;vertex_buffer_data6[this->x++] =  0.00f;vertex_buffer_data6[this->x++] = 0.0f;
    vertex_buffer_data6[this->x++] =  0.30f;vertex_buffer_data6[this->x++] =  0.00f;vertex_buffer_data6[this->x++] = 0.0f;
    vertex_buffer_data6[this->x++] =  0.25f;vertex_buffer_data6[this->x++] = -0.50f;vertex_buffer_data6[this->x++] = 0.0f;
    
    vertex_buffer_data6[this->x++] =  0.30f;vertex_buffer_data6[this->x++] = -0.50f;vertex_buffer_data6[this->x++] = 0.0f;
    vertex_buffer_data6[this->x++] =  0.30f;vertex_buffer_data6[this->x++] =  0.00f;vertex_buffer_data6[this->x++] = 0.0f;
    vertex_buffer_data6[this->x++] =  0.25f;vertex_buffer_data6[this->x++] = -0.50f;vertex_buffer_data6[this->x++] = 0.0f;
    //g
    vertex_buffer_data6[this->x++] =  0.25f;vertex_buffer_data6[this->x++] =  0.00f;vertex_buffer_data6[this->x++] = 0.0f;
    vertex_buffer_data6[this->x++] =  0.25f;vertex_buffer_data6[this->x++] =  0.05f;vertex_buffer_data6[this->x++] = 0.0f;
    vertex_buffer_data6[this->x++] = -0.25f;vertex_buffer_data6[this->x++] =  0.00f;vertex_buffer_data6[this->x++] = 0.0f;
    
    vertex_buffer_data6[this->x++] = -0.25f;vertex_buffer_data6[this->x++] =  0.05f;vertex_buffer_data6[this->x++] = 0.0f;
    vertex_buffer_data6[this->x++] =  0.25f;vertex_buffer_data6[this->x++] =  0.05f;vertex_buffer_data6[this->x++] = 0.0f;
    vertex_buffer_data6[this->x++] = -0.25f;vertex_buffer_data6[this->x++] =  0.00f;vertex_buffer_data6[this->x++] = 0.0f;
    
    GLfloat vertex_buffer_data7[200];
    this->x = 0;
    
    //a
    vertex_buffer_data7[this->x++] =  0.25f;vertex_buffer_data7[this->x++] = 0.00f;vertex_buffer_data7[this->x++] = 0.0f;
    vertex_buffer_data7[this->x++] =  0.30f;vertex_buffer_data7[this->x++] = 0.00f;vertex_buffer_data7[this->x++] = 0.0f;
    vertex_buffer_data7[this->x++] =  0.30f;vertex_buffer_data7[this->x++] = 0.50f;vertex_buffer_data7[this->x++] = 0.0f;
    
    vertex_buffer_data7[this->x++] =  0.25f;vertex_buffer_data7[this->x++] = 0.00f;vertex_buffer_data7[this->x++] = 0.0f;
    vertex_buffer_data7[this->x++] =  0.25f;vertex_buffer_data7[this->x++] = 0.50f;vertex_buffer_data7[this->x++] = 0.0f;
    vertex_buffer_data7[this->x++] =  0.30f;vertex_buffer_data7[this->x++] = 0.50f;vertex_buffer_data7[this->x++] = 0.0f;
    //b
    vertex_buffer_data7[this->x++] =  0.25f;vertex_buffer_data7[this->x++] = 0.50f;vertex_buffer_data7[this->x++] = 0.0f;
    vertex_buffer_data7[this->x++] =  0.25f;vertex_buffer_data7[this->x++] = 0.55f;vertex_buffer_data7[this->x++] = 0.0f;
    vertex_buffer_data7[this->x++] = -0.25f;vertex_buffer_data7[this->x++] = 0.50f;vertex_buffer_data7[this->x++] = 0.0f;
    
    vertex_buffer_data7[this->x++] = -0.25f;vertex_buffer_data7[this->x++] = 0.55f;vertex_buffer_data7[this->x++] = 0.0f;
    vertex_buffer_data7[this->x++] =  0.25f;vertex_buffer_data7[this->x++] = 0.55f;vertex_buffer_data7[this->x++] = 0.0f;
    vertex_buffer_data7[this->x++] = -0.25f;vertex_buffer_data7[this->x++] = 0.50f;vertex_buffer_data7[this->x++] = 0.0f;
    //f
    vertex_buffer_data7[this->x++] =  0.25f;vertex_buffer_data7[this->x++] =  0.00f;vertex_buffer_data7[this->x++] = 0.0f;
    vertex_buffer_data7[this->x++] =  0.30f;vertex_buffer_data7[this->x++] =  0.00f;vertex_buffer_data7[this->x++] = 0.0f;
    vertex_buffer_data7[this->x++] =  0.25f;vertex_buffer_data7[this->x++] = -0.50f;vertex_buffer_data7[this->x++] = 0.0f;
    
    vertex_buffer_data7[this->x++] =  0.30f;vertex_buffer_data7[this->x++] = -0.50f;vertex_buffer_data7[this->x++] = 0.0f;
    vertex_buffer_data7[this->x++] =  0.30f;vertex_buffer_data7[this->x++] =  0.00f;vertex_buffer_data7[this->x++] = 0.0f;
    vertex_buffer_data7[this->x++] =  0.25f;vertex_buffer_data7[this->x++] = -0.50f;vertex_buffer_data7[this->x++] = 0.0f;
    
    GLfloat vertex_buffer_data8[200];
    this->x = 0;

    //a
    vertex_buffer_data8[this->x++] =  0.25f;vertex_buffer_data8[this->x++] = 0.00f;vertex_buffer_data8[this->x++] = 0.0f;
    vertex_buffer_data8[this->x++] =  0.30f;vertex_buffer_data8[this->x++] = 0.00f;vertex_buffer_data8[this->x++] = 0.0f;
    vertex_buffer_data8[this->x++] =  0.30f;vertex_buffer_data8[this->x++] = 0.50f;vertex_buffer_data8[this->x++] = 0.0f;
    
    vertex_buffer_data8[this->x++] =  0.25f;vertex_buffer_data8[this->x++] = 0.00f;vertex_buffer_data8[this->x++] = 0.0f;
    vertex_buffer_data8[this->x++] =  0.25f;vertex_buffer_data8[this->x++] = 0.50f;vertex_buffer_data8[this->x++] = 0.0f;
    vertex_buffer_data8[this->x++] =  0.30f;vertex_buffer_data8[this->x++] = 0.50f;vertex_buffer_data8[this->x++] = 0.0f;
    //b
    vertex_buffer_data8[this->x++] =  0.25f;vertex_buffer_data8[this->x++] = 0.50f;vertex_buffer_data8[this->x++] = 0.0f;
    vertex_buffer_data8[this->x++] =  0.25f;vertex_buffer_data8[this->x++] = 0.55f;vertex_buffer_data8[this->x++] = 0.0f;
    vertex_buffer_data8[this->x++] = -0.25f;vertex_buffer_data8[this->x++] = 0.50f;vertex_buffer_data8[this->x++] = 0.0f;
    
    vertex_buffer_data8[this->x++] = -0.25f;vertex_buffer_data8[this->x++] = 0.55f;vertex_buffer_data8[this->x++] = 0.0f;
    vertex_buffer_data8[this->x++] =  0.25f;vertex_buffer_data8[this->x++] = 0.55f;vertex_buffer_data8[this->x++] = 0.0f;
    vertex_buffer_data8[this->x++] = -0.25f;vertex_buffer_data8[this->x++] = 0.50f;vertex_buffer_data8[this->x++] = 0.0f;
    //c
    vertex_buffer_data8[this->x++] = -0.25f;vertex_buffer_data8[this->x++] = 0.00f;vertex_buffer_data8[this->x++] = 0.0f;
    vertex_buffer_data8[this->x++] = -0.25f;vertex_buffer_data8[this->x++] = 0.50f;vertex_buffer_data8[this->x++] = 0.0f;
    vertex_buffer_data8[this->x++] = -0.30f;vertex_buffer_data8[this->x++] = 0.00f;vertex_buffer_data8[this->x++] = 0.0f;
    
    vertex_buffer_data8[this->x++] = -0.30f;vertex_buffer_data8[this->x++] = 0.50f;vertex_buffer_data8[this->x++] = 0.0f;
    vertex_buffer_data8[this->x++] = -0.25f;vertex_buffer_data8[this->x++] = 0.50f;vertex_buffer_data8[this->x++] = 0.0f;
    vertex_buffer_data8[this->x++] = -0.30f;vertex_buffer_data8[this->x++] = 0.00f;vertex_buffer_data8[this->x++] = 0.0f;
    //d
    vertex_buffer_data8[this->x++] = -0.25f;vertex_buffer_data8[this->x++] =  0.00f;vertex_buffer_data8[this->x++] = 0.0f;
    vertex_buffer_data8[this->x++] = -0.30f;vertex_buffer_data8[this->x++] =  0.00f;vertex_buffer_data8[this->x++] = 0.0f;
    vertex_buffer_data8[this->x++] = -0.25f;vertex_buffer_data8[this->x++] = -0.50f;vertex_buffer_data8[this->x++] = 0.0f;
    
    vertex_buffer_data8[this->x++] = -0.30f;vertex_buffer_data8[this->x++] = -0.50f;vertex_buffer_data8[this->x++] = 0.0f;
    vertex_buffer_data8[this->x++] = -0.30f;vertex_buffer_data8[this->x++] =  0.00f;vertex_buffer_data8[this->x++] = 0.0f;
    vertex_buffer_data8[this->x++] = -0.25f;vertex_buffer_data8[this->x++] = -0.50f;vertex_buffer_data8[this->x++] = 0.0f;
    //e
    vertex_buffer_data8[this->x++] = -0.25f;vertex_buffer_data8[this->x++] = -0.55f;vertex_buffer_data8[this->x++] = 0.0f;
    vertex_buffer_data8[this->x++] = -0.25f;vertex_buffer_data8[this->x++] = -0.50f;vertex_buffer_data8[this->x++] = 0.0f;
    vertex_buffer_data8[this->x++] =  0.25f;vertex_buffer_data8[this->x++] = -0.55f;vertex_buffer_data8[this->x++] = 0.0f;
    
    vertex_buffer_data8[this->x++] =  0.25f;vertex_buffer_data8[this->x++] = -0.50f;vertex_buffer_data8[this->x++] = 0.0f;
    vertex_buffer_data8[this->x++] = -0.25f;vertex_buffer_data8[this->x++] = -0.50f;vertex_buffer_data8[this->x++] = 0.0f;
    vertex_buffer_data8[this->x++] =  0.25f;vertex_buffer_data8[this->x++] = -0.55f;vertex_buffer_data8[this->x++] = 0.0f;
    //f
    vertex_buffer_data8[this->x++] =  0.25f;vertex_buffer_data8[this->x++] =  0.00f;vertex_buffer_data8[this->x++] = 0.0f;
    vertex_buffer_data8[this->x++] =  0.30f;vertex_buffer_data8[this->x++] =  0.00f;vertex_buffer_data8[this->x++] = 0.0f;
    vertex_buffer_data8[this->x++] =  0.25f;vertex_buffer_data8[this->x++] = -0.50f;vertex_buffer_data8[this->x++] = 0.0f;
    
    vertex_buffer_data8[this->x++] =  0.30f;vertex_buffer_data8[this->x++] = -0.50f;vertex_buffer_data8[this->x++] = 0.0f;
    vertex_buffer_data8[this->x++] =  0.30f;vertex_buffer_data8[this->x++] =  0.00f;vertex_buffer_data8[this->x++] = 0.0f;
    vertex_buffer_data8[this->x++] =  0.25f;vertex_buffer_data8[this->x++] = -0.50f;vertex_buffer_data8[this->x++] = 0.0f;
    //g
    vertex_buffer_data8[this->x++] =  0.25f;vertex_buffer_data8[this->x++] =  0.00f;vertex_buffer_data8[this->x++] = 0.0f;
    vertex_buffer_data8[this->x++] =  0.25f;vertex_buffer_data8[this->x++] =  0.05f;vertex_buffer_data8[this->x++] = 0.0f;
    vertex_buffer_data8[this->x++] = -0.25f;vertex_buffer_data8[this->x++] =  0.00f;vertex_buffer_data8[this->x++] = 0.0f;
    
    vertex_buffer_data8[this->x++] = -0.25f;vertex_buffer_data8[this->x++] =  0.05f;vertex_buffer_data8[this->x++] = 0.0f;
    vertex_buffer_data8[this->x++] =  0.25f;vertex_buffer_data8[this->x++] =  0.05f;vertex_buffer_data8[this->x++] = 0.0f;
    vertex_buffer_data8[this->x++] = -0.25f;vertex_buffer_data8[this->x++] =  0.00f;vertex_buffer_data8[this->x++] = 0.0f;
    
    GLfloat vertex_buffer_data9[200];
    this->x = 0;
    
    //a
    vertex_buffer_data9[this->x++] =  0.25f;vertex_buffer_data9[this->x++] = 0.00f;vertex_buffer_data9[this->x++] = 0.0f;
    vertex_buffer_data9[this->x++] =  0.30f;vertex_buffer_data9[this->x++] = 0.00f;vertex_buffer_data9[this->x++] = 0.0f;
    vertex_buffer_data9[this->x++] =  0.30f;vertex_buffer_data9[this->x++] = 0.50f;vertex_buffer_data9[this->x++] = 0.0f;
    
    vertex_buffer_data9[this->x++] =  0.25f;vertex_buffer_data9[this->x++] = 0.00f;vertex_buffer_data9[this->x++] = 0.0f;
    vertex_buffer_data9[this->x++] =  0.25f;vertex_buffer_data9[this->x++] = 0.50f;vertex_buffer_data9[this->x++] = 0.0f;
    vertex_buffer_data9[this->x++] =  0.30f;vertex_buffer_data9[this->x++] = 0.50f;vertex_buffer_data9[this->x++] = 0.0f;
    //b
    vertex_buffer_data9[this->x++] =  0.25f;vertex_buffer_data9[this->x++] = 0.50f;vertex_buffer_data9[this->x++] = 0.0f;
    vertex_buffer_data9[this->x++] =  0.25f;vertex_buffer_data9[this->x++] = 0.55f;vertex_buffer_data9[this->x++] = 0.0f;
    vertex_buffer_data9[this->x++] = -0.25f;vertex_buffer_data9[this->x++] = 0.50f;vertex_buffer_data9[this->x++] = 0.0f;
    
    vertex_buffer_data9[this->x++] = -0.25f;vertex_buffer_data9[this->x++] = 0.55f;vertex_buffer_data9[this->x++] = 0.0f;
    vertex_buffer_data9[this->x++] =  0.25f;vertex_buffer_data9[this->x++] = 0.55f;vertex_buffer_data9[this->x++] = 0.0f;
    vertex_buffer_data9[this->x++] = -0.25f;vertex_buffer_data9[this->x++] = 0.50f;vertex_buffer_data9[this->x++] = 0.0f;
    //c
    vertex_buffer_data9[this->x++] = -0.25f;vertex_buffer_data9[this->x++] = 0.00f;vertex_buffer_data9[this->x++] = 0.0f;
    vertex_buffer_data9[this->x++] = -0.25f;vertex_buffer_data9[this->x++] = 0.50f;vertex_buffer_data9[this->x++] = 0.0f;
    vertex_buffer_data9[this->x++] = -0.30f;vertex_buffer_data9[this->x++] = 0.00f;vertex_buffer_data9[this->x++] = 0.0f;
    
    vertex_buffer_data9[this->x++] = -0.30f;vertex_buffer_data9[this->x++] = 0.50f;vertex_buffer_data9[this->x++] = 0.0f;
    vertex_buffer_data9[this->x++] = -0.25f;vertex_buffer_data9[this->x++] = 0.50f;vertex_buffer_data9[this->x++] = 0.0f;
    vertex_buffer_data9[this->x++] = -0.30f;vertex_buffer_data9[this->x++] = 0.00f;vertex_buffer_data9[this->x++] = 0.0f;
    //e
    vertex_buffer_data9[this->x++] = -0.25f;vertex_buffer_data9[this->x++] = -0.55f;vertex_buffer_data9[this->x++] = 0.0f;
    vertex_buffer_data9[this->x++] = -0.25f;vertex_buffer_data9[this->x++] = -0.50f;vertex_buffer_data9[this->x++] = 0.0f;
    vertex_buffer_data9[this->x++] =  0.25f;vertex_buffer_data9[this->x++] = -0.55f;vertex_buffer_data9[this->x++] = 0.0f;
    
    vertex_buffer_data9[this->x++] =  0.25f;vertex_buffer_data9[this->x++] = -0.50f;vertex_buffer_data9[this->x++] = 0.0f;
    vertex_buffer_data9[this->x++] = -0.25f;vertex_buffer_data9[this->x++] = -0.50f;vertex_buffer_data9[this->x++] = 0.0f;
    vertex_buffer_data9[this->x++] =  0.25f;vertex_buffer_data9[this->x++] = -0.55f;vertex_buffer_data9[this->x++] = 0.0f;
    //f
    vertex_buffer_data9[this->x++] =  0.25f;vertex_buffer_data9[this->x++] =  0.00f;vertex_buffer_data9[this->x++] = 0.0f;
    vertex_buffer_data9[this->x++] =  0.30f;vertex_buffer_data9[this->x++] =  0.00f;vertex_buffer_data9[this->x++] = 0.0f;
    vertex_buffer_data9[this->x++] =  0.25f;vertex_buffer_data9[this->x++] = -0.50f;vertex_buffer_data9[this->x++] = 0.0f;
    
    vertex_buffer_data9[this->x++] =  0.30f;vertex_buffer_data9[this->x++] = -0.50f;vertex_buffer_data9[this->x++] = 0.0f;
    vertex_buffer_data9[this->x++] =  0.30f;vertex_buffer_data9[this->x++] =  0.00f;vertex_buffer_data9[this->x++] = 0.0f;
    vertex_buffer_data9[this->x++] =  0.25f;vertex_buffer_data9[this->x++] = -0.50f;vertex_buffer_data9[this->x++] = 0.0f;
    //g
    vertex_buffer_data9[this->x++] =  0.25f;vertex_buffer_data9[this->x++] =  0.00f;vertex_buffer_data9[this->x++] = 0.0f;
    vertex_buffer_data9[this->x++] =  0.25f;vertex_buffer_data9[this->x++] =  0.05f;vertex_buffer_data9[this->x++] = 0.0f;
    vertex_buffer_data9[this->x++] = -0.25f;vertex_buffer_data9[this->x++] =  0.00f;vertex_buffer_data9[this->x++] = 0.0f;
    
    vertex_buffer_data9[this->x++] = -0.25f;vertex_buffer_data9[this->x++] =  0.05f;vertex_buffer_data9[this->x++] = 0.0f;
    vertex_buffer_data9[this->x++] =  0.25f;vertex_buffer_data9[this->x++] =  0.05f;vertex_buffer_data9[this->x++] = 0.0f;
    vertex_buffer_data9[this->x++] = -0.25f;vertex_buffer_data9[this->x++] =  0.00f;vertex_buffer_data9[this->x++] = 0.0f;
    
    
    this->object = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data, color, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 4*3, vertex_buffer_data1, color, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 10*3, vertex_buffer_data2, color, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 10*3, vertex_buffer_data3, color, GL_FILL);
    this->object4 = create3DObject(GL_TRIANGLES, 8*3, vertex_buffer_data4, color, GL_FILL);
    this->object5 = create3DObject(GL_TRIANGLES, 10*3, vertex_buffer_data5, color, GL_FILL);
    this->object6 = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data6, color, GL_FILL);
    this->object7 = create3DObject(GL_TRIANGLES, 6*3, vertex_buffer_data7, color, GL_FILL);
    this->object8 = create3DObject(GL_TRIANGLES, 14*3, vertex_buffer_data8, color, GL_FILL);
    this->object9 = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data9, color, GL_FILL);
}

void Score::draw(glm::mat4 VP,int n) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    if(n == 0)draw3DObject(this->object);
    if(n == 1)draw3DObject(this->object1);
    if(n == 2)draw3DObject(this->object2);
    if(n == 3)draw3DObject(this->object3);
    if(n == 4)draw3DObject(this->object4);
    if(n == 5)draw3DObject(this->object5);
    if(n == 6)draw3DObject(this->object6);
    if(n == 7)draw3DObject(this->object7);
    if(n == 8)draw3DObject(this->object8);
    if(n == 9)draw3DObject(this->object9);
    
}

void Score::set_position(float x, float y) 
{
    this->position = glm::vec3(x, y, 0);
}

void Score::tick() 
{
    // if(this->position.y < 3.0f)
    //     this->position.x -= 0.10;
    // this->position.y -= 0.05;
    // this->timer += 0.01;
    // this->rotation += 20.0f;
}

