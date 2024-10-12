#include "../libraries/Frontend.h"
const int x = 0;
const int y = 0;
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
    ShowCur(false);
    int previousWidth, previousHeight;
    int tempW, tempH;
    do
    {
        system("cls");
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
            box(x, y, previousWidth - 2, previousHeight - 2);
            tempH = previousHeight;
        }
    } while (1);
}