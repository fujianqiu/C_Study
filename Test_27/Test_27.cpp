// Test_27.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#define N 5
char reverse_print(int n)
{
	char a;
	if (n == 1) 
	{
		scanf("%c", &a);
		printf("%c",a);
		return 0;
	}
	else
	{
		scanf("%c", &a);
		reverse_print(n-1);
		printf("%c",a);
		return 0;
	}
}

int main()//��Ŀ�����õݹ麯�����÷�ʽ�����������5���ַ������෴˳���ӡ������
{
	reverse_print(N);
	getchar();
	getchar();
    return 0;
}

