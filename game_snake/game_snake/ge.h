#ifndef __GE_H__
#define __GE_H__

#define CANVAS_X 60
#define CANVAS_Y 20
bool clean_canvas(char *canvas, unsigned x, unsigned y);
bool display_canvas(char canvas[][CANVAS_Y], unsigned x, unsigned y);

void cls(void);

#endif