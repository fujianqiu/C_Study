// array 1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define N 10
int sum(int score[N])
{
	int i, j = 0;
	for (i = 0; i<10; i++)
	{
		j += score[i];
	}
	return j;
}

int highest(int score[N])
{
	int i, j;
	for (i = 0; i<9; i++)
	{
		if (score[i]>score[i + 1])
		{
			j = score[i];
			score[i] = score[i + 1];
			score[i + 1] = j;
		}
	}
	return score[9];
}

int lowest(int score[N])
{
	int i, j;
	for (i = 0; i<9; i++)
	{
		if (score[i]>score[i + 1])
		{
			j = score[i];
			score[i] = score[i + 1];
			score[i + 1] = j;
		}
	}
	return score[0];
}

double average(int score[N])
{
	int i;
	double j;
	for (i = 0; i<10; i++)
	{
		j = (score[0] + score[1] + score[2] + score[3] + score[4] + score[5] + score[6] + score[7] + score[8] + score[9]) / 10;
	}
	return j;
}

int descending(int score[N])
{
	int i,j, value;
	for (j = 9; j>=0; j--)
	{
		for (i = 0; i<j; i++)
		{
			if (score[i] > score[i + 1])
			{
				value = score[i];
				score[i] = score[i + 1];
				score[i + 1] = value;
			}
		}
	}
	printf("考试成绩升序排序：%d %d %d %d %d %d %d %d %d %d\n", score[0], score[1], score[2], score[3], score[4], score[5], score[6], score[7], score[8], score[9] );
	return 0;
}

int main()
{
	int score[10] = { 67,98,75,63,82,79,81,91,66,84 };
	sum(score);
	highest(score);
	lowest(score);
	average(score);
	printf("总分：%d\n", sum(score));
	printf("最高分：%d\n", highest(score));
	printf("最低分：%d\n", lowest(score));
	printf("平均分：%.1f\n", average(score));
	descending(score);
	getchar();
    return 0;
}

