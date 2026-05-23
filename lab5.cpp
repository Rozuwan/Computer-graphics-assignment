//  Reflection Transformation (X-axis & Y-axis)

#include <stdio.h>
#include <graphics.h>
#include <dos.h>
#include <conio.h>

int main()
{
	int gd = DETECT, gm;

	int x1 = 100, y1 = 100;
	int x2 = 200, y2 = 150;
	int x3 = 50, y3 = 200;

	initgraph(&gd, &gm, "");

	// X and Y axes
	line(getmaxx() / 2, 0, getmaxx() / 2, getmaxy());
	line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);

	// Original triangle
	setcolor(2);

	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x3, y3, x1, y1);

	// Reflection about Y-axis
	setcolor(3);

	line(getmaxx() - x1, y1, getmaxx() - x2, y2);
	line(getmaxx() - x2, y2, getmaxx() - x3, y3);
	line(getmaxx() - x3, y3, getmaxx() - x1, y1);

	// Reflection about X-axis
	setcolor(4);

	line(x1, getmaxy() - y1, x2, getmaxy() - y2);
	line(x2, getmaxy() - y2, x3, getmaxy() - y3);
	line(x3, getmaxy() - y3, x1, getmaxy() - y1);

	getch();
	closegraph();

	return 0;
}