// Test_26.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
int product(int n)
{
	if (n == 1)
		return 1;
	else
		return n*product(n - 1);
}

int main()//题目：利用递归方法求5!。
{
	printf("%d", product(5));
	getchar();
    return 0;
}

