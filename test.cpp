# include <iostream>
# include <graphics.h>
# pragma GCC diagnostic ignored "-Wwrite-strings"

using namespace std;

int main ()

{
    int gd = DETECT,gm;
    initgraph(&gd, &gm, " ");
    circle(200,200,100);
    getch();
    closegraph();

    return 0;
}
