#include "stdafx.h"
#include "check.h"
#include "malloc.h"
#include "wall.h"
#include "snake.h"
#include "food.h"

static bool creat_empty_checklist(checklist_t **CheckList);
static checknode_t *get_n_node(checklist_t *CheckList, int n);
static bool InsList_n(checklist_t *CheckList, int n, checknode_t *p);
static bool visit_list(checklist_t *CheckList, void *visit(checknode_t *q));
static void *visit(checknode_t *q);

static bool creat_empty_checklist(checklist_t **CheckList)
{
	if (CheckList == NULL)
		return false;
	(*CheckList) = (checklist_t *)malloc(sizeof(checklist_t));
	if ((*CheckList) == NULL)
		return false;
	(*CheckList)->head = NULL;
	(*CheckList)->tail = NULL;
	(*CheckList)->number = 0;
	return true;
}
static bool make_check_node(checknode_t **e, list_t *listHanlde)
{
	checknode_t *p=NULL;
	if (e == NULL)
		return false;
	p = (checknode_t *)malloc(sizeof(checknode_t));
	if (p == NULL)
	{
		(*e) = NULL;
		return false;
	}
	p->listHanlde = listHanlde;
	p->coord_node.next = NULL;
	p->coord_node.coord.x = 0;
	p->coord_node.coord.y = 0;
	(*e) = p;
	return true;
}
static checknode_t *get_n_node(checklist_t *CheckList, int n)
{
	if ((CheckList == NULL) || (CheckList->head == NULL) || (n<1 || n>CheckList->number))
		return NULL;
	checknode_t *p = CheckList->head;
	while (n - 1)
	{
		p = (checknode_t *)p->coord_node.next;
		n--;
	}
	return p;
}
static bool InsList_n(checklist_t *CheckList, int n, checknode_t *p)
{
	checknode_t *temp;
	if ((CheckList == NULL) || (p == NULL) || (n<1 || n>CheckList->number + 1))
		return false;
	if (CheckList->head == NULL)
	{
		CheckList->head = p;
		CheckList->tail = p;
		p->coord_node.next = NULL;
		CheckList->number++;
		return true;
	}
	if (n == 1)
	{
		p->coord_node.next = &CheckList->head->coord_node;
		CheckList->head = p;
		CheckList->number++;
		return true;
	}
	if (n == CheckList->number + 1)
	{
		CheckList->tail->coord_node.next = &p->coord_node;
		CheckList->tail = p;
		p->coord_node.next = NULL;
		CheckList->number++;
		return true;
	}
	temp = get_n_node(CheckList, n - 1);
	p->coord_node.next = temp->coord_node.next;
	temp->coord_node.next = (node_t *)p;
	CheckList->number++;
	return true;
}
static bool list_traverse(list_t *list, bool visit(node_t *q, coordinate coord), coordinate coord)
{
	if ((list == NULL) || (list->head == NULL))
		return false;
	node_t *p = list->head;
	while (p)
	{
		if (visit(p, coord) == true)
			return true;
		p = p->next;
	}
	return false;
}
static bool check_coord_visit(node_t *pNode, coordinate coord)
{
	if (pNode)
	{
	//	printf("pNode->coord.x  %d, pNode->coord.y  %d, coord.x  %d , coord.y %d \n", pNode->coord.x, pNode->coord.y, coord.x, coord.y);
		if (pNode->coord.x == coord.x && pNode->coord.y == coord.y)
			return true;
	}
	return false;
}

static bool check_node_visit(node_t *pNode, coordinate coord)
{
	checknode_t *q = (checknode_t *)pNode;
	if (q)
	{
		if (list_traverse(q->listHanlde, check_coord_visit, coord) == true)
			return true;
	}
	return false;
}



bool creat_collision_detection_engine(CollisionDtectionEngineHandle **CDEHandle)
{
	return creat_empty_checklist(CDEHandle);
}
bool register_collision_detection_list(CollisionDtectionEngineHandle *CDEHandle, list_t *CDEListHanlde)
{
	checknode_t *e = NULL;
	if (true == make_check_node(&e, CDEListHanlde))
		return InsList_n(CDEHandle, 1, e);
	else
		return false;
}

bool start_collision_detection(CollisionDtectionEngineHandle *CDEHandle, coordinate coord)
{
	return list_traverse((list_t *)CDEHandle, check_node_visit, coord);
}

void destory_collision_detection_engine(CollisionDtectionEngineHandle *CDEHandle)
{
	////
}