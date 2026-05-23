// Car Animation using graphics.h
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>

int main()
{
	int gd = DETECT, gm;

	initgraph(&gd, &gm, "");

	int i;

	for (i = 0; i < 300; i++)
	{
		cleardevice();

		// Car body
		setcolor(WHITE);

		rectangle(50 + i, 60, 150 + i, 100);
		rectangle(80 + i, 30, 120 + i, 60);

		// Wheels
		setcolor(YELLOW);

		circle(70 + i, 110, 10);
		circle(130 + i, 110, 10);

		delay(30);
	}

	getch();
	closegraph();

	return 0;
}