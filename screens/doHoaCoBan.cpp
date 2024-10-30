#include "../libraries/mylib.h"
//==========khai bao=========
const int BLACK = 0;
const int BLUE = 1;
const int GREEN = 2;
const int CYAN = 3;
const int RED = 4;
const int MAGENTA = 5;
const int BROWN = 6;
const int LIGHTGRAY = 7;
const int DARKGRAY = 8;
const int LIGHTBLUE = 9;
const int LIGHTGREEN = 10;
const int LIGHTCYAN = 11;
const int LIGHTRED = 12;
const int LIGHTMAGENTA = 13;
const int YELLOW = 14;
const int WHITE = 15;

const int x = 5;
const int y = 5;
const int w = 5;
const int h = 5;
const int wConsole = 120;
const int hConsole = 30;
// ki tu ve
const char vtLine = 179;
const char hzLine = 196;
const char tlCorner = 218;
const char trCorner = 191;
const char blCorner = 192;
const char brCorner = 217;
void drawHCN(int x, int y, int w, int h);
void fillAreaColor(int x, int y, int w, int h, int color);
void verticalLine(int x, int y, int h);
void horizontalLine(int x, int y, int w);
void SetCP437();
void SetUTF8();
//==================================

void SetCP437()
{
    SetConsoleOutputCP(437);
}

void SetUTF8(){
    SetConsoleOutputCP(CP_UTF8);
}


void fillAreaColor(int x, int y, int w, int h, int color)
{
    SetBGColor(color);
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            gotoxy(x + j, y + i);
            cout << " ";
        }
    }
    SetBGColor(0);
}

void drawHCN(int x, int y, int w, int h)
{
    for (int ix = x; ix <= x + w; ix++)
    {
        gotoxy(ix, y);
        cout << hzLine; // Đường ngang trên
        gotoxy(ix, y + h);
        cout << hzLine; // Đường ngang dưới
    }
    for (int iy = y; iy <= y + h; iy++)
    {
        gotoxy(x, iy);
        cout << vtLine; // Đường dọc trái
        gotoxy(x + w, iy);
        cout << vtLine; // Đường dọc phải
    }
    // Vẽ các góc
    gotoxy(x, y);
    cout << tlCorner; // Góc trên-trái
    gotoxy(x + w, y);
    cout << trCorner; // Góc trên-phải
    gotoxy(x, y + h);
    cout << blCorner; // Góc dưới-trái
    gotoxy(x + w, y + h);
    cout << brCorner; // Góc dưới-phải
}

void verticalLine(int x, int y, int h)
{
    for (int i = x; i < x + h; i++)
    {
        gotoxy(x, y + i);
        std::cout << vtLine;
    }
}

void horizontalLine(int x, int y, int w)
{
    for (int i = 0; i < w; i++)
    {
        gotoxy(x + i, y);
        std::cout << hzLine;
    }
}

int main()
{
    ShowCur(false);
    fillAreaColor(0, 0, wConsole, hConsole, LIGHTGRAY);
    fillAreaColor(x, y, w, h, BLACK);
    while (1)
    {
        getch();
    }
}