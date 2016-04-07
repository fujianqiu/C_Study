// problem set 2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	long int bonus, i;
	scanf("%d", &i);
	if (i <= 100000)
	{
		bonus = i*0.1;
	}
	else if (i > 100000, i <= 200000)
	{
		bonus = 10000 + (i - 100000)*0.075;
	}
	else if (i >200000, i <= 400000)
	{
		bonus = 10000 + 7500 + (i - 200000)*0.05;
	}
	else if (i >400000, i <= 600000)
	{
		bonus = 10000 + 7500 + 10000 + (i - 400000)*0.03;
	}
	else if (i >600000, i <= 1000000)
	{
		bonus = 10000 +7500 + 10000 + 6000 + (i - 600000)*0.015;
	}
	else
	{
		bonus = 10000 + 7500 + 10000 + 6000 + 6000 + (i - 1000000)*0.001;
	}
	printf("奖金：%d\n", bonus);
	getchar();
	getchar();
    return 0;
}

