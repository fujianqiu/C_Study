#ifndef __LABYRINTH_
#define __LABYRINTH_
#include "stack.h"
#define HEIGHT 10
#define WIDTH 10
#define WALL 0
#define ROAD 1
map_node MakeNode(int x, int y, int state);
bool CreateLabyrinth(Stack_Sq *labyrinth, int width, int height);
void labyrinth_test();
#endif