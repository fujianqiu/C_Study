// Test_23.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int main()
{
	int i,j,k=0;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j <= 2 * i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = 3; i <=4; i++)
	{
		for (j = 1; j <=2*i;j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (j = 0; j <= 5; j++)
	{
		printf("*");
	}
	printf("\n");
	for (i = 1; i >=0; i--)
	{
		for (j = 0; j <= 2 * i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	getchar();
    return 0;
}

