// Test_21.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
int getPeachNumber(int n)
{
	int num;    //定义所剩桃子数
	if (n == 10)
	{
		return 1;
	}
	else
	{
		num = (getPeachNumber(n + 1) + 1) * 2;
		printf("第%d天所剩桃子%d个\n", n, num);//题目：猴子吃桃问题：猴子第一天摘下若干个桃子，当即吃了一半，还不瘾，又多吃了一个
	}                                          //第二天早上又将剩下的桃子吃掉一半，又多吃了一个。以后每天早上都吃了前一天剩下
	return num;                                //的一半零一个。到第10天早上想再吃时，见只剩下一个桃子了。求第一天共摘了多少。
}
int main()
{
	int num = getPeachNumber(1);
	printf("猴子第一天摘了:%d个桃子。\n", num);
	getchar();
    return 0;
}

