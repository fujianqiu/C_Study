#include "stdafx.h"
#include "ge.h"
#include<windows.h>


void cls(void)
{
	COORD coordScreen = { 0, 0 };    /* here's where we'll home the
									 cursor */
	BOOL bSuccess;
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */
	DWORD dwConSize;                 /* number of character cells in
									 the current buffer */

	/* get the number of character cells in the current buffer */
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	bSuccess = GetConsoleScreenBufferInfo(hConsole, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

	/* fill the entire screen with blanks */

	//bSuccess = FillConsoleOutputCharacter(hConsole, (TCHAR) 'A',
	//	dwConSize, coordScreen, &cCharsWritten);

	/* get the current text attribute */

	bSuccess = GetConsoleScreenBufferInfo(hConsole, &csbi);

	/* now set the buffer's attributes accordingly */

	bSuccess = FillConsoleOutputAttribute(hConsole, csbi.wAttributes,
		dwConSize, coordScreen, &cCharsWritten);

	/* put the cursor at (0, 0) */

	bSuccess = SetConsoleCursorPosition(hConsole, coordScreen);
	return;
}
bool clean_canvas(PBitmapInfo pBitmapHandle)
{
	if (pBitmapHandle == NULL && pBitmapHandle->frameBuf ==NULL)
		return false;
	memset(pBitmapHandle->frameBuf, ' ', pBitmapHandle->width*pBitmapHandle->height*pBitmapHandle->pointSize);
	return true;
}

bool display_canvas(PBitmapInfo pBitmapHandle)
{
	int i, j;
	if (pBitmapHandle == NULL)
		return false;
	cls();
	for (i = 0; i < pBitmapHandle->height; i++)
	{
		for (j = 0; j < pBitmapHandle->width; j++)
			printf("%c", pBitmapHandle->frameBuf[j*pBitmapHandle->pointSize + pBitmapHandle->width * i*pBitmapHandle->pointSize]);
		printf("\n");
	}
	return true;
}
int get_point_size(void )
{
	return 1;
}
PBitmapInfo init_ge(unsigned width, unsigned height)
{
	CONSOLE_CURSOR_INFO cci;
	PBitmapInfo geHandle = NULL;
	cci.bVisible = FALSE;
	cci.dwSize = sizeof(cci);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cci);
	if (width*height == 0)
		return NULL;
	geHandle = (PBitmapInfo)malloc(sizeof(BitmapInfo));
	if (geHandle)
	{
		geHandle->pointSize = get_point_size();
		geHandle->frameBuf = (unsigned char *)malloc(width * height*geHandle->pointSize);
		if (geHandle->frameBuf)
		{
			geHandle->height = height;
			geHandle->width = width;
			clean_canvas(geHandle);
			return geHandle;
		}
		else
		{
			free(geHandle);
			return NULL;
		}
	}
	return NULL;
}