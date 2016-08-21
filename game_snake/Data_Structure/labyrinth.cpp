#include "stdafx.h"
#include "malloc.h"
#include "string.h"
#include "stdlib.h"
#include "labyrinth.h"
map_node MakeNode(int x, int y, int state)
{
	map_node elem;
	elem.state = state;
	elem.xy.x = x;
	elem.xy.y = y;
	return elem;
}
bool CreateLabyrinth(Stack_Sq **labyrinth, int width, int height)
{
	int x, y;
	CreateEmptyStack(labyrinth);
	for (y = 0; y < height; y++)
	{
		for (x = 0; x < width; x++)
		{
			if (x*y == 0 || x == width - 1 || y == height-1)
				Push(*labyrinth, MakeNode(x, y, WALL));
			else if ((x == width / 3 || x == 2 * width / 3) && y<height/3)
				Push(*labyrinth, MakeNode(x, y, WALL));
			else if ((x == width / 3 || x == 2 * width / 3) && y>2*height / 5)
				Push(*labyrinth, MakeNode(x, y, WALL));
			else if ((x<width / 5 || x>4 * width / 5) && y == height/2)
				Push(*labyrinth, MakeNode(x, y, WALL));
			else
				Push(*labyrinth, MakeNode(x, y, ROAD));
		}
	}
	return true;
}
void labyrinth_test()
{
	Stack_Sq *labyrinth=NULL;
	CreateLabyrinth(labyrinth, WIDTH, HEIGHT);
	StackTraverse(labyrinth, PrintfStack);






	getchar();
	return;
}