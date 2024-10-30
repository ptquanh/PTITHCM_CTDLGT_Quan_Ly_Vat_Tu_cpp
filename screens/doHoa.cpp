#pragma once
#include "../libraries/khaibao.h"
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

// const int x = 5;
// const int y = 5;
// const int w = 5;
// const int h = 5;
const int wConsole = 120;
const int hConsole = 30;
// ki tu ve
const char vtLine = 186;   // 179
const char hzLine = 205;   // 196
const char tlCorner = 201; // 218
const char trCorner = 187; // 191
const char blCorner = 200; // 192
const char brCorner = 188; // 217

// Box drawing characters
const char TOP_LEFT = 201;     // ╔
const char TOP_RIGHT = 187;    // ╗
const char BOTTOM_LEFT = 200;  // ╚
const char BOTTOM_RIGHT = 188; // ╝
const char HORIZONTAL = 205;   // ═
const char VERTICAL = 186;     // ║
const char T_DOWN = 203;       // ╦
const char T_UP = 202;         // ╩
const char T_RIGHT = 204;      // ╠
const char T_LEFT = 185;       // ╣
const char CROSS = 206;
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESC 27
#define F1 59
#define F2 60
#define F3 61
#define F4 62
#define TAB 9
#define BACKSPACE 8
//==========tien khai bao==========
void Normal();
void Highlight(int Color);
void drawHCN(int x, int y, int w, int h);
void fillAreaColor(int x, int y, int w, int h, int color);
void verticalLine(int x, int y, int h);
void horizontalLine(int x, int y, int w);
void deleteOneRow(int y);
void deleteOneCollumn(int x);
//==================================
void Normal()
{
    SetBGColor(BLACK);
    SetColor(WHITE);
}
void Highlight(int Color)
{
    SetBGColor(Color);
    SetColor(WHITE);
}
void setColorByRequest(int bgColor, int wordColor){
    SetBGColor(bgColor);
    SetColor(wordColor);
}
void deleteOneRow(int y)
{
    for (int i = 0; i < 120; i++)
    {
        gotoxy(i, y);
        cout << " ";
    }
}
void deleteOneCollumn(int x)
{
    for (int i = 0; i < 30; i++)
    {
        gotoxy(x, i);
        cout << " ";
    }
}
void fillAreaColor(int x, int y, int w, int h, int color)
{
    SetBGColor(color);
    for (int i = 0; i <= h; i++)
    {
        for (int j = 0; j <= w; j++)
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
    for (int i = 0; i < h; i++)
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
void drawTableErrors(int x, int y, string errorMessage)
{
    setColorByRequest(LIGHTGRAY,BLACK);
    drawHCN(x + 69, y + 17, 41, 6);
    gotoxy(x + 85, y + 19);
    setColorByRequest(LIGHTGRAY, RED);
    cout << "THONG BAO";
    for (int i = x + 71; i < x + 109; i++)
    {
        SetBGColor(RED);
        gotoxy(i, y + 21);
        cout << " ";
        SetBGColor(BLACK);
    }
    SetColor(WHITE);
    SetBGColor(BLUE);
    gotoxy(x + 72, y + 21);
    cout << errorMessage;
    SetColor(WHITE);
    SetBGColor(BLACK);
}
// int main()
// {
//     ShowCur(false);
//     int button = 0;
//     while (1)
//     {

//         getch();
//     }
// }