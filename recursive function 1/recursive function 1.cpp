// recursive function 1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
int getpeachnumber(int n)
{
	int num;
	if (n==10)
	{
		return 1;
	}
	else
	{
		num = getpeachnumber(n+1)*2+2;
		printf("��%d����ʣ����%d��\n", n, num);
	}
	return num;
}

int main()
{
	int num = getpeachnumber(1);
	printf("���ӵ�һ��ժ��:%d�����ӡ�\n", num);
	getchar();
    return 0;
}

