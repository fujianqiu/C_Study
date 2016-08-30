#include "malloc.h"
#include "string.h"
#include "stdlib.h"
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int stack_elem;
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
stack_elem GetTop(Stack_Sq *stack);
bool Push(Stack_Sq *stack, stack_elem e);
stack_elem Pop(Stack_Sq *stack);
