// problem set 3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "math.h"


int main()
{
	int num1,num2;
	int a[9999],b[9999];
	printf("���ǣ�");
	for (int c = 0; c <= 9999; c++)
	{
		for (int d = 0; d < c; d++)
		{
			a[c] = (c + 1)*(c + 1);
			b[d] = (d + 1)*(d + 1);
			num1 = a[c] - b[d];
			if (num1 == 168&&b[d]>100)
			{
				num2 =b[d] - 100;
				printf("%d  ",num2);
			}
		}
	}



	long int i, x, y, z;
	for (i = 1; i < 100000; i++)
	{
		x = sqrt(i + 100);/*xΪ����100�󿪷���Ľ��*/
		y = sqrt(i + 268);/*yΪ�ټ���168�󿪷���Ľ��*/
		if (x*x == i + 100 && y*y == i + 268)/*���һ������ƽ������ƽ�����ڸ�������˵����������ȫƽ����*/
			printf("\n%ld\n", i);
	}
	getchar();
    return 0;
}

