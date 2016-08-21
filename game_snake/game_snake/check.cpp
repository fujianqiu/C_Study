#include "stdafx.h"
#include "check.h"
#include "malloc.h"
#include "wall.h"
#include "snake.h"
#include "food.h"
int check_penalty_box(snake *snake_head, wall *wall_head, coordinate *xy)
{
	snake_node *q;
	brick *p;
	if ((snake_head == NULL) || (wall_head == NULL) || (snake_head->head == NULL) || (wall_head->head == NULL) || (xy==NULL))
		return 0;
	q = snake_head->head->next;
	p = wall_head->head;
	while (p)
	{
		if ((p->x == xy->x) && (p->y == xy->y))
			return 1;
		p = p->next;
	}
	while (q)
	{
		if ((q->x == xy->x) && (q->y == xy->y))
			return 1;
		q = q->next;
	}
	return 0;
}
int check_food(coordinate *xy, food *all_food)
{
	if ((all_food) && (xy))
	{
		if ((xy->x == all_food->coord.x) && (xy->y == all_food->coord.y))
			return 1;
		return 0;
	}
	return 0;
}
