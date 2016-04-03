// switch 1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	int grade,score;
	score = 87;
	grade =score/10;
	switch (grade)
	{
	case 6:printf("等级C"); break;
	case 10:
	case 8:printf("等级B");
	case 9:printf("等级A"); 
	case 7:
	default:printf("等级D"); break;
	}
	getchar();
    return 0;
}

