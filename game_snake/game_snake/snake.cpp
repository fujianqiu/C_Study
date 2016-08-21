#include "stdafx.h"
#include "malloc.h"
#include<windows.h>
#include "wall.h"
#include "time.h"
#include "snake.h"

snake *creat_snake(unsigned x, unsigned y)
{
	snake *snake_head;
	snake_node *p;
	p = make_snake_node(x / 2, y / 2,'@');
	if (NULL == p)
		return NULL;
	snake_head = (snake *)malloc(sizeof(snake));
	if (NULL == snake_head)
		return NULL;
	snake_head->head = p;
	snake_head->tail = p;
	(snake_head->number)++;
	return snake_head;
}
snake_node *make_snake_node(int x, int y, char show)
{
	snake_node *p;
	p = (snake_node *)malloc(sizeof(snake_node));
	if (p == NULL)
		return NULL;
	p->next = NULL;
	p->show = show;
	p->x = x;
	p->y = y;
	return p;
}
coordinate snake_head_coord(snake *snake_head)
{
	coordinate xy = {-1,-1};
	if ((snake_head == NULL) || (snake_head->head == NULL))
		return xy;
	xy.x = snake_head->head->x;
	xy.y = snake_head->head->y;
	return xy;
}
void destroy_snake(snake *snake_head)
{
	snake_node *p,*p1;
	if ((snake_head == NULL) || (snake_head->head == NULL))
		return;
	p = snake_head->head;
	free(snake_head);
	while (p)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
}
bool InsFirst_snake(snake *snake_head, snake_node *p)
{
	if ((NULL == snake_head) || (NULL == p))
		return false;
	if (snake_head->head == NULL)
	{
		snake_head->head = p;
		snake_head->tail = p;
		++(snake_head->number);
		return true;
	}
	p->next = snake_head->head;
	snake_head->head = p;
	++(snake_head->number);
	return true;
}
bool InsLast_snake(snake *snake_head, snake_node *p)
{
	if ((NULL == snake_head) || (NULL == p))
		return false;
	snake_head->tail->next = p;
	snake_head->tail = p;
	snake_head++;
	return true;
}
bool freeLast_snake(snake *snake_head)
{
	snake_node *p,*p1=NULL;
	if ((NULL == snake_head)||(snake_head->head==NULL))
		return false;
	if (snake_head->number == 1)
	{
		free(snake_head->head);
		snake_head->head = NULL;
		snake_head->tail = NULL;
		snake_head->number=0;
		return true;
	}
	p = snake_head->head;
	while (p->next)
	{
		p1 = p;
		p = p->next;
	}
	p1->next = NULL;
	free(p);
	snake_head->tail = p1;
	snake_head->number--;
	return true;
}
void snake_body_move(snake *snake_head, unsigned int direction)
{
	snake_node *p,*p1;
	if ((NULL == snake_head) || (snake_head->head == NULL))
		return;
	p = snake_head->head;
	if (direction == VK_LEFT && p->x >0)
	{
		p1=make_snake_node(p->x - 1, p->y, '*');
		InsFirst_snake(snake_head, p1);
		freeLast_snake(snake_head);
	}
	if (direction == VK_RIGHT)
	{
		p1 = make_snake_node(p->x + 1, p->y, '*');
		InsFirst_snake(snake_head, p1);
		freeLast_snake(snake_head);
	}
	if (direction == VK_DOWN)
	{
		p1 = make_snake_node(p->x, p->y+1, '*');
		InsFirst_snake(snake_head, p1);
		freeLast_snake(snake_head);
	}
	if (direction == VK_UP && p->y>0)
	{
		p1 = make_snake_node(p->x, p->y-1, '*');
		InsFirst_snake(snake_head, p1);
		freeLast_snake(snake_head);
	}
}
