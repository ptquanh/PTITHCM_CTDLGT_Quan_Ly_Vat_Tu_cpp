#pragma once
#include "vatTu.h"
#include "nhanVien.h"
#include "../screens/hoaDonScreen.h"
void drawTableUpdateChiTietHoaDon(int x, int y);
void clearTablePrintChiTietHoaDon(int x);
void drawTablePrintChiTietHoaDon(int x, int y, int w, int h);
void drawTableAddVatTuInCTHD(int x, int y);
void drawTablePrintHoaDon(int x, int y, int w, int h);
void drawTableUpdateHoaDon(int x, int y);
void drawTablePrintCTHDInListCTHD(int x, int y, int w, int h);
//======================HOA DON===================================
ptr_DSHD searchHoaDon(dsNhanVien &ds_nv, string soHD, ptr_DSHD found_hd)
{
    for (int i = 0; i < ds_nv.countNV; ++i)
    {
        if (ds_nv.nodes[i] != nullptr)
        {
            ptr_DSHD current_hd = ds_nv.nodes[i]->firstDSHD;
            while (current_hd != nullptr)
            {
                if (current_hd->data_hd.SoHD == soHD)
                {
                    found_hd = current_hd;
                    return found_hd; // Trả về con trỏ đến nhân viên tìm thấy
                }
                current_hd = current_hd->next;
            }
        }
    }
    return nullptr; // Trả về nullptr nếu không tìm thấy hóa đơn
}

void lapHoaDon(dsNhanVien &ds_nv, treeVatTu &root, int index, ptr_DSHD &new_hd, int x, int y, bool &isESC, bool &isSaved)
{
    fillAreaColor(x + 4, y, 62, 25, LIGHTGRAY);
    int w = 15, h = 7;
    drawTablePrintHoaDon(x, y, w, h);
    drawTableUpdateHoaDon(x, y);
    setColorByRequest(LIGHTGRAY, BLACK);
    gotoxy(x + 24, y + 3);
    cout << ds_nv.nodes[index]->MANV;
    gotoxy(x + 24, y + 5);
    cout << ds_nv.nodes[index]->HO << " " << ds_nv.nodes[index]->TEN;
    nodeHoaDon input;
    input.SoHD = "";
    input.loai = "";
    input.day = 0;
    input.month = 0;
    input.year = 0;
    string errorMessage;
    int currentRow = 0;
    bool hasError;
    string result;
    int numResult;
    bool moveNext;
    string tempInput;
    new_hd = new dsHoaDon;
    new_hd->data_hd.firstCTHD = nullptr;
    new_hd->next = nullptr;
    layThoiGianHienTai(input.day, input.month, input.year);
    while (true)
    {
        displayField(x + 94, y + 4, input.SoHD, currentRow == 0, 20);
        displayField(x + 94, y + 6, input.day > 0 ? to_string(input.day) : "", currentRow == 1, 2);
        displayField(x + 94, y + 8, input.month > 0 ? to_string(input.month) : "", currentRow == 2, 2);
        displayField(x + 94, y + 10, input.year > 0 ? to_string(input.year) : "", currentRow == 3, 4);
        displayField(x + 94, y + 12, input.loai, currentRow == 4, 1);
        switch (currentRow)
        {
        case 0:
            result = inputString(x + 94, y + 4, input.SoHD, 20, "So hoa don", moveNext, false);
            if (result == "ESC")
                goto escButton;
            if (result == "F10")
                goto saveButton;
            tempInput = normalizeString(result, hasError);
            if (hasError)
            {
                errorMessage = "So hoa don chua ky tu khong hop le";
                drawTableErrors(errorMessage, false);
                continue;
            }
            for (char &c : tempInput)
            {
                c = std::toupper(c);
            }
            // check ma hd trung
            ptr_DSHD found_hd;
            if (searchHoaDon(ds_nv, tempInput, found_hd) != nullptr)
            {
                errorMessage = "So hoa don da ton tai";
                drawTableErrors(errorMessage, false);
                continue;
            }
            drawTableErrors("", false);
            input.SoHD = tempInput;
            break;
        case 1:
            numResult = inputNumber(x + 94, y + 6, input.day, 2, "Ngay lap", moveNext, false);
            if (numResult == -1)
                goto escButton;
            if (numResult == -10)
                goto saveButton;
            if (numResult == 0)
            {
                errorMessage = "Ngay khong hop le";
                drawTableErrors(errorMessage, false);
                continue;
            }
            if (numResult < 1 || numResult > 31)
            {
                errorMessage = "Ngay khong hop le";
                drawTableErrors(errorMessage, false);
                continue;
            }
            input.day = numResult;
            drawTableErrors("", false);
            break;
        case 2:
            numResult = inputNumber(x + 94, y + 8, input.month, 2, "Thang lap", moveNext, false);
            if (numResult == -1)
                goto escButton;
            if (numResult == -10)
                goto saveButton;
            if (numResult == 0)
            {
                errorMessage = "Thang khong hop le";
                drawTableErrors(errorMessage, false);
                continue;
            }
            if (numResult < 1 || numResult > 12)
            {
                errorMessage = "Thang khong hop le";
                drawTableErrors(errorMessage, false);
                continue;
            }
            drawTableErrors("", false);
            input.month = numResult;
            break;
        case 3:
            numResult = inputNumber(x + 94, y + 10, input.year, 4, "Nam lap", moveNext, false);
            if (numResult == -1)
                goto escButton;
            if (numResult == -10)
                goto saveButton;
            if (numResult == 0)
            {
                errorMessage = "Nam khong hop le";
                drawTableErrors(errorMessage, false);
                continue;
            }
            if (numResult < 1900 || numResult > 2100)
            {
                errorMessage = "Nam khong hop le";
                drawTableErrors(errorMessage, false);
                continue;
            }
            drawTableErrors("", false);
            input.year = numResult;
            break;
        case 4:
            result = inputString(x + 94, y + 12, input.loai, 1, "Loai (N/X)", moveNext, false);
            if (result == "ESC")
                goto escButton;
            if (result == "F10")
                goto saveButton;
            tempInput = normalizeString(result, hasError);
            if (hasError || (tempInput != "N" && tempInput != "X"))
            {
                errorMessage = "Loai hoa don khong hop le (N/X)";
                drawTableErrors(errorMessage, false);
                continue;
            }
            input.loai = tempInput[0];
            break;
        escButton:
            ShowCur(false);
            fillAreaColor(x + 76, y, 41, 17, LIGHTGRAY);
            isESC = true;
            return;
        saveButton:
            ShowCur(false);
            if (!moveNext && !input.SoHD.empty() && !input.loai.empty() && input.day != 0 && input.month != 0 && input.year != 0)
            {
                if (!isValidTime(input.day, input.month, input.year))
                {
                    errorMessage = "Ngay thang nam khong hop le";
                    drawTableErrors(errorMessage, false);
                    Sleep(1500);
                    drawTableErrors("", false);
                }
                else
                {
                    new_hd->data_hd.SoHD = input.SoHD;
                    new_hd->data_hd.day = input.day;
                    new_hd->data_hd.month = input.month;
                    new_hd->data_hd.year = input.year;
                    new_hd->data_hd.loai = input.loai;
                    errorMessage = "Them hoa don thanh cong";
                    drawTableErrors(errorMessage, false);
                    Sleep(1500);
                    drawTableErrors("", false);
                    fillAreaColor(x + 76, y, 41, 17, LIGHTGRAY);
                    drawTablePrintChiTietHoaDon(x, y, 15, 23);
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
                    isSaved = true;
                    return;
                }
            }
            else
            {
                errorMessage = "Thieu thong tin. Chua them hoa don";
                drawTableErrors(errorMessage, false);
                Sleep(1500);
                drawTableErrors("", false);
            }
        }
        if (moveNext)
        {
            currentRow = (currentRow < 4) ? currentRow + 1 : 4;
        }
        else
        {
            currentRow = (currentRow > 0) ? currentRow - 1 : 0;
        }
    }
}

void nhapChiTietHoaDon(dsNhanVien &ds_nv, treeVatTu &root, ptr_DSHD &hd, const string &currentMAVT, int x, int y, bool &isESC, bool &isSaved)
{
    if (hd == nullptr)
    {
        cout << "Hoa don khong ton tai" << endl;
        return;
    }

    nodeChiTietHoaDon input;
    input.soLuong = 0;
    input.donGia = 0;
    input.VAT = 0;
    string TENVT;
    string DVT;
    string errorMessage;
    int currentRow;
    treeVatTu found_vt = search(root, currentMAVT);
    if (found_vt != nullptr)
    {
        TENVT = found_vt->data_vt.TENVT;
        DVT = found_vt->data_vt.DVT;
        currentRow = 1;
        input.MAVT = currentMAVT;
    }
    else
    {
        found_vt = nullptr;
        currentRow = 0;
        input.MAVT = "";
    }
    bool hasError;
    string result;
    double numResult;
    bool moveNext;
    string tempInput;
    string donGia;
    while (true)
    {
        displayField(x + 94, y + 4, TENVT, false, 20);
        displayField(x + 94, y + 6, input.MAVT, currentRow == 0, 10);
        displayField(x + 94, y + 8, input.soLuong > 0 ? to_string(input.soLuong) + " " + DVT : "", currentRow == 1, 6);
        displayField(x + 94, y + 10, input.VAT > 0 ? to_string(input.VAT) + "%" : "", currentRow == 2, 3);
        displayField(x + 94, y + 12, input.donGia > 0 ? donGia + " VND" : "", currentRow == 3, 9);

        switch (currentRow)
        {
        case 0: // Nhập mã vật tư
            result = inputString(x + 94, y + 6, input.MAVT, 10, "Ma vat tu", moveNext, false);
            if (result == "ESC")
                goto escButton;
            if (result == "F10")
                goto saveButton;
            tempInput = normalizeString(result, hasError);
            if (hasError)
            {
                errorMessage = "Ma vat tu chua ky tu khong hop le";
                drawTableErrors(errorMessage, false);
                continue;
            }
            for (char &c : tempInput)
            {
                c = std::toupper(c);
            }
            // Kiểm tra vật tư có tồn tại trong kho
            input.MAVT = tempInput;
            displayField(x + 94, y + 6, input.MAVT, currentRow == 0, 10);
            found_vt = search(root, tempInput);
            if (found_vt == nullptr)
            {
                if (hd->data_hd.loai == "X")
                {
                    errorMessage = "Vat tu khong ton tai trong kho";
                    drawTableErrors(errorMessage, false);
                    continue;
                }
                else
                {
                    drawTableErrors("Nhap so luong de tao vat tu...", false);
                    ShowCur(true);
                    numResult = inputNumber(x + 94, y + 8, input.soLuong, 6, "So luong", moveNext, false);
                    if (numResult == -1)
                        goto escButton;
                    if (numResult == -10)
                        goto saveButton;
                    if (numResult <= 0)
                    {
                        errorMessage = "So luong phai lon hon 0";
                        drawTableErrors(errorMessage, false);
                        continue;
                    }
                    ShowCur(false);
                    drawTableErrors("", false);
                    input.soLuong = numResult;
                    drawTableErrors("Dang den trang tao vat tu...", false);
                    Sleep(1500);
                    drawTableErrors("", false);
                    fillAreaColor(x + 76, y, 41, 17, LIGHTGRAY);
                    drawTableAddVatTuInCTHD(x + 7, y);
                    nhapVatTu(root, x + 7, y, tempInput, input.soLuong, false, true);
                    treeVatTu node = search(root, tempInput);
                    fillAreaColor(x + 76, y, 41, 17, LIGHTGRAY);
                    drawTableUpdateChiTietHoaDon(x, y);
                    SetColor(WHITE);
                    TENVT = node->data_vt.TENVT;
                    input.MAVT = node->data_vt.MAVT;
                    found_vt = search(root, tempInput);
                    if (found_vt == nullptr)
                    {
                        drawTableErrors("Tao vat tu moi that bai", false);
                        return;
                    }
                }
            }
            else
            {
                bool isExisted = false;
                ptr_DSCTHD temp = hd->data_hd.firstCTHD;
                while (temp != nullptr)
                {
                    if (temp->data_cthd.MAVT == tempInput)
                    {
                        isExisted = true;
                    }
                    temp = temp->next;
                }
                if (isExisted)
                {
                    errorMessage = "Ma vat tu da ton tai trong hoa don";
                    drawTableErrors(errorMessage, false);
                    continue;
                }
                TENVT = found_vt->data_vt.TENVT;
                DVT = found_vt->data_vt.DVT;
            }
            drawTableErrors("", false);
            break;
        case 1: // Nhập số lượng
            for (int i = x + 94; i < x + 116; i++)
            {
                SetBGColor(BLACK);
                gotoxy(i, y + 8);
                cout << " ";
            }
            numResult = inputNumber(x + 94, y + 8, input.soLuong, 6, "So luong", moveNext, false);
            if (numResult == -1)
                goto escButton;
            if (numResult == -10)
                goto saveButton;

            if (numResult <= 0)
            {
                errorMessage = "So luong phai lon hon 0";
                drawTableErrors(errorMessage, false);
                continue;
            }

            // Kiểm tra số lượng tồn kho nếu là hóa đơn xuất
            if (hd->data_hd.loai == "X")
            {
                treeVatTu vt = search(root, input.MAVT);
                if (vt->data_vt.soLuongTon < numResult)
                {
                    errorMessage = "So luong ton kho hien tai: " + to_string(vt->data_vt.soLuongTon);
                    drawTableErrors(errorMessage, false);
                    continue;
                }
            }

            drawTableErrors("", false);
            input.soLuong = numResult;
            break;
        case 2: // Nhập VAT
            for (int i = x + 94; i < x + 116; i++)
            {
                SetBGColor(BLACK);
                gotoxy(i, y + 10);
                cout << " ";
            }
            numResult = inputNumber(x + 94, y + 10, input.VAT, 3, "VAT", moveNext, false);
            if (numResult == -1)
                goto escButton;
            if (numResult == -10)
                goto saveButton;

            if (numResult < 0 || numResult > 100)
            {
                errorMessage = "VAT phai nam trong khoang 0-100";
                drawTableErrors(errorMessage, false);
                continue;
            }

            drawTableErrors("", false);
            input.VAT = numResult;
            break;
        case 3: // Nhập đơn giá
            for (int i = x + 94; i < x + 116; i++)
            {
                SetBGColor(BLACK);
                gotoxy(i, y + 12);
                cout << " ";
            }
            numResult = inputNumber(x + 94, y + 12, input.donGia, 9, "Don gia", moveNext, false);
            if (numResult == -1)
                goto escButton;
            if (numResult == -10)
                goto saveButton;

            if (numResult <= 0)
            {
                errorMessage = "Don gia phai lon hon 0";
                drawTableErrors(errorMessage, false);
                continue;
            }
            drawTableErrors("", false);
            input.donGia = numResult;
            donGia = formatMoney(input.donGia);
            break;
        escButton:
            isESC = true;
            return;
        saveButton:
            ShowCur(false);
            if (!moveNext && !input.MAVT.empty() && input.soLuong > 0 && input.donGia > 0 && input.VAT >= 0)
            {
                // Tạo node chi tiết hóa đơn mới
                ptr_DSCTHD new_cthd = new dsChiTietHoaDon;
                new_cthd->data_cthd = input;
                new_cthd->next = nullptr;

                // Cập nhật số lượng tồn kho
                treeVatTu vt = search(root, input.MAVT);
                if (vt != nullptr)
                {
                    if (hd->data_hd.loai == "N")
                    {
                        vt->data_vt.soLuongTon += input.soLuong;
                    }
                    else if (hd->data_hd.loai == "X")
                    {
                        vt->data_vt.soLuongTon -= input.soLuong;
                    }
                }
                // Thêm vào danh sách chi tiết hóa đơn
                if (hd->data_hd.firstCTHD == nullptr)
                {
                    hd->data_hd.firstCTHD = new_cthd;
                }
                else
                {
                    ptr_DSCTHD temp = hd->data_hd.firstCTHD;
                    while (temp->next != nullptr)
                    {
                        temp = temp->next;
                    }
                    temp->next = new_cthd;
                }
                isSaved = true;
                return;
            }
            else
            {
                errorMessage = "Thieu thong tin. Chua them CTHD";
                drawTableErrors(errorMessage, false);
                Sleep(1500);
                drawTableErrors("", false);
            }
        }

        if (moveNext)
        {
            currentRow = (currentRow < 3) ? currentRow + 1 : 3;
        }
        else
        {
            currentRow = (currentRow > 0) ? currentRow - 1 : 0;
        }
        drawTableErrors("", false);
    }
}

// Hàm xóa chi tiết hóa đơn
void xoaChiTietHoaDon(dsNhanVien &ds_nv, treeVatTu &root, nhanVien *nv, ptr_DSHD &hd, string MAVT, int x, int y, bool &isESC, bool &isSaved)
{
    if (hd == nullptr || hd->data_hd.firstCTHD == nullptr)
    {
        cout << "Hoa don khong ton tai hoac khong co chi tiet" << endl;
        return;
    }

    // Tìm chi tiết hóa đơn cần xóa
    ptr_DSCTHD current = hd->data_hd.firstCTHD;
    ptr_DSCTHD prev = nullptr;

    while (current != nullptr && current->data_cthd.MAVT != MAVT)
    {
        prev = current;
        current = current->next;
    }

    if (current == nullptr)
    {
        cout << "Khong tim thay chi tiet hoa don voi ma vat tu nay" << endl;
        return;
    }
    char key;
    treeVatTu vt = search(root, MAVT);

    displayField(x + 94, y + 4, vt->data_vt.TENVT, false, 20);
    displayField(x + 94, y + 6, current->data_cthd.MAVT, false, 10);
    displayField(x + 94, y + 8, to_string(current->data_cthd.soLuong), false, 6);
    displayField(x + 94, y + 10, to_string(current->data_cthd.VAT), false, 3);
    displayField(x + 94, y + 12, to_string(current->data_cthd.donGia), false, 9);
    while (true)
    {
        key = getch();
        if (key == F10)
        {
            if (vt != nullptr)
            {
                if (hd->data_hd.loai == "N")
                {
                    // Nếu là hóa đơn nhập, trừ số lượng tồn
                    vt->data_vt.soLuongTon -= current->data_cthd.soLuong;
                }
                else if (hd->data_hd.loai == "X")
                {
                    // Nếu là hóa đơn xuất, cộng lại số lượng tồn
                    vt->data_vt.soLuongTon += current->data_cthd.soLuong;
                }
            }
            if (prev == nullptr)
            {
                // Xóa node đầu
                hd->data_hd.firstCTHD = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            delete current;
            isSaved = true;
            return;
        }
        else if (key == ESC)
        {
            isESC = true;
            return;
        }
    }
    // Cập nhật số lượng tồn kho trước khi xóa
}

// Hàm sửa chi tiết hóa đơn
void suaChiTietHoaDon(dsNhanVien &ds_nv, treeVatTu &root, nhanVien *nv, ptr_DSHD &hd, string MAVT, int x, int y, bool &isESC, bool &isSaved)
{
    treeVatTu result = search(root, MAVT);
    if (hd == nullptr || hd->data_hd.firstCTHD == nullptr)
    {
        cout << "Hoa don khong ton tai hoac khong co chi tiet" << endl;
        return;
    }

    // Tìm chi tiết hóa đơn cần sửa
    ptr_DSCTHD current = hd->data_hd.firstCTHD;
    while (current != nullptr && current->data_cthd.MAVT != MAVT)
    {
        current = current->next;
    }

    if (current == nullptr)
    {
        cout << "Khong tim thay chi tiet hoa don voi ma vat tu nay" << endl;
        return;
    }

    // Lưu lại số lượng cũ để tính toán số lượng tồn kho
    int oldSoLuong = current->data_cthd.soLuong;

    nodeChiTietHoaDon input = current->data_cthd;
    string errorMessage;
    int currentRow = 1; // Bắt đầu từ số lượng (không cho sửa mã vật tư)
    bool hasError;
    double numResult;
    bool moveNext;

    while (true)
    {
        displayField(x + 94, y + 4, result->data_vt.TENVT, false, 20);
        displayField(x + 94, y + 6, input.MAVT, false, 10);
        displayField(x + 94, y + 8, input.soLuong > 0 ? to_string(input.soLuong) : "", currentRow == 1, 6);
        displayField(x + 94, y + 10, input.VAT > 0 ? to_string(input.VAT) : "", currentRow == 2, 3);
        displayField(x + 94, y + 12, input.donGia > 0 ? to_string(input.donGia) : "", currentRow == 3, 9);

        switch (currentRow)
        {
        case 1: // Sửa số lượng
            numResult = inputNumber(x + 94, y + 8, input.soLuong, 6, "So luong", moveNext, false);
            if (numResult == -1)
                goto escButton;
            if (numResult == -10)
                goto saveButton;

            if (numResult <= 0)
            {
                errorMessage = "So luong phai lon hon 0";
                drawTableErrors(errorMessage, false);
                continue;
            }

            // Kiểm tra số lượng tồn kho nếu là hóa đơn xuất
            if (hd->data_hd.loai == "X")
            {
                treeVatTu vt = search(root, input.MAVT);
                // Tính toán số lượng thực tế cần kiểm tra
                int soLuongKiemTra = vt->data_vt.soLuongTon + oldSoLuong - numResult;
                if (soLuongKiemTra < 0)
                {
                    errorMessage = "So luong vuot qua ton kho";
                    drawTableErrors(errorMessage, false);
                    continue;
                }
            }

            drawTableErrors("", false);
            input.soLuong = numResult;
            break;

        case 2: // Sửa VAT
            numResult = inputNumber(x + 94, y + 10, input.VAT, 3, "VAT", moveNext, false);
            if (numResult == -1)
                goto escButton;
            if (numResult == -10)
                goto saveButton;

            if (numResult < 0 || numResult > 100)
            {
                errorMessage = "VAT phai nam trong khoang 0-100";
                drawTableErrors(errorMessage, false);
                continue;
            }

            drawTableErrors("", false);
            input.VAT = numResult;
            break;

        case 3: // Sửa đơn giá
            numResult = inputNumber(x + 94, y + 12, input.donGia, 9, "Don gia", moveNext, false);
            if (numResult == -1)
                goto escButton;
            if (numResult == -10)
                goto saveButton;

            if (numResult <= 0)
            {
                errorMessage = "Don gia phai lon hon 0";
                drawTableErrors(errorMessage, false);
                continue;
            }

            drawTableErrors("", false);
            input.donGia = numResult;
            break;

        escButton:
            isESC = true;
            return;
        saveButton:
            ShowCur(false);
            if (!moveNext && input.soLuong > 0 && input.donGia > 0 && input.VAT >= 0)
            {
                // Cập nhật số lượng tồn kho
                treeVatTu vt = search(root, input.MAVT);
                if (vt != nullptr)
                {
                    if (hd->data_hd.loai == "N")
                    {
                        vt->data_vt.soLuongTon = vt->data_vt.soLuongTon - oldSoLuong + input.soLuong;
                    }
                    else if (hd->data_hd.loai == "X")
                    {
                        vt->data_vt.soLuongTon = vt->data_vt.soLuongTon + oldSoLuong - input.soLuong;
                    }
                }
                // Cập nhật thông tin chi tiết hóa đơn
                current->data_cthd = input;
                isSaved = true;
                return;
            }
            else
            {
                drawTableErrors("Thieu thong tin. Chua cap nhat chi tiet hoa don", false);
                Sleep(1500);
                drawTableErrors("", false);
            }
        }

        if (moveNext)
        {
            currentRow = (currentRow < 3) ? currentRow + 1 : 3;
        }
        else
        {
            currentRow = (currentRow > 1) ? currentRow - 1 : 1;
        }
    }
}

float tinhTriGiaHoaDon(ptr_DSCTHD ct)
{
    float totalValue = 0;
    while (ct)
    {
        totalValue += ct->data_cthd.soLuong * (float)ct->data_cthd.donGia / 1000 * (1 + (float)ct->data_cthd.VAT / 100);
        ct = ct->next;
    }
    return totalValue * 1000;
}

void inChiTietHoaDon(dsNhanVien &ds_nv, treeVatTu &root, ptr_DSHD &found_hd, int pageNumber, int selectedRow, int &totalPages, int x, int y, string &errorMessage, bool &isEmpty)
{
    string tempInput;
    string result;
    bool hasError = false;
    bool moveNext;
    searchHoaDon(ds_nv, found_hd->data_hd.SoHD, found_hd);
    if (found_hd == nullptr)
    {
        ShowCur(false);
        errorMessage = "Khong tim thay hoa don";
        drawTableErrors(errorMessage, false);
        Sleep(1500);
        drawTableErrors("", false);
        return;
    }
    float triGiaHD = tinhTriGiaHoaDon(found_hd->data_hd.firstCTHD);
    int n = 0;
    ptr_DSCTHD temp_cthd = found_hd->data_hd.firstCTHD;
    while (temp_cthd != nullptr)
    {
        n++;
        temp_cthd = temp_cthd->next;
    }
    nodeChiTietHoaDon *arrCTHD = new nodeChiTietHoaDon[n];
    nodeVatTu *arrVT = new nodeVatTu[n];
    ptr_DSCTHD current_cthd = found_hd->data_hd.firstCTHD;
    float arrTriGia[n];
    if (current_cthd == nullptr)
    {
        isEmpty = true;
        return;
    }
    for (int i = 0; i < n && current_cthd != nullptr; i++)
    {
        arrTriGia[n] = 0;
        arrCTHD[i].MAVT = current_cthd->data_cthd.MAVT;

        treeVatTu node = search(root, current_cthd->data_cthd.MAVT);
        if (node == nullptr)
        {
            drawTableErrors("Khong tim thay ma vat tu", false);
            break;
        }
        else
        {
            arrVT[i].TENVT = node->data_vt.TENVT;
            arrCTHD[i].soLuong = current_cthd->data_cthd.soLuong;
            arrCTHD[i].donGia = (float)current_cthd->data_cthd.donGia / 1000;
            arrCTHD[i].VAT = current_cthd->data_cthd.VAT;
            arrTriGia[i] = arrCTHD[i].soLuong * arrCTHD[i].donGia * (1 + (float)(arrCTHD[i].VAT) / 100);
        }
        current_cthd = current_cthd->next;
    }
    int startIndex = (pageNumber - 1) * HDROWS;
    int endIndex = min(startIndex + HDROWS - 1, n);
    int currentRow = 13;
    for (int i = startIndex; i < endIndex; i++)
    {
        gotoxy(x + 3, currentRow);
        if (selectedRow == i - startIndex)
        {
            Highlight(LIGHTBLUE);
            cout << arrCTHD[i].MAVT;
            setColorByRequest(LIGHTGRAY, BLACK);
        }
        else
        {
            cout << arrCTHD[i].MAVT;
        }
        gotoxy(x + 18, currentRow);
        cout << arrVT[i].TENVT;
        gotoxy(x + 43, currentRow);
        cout << arrCTHD[i].soLuong;
        gotoxy(x + 54, currentRow);
        cout << arrCTHD[i].donGia;
        gotoxy(x + 65, currentRow);
        cout << arrTriGia[i];
        currentRow++;
    }
    gotoxy(x + 18, y + 23);
    string triGia = formatMoney(triGiaHD);
    cout << triGia << " VND";
    totalPages = ceil((float)n / HDROWS);
    gotoxy(52, 26);
    cout << "<- Trang " << pageNumber << "/" << totalPages << " ->";
    delete[] arrCTHD;
    delete[] arrVT;
}

void inHoaDon(dsNhanVien &ds_nv, treeVatTu &root, int pageNumber, int selectedRow, int &totalPages, int x, int y, string &errorMessage, bool &isESC, bool &isInputting)
{
    static string so_hd = "";
    string tempInput;
    string result;
    bool hasError = false;
    bool moveNext;
    if (isInputting)
    {
        displayField(x + 95, y + 4, so_hd, true, 10);
        while (isInputting)
        {
            result = inputString(x + 95, y + 4, so_hd, 20, "So hoa don", moveNext, false);
            ShowCur(false);
            if (result == "ESC")
            {
                isESC = true;
                return;
            }
            tempInput = normalizeString(result, hasError);
            if (hasError)
            {
                errorMessage = "So hoa don chua ky tu khong hop le";
                drawTableErrors(errorMessage, false);
                continue;
            }
            if (tempInput.empty())
            {
                errorMessage = "So hoa don khong duoc de trong";
                drawTableErrors(errorMessage, false);
                continue;
            }
            for (char &c : tempInput)
            {
                c = std::toupper(c); // Chuyển từng ký tự sang chữ hoa
            }
            so_hd = tempInput;
            drawTableErrors("", false);
            break;
        }
        fillAreaColor(x + 76, y, 41, 17, LIGHTGRAY);
        x = 5;
        drawTablePrintCTHDInListCTHD(x, y, 15, 23);
    }
    x = 5;
    nhanVien *nv = nullptr;
    ptr_DSHD found_hd = nullptr;
    for (int i = 0; i < ds_nv.countNV; ++i)
    {
        if (ds_nv.nodes[i] != nullptr)
        {
            ptr_DSHD current_hd = ds_nv.nodes[i]->firstDSHD;
            while (current_hd != nullptr)
            {
                if (current_hd->data_hd.SoHD == so_hd)
                {
                    nv = ds_nv.nodes[i];
                    found_hd = current_hd;
                    nv->MANV = ds_nv.nodes[i]->MANV;
                    nv->HO = ds_nv.nodes[i]->HO;
                    nv->TEN = ds_nv.nodes[i]->TEN;
                    break;
                }
                current_hd = current_hd->next;
            }
            if (found_hd != nullptr)
                break;
        }
    }
    if (found_hd == nullptr)
    {
        ShowCur(false);
        errorMessage = "Khong tim thay hoa don";
        drawTableErrors(errorMessage, false);
        Sleep(1500);
        drawTableErrors("", false);
        return;
    }
    setColorByRequest(LIGHTGRAY, BLACK);
    float triGiaHD = tinhTriGiaHoaDon(found_hd->data_hd.firstCTHD) / 1000;
    gotoxy(x + 15, y + 1);
    cout << found_hd->data_hd.SoHD;
    gotoxy(x + 42, y + 1);
    cout << (found_hd->data_hd.loai == "N" ? "Nhap" : "Xuat");
    gotoxy(x + 24, y + 3);
    cout << nv->MANV;
    gotoxy(x + 24, y + 5);
    cout << nv->HO << " " << nv->TEN;
    gotoxy(x + 9, y + 7);
    cout << found_hd->data_hd.day;
    gotoxy(x + 24, y + 7);
    cout << found_hd->data_hd.month;
    gotoxy(x + 36, y + 7);
    cout << found_hd->data_hd.year;
    int n = 0;
    ptr_DSCTHD temp_cthd = found_hd->data_hd.firstCTHD;
    while (temp_cthd != nullptr)
    {
        n++;
        temp_cthd = temp_cthd->next;
    }
    nodeChiTietHoaDon *arrCTHD = new nodeChiTietHoaDon[n];
    nodeVatTu *arrVT = new nodeVatTu[n];
    ptr_DSCTHD current_cthd = found_hd->data_hd.firstCTHD;
    float arrTriGia[n];
    for (int i = 0; i < n && current_cthd != nullptr; i++)
    {
        arrTriGia[i] = 0;
        arrCTHD[i].MAVT = current_cthd->data_cthd.MAVT;

        treeVatTu node = search(root, current_cthd->data_cthd.MAVT);
        if (node == nullptr)
        {
            errorMessage = "Khong tim thay ma vat tu";
            drawTableErrors(errorMessage, false);
            break;
        }
        else
        {
            arrVT[i].TENVT = node->data_vt.TENVT;
            arrCTHD[i].soLuong = current_cthd->data_cthd.soLuong;
            arrCTHD[i].donGia = (float)current_cthd->data_cthd.donGia / 1000;
            arrCTHD[i].VAT = current_cthd->data_cthd.VAT;
            arrTriGia[i] = arrCTHD[i].soLuong * arrCTHD[i].donGia * (1 + (float)arrCTHD[i].VAT / 100);
        }
        current_cthd = current_cthd->next;
    }
    int startIndex = (pageNumber - 1) * HDROWS;
    int endIndex = min(startIndex + HDROWS - 1, n);
    int currentRow = 13;
    for (int i = startIndex; i < endIndex; i++)
    {
        gotoxy(x + 3, currentRow);
        if (selectedRow == i - startIndex)
        {
            Highlight(LIGHTBLUE);
            cout << arrCTHD[i].MAVT;
            setColorByRequest(LIGHTGRAY, BLACK);
        }
        else
        {
            cout << arrCTHD[i].MAVT;
        }
        gotoxy(x + 18, currentRow);
        cout << arrVT[i].TENVT;
        gotoxy(x + 43, currentRow);
        cout << arrCTHD[i].soLuong;
        gotoxy(x + 54, currentRow);
        cout << arrCTHD[i].donGia;
        gotoxy(x + 65, currentRow);
        string triGia = formatMoney(arrTriGia[i]);
        cout << triGia;
        currentRow++;
    }
    gotoxy(x + 18, y + 23);
    string tongTriGia = formatMoney(triGiaHD);
    cout << tongTriGia << " VND";
    totalPages = ceil((float)n / HDROWS);
    gotoxy(74, 26);
    cout << "<- Trang " << pageNumber << "/" << totalPages << " ->";
    delete[] arrCTHD;
    delete[] arrVT;
    if (isInputting)
    {
        isInputting = false;
        return;
    }
}