// chengfabiao.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int main()
{
	int a, b;
	a = 1;
	b =0;
	while (b++ < 9)
	{
		

		a = 1;
		while (a <= b)
		{
			printf("%2dX%2d=%2d ", b, a, a*b);
			a++;
		}



		printf(" \n");
	}
	getchar();
    return 0;
}

