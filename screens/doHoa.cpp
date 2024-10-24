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

const int x = 5;
const int y = 5;
const int w = 5;
const int h = 5;
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
// #define HeaderVT 4
// char headerVatTuList[HeaderVT][50]{
//     "MA VT",  // 5
//     "TEN VT", // 6
//     "DVT",    // 3
//     "SL"};    // 2
//==========tien khai bao==========
void drawHCN(int x, int y, int w, int h);
void fillAreaColor(int x, int y, int w, int h, int color);
void verticalLine(int x, int y, int h);
void horizontalLine(int x, int y, int w);
//==================================
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

void drawTable(int x, int y, int w, int h, char headerVatTuList[HeaderVT][50], treeVatTu root)
{
    drawHCN(x, y, w * 4, h);
    horizontalLine(x + 1, y + 2, (w * 4) - 1);
    // ve vien
    gotoxy(x, y + 2);
    cout << (char)204;
    gotoxy(x + w * 4, y + 2);
    cout << (char)185;
    gotoxy(x + ((w * 4) - 45), y);
    cout << (char)203;
    gotoxy(x + ((w * 4) - 45), y + h);
    cout << (char)202;
    gotoxy(x + ((w * 4) - 22), y);
    cout << (char)203;
    gotoxy(x + ((w * 4) - 22), y + h);
    cout << (char)202;
    gotoxy(x + ((w * 4) - 11), y);
    cout << (char)203;
    gotoxy(x + ((w * 4) - 11), y + h);
    cout << (char)202;
    verticalLine(x + ((w * 4) - 45), y + 1, h - 1);
    verticalLine(x + ((w * 4) - 22), y + 1, h - 1);
    verticalLine(x + ((w * 4) - 11), y + 1, h - 1);
    gotoxy(x + ((w * 4) - 45), y + 2);
    cout << (char)206;
    gotoxy(x + ((w * 4) - 22), y + 2);
    cout << (char)206;
    gotoxy(x + ((w * 4) - 11), y + 2);
    cout << (char)206;
    // ve header 0
    gotoxy(x + 1, y + 1);
    cout << headerVatTuList[0];
    // ve header 1
    gotoxy(x + ((w * 4) - 44), y + 1);
    cout << headerVatTuList[1];
    // ve header 2
    gotoxy(x + ((w * 4) - 21), y + 1);
    cout << headerVatTuList[2];
    // ve header 3
    gotoxy(x + ((w * 4) - 10), y + 1);
    cout << headerVatTuList[3];
    // inDanhSachVatTu(root);
}

// int main()
// {
//     ShowCur(false);
//     fillAreaColor(0, 0, wConsole, hConsole, LIGHTGRAY);
//     fillAreaColor(x, y, w, h, BLACK);
//     // drawHCN(x,y,w,h);
//     while (1)
//     {
//         getch();
//     }
// }