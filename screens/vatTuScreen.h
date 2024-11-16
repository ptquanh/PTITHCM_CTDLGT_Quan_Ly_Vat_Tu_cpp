#pragma once
#include "../sources/vatTu.h"
void drawKeysGuideVatTu(int x, int y)
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
    cout << "MENU VT";
    setColorByRequest(LIGHTGRAY, BLACK);
    gotoxy(x + 8 + space + 1, y + 26);
    cout << "F3: Nhap VT";
    gotoxy(x + 20 + 2 * space + 1, y + 26);
    cout << "F4: Sua VT";
    gotoxy(x + 31 + 3 * space + 1, y + 26);
    cout << "DEL: Xoa VT";
    gotoxy(x + 43 + 4 * space + 1, y + 26);
    cout << "F5: Tim ten VT";
    gotoxy(x + 58 + 5 * space + 1, y + 26);
    cout << "F10: Luu file";
    gotoxy(x + 100, y + 26);
    cout << "ESC: Thoat";
}

void drawTableSearchTenVatTu(int x, int y)
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
    cout << "TIM KIEM VAT TU";
    gotoxy(x + 71, y + 4);
    cout << "TEN VAT TU     :";
    // to mau trang
    for (int i = x + 87; i < x + 109; i++)
    {
        SetBGColor(BLACK);
        gotoxy(i, y + 4);
        cout << " ";
    }
}

void drawTableAddVatTuInCTHD(int x, int y)
{
    setColorByRequest(LIGHTGRAY, DARKGRAY);
    drawHCN(x + 69, y, 41, 13);
    drawHCN(x + 87, y + 10, 9, 2);
    drawHCN(x + 99, y + 10, 9, 2);
    SetColor(BLACK);
    gotoxy(x + 88, y + 11);
    cout << "ESC: Huy";
    gotoxy(x + 100, y + 11);
    cout << "F10: Luu";
    SetColor(GREEN);
    gotoxy(x + 71, y + 5);
    cout << "Toi da 10 ki tu";
    gotoxy(x + 71, y + 7);
    cout << "Toi da 20 ki tu";
    gotoxy(x + 71, y + 9);
    cout << "Toi da 6 ki tu";
    SetColor(BLACK);
    gotoxy(x + 82, y + 2);
    cout << "THEM VAT TU";
    gotoxy(x + 71, y + 4);
    cout << "MA VAT TU      :";
    gotoxy(x + 71, y + 6);
    cout << "TEN VAT TU     :";
    gotoxy(x + 71, y + 8);
    cout << "DON VI TINH    :";
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
    }
}

void drawTableUpdateVatTu(int x, int y)
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
    cout << "Toi da 6 chu so";
    SetColor(BLACK);
    gotoxy(x + 82, y + 2);
    cout << "CAP NHAT VAT TU";
    gotoxy(x + 71, y + 4);
    cout << "MA VAT TU      :";
    gotoxy(x + 71, y + 6);
    cout << "TEN VAT TU     :";
    gotoxy(x + 71, y + 8);
    cout << "DON VI TINH    :";
    gotoxy(x + 71, y + 10);
    cout << "SO LUONG TON   :";
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

void drawTablePrintVatTu(int x, int y, int w, int h)
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
    cout << "---DANH SACH VAT TU---";
    gotoxy(x + 3, y + 1);
    cout << "MA VT";
    // ve header 1
    gotoxy(x + 18, y + 1);
    cout << "TEN VT";
    // ve header 2
    gotoxy(x + 43, y + 1);
    cout << "DVT";
    // ve header 3
    gotoxy(x + 54, y + 1);
    cout << "SL";
}

void handleNavigationAddVatTu(treeVatTu &root, int x, int y)
{
    drawTableUpdateVatTu(x, y);
    nhapVatTu(root, x, y, "", 0, true, false);
    clearTablePrint(x);
}

void handleNavigationUpdateVatTu(treeVatTu &root, int &currentPage, int x, int y)
{
    int n = countNodes(root);
    treeVatTu *arr = new treeVatTu[n];
    int index = 0;
    storeInorder(root, arr, &index);
    quickSortVatTu(arr, 0, n - 1);
    string errorMessage;
    string currentMAVT;
    int totalPages = ceil((float)n / ROWS);
    currentPage = 1;
    int selectedRow = 0;
    char key;
    int currentChoice = -1;
    drawTableUpdateVatTu(x, y);
    while (true)
    {
        bool isESC, isSaved = false;
        inDanhSachVatTu(root, currentPage, selectedRow, x, errorMessage);
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
            currentMAVT = arr[currentChoice]->data_vt.MAVT;
            suaVatTu(root, currentMAVT, x, y, isESC, isSaved);
            ShowCur(false);
            if (isESC)
            {
                errorMessage = "Dang thoat chuong trinh...";
                drawTableErrors(errorMessage, true);
                Sleep(1500);
                drawTableErrors("", true);
                fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                delete[] arr;
                return;
            }
            if (isSaved)
            {
                delete[] arr;
                n = countNodes(root);
                arr = new treeVatTu[n];
                index = 0;
                storeInorder(root, arr, &index);
                quickSortVatTu(arr, 0, n - 1);
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
                delete[] arr;
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
            delete[] arr;
            return;
        }
    }
}

void handleNavigationDeleteVatTu(treeVatTu &root, int &currentPage, int x, int y)
{
    int n = countNodes(root);
    treeVatTu *arr = new treeVatTu[n];
    int index = 0;
    storeInorder(root, arr, &index);
    quickSortVatTu(arr, 0, n - 1);
    string errorMessage;
    string currentMAVT;
    int totalPages = ceil((float)n / ROWS);
    currentPage = 1;
    int selectedRow = 0;
    char key;
    int currentChoice = -1;
    drawTableUpdateVatTu(x, y);
    while (true)
    {
        bool isESC, isSaved = false;
        inDanhSachVatTu(root, currentPage, selectedRow, x, errorMessage);
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
            currentMAVT = arr[currentChoice]->data_vt.MAVT;
            gotoxy(0, 3);
            setColorByRequest(BLACK, WHITE);
            xoaVatTu(root, currentMAVT, x, y, isESC, isSaved);
            ShowCur(false);
            if (isESC)
            {
                errorMessage = "Dang thoat chuong trinh...";
                drawTableErrors(errorMessage, true);
                Sleep(1500);
                drawTableErrors("", true);
                fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                delete[] arr;
                return;
            }
            if (isSaved)
            {
                delete[] arr;
                n = countNodes(root);
                arr = new treeVatTu[n];
                index = 0;
                storeInorder(root, arr, &index);
                quickSortVatTu(arr, 0, n - 1);
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
                delete[] arr;
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
            delete[] arr;
            return;
        }
    }
}

void handleNavigationListVatTu(treeVatTu root, int x, int y)
{
    string errorMessage;
    int n = countNodes(root);
    treeVatTu *arr = new treeVatTu[n];
    int index = 0;
    storeInorder(root, arr, &index);
    quickSortVatTu(arr, 0, n - 1);

    int totalPages = ceil((float)n / ROWS);
    int currentPage = 1;
    int selectedRow = -1;
    char key;
    int currentChoice = -1;
    drawTablePrintVatTu(x, y, 15, 23);
    while (true)
    {
        setColorByRequest(LIGHTGRAY, BLACK);
        inDanhSachVatTu(root, currentPage, selectedRow, x, errorMessage);
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
            delete[] arr;
            return;
        }
    }
}

void handleNavigationSearchVatTu(treeVatTu &root, int x, int y)
{
    treeVatTu result;
    drawTableSearchTenVatTu(x, y);
    drawTablePrintVatTu(x, y, 15, 23);
    bool isESC = false, isSaved = false;
    timKiemTenVatTu(root, x, y, result, isESC);
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
                suaVatTu(root, result->data_vt.MAVT, x, y, isESC, isSaved);
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
                xoaVatTu(root, result->data_vt.MAVT, x, y, isESC, isSaved);
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

void menuVatTu(treeVatTu &root, int x, int y)
{
    int n = countNodes(root);
    treeVatTu *arr = new treeVatTu[n];
    int index = 0;
    storeInorder(root, arr, &index);
    quickSortVatTu(arr, 0, n - 1);
    int totalPages = ceil((float)n / ROWS);
    int currentPage = 1;
    string errorMessage;
    char key;
    drawKeysGuideVatTu(x, y);
    drawTablePrintVatTu(x, y, 15, 23);
    while (true)
    {
        setColorByRequest(LIGHTGRAY, BLACK);
        inDanhSachVatTu(root, currentPage, -1, x, errorMessage);
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
            handleNavigationAddVatTu(root, x, y);
            break;
        case F4:
            handleNavigationUpdateVatTu(root, currentPage, x, y);
            break;
        case DEL:
            handleNavigationDeleteVatTu(root, currentPage, x, y);
            break;
        case F5:
            handleNavigationSearchVatTu(root, x, y);
            break;
        case F10:
            writeFile_dsVatTu(root);
            break;
        case ESC:
            errorMessage = "Dang thoat chuong trinh...";
            drawTableErrors(errorMessage, true);
            Sleep(1500);
            drawTableErrors("", true);
            fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
            delete[] arr;
            return;
        }
    }
}