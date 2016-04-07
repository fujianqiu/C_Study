// problem set 7.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	int i, j;
	for (i = 1; i < 9; i++)
	{
		for (j = 1; j < 9; j++)
		{
			if ((i +j) % 2 == 0)
			{
				printf("( )");
			}
			else
			{
				printf("   ");
			}
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
	printf("\n");

	int a, b;
	for (a = 0; a<8; a++)
	{
		for (b = 0; b<8; b++)
			if ((a + b) % 2 == 0)
				printf("%c%c", 219, 219);
			else
				printf(" ");
		printf("\n");
	}
	getchar();
    return 0;
}

