// chengfabiao 2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int main()
{
	int a, b;
	a = 10;
	b = 9;
	while (a-->1)
	{
		b = 9;
		while (a <= b)
		{
			
			printf("%2dX%2d=%2d ", b, a, b*a);
			b--;
		}
		printf(" \n");
	}
	getchar();
    return 0;
}

