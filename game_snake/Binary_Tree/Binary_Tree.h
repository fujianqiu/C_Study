#ifndef __BITREE_
#define __BITREE_
#define LEFT 0
#define RIGHT 1
typedef char TElemType;
typedef struct BiTNode_
{
	TElemType data;
	struct BiTNode_ *lchild, *rchild;
}BiTNode, *stack_elem;
#endif