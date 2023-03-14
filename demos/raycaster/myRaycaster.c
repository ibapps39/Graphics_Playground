#include "myRaycaster.h"

void init_raycaster(GLFWwindow* window) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //view angle, aspect ratio, near and far clipping distance
    gluPerspective(60.0f, ASPECT, .1f, 100.0f);
    // sets up model (world) and view (camera) -> modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    Player player = {
        .x          = 2.0f,
        .y          = 2.0f,
        .direction  = 0.0f,
    };

    glfwSetKeyCallback(window, handle_keys);
    //ref ensures that the player is alive as long as the window vs seperately allocating and freeing
    glfwSetWindowUserPointer(window, &player);
}

int main() {
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(
        SCREEN_WIDTH, 
        SCREEN_HEIGHT, 
        SCREEN_TITLE, 
        NULL, 
        NULL
        );
    
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    init_raycaster(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }


    glfwDestroyWindow(window);
    glfwTerminate();
    exit(0);
}