// problem set 3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "math.h"


int main()
{
	int num1,num2;
	int a[9999],b[9999];
	printf("答案是：");
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
		x = sqrt(i + 100);/*x为加上100后开方后的结果*/
		y = sqrt(i + 268);/*y为再加上168后开方后的结果*/
		if (x*x == i + 100 && y*y == i + 268)/*如果一个数的平方根的平方等于该数，这说明此数是完全平方数*/
			printf("\n%ld\n", i);
	}
	getchar();
    return 0;
}

