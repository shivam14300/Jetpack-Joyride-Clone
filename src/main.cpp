#include "main.h"
#include "timer.h"
#include "ball.h"
#include "floor.h"
#include "coin.h"
#include "enemy1.h"
#include "laser.h"
#include "special.h"
#include "boomer.h"
#include "magnet.h"
#include "balloon.h"
#include "jet.h"
#include "dragon.h"
#include "score.h"
#include "tunnel.h"
#include "blueballs.h"
#include "wall.h"

using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/
Wall wall[20];
Ball ball1; bounding_box_t ball1_bbt;
vector<Laser> laser; vector<bounding_box_t> laser_bbt;
vector<Coin> cn; vector<bounding_box_t> coin_bbt;
vector<Enemy1> enemy1; vector<bounding_box_t> enemy1_bbt;
vector<Special> special; vector<bounding_box_t> special_bbt;
vector<Boomer> boomer; vector<bounding_box_t> boomer_bbt;
Magnet magnet; bounding_box_t magnet_bbt;
vector<Balloon> balloon; vector<bounding_box_t> balloon_bbt;
vector<Blueballs> blueballs; vector<bounding_box_t> blueballs_bbt;
vector<Jet> jet;
Dragon dragon;vector<bounding_box_t> dragon_bbt;
Tunnel tunnel; bounding_box_t tunnel_bbt;
Score score[10];
Floor flr[3000];

float lives;
int balloon_flag;
int player_score;
int laser_start;
float laser_timer;
float camx,camy,speed,speedy,balloon_timer;
double dist,force,forcex,forcey;
float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0;
float top,bottom,left1,right1;
float lower_limit,upper_limit;


Timer t60(1.0 / 60);

/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

    // Eye - Location of camera. Don't change unless you are sure!!
    // glm::vec3 eye ( 5*cos(camera_rotation_angle*M_PI/180.0f), 0, 5*sin(camera_rotation_angle*M_PI/180.0f) );
    glm::vec3 eye (camx, camy, 10);
    // Target - Where is the camera looking at.  Don't change unless you are sure!!
    glm::vec3 target (camx, camy, 0);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
    glm::vec3 up (0, 1, 0);

    // Compute Camera matrix (view)
    Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
    // Don't change unless you are sure!!
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model

    // Scene render

    for(int i=0;i<20;i++)wall[i].draw(VP);
    for(int i=0;i<3000;i++)flr[i].draw(VP);
    for(int i=0;i<cn.size();i++)cn[i].draw(VP);
    for(int i=0;i<enemy1.size();i++)
    {
        enemy1[i].draw(VP);
    }
    for(int i=0;i<special.size();i++)special[i].draw(VP);
    for(int i=0;i<boomer.size();i++)boomer[i].draw(VP);
    for(int i=0;i<laser.size();i++)
    {
        if(laser_start == 1)
        {
            laser[i].draw(VP, laser_timer);
            laser_timer += ((float)1.0/(float)60.0);
            if(laser_timer > 10.0)
            {
                laser_start = 0;
                laser_timer = 0.0;
                laser.clear();
                laser_bbt.clear();
                break;
            }
        }
        
    }
    magnet.draw(VP);
    dragon.draw(VP);
    for(int i=0;i<balloon.size();i++)
    {
        if(balloon[i].position.y < -1.8f)
        {
            balloon.erase(balloon.begin()+i);
            balloon_bbt.erase(balloon_bbt.begin()+i);
            continue;
        }
        balloon[i].draw(VP);
    }
    for(int i=0;i<jet.size();i++)
    {
        if(jet[i].timer > 0.4f || jet[i].position.y < -4.5f)
            jet.erase(jet.begin()+i);
        jet[i].draw(VP);
    }
    for(int i=0;i<blueballs.size();i++)
    {
        blueballs[i].draw(VP);
        blueballs[i].timer += 0.1;
        if(blueballs[i].timer > 5.0)
        {
            blueballs.erase(blueballs.begin()+i);
        }
    }
    ball1.draw(VP);
    tunnel.draw(VP);
    int temp_score = player_score;
    for(int i=3;i>=0;i--)
    {   
        int x = temp_score%10;
        temp_score /= 10;
        score[i].draw(VP, x);
    }
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) 
{
    /* Objects should be created before any other gl function and shaders */
    // Create the models

    float x1 = -4.0;
    float x2 = -4.0;
    wall[0] = Wall(0.0,0.0, COLOR_B1,0);
    wall[1] = Wall(200,0.0, COLOR_B2,1);
    wall[2] = Wall(400,0.0, COLOR_B3,0);
    wall[3] = Wall(600,0.0, COLOR_B4,1);
    wall[4] = Wall(600,0.0, COLOR_B4,0);
    wall[5] = Wall(600,0.0, COLOR_B4,1);
    wall[6] = Wall(600,0.0, COLOR_B4,0);
    wall[7] = Wall(600,0.0, COLOR_B4,1);
    wall[8] = Wall(600,0.0, COLOR_B4,0);
    wall[9] = Wall(600,0.0, COLOR_B4,1);
    wall[10] = Wall(600,0.0, COLOR_B4,0);
    wall[11] = Wall(600,0.0, COLOR_B4,1);
    wall[12] = Wall(600,0.0, COLOR_B4,0);
    wall[13] = Wall(600,0.0, COLOR_B4,1);
    wall[14] = Wall(600,0.0, COLOR_B4,0);
    wall[15] = Wall(600,0.0, COLOR_B4,1);
    wall[16] = Wall(600,0.0, COLOR_B4,0);
    wall[17] = Wall(600,0.0, COLOR_B4,1);
    wall[18] = Wall(600,0.0, COLOR_B4,0);
    wall[19] = Wall(600,0.0, COLOR_B4,1);
    //ball
    ball1 = Ball(0, -1.5f, COLOR_RED, COLOR_BLACK);
    ball1_bbt.x = ball1.position.x;ball1_bbt.y = ball1.position.y;ball1_bbt.height = 2.0;ball1_bbt.width = 2.0;
    //floor
    for(int i=0;i<1000;i++)
    {
        x1 += 2.0;
        if(i%2)
        {
            flr[i] = Floor(x1 , -2.95, COLOR_GREEN);
            flr[i+1000] = Floor(x1 , -1.95, COLOR_DARKGREEN);
            flr[i+2000] = Floor(x1,11.5,COLOR_GREEN);
        }
        else
        {
            flr[i] = Floor(x1 , -2.95, COLOR_DARKGREEN);
            flr[i+1000] = Floor(x1 , -1.95, COLOR_GREEN);
            flr[i+2000] = Floor(x1,11.5,COLOR_DARKGREEN);
        }
    }
    //coin
    for(int i=0;i<50;i++)
    {
        float x = ((float)(rand()%1000));
        float y = ((float)(rand()%25))/10.0;
        bounding_box_t temp;
        cn.push_back(Coin((float)i*20.0 + 0.0f+0.0f,y + 0.0f, COLOR_GOLD)); 
        temp.x = cn[cn.size()-1].position.x;temp.y = cn[cn.size()-1].position.y;temp.height = 0.2f;temp.width = 0.2f;
        coin_bbt.push_back(temp);
        
        cn.push_back(Coin((float)i*20.0 + 0.0f+0.5f,y + 0.0f, COLOR_SILVER)); 
        temp.x = cn[cn.size()-1].position.x;temp.y = cn[cn.size()-1].position.y;temp.height = 0.2f;temp.width = 0.2f;
        coin_bbt.push_back(temp);
        
        cn.push_back(Coin((float)i*20.0 + 0.0f+1.0f,y + 0.0f, COLOR_GOLD)); 
        temp.x = cn[cn.size()-1].position.x;temp.y = cn[cn.size()-1].position.y;temp.height = 0.2f;temp.width = 0.2f;
        coin_bbt.push_back(temp);
        
        cn.push_back(Coin((float)i*20.0 + 0.0f-0.5f,y + 0.0f, COLOR_SILVER)); 
        temp.x = cn[cn.size()-1].position.x;temp.y = cn[cn.size()-1].position.y;temp.height = 0.2f;temp.width = 0.2f;
        coin_bbt.push_back(temp);
        
        cn.push_back(Coin((float)i*20.0 + 0.0f-1.0f,y + 0.0f, COLOR_GOLD)); 
        temp.x = cn[cn.size()-1].position.x;temp.y = cn[cn.size()-1].position.y;temp.height = 0.2f;temp.width = 0.2f;
        coin_bbt.push_back(temp);
        
        cn.push_back(Coin((float)i*20.0 + 0.0f,y + 0.0f+0.5f, COLOR_SILVER)); 
        temp.x = cn[cn.size()-1].position.x;temp.y = cn[cn.size()-1].position.y;temp.height = 0.2f;temp.width = 0.2f;
        coin_bbt.push_back(temp);
        
        cn.push_back(Coin((float)i*20.0 + 0.0f,y + 0.0f+1.0f, COLOR_GOLD)); 
        temp.x = cn[cn.size()-1].position.x;temp.y = cn[cn.size()-1].position.y;temp.height = 0.2f;temp.width = 0.2f;
        coin_bbt.push_back(temp);
        
        cn.push_back(Coin((float)i*20.0 + 0.0f,y + 0.0f-0.5f, COLOR_SILVER)); 
        temp.x = cn[cn.size()-1].position.x;temp.y = cn[cn.size()-1].position.y;temp.height = 0.2f;temp.width = 0.2f;
        coin_bbt.push_back(temp);
        
        cn.push_back(Coin((float)i*20.0 + 0.0f,y + 0.0f-1.0f, COLOR_GOLD)); 
        temp.x = cn[cn.size()-1].position.x;temp.y = cn[cn.size()-1].position.y;temp.height = 0.2f;temp.width = 0.2f;
        coin_bbt.push_back(temp);
        x2 += 2.0;
    }
    //enemy1
    x2 = 0.0;
    for(int i=0;i<100;i++)
    {
        float x = 10.0*(float)i + 5.0;
        float y1 = ((float)(rand()%60))/10.0;
        float y2 = ((float)(rand()%40))/10.0;
        float y = y1 - y2;
        enemy1.push_back(Enemy1(x, y, COLOR_BLACK)); 
        bounding_box_t temp;
        temp.x = x;temp.y = y;temp.height = 0.6f;temp.width = 0.6f;
        enemy1_bbt.push_back(temp);
        temp.x = x+1.0f;temp.y = y+1.0f;temp.height = 0.6f;temp.width = 0.6f;
        enemy1_bbt.push_back(temp);
        temp.x = x+0.59f;temp.y = y+0.59f;temp.height = 0.1f;temp.width = 0.1f;
        enemy1_bbt.push_back(temp);
        x2 += 10.0;
    }
    //special element
    for(int i=0;i<10;i++)
    {
        int x = rand()%3;
        float y = (float)(rand()%7);
        special.push_back(Special((float)i*20.0f*(float)x+25.0,y,COLOR_BLACK,x));
        bounding_box_t temp;
        temp.x = (float)i*20.0f+14.0;
        temp.y = y;
        if(x == 0){
            temp.x += 0.125;
            temp.height = 0.7f;
            temp.width = 0.7f;
        }
        if(x == 1){
            temp.height = 4.0f;
            temp.width = 4.0f;
        }
        if(x == 2){
            temp.height = 3.5f;
            temp.width = 3.5f;
        }
        special_bbt.push_back(temp);
    }
    //boomerang
    for(int i=0;i<4;i++)
    {
        float y = (float)(rand()%3);
        boomer.push_back(Boomer((float)i*180.0f*y,y, COLOR_BROWN));
        bounding_box_t temp;
        temp.x = (float)i*100.0f;
        temp.y = y;
        temp.width = 1.0f;
        temp.height = 1.0f;
        boomer_bbt.push_back(temp);
    }
    magnet = Magnet(150.0f,3.0f, COLOR_BLACK);
    
    dragon = Dragon(350.0f,-2.0f, COLOR_RED);
    bounding_box_t temp;
    temp.x = dragon.position.x; temp.y = dragon.position.y + 1.0f; temp.height = 4.0f; temp.width = 2.0f;
    dragon_bbt.push_back(temp);
    temp.x = dragon.position.x-2.0; temp.y = dragon.position.y + 1.0f; temp.height = 2.0f; temp.width = 2.0f;
    dragon_bbt.push_back(temp);
    temp.x = dragon.position.x+2.5; temp.y = dragon.position.y; temp.height = 2.0f; temp.width = 3.0f;
    dragon_bbt.push_back(temp);

    for(int i=0;i<4;i++)score[i] = Score(0.75*(float)i+3.2f,4.5f,COLOR_RED);

    tunnel = Tunnel(100.0f,-1.5f, COLOR_BLACK, COLOR_BACKGROUND);
    tunnel_bbt.x = tunnel.position.x - 9.0;tunnel_bbt.y = tunnel.position.y;tunnel_bbt.width = 1.0f;tunnel_bbt.height = 1.0f;
    
    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");

    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}

void tick_input(GLFWwindow *window) {

    int left  = glfwGetKey(window, GLFW_KEY_LEFT);
    int right = glfwGetKey(window, GLFW_KEY_RIGHT);
    int up = glfwGetKey(window, GLFW_KEY_SPACE);
    // int zoomIn = glfwGetKey(window, GLFW_KEY_UP);
    // int zoomOut = glfwGetKey(window, GLFW_KEY_DOWN);
    int balloonsKey = glfwGetKey(window, GLFW_KEY_B);

    if(left) 
    {
        if(ball1.tunnel_flag)ball1.tunnel_timer += 1.0;
        else ball1.speed = speed-forcex;
    }
    else if(right)
    {
        if(ball1.tunnel_flag)ball1.tunnel_timer -= 1.0f;
        else ball1.speed = -1*speed+forcex;
    }
    else ball1.speed = forcex;

    if(up == 0 && ball1.position.y > lower_limit && !ball1.falling)
    {
        ball1.jumping = 0;
        ball1.falling = 1;
        ball1.falling_time = 0.0f;
    }
    if(up) 
    {
        ball1.jumping = 1;
        ball1.falling = 0;
        ball1.jumping_time = 0.00;
        int x = rand()%4;
        float y = (float)x/10.0;
        jet.push_back(Jet(ball1.position.x-y,ball1.position.y,COLOR_GOLD,COLOR_ORANGE));
    }
    if(balloonsKey)
    {
        if(balloon_flag == 1)
        {
            balloon_flag = 0;
            balloon.push_back(Balloon(ball1.position.x,ball1.position.y,COLOR_GRAY));
            bounding_box_t temp;
            temp.x = balloon[balloon.size()-1].position.x;
            temp.y = balloon[balloon.size()-1].position.y;
            temp.width = 0.6;
            temp.height = 0.6;
            balloon_bbt.push_back(temp);
        }

    }
}  

void tick_elements() {
    ball1.tick();
    ball1.sheild_time -= 1.0/60.0;
    ball1.magnet_time -= 1.0/60.0;
    if(ball1.sheild_time < 0.0)
    {
        ball1.sheild_time = 0.0;
        ball1.sheild = 0;
    }
    if(ball1.magnet_time < 0.0)
    {
        ball1.magnet_time = 0.0;
        ball1.magnet = 0;
    }
    camx = ball1.position.x;
    
    for(int i=0;i<boomer.size();i++)
        boomer[i].tick();

    for(int i=0;i<4;i++)
        score[i].position.x = ball1.position.x + 0.75*(double)i + 3.2f;
    
    for(int i=0;i<special.size();i++)
    {
        // cout<<ball1.position.y<<endl;
        if(special[i].occupied == 0)
        special[i].tick();
        else
        {
            // cout<<"occupied "<<special[i].occupied_time<<endl;
            special[i].occupied_time += 1.0/60.0;
            if(special[i].occupied_time >= 10.0f)
            {
                special.erase(special.begin()+i);
                break;
            }
            special[i].position.y = ball1.position.y;
            special[i].position.x = ball1.position.x;
            if(special[i].type == 0)special[i].position.x += 0.9;
        }
    }
    for(int i=0;i<laser.size();i++)
    {
        laser[i].tick(laser_timer);
        laser[i].position.x = ball1.position.x;
    }
    for(int i=0;i<cn.size();i++)
    {
        if(ball1.magnet == 1)
        {
            dist = pow(pow(ball1.position.y-cn[i].position.y,2) + pow(ball1.position.x-cn[i].position.x,2),0.5);
            if(dist <= 8.0){
                force = (0.0001257*6*80*80)/(dist*dist);
                forcex = force*((cn[i].position.x-ball1.position.x)/dist);
                forcey = force*((cn[i].position.y-ball1.position.y)/dist);
                cn[i].position.y -= forcey;
                cn[i].position.x -= forcex;
            }
        }
        // cn[i].tick();
    }
    // cout<<cn[0].position.x<<endl;
    for(int i=0;i<balloon.size();i++)
        balloon[i].tick();
    for(int i=0;i<jet.size();i++)
    {
        int x = rand()%10;
        int y = rand()%10;
        jet[i].tick((float)x/100.0, (float)y/100.0);
    }
    for(int i=0;i<blueballs.size();i++)
    {
        int x = rand()%5;
        int y = rand()%5;
        int flag;
        float flagy = 1.0f;
        if(ball1.position.x - dragon.position.x <= 10.0 && ball1.position.x - dragon.position.x >= -2.0)flag = -1;
        else if(ball1.position.x - dragon.position.x < -2.0 && ball1.position.x - dragon.position.x > -10.0)flag = 1;
        if(ball1.position.y > dragon.position.y)flagy = -1.0;
        blueballs[i].tick((float)flag*(float)x/10.0,flagy*(float)y/10.0);
    }

    if(!balloon_flag)
    {
        balloon_timer += 360.0/15000.0;
        if(balloon_timer >= 0.8)
        {
            balloon_timer = 0.0;
            balloon_flag = 1;
        }
    }

}


void checkJumping()
{
    if(ball1.jumping)
    {
        ball1.jumping_time += ((float)1/(float)60);
        float t = ball1.jumping_time;
        ball1.position.y += 0.1+(0.5)*t;
        if(ball1.position.y > upper_limit && !ball1.tunnel_flag)ball1.position.y = upper_limit;
    }
    else
    {
        if(ball1.position.y > -4.5f && !ball1.tunnel_flag)
        {
            ball1.falling_time += 1.0f/120.0f;
            float t = ball1.falling_time;
            ball1.position.y -= ((4.9)*t*t);
            if(ball1.position.y < lower_limit)ball1.position.y = lower_limit;
        }
    }
}

void checkMoving()
{
    if(ball1.speed > 0)
    {
        ball1.speed -= ((float)1/(float)60);
        if(ball1.speed < 0.00)ball1.speed = 0.00;
    }
    if(ball1.speed < 0)
    {
        ball1.speed += ((float)1/(float)60);
        if(ball1.speed > 0.00)ball1.speed = 0.00;
    }

    for(int i=0;i<laser.size();i++)
    {
        laser[i].position.y += laser[i].flag*0.03;
        if(laser[i].position.y - laser[i].y > 2.5)laser[i].flag = -1.0;
        if(laser[i].position.y - laser[i].y < 0)laser[i].flag =  1.0;
        
    }

}

void moving_bbt()
{
    ball1_bbt.x = ball1.position.x;
    ball1_bbt.y = ball1.position.y;
    for(int i=0;i<special_bbt.size();i++)
    {
        special_bbt[i].x = special[i].position.x;
        special_bbt[i].y = special[i].position.y;
    }
    for(int i=0;i<coin_bbt.size();i++)
    {
        coin_bbt[i].x = cn[i].position.x;
        coin_bbt[i].y = cn[i].position.y;
    }

    for(int i=0;i<boomer.size();i++)
    {
        boomer_bbt[i].x = boomer[i].position.x;
        boomer_bbt[i].y = boomer[i].position.y;
    }
    for(int i=0;i<balloon_bbt.size();i++)
    {
        balloon_bbt[i].x = balloon[i].position.x;
        balloon_bbt[i].y = balloon[i].position.y;
    }
    for(int i=0;i<blueballs_bbt.size();i++)
    {
        blueballs_bbt[i].x = blueballs[i].position.x;
        blueballs_bbt[i].y = blueballs[i].position.y;
    }
    for(int i=0;i<laser_bbt.size();i++)
    {
        laser_bbt[i].x = laser[i].position.x;
        laser_bbt[i].y = laser[i].position.y;
    }
}

void collisions()
{
    /* ball - coin */   
    for(int i=0;i<cn.size();i++)
    {
        if(detect_collision(ball1_bbt,coin_bbt[i]))
        {
            // cout<<"Coins 1\n";
            player_score++;
            cn.erase(cn.begin()+i);
            coin_bbt.erase(coin_bbt.begin()+i);
        }
    }
    /* ball - laser */
    for(int i=0;i<laser.size();i++)
    {
        if(laser_start == 1 && !ball1.tunnel_flag && ball1.sheild == 0)
        {
            if(detect_collision(ball1_bbt,laser_bbt[i]))
            {
                lives--;
                cout<<lives<<endl;
                ball1.position.x -= 4.0f;
                ball1.position.y -= 4.0f;
                if(ball1.position.x < 0.0)ball1.position.x = 0.0;
                if(ball1.position.y < -4.5)ball1.position.y = -4.5;
                player_score -= 30;
                if(player_score < 0)player_score = 0;

                // cout<<"Fire Beams"<<endl;
            }
        }
    }
     
    /* ball - enemy1 */
    for(int i=0;i<enemy1_bbt.size();i++)
    {
        if(detect_collision(ball1_bbt,enemy1_bbt[i]) && !ball1.tunnel_flag && ball1.sheild == 0)
        {
            lives--;
            cout<<lives<<endl;
            ball1.position.x -= 4.0f;
            ball1.position.y -= 4.0f;
            if(ball1.position.x < 0.0)ball1.position.x = 0.0;
            if(ball1.position.y < -4.5)ball1.position.y = -4.5;
            player_score -= 20;
            if(player_score < 0)player_score = 0;
        }
    }

    for(int i=0;i<balloon_bbt.size();i++)
    {
        int flag = 0;
        for(int j=0;j<enemy1_bbt.size();j++)
        {
            if(detect_collision(balloon_bbt[i],enemy1_bbt[j]))
            {
                player_score += 20;
                balloon.erase(balloon.begin()+i);
                balloon_bbt.erase(balloon_bbt.begin()+i);
                enemy1.erase(enemy1.begin()+(j/3));
                if(j%3 == 0)
                {
                    enemy1_bbt.erase(enemy1_bbt.begin()+j);
                    enemy1_bbt.erase(enemy1_bbt.begin()+j);
                    enemy1_bbt.erase(enemy1_bbt.begin()+j);
                
                }
                else if(j%3 == 1)
                {
                    enemy1_bbt.erase(enemy1_bbt.begin()+j-1);
                    enemy1_bbt.erase(enemy1_bbt.begin()+j-1);
                    enemy1_bbt.erase(enemy1_bbt.begin()+j-1);
                }
                else if(j%3 == 2)
                {
                    enemy1_bbt.erase(enemy1_bbt.begin()+j-2);
                    enemy1_bbt.erase(enemy1_bbt.begin()+j-2);
                    enemy1_bbt.erase(enemy1_bbt.begin()+j-2);
                }
                flag = 1;
                break;
            }
        }
        if(flag = 1)break;
    }

    for(int i=0;i<balloon_bbt.size();i++)
    {
        int flag = 0;
        for(int j=0;j<laser_bbt.size();j++)
        {
            if(detect_collision(balloon_bbt[i],laser_bbt[j]))
            {
                player_score += 30;
                balloon.erase(balloon.begin()+i);
                balloon_bbt.erase(balloon_bbt.begin()+i);
                laser.erase(laser.begin()+j);
                laser_bbt.erase(laser_bbt.begin()+j);
                flag = 1;
                break;
            }
        }
        if(flag = 1)break;
    }
    for(int i=0;i<balloon_bbt.size();i++)
    {
        int flag = 0;
        for(int j=0;j<boomer_bbt.size();j++)
        {
            if(detect_collision(balloon_bbt[i],boomer_bbt[j]))
            {
                lives--;
                cout<<lives<<endl;
                ball1.position.x -= 4.0f;
                ball1.position.y -= 4.0f;
                if(ball1.position.x < 0.0)ball1.position.x = 0.0;
                if(ball1.position.y < -4.5)ball1.position.y = -4.5;
                player_score += 50;
                balloon.erase(balloon.begin()+i);
                balloon_bbt.erase(balloon_bbt.begin()+i);
                boomer.erase(boomer.begin()+j);
                boomer_bbt.erase(boomer_bbt.begin()+j);
                flag = 1;
                break;
            }
        }
        if(flag = 1)break;
    }

    for(int i=0;i<blueballs_bbt.size();i++)
    {
        if(detect_collision(blueballs_bbt[i],ball1_bbt) && !ball1.tunnel_flag && ball1.sheild == 0 && abs(ball1.position.x - blueballs[i].position.x) <= 2.0 )
        {
            lives-=0.01;
            cout<<lives<<endl;
            // ball1.position.x -= 2.0f;
            // ball1.position.y -= 2.0f;
            // if(ball1.position.x < 0.0)ball1.position.x = 0.0;
            // if(ball1.position.y < -4.5)ball1.position.y = -4.5;
            player_score -= 1;
            if(player_score < 0)player_score = 0;
            // cout<<"Cene mein jalan\n";
        }
    }

    /* ball - special object */
    for(int i=0;i<special_bbt.size();i++)
    {
        if(detect_collision(ball1_bbt,special_bbt[i]))
        {
            if(special[i].type == 0 && special[i].occupied == 0 && ball1.magnet == 0){
                ball1.magnet = 1;
                ball1.magnet_time += 10.0f;
                special[i].position.x = ball1.position.x+1.9;
                special[i].position.y = ball1.position.y;
                special[i].occupied = 1;
            }
            if(special[i].type == 1){
                player_score += 100;
                special.erase(special.begin()+i);
                special_bbt.erase(special_bbt.begin()+i);
                break;
            }
            if(special[i].type == 2 && special[i].occupied == 0 && ball1.sheild == 0){
                ball1.sheild = 1;
                ball1.sheild_time += 10.0f;
                special[i].position.x = ball1.position.x;
                special[i].position.y = ball1.position.y;
                special[i].occupied = 1;
            }
            // cout<<special[i].type<<" collision with special object"<<endl;
        }
        int flag =0;
        for(int j=0;j<enemy1_bbt.size();j++)
        {
            if(detect_collision(special_bbt[i],enemy1_bbt[j]) && special[i].occupied == 1 && special[i].type == 2)
            {
                player_score += 20;
                enemy1.erase(enemy1.begin()+j/3);
                if(j%3 == 0)
                {
                    enemy1_bbt.erase(enemy1_bbt.begin()+j);
                    enemy1_bbt.erase(enemy1_bbt.begin()+j);
                    enemy1_bbt.erase(enemy1_bbt.begin()+j);
                
                }
                else if(j%3 == 1)
                {
                    enemy1_bbt.erase(enemy1_bbt.begin()+j-1);
                    enemy1_bbt.erase(enemy1_bbt.begin()+j-1);
                    enemy1_bbt.erase(enemy1_bbt.begin()+j-1);
                }
                else if(j%3 == 2)
                {
                    enemy1_bbt.erase(enemy1_bbt.begin()+j-2);
                    enemy1_bbt.erase(enemy1_bbt.begin()+j-2);
                    enemy1_bbt.erase(enemy1_bbt.begin()+j-2);
                }
                flag = 1;
                break;
            }
        }
        if(flag == 1)break;
        flag = 0;
        for(int j=0;j<laser_bbt.size();j++)
        {
            if(detect_collision(laser_bbt[j],special_bbt[i]) && special[i].occupied == 1)
            {
                player_score += 30;
                laser.erase(laser.begin()+j);
                laser_bbt.erase(laser_bbt.begin()+j);
                flag = 1;
                break;
            }
        }
        if(flag == 1)break;
        flag = 0;
        for(int j=0;j<boomer_bbt.size();j++)
        {
            if(detect_collision(boomer_bbt[j],special_bbt[i]) && special[i].occupied == 1)
            {
                player_score += 50;
                boomer.erase(boomer.begin()+j);
                boomer_bbt.erase(boomer_bbt.begin()+j);
                flag = 1;
                break;
            }
        }
        if(flag == 1)break;

    }
    /* ball - boomerang */
    for(int i=0;i<boomer.size();i++)
    {
        if(detect_collision(ball1_bbt,boomer_bbt[i]))
        {
            player_score -= 10;
            if(player_score < 0)player_score = 0;
        }
    }

    if(detect_collision(ball1_bbt,tunnel_bbt))
    {
        ball1.tunnel_flag = 1;
        ball1.tunnel_position_x = tunnel.position.x;
        ball1.tunnel_position_y = tunnel.position.y;
        // cout<<"Udi Udi jae Udi Udi jae\n";
    }
}
void magnetic_force()
{
    dist = pow(pow(ball1.position.y-magnet.position.y,2) + pow(ball1.position.x-magnet.position.x,2),0.5);
    force = (0.000001257*80*80)/(dist*dist);
    forcex = -1*force*((magnet.position.x-ball1.position.x)/dist);
    forcey = force*((magnet.position.y-ball1.position.y)/dist);
    ball1.position.y += forcey;
    if(ball1.position.y > upper_limit && ball1.tunnel_flag == 0)ball1.position.y = upper_limit;
    if(ball1.position.y < lower_limit)ball1.position.y = lower_limit;
    // cout<<force<<" "<<forcex<<" "<<forcey<<endl;
}

void dragon_fire()
{
    int x = rand()%15000;
    int y = rand()%15000;
    float r = rand()%20;
    int z1 = rand()%2;int z2 = rand()%2;int z3 = rand()%2;int z4 = rand()%2;int z5 = rand()%2;
    r = 0.1;
    if(abs(ball1.position.x - dragon.position.x) <= 10.0f && x == y)
    {
        bounding_box_t temp;temp.x = dragon.position.x - 4.0f;temp.y = dragon.position.y + 0.5f;temp.height = 10.0*r;temp.width = 10.0*r;
        blueballs_bbt.push_back(temp);
        temp.x = dragon.position.x - 3.8f;temp.y = dragon.position.y + 0.6f;temp.height = 8.0*r;temp.width = 8.0*r;
        blueballs_bbt.push_back(temp);
        temp.x = dragon.position.x - 3.6f;temp.y = dragon.position.y + 0.7f;temp.height = 6.0*r;temp.width = 6.0*r;
        blueballs_bbt.push_back(temp);
        temp.x = dragon.position.x - 3.4f;temp.y = dragon.position.y + 0.8f;temp.height = 4.0*r;temp.width = 4.0*r;
        blueballs_bbt.push_back(temp);
        temp.x = dragon.position.x - 3.2f;temp.y = dragon.position.y + 0.9f;temp.height = 2.0*r;temp.width = 2.0*r;
        blueballs_bbt.push_back(temp);
        if(z1 == 0)blueballs.push_back(Blueballs(dragon.position.x - 4.0f, dragon.position.y + 0.5f, COLOR_DARKBLUE, 5.0*r));
        else blueballs.push_back(Blueballs(dragon.position.x - 4.0f, dragon.position.y + 0.5f, COLOR_WHITE, 5.0*r));
        if(z2 == 0)blueballs.push_back(Blueballs(dragon.position.x - 3.8f, dragon.position.y + 0.6f, COLOR_DARKBLUE, 4.0*r));
        else blueballs.push_back(Blueballs(dragon.position.x - 4.0f, dragon.position.y + 0.6f, COLOR_WHITE, 5.0*r));
        if(z3 == 0)blueballs.push_back(Blueballs(dragon.position.x - 3.6f, dragon.position.y + 0.7f, COLOR_DARKBLUE, 3.0*r));
        else blueballs.push_back(Blueballs(dragon.position.x - 4.0f, dragon.position.y + 0.7f, COLOR_WHITE, 5.0*r));
        if(z4 == 0)blueballs.push_back(Blueballs(dragon.position.x - 3.4f, dragon.position.y + 0.8f, COLOR_DARKBLUE, 2.0*r));
        else blueballs.push_back(Blueballs(dragon.position.x - 4.0f, dragon.position.y + 0.8f, COLOR_WHITE, 5.0*r));
        if(z5 == 0)blueballs.push_back(Blueballs(dragon.position.x - 3.2f, dragon.position.y + 0.9f, COLOR_DARKBLUE, 1.0*r));
        else blueballs.push_back(Blueballs(dragon.position.x - 4.0f, dragon.position.y + 0.9f, COLOR_WHITE, 5.0*r));
    }
}

void laser_render()
{
    if(laser.size() == 0)laser_start = 0;
    int x = rand()%80000;
    int y = rand()%80000;
    if(2*x == y && laser_start == 0)
    {
        laser_start = 1;
        laser_timer = 0.0f;
        laser.push_back(Laser(0.0f, 0.0f, COLOR_RED,COLOR_ORANGE));
        laser.push_back(Laser(0.0f, 2.5f, COLOR_RED,COLOR_ORANGE));
        bounding_box_t temp;
        temp.x = 0.0f;temp.y = 0.0f;temp.height = 0.1f;temp.width = 10.0f;laser_bbt.push_back(temp);
        temp.x = 0.0f;temp.y = 2.5f;temp.height = 0.1f;temp.width = 10.0f;laser_bbt.push_back(temp);

    }
}



int main(int argc, char **argv) 
{
    srand(time(0));
    int width = 800,height = 800;
    // cout<<"Enter width and height: ";
    // cin>>width>>height;
    camx = 0;camy = 0;speed = 0.2f;balloon_timer = 2.0f;balloon_flag = 1;
    window = initGLFW(width, height);
    initGL (window, width, height);
    laser_start = 0;
    lower_limit = -4.0;
    upper_limit = 7.0;
    lives = 5.0;
    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) 
    {
        // Process timers
        // int l = rand()%30000;
        // if(ball1.position.x > 10.0 && l == 3333)
        // {
        //     generator();
        // }
        if(lives <= 0)
        {
            cout<<"game end"<<endl;
            exit(0);
        }
        magnetic_force();
        dragon_fire();
        laser_render();
        if (t60.processTick()) 
        {
            speed += 0.00005;
            if(speed > 5.0) speed = 5.0;
            speedy += 0.00005;
            if(speedy > 3.0) speedy = 3.0;
            // cout<<speed<<" "<<speedy<<endl;
            if(ball1.position.x - magnet.position.x > 100.0)magnet.position.x += 300.0f;
            // 60 fps
            // OpenGL Draw commands
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);
            
            tick_input(window);
            tick_elements();
            moving_bbt();
            collisions();
            checkJumping();
            checkMoving();
            reset_screen();            
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

bool detect_collision(bounding_box_t a, bounding_box_t b) 
{
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) && (abs(a.y - b.y) * 2 < (a.height + b.height));
}
bool detect_collision1(bounding_box_t a, bounding_box_t b) 
{
    return (abs(a.x - b.x) * 2 < 3.0 + (a.width + b.width)) && (abs(a.y - b.y) * 2 < 3.0 + (a.height + b.height));
}
void reset_screen() {
    if(screen_zoom > 1.0)
    {
        screen_center_y = ball1.position.y;
    }
    for(int i=0;i<4;i++)
    {
        score[i].position.x = ball1.position.x + 0.75*(float)i+right1 - 4.0f; 
        score[i].position.y = top - 1.5f; 
        
    }
    top    = screen_center_y + 8 / screen_zoom;
    bottom = screen_center_y - 8 / screen_zoom;
    left1   = screen_center_x - 8 / screen_zoom;
    right1  = screen_center_x + 8 / screen_zoom;
    Matrices.projection = glm::ortho(left1, right1, bottom, top, 0.1f, 500.0f);
}
