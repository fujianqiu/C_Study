#ifndef __TSTACK_
#define __TSTACK_
#include "Binary_Tree.h"
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
//typedef Pelem stack_elem;
typedef struct
{
	stack_elem *top;
	stack_elem *base;
	int stack_size;
}Stack_Sq;
bool CreateEmptyStack(Stack_Sq **stack);
bool DestroyStack(Stack_Sq *stack);
bool ClearStack(Stack_Sq *stack);
int StackLength(Stack_Sq *stack);
bool GetTop(Stack_Sq *stack, stack_elem *e);
bool Push(Stack_Sq *stack, stack_elem e);
bool Pop(Stack_Sq *stack, stack_elem *e);
bool StackEmpty(Stack_Sq *stack);
#endif