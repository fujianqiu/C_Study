#include "stdafx.h"
#include "CalculatorStack.h"
bool CreateEmptyStack(Stack_Sq **stack)
{
	Stack_Sq *p;
	stack_elem *base;
	if (stack == NULL)
		exit(1);
	p = (Stack_Sq *)malloc(sizeof(Stack_Sq));
	if (p == NULL)
		exit(1);
	base = (stack_elem *)malloc(STACK_INIT_SIZE*sizeof(stack_elem));
	if (base == NULL)
		exit(1);
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
		stack->top = NULL;
		stack->stack_size = 0;
		return true;
	}
	stack->top = stack->base + stack->stack_size;
	while (stack->top != stack->base)
	{
		stack->top--;
		free(stack->top);
	}
	stack->base = NULL;
	stack->top = NULL;
	stack->stack_size = 0;
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
stack_elem GetTop(Stack_Sq *stack)
{
	stack_elem e;
	if ((stack == NULL) || (stack->base == NULL))
		exit(1);
	e= stack->base[StackLength(stack) - 1];
	return e;
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
stack_elem Pop(Stack_Sq *stack)
{
	stack_elem a;
	if ((stack == NULL) || (stack->base == NULL)|| (stack->base == stack->top))
		exit(1);
	stack->top--;
	a = stack->top[0];
	memset(stack->top, 0, sizeof(stack_elem));
	return a;
}
