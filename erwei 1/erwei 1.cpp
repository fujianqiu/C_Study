// erwei 1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	int a[9][9];

	for (int index = 0; index < 9; index++)
	{
		for (int indexj = 0; indexj < 9; indexj++)
		{
			a[index][indexj] = (index + 1)*(indexj + 1);
		}

	}

	for (int index = 0; index < 9; index++)
	{
		for (int indexj = 0; indexj < 9; indexj++)
		{
			printf("%3d", a[index][indexj] );
		}
		printf("\n");
	}

	getchar();

	
		for (int indexj = 8; indexj >=0; indexj--)
		{
			for (int index = 0; index < 9; index++)
			{
				printf("%3d", a[indexj][index]);
			}
			printf("\n");
		}

	getchar();
    return 0;
}

