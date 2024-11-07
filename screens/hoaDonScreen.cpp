#include "../sources/nhanVien.h"
void handleNavigationAddChiTietHoaDon(dsNhanVien &dsnv, treeVatTu &root, int x, int y);
void handleNavigationUpdateChiTietHoaDon(dsNhanVien &dsnv, int x, int y);
void handleNavigationDeleteChiTietHoaDon(dsNhanVien &dsnv, int x, int y);
void handleNavigationListChiTietHoaDon(dsNhanVien dsnv, treeVatTu root, int x, int y);
void menuChiTietHoaDon(dsNhanVien &dsnv, int x, int y);

void clearTablePrintChiTietHoaDon(int x)
{
    SetBGColor(LIGHTGRAY);
    for (int currentRow = 12; currentRow <= HDROWS + 11; currentRow++)
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
        for (int i = x + 63; i < x + 71; i++)
        {
            gotoxy(i, currentRow);
            cout << " ";
        }
    }
}
void drawTableInputSoHD(int x, int y)
{
    setColorByRequest(LIGHTGRAY, DARKGRAY);
    drawHCN(x + 76, y, 41, 9);
    drawHCN(x + 104, y + 6, 11, 2);
    drawHCN(x + 92, y + 6, 9, 2);
    SetColor(BLACK);
    gotoxy(x + 93, y + 7);
    cout << "ESC: Huy";
    gotoxy(x + 105, y + 7);
    cout << "ENTER: Tim";
    SetColor(GREEN);
    gotoxy(x + 78, y + 5);
    cout << "Toi da 20 ki tu";
    SetColor(BLACK);
    gotoxy(x + 82, y + 2);
    cout << "XEM CHI TIET HOA DON";
    gotoxy(x + 78, y + 4);
    cout << "SO HOA DON     :";
    // to mau trang
    for (int i = x + 94; i < x + 116; i++)
    {
        SetBGColor(BLACK);
        gotoxy(i, y + 4);
        cout << " ";
    }
}
void drawTableUpdateChiTietHoaDon(int x, int y)
{
    setColorByRequest(LIGHTGRAY, DARKGRAY);
    drawHCN(x + 76, y, 41, 15);
    drawHCN(x + 107, y + 12, 8, 2);
    drawHCN(x + 95, y + 12, 9, 2);
    SetColor(BLACK);
    gotoxy(x + 96, y + 13);
    cout << "ESC: Huy";
    gotoxy(x + 108, y + 13);
    cout << "F4: Luu";
    SetColor(GREEN);
    gotoxy(x + 78, y + 5);
    cout << "Toi da 10 ki tu";
    gotoxy(x + 78, y + 7);
    cout << "Toi da 20 ki tu";
    gotoxy(x + 78, y + 9);
    cout << "Toi da 6 ki tu";
    gotoxy(x + 78, y + 11);
    cout << "0: Nam - 1: Nu";
    SetColor(BLACK);
    gotoxy(x + 82, y + 2);
    cout << "CAP NHAT CHI TIET HOA DON";
    gotoxy(x + 78, y + 4);
    cout << "MA VAT TU      :";
    gotoxy(x + 78, y + 6);
    cout << "SO LUONG       :";
    gotoxy(x + 78, y + 8);
    cout << "THUE VAT       :";
    gotoxy(x + 78, y + 10);
    cout << "DON GIA        :";
    // to mau trang
    for (int i = x + 94; i < x + 116; i++)
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
void drawTableUpdateHoaDon(int x, int y)
{
    setColorByRequest(LIGHTGRAY, DARKGRAY);
    drawHCN(x + 76, y, 41, 17);
    drawHCN(x + 107, y + 14, 8, 2);
    drawHCN(x + 95, y + 14, 9, 2);
    SetColor(BLACK);
    gotoxy(x + 96, y + 15);
    cout << "ESC: Huy";
    gotoxy(x + 108, y + 15);
    cout << "F4: Luu";
    SetColor(GREEN);
    gotoxy(x + 78, y + 5);
    cout << "Toi da 10 ki tu";
    gotoxy(x + 78, y + 7);
    cout << "Toi da 2 chu so";
    gotoxy(x + 78, y + 9);
    cout << "Toi da 2 chu so";
    gotoxy(x + 78, y + 11);
    cout << "Toi da 4 chu so";
    gotoxy(x + 78, y + 13);
    cout << "N: Nhap - X: Xuat";
    SetColor(BLACK);
    gotoxy(x + 82, y + 2);
    cout << "CAP NHAT HOA DON";
    gotoxy(x + 78, y + 4);
    cout << "MA HOA DON     :";
    gotoxy(x + 78, y + 6);
    cout << "NGAY           :";
    gotoxy(x + 78, y + 8);
    cout << "THANG          :";
    gotoxy(x + 78, y + 10);
    cout << "NAM            :";
    gotoxy(x + 78, y + 12);
    cout << "LOAI           :";
    // to mau trang
    for (int i = x + 94; i < x + 116; i++)
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
        gotoxy(i, y + 12);
        cout << " ";
    }
}
void drawTablePrintChiTietHoaDon(int x, int y, int w, int h)
{
    setColorByRequest(LIGHTGRAY, DARKGRAY);
    drawHCN(x, y, (w * 4) + 13, h + 1);
    horizontalLine(x + 1, y + 8, ((w * 4) + 13) - 1);
    horizontalLine(x + 1, y + 10, ((w * 4) + 13) - 1);
    horizontalLine(x + 1, y + h - 1, ((w * 4) + 13) - 1);
    // ve vien
    gotoxy(x, y + 8);
    cout << tRight;
    gotoxy(x + (w * 4) + 13, y + 8);
    cout << tLeft;
    gotoxy(x, y + 10);
    cout << tRight;
    gotoxy(x + (w * 4) + 13, y + 10);
    cout << tLeft;
    gotoxy(x + (((w * 4)) - 45), y + 8);
    cout << tDown;
    gotoxy(x + (((w * 4)) - 45), y + h - 1);
    cout << tUp;
    gotoxy(x + (((w * 4) + 2) - 22), y + 8);
    cout << tDown;
    gotoxy(x + (((w * 4) + 2) - 22), y + h - 1);
    cout << tUp;
    gotoxy(x + (((w * 4) + 2) - 11), y + 8);
    cout << tDown;
    gotoxy(x + (((w * 4) + 2) - 11), y + h - 1);
    cout << tUp;
    gotoxy(x + (((w * 4) + 2)), y + 8);
    cout << tDown;
    gotoxy(x + (((w * 4) + 2)), y + h - 1);
    cout << tUp;
    verticalLine(x + (((w * 4)) - 45), y + 9, h - 10);
    verticalLine(x + (((w * 4) + 2) - 22), y + 9, h - 10);
    verticalLine(x + (((w * 4) + 2) - 11), y + 9, h - 10);
    verticalLine(x + (((w * 4) + 2)), y + 9, h - 10);
    gotoxy(x + (((w * 4)) - 45), y + 10);
    cout << cross;
    gotoxy(x + (((w * 4) + 2) - 22), y + 10);
    cout << cross;
    gotoxy(x + (((w * 4) + 2) - 11), y + 10);
    cout << cross;
    gotoxy(x + (((w * 4) + 2)), y + 10);
    cout << cross;
    setColorByRequest(LIGHTGRAY, RED);
    gotoxy(x + 3, y + 1);
    cout << "SO HOA DON:         LOAI:";
    gotoxy(x + 3, y + 3);
    cout << "MA NHAN VIEN       :";
    gotoxy(x + 3, y + 5);
    cout << "HO TEN NHAN VIEN   :";
    gotoxy(x + 3, y + 7);
    cout << "NGAY:         THANG:        NAM:";
    gotoxy(x + 3, y + 9);
    cout << "MA VT";
    gotoxy(x + 18, y + 9);
    cout << "TEN VT";
    gotoxy(x + 43, y + 9);
    cout << "SL";
    gotoxy(x + 54, y + 9);
    cout << "DON GIA";
    gotoxy(x + 65, y + 9);
    cout << "TRI GIA";
    gotoxy(x + 3, y + h);
    cout << "TONG TRI GIA:";
}

void drawTablePrintHoaDon(int x, int y, int w, int h)
{
    setColorByRequest(LIGHTGRAY, DARKGRAY);
    drawHCN(x, y, (w * 4) + 13, h + 1);
    horizontalLine(x + 1, y + 8, ((w * 4) + 13) - 1);
    horizontalLine(x + 1, y + 10, ((w * 4) + 13) - 1);
    horizontalLine(x + 1, y + h - 1, ((w * 4) + 13) - 1);
    // ve vien
    gotoxy(x, y + 8);
    cout << tRight;
    gotoxy(x + (w * 4) + 13, y + 8);
    cout << tLeft;
    gotoxy(x, y + 10);
    cout << tRight;
    gotoxy(x + (w * 4) + 13, y + 10);
    cout << tLeft;
    gotoxy(x + (((w * 4)) - 45), y + 8);
    cout << tDown;
    gotoxy(x + (((w * 4)) - 45), y + h - 1);
    cout << tUp;
    gotoxy(x + (((w * 4) + 2) - 22), y + 8);
    cout << tDown;
    gotoxy(x + (((w * 4) + 2) - 22), y + h - 1);
    cout << tUp;
    gotoxy(x + (((w * 4) + 2) - 11), y + 8);
    cout << tDown;
    gotoxy(x + (((w * 4) + 2) - 11), y + h - 1);
    cout << tUp;
    gotoxy(x + (((w * 4) + 2)), y + 8);
    cout << tDown;
    gotoxy(x + (((w * 4) + 2)), y + h - 1);
    cout << tUp;
    verticalLine(x + (((w * 4)) - 45), y + 9, h - 10);
    verticalLine(x + (((w * 4) + 2) - 22), y + 9, h - 10);
    verticalLine(x + (((w * 4) + 2) - 11), y + 9, h - 10);
    verticalLine(x + (((w * 4) + 2)), y + 9, h - 10);
    gotoxy(x + (((w * 4)) - 45), y + 10);
    cout << cross;
    gotoxy(x + (((w * 4) + 2) - 22), y + 10);
    cout << cross;
    gotoxy(x + (((w * 4) + 2) - 11), y + 10);
    cout << cross;
    gotoxy(x + (((w * 4) + 2)), y + 10);
    cout << cross;
    setColorByRequest(LIGHTGRAY, RED);
    gotoxy(x + 3, y + 1);
    cout << "SO HOA DON       LOAI";
    gotoxy(x + 3, y + 3);
    cout << "MA NHAN VIEN       :";
    gotoxy(x + 3, y + 5);
    cout << "HO TEN NHAN VIEN   :";
    gotoxy(x + 3, y + 7);
    cout << "NGAY   THANG   NAM";
    // gotoxy(x + 3, y + 9);
    // cout << "MA VT";
    // gotoxy(x + 18, y + 9);
    // cout << "TEN VT";
    // gotoxy(x + 43, y + 9);
    // cout << "SL";
    // gotoxy(x + 54, y + 9);
    // cout << "DON GIA";
    // gotoxy(x + 65, y + 9);
    // cout << "TRI GIA";
    // gotoxy(x + 3, y + h);
    // cout << "TONG TRI GIA:";
}
void handleNavigationAddChiTietHoaDon(dsNhanVien &dsnv, treeVatTu &root, int x, int y)
{
    drawTableUpdateChiTietHoaDon(x, y);
    // lapHoaDon(dsnv, root, x, y);
    clearTablePrintChiTietHoaDon(x);
}

void handleNavigationUpdateChiTietHoaDon(dsNhanVien &dsnv, int x, int y)
{
    int n = dsnv.CountNV;
    string errorMessage;
    string currentMANV;
    int totalPages = ceil((float)n / ROWS);
    int currentPage = 1;
    int selectedRow = 0;
    char key;
    int currentChoice = -1;
    drawTableUpdateChiTietHoaDon(x, y);
    while (true)
    {
        bool isESC, isSaved = false;
        // inDanhSachNhanVien(dsnv, currentPage, selectedRow, x, errorMessage);
        key = getch();
        switch (key)
        {
        case LEFT:
            if (currentPage > 1)
            {
                currentPage--;
                selectedRow = 0;
                clearTablePrintChiTietHoaDon(x);
            }
            break;
        case RIGHT:
            if (currentPage < totalPages)
            {
                currentPage++;
                selectedRow = 0;
                clearTablePrintChiTietHoaDon(x);
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
            gotoxy(0, 0);
            cout << currentMANV;
            suaNhanVien(dsnv, currentMANV, x, y, isESC, isSaved);
            ShowCur(false);
            if (isESC)
            {
                errorMessage = "Dang thoat chuong trinh...";
                // drawTableErrors(5, 2, errorMessage);
                Sleep(1500);
                errorMessage = "";
                // drawTableErrors(5, 2, errorMessage);
                fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                return;
            }
            if (isSaved)
            {
                n = dsnv.CountNV;
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
                // drawTableErrors(5, 2, errorMessage);
                Sleep(1500);
                errorMessage = "";
                // drawTableErrors(5, 2, errorMessage);
                fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                clearTablePrintChiTietHoaDon(x);
                return;
            }
            break;
        case TAB:
            currentPage = pageSearchByTab(x, currentPage, totalPages, errorMessage);
            break;
        case ESC:
            errorMessage = "Dang thoat chuong trinh...";
            // drawTableErrors(5, 2, errorMessage);
            Sleep(1500);
            errorMessage = "";
            // drawTableErrors(5, 2, errorMessage);
            fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
            return;
        }
    }
}

void handleNavigationDeleteChiTietHoaDon(dsNhanVien &dsnv, int x, int y)
{
    int n = dsnv.CountNV;
    string errorMessage;
    string currentMANV;
    int totalPages = ceil((float)n / ROWS);
    int currentPage = 1;
    int selectedRow = 0;
    char key;
    int currentChoice = -1;
    drawTableUpdateChiTietHoaDon(x, y);
    while (true)
    {
        bool isESC, isSaved = false;
        // inDanhSachNhanVien(dsnv, currentPage, selectedRow, x, errorMessage);
        key = getch();
        switch (key)
        {
        case LEFT:
            if (currentPage > 1)
            {
                currentPage--;
                selectedRow = 0;
                clearTablePrintChiTietHoaDon(x);
            }
            break;
        case RIGHT:
            if (currentPage < totalPages)
            {
                currentPage++;
                selectedRow = 0;
                clearTablePrintChiTietHoaDon(x);
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
                // drawTableErrors(5, 2, errorMessage);
                Sleep(1500);
                errorMessage = "";
                // drawTableErrors(5, 2, errorMessage);
                fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                return;
            }
            if (isSaved)
            {
                n = dsnv.CountNV;
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
                // drawTableErrors(5, 2, errorMessage);
                Sleep(1500);
                errorMessage = "";
                // drawTableErrors(5, 2, errorMessage);
                fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                clearTablePrintChiTietHoaDon(x);
                return;
            }
            break;
        case TAB:
            currentPage = pageSearchByTab(x, currentPage, totalPages, errorMessage);
            break;
        case ESC:
            errorMessage = "Dang thoat chuong trinh...";
            // drawTableErrors(5, 2, errorMessage);
            Sleep(1500);
            errorMessage = "";
            // drawTableErrors(5, 2, errorMessage);
            fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
            return;
        }
    }
}
void handleNavigationListChiTietHoaDon(dsNhanVien dsnv, treeVatTu root, int x, int y)
{
    string errorMessage;
    int totalPages = 1;
    int currentPage = 1;
    int selectedRow = -1;
    char key;
    bool isESC = false, isSaved = false, isInputting = true;
    string storedSoHD = "";

    drawTablePrintChiTietHoaDon(x, y, 15, 23);
    drawTableInputSoHD(x, y);
    setColorByRequest(LIGHTGRAY, BLACK);

    while (true)
    {
        if (isInputting)
        {
            inHoaDon(dsnv, root, currentPage, selectedRow, totalPages, x, y, errorMessage, isESC, isSaved, isInputting);
            if (isESC)
            {
                errorMessage = "Dang thoat chuong trinh...";
                drawTableErrors(errorMessage, false);
                Sleep(1500);
                drawTableErrors("", false);
                fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                return;
            }
        }
        key = getch();
        switch (key)
        {
        case LEFT:
            if (currentPage > 1)
            {
                currentPage--;
                clearTablePrintChiTietHoaDon(x);
                isInputting = false;
                inHoaDon(dsnv, root, currentPage, selectedRow, totalPages, x, y, errorMessage, isESC, isSaved, isInputting);
            }
            break;

        case RIGHT:
            if (currentPage < totalPages)
            {
                currentPage++;
                clearTablePrintChiTietHoaDon(x);
                isInputting = false;
                inHoaDon(dsnv, root, currentPage, selectedRow, totalPages, x, y, errorMessage, isESC, isSaved, isInputting);
            }
            break;

        case TAB:
            pageSearchByTab(x, currentPage, totalPages, errorMessage);
            break;
        case ESC:
            errorMessage = "Dang thoat chuong trinh...";
            drawTableErrors(errorMessage, false);
            Sleep(1500);
            drawTableErrors("", false);
            fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
            return;
        }
    }
}
// void handleNavigationListChiTietHoaDon(dsNhanVien dsnv, treeVatTu root, int x, int y)
// {
//     string errorMessage;
//     // int n = dsnv.CountNV;
//     // int totalPages = ceil((float)n / HDROWS);
//     int totalPages;
//     int currentPage = 1;
//     int selectedRow = -1;
//     char key;
//     int currentChoice = -1;
//     drawTablePrintChiTietHoaDon(x, y, 15, 23);
//     drawTableInputSoHD(x, y);
//     bool isESC = false, isSaved = false, isInputting = true;
//     setColorByRequest(LIGHTGRAY, BLACK);
//     while (true)
//     {
//         inHoaDon(dsnv, root, currentPage, selectedRow, totalPages, x, y, errorMessage, isESC, isSaved, isInputting);
//         if (isESC)
//         {
//             errorMessage = "Dang thoat chuong trinh...";
//             drawTableErrors(errorMessage, false);
//             Sleep(1500);
//             drawTableErrors("", false);
//             fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
//             return;
//         }
//         if(!isInputting){
//         key = getch();
//         switch (key)
//         {
//         case LEFT:
//             setColorByRequest(BLACK, WHITE);
//             gotoxy(0, 0);
//             cout << "l";
//             if (currentPage > 1)
//             {
//                 currentPage--;
//                 clearTablePrintChiTietHoaDon(x);
//             }
//             break;
//         case RIGHT:
//             setColorByRequest(BLACK, WHITE);
//             gotoxy(0, 0);
//             cout << "r";
//             if (currentPage < totalPages)
//             {
//                 currentPage++;
//                 clearTablePrintChiTietHoaDon(x);
//             }
//             break;
//         case TAB:
//             currentPage = pageSearchByTab(x, currentPage, totalPages, errorMessage);
//             break;
//         case ESC:
//             errorMessage = "Dang thoat chuong trinh from handle...";
//             drawTableErrors(errorMessage, false);
//             Sleep(1500);
//             drawTableErrors("", false);
//             fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
//             return;
//         }
//         }
//     }
//     fillAreaColor(x, y, 15, 23, LIGHTGRAY);
// }

void menuChiTietHoaDon(dsNhanVien &dsnv, int x, int y)
{
    int n = dsnv.CountNV;
    int totalPages = ceil((float)n / ROWS);
    int currentPage = 1;
    string errorMessage;
    char key;
    drawTablePrintChiTietHoaDon(x, y, 15, 23);
    while (true)
    {
        setColorByRequest(LIGHTGRAY, BLACK);
        // inDanhSachNhanVien(dsnv, currentPage, -1, x, errorMessage);
        key = getch();
        switch (key)
        {
        case LEFT:
            if (currentPage > 1)
            {
                currentPage--;
                clearTablePrintChiTietHoaDon(x);
            }
            break;
        case RIGHT:
            if (currentPage < totalPages)
            {
                currentPage++;
                clearTablePrintChiTietHoaDon(x);
            }
            break;
        case TAB:
            currentPage = pageSearchByTab(x, currentPage, totalPages, errorMessage);
            break;
        case F1:
            // handleNavigationAddChiTietHoaDon(dsnv, x, y);
            break;
        case F2:
            handleNavigationUpdateChiTietHoaDon(dsnv, x, y);
            break;
        case F3:
            handleNavigationDeleteChiTietHoaDon(dsnv, x, y);
            break;
        case F5:
            gotoxy(0, 0);
            cout << "F5";
            break;
        case ESC:
            errorMessage = "Dang thoat chuong trinh...";
            // drawTableErrors(5, 2, errorMessage);
            Sleep(1500);
            errorMessage = "";
            // drawTableErrors(5, 2, errorMessage);
            fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
            return;
        }
    }
}

void drawKeysGuideChiTietHoaDon(int x, int y)
{
    int space = 6;
    setColorByRequest(LIGHTGRAY, BROWN);
    drawHCN(x, y + 26, 10, 2);
    setColorByRequest(LIGHTGRAY, DARKGRAY);
    drawHCN(x + 10 + space, y + 26, 12, 2);
    drawHCN(x + 22 + 2 * space, y + 26, 11, 2);
    drawHCN(x + 33 + 3 * space, y + 26, 11, 2);
    drawHCN(x + 44 + 4 * space, y + 26, 15, 2);
    drawHCN(x + 59 + 5 * space, y + 26, 11, 2);
    drawHCN(x + 106, y + 26, 11, 2);
    setColorByRequest(BROWN, BLACK);
    gotoxy(x + 1, y + 27);
    cout << "MENU CTHD";
    setColorByRequest(LIGHTGRAY, BLACK);
    gotoxy(x + 10 + space + 1, y + 27);
    cout << "F1: Nhap CT";
    gotoxy(x + 22 + 2 * space + 1, y + 27);
    cout << "F2: Sua CT";
    gotoxy(x + 33 + 3 * space + 1, y + 27);
    cout << "F3: Xoa CT";
    gotoxy(x + 44 + 4 * space + 1, y + 27);
    cout << "F5: Tim ten VT";
    gotoxy(x + 59 + 5 * space + 1, y + 27);
    cout << "F6: Luu HD";
    gotoxy(x + 107, y + 27);
    cout << "ESC: Thoat";
}

int main()
{
    ShowCur(false);
    dsNhanVien dsnv;
    treeVatTu root = nullptr;
    bool isOpened;
    string errorMessage;
    int x = 1;
    int y = 1;
    fillConsoleWithColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
    readFile_dsNhanVien(dsnv);
    readFile_dsVatTu(root, isOpened);
    if (!isOpened)
    {
        errorMessage = "Khong the mo file ds_NhanVien.txt";
        drawTableErrors(errorMessage, false);
        return 0;
    }
    drawTableErrors(errorMessage, false);
    drawKeysGuideChiTietHoaDon(x, y);
    handleNavigationListChiTietHoaDon(dsnv, root, x, y);
    // menuChiTietHoaDon(dsnv, x, y);
    // writeFile_dsNhanVien(dsnv);
    while (1)
    {
        getch();
    }
}