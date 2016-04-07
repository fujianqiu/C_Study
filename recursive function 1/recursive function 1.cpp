// recursive function 1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
int getpeachnumber(int n)
{
	int num;
	if (n==10)
	{
		return 1;
	}
	else
	{
		num = getpeachnumber(n+1)*2+2;
		printf("第%d天所剩桃子%d个\n", n, num);
	}
	return num;
}

int main()
{
	int num = getpeachnumber(1);
	printf("猴子第一天摘了:%d个桃子。\n", num);
	getchar();
    return 0;
}

