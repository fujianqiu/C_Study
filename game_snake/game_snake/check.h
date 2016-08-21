#include "public.h"
#include "wall.h"
#ifndef __CHECK_PEN__
#define __CHECK_PEN__

typedef struct checknode_s
{
	node_t coord_node;
	list_t *listHanlde;
}checknode_t;

typedef struct checklist_s
{
	checknode_t *head;
	checknode_t *tail;
	unsigned int number;
}checklist_t;

typedef checklist_t CollisionDtectionEngineHandle;
typedef list_t     CollisionDtectionList;

bool creat_collision_detection_engine(CollisionDtectionEngineHandle **CDEHandle);
bool register_collision_detection_list(CollisionDtectionEngineHandle *CDEHandle, list_t *CDEListHanlde);
bool start_collision_detection(CollisionDtectionEngineHandle *CDEHandle, coordinate coord);
void destory_collision_detection_engine(CollisionDtectionEngineHandle *CDEHandle);
#endif