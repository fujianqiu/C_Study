#include "stdafx.h"
#include "malloc.h"
#include<windows.h>
#include "wall.h"
#include "time.h"
#include "snake.h"

#define SNAKE_HEAD_IMAGE  '@'
#define SNAKE_BODY_IMAGE  '*'

static void snake_body_move(snake *snake_head,unsigned int direction);
snake *creat_snake(unsigned x, unsigned y)
{
	snake *snake_head;
	snake_node *p;
	p = make_snake_node(x, y, SNAKE_HEAD_IMAGE);
	if (NULL == p)
		return NULL;
	snake_head = (snake *)malloc(sizeof(snake));
	if (NULL == snake_head)
		return NULL;
	snake_head->head = p;
	snake_head->tail = p;
	snake_head->number=1;
	creat_collision_detection_engine(&snake_head->foodCDEHandle);
	creat_collision_detection_engine(&snake_head->penaltCDEHandle);
	register_collision_detection_list(snake_head->penaltCDEHandle, (CollisionDtectionList *)snake_head);
	return snake_head;
}
void register_snake_penalt(snake *snake_head, CollisionDtectionList *penaltList)
{
	register_collision_detection_list(snake_head->penaltCDEHandle, penaltList);
}

void register_snake_food(snake *snake_head, CollisionDtectionList *foodList)
{
	register_collision_detection_list(snake_head->foodCDEHandle, foodList);
}

snake_node *make_snake_node(int x, int y, char show)
{
	snake_node *p;
	p = (snake_node *)malloc(sizeof(snake_node));
	if (p == NULL)
		return NULL;
	p->node.next = NULL;
	p->show = show;
	p->node.coord.x = x;
	p->node.coord.y = y;
	return p;
}
coordinate snake_head_coord(snake *snake_head)
{
	coordinate xy = {-1,-1};
	if ((snake_head == NULL) || (snake_head->head == NULL))
		return xy;
	xy.x = snake_head->head->node.coord.x;
	xy.y = snake_head->head->node.coord.y;
	return xy;
}
void destroy_snake(snake *snake_head)
{
	node_t *p, *p1;
	if ((snake_head == NULL) || (snake_head->head == NULL))
		return;
	p = (node_t *)snake_head->head;
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
	p->node.next = (node_t *)snake_head->head;
	snake_head->head = p;
	++(snake_head->number);
	return true;
}
bool InsLast_snake(snake *snake_head, snake_node *p)
{
	if ((NULL == snake_head) || (NULL == p))
		return false;
	snake_head->tail->node.next = (node_t *)p;
	snake_head->tail = p;
	snake_head->number++;
	return true;
}
bool freeLast_snake(snake *snake_head)
{
	node_t *p, *p1 = NULL;
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
	p = (node_t *)snake_head->head;
	while (p->next)
	{
		p1 = p;
		p = p->next;
	}
	p1->next = NULL;
	free(p);
	snake_head->tail = (snake_node *)p1;
	snake_head->number--;
	return true;
}
static void snake_body_move(snake *snake_head, unsigned int direction)
{
	snake_node *p,*p1;
	if ((NULL == snake_head) || (snake_head->head == NULL))
		return;
	p = snake_head->head;
	if (direction == VK_LEFT && p->node.coord.x >0)
	{
		p1 = make_snake_node(p->node.coord.x - 1, p->node.coord.y, SNAKE_BODY_IMAGE);
		InsFirst_snake(snake_head, p1);
		freeLast_snake(snake_head);
	}
	if (direction == VK_RIGHT)
	{
		p1 = make_snake_node(p->node.coord.x + 1, p->node.coord.y, SNAKE_BODY_IMAGE);
		InsFirst_snake(snake_head, p1);
		freeLast_snake(snake_head);
	}
	if (direction == VK_DOWN)
	{
		p1 = make_snake_node(p->node.coord.x, p->node.coord.y + 1, SNAKE_BODY_IMAGE);
		InsFirst_snake(snake_head, p1);
		freeLast_snake(snake_head);
	}
	if (direction == VK_UP && p->node.coord.y>0)
	{
		p1 = make_snake_node(p->node.coord.x, p->node.coord.y - 1, SNAKE_BODY_IMAGE);
		InsFirst_snake(snake_head, p1);
		freeLast_snake(snake_head);
	}
}
static void snake_body_move_kg(snake *snake_head, unsigned int direction)
{
	snake_node *p, *p1;
	if ((NULL == snake_head) || (snake_head->head == NULL))
		return;
	p = snake_head->head;
	if (direction == VK_NUMPAD4 && p->node.coord.x >0)
	{
		p1 = make_snake_node(p->node.coord.x - 1, p->node.coord.y, SNAKE_BODY_IMAGE);
		InsFirst_snake(snake_head, p1);
		freeLast_snake(snake_head);
	}
	if (direction == VK_NUMPAD6)
	{
		p1 = make_snake_node(p->node.coord.x + 1, p->node.coord.y, SNAKE_BODY_IMAGE);
		InsFirst_snake(snake_head, p1);
		freeLast_snake(snake_head);
	}
	if (direction == VK_NUMPAD5)
	{
		p1 = make_snake_node(p->node.coord.x, p->node.coord.y + 1, SNAKE_BODY_IMAGE);
		InsFirst_snake(snake_head, p1);
		freeLast_snake(snake_head);
	}
	if (direction == VK_NUMPAD8 && p->node.coord.y>0)
	{
		p1 = make_snake_node(p->node.coord.x, p->node.coord.y - 1, SNAKE_BODY_IMAGE);
		InsFirst_snake(snake_head, p1);
		freeLast_snake(snake_head);
	}
}
coordinate snake_move_kg(snake *snake_head, unsigned int direction, PBitmapInfo pBitmapHandle)
{
	coordinate xy = { -1, -1 };
	if ((snake_head == NULL) || ((snake_head->head == NULL))||(pBitmapHandle == NULL) || (pBitmapHandle->frameBuf == NULL))
		return xy;
	static unsigned int lastKey = 0;
	int temp;
	if (direction == 0)
		direction = lastKey;
	if (snake_head->head->node.next!=NULL)
	{
		if ((direction == VK_NUMPAD4) && (lastKey == VK_NUMPAD6))
		{
			direction = VK_NUMPAD6;
		}
		if ((direction == VK_NUMPAD6) && (lastKey == VK_NUMPAD4))
		{
			direction = VK_NUMPAD4;
		}
		if ((direction == VK_NUMPAD8) && (lastKey == VK_NUMPAD5))
		{
			direction = VK_NUMPAD5;
		}
		if ((direction == VK_NUMPAD5) && (lastKey == VK_NUMPAD8))
		{
			direction = VK_NUMPAD8;
		}
	}
	lastKey = direction;
	xy.x = snake_head->tail->node.coord.x;
	xy.y = snake_head->tail->node.coord.y;
	snake_body_move_kg(snake_head, direction);
	updata_snake(pBitmapHandle, snake_head);
	return xy;
}
coordinate snake_move(snake *snake_head, unsigned int direction, PBitmapInfo pBitmapHandle)
{
	coordinate xy = { -1, -1 };
	if ((snake_head == NULL) || ((snake_head->head == NULL)) || (pBitmapHandle == NULL) || (pBitmapHandle->frameBuf == NULL))
		return xy;
	static unsigned int lastKey = 0;
	int temp;
	if (direction == 0)
		direction = lastKey;
	if (snake_head->head->node.next != NULL)
	{
		if ((direction == VK_LEFT) && (lastKey == VK_RIGHT))
		{
			direction = VK_RIGHT;
		}
		if ((direction == VK_RIGHT) && (lastKey == VK_LEFT))
		{
			direction = VK_LEFT;
		}
		if ((direction == VK_UP) && (lastKey == VK_DOWN))
		{
			direction = VK_DOWN;
		}
		if ((direction == VK_DOWN) && (lastKey == VK_UP))
		{
			direction = VK_UP;
		}
	}
	lastKey = direction;
	xy.x = snake_head->tail->node.coord.x;
	xy.y = snake_head->tail->node.coord.y;
	snake_body_move(snake_head, direction);
	updata_snake(pBitmapHandle, snake_head);
	return xy;
}
void updata_have_walk_place(PBitmapInfo pBitmapHandle, coordinate xy)
{
	pBitmapHandle->frameBuf[xy.x + xy.y*pBitmapHandle->width] = ' ';
}
bool updata_snake(PBitmapInfo pBitmapHandle, snake *snake_head)
{
	node_t *p;
	char show = '0';
	if ((pBitmapHandle == NULL) || (pBitmapHandle->frameBuf == NULL))
		return false;
	p = (node_t *)snake_head->head;
	while (p)
	{

		if (p->coord.y < pBitmapHandle->height && p->coord.x < pBitmapHandle->width)
			pBitmapHandle->frameBuf[p->coord.y*pBitmapHandle->width*pBitmapHandle->pointSize + p->coord.x * pBitmapHandle->pointSize] = show++;
		p = p->next;

	
	}
	return true;
}
bool updata_snake_kg(PBitmapInfo pBitmapHandle, snake *snake_head)
{
	node_t *p;
	char show = '*';
	if ((pBitmapHandle == NULL) || (pBitmapHandle->frameBuf == NULL))
		return false;
	p = (node_t *)snake_head->head;
	while (p)
	{

		if (p->coord.y < pBitmapHandle->height && p->coord.x < pBitmapHandle->width)
			pBitmapHandle->frameBuf[p->coord.y*pBitmapHandle->width*pBitmapHandle->pointSize + p->coord.x * pBitmapHandle->pointSize] = show;
		p = p->next;


	}
	return true;
}
bool snake_eat_food(snake *snake_head, coordinate xy)
{	
	snake_node * eq = NULL;
	if (snake_head == NULL)
		return false;
	eq = make_snake_node(xy.x, xy.y, SNAKE_BODY_IMAGE);
	if (eq)
	{
		InsLast_snake(snake_head, eq);
		return true;
	}
	return false;
}

int snake_length(snake *snake_head)
{
	if (snake_head == NULL)
		return 0;
	return snake_head->number;
}


bool remove_snake_head(snake *snake_head, snake_node **e)
{
	if ((snake_head == NULL) || (snake_head->head == NULL) || (e == NULL))
		return false;
	*e = snake_head->head;
	snake_head->head = (snake_node *)snake_head->head->node.next;
	--snake_head->number;
	if (snake_head->number == 0)
		snake_head->tail = NULL;
	(*e)->node.next = NULL;
	return true;
}
bool DoesSnakeIntoForbiddenZone(snake *snake_head)
{
	snake_node * head = NULL;
	bool  result = false;
	coordinate xy = snake_head_coord(snake_head);
	if (xy.x == -1)
		return false;
	remove_snake_head(snake_head, &head);
	result = start_collision_detection(snake_head->penaltCDEHandle, xy);
	InsFirst_snake(snake_head, head);
	return result;
}
bool DoesSnakeEatFood(snake *snake_head)
{
	coordinate xy = snake_head_coord(snake_head);
	if (xy.x == -1)
		return false;
	return start_collision_detection(snake_head->foodCDEHandle, xy);
}