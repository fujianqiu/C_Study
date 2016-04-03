// continue 1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	int i, sum;
	for (i = 1, sum = 0; i <= 20; i++)
	{
		if (i % 3 == 0)
		{
			continue;
		}
		sum += i;
	}
	printf("sum=%d\n",sum);
	getchar();
    return 0;
}

 