#include "doHoa.cpp"
#include "../libraries/khaibao.h"

const int Collums = 20;
const int Rows = 7;
const int Header_x = 20;
const int Header_y = 6;
const int CTNNV = 4;

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESC 27
#define F1 59
#define F2 60
#define F3 61
#define F4 62

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
// int menuChinhDong(char menuchinh[YeuCauChinh][100])
// {
//     Normal();
//     int choice = 0;
//     system("cls");
//     gotoxy(Header_x, Header_y);

//     const int menuSpacing = 2; // Khoảng cách giữa các mục menu

//     // Hiển thị menu theo chiều ngang
//     int positions[YeuCauChinh]; // Lưu vị trí x của mỗi mục menu
//     for (int i = 0; i < YeuCauChinh; i++)
//     {
//         int menuWidth = strlen(menuchinh[i]) - 1 + 2; // Chiều rộng của mỗi mục menu
//         int x = Collums + (i > 0 ? menuSpacing : 0);
//         for (int j = 0; j < i; j++)
//         {
//             x += strlen(menuchinh[j]) + 2 + menuSpacing; // Cộng dồn chiều rộng các menu trước đó
//         }

//         positions[i] = x; // Lưu vị trí x
//         drawHCN(x, Rows, menuWidth, 2);
//         gotoxy(x + 1, Rows + 1);
//         cout << menuchinh[i];
//     }

//     // Hàm để highlight hoặc unhighlight một mục menu
//     auto highlightMenuItem = [&](int index, bool isHighlight)
//     {
//         int x = positions[index];
//         int menuWidth = strlen(menuchinh[index]) - 1 + 2;
//         if (isHighlight)
//         {
//             Highlight(LIGHTBLUE);
//         }
//         else
//         {
//             Normal();
//         }
//         drawHCN(x, Rows, menuWidth, 2);
//         gotoxy(x + 1, Rows + 1);
//         cout << menuchinh[index];
//     };

//     // Highlight mục đầu tiên
//     highlightMenuItem(choice, true);

//     char direction;
//     do
//     {
//         direction = getch();

//         switch (direction)
//         {
//         case LEFT:
//             if (choice > 0)
//             {
//                 highlightMenuItem(choice, false); // Unhighlight mục hiện tại
//                 choice--;
//                 highlightMenuItem(choice, true); // Highlight mục mới
//             }
//             break;
//         case RIGHT:
//             if (choice < YeuCauChinh - 1)
//             {
//                 highlightMenuItem(choice, false); // Unhighlight mục hiện tại
//                 choice++;
//                 highlightMenuItem(choice, true); // Highlight mục mới
//             }
//             break;
//         case ENTER:
//             Normal();
//             return choice;
//         }
//     } while (true);
// }
int menuChinhDong(char menuchinh[YeuCauChinh][100])
{
    Normal();
    int choice = 0;
    system("cls");
    gotoxy(Header_x, Header_y);
    for (int i = 0; i < YeuCauChinh; i++)
    {
        gotoxy(Collums, Rows + i);
        cout << menuchinh[i];
    }

    Highlight(LIGHTBLUE);
    gotoxy(Collums, Rows + choice);
    cout << menuchinh[choice];

    char direction;
    do
    {
        direction = getch();

        switch (direction)
        {
        case UP:
            if (choice + 1 > 1)
            {
                Normal();
                gotoxy(Collums, Rows + choice);
                cout << menuchinh[choice];
                choice--;
                Highlight(LIGHTBLUE);
                gotoxy(Collums, Rows + choice);
                cout << menuchinh[choice];
            }
            else
            {
                choice = YeuCauChinh - 1;
                Normal();
                gotoxy(Collums, Rows + 0);
                cout << menuchinh[0];
                Highlight(LIGHTBLUE);
                gotoxy(Collums, Rows + choice);
                cout << menuchinh[choice];
            }
            break;
        case DOWN:
            if (choice + 1 < YeuCauChinh)
            {
                Normal();
                gotoxy(Collums, Rows + choice);
                cout << menuchinh[choice];
                choice++;
                Highlight(LIGHTBLUE);
                gotoxy(Collums, Rows + choice);
                cout << menuchinh[choice];
            }
            else
            {
                choice = 0;
                Normal();
                gotoxy(Collums, Rows + YeuCauChinh - 1);
                cout << menuchinh[YeuCauChinh - 1];
                Highlight(LIGHTBLUE);
                gotoxy(Collums, Rows + choice);
                cout << menuchinh[choice];
            }
            break;
        case ENTER:
            Normal();
            return choice;
        }
    } while (true);
}

int MenuVatTuDong(char menuvattu[YeuCauVatTu][100])
{
    Normal();
    int choice = 0;
    // system("cls");
    Highlight(LIGHTGREEN);
    gotoxy(Header_x, Header_y);
    Normal();
    for (int i = 0; i < YeuCauVatTu; i++)
    {
        gotoxy(Collums + 10, Rows + i);
        cout << menuvattu[i];
    }

    Highlight(LIGHTBLUE);
    gotoxy(Collums + 10, Rows + choice);
    cout << menuvattu[choice];

    char direction;
    do
    {
        direction = getch();
        switch (direction)
        {
        case UP:
            if (choice + 1 > 1)
            {
                Normal();
                gotoxy(Collums + 10, Rows + choice);
                cout << menuvattu[choice];
                choice--;
                Highlight(LIGHTBLUE);
                gotoxy(Collums + 10, Rows + choice);
                cout << menuvattu[choice];
            }
            else
            {
                choice = YeuCauVatTu - 1;
                Normal();
                gotoxy(Collums + 10, Rows + 0);
                cout << menuvattu[0];
                Highlight(LIGHTBLUE);
                gotoxy(Collums + 10, Rows + choice);
                cout << menuvattu[choice];
            }
            break;
        case DOWN:
            if (choice + 1 < YeuCauVatTu)
            {
                Normal();
                gotoxy(Collums + 10, Rows + choice);
                cout << menuvattu[choice];
                choice++;
                Highlight(LIGHTBLUE);
                gotoxy(Collums + 10, Rows + choice);
                cout << menuvattu[choice];
            }
            else
            {
                choice = 0;
                Normal();
                gotoxy(Collums + 10, Rows + YeuCauVatTu - 1);
                cout << menuvattu[YeuCauVatTu - 1];
                Highlight(LIGHTBLUE);
                gotoxy(Collums + 10, Rows + choice);
                cout << menuvattu[choice];
            }
            break;
        case ENTER:
            Normal();
            return choice + 1;
        }
    } while (true);
}

int MenuNhanVienDong(char menunhanvien[YeuCauNhanVien][100])
{
    Normal();
    int choice = 0;
    system("cls");
    gotoxy(Header_x, Header_y);
    cout << "MENU NHÂN VIÊN";

    for (int i = 0; i < YeuCauNhanVien; i++)
    {
        gotoxy(Collums, Rows + i);
        cout << menunhanvien[i];
    }

    Highlight(LIGHTBLUE);
    gotoxy(Collums, Rows + choice);
    cout << menunhanvien[choice];

    char direction;
    do
    {
        direction = getch();

        switch (direction)
        {
        case UP:
            if (choice + 1 > 1)
            {
                Normal();
                gotoxy(Collums, Rows + choice);
                cout << menunhanvien[choice];

                choice--;
                Highlight(LIGHTBLUE);
                gotoxy(Collums, Rows + choice);
                cout << menunhanvien[choice];
                break;
            }
        case DOWN:
            if (choice < YeuCauNhanVien)
            {
                Normal();
                gotoxy(Collums, Rows + choice);
                cout << menunhanvien[choice];

                choice++;
                Highlight(LIGHTBLUE);
                gotoxy(Collums, Rows + choice);
                cout << menunhanvien[choice];
                break;
            }
        case ENTER:
            Normal();
            return choice + 1;
        }
    } while (true);
}

int MenuHoaDonDong(char menuhoadon[YeuCauHoaDon][100])
{
    Normal();
    int choice = 0;
    system("cls");
    gotoxy(Header_x, Header_y);
    cout << "MENU HÓA ĐƠN";

    for (int i = 0; i < YeuCauHoaDon; i++)
    {
        gotoxy(Collums, Rows + i);
        cout << menuhoadon[i];
    }

    Highlight(LIGHTBLUE);
    gotoxy(Collums, Rows + choice);
    cout << menuhoadon[choice];

    char direction;
    do
    {
        direction = getch();

        switch (direction)
        {
        case UP:
            if (choice + 1 > 1)
            {
                Normal();
                gotoxy(Collums, Rows + choice);
                cout << menuhoadon[choice];

                choice--;
                Highlight(LIGHTBLUE);
                gotoxy(Collums, Rows + choice);
                cout << menuhoadon[choice];
                break;
            }
        case DOWN:
            if (choice < YeuCauHoaDon)
            {
                Normal();
                gotoxy(Collums, Rows + choice);
                cout << menuhoadon[choice];

                choice++;
                Highlight(LIGHTBLUE);
                gotoxy(Collums, Rows + choice);
                cout << menuhoadon[choice];
                break;
            }
        case ENTER:
            Normal();
            return choice + 1;
        }
    } while (true);
}

int MenuThongKeDong(char menuthongke[YeuCauThongKe][100])
{
    Normal();
    int choice = 0;
    system("cls");
    gotoxy(Header_x, Header_y);
    cout << "MENU THỐNG KÊ";

    for (int i = 0; i < YeuCauThongKe; i++)
    {
        gotoxy(Collums, Rows + i);
        cout << menuthongke[i];
    }

    Highlight(LIGHTBLUE);
    gotoxy(Collums, Rows + choice);
    cout << menuthongke[choice];

    char direction;
    do
    {
        direction = getch();

        switch (direction)
        {
        case UP:
            if (choice + 1 > 1)
            {
                Normal();
                gotoxy(Collums, Rows + choice);
                cout << menuthongke[choice];

                choice--;
                Highlight(LIGHTBLUE);
                gotoxy(Collums, Rows + choice);
                cout << menuthongke[choice];
                break;
            }
        case DOWN:
            if (choice < YeuCauThongKe)
            {
                Normal();
                gotoxy(Collums, Rows + choice);
                cout << menuthongke[choice];

                choice++;
                Highlight(LIGHTBLUE);
                gotoxy(Collums, Rows + choice);
                cout << menuthongke[choice];
                break;
            }
        case ENTER:
            Normal();
            return choice + 1;
        }
    } while (true);
}

void HeaderPrint(char header[CTNNV][50])
{
    system("cls");
    Normal();
    drawHCN(1, 1, 53, 2);
    gotoxy(5, 2);
    cout << char(179);
    gotoxy(22, 2);
    cout << char(179);
    gotoxy(48, 2);
    cout << char(179);
    gotoxy(2, 2);
    cout << header[0];
    gotoxy(8, 2);
    cout << header[1];
    gotoxy(31, 2);
    cout << header[2];
    gotoxy(49, 2);
    cout << header[3];
}
void PrintNhanien(dsNhanVien list)
{
    char Header[CTNNV][50] =
        {
            "STT",
            "MÃ NHÂN VIÊN",
            "HỌ VÀ TÊN",
            "PHÁI",
        };
    HeaderPrint(Header);
}

int main()
{
    ShowCur(false);
    int chon = 0;
    while (1)
    {
        chon = menuChinhDong(MenuChinh);
        // system("cls");
        switch (chon)
        {
        case 1:
            chon = MenuVatTuDong(MenuVatTu);
            break;
        case 2:
            cout << 2;
            break;
        case 3:
            cout << 3;
            break;
        case 4:
            cout << 4;
            break;
        }
    };
    // int a;
    // while (1)
    // {
    //     a = inputKey();
    //     if (a != -1)
    //         cout << a << endl;
    // }
    return 0;
}