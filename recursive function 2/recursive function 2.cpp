// recursive function 2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
int age(int n)
{
	int num;
	if (n == 1)
	{
		return 10;
	}
	else
	{
		num = age(n - 1) + 2;
	}
	return num;
}

int main()
{
	int num = age(5);
	printf("��5���˵�������%d��", num);
	getchar();
    return 0;
}

