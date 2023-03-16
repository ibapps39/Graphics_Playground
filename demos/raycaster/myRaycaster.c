#include "myRaycaster.h"


void drawPlayer()
{
    glColor3f(1,1,0);
    glPointSize(20);
    glLineWidth(4);
    glBegin(GL_POINTS);
    glVertex2i(playerX,playerY);
    glEnd();
}

void init()
{
    //background
    glClearColor(0.3,0.3,0.3,0);
    glOrtho(0,SCREEN_WIDTH,SCREEN_HEIGHT,0,-1,1);
    playerX=300;
    playerY=300;
}

void display(GLFWwindow* window)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawPlayer();
    glfwSwapBuffers(window);
}

int main()
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE, NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    init(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        display(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
