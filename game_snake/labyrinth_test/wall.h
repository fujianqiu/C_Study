#ifndef __WALL_
#define __WALL_
#include "public.h"
#define WIDTH 140
#define HEIGHT 40
#define MAP_SHOW ' '
#define END_SHOW '0'
#define WALL_SHOW '#'

typedef struct _map
{
	coord xy;
	int state;
	char show;
}MapNode;
bool CreateEND(MapNode *map, coord xy);
bool CreateMap(MapNode **map);
bool CreateWall(MapNode *map);
bool DisplayMap(MapNode *map);
bool CreateRandomWall(MapNode *map);
bool UpdataPath(MapNode *map, coord xy, bool F_or_T);
#endif