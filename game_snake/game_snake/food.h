#include "public.h"
#include "malloc.h"
#ifndef __FOOD_H__
#define __FOOD_H__
typedef struct _food
{
	struct _food *next;
	coordinate coord;
	char show;
}food;
food *create_food(coordinate *xy);
food *Insfood(food *all_food, coordinate xy);
#endif