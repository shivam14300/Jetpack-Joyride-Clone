#include "dragon.h"
#include "main.h"
#include<math.h>
Dragon::Dragon(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0.0;
    this->timer = 0.0;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    
    GLfloat vertex_buffer_data[120];
    vertex_buffer_data[0] = 1.0f;vertex_buffer_data[1] = 1.0f;vertex_buffer_data[2] = 0.0f;
    vertex_buffer_data[3] = 1.0f;vertex_buffer_data[4] = -1.0f;vertex_buffer_data[5] = 0.0f;
    vertex_buffer_data[6] = -1.0f;vertex_buffer_data[7] = 1.0f;vertex_buffer_data[8] = 0.0f;
    
    vertex_buffer_data[9] = -1.0f;vertex_buffer_data[10] = -1.0f;vertex_buffer_data[11] = 0.0f;
    vertex_buffer_data[12] = 1.0f;vertex_buffer_data[13] = -1.0f;vertex_buffer_data[14] = 0.0f;
    vertex_buffer_data[15] = -1.0f;vertex_buffer_data[16] = 1.0f;vertex_buffer_data[17] = 0.0f;
    
    vertex_buffer_data[18] = 1.0f;vertex_buffer_data[19] = 0.0f;vertex_buffer_data[20] = 0.0f;
    vertex_buffer_data[21] = -1.0f;vertex_buffer_data[22] = 0.0f;vertex_buffer_data[23] = 0.0f;
    vertex_buffer_data[24] = 0.0f;vertex_buffer_data[25] = 3.0f;vertex_buffer_data[26] = 0.0f;
    
    vertex_buffer_data[27] = 1.0f;vertex_buffer_data[28] = 1.0f;vertex_buffer_data[29] = 0.0f;
    vertex_buffer_data[30] = 0.0f;vertex_buffer_data[31] = 1.0f;vertex_buffer_data[32] = 0.0f;
    vertex_buffer_data[33] = 0.75f;vertex_buffer_data[34] = 3.0f;vertex_buffer_data[35] = 0.0f;
    
    vertex_buffer_data[36] = 1.0f;vertex_buffer_data[37] = 0.5f;vertex_buffer_data[38] = 0.0f;
    vertex_buffer_data[39] = 1.0f;vertex_buffer_data[40] = -0.5f;vertex_buffer_data[41] = 0.0f;
    vertex_buffer_data[42] = 2.0f;vertex_buffer_data[43] = -1.0f;vertex_buffer_data[44] = 0.0f;

    vertex_buffer_data[45] = 1.0f;vertex_buffer_data[46] = 0.5f;vertex_buffer_data[47] = 0.0f;
    vertex_buffer_data[48] = 2.0f;vertex_buffer_data[49] = -1.0f;vertex_buffer_data[50] = 0.0f;
    vertex_buffer_data[51] = 2.0f;vertex_buffer_data[52] = 0.0f;vertex_buffer_data[53] = 0.0f;

    vertex_buffer_data[54] = 2.0f;vertex_buffer_data[55] = 0.0f;vertex_buffer_data[56] = 0.0f;
    vertex_buffer_data[57] = 2.0f;vertex_buffer_data[58] = -1.0f;vertex_buffer_data[59] = 0.0f;
    vertex_buffer_data[60] = 3.0f;vertex_buffer_data[61] = 1.0f;vertex_buffer_data[62] = 0.0f;

    vertex_buffer_data[63] = 2.0f;vertex_buffer_data[64] = -1.0f;vertex_buffer_data[65] = 0.0f;
    vertex_buffer_data[66] = 3.0f;vertex_buffer_data[67] = 0.0f;vertex_buffer_data[68] = 0.0f;
    vertex_buffer_data[69] = 3.0f;vertex_buffer_data[70] = 1.0f;vertex_buffer_data[71] = 0.0f;

    vertex_buffer_data[72] = 3.0f;vertex_buffer_data[73] = 0.0f;vertex_buffer_data[74] = 0.0f;
    vertex_buffer_data[75] = 3.0f;vertex_buffer_data[76] = 1.0f;vertex_buffer_data[77] = 0.0f;
    vertex_buffer_data[78] = 4.0f;vertex_buffer_data[79] = 0.5f;vertex_buffer_data[80] = 0.0f;

    vertex_buffer_data[81] = -1.0f;vertex_buffer_data[82] = 0.0f;vertex_buffer_data[83] = 0.0f;
    vertex_buffer_data[84] = -1.0f;vertex_buffer_data[85] = 1.0f;vertex_buffer_data[86] = 0.0f;
    vertex_buffer_data[87] = -2.0f;vertex_buffer_data[88] = 2.0f;vertex_buffer_data[89] = 0.0f;

    vertex_buffer_data[90] = -2.0f;vertex_buffer_data[91] = 1.0f;vertex_buffer_data[92] = 0.0f;
    vertex_buffer_data[93] = -2.0f;vertex_buffer_data[94] = 2.0f;vertex_buffer_data[95] = 0.0f;
    vertex_buffer_data[96] = -1.0f;vertex_buffer_data[97] = 0.0f;vertex_buffer_data[98] = 0.0f;

    vertex_buffer_data[99] = -2.0f;vertex_buffer_data[100] = 1.0f;vertex_buffer_data[101] = 0.0f;
    vertex_buffer_data[102] = -2.0f;vertex_buffer_data[103] = 2.0f;vertex_buffer_data[104] = 0.0f;
    vertex_buffer_data[105] = -3.0f;vertex_buffer_data[106] = 1.0f;vertex_buffer_data[107] = 0.0f;

    vertex_buffer_data[108] = -3.0f;vertex_buffer_data[109] = 1.0f;vertex_buffer_data[110] = 0.0f;
    vertex_buffer_data[111] = -2.0f;vertex_buffer_data[112] = 2.0f;vertex_buffer_data[113] = 0.0f;
    vertex_buffer_data[114] = -3.0f;vertex_buffer_data[115] = 2.0f;vertex_buffer_data[116] = 0.0f;



    this->object = create3DObject(GL_TRIANGLES, 13*3, vertex_buffer_data, color, GL_FILL);
}

void Dragon::draw(glm::mat4 VP) {
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

void Dragon::set_position(float x, float y) 
{
    this->position = glm::vec3(x, y, 0);
}

void Dragon::tick() 
{
    this->timer += 0.1;
    this->position.x += 0.75;
    this->position.y -= 0.5*(this->timer*this->timer);
    this->rotation -= 30.0; 
}
