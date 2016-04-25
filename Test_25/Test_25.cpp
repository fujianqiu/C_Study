// Test_25.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
int item(int n) 
{
	int i, j=1;
	for (i = 1; i <= n; i++)
	{
		j = j*i;
	}
	return j;
}


int main()//题目：求1+2!+3!+...+20!的和
{
	int i, j,sum=0;
	for (i = 1; i <=20; i++)
	{
		sum += item(i);
	}
	printf("%d\n", sum);
	getchar();
    return 0;
}

