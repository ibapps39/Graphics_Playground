#include "myRaycaster.h"

int map[] = {
    1,1,1,1,1,1,1,1, 
    1,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1
};


/*
Setup the lib and init
Setup window and context, setting the current context to the window initiated
Use glClearColor to set the color of the background and glOrtho to setup coordinate system
Init player position
Define player color, pixels used, and pixel line size, then draw shape with glVertex and pass player position
Setup key input and manipulating the player
*/

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    if (key == GLFW_KEY_W && (action == GLFW_PRESS || action == GLFW_REPEAT))
    {
        playerX += playerDx;
        playerY += playerDy;
    }
    else if (key == GLFW_KEY_A && (action == GLFW_PRESS || action == GLFW_REPEAT))
    {
        playerAngle -= 0.1;
        if (playerAngle < 0) {playerAngle += 2*M_PI;}
        playerDx = cos(playerAngle)*PLAYER_DIRECTIONAL_ANGLE_SCALER;
        playerDy = sin(playerAngle)*PLAYER_DIRECTIONAL_ANGLE_SCALER;
    }
    else if (key == GLFW_KEY_S && (action == GLFW_PRESS || action == GLFW_REPEAT))
    {
        playerX -= playerDx;
        playerY -= playerDy;
    }
    else if (key == GLFW_KEY_D && (action == GLFW_PRESS || action == GLFW_REPEAT))
    {
        playerAngle += 0.1;
        if (playerAngle > 2*M_PI) {playerAngle -= 2*M_PI;}
        playerDx = cos(playerAngle)*PLAYER_DIRECTIONAL_ANGLE_SCALER;
        playerDy = sin(playerAngle)*PLAYER_DIRECTIONAL_ANGLE_SCALER;
    }
    //glfwSwapInterval(1);
}

// This function is responsible for drawing the map using OpenGL.
// It iterates through each cell in the 2D map and draws either a white or a black rectangle
// based on the cell value (1 for white, 0 for black).
void drawMap()
{
    int x, y;
    int scaledX, scaledY;
    //see additionalDoc.md
    int linearIndex;

    // Iterate through each row (y-axis) of the map
    for (y = 0; y < MAP_HEIGHT; y++)
    {
        // Iterate through each column (x-axis) of the map
        for (x = 0; x < MAP_LENGTH; x++)
        {
            // Convert 2D coordinates to a 1D index
            // Set the color for the current cell based on its value in the map array
            // If the value is 1, set the color to white (1, 1, 1); otherwise, set it to black (0, 0, 0)
            linearIndex = y * MAP_HEIGHT + x;
            map[linearIndex] == 1 ? glColor3f(1, 1, 1) : glColor3f(0, 0, 0);

            // Calculate the scaled screen coordinates for the current cell
            scaledX = x * MAP_AREA;
            scaledY = y * MAP_AREA;

            // Draw a rectangle (quad) for the current cell using the scaled screen coordinates
            glBegin(GL_QUADS);
                glVertex2i(scaledX + 1, scaledY + 1);                            // Top-left vertex
                glVertex2i(scaledX + 1, scaledY + MAP_AREA - 1);                // Bottom-left vertex
                glVertex2i(scaledX + MAP_AREA - 1, scaledY + MAP_AREA - 1);     // Bottom-right vertex
                glVertex2i(scaledX + MAP_AREA - 1, scaledY + 1);                // Top-right vertex
            glEnd();
        }
    }
} 

void drawPlayer()
{
    glColor3f(1,1,0);
    glPointSize(8);
    glLineWidth(4);
    glBegin(GL_POINTS);
    glVertex2i(playerX,playerY);
    glEnd();
}

void drawPlayerDirection() {
    glColor3f(1,1,0);
    glPointSize(8);
    glLineWidth(3);
    glBegin(GL_LINES);
        glVertex2i(playerX,playerY);
        glVertex2i(
            playerX+playerDx*PLAYER_DIRECTIONAL_ANGLE_SCALER,
            playerY+playerDy*PLAYER_DIRECTIONAL_ANGLE_SCALER
            );
    glEnd();
}

//init the background color, the screen dimensions, and the player position
void init()
{
    //background
    glClearColor(0.3,0.3,0.3,0);
    glOrtho(0,SCREEN_WIDTH,SCREEN_HEIGHT,0,-1,1);
    playerX=300;
    playerY=300;
}

void drawRays()
{
    int mapTileX, mapTileY, mapIndex, depthOfField;
    float rayAngle, rayLengthX, rayHeightY, offsetX, offsetY;
    rayAngle = playerAngle;

    depthOfField = 0;
    float slope = -1/tan(rayAngle);
    // Check the horizontal lines, up/down
    // If the player is looking up
    if (rayAngle > M_PI)
    {
        rayHeightY = (((int)playerY >> 6) << 6) - RAY_ACCURACY_ERROR;
        rayLengthX = (playerY-rayHeightY)*slope+playerX;
        offsetY = -MAP_AREA;
        offsetX = -offsetY*slope;
    }
    // If the player is looking down
    // If the player is looking down
    if (rayAngle < M_PI)
    {
        rayHeightY = (((int)playerY >> 6) << 6) + MAP_AREA;
        rayLengthX = (playerY-rayHeightY)*slope+playerX;
        offsetY = 64;
        offsetX = -offsetY*slope;
    }
    if (rayAngle == M_PI || rayAngle == 0)
    {
        rayHeightY = playerY;
        rayLengthX = playerX;
        depthOfField = 8;
    }

    while (depthOfField < 8)
    {
        mapTileX = (int)(rayLengthX) >> 6;
        mapTileY = (int)(rayHeightY) >> 6;
        mapIndex = mapTileY*MAP_AREA+mapTileX;
        if (mapIndex < MAP_SIZE && map[mapIndex] == 1)
        {
            depthOfField = 8;
        }
        else
        {
            rayLengthX += offsetX;
            rayHeightY += offsetY;
            depthOfField += 1;
        }
    }

    glColor3f(0.0f, 1.0f, 0.0f);
    glLineWidth(1.0f);
    glBegin(GL_LINES);
        glVertex2i(playerX, playerY);
        glVertex2i(rayLengthX, rayHeightY);
    glEnd();
}


//What to render
//background, map, player, and then swap buffers
void display(GLFWwindow* window)
{
    //clear the buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //map
    drawMap();
    //player
    drawPlayer();
    drawPlayerDirection();
    drawRays();
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

    init();

    glfwSetKeyCallback(window, key_callback);

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
