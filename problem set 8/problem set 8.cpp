// problem set 8.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

int main()
{
	long f1, f2;
	int i;
	f1 = f2 = 1;
	for (i = 1; i <= 20; i++)
	{
		printf("%-12ld %-12ld", f1, f2);
		if (i % 2 == 0) printf("\n");/*���������ÿ���ĸ�*/
		f1 = f1 + f2; /*ǰ�����¼�������ֵ����������*/
		f2 = f1 + f2; /*ǰ�����¼�������ֵ����������*/
	}
	getchar();
    return 0;
}
