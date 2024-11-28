#pragma once
#include "../sources/hoaDon.h"
#include "./nhanVienScreen.h"
void drawKeysGuideChiTietHoaDon(int x, int y)
{
    int space = 6;
    setColorByRequest(LIGHTGRAY, BROWN);
    drawHCN(x, y + 26, 10, 2);
    setColorByRequest(LIGHTGRAY, DARKGRAY);
    drawHCN(x + 10 + space, y + 26, 12, 2);
    drawHCN(x + 22 + 2 * space, y + 26, 11, 2);
    drawHCN(x + 33 + 3 * space, y + 26, 12, 2);
    drawHCN(x + 45 + 4 * space, y + 26, 15, 2);
    drawHCN(x + 60 + 5 * space, y + 26, 12, 2);
    drawHCN(x + 107, y + 26, 11, 2);
    setColorByRequest(BROWN, BLACK);
    gotoxy(x + 1, y + 27);
    cout << "MENU CTHD";
    setColorByRequest(LIGHTGRAY, BLACK);
    gotoxy(x + 10 + space + 1, y + 27);
    cout << "F3: Nhap CT";
    gotoxy(x + 22 + 2 * space + 1, y + 27);
    cout << "F4: Sua CT";
    gotoxy(x + 33 + 3 * space + 1, y + 27);
    cout << "DEL: Xoa CT";
    gotoxy(x + 45 + 4 * space + 1, y + 27);
    cout << "F5: Tim ten VT";
    gotoxy(x + 60 + 5 * space + 1, y + 27);
    cout << "F10: Luu HD";
    gotoxy(x + 108, y + 27);
    cout << "ESC: Thoat";
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
    drawHCN(x + 76, y, 41, 17);
    drawHCN(x + 94, y + 14, 9, 2);
    drawHCN(x + 106, y + 14, 9, 2);
    SetColor(BLACK);
    gotoxy(x + 95, y + 15);
    cout << "ESC: Huy";
    gotoxy(x + 107, y + 15);
    cout << "F10: Luu";
    SetColor(GREEN);
    gotoxy(x + 78, y + 5);
    cout << "Toi da 20 ki tu";
    gotoxy(x + 78, y + 7);
    cout << "Toi da 10 ki tu";
    gotoxy(x + 78, y + 9);
    cout << "Toi da 6 chu so";
    gotoxy(x + 78, y + 11);
    cout << "Toi da 3 chu so";
    gotoxy(x + 78, y + 13);
    cout << "Toi da 9 chu so";
    SetColor(BLACK);
    gotoxy(x + 82, y + 2);
    cout << "CAP NHAT CHI TIET HOA DON";
    gotoxy(x + 78, y + 4);
    cout << "TEN VAT TU     :";
    gotoxy(x + 78, y + 6);
    cout << "MA VAT TU      :";
    gotoxy(x + 78, y + 8);
    cout << "SO LUONG       :";
    gotoxy(x + 78, y + 10);
    cout << "THUE VAT %     :";
    gotoxy(x + 78, y + 12);
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
        gotoxy(i, y + 12);
        cout << " ";
    }
}

void drawTableUpdateHoaDon(int x, int y)
{
    setColorByRequest(LIGHTGRAY, DARKGRAY);
    drawHCN(x + 76, y, 41, 17);
    drawHCN(x + 94, y + 14, 9, 2);
    drawHCN(x + 106, y + 14, 9, 2);
    SetColor(BLACK);
    gotoxy(x + 95, y + 15);
    cout << "ESC: Huy";
    gotoxy(x + 107, y + 15);
    cout << "F10: Luu";
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
    gotoxy(x + 23, y - 1);
    cout << "CAP NHAT CHI TIET HOA DON";
    gotoxy(x + 3, y + 1);
    cout << "SO HOA DON:                      LOAI:";
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
    setColorByRequest(LIGHTGRAY, RED);
    gotoxy(x + 3, y + 1);
    cout << "SO HOA DON:                      LOAI:";
    gotoxy(x + 3, y + 3);
    cout << "MA NHAN VIEN       :";
    gotoxy(x + 3, y + 5);
    cout << "HO TEN NHAN VIEN   :";
    gotoxy(x + 3, y + 7);
    cout << "NGAY:         THANG:        NAM:";
}

void nhapMaNVFromAddHoaDon(dsNhanVien &dsnv, treeVatTu &root, ptr_DSHD &new_hd, string &currentMANV, int x, int y, bool &isSaved)
{
    nhanVien *nv;
    string errorMessage;
    bool moveNext = false;
    bool isActive = true;
    bool isESC;
    x = 5, y = 2;
    drawTableInputNhanVien(x, y);
    displayField(x + 87, y + 4, currentMANV, isActive, 10);
    while (true)
    {
        string result = inputString(x + 87, y + 4, currentMANV, 10, "Ma nhan vien", moveNext, true);
        for (char &c : result)
        {
            c = std::toupper(c);
        }
        ShowCur(false);
        if (result == "ESC")
        {
            isSaved = false;
            fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
            return;
        }
        else if (result == "F10")
        {
            int index = searchNhanVien(dsnv, currentMANV);
            if (index != -1)
            {
                fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                drawTableUpdateNhanVien(x, y);
                setColorByRequest(BLACK, WHITE);
                gotoxy(x + 88, y + 4);
                cout << dsnv.nodes[index]->MANV;
                gotoxy(x + 88, y + 6);
                cout << dsnv.nodes[index]->HO;
                gotoxy(x + 88, y + 8);
                cout << dsnv.nodes[index]->TEN;
                gotoxy(x + 88, y + 10);
                cout << dsnv.nodes[index]->PHAI;
                while (true)
                {
                    char key = getch();
                    switch (key)
                    {
                    case F10:
                        fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                        x = 1, y = 1;
                        lapHoaDon(dsnv, root, index, new_hd, x, y, isESC, isSaved);
                        ShowCur(false);
                        isSaved = true;
                        return;
                    case ESC:
                        ShowCur(false);
                        fillAreaColor(x + 76, y, 41, 17, LIGHTGRAY);
                        isSaved = false;
                        return;
                    }
                }
            }
            else
            {
                isSaved = false;
                errorMessage = "Khong tim thay ma nhan vien";
                drawTableErrors(errorMessage, true);
                Sleep(1500);
                drawTableErrors("", true);
                currentMANV = "";
                displayField(x + 87, y + 4, currentMANV, isActive, 10);
                continue;
            }
        }
        else
        {
            isSaved = false;
            currentMANV = result;
            displayField(x + 87, y + 4, currentMANV, isActive, 10);
        }
    }
}

void chonMaNVFromAddHoaDon(dsNhanVien &dsnv, treeVatTu &root, ptr_DSHD &new_hd, string &currentMANV, int x, int y, bool &isSaved)
{
    int n = dsnv.countNV;
    string errorMessage;
    int totalPages = ceil((float)n / ROWS);
    int currentPage = 1;
    int selectedRow = 0;
    char key;
    int currentChoice = -1;
    nhanVien *nv;
    int index;
    bool isESC;
    drawTablePrintNhanVien(x + 4, y + 1, 15, 23);
    while (true)
    {
        isSaved = false;
        inDanhSachNhanVien(dsnv, currentPage, selectedRow, x + 4);
        key = getch();
        switch (key)
        {
        case LEFT:
            if (currentPage > 1)
            {
                currentPage--;
                selectedRow = 0;
                clearTablePrint(x + 4);
            }
            break;
        case RIGHT:
            if (currentPage < totalPages)
            {
                currentPage++;
                selectedRow = 0;
                clearTablePrint(x + 4);
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
            index = searchNhanVien(dsnv, currentMANV);
            if (index != -1)
            {
                fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                x = 5, y = 2;
                drawTableUpdateNhanVien(x, y);
                setColorByRequest(BLACK, WHITE);
                gotoxy(x + 88, y + 4);
                cout << dsnv.nodes[index]->MANV;
                gotoxy(x + 88, y + 6);
                cout << dsnv.nodes[index]->HO;
                gotoxy(x + 88, y + 8);
                cout << dsnv.nodes[index]->TEN;
                gotoxy(x + 88, y + 10);
                cout << dsnv.nodes[index]->PHAI;
                x = 1, y = 1;
                while (true)
                {
                    char key = getch();
                    switch (key)
                    {
                    case F10:
                        x = 5, y = 2;
                        fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                        x = 1, y = 1;
                        lapHoaDon(dsnv, root, index, new_hd, x, y, isESC, isSaved);
                        ShowCur(false);
                        isSaved = true;
                        return;
                    case ESC:
                        ShowCur(false);
                        fillAreaColor(x + 76, y, 41, 17, LIGHTGRAY);
                        isSaved = false;
                        return;
                    }
                }
            }
            else
            {
                isSaved = false;
                errorMessage = "Khong tim thay ma nhan vien";
                drawTableErrors(errorMessage, true);
                Sleep(1500);
                drawTableErrors("", true);
                currentMANV = "";
                displayField(x + 87, y + 4, currentMANV, true, 10);
                continue;
            }
            break;
        case TAB:
            currentPage = pageSearchByTab(x + 4, currentPage, totalPages, errorMessage);
            break;
        case ESC:
            fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
            return;
        }
    }
}

void searchNVFromAddHoaDon(dsNhanVien &dsnv, treeVatTu &root, ptr_DSHD &new_hd, int x, int y, int currentPage, bool &isSaved)
{
    nhanVien *result;
    x = 5, y = 2;
    drawTableSearchTenNhanVien(x, y);
    drawTablePrintNhanVien(x, y, 15, 23);
    bool isESC = false;
    timKiemTenNhanVien(dsnv, x, y, result, isESC);
    x = 1, y = 1;
    ShowCur(false);
    if (isESC)
    {
        clearTablePrint(x);
        fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
        return;
    }
    else
    {
        string currentMANV = result->MANV;
        int index = searchNhanVien(dsnv, currentMANV);
        drawTableErrors("Lay ma nhan vien thanh cong", true);
        Sleep(1500);
        drawTableErrors("", true);
        fillAreaColor(x + 69, y, 46, 16, LIGHTGRAY);
        drawTableUpdateHoaDon(x, y);
        setColorByRequest(LIGHTGRAY, BLACK);
        string errorMessage;
        lapHoaDon(dsnv, root, index, new_hd, x, y, isESC, isSaved);
        // if (isESC)
        // {
        //     drawTableErrors("Dang thoat chuong trinh...", true);
        //     Sleep(1500);
        //     drawTableErrors("", true);
        //     fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
        //     return;
        // }
        // if (isSaved)
        // {
        //     drawTableErrors("Sua nhan vien thanh cong", true);
        //     Sleep(1500);
        //     drawTableErrors("", true);
        //     fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
        //     clearTablePrint(x);
        //     return;
        // }
    }
}
void nhapMaVTFromAddCTHD(treeVatTu &root, string &currentMAVT, int &currentPage, int x, int y)
{
    int n = countNodes(root);
    treeVatTu *arr = new treeVatTu[n];
    int index = 0;
    storeInorder(root, arr, &index);
    quickSortVatTu(arr, 0, n - 1);
    string errorMessage;
    bool moveNext = false;
    bool isActive = true;
    x += 7;
    drawTableInputVatTu(x, y);
    displayField(x + 87, y + 4, currentMAVT, isActive, 10);
    while (true)
    {
        string result = inputString(x + 87, y + 4, currentMAVT, 10, "Ma vat tu", moveNext, false);
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
            if (found == nullptr)
            {
               errorMessage = "Ma vat tu khong ton tai";
                drawTableErrors(errorMessage, false);
                Sleep(1500);
                drawTableErrors("", false);
            }
            // else
            // {
            //
            //     currentMAVT = "";
            //     displayField(x + 87, y + 4, currentMAVT, isActive, 10);
            //     continue;
            // }
            return;
        }
        else
        {
            currentMAVT = result;
            displayField(x + 87, y + 4, currentMAVT, isActive, 10);
        }
    }
}

void chonMaVTFromAddCTHD(treeVatTu &root, string &currentMAVT, int &currentPage, int x, int y)
{
    int n = countNodes(root);
    treeVatTu *arr = new treeVatTu[n];
    int index = 0;
    storeInorder(root, arr, &index);
    quickSortVatTu(arr, 0, n - 1);
    string errorMessage;
    int totalPages = ceil((float)n / ROWS);
    currentPage = 1;
    int selectedRow = 0;
    char key;
    int currentChoice = -1;
    bool isESC, isSaved = false;
    x = 5, y = 2;
    fillAreaColor(x - 4, y - 2, 80, 25, LIGHTGRAY);
    drawTableUpdateVatTu(x, y);
    drawTablePrintVatTu(x, y, 15, 23);
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
            currentMAVT = arr[currentChoice]->data_vt.MAVT;
            return;
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
void searchVTFromAddCTHD(treeVatTu &root, int x, int y, int currentPage, string &currentMAVT)
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
    timKiemTenVatTu(root, x, y, result, isESC);
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
    }
}
void handleNavigationAddChiTietHoaDon(dsNhanVien &dsnv, treeVatTu &root, ptr_DSHD &new_hd, string currentMANV, int x, int y)
{
    int n = dsnv.countNV;
    int totalPages = ceil((float)n / HDROWS);
    int currentPage = 1;
    int selectedRow = 0;
    string errorMessage;
    // treeVatTu result;
    string currentMAVT;
    bool isEmpty;
    y += 1;
    fillAreaColor(x, y + 25, 102, 2, LIGHTGRAY);
    int space = 8;
    setColorByRequest(LIGHTGRAY, BROWN);
    drawHCN(x, y + 25, 8, 2);
    setColorByRequest(LIGHTGRAY, DARKGRAY);
    drawHCN(x + 8 + space, y + 25, 15, 2);
    drawHCN(x + 23 + 2 * space, y + 25, 28, 2);
    drawHCN(x + 51 + 3 * space, y + 25, 15, 2);
    setColorByRequest(BROWN, BLACK);
    gotoxy(x + 1, y + 26);
    cout << "NHAP CT";
    setColorByRequest(LIGHTGRAY, BLACK);
    gotoxy(x + 8 + space + 1, y + 26);
    cout << "F3: Nhap ma VT";
    gotoxy(x + 23 + 2 * space + 1, y + 26);
    cout << "F4: Chon ma VT tu danh sach";
    gotoxy(x + 51 + 3 * space + 1, y + 26);
    cout << "F5: Tim ten VT";
    y -= 1;
    bool isESC, isSaved = false;
    int index;
    if (new_hd == nullptr)
    {
        return;
    }
    while (true)
    {
        char key = getch();
        switch (key)
        {
        case F3:
            drawTableUpdateChiTietHoaDon(x, y);
            nhapChiTietHoaDon(dsnv, root, new_hd, "", x, y, isESC, isSaved);
            y += 1;
            fillAreaColor(x, y + 25, 102, 2, LIGHTGRAY);
            y -= 1;
            drawKeysGuideChiTietHoaDon(x, y);
            ShowCur(false);
            if (isESC)
            {
                ShowCur(false);
                fillAreaColor(x + 76, y, 41, 17, LIGHTGRAY);
                return;
            }
            if (isSaved)
            {
                n = dsnv.countNV;
                totalPages = ceil((float)n / HDROWS);
                if (currentPage > totalPages)
                {
                    currentPage = totalPages;
                }
                if (selectedRow >= min(HDROWS, n - (currentPage - 1) * HDROWS))
                {
                    selectedRow = min(HDROWS, n - (currentPage - 1) * HDROWS) - 1;
                }
                errorMessage = "Them chi tiet hoa don thanh cong";
                drawTableErrors(errorMessage, false);
                Sleep(1500);
                drawTableErrors("", false);
                fillAreaColor(x + 76, y, 41, 17, LIGHTGRAY);
                clearTablePrintChiTietHoaDon(x);
                return;
            }
            break;
        case F4:
            chonMaVTFromAddCTHD(root, currentMAVT, currentPage, x, y);
            fillAreaColor(x, y, 115, 25, LIGHTGRAY);
            drawTablePrintChiTietHoaDon(x, y, 15, 23);
            index = searchNhanVien(dsnv, currentMANV);
            setColorByRequest(LIGHTGRAY, BLACK);
            gotoxy(x + 24, y + 3);
            cout << dsnv.nodes[index]->MANV;
            gotoxy(x + 24, y + 5);
            cout << dsnv.nodes[index]->HO << " " << dsnv.nodes[index]->TEN;
            setColorByRequest(LIGHTGRAY, BLACK);
            gotoxy(x + 15, y + 1);
            cout << new_hd->data_hd.SoHD;
            gotoxy(x + 42, y + 1);
            cout << (new_hd->data_hd.loai == "N" ? "Nhap" : "Xuat");
            gotoxy(x + 9, y + 7);
            cout << new_hd->data_hd.day;
            gotoxy(x + 24, y + 7);
            cout << new_hd->data_hd.month;
            gotoxy(x + 36, y + 7);
            cout << new_hd->data_hd.year;
            drawTableUpdateChiTietHoaDon(x, y);
            setColorByRequest(LIGHTGRAY, BLACK);
            inChiTietHoaDon(dsnv, root, new_hd, currentPage, -1, totalPages, x, y, errorMessage, isEmpty);
            nhapChiTietHoaDon(dsnv, root, new_hd, currentMAVT, x, y, isESC, isSaved);
            y += 1;
            fillAreaColor(x, y + 25, 102, 2, LIGHTGRAY);
            y -= 1;
            drawKeysGuideChiTietHoaDon(x, y);
            ShowCur(false);
            if (isESC)
            {
                ShowCur(false);
                fillAreaColor(x + 76, y, 41, 17, LIGHTGRAY);
                return;
            }
            if (isSaved)
            {
                n = dsnv.countNV;
                totalPages = ceil((float)n / HDROWS);
                if (currentPage > totalPages)
                {
                    currentPage = totalPages;
                }
                if (selectedRow >= min(HDROWS, n - (currentPage - 1) * HDROWS))
                {
                    selectedRow = min(HDROWS, n - (currentPage - 1) * HDROWS) - 1;
                }
                errorMessage = "Them chi tiet hoa don thanh cong";
                drawTableErrors(errorMessage, false);
                Sleep(1500);
                drawTableErrors("", false);
                fillAreaColor(x + 76, y, 41, 17, LIGHTGRAY);
                clearTablePrintChiTietHoaDon(x);
                return;
            }
            break;
        case F5:
            fillAreaColor(0, 0, 119, 26, LIGHTGRAY);
            x = 5, y = 2;
            drawTableSearchTenVatTu(x, y);
            searchVTFromAddCTHD(root, x, y, currentPage, currentMAVT);
            ShowCur(false);
            if (isESC)
            {
                clearTablePrint(x);
                fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                return;
            }
            else
            {
                x = 1, y = 1;
                fillAreaColor(x, y, 115, 25, LIGHTGRAY);
                drawTablePrintChiTietHoaDon(x, y, 15, 23);
                index = searchNhanVien(dsnv, currentMANV);
                setColorByRequest(LIGHTGRAY, BLACK);
                gotoxy(x + 24, y + 3);
                cout << dsnv.nodes[index]->MANV;
                gotoxy(x + 24, y + 5);
                cout << dsnv.nodes[index]->HO << " " << dsnv.nodes[index]->TEN;
                setColorByRequest(LIGHTGRAY, BLACK);
                gotoxy(x + 15, y + 1);
                cout << new_hd->data_hd.SoHD;
                gotoxy(x + 42, y + 1);
                cout << (new_hd->data_hd.loai == "N" ? "Nhap" : "Xuat");
                gotoxy(x + 9, y + 7);
                cout << new_hd->data_hd.day;
                gotoxy(x + 24, y + 7);
                cout << new_hd->data_hd.month;
                gotoxy(x + 36, y + 7);
                cout << new_hd->data_hd.year;
                drawTableUpdateChiTietHoaDon(x, y);
                setColorByRequest(LIGHTGRAY, BLACK);
                inChiTietHoaDon(dsnv, root, new_hd, currentPage, -1, totalPages, x, y, errorMessage, isEmpty);
                nhapChiTietHoaDon(dsnv, root, new_hd, currentMAVT, x, y, isESC, isSaved);
                y += 1;
                fillAreaColor(x, y + 25, 102, 2, LIGHTGRAY);
                y -= 1;
                drawKeysGuideChiTietHoaDon(x, y);
                ShowCur(false);
                if (isESC)
                {
                    ShowCur(false);
                    fillAreaColor(x + 76, y, 41, 17, LIGHTGRAY);
                    return;
                }
                if (isSaved)
                {
                    n = dsnv.countNV;
                    totalPages = ceil((float)n / HDROWS);
                    if (currentPage > totalPages)
                    {
                        currentPage = totalPages;
                    }
                    if (selectedRow >= min(HDROWS, n - (currentPage - 1) * HDROWS))
                    {
                        selectedRow = min(HDROWS, n - (currentPage - 1) * HDROWS) - 1;
                    }
                    errorMessage = "Them chi tiet hoa don thanh cong";
                    drawTableErrors(errorMessage, false);
                    Sleep(1500);
                    drawTableErrors("", false);
                    fillAreaColor(x + 76, y, 41, 17, LIGHTGRAY);
                    return;
                }
            }
            break;
        }
    }
}

void handleNavigationAddHoaDon(dsNhanVien &dsnv, treeVatTu &root, ptr_DSHD &new_hd, string &currentMANV, int x, int y, bool &isSuccess)
{
    string errorMessage;
    int n = dsnv.countNV;
    int totalPages = ceil((float)n / ROWS);
    int currentPage = 1;
    int selectedRow = 0;
    char key;
    int currentChoice = -1;
    nhanVien *nv;
    x = 5, y = 2;
    fillAreaColor(x - 4, y + 25, 105, 2, LIGHTGRAY);
    int space = 8;
    setColorByRequest(LIGHTGRAY, BROWN);
    drawHCN(x, y + 25, 7, 2);
    setColorByRequest(LIGHTGRAY, DARKGRAY);
    drawHCN(x + 8 + space, y + 25, 15, 2);
    drawHCN(x + 23 + 2 * space, y + 25, 28, 2);
    drawHCN(x + 51 + 3 * space, y + 25, 15, 2);
    setColorByRequest(BROWN, BLACK);
    gotoxy(x + 1, y + 26);
    cout << "LAP HD";
    setColorByRequest(LIGHTGRAY, BLACK);
    gotoxy(x + 8 + space + 1, y + 26);
    cout << "F3: Nhap ma NV";
    gotoxy(x + 23 + 2 * space + 1, y + 26);
    cout << "F4: Chon ma NV tu danh sach";
    gotoxy(x + 51 + 3 * space + 1, y + 26);
    cout << "F5: Tim ten NV";
    x = 1, y = 1;
    drawTablePrintNhanVien(x + 4, y + 1, 15, 23);
    clearTablePrint(x + 4);
    while (true)
    {
        setColorByRequest(LIGHTGRAY, BLACK);
        inDanhSachNhanVien(dsnv, currentPage, -1, x + 4);
        key = getch();
        switch (key)
        {
        case F3:
            nhapMaNVFromAddHoaDon(dsnv, root, new_hd, currentMANV, x, y, isSuccess);
            return;
        case F4:
            chonMaNVFromAddHoaDon(dsnv, root, new_hd, currentMANV, x, y, isSuccess);
            return;
        case F5:
            searchNVFromAddHoaDon(dsnv, root, new_hd, x, y, currentPage, isSuccess);
            return;
        case LEFT:
            if (currentPage > 1)
            {
                currentPage--;
                selectedRow = 0;
                clearTablePrint(x + 4);
            }
            break;

        case RIGHT:
            if (currentPage < totalPages)
            {
                currentPage++;
                selectedRow = 0;
                clearTablePrint(x + 4);
            }
            break;

        case TAB:
            currentPage = pageSearchByTab(x + 4, currentPage, totalPages, errorMessage);
            break;
        case ESC:
            fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
            return;
        }
    }
}

void handleNavigationUpdateChiTietHoaDon(dsNhanVien &dsnv, treeVatTu &root, ptr_DSHD &new_hd, int x, int y)
{
    int n = 0;
    ptr_DSCTHD temp_cthd = new_hd->data_hd.firstCTHD;
    while (temp_cthd != nullptr)
    {
        n++;
        temp_cthd = temp_cthd->next;
    }
    string errorMessage;
    string currentMAVT;
    int totalPages;
    int currentPage = 1;
    int selectedRow = 0;
    char key;
    int currentChoice = -1;
    nhanVien *nv;
    drawTableUpdateChiTietHoaDon(x, y);
    while (true)
    {
        bool isESC = false, isSaved = false, isEmpty = false;
        inChiTietHoaDon(dsnv, root, new_hd, currentPage, selectedRow, totalPages, x, y, errorMessage, isEmpty);
        if (isEmpty)
        {
            drawTableErrors("Khong co chi tiet hoa don de sua", false);
            Sleep(1500);
            drawTableErrors("", false);
            fillAreaColor(x + 76, y, 41, 17, LIGHTGRAY);
            return;
        }
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
                int itemsOnPage = min(HDROWS, n - (currentPage - 1) * HDROWS);
                selectedRow = itemsOnPage - 1;
            }
            break;
        case DOWN:
        {
            int itemsOnPage = min(HDROWS, n - (currentPage - 1) * HDROWS);
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
        {
            currentChoice = (currentPage - 1) * HDROWS + selectedRow;
            setColorByRequest(BLACK, WHITE);
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
            nodeChiTietHoaDon *arrCTHD = new nodeChiTietHoaDon[n];
            ptr_DSCTHD current_cthd = new_hd->data_hd.firstCTHD;
            for (int i = 0; i < n && current_cthd != nullptr; i++)
            {
                arrCTHD[i].MAVT = current_cthd->data_cthd.MAVT;
                current_cthd = current_cthd->next;
            }
            setColorByRequest(BLACK, WHITE);
            currentMAVT = arrCTHD[currentChoice].MAVT;
            suaChiTietHoaDon(dsnv, root, nv, new_hd, currentMAVT, x, y, isESC, isSaved);
            ShowCur(false);
            if (isESC)
            {
                fillAreaColor(x + 76, y, 41, 17, LIGHTGRAY);
                return;
            }
            if (isSaved)
            {
                n = dsnv.countNV;
                totalPages = ceil((float)n / HDROWS);
                if (currentPage > totalPages)
                {
                    currentPage = totalPages;
                }
                if (selectedRow >= min(HDROWS, n - (currentPage - 1) * HDROWS))
                {
                    selectedRow = min(HDROWS, n - (currentPage - 1) * HDROWS) - 1;
                }
                drawTableErrors("Sua chi tiet hoa don thanh cong", false);
                Sleep(1500);
                drawTableErrors("", false);
                fillAreaColor(x + 76, y, 41, 17, LIGHTGRAY);
                clearTablePrintChiTietHoaDon(x);
                return;
            }
            break;
        }
        case ESC:
            fillAreaColor(x + 76, y, 41, 17, LIGHTGRAY);
            return;
        }
    }
}

void handleNavigationDeleteChiTietHoaDon(dsNhanVien &dsnv, treeVatTu &root, ptr_DSHD &new_hd, int x, int y)
{
    int n = 0;
    ptr_DSCTHD temp_cthd = new_hd->data_hd.firstCTHD;
    while (temp_cthd != nullptr)
    {
        n++;
        temp_cthd = temp_cthd->next;
    }
    string errorMessage;
    string currentMAVT;
    int totalPages;
    int currentPage = 1;
    int selectedRow = 0;
    char key;
    int currentChoice = -1;
    nhanVien *nv;
    drawTableUpdateChiTietHoaDon(x, y);
    while (true)
    {
        bool isESC = false, isSaved = false, isEmpty = false;
        inChiTietHoaDon(dsnv, root, new_hd, currentPage, selectedRow, totalPages, x, y, errorMessage, isEmpty);
        if (isEmpty)
        {
            drawTableErrors("Khong co chi tiet hoa don de xoa", false);
            Sleep(1500);
            drawTableErrors("", false);
            fillAreaColor(x + 76, y, 41, 17, LIGHTGRAY);
            return;
        }
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
                int itemsOnPage = min(HDROWS, n - (currentPage - 1) * HDROWS);
                selectedRow = itemsOnPage - 1;
            }
            break;
        case DOWN:
        {
            int itemsOnPage = min(HDROWS, n - (currentPage - 1) * HDROWS);
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
        {
            currentChoice = (currentPage - 1) * HDROWS + selectedRow;
            setColorByRequest(BLACK, WHITE);
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
            nodeChiTietHoaDon *arrCTHD = new nodeChiTietHoaDon[n];
            ptr_DSCTHD current_cthd = new_hd->data_hd.firstCTHD;
            for (int i = 0; i < n && current_cthd != nullptr; i++)
            {
                arrCTHD[i].MAVT = current_cthd->data_cthd.MAVT;
                current_cthd = current_cthd->next;
            }
            setColorByRequest(BLACK, WHITE);
            currentMAVT = arrCTHD[currentChoice].MAVT;
            xoaChiTietHoaDon(dsnv, root, nv, new_hd, currentMAVT, x, y, isESC, isSaved);
            ShowCur(false);
            if (isESC)
            {
                fillAreaColor(x + 76, y, 41, 17, LIGHTGRAY);
                return;
            }
            if (isSaved)
            {
                n = dsnv.countNV;
                totalPages = ceil((float)n / HDROWS);
                if (currentPage > totalPages)
                {
                    currentPage = totalPages;
                }
                if (selectedRow >= min(HDROWS, n - (currentPage - 1) * HDROWS))
                {
                    selectedRow = min(HDROWS, n - (currentPage - 1) * HDROWS) - 1;
                }
                drawTableErrors("Sua chi tiet hoa don thanh cong", false);
                Sleep(1500);
                drawTableErrors("", false);
                fillAreaColor(x + 76, y, 41, 17, LIGHTGRAY);
                clearTablePrintChiTietHoaDon(x);
                return;
            }
            break;
        }
        case ESC:
            fillAreaColor(x + 76, y, 41, 17, LIGHTGRAY);
            return;
        }
    }
}

void handleNavigationListChiTietHoaDon(dsNhanVien dsnv, treeVatTu root, int x, int y)
{
    string errorMessage;
    int totalPages = 1;
    int currentPage = 1;
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
            inHoaDon(dsnv, root, currentPage, -1, totalPages, x, y, errorMessage, isESC, isSaved, isInputting);
            if (isESC)
            {
                fillAreaColor(x + 76, y, 41, 17, LIGHTGRAY);
                return;
            }
            if (isSaved)
            {
                fillAreaColor(x + 76, y, 41, 17, LIGHTGRAY);
                errorMessage = "Xem chi tiet hoa don thanh cong";
                drawTableErrors(errorMessage, false);
                Sleep(1500);
                drawTableErrors("", false);
                fillAreaColor(x + 76, y, 41, 17, LIGHTGRAY);
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
                inHoaDon(dsnv, root, currentPage, -1, totalPages, x, y, errorMessage, isESC, isSaved, isInputting);
            }
            break;

        case RIGHT:
            if (currentPage < totalPages)
            {
                currentPage++;
                clearTablePrintChiTietHoaDon(x);
                isInputting = false;
                inHoaDon(dsnv, root, currentPage, -1, totalPages, x, y, errorMessage, isESC, isSaved, isInputting);
            }
            break;

        case TAB:
            pageSearchByTab(x, currentPage, totalPages, errorMessage);
            break;
        case ESC:
            fillAreaColor(x + 76, y, 41, 17, LIGHTGRAY);
            return;
        }
    }
}

void menuChiTietHoaDon(dsNhanVien &dsnv, treeVatTu &root, int x, int y)
{
    int n = dsnv.countNV;
    int totalPages = ceil((float)n / ROWS);
    int currentPage = 1;
    string errorMessage;
    char key;
    string currentMANV;
    ptr_DSHD new_hd = nullptr;
    nhanVien *nv = nullptr;
    treeVatTu result = nullptr;
    int selectedRow = 0;
    bool isSuccess = false, isEmpty = false, isESC = false, isSaved = false;
    drawKeysGuideChiTietHoaDon(x, y);
    handleNavigationAddHoaDon(dsnv, root, new_hd, currentMANV, x, y, isSuccess);
    x = 5, y = 2;
    fillAreaColor(x - 4, y + 25, 105, 2, LIGHTGRAY);
    x = 1, y = 1;
    drawKeysGuideChiTietHoaDon(x, y);
    int index;
    if (isSuccess && new_hd != nullptr)
    {
        while (true)
        {
            setColorByRequest(LIGHTGRAY, BLACK);
            inChiTietHoaDon(dsnv, root, new_hd, currentPage, -1, totalPages, x, y, errorMessage, isEmpty);
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
            case F3:
                handleNavigationAddChiTietHoaDon(dsnv, root, new_hd, currentMANV, x, y);
                break;
            case F4:
                handleNavigationUpdateChiTietHoaDon(dsnv, root, new_hd, x, y);
                break;
            case DEL:
                handleNavigationDeleteChiTietHoaDon(dsnv, root, new_hd, x, y);
                break;
            case F5:
                fillAreaColor(0, 0, 119, 26, LIGHTGRAY);
                x = 5, y = 2;
                drawTableSearchTenVatTu(x, y);
                drawTablePrintVatTu(x, y, 15, 23);
                timKiemTenVatTu(root, x, y, result, isESC);
                ShowCur(false);
                if (isESC)
                {
                    clearTablePrint(x);
                    fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                    return;
                }
                else
                {
                    string currentMAVT = result->data_vt.MAVT;
                    drawTableErrors("Lay ma vat tu thanh cong", true);
                    Sleep(1500);
                    drawTableErrors("", true);
                    clearTablePrint(x);
                    fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                    drawTableUpdateVatTu(x, y);
                    setColorByRequest(LIGHTGRAY, BLACK);
                    inDanhSachVatTu(root, currentPage, -1, x);
                    fillAreaColor(0, 0, 119, 26, LIGHTGRAY);
                    x = 1, y = 1;
                    drawTablePrintChiTietHoaDon(x, y, 15, 23);
                    index = searchNhanVien(dsnv, currentMANV);
                    setColorByRequest(LIGHTGRAY, BLACK);
                    gotoxy(x + 24, y + 3);
                    cout << dsnv.nodes[index]->MANV;
                    gotoxy(x + 24, y + 5);
                    cout << dsnv.nodes[index]->HO << " " << dsnv.nodes[index]->TEN;
                    setColorByRequest(LIGHTGRAY, BLACK);
                    gotoxy(x + 15, y + 1);
                    cout << new_hd->data_hd.SoHD;
                    gotoxy(x + 42, y + 1);
                    cout << (new_hd->data_hd.loai == "N" ? "Nhap" : "Xuat");
                    gotoxy(x + 9, y + 7);
                    cout << new_hd->data_hd.day;
                    gotoxy(x + 24, y + 7);
                    cout << new_hd->data_hd.month;
                    gotoxy(x + 36, y + 7);
                    cout << new_hd->data_hd.year;
                    drawTableUpdateChiTietHoaDon(x, y);
                    nhapChiTietHoaDon(dsnv, root, new_hd, currentMAVT, x, y, isESC, isSaved);
                    ShowCur(false);
                    if (isESC)
                    {
                        ShowCur(false);
                        fillAreaColor(x + 76, y, 41, 17, LIGHTGRAY);
                    }
                    if (isSaved)
                    {
                        n = dsnv.countNV;
                        totalPages = ceil((float)n / HDROWS);
                        if (currentPage > totalPages)
                        {
                            currentPage = totalPages;
                        }
                        if (selectedRow >= min(HDROWS, n - (currentPage - 1) * HDROWS))
                        {
                            selectedRow = min(HDROWS, n - (currentPage - 1) * HDROWS) - 1;
                        }
                        errorMessage = "Them chi tiet hoa don thanh cong";
                        drawTableErrors(errorMessage, false);
                        Sleep(1500);
                        drawTableErrors("", false);
                        fillAreaColor(x + 76, y, 41, 17, LIGHTGRAY);
                        clearTablePrintChiTietHoaDon(x);
                    }
                }
                break;
            case F10:
                if (new_hd->data_hd.firstCTHD != nullptr)
                {
                    ptr_DSHD found_hd = nullptr;
                    // Nếu hóa đơn đã tồn tại thì cập nhật
                    found_hd = searchHoaDon(dsnv, new_hd->data_hd.SoHD, found_hd);
                    if (found_hd == nullptr)
                    {
                        // Thêm hóa đơn mới vào nhân viên hiện tại
                        for (int i = 0; i < dsnv.countNV; i++)
                        {
                            if (dsnv.nodes[i]->MANV == currentMANV)
                            {
                                ptr_DSHD temp = dsnv.nodes[i]->firstDSHD;

                                if (temp == nullptr)
                                {
                                    dsnv.nodes[i]->firstDSHD = new_hd;
                                }
                                else
                                {
                                    while (temp->next != nullptr)
                                    {
                                        temp = temp->next;
                                    }
                                    temp->next = new_hd;
                                }
                                new_hd->next = nullptr;
                                break;
                            }
                        }
                    }
                    else
                    {
                        // Nếu hóa đơn đã tồn tại thì cập nhật chi tiết
                        found_hd->data_hd = new_hd->data_hd;
                    }
                    writeFile_dsNhanVien(dsnv);
                    drawTableErrors("Luu va ghi hoa don thanh cong", false);
                    Sleep(1500);
                    drawTableErrors("", false);
                    fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                    return;
                }
                else
                {
                    drawTableErrors("Hoa don rong", false);
                    Sleep(1500);
                    drawTableErrors("", false);
                }
                break;
            case ESC:
                fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                return;
            }
        }
    }
    else
        cout << "do not succeed";
}