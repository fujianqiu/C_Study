#ifndef _DIRTYRECT_FLIPGDI_H
#define _DIRTYRECT_FLIPGDI_H

#include "canvas.h"

struct gdi {
	draw_func flip;
	void *object;
	pixel *buffer;
	int width;
	int height;
	int pitch;
};
void flip(int xDest, int yDest, DWORD w, DWORD h, int xSrc,
	int ySrc, UINT StartScan, UINT cLines, CONST VOID * lpvBits)
	;
void gdi_create(struct gdi *g, void *wnd, int w, int h);
void gdi_release(struct gdi *g);

#endif