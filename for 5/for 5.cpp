// for 5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
int Prime_factors(int *addr,int N)
{
	
	int Prime_max,k,i=0;
	for (k = 2; k < N; k++)
	if (N%k == 0)
	{
		N = N / k;
		*(addr+i) = k;
		i++;
		k=1;
	}
	*(addr + i) = N;
	return *addr;
}
int findgreatest_common_factor(int a_max,int b_max)
{
	int a[50];
	int b[50];
	int num_n = 0, num_m = 0;
	int loop = 1;
	for (num_n = 0; num_n<=50; num_n++)
	{
		for (num_m = 0; num_m<=0; num_m++)
		{
			if (a[num_n] == b[num_m])
			{
				printf("最小公因数：%d\n", b[num_m]);         //合并2个数组a[n] b[m] ,
				loop = 1;
				break;
			}
		}
		if (loop)
			break;                                            //题目：输入两个正整数m和n，求其最大公约数和最小公倍数。
	}
	return b[num_m];
}

int main()
{
	int n, m;
	printf("请输入两个[1,2147483647]内的整数\n");
	scanf("%d%d", &n, &m);
	if (n < 0 || m < 0 || n>2147483647 | m>2147483647)
	{
		printf("error");
	}
	else
	{
		int c[50];
		int d[50];
		Prime_factors(n);
		Prime_factors(m);
	}

	getchar();
	getchar();
    return 0;
}

