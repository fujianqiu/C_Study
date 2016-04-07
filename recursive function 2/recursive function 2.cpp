// recursive function 2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
int age(int n)
{
	int num;
	if (n == 1)
	{
		return 10;
	}
	else
	{
		num = age(n - 1) + 2;
	}
	return num;
}

int main()
{
	int num = age(5);
	printf("第5个人的年龄是%d岁", num);
	getchar();
    return 0;
}

