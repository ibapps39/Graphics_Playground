#pragma once
#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>
#include <time.h>


#ifdef __APPLE__
#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"
#include "GLFW/glfw3.h"
#endif // DEBUG

#ifdef __linux__
#include <linux/time.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"
#include <gl.h>
#endif // __linux__
#ifdef unix
#include <time.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"
#include <gl.h>
#endif // unix

#ifdef _WIN32
#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"
#include <gl.h>
#endif // DEBUG

typedef struct {
  SDL_Renderer *renderer;
  SDL_Window *window;
} App; 


