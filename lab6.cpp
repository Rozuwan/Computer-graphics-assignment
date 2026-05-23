// Rotation Transformation (+45°)
// input = 45
#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>
#include <conio.h>

int main()
{
	int gd=DETECT,gm;

	float angle;
	float x1=100,y1=100;
	float x2=200,y2=50;
	float x3=300,y3=150;

	float x1_ref,y1_ref;
	float x2_ref,y2_ref;
	float x3_ref,y3_ref;

	printf("Enter the angle of rotation:\n");
	scanf("%f",&angle);

	angle = angle * (3.1415/180);

	initgraph(&gd,&gm,"");

	// Original Triangle
	setcolor(2);

	line((int)x1,(int)y1,(int)x2,(int)y2);
	line((int)x2,(int)y2,(int)x3,(int)y3);
	line((int)x3,(int)y3,(int)x1,(int)y1);

	// Rotated Triangle
	x1_ref = x1*cos(angle) - y1*sin(angle);
	y1_ref = x1*sin(angle) + y1*cos(angle);

	x2_ref = x2*cos(angle) - y2*sin(angle);
	y2_ref = x2*sin(angle) + y2*cos(angle);

	x3_ref = x3*cos(angle) - y3*sin(angle);
	y3_ref = x3*sin(angle) + y3*cos(angle);

	setcolor(3);

	line((int)x1_ref,(int)y1_ref,(int)x2_ref,(int)y2_ref);
	line((int)x2_ref,(int)y2_ref,(int)x3_ref,(int)y3_ref);
	line((int)x3_ref,(int)y3_ref,(int)x1_ref,(int)y1_ref);

	getch();
	closegraph();

	return 0;
}
