// if-eles 2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	int sale = 120;
	int year =3;
	if (sale>=100)
	{
		if (year >= 2)
		{
			printf("获得优秀员工奖");
		}
		else
		{
			printf("获得表扬");
		}
	}
	else
	{
		printf("很遗憾，期望你再接再厉");
	}
	getchar();
    return 0;
}

