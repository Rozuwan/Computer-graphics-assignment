// DDA Line Drawing Algorithm
// input 100 100 , 200 200
#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>

int main(int argc, char const *argv[])
{
	int x1,y1,x2,y2,steps;
	float dx,dy;

	printf("Enter the initial point\n");
	scanf("%d %d",&x1,&y1);

	printf("Enter the final point\n");
	scanf("%d %d",&x2,&y2);

	dx=x2-x1;
	dy=y2-y1;

	if (abs(dx)>=abs(dy))
	{
		steps=abs(dx);
	}
	else
	{
		steps=abs(dy);
	}

	dx/=steps;
	dy/=steps;

	int gd=DETECT,gm;

	initgraph(&gd,&gm,"");

	float x=x1;
	float y=y1;

	for (int i = 0; i < steps; i++)
	{
		putpixel((int)x,(int)y,5);
		x+=dx;
		y+=dy;
		delay(100);
	}

	delay(5000);
	closegraph();

	return 0;
}