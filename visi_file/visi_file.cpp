// visi_file.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "stdlib.h"

int main()
{
	FILE *fp;
	char ch;
	fp = fopen("f;\\project\\TestForC\\1.txt", "r");
	if ((fp = fopen("f;\\project\\TestForC\\1.txt" , "r")) == NULL)
	{
		printf("not open");
		getchar();
		exit(1);
	}
	while ((ch = fgetc(fp)) != EOF) /* ���ļ���һ�ַ�����ʾ����Ļ*/
	{
		putchar(ch);
	}
	fclose(fp);
	getchar();
	return 0;
}

