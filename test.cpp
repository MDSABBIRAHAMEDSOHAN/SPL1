#include<iostream>
#include <graphics.h>

//int gd = DETECT ,gm;

int driver=DETECT,mode;

void graphinit()
{
   int driver=DETECT,mode;
   initgraph(&driver,&mode," ");
}
//

int main (void)

{
    void graphinit();
    //int gd = DETECT ,gm;
    //initgraph(&gd,&gm," ");
    initgraph(&driver,&mode," ");
  //  circle(200,200,100);


  // print dot//
    putpixel(100,50,WHITE);
    setcolor(YELLOW);
    line(10,10,50,50);
    getch();
    closegraph();

    return 0;

}
