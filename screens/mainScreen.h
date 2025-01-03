#pragma once
#include "doHoa.h"

int menuChinhDong(char menuchinh[YeuCauChinh][100])
{
    system("cls");
    fillConsoleWithColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
    gotoxy(55, 3);
    setColorByRequest(LIGHTGRAY, RED);
    cout << "QUAN LY VAT TU";
    gotoxy(29, 27);
    setColorByRequest(LIGHTGRAY, RED);
    cout << "PHAN TUAN QUOC ANH - N23DCCN003    NGUYEN TOAN PHUC - N23DCCN115";
    int selectedIndex = 1;
    int space = 15;
    int mainX = 10, mainY = 10;
    char direction;
    do
    {
        mainX = 10;
        for (int i = 0; i < YeuCauChinh; i++)
        {
            if (i == 0)
            {
                setColorByRequest(LIGHTGRAY, BROWN);
                drawHCN(mainX - 1, mainY - 1, strlen(menuchinh[i]) + 3, 2);
                setColorByRequest(BROWN, BLACK);
                gotoxy(mainX, mainY);
                cout << " " << menuchinh[i] << " ";
            }
            else if (i == selectedIndex)
            {
                Highlight(LIGHTBLUE);
            }
            else
            {
                setColorByRequest(LIGHTGRAY, BLACK);
            }
            if (i != 0)
            {
                gotoxy(mainX, mainY);
                cout << " " << menuchinh[i] << " ";
                drawHCN(mainX - 1, mainY - 1, strlen(menuchinh[i]) + 3, 2);
            }
            mainX += strlen(menuchinh[i]) + space;
        }
        direction = getch();
        switch (direction)
        {
        case LEFT:
            selectedIndex = (selectedIndex > 1) ? selectedIndex - 1 : YeuCauChinh - 1;
            break;
        case RIGHT:
            selectedIndex = (selectedIndex < YeuCauChinh - 1) ? selectedIndex + 1 : 1;
            break;
        case ENTER:
            return selectedIndex;
        }
    } while (true);
}

int menuVatTuDong(char menuvattu[YeuCauVatTu][100])
{
    int selectedIndex = 0;
    int space = 5;
    int mainX = 30, mainY = 15;
    char direction;
    do
    {
        mainY = 15;
        for (int i = 0; i < YeuCauVatTu; i++)
        {
            if (i == selectedIndex)
            {
                Highlight(LIGHTBLUE);
            }
            else
            {
                setColorByRequest(LIGHTGRAY, BLACK);
            }
            gotoxy(mainX, mainY);
            cout << " " << menuvattu[i] << " ";
            drawHCN(mainX - 1, mainY - 1, strlen(menuvattu[i]) + 3, 2);
            mainY += space;
        }
        direction = getch();
        switch (direction)
        {
        case UP:
            selectedIndex = (selectedIndex > 0) ? selectedIndex - 1 : YeuCauVatTu - 1;
            break;
        case DOWN:
            selectedIndex = (selectedIndex < YeuCauVatTu - 1) ? selectedIndex + 1 : 0;
            break;
        case ESC:
            return -1;
        case ENTER:
            return selectedIndex;
        }
    } while (true);
}

int menuNhanVienDong(char menunhanvien[YeuCauNhanVien][100])
{
    int selectedIndex = 0;
    int space = 5;
    int mainX = 50, mainY = 15;
    char direction;
    do
    {
        mainY = 15;
        for (int i = 0; i < YeuCauNhanVien; i++)
        {
            if (i == selectedIndex)
            {
                Highlight(LIGHTBLUE);
            }
            else
            {
                setColorByRequest(LIGHTGRAY, BLACK);
            }
            gotoxy(mainX, mainY);
            cout << " " << menunhanvien[i] << " ";
            drawHCN(mainX - 1, mainY - 1, strlen(menunhanvien[i]) + 3, 2);
            mainY += space;
        }
        direction = getch();
        switch (direction)
        {
        case UP:
            selectedIndex = (selectedIndex > 0) ? selectedIndex - 1 : YeuCauNhanVien - 1;
            break;
        case DOWN:
            selectedIndex = (selectedIndex < YeuCauNhanVien - 1) ? selectedIndex + 1 : 0;
            break;
        case ESC:
            return -1;
        case ENTER:
            return selectedIndex;
        }
    } while (true);
}

int menuHoaDonDong(char menuhoadon[YeuCauHoaDon][100])
{
    int selectedIndex = 0;
    int space = 5;
    int mainX = 70, mainY = 15;
    char direction;
    do
    {
        mainY = 15;
        for (int i = 0; i < YeuCauHoaDon; i++)
        {
            if (i == selectedIndex)
            {
                Highlight(LIGHTBLUE);
            }
            else
            {
                setColorByRequest(LIGHTGRAY, BLACK);
            }
            gotoxy(mainX, mainY);
            cout << " " << menuhoadon[i] << " ";
            drawHCN(mainX - 1, mainY - 1, strlen(menuhoadon[i]) + 3, 2);
            mainY += space;
        }
        direction = getch();
        switch (direction)
        {
        case UP:
            selectedIndex = (selectedIndex > 0) ? selectedIndex - 1 : YeuCauHoaDon - 1;
            break;
        case DOWN:
            selectedIndex = (selectedIndex < YeuCauHoaDon - 1) ? selectedIndex + 1 : 0;
            break;
        case ESC:
            return -1;
        case ENTER:
            return selectedIndex;
        }
    } while (true);
}

int menuThongKeDong(char menuthongke[YeuCauThongKe][100])
{
    int selectedIndex = 0;
    int space = 5;
    int mainX = 80, mainY = 15;
    char direction;
    do
    {
        mainY = 15;
        for (int i = 0; i < YeuCauThongKe; i++)
        {
            if (i == selectedIndex)
            {
                Highlight(LIGHTBLUE);
            }
            else
            {
                setColorByRequest(LIGHTGRAY, BLACK);
            }
            gotoxy(mainX, mainY);
            cout << " " << menuthongke[i] << " ";
            drawHCN(mainX - 1, mainY - 1, strlen(menuthongke[i]) + 3, 2);
            mainY += space;
        }
        direction = getch();
        switch (direction)
        {
        case UP:
            selectedIndex = (selectedIndex > 0) ? selectedIndex - 1 : YeuCauThongKe - 1;
            break;
        case DOWN:
            selectedIndex = (selectedIndex < YeuCauThongKe - 1) ? selectedIndex + 1 : 0;
            break;
        case ESC:
            return -1;
        case ENTER:
            return selectedIndex;
        }
    } while (true);
}
