// for 1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int main()
{
	int sum, num;
	for (sum = 0, num = 0; num <= 100&&sum <= 100; num++, sum++)
	{
		sum += num;
		printf("num=%d,sum=%d\n", num, sum);
	}
	getchar();
    return 0;
}

