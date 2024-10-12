#include <windows.h>
#include <iostream>
using namespace std;
const int x = 5;
const int y = 5;
const int w = 100;
const int h = 20;
COORD GetConsoleSize()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    return {static_cast<SHORT>(columns), static_cast<SHORT>(rows)};
}
int main()
{
    
    int previousWidth, previousHeight;
    int tempW, tempH;
    do
    {
        COORD currentSize = GetConsoleSize();
        previousWidth = currentSize.X;
        previousHeight = currentSize.Y;
        if (tempW != previousWidth)
        {
            cout << previousWidth << endl;
            tempW = previousWidth;
        }
        if (tempH != previousHeight)
        {
            cout << previousHeight;
            tempH = previousHeight;
        }
    } while (1);
}