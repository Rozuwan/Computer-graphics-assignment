// Human Body Animation
#include <stdio.h>
#include <graphics.h>
#include <dos.h>
#include <conio.h>

int main()
{
	int gd=DETECT,gm;

	initgraph(&gd,&gm,"");

	int i;

	for(i=0;i<300;i++)
	{
		cleardevice();

		// Head
		circle(100+i,80,20);

		// Body
		line(100+i,100,100+i,180);

		// Arms
		line(100+i,120,70+i,150);
		line(100+i,120,130+i,150);

		// Legs
		line(100+i,180,70+i,220);
		line(100+i,180,130+i,220);

		delay(30);
	}

	getch();
	closegraph();

	return 0;
}