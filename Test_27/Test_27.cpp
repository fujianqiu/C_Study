// Test_27.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define N 5
char reverse_print(int n)
{
	char a;
	if (n == 1) 
	{
		scanf("%c", &a);
		printf("%c",a);
		return 0;
	}
	else
	{
		scanf("%c", &a);
		reverse_print(n-1);
		printf("%c",a);
		return 0;
	}
}

int main()//题目：利用递归函数调用方式，将所输入的5个字符，以相反顺序打印出来。
{
	reverse_print(N);
	getchar();
	getchar();
    return 0;
}

