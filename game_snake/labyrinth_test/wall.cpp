#include "stdafx.h"
#include "public.h"
#include "malloc.h"
#include "wall.h"
#include "string.h"
#include "stdlib.h"
#include "node_stack.h"
#include<windows.h>
bool CreateMap(MapNode **map)
{
	int x, y;
	MapNode *p;
	if (map == NULL)
		return false;
	p = (MapNode *)malloc(WIDTH*HEIGHT*sizeof(MapNode));
	if (p == NULL)
		return false;
	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			p[x + y*WIDTH].show = MAP_SHOW;
			p[x + y*WIDTH].state = 1;
			p[x + y*WIDTH].xy.x = x;
			p[x + y*WIDTH].xy.y = y;
		}
	}
	*map = p;
	return true;
}
bool CreateWall(MapNode *map)
{
	int x, y, map_x, map_y;
	if (map == NULL)
		return false;
	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			map_x = map[x + y*WIDTH].xy.x;
			map_y = map[x + y*WIDTH].xy.y;
			if (map_x*map_y == 0 || map_x == WIDTH-1|| map_y == HEIGHT-1)
			{
				map[x + y*WIDTH].state = 0;
				map[x + y*WIDTH].show = WALL_SHOW;
			}
			if (map_x == WIDTH / 2 && map_y < HEIGHT / 2)
			{
				map[x + y*WIDTH].state = 0;
				map[x + y*WIDTH].show = WALL_SHOW;
			}
		}
	}
	return true;
}
bool CreateRandomWall(MapNode *map)
{
	int temp,x,y;
	if (map == NULL)
		return false;
	for (temp = 0; temp <2300; temp++)
	{
		x = rand() % WIDTH;
		y = rand() % HEIGHT;
		if ((x != 1 && y != 1) && (x != WIDTH - 1 && y != HEIGHT - 1))
		{
			map[x + y*WIDTH].state = 0;
			map[x + y*WIDTH].show = WALL_SHOW;
		}
	}
	return true;
}
bool CreateStart(MapNode *map, coord xy)
{
	if (map == NULL)
		return false;
	map[xy.x + xy.y*WIDTH].state = 1;
	map[xy.x + xy.y*WIDTH].show = END_SHOW;
	return true;
}
bool CreateEND(MapNode *map, coord xy)
{
	if (map == NULL)
		return false;
	map[xy.x + xy.y*WIDTH].show = END_SHOW;
	map[xy.x + xy.y*WIDTH].state = 2;
	return true;
}
bool DisplayMap(MapNode *map)
{
	int i,j;
	char a;
	if (map == NULL)
		return false;
	for (j = 0; j <HEIGHT; j++)
	{
		for (i = 0; i < WIDTH; i++)
		{
			printf("%c",map[i + j*WIDTH].show);
		}
		printf("\n");
	}
	return true;
}
bool UpdataPath(MapNode *map, coord xy,bool F_or_T)
{
	if (map == NULL)
		return false;
	if (F_or_T)
	{
		map[xy.x + xy.y*WIDTH].show = PATH_SHOW;
		map[xy.x + xy.y*WIDTH].state = 0;
		return true;
	}
	map[xy.x + xy.y*WIDTH].show = '.';
	map[xy.x + xy.y*WIDTH].state =0;

	return true;
}