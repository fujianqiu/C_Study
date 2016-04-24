// for 4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
/*题目：将一个正整数分解质因数。例如：输入90,打印出90=2*3*3*5。*/

int main()
{
	int n, k;
	scanf("%d", &n);
	printf("%d=",n);
	loop:for (k = 2; k < n; k++)
		if (n%k == 0)
		{
			n = n / k;
			printf("%d*",k);
			goto loop;
		}
	printf("%d",n);
	getchar();
	getchar();
    return 0;
}

