#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string>
#include <ctime>
#include <windows.h>
using namespace std;
#define KEY_NONE -1
#define ENTER 13
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27
// const int WHITE=15;
#define PASSWORD "abcdef"
// const int WHITE=15;
char *Pwd()
{
    char S[40];
    int i = 0;
    while ((S[i] = getch()) != ENTER)
    {
        printf("%c", '*');
        i++;
    }
    S[i] = '\0';
    return S;
}
int CheckPwd()
{
    int dem = 0;
    for (dem = 1; dem <= 3; dem++)
    {
        printf("Password :");
        if (strcmp(Pwd(), PASSWORD) == 0)
            return 1;
        else
            printf("\nPassword sai. Hay nhap lai\n");
    }
    return 0;
}
//===== dịch con trỏ hiện tại đến điểm có tọa độ (x,y) ======
void gotoxy(short x, short y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = {x, y};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
//======= lấy tọa độ x của con trỏ hiện tại =============
int wherex(void)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.X;
}
//======= lấy tọa độ y của con trỏ hiện tại =============
int wherey(void)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.Y;
}
void clreol()
{
    COORD coord;
    DWORD written;
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    coord.X = info.dwCursorPosition.X;
    coord.Y = info.dwCursorPosition.Y;
    FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ',
                               info.dwSize.X - info.dwCursorPosition.X * info.dwCursorPosition.Y, coord, &written);
    gotoxy(info.dwCursorPosition.X, info.dwCursorPosition.Y);
}
//============= đặt màu cho chữ =========
void SetColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void SetBGColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void clrscr1()
{
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    HANDLE hConsoleOut;
    COORD Home = {0, 0};
    DWORD dummy;

    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

    FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
    csbiInfo.dwCursorPosition.X = 0;
    csbiInfo.dwCursorPosition.Y = 0;
    SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}
void clrscr()
{
    system("cls");
}
//======= trả về mã phím người dùng bấm =========
int inputKey()
{
    if (_kbhit())
    {
        int key = _getch();
        if (key == 224)
        {
            key = _getch();
            return key;
        }
        return key;
    }
    else
    {
        return KEY_NONE;
    }

    return KEY_NONE;
}
//============== làm ẩn trỏ chuột ===========
void ShowCur(bool CursorVisibility)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = {1, CursorVisibility};
    SetConsoleCursorInfo(handle, &cursor);
}

void ShowCurAtXY(int x, int y, bool show)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(console, &cursorInfo);
    cursorInfo.bVisible = show;
    SetConsoleCursorInfo(console, &cursorInfo);
    if (show)
    {
        gotoxy(x, y);
    }
}
//========== in giữa ============
void CoutCentered(std::string text)
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);                           // Get the console handle.
    PCONSOLE_SCREEN_BUFFER_INFO lpScreenInfo = new CONSOLE_SCREEN_BUFFER_INFO(); // Create a pointer to the Screen Info pointing to a temporal screen info.
    GetConsoleScreenBufferInfo(hConsole, lpScreenInfo);                          // Saves the console screen info into the lpScreenInfo pointer.
    COORD NewSBSize = lpScreenInfo->dwSize;                                      // Gets the size of the screen
    if (NewSBSize.X > text.size())
    {
        int newpos = ((NewSBSize.X - text.size()) / 2); // Calculate the number of spaces to center the specific text.
        for (int i = 0; i < newpos; i++)
            std::cout << " "; // Prints the spaces
    }
    std::cout << text << std::endl; // Prints the text centered :]
}
// Hàm lấy width của console
int getConsoleWidth()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int width = 0;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    {
        width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }
    return width;
}
// Hàm lấy height của console
int getConsoleHeight()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int height = 0;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    {
        height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    }
    return height;
}
/*===============các hằng số định nghĩa sẵn dùng tô màu===============
// Màu chữ
FOREGROUND_BLUE: Màu xanh dương
FOREGROUND_GREEN : Màu xanh lá
FOREGROUND_RED : Màu đỏ
FOREGROUND_INTENSITY: Tăng cường độ sáng cho màu
// Màu nền
BACKGROUND_BLUE: Màu nền xanh dương
BACKGROUND_GREEN: Màu nền xanh lá
BACKGROUND_RED: Màu nền đỏ
BACKGROUND_INTENSITY: Tăng cường độ sáng cho màu nền
*/
void fillConsoleWithColor(WORD color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int width = getConsoleWidth();
    int height = getConsoleHeight();
    int consoleSize = width * height;
    DWORD charsWritten;
    FillConsoleOutputAttribute(hConsole, color, consoleSize, {0, 0}, &charsWritten);
    SetConsoleCursorPosition(hConsole, {0, 0});
}