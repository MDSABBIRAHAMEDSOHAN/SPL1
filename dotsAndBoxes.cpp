# include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

char board[49];
char input1[3], input2[3];

void initializeBoard();
void showBoard();
int takeInput();

void initializeBoard()
{
    for(int i=0; i<49; i++)
    {
        if(i%2==1)
        {
            board[i] = ' ';
        }
        else if((i%7)%2 == 1)
        {
            board[i] = '  ';
        }
        else board[i] = '.';
    }
}

void showBoard()
{
    char ch = 'a';

    cout << "  1 2 3 4  " << endl;

    for( int i=0; i<49; i++)
    {
        if(i%14 == 0)
        {
            printf("\n%c ",ch++);
        }
        else if(i%7 == 0) printf("\n  ");
        printf("%c", board[i]);

    }
    cout << "\n\n\n\n" << endl;

}

int takeInput()
{
    int index1, index2;
    int input1,input2;
    char calcIndex;

    while(1)
    {
        cout << "Enter 1st coordinate : " << endl;
        cin>> input1 ;

        cout <<"Enter 2nd coordinate :  " << endl ;
        cin >> input2;

        // calIndex not used///....
        index1 = calcIndex(input1);
        index2 = calcIndex(input2);

        int diff = abs(index1 - index2);

        if(diff == 2 || diff == 14) break;

        cout << "Invalid Input\n" << endl;
    }
    return (index1+index2)/2;
}

void makeMove()
{
    if((move%7)%2 == 1)
        board[move] = '_';
    else
        board[move] = '|';
}

int main (void)

{
     initializeBoard();
     showBoard();
     takeInput();
     makeMove();

     return 0;
}
