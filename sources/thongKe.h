#pragma once
#include "nhanVien.h"
float tinhToanChiPhiCuaHoaDon(ptr_DSCTHD ct)
{
    float price = 0;
    while (ct != nullptr)
    {
        price += ct->data_cthd.soLuong * ct->data_cthd.donGia * (1 - ct->data_cthd.VAT / 100);
        ct = ct->next;
    }
    return price;
}

void tinhToanDoanhThu(ptr_DSCTHD ct, doanhThuVatTu doanhThu[], int &countVatTu, string loai, int maxVatTu)
{
    while (ct != nullptr && countVatTu < maxVatTu)
    {
        bool found = false;
        for (int j = 0; j < countVatTu; ++j)
        {
            if (doanhThu[j].MAVT == ct->data_cthd.MAVT)
            {
                if (loai == "X")
                {
                    doanhThu[j].doanhThu += ct->data_cthd.soLuong * (float)ct->data_cthd.donGia / 1000 * (1 + (float)ct->data_cthd.VAT / 100);
                    doanhThu[j].soluong += ct->data_cthd.soLuong;
                }
                found = true;
                break;
            }
        }
        if (!found && loai == "X" && countVatTu < maxVatTu)
        {
            doanhThu[countVatTu].MAVT = ct->data_cthd.MAVT;
            doanhThu[countVatTu].doanhThu = ct->data_cthd.soLuong * (float)ct->data_cthd.donGia / 1000 * (1 + (float)ct->data_cthd.VAT / 100);
            doanhThu[countVatTu].soluong = ct->data_cthd.soLuong;
            countVatTu++;
        }
        ct = ct->next;
    }
}

void layDoanhThu(dsNhanVien &dsnv, doanhThuVatTu doanhThu[], int &countVatTu, time_t start, time_t end, int maxVatTu)
{
    for (int i = 0; i < dsnv.countNV; ++i)
    {
        ptr_DSHD p = dsnv.nodes[i]->firstDSHD;
        while (p != nullptr)
        {
            time_t hdTime = to_time_t(p->data_hd.day, p->data_hd.month, p->data_hd.year);
            if (hdTime >= start && hdTime <= end)
            {
                tinhToanDoanhThu(p->data_hd.firstCTHD, doanhThu, countVatTu, p->data_hd.loai, maxVatTu);
            }
            p = p->next;
        }
    }
}

void inTop10DTVT(dsNhanVien &dsnv, treeVatTu root, int x, int y, int day1, int month1, int year1, int day2, int month2, int year2)
{
    int maxVatTu = countNodes(root);
    doanhThuVatTu *doanhThu = new doanhThuVatTu[maxVatTu];
    int countVatTu = 0;
    char key;

    time_t start = to_time_t(day1, month1, year1);
    time_t end = to_time_t(day2, month2, year2);
    layDoanhThu(dsnv, doanhThu, countVatTu, start, end, maxVatTu);

    if (countVatTu > 0)
    {
        quickSortDoanhThu(doanhThu, 0, countVatTu - 1);
    }
    setColorByRequest(LIGHTGRAY, RED);
    gotoxy(x + 17, y + 2);
    cout << "Tu ngay ";
    gotoxy(x + 35, y + 2);
    cout << " Den ngay";
    setColorByRequest(LIGHTGRAY, BLACK);
    gotoxy(x + 25, y + 2);
    cout << day1 << "/" << month1 << "/" << year1;
    gotoxy(x + 45, y + 2);
    cout << day2 << "/" << month2 << "/" << year2;
    for (int i = 0; i < 10 && i < countVatTu; i++)
    {
        if (i < 9)
        {
            string str = "0" + to_string(i + 1);
            gotoxy(x + 3, y + 6 + i);
            cout << str;
        }
        else
        {
            gotoxy(x + 3, y + 6 + i);
            cout << 10;
        }
        if (doanhThu[i].doanhThu > 0)
        {
            gotoxy(x + 10, y + 6 + i);
            cout << doanhThu[i].MAVT;
            treeVatTu node = search(root, doanhThu[i].MAVT);
            gotoxy(x + 25, y + 6 + i);
            cout << node->data_vt.TENVT;
            gotoxy(x + 50, y + 6 + i);
            cout << doanhThu[i].soluong;
            gotoxy(x + 61, y + 6 + i);
            cout << node->data_vt.DVT;
            gotoxy(x + 72, y + 6 + i);
            string doanhThuVT = formatMoney(doanhThu[i].doanhThu);
            cout << doanhThuVT;
        }
    }
    while (true)
    {
        key = getch();
        if (key == ESC)
        {
            gotoxy(0, 0);
            cout << "ESC";
        }
    }
    delete[] doanhThu;
}

void clearTablePrintThongKe(int x)
{
    SetBGColor(LIGHTGRAY);
    for (int currentRow = 7; currentRow <= HDROWS + 5; currentRow++)
    {
        for (int i = x + 3; i < x + 25; i++)
        {
            gotoxy(i, currentRow);
            cout << " ";
        }
        for (int i = x + 26; i < x + 40; i++)
        {
            gotoxy(i, currentRow);
            cout << " ";
        }
        for (int i = x + 41; i < x + 53; i++)
        {
            gotoxy(i, currentRow);
            cout << " ";
        }
        for (int i = x + 54; i < x + 84; i++)
        {
            gotoxy(i, currentRow);
            cout << " ";
        }
        for (int i = x + 85; i < x + 107; i++)
        {
            gotoxy(i, currentRow);
            cout << " ";
        }
    }
}

void inThongKeHoaDon(nodeHoaDon *arrHoaDon, string *employeeNames, float *triGiaHoaDon,
                     int totalInvoices, int pageNumber, int &selectedRow, int x, int y, string &errorMessage)
{
    if (totalInvoices == 0)
    {
        errorMessage = "Khong co hoa don";
        drawTableErrors(errorMessage, true);
        return;
    }

    int startIndex = (pageNumber - 1) * (HDROWS - 1);
    int endIndex = min(startIndex + HDROWS - 1, totalInvoices);
    int currentRow = 7;

    // In dữ liệu trang hiện tại
    for (int i = startIndex; i < endIndex; i++)
    {
        gotoxy(x + 3, currentRow);
        if (i - startIndex == selectedRow)
        {
            Highlight(LIGHTBLUE);
            cout << arrHoaDon[i].SoHD;
            setColorByRequest(LIGHTGRAY, BLACK);
        }
        else
        {
            cout << arrHoaDon[i].SoHD;
        }

        gotoxy(x + 28, currentRow);
        cout << arrHoaDon[i].day << "/" << arrHoaDon[i].month << "/" << arrHoaDon[i].year;

        gotoxy(x + 43, currentRow);
        arrHoaDon[i].loai == "X" ? cout << "Xuat" : cout << "Nhap";

        gotoxy(x + 56, currentRow);
        cout << employeeNames[i];

        gotoxy(x + 87, currentRow);
        string str = formatMoney(triGiaHoaDon[i] * 1000);
        cout << str;

        currentRow++;
    }

    // In số trang
    int totalPages = ceil((float)totalInvoices / (HDROWS - 1));
    gotoxy(6, 18);
    cout << "TAB: Di chuyen den trang can tim";
    gotoxy(97, 18);
    cout << "<- Trang " << pageNumber << "/" << totalPages << " ->";
}

void inDoanhThuNam(dsNhanVien danhSach, int x, int y, int year)
{
    gotoxy(x + 30, y + 1);
    cout << year;
    float doanhThuThang[12] = {0};
    for (int i = 0; i < danhSach.countNV; i++)
    {
        ptr_DSHD hoaDon = danhSach.nodes[i]->firstDSHD;
        while (hoaDon != nullptr)
        {
            if (hoaDon->data_hd.year == year)
            {
                // float triGiaHoaDon = 0;
                // triGiaHoaDon = tinhTriGiaHoaDon(hoaDon->data_hd.firstCTHD);
                if (hoaDon->data_hd.loai == "X")
                {
                    doanhThuThang[hoaDon->data_hd.month - 1] += hoaDon->data_hd.firstCTHD->data_cthd.soLuong * (float)hoaDon->data_hd.firstCTHD->data_cthd.donGia / 1000 * (1 + (float)hoaDon->data_hd.firstCTHD->data_cthd.VAT / 100);
                }
            }
            hoaDon = hoaDon->next;
        }
    }
    setColorByRequest(LIGHTGRAY, BLACK);
    for (int i = 0; i < 12; i++)
    {
        if (i < 9)
        {
            string str = "0" + to_string(i + 1);
            gotoxy(x + 4, y + 5 + i);
            cout << str;
        }
        else
        {
            gotoxy(x + 4, y + 5 + i);
            cout << i + 1;
        }
        string doanhThu = formatMoney(doanhThuThang[i] * 1000);
        gotoxy(x + 13, y + 5 + i);
        cout << doanhThu;
    }
}