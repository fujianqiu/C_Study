// chenfabiao4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	int a, b;
	b = 0;
	while (b++ < 9)
	{
		a = 1;
		int c = 10 - b;
		while (a<c)
		{
			printf("       ");
			a++;
		}
		a = 1;
		while (a <= b)
		{
			printf("%d*%d=%2d ", a, b, a*b);
			a++;
		}
		
		printf("\n");
	}
	getchar();
    return 0;
}

