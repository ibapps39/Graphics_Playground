#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define NUM_OBSTACLES 10

typedef struct Point
{
    int x;
    int y;
} Point;

typedef struct Node
{
    Point p1;
    Point p2;
    struct Node *left;
    struct Node *right;
} Node;

Node *newNode(Point p1, Point p2)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->p1 = p1;
    node->p2 = p2;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(Node **node, Point p1, Point p2, int depth)
{
    if (*node == NULL)
    {
        *node = newNode(p1, p2);
    }
    else
    {
        int cd = depth % 2;
        if (cd == 0)
        {
            if (p1.x < (*node)->p1.x)
            {
                insert(&((*node)->left), p1, p2, depth + 1);
            }
            else
            {
                insert(&((*node)->right), p1, p2, depth + 1);
            }
        }
        else
        {
            if (p1.y < (*node)->p1.y)
            {
                insert(&((*node)->left), p1, p2, depth + 1);
            }
            else
            {
                insert(&((*node)->right), p1, p2, depth + 1);
            }
        }
    }
}

int isCollision(Node *node, Point p)
{
    if (node == NULL)
    {
        return 0;
    }
    else if (p.x >= node->p1.x && p.x <= node->p2.x && p.y >= node->p1.y && p.y <= node->p2.y)
    {
        return 1;
    }
    else
    {
        int cd = node->left == NULL ? 0 : (node->left->p2.x >= p.x ? 0 : 1);
        if (cd == 0)
        {
            return isCollision(node->left, p);
        }
        else
        {
            return isCollision(node->right, p);
        }
    }
}

void drawRect(SDL_Renderer *renderer, int x, int y, int w, int h)
{
    SDL_Rect rect = {x, y, w, h};
    SDL_RenderDrawRect(renderer, &rect);
}

int mnSDL()
{
    srand(time(NULL));
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("BSP Demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Event event;
    int running = 1;
    Node *root = NULL;
    Point player = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
    Point goal = {rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT};
    Point obstacles[NUM_OBSTACLES];
    for (int i = 0; i < NUM_OBSTACLES; i++)
    {
        Point p1 = {rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT};
        Point p2 = {p1.x + rand() % 50, p1.y + rand() % 50};
        obstacles[i] = p1;
        insert(&root, p1, p2, 0);
    }
    while (running)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        drawRect(renderer, goal.x, goal.y, 10, 10);
        for (int i = 0; i < NUM_OBSTACLES; i++)
        {
            drawRect(renderer, obstacles[i].x, obstacles[i].y, obstacles[i].x + 50, obstacles[i].y + 50);
        }
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        drawRect(renderer, player.x, player.y, 10, 10);
        SDL_RenderPresent(renderer);
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = 0;
            }
        }
        const Uint8 *state = SDL_GetKeyboardState(NULL);
        if (state[SDL_SCANCODE_LEFT])
        {
            player.x--;
        }
        if (state[SDL_SCANCODE_RIGHT])
        {
            player.x++;
        }
        if (state[SDL_SCANCODE_UP])
        {
            player.y--;
        }
        if (state[SDL_SCANCODE_DOWN])
        {
            player.y++;
        }
        if (isCollision(root, player))
        {
            printf("Game over!\n");
            running = 0;
        }
        if (player.x >= goal.x && player.x <= goal.x + 10 && player.y >= goal.y && player.y <= goal.y + 10)
        {
            printf("You win!\n");
            running = 0;
        }
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

/*
In this example, we use binary space partitioning to create a tree of rectangles that represent the game obstacles.
We start by creating a root node and then insert each obstacle into the tree by recursively traversing the tree and
 adding the obstacle to the left or right subtree based on its position relative to the parent node.

We then check for collisions between the player and the obstacles by recursively traversing the tree and checking
 if the player's position is within any of the rectangles.

Finally, we use SDL2 to create a simple game loop that allows the player to
 move around and avoid the obstacles until they reach the goal.
*/
