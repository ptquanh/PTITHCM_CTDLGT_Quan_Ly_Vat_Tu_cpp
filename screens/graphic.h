#include "../libraries/khaibao.h"
#include "../libraries/mylib.h"

void SetUTF8() {
    SetConsoleOutputCP(CP_UTF8); // Chuyển sang mã hóa UTF-8
}

void SetCP437() {
    SetConsoleOutputCP(437); // Chuyển sang mã hóa CP437
}

void FillBackground(int x, int y, int w, int h, int color) {
    // Lưu màu hiện tại
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    WORD originalColor = consoleInfo.wAttributes;

    // Đặt màu nền
    SetConsoleTextAttribute(hConsole, color);

    // Tô màu cho khu vực
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            gotoxy(x + j, y + i);
            std::cout << " "; // Tô màu nền cho mỗi ô
        }
    }

    // Khôi phục màu sắc ban đầu
    SetConsoleTextAttribute(hConsole, originalColor);
}

void box(int x, int y, int w, int h) {
    SetCP437();
    for (int ix = x; ix <= x + w; ix++) {
        gotoxy(ix, y);
        cout << char(196); // Đường ngang trên
        gotoxy(ix, y + h);
        cout << char(196); // Đường ngang dưới
    }
    for (int iy = y; iy <= y + h; iy++) {
        gotoxy(x, iy);
        cout << char(179); // Đường dọc trái
        gotoxy(x + w, iy);
        cout << char(179); // Đường dọc phải
    }
    // Vẽ các góc
    gotoxy(x, y);
    cout << char(218); // Góc trên-trái
    gotoxy(x + w, y);
    cout << char(191); // Góc trên-phải
    gotoxy(x, y + h);
    cout << char(192); // Góc dưới-trái
    gotoxy(x + w, y + h);
    cout << char(217); // Góc dưới-phải
    SetUTF8();
}

// Vẽ một đường thẳng dọc
void VerticalLine(int x, int y, int length) {
    for (int i = 0; i < length; i++) {
        gotoxy(x, y + i);
        std::cout << char(179); // Ký tự đường thẳng dọc
    }
}
// Vẽ một đường thẳng ngang
void HorizontalLine(int x, int y, int length) {
    for (int i = 0; i < length; i++) {
        gotoxy(x + i, y);
        std::cout << char(196); // Ký tự đường thẳng ngang
    }
}
