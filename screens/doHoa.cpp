#include "../libraries/mylib.h"
#include <thread>
#include <chrono>
void drawScreen();
void drawBox();
void colorDefault();
void setFullScreenColor(int color);

//=====================================
COORD GetConsoleSize()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    return {static_cast<SHORT>(columns), static_cast<SHORT>(rows)};
}
COORD currentSize = GetConsoleSize();
int previousWidth = currentSize.X;
int previousHeight = currentSize.Y;
void colorDefault()
{
    SetBGColor(15);
}
void setFullScreenColor(int color)
{
    // COORD currentSize = GetConsoleSize();
    // int previousWidth = currentSize.X;
    // int previousHeight = currentSize.Y;
    for (int ix = 0; ix < previousWidth; ix++)
    {
        for (int iy = 0; iy < previousHeight; iy++)
        {
            SetBGColor(color);
            cout << " ";
        }
    }
}
int main()
{

    while (1)
    {
        
        currentSize = GetConsoleSize();
        int currentWidth = currentSize.X;
        int currentHeight = currentSize.Y;

        // Kiểm tra nếu kích thước thay đổi, thì cập nhật giao diện
        if (currentWidth != previousWidth || currentHeight != previousHeight)
        {
            system("cls"); // Xóa màn hình (Windows)

            // In ra nội dung được căn giữa theo kích thước mới
            setFullScreenColor(7);
            SetColor(1);
            gotoxy(1, 1);
            cout << "hi";
            getch();

            // Cập nhật kích thước trước đó
            previousWidth = currentWidth;
            previousHeight = currentHeight;
        }

        // Tạm dừng một chút để không tiêu tốn quá nhiều tài nguyên CPU
        // std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}