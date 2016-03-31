// chengfabiao 2.cpp : 定义控制台应用程序的入口点。
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

