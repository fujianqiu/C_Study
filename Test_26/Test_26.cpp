// Test_26.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
int product(int n)
{
	if (n == 1)
		return 1;
	else
		return n*product(n - 1);
}

int main()//��Ŀ�����õݹ鷽����5!��
{
	printf("%d", product(5));
	getchar();
    return 0;
}

