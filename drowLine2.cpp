#include <iostream>
#include <graphics.h>
# pragma GCC diagnostic ignored "-Wwrite-strings"
using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    int errorcode = graphresult();
    if (errorcode != grOk)
    {
        cout << "Graphics error: " <<  grapherrormsg(errorcode) << endl;
        return 1;
    }

    line(100, 200, 150, 250);
    cout << "Hello world!" << endl;

    return 0;
}
/*#include <iostream>
#include <winbgim.h>
#include <cstdlib>

using namespace std;

int main()
{
   int gdriver = 9;
   int gmode = 2;
   initgraph(&gdriver,&gmode, " ");
   setbkcolor(WHITE);
   setcolor(BLACK);
   cleardevice();
   circle(320,240,180);
   getch();
   closegraph();

}
*/
