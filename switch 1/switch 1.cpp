// switch 1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int main()
{
	int grade,score;
	score = 87;
	grade =score/10;
	switch (grade)
	{
	case 6:printf("�ȼ�C"); break;
	case 10:
	case 8:printf("�ȼ�B");
	case 9:printf("�ȼ�A"); 
	case 7:
	default:printf("�ȼ�D"); break;
	}
	getchar();
    return 0;
}

