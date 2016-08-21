#include "public.h"
#include "malloc.h"
#include "ge.h"
#include "check.h"
#ifndef __FOOD_H__
#define __FOOD_H__
typedef struct _food
{
	node_t node;
	char show;
}food;
typedef struct _food_list
{
	food *food_head;
	food *tail;
	unsigned int food_num;
	CollisionDtectionEngineHandle *penaltCDEHandle;
}food_list;


int create_food(PBitmapInfo pBitmapHandle,food_list *all_food, unsigned n);
bool get_empty_food_list(food_list **all_food);
bool Insfood(food_list *all_food, food *p);
bool updata_food(PBitmapInfo pBitmapHandle, food_list *all_food);
bool free_food(food_list *all_food, coordinate xy);
void register_food_penalt(food_list *all_food, CollisionDtectionList *penaltList);
#endif