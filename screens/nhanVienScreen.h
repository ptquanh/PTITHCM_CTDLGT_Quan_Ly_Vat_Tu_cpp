#pragma once
#include "../sources/nhanVien.h"
void drawKeysGuideNhanVien(int x, int y)
{
    int space = 4;
    setColorByRequest(LIGHTGRAY, BROWN);
    drawHCN(x, y + 25, 8, 2);
    setColorByRequest(LIGHTGRAY, DARKGRAY);
    drawHCN(x + 8 + space, y + 25, 12, 2);
    drawHCN(x + 20 + 2 * space, y + 25, 11, 2);
    drawHCN(x + 31 + 3 * space, y + 25, 12, 2);
    drawHCN(x + 43 + 4 * space, y + 25, 15, 2);
    drawHCN(x + 58 + 5 * space, y + 25, 14, 2);
    drawHCN(x + 99, y + 25, 11, 2);
    setColorByRequest(BROWN, BLACK);
    gotoxy(x + 1, y + 26);
    cout << "MENU NV";
    setColorByRequest(LIGHTGRAY, BLACK);
    gotoxy(x + 8 + space + 1, y + 26);
    cout << "F3: Nhap NV";
    gotoxy(x + 20 + 2 * space + 1, y + 26);
    cout << "F4: Sua NV";
    gotoxy(x + 31 + 3 * space + 1, y + 26);
    cout << "DEL: Xoa NV";
    gotoxy(x + 43 + 4 * space + 1, y + 26);
    cout << "F5: Tim ten NV";
    gotoxy(x + 58 + 5 * space + 1, y + 26);
    cout << "F10: Luu file";
    gotoxy(x + 100, y + 26);
    cout << "ESC: Thoat";
}
void drawKeysGuideListNhanVien(int x, int y)
{
    int space = 4;
    setColorByRequest(LIGHTGRAY, BROWN);
    drawHCN(x, y + 25, 8, 2);
    setColorByRequest(LIGHTGRAY, DARKGRAY);
    drawHCN(x + 58 + 5 * space, y + 25, 14, 2);
    drawHCN(x + 99, y + 25, 11, 2);
    setColorByRequest(BROWN, BLACK);
    gotoxy(x + 1, y + 26);
    cout << "MENU NV";
    setColorByRequest(LIGHTGRAY, BLACK);
    gotoxy(x + 58 + 5 * space + 1, y + 26);
    cout << "F10: Luu file";
    gotoxy(x + 100, y + 26);
    cout << "ESC: Thoat";
}
void drawTableUpdateNhanVien(int x, int y)
{
    setColorByRequest(LIGHTGRAY, DARKGRAY);
    drawHCN(x + 69, y, 41, 15);
    drawHCN(x + 87, y + 12, 9, 2);
    drawHCN(x + 99, y + 12, 9, 2);
    SetColor(BLACK);
    gotoxy(x + 88, y + 13);
    cout << "ESC: Huy";
    gotoxy(x + 100, y + 13);
    cout << "F10: Luu";
    SetColor(GREEN);
    gotoxy(x + 71, y + 5);
    cout << "Toi da 10 ki tu";
    gotoxy(x + 71, y + 7);
    cout << "Toi da 20 ki tu";
    gotoxy(x + 71, y + 9);
    cout << "Toi da 6 ki tu";
    gotoxy(x + 71, y + 11);
    cout << "Nam / Nu";
    SetColor(BLACK);
    gotoxy(x + 82, y + 2);
    cout << "CAP NHAT NHAN VIEN";
    gotoxy(x + 71, y + 4);
    cout << "MA NHAN VIEN   :";
    gotoxy(x + 71, y + 6);
    cout << "HO NHAN VIEN   :";
    gotoxy(x + 71, y + 8);
    cout << "TEN NHAN VIEN  :";
    gotoxy(x + 71, y + 10);
    cout << "PHAI NHAN VIEN :";
    // to mau trang
    for (int i = x + 87; i < x + 109; i++)
    {
        SetBGColor(BLACK);
        gotoxy(i, y + 4);
        cout << " ";
        gotoxy(i, y + 6);
        cout << " ";
        gotoxy(i, y + 8);
        cout << " ";
        gotoxy(i, y + 10);
        cout << " ";
    }
}

void drawTablePrintNhanVien(int x, int y, int w, int h)
{
    setColorByRequest(LIGHTGRAY, DARKGRAY);
    drawHCN(x, y, (w * 4) + 2, h);
    horizontalLine(x + 1, y + 2, ((w * 4) + 2) - 1);
    // ve vien
    gotoxy(x, y + 2);
    cout << tRight;
    gotoxy(x + (w * 4) + 2, y + 2);
    cout << tLeft;
    gotoxy(x + (((w * 4)) - 45), y);
    cout << tDown;
    gotoxy(x + (((w * 4)) - 45), y + h);
    cout << tUp;
    gotoxy(x + (((w * 4) + 2) - 22), y);
    cout << tDown;
    gotoxy(x + (((w * 4) + 2) - 22), y + h);
    cout << tUp;
    gotoxy(x + (((w * 4) + 2) - 11), y);
    cout << tDown;
    gotoxy(x + (((w * 4) + 2) - 11), y + h);
    cout << tUp;
    verticalLine(x + (((w * 4)) - 45), y + 1, h - 1);
    verticalLine(x + (((w * 4) + 2) - 22), y + 1, h - 1);
    verticalLine(x + (((w * 4) + 2) - 11), y + 1, h - 1);
    gotoxy(x + (((w * 4)) - 45), y + 2);
    cout << cross;
    gotoxy(x + (((w * 4) + 2) - 22), y + 2);
    cout << cross;
    gotoxy(x + (((w * 4) + 2) - 11), y + 2);
    cout << cross;
    // ve header 0
    setColorByRequest(LIGHTGRAY, RED);
    gotoxy(x + 20, y - 1);
    cout << "---DANH SACH NHAN VIEN---";
    gotoxy(x + 3, y + 1);
    cout << "MA NV";
    // ve header 1
    gotoxy(x + 18, y + 1);
    cout << "HO NV";
    // ve header 2
    gotoxy(x + 43, y + 1);
    cout << "TEN NV";
    // ve header 3
    gotoxy(x + 54, y + 1);
    cout << "PHAI";
}
void drawTableSearchTenNhanVien(int x, int y)
{
    setColorByRequest(LIGHTGRAY, DARKGRAY);
    drawHCN(x + 69, y, 41, 9);
    drawHCN(x + 85, y + 6, 9, 2);
    drawHCN(x + 97, y + 6, 11, 2);
    SetColor(BLACK);
    gotoxy(x + 86, y + 7);
    cout << "ESC: Huy";
    gotoxy(x + 98, y + 7);
    cout << "ENTER: Tim";
    SetColor(GREEN);
    gotoxy(x + 71, y + 5);
    cout << "Toi da 20 ki tu";
    SetColor(BLACK);
    gotoxy(x + 82, y + 2);
    cout << "TIM KIEM NHAN VIEN";
    gotoxy(x + 71, y + 4);
    cout << "TEN NHAN VIEN  :";
    // to mau trang
    for (int i = x + 87; i < x + 109; i++)
    {
        SetBGColor(BLACK);
        gotoxy(i, y + 4);
        cout << " ";
    }
}

void handleNavigationSearchNhanVien(dsNhanVien &dsnv, int x, int y)
{
    nhanVien *result;
    drawTableSearchTenNhanVien(x, y);
    drawTablePrintNhanVien(x, y, 15, 23);
    bool isESC = false, isSaved = false;
    timKiemTenNhanVien(dsnv, x, y, result, isESC);
    ShowCur(false);
    if (isESC)
    {

        drawTableErrors("Dang thoat chuong trinh...", true);
        Sleep(1500);
        drawTableErrors("", true);
        clearTablePrint(x);
        fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
        return;
    }
    else
    {
        drawTableErrors("F4 sua, DEL xoa", true);
        Sleep(1500);
        drawTableErrors("", true);
        char key;
        while (true)
        {
            key = _getch();
            switch (key)
            {
            case F4:
                drawTableErrors("Dang den trang sua vat tu", true);
                Sleep(1500);
                drawTableErrors("", true);
                fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                drawTableUpdateVatTu(x, y);
                // suaVatTu(root, result->data_vt.MAVT, x, y, isESC, isSaved);
                ShowCur(false);
                if (isESC)
                {
                    drawTableErrors("Dang thoat chuong trinh...", true);
                    Sleep(1500);
                    drawTableErrors("", true);
                    clearTablePrint(x);
                    fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                    return;
                }
                if (isSaved)
                {
                    drawTableErrors("Sua vat tu thanh cong", true);
                    Sleep(1500);
                    drawTableErrors("", true);
                    fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                    clearTablePrint(x);
                    return;
                }
                break;
            case DEL:
                drawTableErrors("Dang den trang xoa vat tu", true);
                Sleep(1500);
                drawTableErrors("", true);
                fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                drawTableUpdateVatTu(x, y);
                // xoaVatTu(root, result->data_vt.MAVT, x, y, isESC, isSaved);
                ShowCur(false);
                if (isESC)
                {
                    drawTableErrors("Dang thoat chuong trinh...", true);
                    Sleep(1500);
                    drawTableErrors("", true);
                    clearTablePrint(x);
                    fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                    return;
                }
                if (isSaved)
                {
                    drawTableErrors("Xoa vat tu thanh cong", true);
                    Sleep(1500);
                    drawTableErrors("", true);
                    fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                    clearTablePrint(x);
                    return;
                }
                break;
            case ESC:
                drawTableErrors("Dang thoat chuong trinh...", true);
                Sleep(1500);
                drawTableErrors("", true);
                clearTablePrint(x);
                fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                return;
            }
        }
    }
}
void handleNavigationAddNhanVien(dsNhanVien &dsnv, int x, int y)
{
    drawTableUpdateNhanVien(x, y);
    nhapNhanVien(dsnv, x, y);
    clearTablePrint(x);
}

void handleNavigationUpdateNhanVien(dsNhanVien &dsnv, int &currentPage, int x, int y)
{
    int n = dsnv.countNV;
    string errorMessage;
    string currentMANV;
    int totalPages = ceil((float)n / ROWS);
    currentPage = 1;
    int selectedRow = 0;
    char key;
    int currentChoice = -1;
    drawTableUpdateNhanVien(x, y);
    while (true)
    {
        bool isESC, isSaved = false;
        inDanhSachNhanVien(dsnv, currentPage, selectedRow, x, errorMessage);
        key = getch();
        switch (key)
        {
        case LEFT:
            if (currentPage > 1)
            {
                currentPage--;
                selectedRow = 0;
                clearTablePrint(x);
            }
            break;
        case RIGHT:
            if (currentPage < totalPages)
            {
                currentPage++;
                selectedRow = 0;
                clearTablePrint(x);
            }
            break;
        case UP:
            if (selectedRow > 0)
            {
                selectedRow--;
            }
            else
            {
                int itemsOnPage = min(ROWS, n - (currentPage - 1) * ROWS);
                selectedRow = itemsOnPage - 1;
            }
            break;
        case DOWN:
        {
            int itemsOnPage = min(ROWS, n - (currentPage - 1) * ROWS);
            if (selectedRow < itemsOnPage - 1)
            {
                selectedRow++;
            }
            else
            {
                selectedRow = 0;
            }
        }
        break;
        case ENTER:
            currentChoice = (currentPage - 1) * ROWS + selectedRow;
            for (int i = x + 87; i < x + 109; i++)
            {
                SetBGColor(BLACK);
                gotoxy(i, y + 4);
                cout << " ";
                gotoxy(i, y + 6);
                cout << " ";
                gotoxy(i, y + 8);
                cout << " ";
                gotoxy(i, y + 10);
                cout << " ";
            }
            setColorByRequest(BLACK, WHITE);
            currentMANV = dsnv.nodes[currentChoice]->MANV;
            suaNhanVien(dsnv, currentMANV, x, y, isESC, isSaved);
            ShowCur(false);
            if (isESC)
            {
                errorMessage = "Dang thoat chuong trinh...";
                drawTableErrors(errorMessage, true);
                Sleep(1500);
                drawTableErrors("", true);
                fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                return;
            }
            if (isSaved)
            {
                n = dsnv.countNV;
                totalPages = ceil((float)n / ROWS);
                if (currentPage > totalPages)
                {
                    currentPage = totalPages;
                }
                if (selectedRow >= min(ROWS, n - (currentPage - 1) * ROWS))
                {
                    selectedRow = min(ROWS, n - (currentPage - 1) * ROWS) - 1;
                }
                errorMessage = "Sua vat tu thanh cong";
                drawTableErrors(errorMessage, true);
                Sleep(1500);
                drawTableErrors("", true);
                fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                clearTablePrint(x);
                return;
            }
            break;
        case TAB:
            currentPage = pageSearchByTab(x, currentPage, totalPages, errorMessage);
            break;
        case ESC:
            errorMessage = "Dang thoat chuong trinh...";
            drawTableErrors(errorMessage, true);
            Sleep(1500);
            drawTableErrors("", true);
            fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
            return;
        }
    }
}

void handleNavigationDeleteNhanVien(dsNhanVien &dsnv, int &currentPage, int x, int y)
{
    int n = dsnv.countNV;
    string errorMessage;
    string currentMANV;
    int totalPages = ceil((float)n / ROWS);
    currentPage = 1;
    int selectedRow = 0;
    char key;
    int currentChoice = -1;
    drawTableUpdateNhanVien(x, y);
    while (true)
    {
        bool isESC, isSaved = false;
        inDanhSachNhanVien(dsnv, currentPage, selectedRow, x, errorMessage);
        key = getch();
        switch (key)
        {
        case LEFT:
            if (currentPage > 1)
            {
                currentPage--;
                selectedRow = 0;
                clearTablePrint(x);
            }
            break;
        case RIGHT:
            if (currentPage < totalPages)
            {
                currentPage++;
                selectedRow = 0;
                clearTablePrint(x);
            }
            break;
        case UP:
            if (selectedRow > 0)
            {
                selectedRow--;
            }
            else
            {
                int itemsOnPage = min(ROWS, n - (currentPage - 1) * ROWS);
                selectedRow = itemsOnPage - 1;
            }
            break;
        case DOWN:
        {
            int itemsOnPage = min(ROWS, n - (currentPage - 1) * ROWS);
            if (selectedRow < itemsOnPage - 1)
            {
                selectedRow++;
            }
            else
            {
                selectedRow = 0;
            }
        }
        break;
        case ENTER:
            currentChoice = (currentPage - 1) * ROWS + selectedRow;
            for (int i = x + 87; i < x + 109; i++)
            {
                SetBGColor(BLACK);
                gotoxy(i, y + 4);
                cout << " ";
                gotoxy(i, y + 6);
                cout << " ";
                gotoxy(i, y + 8);
                cout << " ";
                gotoxy(i, y + 10);
                cout << " ";
            }
            currentMANV = dsnv.nodes[currentChoice]->MANV;
            gotoxy(0, 3);
            setColorByRequest(BLACK, WHITE);
            xoaNhanVien(dsnv, currentMANV, x, y, isESC, isSaved);
            ShowCur(false);
            if (isESC)
            {
                errorMessage = "Dang thoat chuong trinh...";
                drawTableErrors(errorMessage, true);
                Sleep(1500);
                drawTableErrors("", true);
                fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                return;
            }
            if (isSaved)
            {
                n = dsnv.countNV;
                totalPages = ceil((float)n / ROWS);
                if (currentPage > totalPages)
                {
                    currentPage = totalPages;
                }
                if (selectedRow >= min(ROWS, n - (currentPage - 1) * ROWS))
                {
                    selectedRow = min(ROWS, n - (currentPage - 1) * ROWS) - 1;
                }
                errorMessage = "Xoa vat tu thanh cong";
                drawTableErrors(errorMessage, true);
                Sleep(1500);
                drawTableErrors("", true);
                fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                clearTablePrint(x);
                return;
            }
            break;
        case TAB:
            currentPage = pageSearchByTab(x, currentPage, totalPages, errorMessage);
            break;
        case ESC:
            errorMessage = "Dang thoat chuong trinh...";
            drawTableErrors(errorMessage, true);
            Sleep(1500);
            drawTableErrors("", true);
            fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
            return;
        }
    }
}

void handleNavigationListNhanVien(dsNhanVien dsnv, int x, int y)
{
    string errorMessage;
    int n = dsnv.countNV;
    int totalPages = ceil((float)n / ROWS);
    int currentPage = 1;
    int selectedRow = -1;
    char key;
    int currentChoice = -1;
    drawTablePrintNhanVien(x, y, 15, 23);
    drawKeysGuideListNhanVien(x,y);
    while (true)
    {
        setColorByRequest(LIGHTGRAY, BLACK);
        inDanhSachNhanVien(dsnv, currentPage, selectedRow, x, errorMessage);
        key = getch();
        switch (key)
        {
        case LEFT:
            if (currentPage > 1)
            {
                currentPage--;
                clearTablePrint(x);
            }
            break;
        case RIGHT:
            if (currentPage < totalPages)
            {
                currentPage++;
                clearTablePrint(x);
            }
            break;
        case TAB:
            currentPage = pageSearchByTab(x, currentPage, totalPages, errorMessage);
            break;
        case ESC:
            errorMessage = "Dang thoat chuong trinh...";
            drawTableErrors(errorMessage, true);
            Sleep(1500);
            drawTableErrors("", true);
            fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
            return;
        }
    }
}

void menuNhanVien(dsNhanVien &dsnv, int x, int y)
{
    int n = dsnv.countNV;
    int totalPages = ceil((float)n / ROWS);
    int currentPage = 1;
    string errorMessage;
    char key;
    drawKeysGuideNhanVien(x, y);
    drawTablePrintNhanVien(x, y, 15, 23);
    while (true)
    {
        setColorByRequest(LIGHTGRAY, BLACK);
        inDanhSachNhanVien(dsnv, currentPage, -1, x, errorMessage);
        key = getch();
        switch (key)
        {
        case LEFT:
            if (currentPage > 1)
            {
                currentPage--;
                clearTablePrint(x);
            }
            break;
        case RIGHT:
            if (currentPage < totalPages)
            {
                currentPage++;
                clearTablePrint(x);
            }
            break;
        case TAB:
            currentPage = pageSearchByTab(x, currentPage, totalPages, errorMessage);
            break;
        case F3:
            handleNavigationAddNhanVien(dsnv, x, y);
            break;
        case F4:
            handleNavigationUpdateNhanVien(dsnv, currentPage, x, y);
            break;
        case DEL:
            handleNavigationDeleteNhanVien(dsnv, currentPage, x, y);
            break;
        case F5:
            handleNavigationSearchNhanVien(dsnv, x, y);
            break;
        case F10:
            writeFile_dsNhanVien(dsnv);
            break;
        case ESC:
            errorMessage = "Dang thoat chuong trinh...";
            drawTableErrors(errorMessage, true);
            Sleep(1500);
            drawTableErrors("", true);
            fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
            return;
        }
    }
}