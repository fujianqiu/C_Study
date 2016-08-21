#include "public.h"
#ifndef __SNAKE_H__
#define __SNAKE_H__
struct snake_node
{
	snake_node *next;
	int x;
	int y;
	char show;
};
struct snake
{
	snake_node *head;
	snake_node *tail;
	unsigned int number;
};
snake *creat_snake(unsigned x, unsigned y);
snake_node *make_snake_node(int x, int y, char show);
coordinate snake_head_coord(snake *snake_head);
void destroy_snake(snake *snake_head);
bool InsFirst_snake(snake *snake_head, snake_node *p);
bool freeLast_snake(snake *snake_head);
void snake_body_move(snake *snake_head, unsigned int direction);
bool InsLast_snake(snake *snake_head, snake_node *p);
#endif