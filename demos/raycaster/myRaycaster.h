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
#include <math.h>


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


// Define constants for screen width and height
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 512
#define SCREEN_TITLE "SCREEN_TITLE"
#define ASPECT (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT

#define MAP_LENGTH 8
#define MAP_HEIGHT 8
#define MAP_AREA MAP_LENGTH*MAP_HEIGHT
#define MAP_SIZE sizeof(map)/sizeof(map[0])
#define PLAYER_DIRECTIONAL_ANGLE_SCALER 5
#define RAY_ACCURACY_ERROR 0.0001


//'D' short for delta, and corresponding to the angle between the direction the player 
float playerX, playerY, playerDx, playerDy, playerAngle;
#endif
