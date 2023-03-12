#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    int x;
    int y;
} Point;

typedef struct Node {
    Point p;
    struct Node *left;
    struct Node *right;
} Node;

Node* newNode(Point p) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->p = p;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(Node** node, Point p, int depth) {
    if (*node == NULL) {
        *node = newNode(p);
    } else {
        int cd = depth % 2;
        if (cd == 0) {
            if (p.x < (*node)->p.x) {
                insert(&((*node)->left), p, depth+1);
            } else {
                insert(&((*node)->right), p, depth+1);
            }
        } else {
            if (p.y < (*node)->p.y) {
                insert(&((*node)->left), p, depth+1);
            } else {
                insert(&((*node)->right), p, depth+1);
            }
        }
    }
}

void printTree(Node* node) {
    if (node != NULL) {
        printf("(%d,%d) ", node->p.x, node->p.y);
        printTree(node->left);
        printTree(node->right);
    }
}

int mn() {
    Point points[] = {{3,6}, {17,15}, {13,15}, {6,12}, {9,1}, {2,7}, {10,19}};
    int n = sizeof(points)/sizeof(points[0]);
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        insert(&root, points[i], 0);
    }
    printTree(root);
    return 0;
}
