#include "public.h"
#include "wall.h"
typedef struct _pathnode
{
	coord xy;
}PathNode;
bool CheckWalkable(coord xy, MapNode *map);
bool CheckEnd(coord xy, MapNode *map);
int CheckRight(path_node top, MapNode *map, Stack_Sq *stack);
int CheckDown(path_node top, MapNode *map, Stack_Sq *stack);
int CheckUp(path_node top, MapNode *map, Stack_Sq *stack);
int CheckLeft(path_node top, MapNode *map, Stack_Sq *stack);