// Test_20.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "math.h"

#define H 100;
double height(int n)
{
	return pow(0.5, n)*H;
}
int main()
{
	double l, sum = 0;
	int i;
	for (i = 0; i <=9; i++)//��Ŀ��һ���100�׸߶��������£�ÿ����غ�����ԭ�߶ȵ�һ�룻�����£������� ��10�����ʱ�������������ף���10�η�����ߣ�
	{
		sum += 2*height(i);
	}
	l = sum - height(0);
	printf("��10�����ʱ��������%.10f��,��10�η����߶�%.10f��", l, height(10));
	getchar();
    return 0;
}

