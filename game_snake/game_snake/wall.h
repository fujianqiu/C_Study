#include "ge.h"
#include "public.h"
#ifndef __WALL_H__
#define __WALL_H__
struct brick
{
	node_t node;
	char show;
};
typedef struct wall
{
	brick *head;
	brick *tail;
	unsigned int number;
	//CollisionDtectionEngineHandle *penaltCDEHandle;
}strong_wall;


wall *creat_empty_wall(void);
bool InsFirst(strong_wall *wall_head, brick *p);
brick *get_nbrick(strong_wall *wall_head, unsigned int num);
wall *get_wall_place(unsigned x, unsigned y);
brick *make_brick(int x, int y, char show);
void visit_wall(wall *wall_head);
void destroy_wall(wall *wall_head);
bool updata_wall(PBitmapInfo pBitmapHandle, wall *wall_head);
#endif