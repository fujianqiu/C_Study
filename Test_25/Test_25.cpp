// Test_25.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
int item(int n) 
{
	int i, j=1;
	for (i = 1; i <= n; i++)
	{
		j = j*i;
	}
	return j;
}


int main()//��Ŀ����1+2!+3!+...+20!�ĺ�
{
	int i, j,sum=0;
	for (i = 1; i <=20; i++)
	{
		sum += item(i);
	}
	printf("%d\n", sum);
	getchar();
    return 0;
}

