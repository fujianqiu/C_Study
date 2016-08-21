#include "stdafx.h"
#include "food.h"

food *create_food(coordinate xy)
{
	food *p;
	p = (food *)malloc(sizeof(food));
	if (p == NULL)
		return NULL;
	p->next == NULL;
	p->coord.x = xy.x;
	p->coord.y = xy.y;
	p->show = '$';
	return p;
}
food *Insfood(food *all_food, coordinate xy)
{
	food *p;
	p = create_food(xy);
	if (p == NULL)
		return NULL;
	p->next = all_food;
	all_food = p;
	return all_food;
}