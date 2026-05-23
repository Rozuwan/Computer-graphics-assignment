// BLA algorithm to draw a line between given points
// input : 100 200, 400 200
#include <stdio.h>
#include <graphics.h>
#include <dos.h>
#include <conio.h>

int main()
{
	int x1,y1,x2,y2,dx,dy,p,x,y;

	printf("Enter starting point:\n");
	scanf("%d%d",&x1,&y1);

	printf("Enter ending point:\n");
	scanf("%d%d",&x2,&y2);

	dx=x2-x1;
	dy=y2-y1;

	p=2*dy-dx;

	x=x1;
	y=y1;

	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");

	while(x<=x2)
	{
		putpixel(x,y,WHITE);

		if(p<0)
		{
			p=p+(2*dy);
		}
		else
		{
			y=y+1;
			p=p+(2*dy)-(2*dx);
		}

		x=x+1;
		delay(20);
	}

	getch();
	closegraph();

	return 0;
}