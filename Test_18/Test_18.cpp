// Test_18.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "math.h"

int main()//题目：求s=a+aa+aaa+aaaa+aa...a的值，其中a是一个数字。例如2+22+222+2222+22222(此时 共有5个数相加)，几个数相加有键盘控制。
{
	int a, s=0, i,j, num,b=0;
	printf("请输入相加数a的大小\n");
	scanf("%d", &a);
	printf("请输入相加项的个数\n");
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

