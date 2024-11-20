#pragma once
#include "../screens/hoaDonScreen.h"
#include "../sources/thongKe.h"
//===============================================================
void HelpTable(int x, int y)
{
    setColorByRequest(LIGHTGRAY, BLACK);
    // Vẽ hình
    drawHCN(x, y, 16, 2);

    // Vẽ layer chữ
    gotoxy(x + 2, y + 1);
    cout << "THOAT: ESCAPE";
}
void drawTableDoanhThuNam(int x, int y)
{
    fillConsoleWithColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
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
    fillConsoleWithColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
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
    gotoxy(x + 25, y + 1);
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
    fillConsoleWithColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
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
// void getCurrentDate(int &day, int &month, int &year)
// {
//     time_t now = time(0);
//     tm *ltm = localtime(&now);
//     day = ltm->tm_mday;
//     month = ltm->tm_mon + 1;
//     year = ltm->tm_year + 1900;
// }

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

void displayTimeFields(int tempDay1, int tempMonth1, int tempYear1,
                       int tempDay2, int tempMonth2, int tempYear2,
                       int x, int y)
{
    setColorByRequest(BLACK, WHITE);
    gotoxy(x + 50, y + 9);
    cout << (tempDay1 < 10 ? "0" : "") << tempDay1;
    gotoxy(x + 62, y + 9);
    cout << (tempMonth1 < 10 ? "0" : "") << tempMonth1;
    gotoxy(x + 71, y + 9);
    cout << tempYear1;

    gotoxy(x + 50, y + 11);
    cout << (tempDay2 < 10 ? "0" : "") << tempDay2;
    gotoxy(x + 62, y + 11);
    cout << (tempMonth2 < 10 ? "0" : "") << tempMonth2;
    gotoxy(x + 71, y + 11);
    cout << tempYear2;
}

string handleFieldInput(int currentField, int &tempDay1, int &tempMonth1, int &tempYear1,
                        int &tempDay2, int &tempMonth2, int &tempYear2,
                        int x, int y, int &currentRow)
{
    displayTimeFields(tempDay1, tempMonth1, tempYear1,
                      tempDay2, tempMonth2, tempYear2, x, y);
    string current;
    int maxLength;
    string fieldName;
    int inputX, inputY;
    int *valuePtr = NULL;
    switch (currentField)
    {
    case 0: // Start day
        current = to_string(tempDay1);
        maxLength = 2;
        fieldName = "Ngay bat dau";
        inputX = x + 50;
        inputY = y + 9;
        valuePtr = &tempDay1;
        break;
    case 1: // Start month
        current = to_string(tempMonth1);
        maxLength = 2;
        fieldName = "Thang bat dau";
        inputX = x + 62;
        inputY = y + 9;
        valuePtr = &tempMonth1;
        break;
    case 2: // Start year
        current = to_string(tempYear1);
        maxLength = 4;
        fieldName = "Nam bat dau";
        inputX = x + 71;
        inputY = y + 9;
        valuePtr = &tempYear1;
        break;
    case 3: // End day
        current = to_string(tempDay2);
        maxLength = 2;
        fieldName = "Ngay ket thuc";
        inputX = x + 50;
        inputY = y + 11;
        valuePtr = &tempDay2;
        break;
    case 4: // End month
        current = to_string(tempMonth2);
        maxLength = 2;
        fieldName = "Thang ket thuc";
        inputX = x + 62;
        inputY = y + 11;
        valuePtr = &tempMonth2;
        break;
    case 5: // End year
        current = to_string(tempYear2);
        maxLength = 4;
        fieldName = "Nam ket thuc";
        inputX = x + 71;
        inputY = y + 11;
        valuePtr = &tempYear2;
        break;
    }

    int cursorPos = current.length();
    bool fieldEditing = true;
    string errorMessage;

    while (fieldEditing)
    {
        displayTimeFields(tempDay1, tempMonth1, tempYear1,
                          tempDay2, tempMonth2, tempYear2, x, y);
        setColorByRequest(BLACK, WHITE);
        gotoxy(inputX, inputY);
        cout << string(maxLength, ' ');
        gotoxy(inputX, inputY);
        cout << current;
        gotoxy(inputX + cursorPos, inputY);

        int key = _getch();
        if (key == 224 || key == 0)
        {
            key = _getch();
            switch (key)
            {
            case UP:
                if (currentField >= 3)
                { // If in bottom row
                    currentRow = currentField - 3;
                    fieldEditing = false;
                }
                break;
            case DOWN:
                if (currentField < 3)
                {
                    currentRow = currentField + 3;
                    fieldEditing = false;
                }
                break;
            case LEFT:
                if (cursorPos > 0)
                {
                    cursorPos--;
                }
                else if (currentField > 0)
                {
                    currentRow = currentField - 1;
                    fieldEditing = false;
                }
                break;
            case RIGHT:
                if (cursorPos < current.length())
                {
                    cursorPos++;
                }
                else if (currentField < 5)
                {
                    currentRow = currentField + 1;
                    fieldEditing = false;
                }
                break;
            case F10:
                return "F10";
            }
            continue;
        }

        switch (key)
        {
        case ESC:
            return "ESC";
        case ENTER:
        {
            if (current.empty())
            {
                errorMessage = fieldName + " khong duoc de trong";
                drawTableErrors(errorMessage, true);
                continue;
            }
            *valuePtr = stoi(current);

            // Validate the date after each input
            bool isValid = true;
            if (tempYear1 < 1900 || tempYear1 > 2100)
            {
                isValid = false;
                errorMessage = "Nam khong hop le. Hop le (1900-2100)";
            }
            else if (tempYear2 < 1900 || tempYear2 > 2100)
            {
                isValid = false;
                errorMessage = "Nam khong hop le. Hop le (1900-2100)";
            }
            if (!isValidTime(tempDay1, tempMonth1, tempYear1) ||
                !isValidTime(tempDay2, tempMonth2, tempYear2))
            {
                isValid = false;
                errorMessage = "Ngay thang nam khong hop le";
            }
            else if (timeConflict(tempDay1, tempMonth1, tempYear1, tempDay2, tempMonth2, tempYear2))
            {
                isValid = false;
                errorMessage = "Time ket thuc phai sau time bat dau";
            }

            if (!isValid)
            {
                drawTableErrors(errorMessage, true);
                continue;
            }

            currentRow = (currentField < 5) ? currentField + 1 : 0;
            fieldEditing = false;
            break;
        }
        case BACKSPACE:
            if (cursorPos > 0)
            {
                current.erase(cursorPos - 1, 1);
                cursorPos--;
            }
            break;
        default:
            if (current.length() < maxLength && isdigit(key))
            {
                if (cursorPos == current.length())
                {
                    current += (char)key;
                }
                else
                {
                    current.insert(cursorPos, 1, (char)key);
                }
                cursorPos++;
            }
        }
        drawTableErrors("", true);
        displayTimeFields(tempDay1, tempMonth1, tempYear1, tempDay2, tempMonth2, tempYear2, x, y);
    }
    return "";
}

void inputTime(int &day1, int &month1, int &year1, int &day2, int &month2, int &year2, int x, int y)
{
    string errorMessage;
    int currentRow = 0;
    bool isEditing = true;
    int tempDay1 = day1, tempMonth1 = month1, tempYear1 = year1;
    int tempDay2 = day2, tempMonth2 = month2, tempYear2 = year2;
    layThoiGianHienTai(tempDay1, tempMonth1, tempYear1);
    layNgayTuongLai(tempDay2, tempMonth2, tempYear2, 1);
    while (isEditing)
    {
        displayTimeFields(tempDay1, tempMonth1, tempYear1, tempDay2, tempMonth2, tempYear2, x, y);
        SetColor(WHITE);
        string result = handleFieldInput(currentRow, tempDay1, tempMonth1, tempYear1, tempDay2, tempMonth2, tempYear2, x, y, currentRow);
        if (result == "ESC")
        {
            ShowCur(false);
            errorMessage = "Dang thoat chuong trinh...";
            drawTableErrors(errorMessage, true);
            Sleep(1500);
            drawTableErrors("", true);
            fillAreaColor(x + 30, y + 3, 50, 13, LIGHTGRAY);
            return;
        }

        if (result == "F10")
        {
            ShowCur(false);
            if (isValidTime(tempDay1, tempMonth1, tempYear1) &&
                isValidTime(tempDay2, tempMonth2, tempYear2) &&
                !timeConflict(tempDay1, tempMonth1, tempYear1, tempDay2, tempMonth2, tempYear2))
            {
                // Save the validated values
                day1 = tempDay1;
                month1 = tempMonth1;
                year1 = tempYear1;
                day2 = tempDay2;
                month2 = tempMonth2;
                year2 = tempYear2;

                errorMessage = "Luu thoi gian thanh cong";
                drawTableErrors(errorMessage, true);
                Sleep(1500);
                drawTableErrors("", true);
                fillAreaColor(x + 30, y + 3, 50, 13, LIGHTGRAY);
                return;
            }
            else
            {
                errorMessage = "Thieu thong tin hoac thong tin khong hop le";
                drawTableErrors(errorMessage, true);
                Sleep(1500);
                drawTableErrors("", true);
            }
        }
    }
}
void inputYear(int &year, int x, int y)
{
    string errorMessage;
    int currentRow = 0;
    bool isEditing = true;
    int tempYear = year;
    layThoiGianHienTai(tempYear, tempYear, tempYear);

    while (isEditing)
    {
        setColorByRequest(BLACK, WHITE);
        gotoxy(x + 44, y + 8);
        cout << tempYear;

        SetColor(WHITE);
        string current = to_string(tempYear);
        int cursorPos = current.length();
        int maxLength = 4;
        string fieldName = "Nam";
        int inputX = x + 44;
        int inputY = y + 8;

        bool fieldEditing = true;
        while (fieldEditing)
        {
            setColorByRequest(BLACK, WHITE);
            gotoxy(inputX, inputY);
            cout << string(maxLength, ' ');
            gotoxy(inputX, inputY);
            cout << current;
            gotoxy(inputX + cursorPos, inputY);

            int key = _getch();
            if (key == 224 || key == 0)
            {
                key = _getch();
                switch (key)
                {
                case F10:

                    tempYear = stoi(current);

                    // Basic year validation (adjust as needed)
                    if (tempYear < 1900 || tempYear > 2100)
                    {
                        errorMessage = "Nam khong hop le (1900-2100)";
                        drawTableErrors(errorMessage, true);
                        continue;
                    }

                    year = tempYear;
                    errorMessage = "Luu nam thanh cong";
                    drawTableErrors(errorMessage, true);
                    Sleep(1500);
                    drawTableErrors("", true);
                    fillAreaColor(x + 30, y + 3, 50, 13, LIGHTGRAY);
                    return;
                case ESC:
                    ShowCur(false);
                    errorMessage = "Dang thoat chuong trinh...";
                    drawTableErrors(errorMessage, true);
                    Sleep(1500);
                    drawTableErrors("", true);
                    fillAreaColor(x + 30, y + 3, 50, 13, LIGHTGRAY);
                    return;
                }
            }

            switch (key)
            {
            case BACKSPACE:
                if (cursorPos > 0)
                {
                    current.erase(cursorPos - 1, 1);
                    cursorPos--;
                }
                break;
            default:
                if (current.length() < maxLength && isdigit(key))
                {
                    if (cursorPos == current.length())
                    {
                        current += (char)key;
                    }
                    else
                    {
                        current.insert(cursorPos, 1, (char)key);
                    }
                    cursorPos++;
                }
            }
            drawTableErrors("", true);
        }
    }
}

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
        case TAB:
            currentPage = pageSearchByTab(x, currentPage, totalPages, errorMessage);
            break;
        case ESC:
            errorMessage = "Dang thoat chuong trinh...";
            drawTableErrors(errorMessage, true);
            Sleep(1500);
            drawTableErrors("", true);

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
    drawTableInputTime(x, y);
    ShowCur(true);
    inputTime(day1, month1, year1, day2, month2, year2, x, y);
    ShowCur(false);
    drawTableTop10DoanhThu(x, y);
    inTop10DTVT(dsnv, root, x, y, day1, month1, year1, day2, month2, year2);
}

void menuThongKeHoaDon(dsNhanVien dsnv, int x, int y)
{
    int day1, month1, year1, day2, month2, year2;
    drawTableInputTime(x, y);
    ShowCur(true);
    inputTime(day1, month1, year1, day2, month2, year2, x, y);
    ShowCur(false);
    y = 1;
    drawTableThongKeHoaDon(x, y);
    handleNavigationThongKeHoaDon(dsnv, x, y, day1, month1, year1, day2, month2, year2);
}

void menuThongKeDoanhThuNam(dsNhanVien dsnv, int x, int y)
{
    int year;
    drawTableInputYear(x, y);
    ShowCur(true);
    inputYear(year, x, y);
    ShowCur(false);
    drawTableDoanhThuNam(x, y);
    inDoanhThuNam(dsnv, x, y, year);
}

// int main()
// {
//     // ShowCur(false);
//     dsNhanVien dsnv;
//     treeVatTu root = nullptr;
//     ptr_DSHD new_hd = new dsHoaDon;
//     new_hd = nullptr;
//     dsHoaDon dshd;
//     nhanVien *nv = nullptr;
//     bool isOpened;
//     bool isSuccess;
//     string errorMessage;
//     int x = 5;
//     int y = 2;
//     fillConsoleWithColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
//     // drawTableInputTime(x, y);
//     int day1 = 1, month1 = 1, year1 = 2024;
//     int day2 = 1, month2 = 1, year2 = 2024;
//     // inputTime(day1, month1, year1, day2, month2, year2, x, y);
//     // gotoxy(0, 0);
//     // SetColor(WHITE);
//     // cout << day1 << "/" << month1 << "/" << year1 << "\n"
//     //      << day2 << "/" << month2 << "/" << year2;
//     // Handle the input
//     readFile_dsNhanVien(dsnv, isOpened);
//     readFile_dsVatTu(root, isOpened);
//     // if (!isOpened)
//     // {
//     //     errorMessage = "Khong the mo file ds_NhanVien.txt";
//     //     drawTableErrors(errorMessage, false);
//     //     return 0;
//     // }
//     // handleNavigationThongKeTop10(dsnv, root, x, y);
//     // handleNavigationThongKeDoanhThuNam(dsnv, x, y);
//     // drawTableThongKeHoaDon(x, y);
//     menuThongKeHoaDon(dsnv, x, y);
//     // drawTableInputYear(x, y);
//     while (1)
//     {
//         getch();
//     }
// }