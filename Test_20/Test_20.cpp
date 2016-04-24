// Test_20.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "math.h"

#define H 100;
double height(int n)
{
	return pow(0.5, n)*H;
}
int main()
{
	double l, sum = 0;
	int i;
	for (i = 0; i <=9; i++)//题目：一球从100米高度自由落下，每次落地后反跳回原高度的一半；再落下，求它在 第10次落地时，共经过多少米？第10次反弹多高？
	{
		sum += 2*height(i);
	}
	l = sum - height(0);
	printf("第10次落地时，共经过%.10f米,第10次反弹高度%.10f米", l, height(10));
	getchar();
    return 0;
}

