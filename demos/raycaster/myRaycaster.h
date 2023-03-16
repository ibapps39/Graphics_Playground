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

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// Define constants for screen width and height
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define SCREEN_TITLE "SCREEN_TITLE"
#define ASPECT (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT

#define MAP_LENGTH 10
#define MAP_HEIGHT 10


int map[MAP_LENGTH][MAP_LENGTH] = {
    {0,0,0,0,0,0,0,0,0, 0},
    {0,0,0,0,0,0,0,0,0, 0},
    {0,0,0,0,0,0,0,0,0, 0},
    {0,0,0,0,0,0,0,0,0, 0},
    {0,0,0,0,0,0,0,0,0, 0},
    {0,0,0,0,0,0,0,0,0, 0},
    {0,0,0,0,0,0,0,0,0, 0},
    {0,0,0,0,0,0,0,0,0, 0},
    {0,0,0,0,0,0,0,0,0, 0},
    {0,0,0,0,0,0,0,0,0, 0}
};
// Define a struct to represent the player's position and direction

// Define a struct to represent a ray

// Define a function to initialize the raycaster

// Define a function to handle key presses

// Define a function to render the scene

// Define a function to calculate the distance to the nearest wall

//
float playerX, playerY;

#endif
