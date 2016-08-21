#ifndef __STACK_
#define __STACK_
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define PATH_SHOW '1'
#include "public.h"
typedef struct direction_
{
	int right;
	int up;
	int left;
	int down;
}_direction;
typedef struct _stack_elem
{
	coord xy;
	_direction direction;
}stack_elem,path_node;
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
bool Push(Stack_Sq *stack, coord xy);
bool Pop(Stack_Sq *stack);
bool FirstStep(Stack_Sq *stack, coord xy);
bool InPath(Stack_Sq *stack, coord xy);
bool OutPath(Stack_Sq *stack);
#endif