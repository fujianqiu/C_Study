#include "stdafx.h"
#include "malloc.h"
#include "wall.h"
#include "windows.h"
#include "time.h"
#include "food.h"
#include "snake.h"
wall *creat_empty_wall(void)
{
	strong_wall *wall_head;
	wall_head = (strong_wall *)malloc(sizeof(strong_wall));
	if (NULL == wall_head)
		return NULL;
	memset(wall_head, 0, sizeof(strong_wall));
	return wall_head;
}
bool InsFirst(strong_wall *wall_head, brick *p)
{
	if ((NULL == wall_head) || (NULL==p))
		return false;
	if (wall_head->head == NULL)
	{
		wall_head->head = p;
		wall_head->tail = p;
		++(wall_head->number);
		return true;
	}
	p->next = wall_head->head;
	wall_head->head = p;
	++(wall_head->number);
	return true;
}
brick *get_nbrick(strong_wall *wall_head, unsigned int num)
{
	if ((wall_head == NULL)||(wall_head->number<num))
		return NULL;
	brick *head = wall_head->head;
	for (int temp = 0; temp < num-1; temp++)
	{
		head = head->next;
	}
	return head;
}
brick *make_brick(int x,int y,char show)
{
	brick *p;
	p = (brick *)malloc(sizeof(brick));
	if (p == NULL)
		return NULL;
	p->next = NULL;
	p->show = show;
	p->x = x;
	p->y = y;
	return p;
}
wall *get_wall_place(unsigned x, unsigned y)
{
	wall *wall_head;
	brick *p;
	int temp;
	srand(time(NULL));
	wall_head = creat_empty_wall();
	if (NULL == wall_head)
		return NULL;
	for (temp = 0; temp < x; temp++)
	{
		p=make_brick(temp, 0, '+');
		InsFirst(wall_head, p);
	}
	for (temp = 0; temp < x; temp++)
	{
		p = make_brick(temp, y-1, '+');
		InsFirst(wall_head, p);
	}
	for (temp = 0; temp < y; temp++)
	{
		p = make_brick(0, temp, '+');
		InsFirst(wall_head, p);
	}
	for (temp = 0; temp < x; temp++)
	{
		p = make_brick(x-1, temp, '+');
		InsFirst(wall_head, p);
	}
	for (temp = 0; temp <5; temp++)
	{
		p = make_brick(rand() % x, rand() % y, '+');
		InsFirst(wall_head, p);
	}
	return wall_head;
}
void visit_wall(wall *wall_head)
{
	brick *p;
	if (wall_head == NULL)
		return;
	p = wall_head->head;
	if (wall_head == NULL)
		return;
	while (p)
	{
		p = p->next;
	}
}
void destroy_wall(wall *wall_head)
{
	brick *p, *p1;
	if ((wall_head == NULL) || (wall_head->head == NULL))
		return;
	p = wall_head->head;
	free(wall_head);
	while (p)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
}