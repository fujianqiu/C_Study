// for 5.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int main()
{
	int n,m, k,i=1;
	int num_n=0,num_m=0;                  //��Ŀ����������������m��n���������Լ������С��������
	int a_max,b_max;
	int a[1000];
	int b[1000];
	scanf("%d%d", &n,&m);
	for (k = 2; k < n / k; k++)
		if (n%k == 0)
		{
			n = n / k;
			printf("%d*", k);
			a[num_n] = k;
			num_n++;
			a_max = num_n + 1;
			a[a_max] = n;
			k = 2;
		}
	
	printf("%d\n",n);
	for (k = 2; k < m / k; k++)         //���޸�
		if (m%k == 0)
		{
			m = m / k;
			printf("%d*", k);
			b[num_m] = k;
			num_m++;
			b_max = num_m + 1;
			a[b_max] = n;
			k = 2;
		}
	printf("%d\n", m);
	for (num_n = 0; num_n <= a_max; num_n++)
		for (num_m = 0; num_m <= b_max; num_m++)
			if (a[num_n] = b[num_m])
			{
				printf("��С��������%d", a[num_n]);
				break;
			}
	getchar();
	getchar();
    return 0;
}

