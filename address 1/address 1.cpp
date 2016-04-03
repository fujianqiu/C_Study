// address 1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	int i;
	int a[10] = { 1,2,3,4,5,6,7,8,9,0 };
	char b[10] = { 'c','l','a','n','g','u','a','g','e' };
	for (i = 0; i<10; i++)
	{
		printf("int Address:0x%x,Value:%d\n", &a[i], a[i]);
	}
	printf("\n");
	for (i = 0; i<10; i++)
	{
		printf("char Address:0x%x,Value :%c\n", &b[i], b[i]);
	}
	printf("\n");
	printf("\n");

	int num = 2014;
	int *p = &num;
	printf("num Address = 0x%x,num=%d\n", &num, num);
	printf("p = 0x%x,*p=%d\n", p, *p);
	printf("%d\n", *&num);
	getchar();
    return 0;


}

