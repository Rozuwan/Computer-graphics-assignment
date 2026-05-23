// Cohen-Sutherland Line Clipping Algorithm
#include <stdio.h>
#include <graphics.h>
#include <dos.h>
#include <conio.h>
#include <math.h>

int xmin, xmax, ymin, ymax;

struct lines
{
	int x1, y1, x2, y2;
};

int sign(int x)
{
	if (x > 0)
		return 1;
	else
		return 0;
}

void clip(struct lines mylines)
{
	int bits[4], bite[4];
	int i, var;

	setcolor(RED);

	bits[0] = sign(xmin - mylines.x1);
	bite[0] = sign(xmin - mylines.x2);

	bits[1] = sign(mylines.x1 - xmax);
	bite[1] = sign(mylines.x2 - xmax);

	bits[2] = sign(ymin - mylines.y1);
	bite[2] = sign(ymin - mylines.y2);

	bits[3] = sign(mylines.y1 - ymax);
	bite[3] = sign(mylines.y2 - ymax);

	float m = (mylines.y2 - mylines.y1) /
			  (float)(mylines.x2 - mylines.x1);

	float c = mylines.y1 - m * mylines.x1;

	int inside1 =
		(bits[0] == 0 && bits[1] == 0 &&
		 bits[2] == 0 && bits[3] == 0);

	int inside2 =
		(bite[0] == 0 && bite[1] == 0 &&
		 bite[2] == 0 && bite[3] == 0);

	if (inside1 && inside2)
	{
		line(mylines.x1, mylines.y1,
			 mylines.x2, mylines.y2);
		return;
	}

	for (i = 0; i < 4; i++)
	{
		if (bits[i] && bite[i])
			return;
	}

	if (bits[0])
	{
		var = (int)(m * xmin + c);
		mylines.y1 = var;
		mylines.x1 = xmin;
	}

	if (bite[0])
	{
		var = (int)(m * xmin + c);
		mylines.y2 = var;
		mylines.x2 = xmin;
	}

	if (bits[1])
	{
		var = (int)(m * xmax + c);
		mylines.y1 = var;
		mylines.x1 = xmax;
	}

	if (bite[1])
	{
		var = (int)(m * xmax + c);
		mylines.y2 = var;
		mylines.x2 = xmax;
	}

	if (bits[2])
	{
		var = (int)((ymin - c) / m);
		mylines.x1 = var;
		mylines.y1 = ymin;
	}

	if (bite[2])
	{
		var = (int)((ymin - c) / m);
		mylines.x2 = var;
		mylines.y2 = ymin;
	}

	if (bits[3])
	{
		var = (int)((ymax - c) / m);
		mylines.x1 = var;
		mylines.y1 = ymax;
	}

	if (bite[3])
	{
		var = (int)((ymax - c) / m);
		mylines.x2 = var;
		mylines.y2 = ymax;
	}

	line(mylines.x1, mylines.y1,
		 mylines.x2, mylines.y2);
}

int main()
{
	int gd = DETECT, gm;

	xmin = 40;
	xmax = 100;
	ymin = 40;
	ymax = 80;

	initgraph(&gd, &gm, "");

	rectangle(xmin, ymin, xmax, ymax);

	struct lines mylines[4];

	int i;

	mylines[0].x1 = 30;
	mylines[0].y1 = 65;
	mylines[0].x2 = 55;
	mylines[0].y2 = 30;

	mylines[1].x1 = 60;
	mylines[1].y1 = 20;
	mylines[1].x2 = 100;
	mylines[1].y2 = 90;

	mylines[2].x1 = 60;
	mylines[2].y1 = 100;
	mylines[2].x2 = 80;
	mylines[2].y2 = 70;

	mylines[3].x1 = 85;
	mylines[3].y1 = 50;
	mylines[3].x2 = 120;
	mylines[3].y2 = 75;

	// Original lines
	for (i = 0; i < 4; i++)
	{
		line(mylines[i].x1,
			 mylines[i].y1,
			 mylines[i].x2,
			 mylines[i].y2);

		delay(1000);
	}

	// Clipped lines
	setcolor(YELLOW);

	for (i = 0; i < 4; i++)
	{
		clip(mylines[i]);
		delay(1000);
	}

	getch();
	closegraph();

	return 0;
}