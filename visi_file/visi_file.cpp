// visi_file.cpp : 定义控制台应用程序的入口点。
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
	while ((ch = fgetc(fp)) != EOF) /* 从文件读一字符，显示到屏幕*/
	{
		putchar(ch);
	}
	fclose(fp);
	getchar();
	return 0;
}

