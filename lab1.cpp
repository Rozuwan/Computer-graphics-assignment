// Translation and Scaling a triangle
#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    int x1=100, y1=50;
    int x2=150, y2=200;
    int x3=200, y3=20;

    // ORIGINAL TRIANGLE
    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x3,y3,x1,y1);

    // TRANSLATION
    int tx1 = x1 + 50;
    int tx2 = x2 + 50;
    int tx3 = x3 + 50;

    int ty1 = y1;
    int ty2 = y2;
    int ty3 = y3;

    line(tx1,ty1,tx2,ty2);
    line(tx2,ty2,tx3,ty3);
    line(tx3,ty3,tx1,ty1);

    // SCALING
    int sx = 2, sy = 2;

    int sx1 = tx1 * sx;
    int sy1 = ty1 * sy;

    int sx2 = tx2 * sx;
    int sy2 = ty2 * sy;

    int sx3 = tx3 * sx;
    int sy3 = ty3 * sy;

    line(sx1,sy1,sx2,sy2);
    line(sx2,sy2,sx3,sy3);
    line(sx3,sy3,sx1,sy1);

    getch();
    closegraph();

    return 0;
}