#ifndef RAYCASTER_H
#define RAYCASTER_H

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#ifdef __linux__
#include <GL/glu.h>
#else
#include <GL/glu.h>
#endif

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define constants for screen width and height
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define SCREEN_TITLE "SCREEN_TITLE"
#define ASPECT (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT

#define mapX 10
#define mapY 10
// Define a struct to represent the player's position and direction
typedef struct {
    float x;
    float y;
    float direction;
} Player;

// Define a struct to represent a ray
typedef struct {
    float x;
    float y;
    float distance;
    int wallHit;
} Ray;

// Define a function to initialize the raycaster
void init_raycaster(GLFWwindow* window);

// Define a function to handle key presses
void handle_keys(GLFWwindow* window, int key, int code, int action, int mods);

// Define a function to render the scene
void render_scene(Player* player);

// Define a function to calculate the distance to the nearest wall
float cast_ray(Player* player, float angle);

#endif
