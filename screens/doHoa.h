#pragma once
#include "../libraries/khaibao.h"
#include "../libraries/mylib.h"
#define ROWS 20
#define HDROWS 11
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
// console size
const int wConsole = 120;
const int hConsole = 30;
// ki tu ve
const char vtLine = 186;
const char hzLine = 205;
const char tlCorner = 201;
const char trCorner = 187;
const char blCorner = 200;
const char brCorner = 188;
const char tDown = 203;
const char tUp = 202;
const char tRight = 204;
const char tLeft = 185;
const char cross = 206;
// dinh nghia nut
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESC 27
#define F3 61
#define F4 62
#define F5 63
#define F10 68
#define TAB 9
#define BACKSPACE 8
#define HOME 71
#define END 79
#define DEL 83
#define PAGEUP 73
#define PAGEDOWN 81
//==========tien khai bao==========
void Normal();
void Highlight(int Color);
void setColorByRequest(int bgColor, int wordColor);
void drawHCN(int x, int y, int w, int h);
void fillAreaColor(int x, int y, int w, int h, int color);
void verticalLine(int x, int y, int h);
void horizontalLine(int x, int y, int w);
void deleteOneRow(int y);
void deleteOneCollumn(int x);
void drawTableErrors(string errorMessage, bool isSmallErrorTable);
int pageSearchByTab(int x, int currentPage, int totalPages, string &errorMessage);
void clearTablePrint(int x);
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
void setColorByRequest(int bgColor, int wordColor)
{
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
void drawTableErrors(string errorMessage, bool isSmallErrorTable)
{
    int x, y;
    if (isSmallErrorTable)
    {
        x = 5;
        y = 2;
    }
    else
    {
        x = 8;
        y = 2;
    }
    if (errorMessage == "")
    {
        fillAreaColor(x + 69, y + 17, 41, 6, LIGHTGRAY);
        return;
    }
    setColorByRequest(LIGHTGRAY, DARKGRAY);
    drawHCN(x + 69, y + 17, 41, 6);
    gotoxy(x + 85, y + 19);
    setColorByRequest(LIGHTGRAY, RED);
    cout << "THONG BAO";
    for (int i = x + 71; i < x + 109; i++)
    {
        SetBGColor(RED);
        gotoxy(i, y + 21);
        cout << " ";
        SetBGColor(LIGHTGRAY);
    }
    setColorByRequest(RED, WHITE);
    gotoxy(x + 72, y + 21);
    cout << errorMessage;
    setColorByRequest(LIGHTGRAY, BLACK);
}

void clearTablePrint(int x)
{
    SetBGColor(LIGHTGRAY);
    for (int currentRow = 5; currentRow <= ROWS + 4; currentRow++)
    {
        for (int i = x + 3; i < x + 15; i++)
        {
            gotoxy(i, currentRow);
            cout << " ";
        }
        for (int i = x + 18; i < x + 38; i++)
        {
            gotoxy(i, currentRow);
            cout << " ";
        }
        for (int i = x + 41; i < x + 49; i++)
        {
            gotoxy(i, currentRow);
            cout << " ";
        }
        for (int i = x + 52; i < x + 60; i++)
        {
            gotoxy(i, currentRow);
            cout << " ";
        }
    }
}

int pageSearchByTab(int x, int currentPage, int totalPages, string &errorMessage)
{
    int goToPage;
    string numberStr = to_string(totalPages);
    int length = numberStr.length();
    for (int i = 0; i < 7; i++)
    {
        gotoxy(x + 26 + i, 26);
        SetBGColor(LIGHTGRAY);
        cout << " ";
    }
    for (int i = 0; i <= length + 1; i++)
    {
        gotoxy(x + 26 + i, 26);
        SetBGColor(BLACK);
        cout << " ";
        SetBGColor(LIGHTGRAY);
    }
    setColorByRequest(BLACK, WHITE);
    ShowCurAtXY(x + 27, 26, true);
    cin >> goToPage;
    ShowCur(false);
    while (goToPage > totalPages)
    {
        errorMessage = "Loi trang. Vui long nhap lai";
        drawTableErrors(errorMessage, true);
        for (int i = 0; i <= length + 1; i++)
        {
            gotoxy(x + 26 + i, 26);
            SetBGColor(BLACK);
            cout << " ";
            SetBGColor(LIGHTGRAY);
        }
        setColorByRequest(BLACK, WHITE);
        ShowCurAtXY(x + 27, 26, true);
        cin >> goToPage;
        ShowCur(false);
    }
    currentPage = goToPage;
    setColorByRequest(LIGHTGRAY, BLACK);
    clearTablePrint(x);
    drawTableErrors("", true);
    return currentPage;
}