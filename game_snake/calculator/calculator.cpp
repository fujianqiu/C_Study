// calculator.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "CalculatorStack.h"
#include "math.h"
#define NUM 1
#define SIG 2
typedef struct node_
{
	int value,tag;
}node;
char Priority(char a, char b)
{
	int i, j;
	char priority[][7] =
	{
		{ '>', '>', '<', '<', '<', '>', '>' },
		{ '>', '>', '<', '<', '<', '>', '>' },
		{ '>', '>', '>', '>', '<', '>', '>' },
		{ '>', '>', '<', '<', '<', '>', '>' },
		{ '<', '<', '<', '<', '<', '=', '.' },
		{ '>', '>', '>', '>', '.', '>', '>' },
		{ '<', '<', '<', '<', '<', '.', '=' }
	};
	switch (b)
	{
	case '+':j = 0; break;
	case '-':j = 1; break;
	case '*':j = 2; break;
	case '/':j = 3; break;
	case '(':j = 4; break;
	case ')':j = 5; break;
	case '=':j = 6; break;
	default:return '.';
	}
	switch (a)
	{
	case '+':i = 0; break;
	case '-':i = 1; break;
	case '*':i = 2; break;
	case '/':i = 3; break;
	case '(':i = 4; break;
	case ')':i = 5; break;
	case '=':i = 6; break;
	default:return '.';
	}
	return priority[i][j];
}
int calculat(int a,int b,char c)
{
	if (c == '+')
		return a + b;
	if (c == '-')
		return a -b;
	if (c == '*')
		return a * b;
	if (c == '/')
		return a / b;
}
bool run(Stack_Sq *OPED, Stack_Sq *OPER, node *r)//OPED  运算数  OPER  运算符  "(0-9)+5#"
{
	int i = 0;
	int a, b;
	char c;
	stack_elem e;
	char ch;
	if (r == NULL)
		return false;
	StackEmpty(OPED);
	StackEmpty(OPER);
	Push(OPER, '=');
	while (r[i].tag == NUM || r[i].tag==SIG)
	{
		if (r[i].tag == NUM)
		{
			Push(OPED, r[i++].value);
		}
		else
		{
			switch (Priority(GetTop(OPER), r[i].value))
			{
			case '<':Push(OPER, r[i++].value); 
				break;
			case '=':Pop(OPER); i++;
				break;
			case '>':
				c = Pop(OPER);
 				a = Pop(OPED);
				b = Pop(OPED);
				Push(OPED, calculat(b, a, c));
				break;
			default:return false;
			}
		}
	}
	return true;
}
#if 1
int mkint(char *c,int len)
{
	int i = 0;
	int x;
	int a =0;
	int b = len;
	if (c == NULL||len==0)
		return -1;
	while (len--)
	{
		x = c[i++]-48;
		a += x*pow(10.0,b-i);
	}
	return a;
}
node *char_int(char *r, int len)
{
	node *a;
	int i = 0;
	int j;
	int k=0;
	char *temp;
	if (r == NULL||len==0)
		return false;
	a = (node *)malloc(2*len*sizeof(node));
	if (a == NULL)
		return NULL;
	memset(a, 0, len*sizeof(node));
	while (r[i])
	{
		if (r[i] >= '0'&& r[i] <= '9')
		{
			if (i > 0 && r[i - 1] == '/'&&r[i] == '0')
				return NULL;
			j = 1;
			temp = r + i++;
			while (r[i] >= '0'&& r[i] <= '9')
			{
				i++; j++;
			}
			a[k].value = mkint(temp, j);
			a[k++].tag = NUM;
		}
		if (!r[i])
			break;
		if (i > 0 && (r[i - 1] == '+' || r[i - 1] == '-' || r[i - 1] == '*' || r[i - 1] == '/' || r[i - 1] == '=') && (r[i] != '(' && (r[i]< '0' || r[i] >'9')))
			return NULL;
		if (i > 0 && (r[i - 1] == '(') && (r[i] != '-' && (r[i]< '0' || r[i] >'9')))
			return NULL;
		if (i > 0 && r[i - 1] == '('&&r[i] == '-')
		{
			a[k].value = 0;
			a[k++].tag = NUM;
		}
		a[k].value = (int)r[i++];
		a[k++].tag = SIG;
	}
	return a;
}
#endif

int _tmain(int argc, _TCHAR* argv[])
{
	node *a;
	Stack_Sq *OPED, *OPER;
	char r[] = "(8-9)+5*(-5)/5+(-6+8)*5+3=";
	//char r[] = "()(";
	//char r[] = "48*59-48/*4=";
	//char r[] = "48*59-48/*4=";
	a = char_int(r, strlen(r));
	while (a)
	{
		CreateEmptyStack(&OPED);
		CreateEmptyStack(&OPER);
		if (!run(OPED, OPER, a))
			break;
		if (!StackEmpty(OPER) || StackEmpty(OPED))
			break;
		printf("%d", GetTop(OPED));
		free(a);
		getchar();
		return 0;
	}
	printf("ERROR\n");
	free(a);
	getchar();
	return 0;
}

