// if-else 1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	int year = 2014;
	if (year % 4 == 0)
	{
		printf("今年是闰年");
	}
	else
	{
		printf("今年是平年");
	}
	getchar();
    return 0;
}

