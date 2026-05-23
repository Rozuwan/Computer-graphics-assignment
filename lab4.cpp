//  Mid-Point Circle Drawing Algorithm
// input: 200 200,100

#include <stdio.h>
#include <graphics.h>
#include <dos.h>
#include <conio.h>

int main()
{
	float x1,y1,radius,p,x,y;

	printf("Enter the co-ordinates of center of the circle\n");
	scanf("%f %f",&x1,&y1);

	printf("Enter the radius of the circle\n");
	scanf("%f",&radius);

	x=0;
	y=radius;
	p=1-radius;

	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");

	putpixel(x+x1,y+y1,7);

	while (x <= y)
	{
		if (p < 0)
		{
			x++;

			p = p + (2*x + 1);
		}
		else
		{
			x++;
			y--;

			p = p + (2*x - 2*y + 1);
		}

		putpixel(x+x1,y+y1,2);
		putpixel(y+x1,x+y1,2);
		putpixel(-y+x1,x+y1,2);
		putpixel(-x+x1,y+y1,2);
		putpixel(-x+x1,-y+y1,2);
		putpixel(-y+x1,-x+y1,2);
		putpixel(y+x1,-x+y1,2);
		putpixel(x+x1,-y+y1,2);

		delay(20);
	}

	getch();
	closegraph();

	return 0;
}