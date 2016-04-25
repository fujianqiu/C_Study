// Test_24.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()//题目：有一分数序列：2/1，3/2，5/3，8/5，13/8，21/13...求出这个数列的前20项之和。
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

