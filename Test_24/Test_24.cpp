// Test_24.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int main()//��Ŀ����һ�������У�2/1��3/2��5/3��8/5��13/8��21/13...���������е�ǰ20��֮�͡�
{
	int i;
	double a = 2, b = 1,c,sum=0;
	for (i = 0; i < 20; i++)
	{
		sum += a / b;
		c = a;
		a = a + b;
		b = c;
	}
	printf("%.10f\n", sum);
	getchar();
    return 0;
}

