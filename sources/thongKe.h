#pragma once
#include "nhanVien.h"
#include "hoaDon.h"
#include "vatTu.h"
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
        if (!found && loai == "X" && countVatTu < maxVatTu) // nếu chưa tìm thấy
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
    gotoxy(x + 34, y + 2);
    cout << "Tu ngay ";
    gotoxy(x + 52, y + 2);
    cout << " Den ngay";
    setColorByRequest(LIGHTGRAY, BLACK);
    gotoxy(x + 42, y + 2);
    cout << day1 << "/" << month1 << "/" << year1;
    gotoxy(x + 62, y + 2);
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
            return;
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
    int *indices = new int[totalInvoices];
    for (int i = 0; i < totalInvoices; i++)
    {
        indices[i] = i;
    }

    // Sắp xếp mảng chỉ số theo thời gian tăng dần
    for (int i = 0; i < totalInvoices - 1; i++)
    {
        for (int j = 0; j < totalInvoices - i - 1; j++)
        {
            // So sánh thời gian
            bool shouldSwap = false;
            if (arrHoaDon[indices[j]].year > arrHoaDon[indices[j + 1]].year)
            {
                shouldSwap = true;
            }
            else if (arrHoaDon[indices[j]].year == arrHoaDon[indices[j + 1]].year)
            {
                if (arrHoaDon[indices[j]].month > arrHoaDon[indices[j + 1]].month)
                {
                    shouldSwap = true;
                }
                else if (arrHoaDon[indices[j]].month == arrHoaDon[indices[j + 1]].month)
                {
                    if (arrHoaDon[indices[j]].day > arrHoaDon[indices[j + 1]].day)
                    {
                        shouldSwap = true;
                    }
                }
            }

            if (shouldSwap)
            {
                int temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }
    int startIndex = (pageNumber - 1) * (HDROWS - 1);
    int endIndex = min(startIndex + HDROWS - 1, totalInvoices);
    int currentRow = 7;

    // In dữ liệu trang hiện tại
    for (int i = startIndex; i < endIndex; i++)
    {
        int idx = indices[i];
        gotoxy(x + 3, currentRow);
        if (i - startIndex == selectedRow)
        {
            Highlight(LIGHTBLUE);
            cout << arrHoaDon[idx].SoHD;
            setColorByRequest(LIGHTGRAY, BLACK);
        }
        else
        {
            cout << arrHoaDon[idx].SoHD;
        }

        gotoxy(x + 28, currentRow);
        cout << arrHoaDon[idx].day << "/" << arrHoaDon[idx].month << "/" << arrHoaDon[idx].year;

        gotoxy(x + 43, currentRow);
        arrHoaDon[idx].loai == "X" ? cout << "Xuat" : cout << "Nhap";

        gotoxy(x + 56, currentRow);
        cout << employeeNames[idx];

        gotoxy(x + 87, currentRow);
        string str = formatMoney(triGiaHoaDon[idx] * 1000);
        cout << str;

        currentRow++;
    }
    delete[] indices;
    // In số trang
    int totalPages = ceil((float)totalInvoices / (HDROWS - 1));
    gotoxy(6, 18);
    cout << "TAB: Di chuyen den trang can tim";
    gotoxy(97, 18);
    cout << "<- Trang " << pageNumber << "/" << totalPages << " ->";
}

void inDoanhThuNam(dsNhanVien danhSach, int x, int y, int year)
{
    setColorByRequest(LIGHTGRAY, BLACK);
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
    char key;
    while (true)
    {
        key = getch();
        if (key == ESC)
            return;
    }
}

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

void inputTime(int &day1, int &month1, int &year1, int &day2, int &month2, int &year2, int x, int y, bool &isESC, bool &isSaved)
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
            isESC = true;
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
                isSaved = true;
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
void inputYear(int &year, int x, int y, bool &isESC, bool &isSaved)
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
                case LEFT:
                    if (cursorPos > 0)
                    {
                        cursorPos--;
                    }
                    break;
                case RIGHT:
                    if (cursorPos < current.length())
                    {
                        cursorPos++;
                    }
                    break;
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
                    isSaved = true;
                    return;
                }
                continue;
            }

            switch (key)
            {
            case ESC:
                isESC = true;
                return;
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