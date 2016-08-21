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
	p->node.next= &wall_head->head->node;
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
		head = (brick *)head->node.next;
	}
	return head;
}
brick *make_brick(int x,int y,char show)
{
	brick *p;
	p = (brick *)malloc(sizeof(brick));
	if (p == NULL)
		return NULL;
	p->node.next = NULL;
	p->show = show;
	p->node.coord.x = x;
	p->node.coord.y = y;
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
	node_t *p;
	if (wall_head == NULL)
		return;
	p = &wall_head->head->node;
	if (wall_head == NULL)
		return;
	while (p)
	{
		p = p->next;
	}
}
void destroy_wall(wall *wall_head)
{
	node_t *p, *p1;
	if ((wall_head == NULL) || (wall_head->head == NULL))
		return;
	p = &wall_head->head->node;
	free(wall_head);
	while (p)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
}

bool updata_wall(PBitmapInfo pBitmapHandle, wall *wall_head)
{
	node_t *p;
	if ((pBitmapHandle == NULL) || (pBitmapHandle->frameBuf == NULL))
		return false;
	p = &wall_head->head->node;
	while (p)
	{
		if (p->coord.y < pBitmapHandle->height &&p->coord.x < pBitmapHandle->width)
			pBitmapHandle->frameBuf[p->coord.y*pBitmapHandle->width*pBitmapHandle->pointSize + p->coord.x * pBitmapHandle->pointSize] = ((brick *)p)->show;
		p = p->next;
	}
	return true;
}