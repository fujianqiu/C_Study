#include "public.h"
#include "ge.h"
#include "check.h"
#ifndef __SNAKE_H__
#define __SNAKE_H__
struct snake_node
{
	node_t node;
	char show;
};
struct snake
{
	snake_node *head;
	snake_node *tail;
	unsigned int number;
	CollisionDtectionEngineHandle *foodCDEHandle;
	CollisionDtectionEngineHandle *penaltCDEHandle;
};

snake *creat_snake(unsigned x, unsigned y);
snake_node *make_snake_node(int x, int y, char show);
coordinate snake_head_coord(snake *snake_head);
void destroy_snake(snake *snake_head);
bool InsFirst_snake(snake *snake_head, snake_node *p);
bool freeLast_snake(snake *snake_head);
void updata_have_walk_place(PBitmapInfo pBitmapHandle, coordinate xy);
bool snake_eat_food(snake *snake_head, coordinate xy);
coordinate snake_move(snake *snake_head, unsigned int direction, PBitmapInfo pBitmapHandle);
coordinate snake_move_kg(snake *snake_head, unsigned int direction, PBitmapInfo pBitmapHandle);
static void snake_body_move_kg(snake *snake_head, unsigned int direction);
bool InsLast_snake(snake *snake_head, snake_node *p);
bool updata_snake(PBitmapInfo pBitmapHandle, snake *snake_head);
int snake_length(snake *snake_head);
bool updata_snake_kg(PBitmapInfo pBitmapHandle, snake *snake_head);
void register_snake_penalt(snake *snake_head, CollisionDtectionList *penaltList);
void register_snake_food(snake *snake_head, CollisionDtectionList *foodList);
bool DoesSnakeIntoForbiddenZone(snake *snake_head);
bool DoesSnakeEatFood(snake *snake_head);
#endif