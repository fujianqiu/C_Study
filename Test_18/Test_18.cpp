// Test_18.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "math.h"

int main()//��Ŀ����s=a+aa+aaa+aaaa+aa...a��ֵ������a��һ�����֡�����2+22+222+2222+22222(��ʱ ����5�������)������������м��̿��ơ�
{
	int a, s=0, i,j, num,b=0;
	printf("�����������a�Ĵ�С\n");
	scanf("%d", &a);
	printf("�����������ĸ���\n");
	scanf("%d", &num);
	int c = num;
	for (j = 1; j <= num;j++)
	{
		for (i =c; i > 0; i--)
		{
			b = pow(10, i-1)*a;
			s = s + b;
			b = 0;
		}
		c--;
	}
	printf("s=%d", s);
	getchar();
	getchar();
    return 0;
}

