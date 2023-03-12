#include <stdio.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 25

int worldMap[HEIGHT][WIDTH] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};

int main()
{
    float playerX = 2.0;
    float playerY = 2.0;
    float playerAngle = M_PI / 4.0;

    char screen[HEIGHT][WIDTH];
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            float rayAngle = playerAngle - atan2(y - HEIGHT / 2, x - WIDTH / 2);
            float distanceToWall = 0;
            int hitWall = 0;
            int wallX, wallY;

            float testX = playerX;
            float testY = playerY;

            while (!hitWall && distanceToWall < 20.0) {
                int mapX = (int)testX;
                int mapY = (int)testY;

                if (mapX < 0 || mapX >= WIDTH || mapY < 0 || mapY >= HEIGHT) {
                    hitWall = 1;
                    distanceToWall = 20.0;
                } else if (worldMap[mapY][mapX] == 1) {
                    hitWall = 1;
                    wallX = mapX;
                    wallY = mapY;
                } else {
                    distanceToWall += 0.1;
                    testX = playerX + distanceToWall * cos(rayAngle);
                    testY = playerY + distanceToWall * sin(rayAngle);
                }
            }

            int ceiling = HEIGHT / 2 - HEIGHT / distanceToWall;
            int floor = HEIGHT - ceiling;

            char shade;
            if (distanceToWall <= 5.0) {
                shade = '#';
            } else if (distanceToWall <= 10.0) {
                shade = 'x';
            } else if (distanceToWall <= 15.0) {
                shade = '.';
            } else if (distanceToWall <= 20.0) {
                shade = '-';
            } else {
                shade = ' ';
            }

            for (int i = 0; i < HEIGHT; i++) {
                if (i < ceiling) {
                    screen[i][x] = ' ';
                } else if (i >= ceiling && i <= floor) {
                    screen[i][x] = shade;
                } else {
                    screen[i][x] = ' ';
                }
            }
        }
    }

   
