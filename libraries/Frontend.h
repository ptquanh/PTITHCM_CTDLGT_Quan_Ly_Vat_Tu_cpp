#include <iostream>
#include "mylib.h"
using namespace std;
//khai bao
//
void Normal()
{
    SetColor(15);
    SetBGColor(0);
}
void HighLight()
{
    SetColor(15);
    SetBGColor(1);
}
void box(int x, int y, int w, int h)
{
    for (int ix = x; ix <= x + w; ix++)
    {
        gotoxy(ix, y);
        cout << char(196);
        gotoxy(ix, y + h);
        cout << char(196);
    }
    for (int iy = y; iy <= y + h; iy++)
    {
        gotoxy(x, iy);
        cout << char(179);
        gotoxy(x + w, iy);
        cout << char(179);
    }
    gotoxy(x, y);
    cout << char(218);
    gotoxy(x + w, y);
    cout << char(191);
    gotoxy(x, y + h);
    cout << char(192);
    gotoxy(x + w, y + h);
    cout << char(217);
}
//
