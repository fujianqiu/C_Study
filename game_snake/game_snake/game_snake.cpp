// game_snake.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "malloc.h"
#include "snake.h"
#include<windows.h>
#include "wall.h"
#include "public.h"
#include "check.h"
#include "food.h"
#include "time.h"
#include "ge.h"

int ak = 0;
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
coordinate move(snake *snake_head, unsigned x, unsigned y, unsigned int direction, char canvas[][CANVAS_Y])
{
	coordinate xy = {-1,-1};
	if ((snake_head == NULL) || (canvas == NULL))
		return xy;
	static unsigned int lastKey = 0;
	int temp;
	if (direction == 0)
		direction = lastKey;
	else if ((direction == VK_LEFT) && (lastKey == VK_RIGHT))
	{
		direction = VK_RIGHT;
	}
	else if ((direction == VK_RIGHT) && (lastKey == VK_LEFT))
	{
		direction = VK_LEFT;
	}
	else if ((direction == VK_UP) && (lastKey == VK_DOWN))
	{
		direction = VK_DOWN;
	}
	else if ((direction == VK_DOWN) && (lastKey == VK_UP))
	{
		direction = VK_UP;
	}
	else
		lastKey = direction;
	xy.x = snake_head->tail->x;
	xy.y = snake_head->tail->y;
	canvas[xy.x][xy.y] = ' ';
	snake_body_move(snake_head, direction);
	return xy;
}
bool updata_wall(char canvas[][CANVAS_Y], wall *wall_head)
{
	brick *p;
	if ((canvas == NULL) || (wall_head == NULL))
		return false;
	p = wall_head->head;
	while (p)
	{
		canvas[p->x][p->y] = p->show;
		p = p->next;
	}
	return true;
}
bool updata_snake(char canvas[][CANVAS_Y], snake *snake_head)
{
	snake_node *p;
	if ((canvas == NULL) || (snake_head == NULL))
		return false;
	p = snake_head->head;
	while (p)
	{
		canvas[p->x][p->y] = p->show;
		p = p->next;
	}
	return true;
}
food *updata_food(snake *snake_head, wall *wall_head, food *all_food, char canvas[][CANVAS_Y])
{
	int temp;
	coordinate xy;
	if ((snake_head == NULL) || (wall_head == NULL))
		return NULL;
	if (ak ==1)
		return all_food;
	do
	{
		xy.x = rand() % CANVAS_X;
		xy.y = rand() % CANVAS_Y;
		temp = check_penalty_box(snake_head, wall_head, &xy);
	} while (temp);
	all_food=Insfood(all_food, xy);
	canvas[all_food->coord.x][all_food->coord.y] = all_food->show;
	ak = 1;
	return all_food;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int food_or_not;
	int pena_or_not;
	strong_wall *wall_head;
	snake *snake_head;
	snake_node *eq;
	food *all_food=NULL;
	coordinate last_xy;
	unsigned int  direct;
	char canvas[CANVAS_X][CANVAS_Y];
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = FALSE;
	cci.dwSize = sizeof(cci);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cci);
	/*********************************************************/
	clean_canvas((char *)canvas, CANVAS_X, CANVAS_Y);
	wall_head = get_wall_place(CANVAS_X, CANVAS_Y);
	updata_wall(canvas, wall_head);
	snake_head=creat_snake(CANVAS_X, CANVAS_Y);
	updata_snake(canvas, snake_head);
	display_canvas(canvas, CANVAS_X, CANVAS_Y);
	/*********************************************************/
	do
	{
		direct = get_direction();
		last_xy=move(snake_head, CANVAS_X, CANVAS_Y, direct, canvas);
		all_food=updata_food(snake_head, wall_head, all_food, canvas);
		coordinate xy = snake_head_coord(snake_head);
		if (xy.x == -1)
			break;
		pena_or_not= check_penalty_box(snake_head, wall_head, &xy);
		if (pena_or_not)
			break;
		food_or_not = check_food(&xy, all_food);
		if (food_or_not)
		{
			eq=make_snake_node(last_xy.x, last_xy.y, '*');
			InsLast_snake(snake_head, eq);
			free(all_food);
			ak =0;
		}
		updata_snake(canvas, snake_head);
		display_canvas(canvas, CANVAS_X, CANVAS_Y);
		Sleep(100);
	} while (1);
	/*********************************************************/
	destroy_wall(wall_head);
	destroy_snake(snake_head);
	printf("GAME OVER\n");
	getchar();
	return 0;
}

