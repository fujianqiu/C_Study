// address 2.cpp : �������̨Ӧ�ó������ڵ㡣
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
	struct INFO *p4;   //struct INFO����Ϊ�ṹ������ ���ǽ����ں�����½��н���
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

