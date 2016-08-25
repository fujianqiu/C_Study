// Binary_Tree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "malloc.h"
#include "stdlib.h"
#include "string.h"
#include "Tree_stack.h"
#include "Binary_Tree.h"

/*************************************************/
BiTNode *CreateBiTreeNode(TElemType e)
{
	BiTNode *p;
	p = (BiTNode *)malloc(sizeof(BiTNode));
	if (p == NULL)
		exit(1);
	p->data = e;
	p->lchild = NULL;
	p->rchild = NULL;
	return p;
}
bool CreateTree(BiTNode **root, char *c, int len_of_c)
{
	if (root == NULL || c == NULL || len_of_c<=0)
		return false;
	BiTNode **ptr;
	int i=0;
	ptr = (BiTNode **)malloc(len_of_c*sizeof(BiTNode *));
	if (ptr == NULL)
		exit(1);
	while (i<len_of_c)
		ptr[i++] = CreateBiTreeNode(c[i]);
	i = 0;
	while (1)
	{
 		if (((2 * i + 1)>=len_of_c))
			break;
		ptr[i]->lchild = ptr[(2 * i + 1)];
		if (((2 * i + 2)>=len_of_c))
			break;
		ptr[i]->rchild = ptr[(2 * i + 2)];
		i++;
	}
	*root = ptr[0];
	free(ptr);
	return true;
}
bool PrintElement(TElemType e)
{
	printf("%c", e);
	return true;
}
bool PreOrderTraverse(BiTNode *root, bool(*Visit)(TElemType e))//先序遍历
{
	if (root)
	{
		if (Visit(root->data))
		if (PreOrderTraverse(root->lchild,Visit))
		if (PreOrderTraverse(root->rchild, Visit))
			return true;
		return false;
	}
	return true;
}
bool InOrderTraverse(BiTNode *root, bool(*Visit)(TElemType e))//中序遍历
{
	if (root)
	{
		if (InOrderTraverse(root->lchild, Visit))
		if (Visit(root->data))
		if (InOrderTraverse(root->rchild, Visit))
			return true;
		return false;
	}
	return true;
}
bool PostOrderTraverse(BiTNode *root, bool(*Visit)(TElemType e))//后序遍历
{
	if (root)
	{
		if (PostOrderTraverse(root->lchild, Visit))
		if (PostOrderTraverse(root->rchild, Visit))
		if (Visit(root->data))
			return true;
		return false;
	}
	return true;
}
bool LevelOrderTraverse(BiTNode *root, bool(*Visit)(TElemType e))//层序遍历
{
	Stack_Sq *stack;
	int i= 0;
	if (root == NULL || Visit == NULL)
		return false;
	CreateEmptyStack(&stack);
	Push(stack, root);
	do
	{
		if (stack->base[i]->lchild){
			Push(stack, stack->base[i]->lchild);
		}
		if (stack->base[i]->rchild){
			Push(stack, stack->base[i]->rchild);
		}
		i++;
	} while (i!= StackLength(stack) - 1);
	for (i = 0; i < StackLength(stack);i++)
		Visit(stack->base[i]->data);
	DestroyStack(stack);
	return true;
}
bool InOrderTraverseStack(BiTNode *root, bool(*Visit)(TElemType e))
{
	Stack_Sq *stack;
	stack_elem p;
	if (root == NULL || Visit == NULL)
		return false;
	CreateEmptyStack(&stack);
	Push(stack, root);
	while (!StackEmpty(stack))
	{
		while (GetTop(stack, &p) && p)
			Push(stack, p->lchild);
		Pop(stack, &p);
		if (!StackEmpty(stack))
		{
			Pop(stack, &p);
			if (!Visit(p->data))
				return false;
			Push(stack, p->rchild);
		}
	}
	return true;
}
int _tmain(int argc, _TCHAR* argv[])
{
	BiTNode *root;
	
	char c[] = "123456789";
	CreateTree(&root, c, strlen(c));
	PreOrderTraverse(root, PrintElement);
	printf("\n");
	InOrderTraverse(root, PrintElement);
	printf("\n");
	PostOrderTraverse(root, PrintElement);
	printf("\n");
	InOrderTraverseStack(root, PrintElement);
	printf("\n");
	LevelOrderTraverse(root, PrintElement);
	getchar();
	return 0;
}
