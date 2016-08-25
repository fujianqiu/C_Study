#include "stdafx.h"
#include "malloc.h"
#include "string.h"
#include "stdlib.h"
#include "Tree_stack.h"
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
bool CreateEmptyStack(Stack_Sq **stack)
{
	Stack_Sq *p;
	stack_elem *base;
	if (stack == NULL)
		return false;
	p = (Stack_Sq *)malloc(sizeof(Stack_Sq));
	if (p == NULL)
		return false;
	base = (stack_elem *)malloc(STACK_INIT_SIZE*sizeof(stack_elem));
	if (base == NULL)
		return false;
	memset(base, 0, STACK_INIT_SIZE*sizeof(stack_elem));
	p->base = base;
	p->top = base;
	p->stack_size = STACK_INIT_SIZE;
	(*stack) = p;
	return true;
}
bool DestroyStack(Stack_Sq *stack)
{
	if (stack == NULL)
		return false;
	if (stack->base == NULL)
	{
		free(stack);
		return true;
	}
	free(stack->base);
	free(stack);
	return true;
}
bool ClearStack(Stack_Sq *stack)
{
	if ((stack == NULL) || (stack->base == NULL))
		return false;
	memset(stack->base, 0, stack->stack_size*sizeof(stack_elem));
	stack->top = stack->base;
	return true;
}
bool StackEmpty(Stack_Sq *stack)
{
	if ((stack == NULL) || (stack->base == NULL))
		return false;
	if (stack->base == stack->top)
		return true;
	return false;
}
int StackLength(Stack_Sq *stack)
{
	if ((stack == NULL) || (stack->base == NULL))
		exit(1);
	return stack->top - stack->base;
}
bool GetTop(Stack_Sq *stack, stack_elem *e)
{
	if ((stack == NULL) || (stack->base == NULL) || (e == NULL) || (stack->base == stack->top))
		return false;
	e[0] = stack->base[StackLength(stack) - 1];
	return true;
}
bool Push(Stack_Sq *stack, stack_elem e)
{
	int temp;
	int index;
	if ((stack == NULL) || (stack->base == NULL))
		return false;
	temp = stack->stack_size;
	index = stack->top - stack->base;
	if (stack->top >= (stack->base + stack->stack_size))
	{
		stack->base = (stack_elem *)realloc(stack->base, (temp + STACKINCREMENT)*sizeof(stack_elem));
		if (stack->base == NULL)
			return false;
		stack->stack_size = temp + STACKINCREMENT;
		stack->top = stack->base + index;
	}
	stack->base[StackLength(stack)] = e;
	stack->top++;
	return true;
}
bool Pop(Stack_Sq *stack, stack_elem *e)
{
	if ((stack == NULL) || (stack->base == NULL) || (e == NULL) || (stack->base == stack->top))
		return false;
	e[0] = stack->base[StackLength(stack) - 1];
	stack->top--;
	memset(stack->top, 0, sizeof(stack_elem));
	return true;
}