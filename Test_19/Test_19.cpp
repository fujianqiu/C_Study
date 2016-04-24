// Test_19.cpp : 定义控制台应用程序的入口点。
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


int main()//题目：一个数如果恰好等于它的因子之和，这个数就称为“完数”。例如6=1＋2＋3.编程 找出1000以内的所有完数。
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

