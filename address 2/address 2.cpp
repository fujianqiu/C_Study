// address 2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct INFO
{
	int a;
	char b;
	double c;
};
int main()
{
	int *p;
	char *p1;
	float *p2;
	double *p3;
	struct INFO *p4;   //struct INFO类型为结构体类型 我们将会在后面的章节中讲解
	void *p5;
	printf("int point size is :%d\n", sizeof(p));
	printf("char point size is :%d\n", sizeof(p1));
	printf("float point size is :%d\n", sizeof(p2));
	printf("double point size is :%d\n", sizeof(p3));
	printf("struct point size is :%d\n", sizeof(p4));
	printf("void point size is :%d\n", sizeof(p5));
	getchar();
    return 0;
}

