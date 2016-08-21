#ifndef __STACK_
#define __STACK_
#include "malloc.h"
#include "string.h"
#include "stdlib.h"

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
//typedef struct elem_n
//{
//	int a;
//}stack_elem;
typedef struct coord_
{
	int x;
	int y;
}coord;
typedef struct map_node_
{
	coord xy;
	int state;
}map_node,stack_elem;
typedef struct
{
	stack_elem *top;
	stack_elem *base;
	int stack_size;
}Stack_Sq;
bool CreateEmptyStack(Stack_Sq **stack);
bool DestroyStack(Stack_Sq *stack);
bool ClearStack(Stack_Sq *stack);
bool StackEmpty(Stack_Sq *stack);
int StackLength(Stack_Sq *stack);
bool GetTop(Stack_Sq *stack, stack_elem *e);
bool Push(Stack_Sq *stack, stack_elem e);
bool Pop(Stack_Sq *stack, stack_elem *e);
void stack_test_main();
bool PrintfStack(stack_elem elem, stack_elem q);
bool StackTraverse(Stack_Sq *stack, bool visit(stack_elem elem, stack_elem q));
#endif