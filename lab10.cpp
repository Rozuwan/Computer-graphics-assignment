// Ellipse using Mid-Point Ellipse Drawing Algorithm
#include <stdio.h>
#include <math.h>
#include <graphics.h>
#include <dos.h>
#include <conio.h>

void _ellipse(int xc, int yc, int rx, int ry)
{
	int x = 0;
	int y = ry;

	int p = (ry * ry) - (rx * rx * y) + (rx * rx) / 4;

	// Region 1
	while (2 * ry * ry * x < 2 * rx * rx * y)
	{
		putpixel(xc + x, yc + y, WHITE);
		putpixel(xc - x, yc + y, WHITE);
		putpixel(xc - x, yc - y, WHITE);
		putpixel(xc + x, yc - y, WHITE);

		x = x + 1;

		if (p < 0)
		{
			p = p + (2 * ry * ry * x) + ry * ry;
		}
		else
		{
			y = y - 1;

			p = p + (2 * ry * ry * x) - (2 * rx * rx * y) + rx * rx;
		}

		delay(100);
	}

	// Region 2
	p = (int)pow(((float)x + 0.5) * ry, 2) + pow(rx * (y - 1), 2) - pow(rx * ry, 2);

	while (y >= 0)
	{
		putpixel(xc + x, yc + y, WHITE);
		putpixel(xc - x, yc + y, WHITE);
		putpixel(xc - x, yc - y, WHITE);
		putpixel(xc + x, yc - y, WHITE);

		y = y - 1;

		if (p > 0)
		{
			p = p - (2 * rx * rx * y) + rx * rx;
		}
		else
		{
			x = x + 1;

			p = p + (2 * ry * ry * x) - (2 * rx * rx * y) + rx * rx;
		}

		delay(100);
	}
}

int main()
{
	int gd = DETECT, gm;

	initgraph(&gd, &gm, "");

	_ellipse(200, 300, 15, 10);

	getch();

	closegraph();

	return 0;
}