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
bool clean_canvas(char *canvas, unsigned x, unsigned y)
{
	if (canvas == NULL)
		return false;
	memset(canvas, ' ', x*y);
	return true;
}
bool display_canvas(char canvas[][CANVAS_Y], unsigned x, unsigned y)
{
	int i, j;
	if (canvas == NULL)
		return false;
	cls();
	for (i = 0; i < y; i++)
	{
		for (j = 0; j < x; j++)
			printf("%c", canvas[j][i]);
		printf("\n");
	}
	return true;
}