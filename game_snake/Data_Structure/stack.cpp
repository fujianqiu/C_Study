#include "stdafx.h"
#include "stack.h"
#include "malloc.h"
#include "string.h"
#include "stdlib.h"
#include "labyrinth.h"
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
		stack->top==NULL;
		stack->stack_size = 0;
		return true;
	}
	stack->top = stack->base + stack->stack_size;
	while (stack->top != stack->base)
	{
		stack->top--;
		free(stack->top);
	}
	stack->base==NULL;
	stack->top == NULL;
	stack->stack_size = 0;
	return true;
}
bool ClearStack(Stack_Sq *stack)
{
	if ((stack == NULL)||(stack->base == NULL))
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
		exit (1);
	return stack->top - stack->base;
}
bool GetTop(Stack_Sq *stack,stack_elem *e)
{
	if ((stack == NULL) || (stack->base == NULL) || (e == NULL) || (stack->base==stack->top))
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
	index = stack->top-stack->base;
	if (stack->top >= (stack->base + stack->stack_size))
	{
		stack->base = (stack_elem *)realloc(stack->base, (temp + STACKINCREMENT)*sizeof(stack_elem));
		if (stack->base == NULL)
			return false;
		stack->stack_size = temp + STACKINCREMENT;
		stack->top = stack->base + index;
	}
	stack->base[StackLength(stack)] = e;
	stack->top ++;
	return true;
}
bool Pop(Stack_Sq *stack, stack_elem *e)
{
	if ((stack == NULL) || (stack->base == NULL) || (e == NULL) || (stack->base == stack->top))
		return false;
	e[0] = stack->base[StackLength(stack) - 1];
	stack->top --;
	memset(stack->top, 0, sizeof(stack_elem));
	return true;
}
bool compare(stack_elem elem, stack_elem q)
{
	//if (elem >= q)
		return false;
	//if (elem < q)
	{
		return true;
	}
}
bool PrintfStack(stack_elem elem, stack_elem q)
{
	if (elem.state == WALL)
		printf("#");
	if (elem.state==ROAD)
		printf(" ");
	return false;
}
bool StackTraverse(Stack_Sq *stack, bool visit(stack_elem elem, stack_elem q))
{
	int i;
	int len;
	if ((stack == NULL) || (stack->base == NULL) || (visit == NULL))
		return false;
	len = StackLength(stack);
	for (i = 0; i <len; i++)
	{
		PrintfStack(stack->base[i], stack->base[i]);
		if ((i + 1) % WIDTH == 0)
			printf("\n");
	}
	return true;
}
void stack_test_main()
{
	Stack_Sq *stack;
	//stack_elem gh = 0;
	CreateEmptyStack(&stack);
	
#if 0
	for (int i = 0; i <252; i++)
	{
		Push(stack,i);
		printf("%-3d  len:%-3d  size:%-3d  base:%-10x top:%-10x\n", stack->base[StackLength(stack) - 1],StackLength(stack),stack->stack_size,stack->base,stack->top);
		Pop(stack,&gh);
	}

	int a[5]={0,1,2,3,4};
	printf("%d %d", &a[3] - &a[1], a[0]);

	char *c[] = {
		"enter",
		"new",
		"point",
		"first"};
	//char **cp[]={c+3,c+2,c+1,c};
	//char ***cpp=cp;
	//printf("%s\n",**++cpp);
	//printf("%s\n",*--*++cpp+3);
	//printf("%s\n",*cpp[-2]);
	
	unsigned i = 26165;//十进制转八进制
	int j, k = 1;
	int aak;
	while(k)
	{
		k=i/8;
		j=i%8;
		Push(stack,j);
		//StackTraverse(stack, PrintfStack);
		//printf("\n");
		i = k;
	}
	for(int index=0;index<StackLength(stack);)
	{
		Pop(stack, &aak);
		printf("%d",aak);
	}
#endif
#if 0
	
	StackTraverse(stack,compare);
	StackTraverse(stack,PrintfStack);
	printf("\n---------------------------------------------\n");
	//stack =NULL;
	GetTop(stack,&gh);
	printf("%d", gh);
	printf("\n---------------------------------------------\n");
	Push(stack, 18);
	for (i = 0; i < StackLength(stack); i++)
	{
		printf("%d ", stack->base[i]);
	}
	printf("\n---------------------------------------------\n");
	Pop(stack,&gh);
	printf("%d",gh);
	printf("\n---------------------------------------------\n");
	for (i = 0; i < StackLength(stack); i++)
	{
		printf("%d ", stack->base[i]);
	}
#endif
}