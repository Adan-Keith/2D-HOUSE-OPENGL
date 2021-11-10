#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>

#include<stdlib.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 640

void drawRoof(GLfloat x, GLfloat y, GLfloat radius, GLint numberOfSides);
void doorKnob(float cx, float cy, float r, int num_segments);


void moon(float cx, float cy, float r, int num_segments);
void moon2(float cx, float cy, float r, int num_segments);
int main(void)
{
    GLFWwindow* window;

    // Initialize the library
    if (!glfwInit())
    {
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "5 Vertice Polygon", NULL, NULL); // "Polygon" is title of window

    if (!window)
    {
        glfwTerminate();
        return -1;
    }


    glfwMakeContextCurrent(window);

    glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    GLfloat house[] =
    {
        180, 240, 0,// 1 
        140, 240, 0,// 2
        140, 300, 0,// 3
        500, 300, 0,// 4
        500, 240, 0,// 5
        460, 240, 0,// 6
        460, 120, 0,// 7
        180, 120, 0,// 8
    };

    GLfloat door[] =
    {
        280, 120, 0,
        280, 220, 0,
        360, 220, 0,
        360, 120, 0,
    };

    GLfloat windowLeft[] =
    {
        220, 180, 0,
        220, 220, 0,
        260, 220, 0,
        260, 180, 0,
    };

    GLfloat windowRight[] =
    {
        380, 180, 0,
        380, 220, 0,
        420, 220, 0,
        420, 180, 0,
    };

    GLfloat line1_left[] =
    {
        240, 180, 0,
        240, 220, 0
    };

    GLfloat line2_left[] =
    {
        220, 200, 0,
        260, 200, 0
    };

    GLfloat line1_right[] =
    {
        400, 180, 0,
        400, 220, 0
    };

    GLfloat line2_right[] =
    {
        380, 200, 0,
        420, 200, 0
    };




    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    GLfloat colour[] = {
        255, 0, 0,
        0, 201, 0,
        0, 0, 0

    };

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);


        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, house);
        glDrawArrays(GL_POLYGON, 0, 8);
        glDisableClientState(GL_VERTEX_ARRAY);





        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, door);

        glDrawArrays(GL_POLYGON, 0, 4);
        glDisableClientState(GL_COLOR_ARRAY);
        glDisableClientState(GL_VERTEX_ARRAY);


        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, windowLeft);
        glDrawArrays(GL_POLYGON, 0, 4);
        glDisableClientState(GL_VERTEX_ARRAY);


        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, windowRight);


        glDrawArrays(GL_POLYGON, 0, 4);

        glDisableClientState(GL_VERTEX_ARRAY);


        glEnable(GL_LINE_SMOOTH);
        glEnableClientState(GL_COLOR_ARRAY);
        glColorPointer(3, GL_FLOAT, 0, colour);
        glPushAttrib(GL_LINE_BIT);
        glLineWidth(3);
        glLineStipple(1, 0x00FF);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, line1_left);
        glDrawArrays(GL_LINES, 0, 2);
        glDisableClientState(GL_COLOR_ARRAY);
        glDisableClientState(GL_VERTEX_ARRAY);

        glPopAttrib();
        glDisable(GL_LINE_STIPPLE);
        glDisable(GL_LINE_SMOOTH);


        glEnable(GL_LINE_SMOOTH);
        glEnableClientState(GL_COLOR_ARRAY);
        glColorPointer(2, GL_FLOAT, 0, colour);
        glPushAttrib(GL_LINE_BIT);
        glLineWidth(3);
        glLineStipple(1, 0x00FF);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, line2_left);
        glDrawArrays(GL_LINES, 0, 2);
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);
        glPopAttrib();
        glDisable(GL_LINE_STIPPLE);
        glDisable(GL_LINE_SMOOTH);


        glEnable(GL_LINE_SMOOTH);
        glEnableClientState(GL_COLOR_ARRAY);
        glColorPointer(2, GL_FLOAT, 0, colour);
        glPushAttrib(GL_LINE_BIT);
        glLineWidth(3);
        glLineStipple(1, 0x00FF);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, line1_right);
        glDrawArrays(GL_LINES, 0, 2);
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);
        glPopAttrib();
        glDisable(GL_LINE_STIPPLE);
        glDisable(GL_LINE_SMOOTH);


        glEnable(GL_LINE_SMOOTH);

        glPushAttrib(GL_LINE_BIT);
        glLineWidth(3);
        glLineStipple(1, 0x00FF);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, line2_right);
        glDrawArrays(GL_LINES, 0, 2);
        glDisableClientState(GL_VERTEX_ARRAY);
        glPopAttrib();
        glDisable(GL_LINE_STIPPLE);
        glDisable(GL_LINE_SMOOTH);



        drawRoof(320, 300, 120, 250);
        doorKnob(350, 170, 5, 250); 


        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glLineWidth(5);
        // movement on x axis, movement on y axis , radius, sides
        glColor3f(0.8f, 0.6f, 0.2f); //Golden
        glLineWidth(5);
        moon(630, 460, 60, 1000);// movement on x axis, movement on y axis , radius, sides 


        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glColor3f(0.8f, 0.6f, 0.2f); //Golden

        //glColor3f(0.0f, 0.0f, 0.0f); //black
        moon2(650, 460, 60, 100);
        glColor3f(1.0f, 1.0f, 1.0f);

        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        glfwSwapBuffers(window);
        glColor3f(1.0f, 1.0f, 1.0f);

        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}

void moon2(float cx, float cy, float r, int num_segments)

{


    float theta = 3.14159265358979323846264338327950288 * 2 / float(num_segments);
    float tangetial_factor = tanf(theta);

    float radial_factor = cosf(theta);

    float x = r;

    float y = 0;

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; i++)
    {
        glVertex2f(x + cx, y + cy);



        float tx = -y;
        float ty = x;



        x += tx * tangetial_factor;
        y += ty * tangetial_factor;



        x *= radial_factor;
        y *= radial_factor;
    }
    glEnd();
}
void moon(float cx, float cy, float r, int num_segments)
{
    int R = 255;
    int G = 201;
    int B = 0;



    float theta = 3.14159265358979323846264338327950288 * 2 / float(num_segments);
    float tangetial_factor = tanf(theta);

    float radial_factor = cosf(theta);

    float x = r;

    float y = 0;

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; i++)
    {
        glVertex2f(x + cx, y + cy);



        float tx = -y;
        float ty = x;



        x += tx * tangetial_factor;
        y += ty * tangetial_factor;



        x *= radial_factor;
        y *= radial_factor;

    }
   
    glEnd();
}
void doorKnob(float cx, float cy, float r, int num_segments)
{
    float theta = 3.1415926 * 2 / float(num_segments);
    float tangetial_factor = tanf(theta);

    float radial_factor = cosf(theta);

    float x = r;

    float y = 0;

    glBegin(GL_LINE_LOOP);
    for (int ii = 0; ii < num_segments; ii++)
    {
        glVertex2f(x + cx, y + cy);



        float tx = -y;
        float ty = x;



        x += tx * tangetial_factor;
        y += ty * tangetial_factor;



        x *= radial_factor;
        y *= radial_factor;
    }
    glEnd();
}

void drawRoof(float cx, float cy, float r, int num_segments)
{
    float theta = 3.1415926 / float(num_segments);
    float tangetial_factor = tanf(theta);//calculate the tangential factor 

    float radial_factor = cosf(theta);//calculate the radial factor =

    float x = r;//we start at angle = 0 

    float y = 0;

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; i++)
    {
        glVertex2f(x + cx, y + cy);//output vertex 



        float tx = -y;
        float ty = x;



        x += tx * tangetial_factor;
        y += ty * tangetial_factor;



        x *= radial_factor;
        y *= radial_factor;
    }
    glEnd();
}