#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include<math.h>
//#include <GL/glut.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(void)
{
    GLFWwindow* window;

    // Initialize GLFW library
    if (!glfwInit())
    {
        return -1;
    }

    // Create a window
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "5 SIDE SHAPED POLYGON", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT); // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
    glMatrixMode(GL_PROJECTION); // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
    glLoadIdentity(); // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1); // essentially set coordinate system
    glMatrixMode(GL_MODELVIEW); // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
    glLoadIdentity(); // same as above comment

    GLfloat polygonVertices[] =
    {
        100, 100, 0,//A
        100, 300, 0,//B
        40, 300, 0,//C
        40, 320, 0,//D
        500, 320, 0,//E
        500, 300, 0,//F
        440, 300, 0,//G
        440, 100, 0,//H

    };

    GLfloat door[] =
    {
        250, 120, 0,//A(door)
        250, 220, 0, //B(door)
        310, 220, 0,//C(door) 
        310, 120, 0,//D(door)
    };

    GLfloat left_window[] =//Left Window Pane
    {
        120, 180, 0,//A
        120, 220, 0,//B
        160, 220, 0,//C
        160, 180, 0,//D
    };

    GLfloat right_window[] =//Right Window Pane
    {
        380, 180, 0,//A
        380, 220, 0,//B
        420, 220, 0,//C
        420, 180, 0,//D
    };

    //Vertical window frame For Window Pane on the Left
    GLfloat left_window_vertical[] =
    {
        140, 180, 0,
        140, 220, 0
    };

    //Horizonatl Window frame For Window Pane on the Left
    GLfloat left_window_horizontal[] =
    {
        120, 200, 0,
        160, 200, 0
    };

    //Vertical Window frame For Window Pane on the Right

    GLfloat right_window_vertical[] =
    {
        400, 180, 0,
        400, 220, 0
    };

    //Horizontal Window frame For Window Pane on the Right

    GLfloat right_window_horizontal[] =
    {
        380, 200, 0,
        420, 200, 0
    };

    //.................................................................................................................................................................................
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // polygon drawing mode (GL_POINT, GL_LINE, GL_FILL)


    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        // render OpenGL here
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, polygonVertices);
        glDrawArrays(GL_POLYGON, 0, 8);
        glDisableClientState(GL_VERTEX_ARRAY);

        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, door);
        glDrawArrays(GL_POLYGON, 0, 4);
        glDisableClientState(GL_VERTEX_ARRAY);

        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, left_window);
        glDrawArrays(GL_POLYGON, 0, 4);
        glDisableClientState(GL_VERTEX_ARRAY);

        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, right_window);
        glDrawArrays(GL_POLYGON, 0, 4);
        glDisableClientState(GL_VERTEX_ARRAY);


        glEnable(GL_LINE_SMOOTH);
        glPushAttrib(GL_LINE_BIT);
        glLineWidth(3);
        glLineStipple(1, 0x00FF);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, left_window_vertical);
        glDrawArrays(GL_LINES, 0, 2);
        glDisableClientState(GL_VERTEX_ARRAY);
        glPopAttrib();
        glDisable(GL_LINE_STIPPLE);
        glDisable(GL_LINE_SMOOTH);

        glEnable(GL_LINE_SMOOTH);
        glPushAttrib(GL_LINE_BIT);
        glLineWidth(3);
        glLineStipple(1, 0x00FF);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, left_window_horizontal); 
        glDrawArrays(GL_LINES, 0, 2);
        glDisableClientState(GL_VERTEX_ARRAY);
        glPopAttrib();
        glDisable(GL_LINE_STIPPLE);
        glDisable(GL_LINE_SMOOTH);

        glEnable(GL_LINE_SMOOTH);
        glPushAttrib(GL_LINE_BIT);
        glLineWidth(3);
        glLineStipple(1, 0x00FF);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, right_window_vertical); 
        glDrawArrays(GL_LINES, 0, 2);
        glDisableClientState(GL_VERTEX_ARRAY);
        glPopAttrib();
        glDisable(GL_LINE_STIPPLE);
        glDisable(GL_LINE_SMOOTH);

        glEnable(GL_LINE_SMOOTH);
        glPushAttrib(GL_LINE_BIT);
        glLineWidth(3);
        glLineStipple(1, 0x00FF);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, right_window_horizontal); 
        glDrawArrays(GL_LINES, 0, 2);
        glDisableClientState(GL_VERTEX_ARRAY);
        glPopAttrib();
        glDisable(GL_LINE_STIPPLE);
        glDisable(GL_LINE_SMOOTH);

        drawCircle(320, 300, 160, 360);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}