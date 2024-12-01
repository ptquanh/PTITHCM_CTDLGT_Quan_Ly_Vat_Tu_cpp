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
void drawKeysGuideListVatTu(int x, int y)
{
    int space = 4;
    setColorByRequest(LIGHTGRAY, BROWN);
    drawHCN(x, y + 25, 7, 2);
    setColorByRequest(LIGHTGRAY, DARKGRAY);
    drawHCN(x + 99, y + 25, 11, 2);
    setColorByRequest(BROWN, BLACK);
    gotoxy(x + 1, y + 26);
    cout << "XEM VT";
    setColorByRequest(LIGHTGRAY, BLACK);
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

void drawTableInputVatTu(int x, int y)
{
    setColorByRequest(LIGHTGRAY, DARKGRAY);
    drawHCN(x + 69, y, 41, 9);
    drawHCN(x + 87, y + 6, 9, 2);
    drawHCN(x + 99, y + 6, 9, 2);
    SetColor(BLACK);
    gotoxy(x + 88, y + 7);
    cout << "ESC: Huy";
    gotoxy(x + 100, y + 7);
    cout << "F10: Luu";
    SetColor(GREEN);
    gotoxy(x + 71, y + 5);
    cout << "Toi da 10 ki tu";
    SetColor(BLACK);
    gotoxy(x + 82, y + 2);
    cout << "CAP NHAT VAT TU";
    gotoxy(x + 71, y + 4);
    cout << "NHAP MA VAT TU :";
    // to mau trang
    for (int i = x + 87; i < x + 109; i++)
    {
        SetBGColor(BLACK);
        gotoxy(i, y + 4);
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

void nhapMaVTFromUpdateVatTu(treeVatTu &root, int &currentPage, int x, int y)
{
    int n = countNodes(root);
    treeVatTu *arr = new treeVatTu[n];
    int index = 0;
    storeInorder(root, arr, &index);
    quickSortVatTu(arr, 0, n - 1);
    string errorMessage;
    string currentMAVT;
    bool moveNext = false;
    bool isActive = true;
    drawTableInputVatTu(x, y);
    displayField(x + 87, y + 4, currentMAVT, isActive, 10);
    while (true)
    {
        string result = inputString(x + 87, y + 4, currentMAVT, 10, "Ma vat tu", moveNext, true);
        for (char &c : result)
        {
            c = std::toupper(c);
        }
        if (result == "ESC")
        {
            fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
            delete[] arr;
            return;
        }
        else if (result == "F10")
        {
            treeVatTu found = search(root, currentMAVT);
            if (found != nullptr)
            {
                bool isESC = false, isSaved = false;
                fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                drawTableUpdateVatTu(x, y);
                suaVatTu(root, currentMAVT, x, y, isESC, isSaved);
                ShowCur(false);
                if (isESC)
                {
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
                    errorMessage = "Sua vat tu thanh cong";
                    drawTableErrors(errorMessage, true);
                    Sleep(1500);
                    drawTableErrors("", true);
                    fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                    clearTablePrint(x);
                    delete[] arr;
                    return;
                }
            }
            else
            {
                errorMessage = "Khong tim thay ma vat tu";
                drawTableErrors(errorMessage, true);
                Sleep(1500);
                drawTableErrors("", true);
                currentMAVT = "";
                displayField(x + 87, y + 4, currentMAVT, isActive, 10);
                continue;
            }
        }
        else
        {
            currentMAVT = result;
            displayField(x + 87, y + 4, currentMAVT, isActive, 10);
        }
    }
}

void chonMaVTFromUpdateVatTu(treeVatTu &root, int &currentPage, int x, int y)
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
    bool isESC, isSaved = false;
    drawTableUpdateVatTu(x, y);
    while (true)
    {
        inDanhSachVatTu(root, currentPage, selectedRow, x);
        setColorByRequest(LIGHTGRAY, BLACK);
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
            fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
            delete[] arr;
            return;
        }
    }
}

void handleNavigationSearchVatTu(treeVatTu &root, dsNhanVien &dsnv, int x, int y)
{
    treeVatTu result;
    drawTableSearchTenVatTu(x, y);
    drawTablePrintVatTu(x, y, 15, 23);
    bool isESC = false, isSaved = false;
    timKiemTenVatTu(root, nullptr, x, y, result, isESC);
    ShowCur(false);
    if (isESC)
    {
        clearTablePrint(x);
        fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
        return;
    }
    else
    {
        fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
        drawTableUpdateVatTu(x, y);
        fillAreaColor(x + 87, y + 12, 8, 2, LIGHTGRAY);
        setColorByRequest(LIGHTGRAY, DARKGRAY);
        drawHCN(x + 88, y + 12, 8, 2);
        setColorByRequest(LIGHTGRAY, BLACK);
        gotoxy(x + 89, y + 13);
        cout << "F4: Sua";
        gotoxy(x + 100, y + 13);
        cout << "DEL: Xoa";
        treeVatTu node = search(root, result->data_vt.MAVT);
        setColorByRequest(BLACK, WHITE);
        gotoxy(x + 88, y + 4);
        cout << node->data_vt.TENVT;
        gotoxy(x + 88, y + 6);
        cout << node->data_vt.MAVT;
        gotoxy(x + 88, y + 8);
        cout << node->data_vt.DVT;
        gotoxy(x + 88, y + 10);
        cout << node->data_vt.soLuongTon;
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
                else
                {
                    drawTableErrors("Sua vat tu khong thanh cong", true);
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
                xoaVatTu(root, dsnv, result->data_vt.MAVT, x, y, isESC, isSaved);
                ShowCur(false);
                if (isESC)
                {
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
                else
                {
                    drawTableErrors("Xoa vat tu khong thanh cong", true);
                    Sleep(1500);
                    drawTableErrors("", true);
                    fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                    clearTablePrint(x);
                    return;
                }
                break;
            case ESC:
                clearTablePrint(x);
                fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                return;
            }
        }
    }
}

void searchVTFromUpdateVatTu(treeVatTu &root, int x, int y, int currentPage, string &currentMAVT)
{
    treeVatTu result;
    int n = countNodes(root);
    treeVatTu *arr = new treeVatTu[n];
    int index = 0;
    storeInorder(root, arr, &index);
    quickSortVatTu(arr, 0, n - 1);
    int totalPages = ceil((float)n / ROWS);
    drawTableSearchTenVatTu(x, y);
    drawTablePrintVatTu(x, y, 15, 23);
    bool isESC = false, isSaved = false;
    timKiemTenVatTu(root, nullptr, x, y, result, isESC);
    ShowCur(false);
    if (isESC)
    {
        clearTablePrint(x);
        fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
        return;
    }
    else
    {
        currentMAVT = result->data_vt.MAVT;
        drawTableErrors("Lay ma vat tu thanh cong", true);
        Sleep(1500);
        drawTableErrors("", true);
        clearTablePrint(x);
        fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
        drawTableUpdateVatTu(x, y);
        setColorByRequest(LIGHTGRAY, BLACK);
        inDanhSachVatTu(root, currentPage, -1, x);
        suaVatTu(root, currentMAVT, x, y, isESC, isSaved);
        if (isESC)
        {
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
    }
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
    fillAreaColor(x, y + 25, 92, 2, LIGHTGRAY);
    int space = 8;
    setColorByRequest(LIGHTGRAY, BROWN);
    drawHCN(x, y + 25, 7, 2);
    setColorByRequest(LIGHTGRAY, DARKGRAY);
    drawHCN(x + 8 + space, y + 25, 15, 2);
    drawHCN(x + 23 + 2 * space, y + 25, 28, 2);
    drawHCN(x + 51 + 3 * space, y + 25, 15, 2);
    setColorByRequest(BROWN, BLACK);
    gotoxy(x + 1, y + 26);
    cout << "SUA VT";
    setColorByRequest(LIGHTGRAY, BLACK);
    gotoxy(x + 8 + space + 1, y + 26);
    cout << "F3: Nhap ma VT";
    gotoxy(x + 23 + 2 * space + 1, y + 26);
    cout << "F4: Chon ma VT tu danh sach";
    gotoxy(x + 51 + 3 * space + 1, y + 26);
    cout << "F5: Tim ten VT";
    bool isESC = false, isSaved = false;
    clearTablePrint(x);
    while (true)
    {
        setColorByRequest(LIGHTGRAY, BLACK);
        inDanhSachVatTu(root, currentPage, -1, x);
        key = getch();
        switch (key)
        {
        case F3:
            nhapMaVTFromUpdateVatTu(root, currentPage, x, y);
            break;
        case F4:
            chonMaVTFromUpdateVatTu(root, currentPage, x, y);
            break;
        case F5:
            searchVTFromUpdateVatTu(root, x, y, currentPage, currentMAVT);
            break;
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
        case TAB:
            currentPage = pageSearchByTab(x, currentPage, totalPages, errorMessage);
            break;
        case ESC:
            fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
            delete[] arr;
            return;
        }
    }
}

void nhapMaVTFromDeleteVatTu(treeVatTu &root, dsNhanVien &dsnv, int &currentPage, int x, int y)
{
    int n = countNodes(root);
    treeVatTu *arr = new treeVatTu[n];
    int index = 0;
    storeInorder(root, arr, &index);
    quickSortVatTu(arr, 0, n - 1);
    string errorMessage;
    string currentMAVT;
    bool moveNext = false;
    bool isActive = true;
    drawTableInputVatTu(x, y);
    displayField(x + 87, y + 4, currentMAVT, isActive, 10);
    while (true)
    {
        string result = inputString(x + 87, y + 4, currentMAVT, 10, "Ma vat tu", moveNext, true);
        for (char &c : result)
        {
            c = std::toupper(c);
        }
        if (result == "ESC")
        {
            ShowCur(false);
            fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
            delete[] arr;
            return;
        }
        else if (result == "F10")
        {
            ShowCur(false);
            treeVatTu found = search(root, currentMAVT);
            if (found != nullptr)
            {
                bool isESC = false, isSaved = false;
                fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                drawTableUpdateVatTu(x, y);
                xoaVatTu(root, dsnv, currentMAVT, x, y, isESC, isSaved);
                ShowCur(false);
                if (isESC)
                {
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
                    errorMessage = "Xoa vat tu thanh cong";
                    drawTableErrors(errorMessage, true);
                    Sleep(1500);
                    drawTableErrors("", true);
                    fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                    clearTablePrint(x);
                    delete[] arr;
                    return;
                }
                else
                {
                    ShowCur(false);
                    return;
                }
            }
            else
            {
                errorMessage = "Khong tim thay ma vat tu";
                drawTableErrors(errorMessage, true);
                Sleep(1500);
                drawTableErrors("", true);
                currentMAVT = "";
                displayField(x + 87, y + 4, currentMAVT, isActive, 10);
                continue;
            }
        }
        else
        {
            currentMAVT = result;
            displayField(x + 87, y + 4, currentMAVT, isActive, 10);
        }
    }
}

void chonMaVTFromDeleteVatTu(treeVatTu &root, dsNhanVien &dsnv, int &currentPage, int x, int y)
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
    bool isESC, isSaved = false;
    drawTableUpdateVatTu(x, y);

    while (true)
    {
        inDanhSachVatTu(root, currentPage, selectedRow, x);
        setColorByRequest(LIGHTGRAY, BLACK);
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
            xoaVatTu(root, dsnv, currentMAVT, x, y, isESC, isSaved);
            ShowCur(false);
            if (isESC)
            {
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
            else
            {
                selectedRow = -1;
                return;
            }
            break;
        case TAB:
            currentPage = pageSearchByTab(x, currentPage, totalPages, errorMessage);
            break;
        case ESC:
            fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
            delete[] arr;
            return;
        }
    }
}

void searchVTFromDeleteVatTu(treeVatTu &root, dsNhanVien &dsnv, int x, int y, int currentPage, string &currentMAVT)
{
    treeVatTu result;
    int n = countNodes(root);
    treeVatTu *arr = new treeVatTu[n];
    int index = 0;
    storeInorder(root, arr, &index);
    quickSortVatTu(arr, 0, n - 1);
    int totalPages = ceil((float)n / ROWS);
    drawTableSearchTenVatTu(x, y);
    drawTablePrintVatTu(x, y, 15, 23);
    bool isESC = false, isSaved = false;
    timKiemTenVatTu(root, nullptr, x, y, result, isESC);
    ShowCur(false);
    if (isESC)
    {
        clearTablePrint(x);
        fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
        return;
    }
    else
    {
        currentMAVT = result->data_vt.MAVT;
        drawTableErrors("Lay ma vat tu thanh cong", true);
        Sleep(1500);
        drawTableErrors("", true);
        clearTablePrint(x);
        fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
        drawTableUpdateVatTu(x, y);
        setColorByRequest(LIGHTGRAY, BLACK);
        inDanhSachVatTu(root, currentPage, -1, x);
        xoaVatTu(root, dsnv, currentMAVT, x, y, isESC, isSaved);
        if (isESC)
        {
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
    }
}

void handleNavigationDeleteVatTu(treeVatTu &root, dsNhanVien &dsnv, int &currentPage, int x, int y)
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

    fillAreaColor(x, y + 25, 92, 2, LIGHTGRAY);
    int space = 8;
    setColorByRequest(LIGHTGRAY, BROWN);
    drawHCN(x, y + 25, 7, 2);
    setColorByRequest(LIGHTGRAY, DARKGRAY);
    drawHCN(x + 8 + space, y + 25, 15, 2);
    drawHCN(x + 23 + 2 * space, y + 25, 28, 2);
    drawHCN(x + 51 + 3 * space, y + 25, 15, 2);

    setColorByRequest(BROWN, BLACK);
    gotoxy(x + 1, y + 26);
    cout << "XOA VT";
    setColorByRequest(LIGHTGRAY, BLACK);
    gotoxy(x + 8 + space + 1, y + 26);
    cout << "F3: Nhap ma VT";
    gotoxy(x + 23 + 2 * space + 1, y + 26);
    cout << "F4: Chon ma VT tu danh sach";
    gotoxy(x + 51 + 3 * space + 1, y + 26);
    cout << "F5: Tim ten VT";
    bool isESC = false, isSaved = false;
    clearTablePrint(x);
    while (true)
    {
        setColorByRequest(LIGHTGRAY, BLACK);
        inDanhSachVatTu(root, currentPage, -1, x);
        key = getch();
        switch (key)
        {
        case F3:
            nhapMaVTFromDeleteVatTu(root, dsnv, currentPage, x, y);
            break;
        case F4:
            chonMaVTFromDeleteVatTu(root, dsnv, currentPage, x, y);
            break;
        case F5:
            searchVTFromDeleteVatTu(root, dsnv, x, y, currentPage, currentMAVT);
            break;
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
        case TAB:
            currentPage = pageSearchByTab(x, currentPage, totalPages, errorMessage);
            break;
        case ESC:
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
    drawKeysGuideListVatTu(x, y);
    while (true)
    {
        setColorByRequest(LIGHTGRAY, BLACK);
        inDanhSachVatTu(root, currentPage, selectedRow, x);
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
            delete[] arr;
            return;
        }
    }
}

void menuVatTu(treeVatTu &root, dsNhanVien &dsnv, int x, int y)
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
        inDanhSachVatTu(root, currentPage, -1, x);
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
            fillAreaColor(x, y + 25, 92, 2, LIGHTGRAY);
            drawKeysGuideVatTu(x, y);
            break;
        case DEL:
            handleNavigationDeleteVatTu(root, dsnv, currentPage, x, y);
            fillAreaColor(x, y + 25, 92, 2, LIGHTGRAY);
            drawKeysGuideVatTu(x, y);
            break;
        case F5:
            handleNavigationSearchVatTu(root, dsnv, x, y);
            break;
        case F10:
            writeFile_dsVatTu(root);
            drawTableErrors("Ghi vat tu vao file thanh cong", true);
            Sleep(1500);
            drawTableErrors("", true);
            fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
            break;
        case ESC:
            fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
            delete[] arr;
            return;
        }
    }
}