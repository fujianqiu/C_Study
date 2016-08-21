// game_snake.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "malloc.h"
#include "snake.h"
#include <windows.h>
#include "wall.h"
#include "public.h"
#include "check.h"
#include "food.h"
#include "time.h"
#include "ge.h"
#define CANVAS_X 60
#define CANVAS_Y 20
#define FOOD_NUM  10
unsigned int  get_direction_kg()
{
	if (GetAsyncKeyState(VK_NUMPAD4))
	{
		return VK_NUMPAD4;
	}
	if (GetAsyncKeyState(VK_NUMPAD8))
	{
		return VK_NUMPAD8;
	}
	if (GetAsyncKeyState(VK_NUMPAD6))
	{
		return VK_NUMPAD6;
	}
	if (GetAsyncKeyState(VK_NUMPAD5))
	{
		return VK_NUMPAD5;
	}
	return 0;
}
unsigned int  get_direction()
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		return VK_LEFT;
	}
	if (GetAsyncKeyState(VK_UP))
	{
		return VK_UP;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		return VK_RIGHT;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		return VK_DOWN;
	}
	return 0;
}
unsigned get_food_num(void)
{
	return FOOD_NUM;
}
int _tmain(int argc, _TCHAR* argv[])
{ 
	int mk;
	int food_or_not;
	int pena_or_not;
	strong_wall *wall_head;
	snake *snake_head;
	snake *snake_head_kg;
	snake_node *eq;
	food_list *all_food=NULL;
	coordinate last_xy;
	coordinate last_xy_kg;
	unsigned int  direct;
	unsigned int  direct_kg;
	PBitmapInfo geHandle = NULL;
	CollisionDtectionEngineHandle *CDEHandle = NULL;

	geHandle = init_ge(CANVAS_X, CANVAS_Y);
	wall_head = get_wall_place(CANVAS_X, CANVAS_Y);
	snake_head = creat_snake(CANVAS_X / 2, CANVAS_Y / 2);
	snake_head_kg = creat_snake(CANVAS_X /3, CANVAS_Y /3);
	get_empty_food_list(&all_food);
	register_snake_penalt(snake_head, (CollisionDtectionList *)wall_head);
	register_snake_food(snake_head, (CollisionDtectionList *)all_food);
	register_snake_penalt(snake_head_kg, (CollisionDtectionList *)wall_head);
	register_snake_food(snake_head_kg, (CollisionDtectionList *)all_food);
	register_collision_detection_list(snake_head->penaltCDEHandle, (CollisionDtectionList *)snake_head_kg);
	register_food_penalt(all_food, (CollisionDtectionList *)wall_head);
	register_food_penalt(all_food, (CollisionDtectionList *)snake_head);
	register_food_penalt(all_food, (CollisionDtectionList *)snake_head_kg);
	/*********************************************************/
	updata_wall(geHandle, wall_head);
	/*********************************************************/
	do
	{
		direct = get_direction();
		direct_kg = get_direction_kg();

		mk = create_food(geHandle,  all_food, get_food_num());
		if (mk == -1)
			break;
		last_xy = snake_move(snake_head, direct, geHandle);
		last_xy_kg = snake_move_kg(snake_head_kg, direct_kg, geHandle);
		coordinate xy = snake_head_coord(snake_head);
		coordinate xy_kg = snake_head_coord(snake_head_kg);
		if (xy.x == -1)
			break;
		if (xy_kg.x == -1)
			break;
		if (DoesSnakeIntoForbiddenZone(snake_head))
		{
			break;
		}
		if (DoesSnakeIntoForbiddenZone(snake_head_kg))
		{
			break;
		}
		if (DoesSnakeEatFood(snake_head))
		{
			snake_eat_food(snake_head, last_xy);
			free_food(all_food, xy);
		}
		if (DoesSnakeEatFood(snake_head_kg))
		{
			snake_eat_food(snake_head_kg, last_xy_kg);
			free_food(all_food, xy_kg);
		}
		clean_canvas(geHandle);
		updata_have_walk_place(geHandle, last_xy);
		updata_wall(geHandle, wall_head);
		updata_snake(geHandle, snake_head);
		updata_snake_kg(geHandle, snake_head_kg);
		updata_food(geHandle, all_food);
		display_canvas(geHandle);
		if (500 - snake_length(snake_head)*snake_length(snake_head_kg) > 50)
			Sleep(500 - snake_length(snake_head)*snake_length(snake_head_kg));
		else
			Sleep(50);
	} while (1);
	/*********************************************************/
	free(geHandle->frameBuf);
	free(geHandle);
	destroy_wall(wall_head);
	destroy_snake(snake_head_kg);
	destroy_snake(snake_head);
	printf("GAME OVER\n");

	getchar();
	return 0;
}

