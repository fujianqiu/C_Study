// sanmu yunsuan1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	float money;
	float price;
	money = 12;
	price = 11.5;
	printf("小明能不能打车回家：%c\n", money >= price ?'y' : 'n');
	getchar();
    return 0;
}

