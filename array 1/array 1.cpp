// array 1.cpp : �������̨Ӧ�ó������ڵ㡣
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
	printf("���Գɼ���������%d %d %d %d %d %d %d %d %d %d\n", score[0], score[1], score[2], score[3], score[4], score[5], score[6], score[7], score[8], score[9] );
	return 0;
}

int main()
{
	int score[10] = { 67,98,75,63,82,79,81,91,66,84 };
	sum(score);
	highest(score);
	lowest(score);
	average(score);
	printf("�ܷ֣�%d\n", sum(score));
	printf("��߷֣�%d\n", highest(score));
	printf("��ͷ֣�%d\n", lowest(score));
	printf("ƽ���֣�%.1f\n", average(score));
	descending(score);
	getchar();
    return 0;
}

