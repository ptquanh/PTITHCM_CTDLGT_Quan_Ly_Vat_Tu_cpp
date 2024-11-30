#pragma once
#include "../screens/hoaDonScreen.h"
#include "../sources/thongKe.h"
//===============================================================
void drawKeysGuideThongKe(int x, int y)
{
    setColorByRequest(LIGHTGRAY, DARKGRAY);
    drawHCN(x + 99, y + 25, 11, 2);
    setColorByRequest(LIGHTGRAY, BLACK);
    gotoxy(x + 100, y + 26);
    cout << "ESC: Thoat";
}
void drawTableDoanhThuNam(int x, int y)
{
    setColorByRequest(LIGHTGRAY, DARKGRAY);
    drawHCN(x, y, 35, 17);
    horizontalLine(x, y + 2, 35);
    horizontalLine(x, y + 4, 35);
    verticalLine(x + 10, y + 3, 14);
    gotoxy(x, y + 2);
    cout << tRight;
    gotoxy(x, y + 4);
    cout << tRight;
    gotoxy(x + 35, y + 2);
    cout << tLeft;
    gotoxy(x + 35, y + 4);
    cout << tLeft;
    gotoxy(x + 10, y + 2);
    cout << tDown;
    gotoxy(x + 10, y + 17);
    cout << tUp;
    gotoxy(x + 10, y + 4);
    cout << cross;
    setColorByRequest(LIGHTGRAY, RED);
    gotoxy(x + 2, y + 1);
    cout << "BANG THONG KE DOANH THU NAM ";
    gotoxy(x + 3, y + 3);
    cout << "THANG";
    gotoxy(x + 20, y + 3);
    cout << "DOANH THU";
}
void drawTableTop10DoanhThu(int x, int y)
{
    setColorByRequest(LIGHTGRAY, DARKGRAY);
    drawHCN(x, y, 103, 16);
    horizontalLine(x + 1, y + 3, 102);
    horizontalLine(x + 1, y + 5, 102);
    verticalLine(x + 7, y + 4, 12);
    verticalLine(x + 22, y + 4, 12);
    verticalLine(x + 47, y + 4, 12);
    verticalLine(x + 58, y + 4, 12);
    verticalLine(x + 69, y + 4, 12);
    gotoxy(x, y + 3);
    cout << tRight;
    gotoxy(x, y + 5);
    cout << tRight;
    gotoxy(x + 7, y + 16);
    cout << tUp;
    gotoxy(x + 22, y + 16);
    cout << tUp;
    gotoxy(x + 47, y + 16);
    cout << tUp;
    gotoxy(x + 58, y + 16);
    cout << tUp;
    gotoxy(x + 69, y + 16);
    cout << tUp;
    gotoxy(x + 103, y + 3);
    cout << tLeft;
    gotoxy(x + 103, y + 5);
    cout << tLeft;
    gotoxy(x + 7, y + 3);
    cout << tDown;
    gotoxy(x + 22, y + 3);
    cout << tDown;
    gotoxy(x + 47, y + 3);
    cout << tDown;
    gotoxy(x + 58, y + 3);
    cout << tDown;
    gotoxy(x + 69, y + 3);
    cout << tDown;
    gotoxy(x + 7, y + 5);
    cout << cross;
    gotoxy(x + 22, y + 5);
    cout << cross;
    gotoxy(x + 47, y + 5);
    cout << cross;
    gotoxy(x + 58, y + 5);
    cout << cross;
    gotoxy(x + 69, y + 5);
    cout << cross;
    setColorByRequest(LIGHTGRAY, RED);
    gotoxy(x + 45, y + 1);
    cout << "TOP 10 VAT TU";
    gotoxy(x + 2, y + 4);
    cout << "HANG";
    gotoxy(x + 10, y + 4);
    cout << "MA VAT TU";
    gotoxy(x + 25, y + 4);
    cout << "TEN VAT TU";
    gotoxy(x + 49, y + 4);
    cout << "SO LUONG";
    gotoxy(x + 61, y + 4);
    cout << "DON VI";
    gotoxy(x + 72, y + 4);
    cout << "DOANH THU";
}
void drawTableThongKeHoaDon(int x, int y)
{
    setColorByRequest(LIGHTGRAY, DARKGRAY);
    drawHCN(x, y, 107, 16);
    horizontalLine(x + 1, y + 3, 106);
    horizontalLine(x + 1, y + 5, 106);
    verticalLine(x + 25, y + 4, 12);
    verticalLine(x + 40, y + 4, 12);
    verticalLine(x + 53, y + 4, 12);
    verticalLine(x + 84, y + 4, 12);
    gotoxy(x, y + 3);
    cout << tRight;
    gotoxy(x, y + 5);
    cout << tRight;
    gotoxy(x + 25, y + 16);
    cout << tUp;
    gotoxy(x + 40, y + 16);
    cout << tUp;
    gotoxy(x + 53, y + 16);
    cout << tUp;
    gotoxy(x + 84, y + 16);
    cout << tUp;
    gotoxy(x + 107, y + 3);
    cout << tLeft;
    gotoxy(x + 107, y + 5);
    cout << tLeft;
    gotoxy(x + 25, y + 3);
    cout << tDown;
    gotoxy(x + 40, y + 3);
    cout << tDown;
    gotoxy(x + 53, y + 3);
    cout << tDown;
    gotoxy(x + 84, y + 3);
    cout << tDown;
    gotoxy(x + 25, y + 5);
    cout << cross;
    gotoxy(x + 40, y + 5);
    cout << cross;
    gotoxy(x + 53, y + 5);
    cout << cross;
    gotoxy(x + 84, y + 5);
    cout << cross;
    setColorByRequest(LIGHTGRAY, RED);
    gotoxy(x + 30, y + 1);
    cout << "BANG LIET KE CAC HOA DON TRONG KHOANG THOI GIAN";
    gotoxy(x + 3, y + 4);
    cout << "SO HOA DON";
    gotoxy(x + 28, y + 4);
    cout << "NGAY LAP";
    gotoxy(x + 43, y + 4);
    cout << "LOAI HD";
    gotoxy(x + 56, y + 4);
    cout << "HO TEN NHAN VIEN";
    gotoxy(x + 87, y + 4);
    cout << "TRI GIA HOA DON";
}
void drawTableInputTime(int x, int y)
{
    setColorByRequest(LIGHTGRAY, DARKGRAY);
    drawHCN(x + 30, y + 3, 50, 13);
    drawHCN(x + 57, y + 13, 9, 2);
    drawHCN(x + 69, y + 13, 9, 2);
    SetColor(BLACK);
    gotoxy(x + 58, y + 14);
    cout << "ESC: Huy";
    gotoxy(x + 70, y + 14);
    cout << "F10: Luu";
    SetColor(BLACK);
    gotoxy(x + 45, y + 5);
    cout << "NHAP KHOANG THOI GIAN";
    gotoxy(x + 49, y + 7);
    cout << "Ngay";
    gotoxy(x + 60, y + 7);
    cout << "Thang";
    gotoxy(x + 72, y + 7);
    cout << "Nam";
    gotoxy(x + 32, y + 9);
    cout << "Tu ngay   :";
    gotoxy(x + 32, y + 11);
    cout << "Den ngay  :";
    for (int i = x + 43; i < x + 79; i++)
    {
        SetBGColor(BLACK);
        gotoxy(i, y + 9);
        cout << " ";
        gotoxy(i, y + 11);
        cout << " ";
    }
}

void drawTableInputYear(int x, int y)
{
    setColorByRequest(LIGHTGRAY, DARKGRAY);
    drawHCN(x + 30, y + 4, 50, 9);
    drawHCN(x + 57, y + 10, 9, 2);
    drawHCN(x + 69, y + 10, 9, 2);
    SetColor(BLACK);
    gotoxy(x + 58, y + 11);
    cout << "ESC: Huy";
    gotoxy(x + 70, y + 11);
    cout << "F10: Luu";
    SetColor(BLACK);
    gotoxy(x + 45, y + 6);
    cout << "NHAP NAM CAN XEM DOANH THU";
    gotoxy(x + 32, y + 8);
    cout << "Nhap nam  :";
    for (int i = x + 43; i < x + 79; i++)
    {
        SetBGColor(BLACK);
        gotoxy(i, y + 8);
        cout << " ";
    }
}

// void addDays(int &day, int &month, int &year, int days)
// {
//     time_t now = time(0);
//     tm *ltm = localtime(&now);
//     ltm->tm_mday = day + days;
//     ltm->tm_mon = month - 1;
//     ltm->tm_year = year - 1900;
//     time_t newTime = mktime(ltm);
//     tm *newDate = localtime(&newTime);
//     day = newDate->tm_mday;
//     month = newDate->tm_mon + 1;
//     year = newDate->tm_year + 1900;
// }

// void drawQuickSelectMenu(int x, int y, bool isStartDate)
// {
//     setColorByRequest(LIGHTGRAY, DARKGRAY);
//     drawHCN(x + 85, y + 4, 30, 12);
//     SetColor(BLACK);

//     string title = isStartDate ? "CHON NGAY BAT DAU" : "CHON NGAY KET THUC";
//     gotoxy(x + 90, y + 5);
//     cout << title;

//     gotoxy(x + 87, y + 7);
//     cout << "1. Ngay hien tai";
//     gotoxy(x + 87, y + 8);
//     cout << "2. Ngay truoc (1 ngay)";
//     gotoxy(x + 87, y + 9);
//     cout << "3. Ngay truoc (3 ngay)";
//     gotoxy(x + 87, y + 10);
//     cout << "4. Tuan truoc";
//     gotoxy(x + 87, y + 11);
//     cout << "5. Thang truoc";
//     gotoxy(x + 87, y + 12);
//     cout << "6. Nam truoc";
//     gotoxy(x + 87, y + 13);
//     cout << "ESC: Thoat";
// }

// void quickSelectDate(int &day, int &month, int &year, int x, int y, bool isStartDate)
// {
//     drawQuickSelectMenu(x, y, isStartDate);
//     char key;
//     while (true)
//     {
//         key = _getch();
//         getCurrentDate(day, month, year);

//         switch (key)
//         {
//         case '1': // Current date
//             break;

//         case '2': // Previous day
//             addDays(day, month, year, -1);
//             break;

//         case '3': // 3 days ago
//             addDays(day, month, year, -3);
//             break;

//         case '4': // Previous week
//             addDays(day, month, year, -7);
//             break;

//         case '5': // Previous month
//             if (month == 1)
//             {
//                 month = 12;
//                 year--;
//             }
//             else
//             {
//                 month--;
//             }
//             break;

//         case '6': // Previous year
//             year--;
//             break;

//         case 27: // ESC
//             fillAreaColor(x + 85, y + 4, 30, 12, LIGHTGRAY);
//             return;
//         }

//         if (key >= '1' && key <= '6')
//         {
//             fillAreaColor(x + 85, y + 4, 30, 12, LIGHTGRAY);
//             return;
//         }
//     }
// }

void handleNavigationThongKeHoaDon(dsNhanVien &dsnv, int x, int y, int day1, int month1, int year1, int day2, int month2, int year2)
{
    string errorMessage;
    int totalInvoices = 0;
    time_t start = to_time_t(day1, month1, year1);
    time_t end = to_time_t(day2, month2, year2);
    setColorByRequest(LIGHTGRAY, RED);
    gotoxy(x + 35, y + 2);
    cout << "Tu ngay ";
    gotoxy(x + 53, y + 2);
    cout << " Den ngay";
    setColorByRequest(LIGHTGRAY, BLACK);
    gotoxy(x + 43, y + 2);
    cout << day1 << "/" << month1 << "/" << year1;
    gotoxy(x + 63, y + 2);
    cout << day2 << "/" << month2 << "/" << year2;
    // Đếm số lượng hóa đơn
    for (int i = 0; i < dsnv.countNV; ++i)
    {
        ptr_DSHD p = dsnv.nodes[i]->firstDSHD;
        while (p != nullptr)
        {
            time_t invoiceTime = to_time_t(p->data_hd.day, p->data_hd.month, p->data_hd.year);
            if (invoiceTime >= start && invoiceTime <= end)
            {
                totalInvoices++;
            }
            p = p->next;
        }
    }

    // Nếu không có hóa đơn
    if (totalInvoices == 0)
    {
        drawTableErrors("Khong co HD trong thoi gian nay", true);
        Sleep(1500);
        drawTableErrors("", true);
        return;
    }

    // Tạo mảng động để lưu thông tin hóa đơn
    nodeHoaDon *arrHoaDon = new nodeHoaDon[totalInvoices];
    string *employeeNames = new string[totalInvoices];
    float *triGiaHoaDon = new float[totalInvoices];
    int index = 0;

    // Lưu thông tin các hóa đơn
    for (int i = 0; i < dsnv.countNV; ++i)
    {
        ptr_DSHD p = dsnv.nodes[i]->firstDSHD;
        while (p != nullptr)
        {
            time_t invoiceTime = to_time_t(p->data_hd.day, p->data_hd.month, p->data_hd.year);
            if (invoiceTime >= start && invoiceTime <= end)
            {
                arrHoaDon[index] = p->data_hd;
                employeeNames[index] = dsnv.nodes[i]->HO + " " + dsnv.nodes[i]->TEN;

                // Tính tổng trị giá hóa đơn
                ptr_DSCTHD cthd = p->data_hd.firstCTHD;
                while (cthd != nullptr)
                {
                    triGiaHoaDon[index] = 0;
                    triGiaHoaDon[index] += cthd->data_cthd.soLuong *
                                           (float)cthd->data_cthd.donGia / 1000 *
                                           (1 + (float)cthd->data_cthd.VAT / 100);
                    cthd = cthd->next;
                }

                index++;
            }
            p = p->next;
        }
    }

    int totalPages = ceil((float)totalInvoices / HDROWS);
    int currentPage = 1;
    int selectedRow = -1;
    char key;

    while (true)
    {
        setColorByRequest(LIGHTGRAY, BLACK);
        inThongKeHoaDon(arrHoaDon, employeeNames, triGiaHoaDon, totalInvoices, currentPage, selectedRow, x, y, errorMessage);
        key = getch();
        switch (key)
        {
        case LEFT:
            if (currentPage > 1)
            {
                currentPage--;
                clearTablePrintThongKe(x);
            }
            break;
        case RIGHT:
            if (currentPage < totalPages)
            {
                currentPage++;
                clearTablePrintThongKe(x);
            }
            break;
        case ESC:
            delete[] arrHoaDon;
            delete[] employeeNames;
            delete[] triGiaHoaDon;
            return;
        }
    }
}

void menuThongKeTop10(dsNhanVien dsnv, treeVatTu root, int x, int y)
{
    int day1, month1, year1, day2, month2, year2;
    bool isESC = false, isSaved = false;
    drawTableInputTime(x, y);
    ShowCur(true);
    inputTime(day1, month1, year1, day2, month2, year2, x, y, isESC, isSaved);
    ShowCur(false);
    if (isESC)
    {
        fillAreaColor(x + 30, y + 3, 50, 13, LIGHTGRAY);
        return;
    }

    if (isSaved)
    {
        drawTableErrors("Luu thoi gian thanh cong", true);
        Sleep(1500);
        drawTableErrors("", true);
        fillAreaColor(x + 30, y + 3, 50, 13, LIGHTGRAY);
        fillConsoleWithColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
        drawKeysGuideThongKe(x, y);
        x += 3;
        drawTableTop10DoanhThu(x, y);
        inTop10DTVT(dsnv, root, x, y, day1, month1, year1, day2, month2, year2);
        return;
    }
}
void menuThongKeHoaDon(dsNhanVien dsnv, int x, int y)
{
    bool isESC = false, isSaved = false;
    int day1, month1, year1, day2, month2, year2;
    drawTableInputTime(x, y);
    ShowCur(true);
    inputTime(day1, month1, year1, day2, month2, year2, x, y, isESC, isSaved);
    ShowCur(false);
    if (isESC)
    {
        fillAreaColor(x + 30, y + 3, 50, 13, LIGHTGRAY);
        return;
    }

    if (isSaved)
    {
        drawTableErrors("Luu thoi gian thanh cong", true);
        Sleep(1500);
        drawTableErrors("", true);
        fillAreaColor(x + 30, y + 3, 50, 13, LIGHTGRAY);
        fillConsoleWithColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
        drawKeysGuideThongKe(x, y);
        y = 1;
        drawTableThongKeHoaDon(x, y);
        handleNavigationThongKeHoaDon(dsnv, x, y, day1, month1, year1, day2, month2, year2);
        return;
    }
}

void menuThongKeDoanhThuNam(dsNhanVien dsnv, int x, int y)
{
    int year;
    bool isESC = false, isSaved = false;
    drawTableInputYear(x, y);
    ShowCur(true);
    inputYear(year, x, y, isESC, isSaved);
    ShowCur(false);
    if (isESC)
    {
        fillAreaColor(x + 30, y + 3, 50, 13, LIGHTGRAY);
        return;
    }
    if (isSaved)
    {
        drawTableErrors("Luu nam thanh cong", true);
        Sleep(1500);
        drawTableErrors("", true);
        fillAreaColor(x + 30, y + 3, 50, 13, LIGHTGRAY);
        fillConsoleWithColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
        drawKeysGuideThongKe(x, y);
        x += 35;
        drawTableDoanhThuNam(x, y);
        inDoanhThuNam(dsnv, x, y, year);
        return;
    }
}