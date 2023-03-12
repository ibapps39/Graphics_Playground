#include <stdio.h>
#include <stdlib.h>

typedef struct xyPoint {
    int x, y;
} Point;
typedef struct treeNode {
    Point point;
    struct treeNode *left;
    struct treeNode *right;
} Node;

Node* newNode(Point p);

void insert(Node** node, Point p, int depth);
void printTreeFromNode(Node* node);

int main_BSP_Custom();