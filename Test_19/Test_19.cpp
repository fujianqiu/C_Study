// Test_19.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
int sumdivisor(int num) 
{
	int k, sum = 0;
	for (k =1; k <num; k++)
		if (num%k == 0)
		{
			sum += k;
		}
	return sum;
}


int main()//��Ŀ��һ�������ǡ�õ�����������֮�ͣ�������ͳ�Ϊ��������������6=1��2��3.��� �ҳ�1000���ڵ�����������
{
	int num;
	for (num = 2; num <=1000; num++)
	{
		if(num== sumdivisor(num))
			printf("%d\n", sumdivisor(num));
	}
	getchar();
    return 0;
}

