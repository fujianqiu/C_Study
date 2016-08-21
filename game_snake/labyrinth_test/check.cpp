#include "stdafx.h"
#include "public.h"
#include "malloc.h"
#include "string.h"
#include "stdlib.h"
#include "node_stack.h"
#include "wall.h"
bool CheckWalkable(coord xy, MapNode *map)
{
	if (map == NULL)
		return false;
	if (map[xy.x + xy.y*WIDTH].state)
		return true;
	return false;
}
bool CheckEnd(coord xy, MapNode *map)
{
	if (map == NULL)
		return false;
	if (map[xy.x + xy.y*WIDTH].state==2)
		return true;
	return false;
}
int CheckRight(path_node top, MapNode *map,Stack_Sq *stack)
{
	coord xy;
	if (map == NULL||stack==NULL||stack->base==NULL)
		exit(1);
	if (top.direction.right == NULL)
		return 0;
	xy.x = top.xy.x + 1;
	xy.y = top.xy.y;
	if (CheckEnd(xy, map))
		return 2;
	if (CheckWalkable(xy, map))
	{
		top.direction.right = 0;
		InPath(stack, xy);
		UpdataPath(map,xy, true);
		return 1;
	}
	return 0;
}
int CheckDown(path_node top, MapNode *map, Stack_Sq *stack)
{
	coord xy;
	if (map == NULL || stack == NULL || stack->base == NULL)
		exit(1);
	if (top.direction.right == NULL)
		return 0;
	xy.x = top.xy.x;
	xy.y = top.xy.y-1;
	if (CheckEnd(xy, map))
		return 2;
	if (CheckWalkable(xy, map))
	{
		top.direction.right = 0;
		InPath(stack, xy);
		UpdataPath(map, xy, true);
		return 1;
	}
	return 0;
}
int CheckUp(path_node top, MapNode *map, Stack_Sq *stack)
{
	coord xy;
	if (map == NULL || stack == NULL || stack->base == NULL)
		exit(1);
	if (top.direction.right == NULL)
		return 0;
	xy.x = top.xy.x;
	xy.y = top.xy.y+1;
	if (CheckEnd(xy, map))
		return 2;
	if (CheckWalkable(xy, map))
	{
		top.direction.right = 0;
		InPath(stack, xy);
		UpdataPath(map, xy, true);
		return 1;
	}
	return 0;
}
int CheckLeft(path_node top, MapNode *map, Stack_Sq *stack)
{
	coord xy;
	if (map == NULL || stack == NULL || stack->base == NULL)
		exit(1);
	if (top.direction.right == NULL)
		return 0;
	xy.x = top.xy.x - 1;
	xy.y = top.xy.y;
	if (CheckEnd(xy, map))
		return 2;
	if (CheckWalkable(xy, map))
	{
		top.direction.right = 0;
		InPath(stack, xy);
		UpdataPath(map, xy, true);
		return 1;
	}
	return 0;
}