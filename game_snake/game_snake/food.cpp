#include "stdafx.h"
#include "food.h"
#include "time.h"
#include "ge.h"
#include "snake.h"
#include "wall.h"
#include "check.h"
#include "time.h"
#include<windows.h>
#define FOOD_IMAGE  '$'
int create_food(PBitmapInfo pBitmapHandle,food_list *all_food,unsigned n)
{
	int temp_one;
	int temp_two;
	node_t *p;
	coordinate xy;
	if (all_food==NULL)
		return -1;
	if (all_food->food_num != 0)
		return 1;
	
	for (int index = 0; index < n; index++)
	{
		do
		{
			xy.x = rand() % pBitmapHandle->width;
			xy.y = rand() % pBitmapHandle->height;
		} while (start_collision_detection(all_food->penaltCDEHandle, xy));
		p = (node_t *)(food *)malloc(sizeof(food));
		if (p == NULL)
			return -1;
		p->coord.x = xy.x;
		p->coord.y = xy.y;
		((food *)p)->show= FOOD_IMAGE;
		p->next = NULL;
		Insfood(all_food, (food *)p);
	}
	return 0;
}
bool Insfood(food_list *all_food, food *p)
{
	if ((all_food == NULL) || (p == NULL))
		return false;
	if (all_food->food_head == NULL)
	{
		all_food->food_head = p;
		all_food->food_num = 1;
		return true;
	}
	p->node.next = &all_food->food_head->node;
	all_food->food_head = p;
	all_food->food_num++;
	return true;
}

bool updata_food(PBitmapInfo pBitmapHandle, food_list *all_food)
{
	node_t *p;
	if ((pBitmapHandle == NULL) || (all_food == NULL) || (all_food->food_head==NULL))
		return false;
	p = &all_food->food_head->node;
	while (p)
	{
		if (p->coord.y< pBitmapHandle->height &&p->coord.x < pBitmapHandle->width)
			pBitmapHandle->frameBuf[p->coord.y*pBitmapHandle->width*pBitmapHandle->pointSize + p->coord.x* pBitmapHandle->pointSize] = ((food *)p)->show;
		p = p->next;
	}
	return true;
}

bool get_empty_food_list(food_list **all_food)
{
	if (all_food == NULL)
		return false;
	*all_food = (food_list *)malloc(sizeof(food_list));
	if (*all_food == NULL)
		return false;
	(*all_food)->food_head = NULL;
	(*all_food)->food_num = 0;

	//CollisionDtectionEngineHandle *foodCDEHandle = NULL;
	creat_collision_detection_engine(&(*all_food)->penaltCDEHandle);
	register_collision_detection_list((*all_food)->penaltCDEHandle, (CollisionDtectionList *)(*all_food));
	return true;
}

void register_food_penalt(food_list *all_food, CollisionDtectionList *penaltList)
{
	register_collision_detection_list(all_food->penaltCDEHandle, penaltList);
}

bool free_food(food_list *all_food, coordinate xy)
{
	node_t *p, *p1;
	if ((all_food == NULL) || (all_food->food_head == NULL))
		return false;
	p = &all_food->food_head->node;
	if ((xy.x == p->coord.x) && (xy.y == p->coord.y))
	{
		all_food->food_head = (food *)(p->next);
		all_food->food_num--;
		free(p);
		return true;
	}
	while (p)
	{
		p1 = p;
		p = p->next;
		if (p)
		{
			if ((xy.x == p->coord.x) && (xy.y == p->coord.y))
			{
				p1->next = p->next;
				all_food->food_num--;
				free(p);
				return true;
			}
		}
	}
	return false;
}