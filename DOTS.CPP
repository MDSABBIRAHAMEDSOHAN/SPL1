//#include <bits/stdc++.h>
#include <graphics.h>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <conio.h>
#include <comm.h>

using namespace std;

int xmax,ymax,xdum=2,ydum=2,player=1,vert,x,o;
int xex[300],yex[300],who[300],ind;


struct pct
{
  int pl;
  int con1;
  int con2;
  int con1_pl;
  int con2_pl;
} p[15][15];


void graphinit()
{
   int driver=DETECT,mode;
   initgraph(&driver,&mode,"..\\bgi");
}

void dimen()
{
    int i,j;
    start:
    system("cls");

    cout<<" Width (2-13):";
    cin>>i;

    if(i<2||i>13) goto start;
    cout<<"Height (2-13):";
    cin>>j;

    if(j<2||j>13) goto start;
    xmax=i+1; ymax=j+1;
}

void intro()
{
   settextstyle(8,0,3);
   setcolor(2);
   outtextxy(150,100,"Dots And Boxes Game");
   getch();

   closegraph();
}


void putDots(int i,int j,int k)
{
   setcolor(k);
   line(i*30-1,j*30-1,i*30+1,j*30-1);
   line(i*30-1,j*30,i*30+1,j*30);
   line(i*30-1,j*30+1,i*30+1,j*30+1);
}



void drawDots()
{
   cleardevice();
   for(int i=1;i<=xmax;i++)
    for(int j=1;j<=ymax;j++) putDots(i,j,1);
}



inline void putline(int i,int j,int k)
{
   setcolor(k);
   line(i*30+2,j*30-1,i*30+28,j*30-1);
   line(i*30+2,j*30,i*30+28,j*30);
   line(i*30+2,j*30+1,i*30+28,j*30+1);
}

inline void putlinev(int i,int j,int k)
{
   setcolor(k);
   line(i*30-1,j*30+2,i*30-1,j*30+28);
   line(i*30,j*30+2,i*30,j*30+28);
   line(i*30+1,j*30+2,i*30+1,j*30+28);
}

void drawX(int i,int j, int k)
{
   setcolor(k);
   line(i*30+6,j*30-6,i*30+24,j*30-24);
   line(i*30+6,j*30-24,i*30+24,j*30-6);
}

void drawO(int i,int j, int k)
{
   setcolor(k);
   circle(i*30+15,j*30-15,10);
}

void putXO()
{
   for(int l=0;l<=ind;l++)
    if(who[l]==1) drawX(xex[l],yex[l],2);
    else drawO(xex[l],yex[l],12);
}

void drawlines()
{
   for(int i=1;i<=xmax;i++)
    for(int j=1;j<=ymax;j++)
    {
       if(p[i][j].con2)
        if(p[i][j].con2_pl==1) putline(i,j,12);
         else putline(i,j,2);
       if(p[i][j].con1)
        if(p[i][j].con1_pl==1) putlinev(i,j,12);
         else putlinev(i,j,2);
    }
}

inline void reposition()
{
   if(xdum>=xmax && !vert) xdum--;
   if(ydum>=ymax && vert) ydum--;
}

inline void status()
{
   if(player==1)
   {
       setcolor(3);
       outtextxy(500,100,"Player-1 Move");
   }
   else
   {
       setcolor(8);
       outtextxy(500,100,"Player-2 Move");
   }
}

void end()
{
   if(ind==(xmax-1)*(ymax-1))
   {
      if(x>o)
      {
        cout<<"\n\nPlayer-1 WINS with "<<x<<"-"<<o;
        getch();
        exit(0);
      }

      if(x==o)
      {
        cout<<"\n\nTie ("<<x<<"-"<<o<<")";
        getch();
        exit(0);
      }

      if(x<o)
      {
        cout<<"\n\nPlayer-2 WINS with "<<o<<"-"<<x;
        getch();
        exit(0);
      }
   }
}

inline void drawall()
{
    drawDots();
    drawlines();
    putXO();
    status();
}

void check()
{
   for(int i=1;i<xmax;i++)
    for(int j=2;j<=ymax;j++)
    {
       int q=0;
       for(int l=0;l<=ind;l++)
        if((xex[l]==i) && (yex[l]==j)) q=1;
     if(!q)
     if(p[i][j].con2 && p[i][j-1].con1 && p[i][j-1].con2 && p[i+1][j-1].con1)
      if(player==1)
      {
        o++;
        player=2;
        drawO(i,j,12);
        xex[ind]=i;
        yex[ind]=j;
        who[ind]=2;
        ind++;

        return;
      }
      else
      {
          x++;
          player=1;
          drawX(i,j,2);
          xex[ind]=i;
          yex[ind]=j;
          who[ind]=1;
          ind++;

          return;
      }
    }
}

void check1()
{
   for(int i=1;i<xmax;i++)
    for(int j=2;j<=ymax;j++)
    {
       int q=0;
       for(int l=0;l<=ind;l++)
        if((xex[l]==i) && (yex[l]==j)) q=1;
     if(!q)
     if(p[i][j].con2 && p[i][j-1].con1 && p[i][j-1].con2 && p[i+1][j-1].con1)
      if(player==1)
      {
          x++;
          drawX(i,j,2);
          xex[ind]=i;
          yex[ind]=j;
          who[ind]=1;
          ind++;

          return;
      }
      else
      {
          o++;
          drawO(i,j,12);
          xex[ind]=i;
          yex[ind]=j;
          who[ind]=2;
          ind++;

        return;
       }
    }
}

void move()
{
   char a;
   while(a!=ESC)
   {
      begin:
      a=getch();
      if(!vert)
      {
         if(a==RIGHT && xdum+1<xmax)
         {
             drawall();
             xdum++;
             putline(xdum,ydum,1);
         }

         if(a==LEFT && xdum-1>=1)
         {
            drawall();
            xdum--;
            putline(xdum,ydum,1);
         }

         if(a==UP && ydum-1>=1)
         {
             drawall();
             ydum--;
             putline(xdum,ydum,1);
         }

         if(a==DOWN && ydum+1<=ymax)
         {
             drawall();
             ydum++;
             putline(xdum,ydum,1);
         }

         if(a==ENTER && !p[xdum][ydum].con2)
         {
              p[xdum][ydum].con2=1;

	        if(player==1)
                player=2;
            else
	        player=1;
	        p[xdum][ydum].con2_pl=player;
	        check();
	        check1();
	        drawall();
	        end();
          }

         if(a==SPACE)
            {
                if(vert)
                    vert=0;
                else
                    vert=1;
                reposition();
                drawall();
                putlinev(xdum,ydum,1);
                goto begin;
            }
      }
      if(vert)
      {
         if(a==RIGHT && xdum<xmax)
         {
             drawall();
             xdum++;
             putlinev(xdum,ydum,1);
         }

         if(a==LEFT && xdum-1>=1)
         {
             drawall();
             xdum--;
             putlinev(xdum,ydum,1);
         }

         if(a==UP && ydum-1>=1)
         {
             drawall();
             ydum--;
             putlinev(xdum,ydum,1);
         }

         if(a==DOWN && ydum+1<ymax)
         {
              drawall();
              ydum++;
              putlinev(xdum,ydum,1);
         }

         if(a==ENTER && !p[xdum][ydum].con1)
            {
                p[xdum][ydum].con1=1;

	         if(player==1)
                 player=2;
             else
	           player=1;
	           p[xdum][ydum].con1_pl=player;
	           check();
	           check1();
	           drawall();
	           end();
            }

         if(a==SPACE)
            {
                if(vert)
                    vert=0;
                else
                    vert=1;
                    reposition();
	                drawall();
	                putline(xdum,ydum,1);
	                goto begin;
            }
      }
   }
}




int main(void)

{
    graphinit();
    intro();
    closegraph();

    dimen();
    graphinit();
    setbkcolor(15);
    drawDots();
    move();
    closegraph();
}

