#pragma once
#include "vatTu.h"
bool nhanVienEmpty(dsNhanVien &list)
{
    return list.CountNV == 0;
}
bool isMANV(dsNhanVien &list, string maso)
{
    for (int i = 0; i < list.CountNV; i++)
    {
        if (list.nodes[i]->MANV == maso)
        {
            return true;
        }
    }
    return false;
}
void formatInputNV(string &MANV, string &HO, string &TEN, string &PHAI)
{
    if (MANV.length() > 10)
    {
        MANV = MANV.substr(0, 10);
    }
    if (HO.length() > 20)
    {
        HO = HO.substr(0, 20);
    }
    if (TEN.length() > 6)
    {
        TEN = TEN.substr(0, 6);
    }
    if (PHAI.length() > 6)
    {
        PHAI = PHAI.substr(0, 6);
    }
}
bool checkThongTin(string type, string value, nhanVien *&nv, dsNhanVien &list)
{
    if (type == "MANV")
    {
        if (value.empty())
        {
            cout << "Loi: Ma nhan vien khong duoc rong!" << endl;
            return true;
        }

        // Xóa khoảng trắng
        string result;
        for (const char c : value)
        {
            if (c != ' ')
            {
                result += c;
            }
        }
        value = result;

        if (value.length() > 10)
        {
            cout << "Loi: Ma nhan vien khong duoc qua 10 ky tu!" << endl;
            return true;
        }

        if (isMANV(list, value))
        {
            cout << "Loi: Ma nhan vien da ton tai!" << endl;
            return true;
        }

        nv->MANV = value;
    }
    else if (type == "HO")
    {
        if (value.empty())
        {
            cout << "Loi: Ho nhan vien khong duoc rong!" << endl;
            return true;
        }

        bool hasError;
        value = normalizeString(value, hasError);
        if (hasError)
        {
            return true;
        }

        nv->HO = value;
    }
    else if (type == "TEN")
    {
        if (value.empty())
        {
            cout << "Loi: Ten nhan vien khong duoc rong!" << endl;
            return true;
        }

        bool hasError;
        value = normalizeString(value, hasError);
        if (hasError)
        {
            return true;
        }

        for (char c : value)
        {
            if (c == ' ')
            {
                cout << "Loi: Ten nhan vien khong duoc chua khoang trang!" << endl;
                return true;
            }
        }

        nv->TEN = value;
    }
    else if (type == "PHAI")
    {
        if (value.empty() || (value != "nam" && value != "nu"))
        {
            cout << "Loi: Gioi tinh khong hop le!" << endl;
            return true;
        }

        nv->PHAI = value;
    }

    return false;
}

int searchNhanVien(dsNhanVien &list, string manv)
{
    for (int i = 0; i < list.CountNV; i++)
    {
        if (list.nodes[i]->MANV == manv)
        {
            return i;
        }
    }
    cout << "Khong tim thay nhan vien!" << endl;
    return -1;
}

void chenNhanVien(dsNhanVien &list, nhanVien *nhanvienmoi)
{
    if (list.CountNV >= MaxNhanVien)
    {
        cout << "Loi: So luong nhan vien da dat toi da. Khong the them nhan vien moi!" << endl;
        return;
    }

    int pos = 0;
    while (pos < list.CountNV && (nhanvienmoi->TEN > list.nodes[pos]->TEN ||
                                  (nhanvienmoi->TEN == list.nodes[pos]->TEN && nhanvienmoi->HO >= list.nodes[pos]->HO)))
    {
        pos++;
    }
    for (int i = list.CountNV; i > pos; i--)
    {
        list.nodes[i] = list.nodes[i - 1];
    }

    list.nodes[pos] = nhanvienmoi;
}

void xoaNhanVien(dsNhanVien &list, string MANV, int x, int y, bool &isESC, bool &isSaved)
{
    nhanVien input;
    input.MANV = "";
    input.HO = "";
    input.TEN = "";
    input.PHAI = "";
    isESC = false;
    isSaved = false;
    if (nhanVienEmpty(list))
    {
        cout << "Danh sach nhan vien rong!";
        return;
    }
    int pos = searchNhanVien(list, MANV);
    if (pos == -1)
    {
        cout << "Khong tim thay ma nhan vien " << MANV << endl;
        return;
    }
    input.MANV = list.nodes[pos]->MANV;
    input.HO = list.nodes[pos]->HO;
    input.TEN = list.nodes[pos]->TEN;
    input.PHAI = list.nodes[pos]->PHAI;

    displayField(x + 87, y + 4, input.MANV, false, 10);
    displayField(x + 87, y + 6, input.HO, false, 20);
    displayField(x + 87, y + 8, input.TEN, false, 10);
    displayField(x + 87, y + 10, input.PHAI, false, 3);
    char key;
    while (true)
    {
        key = getch();
        switch (key)
        {
        case ESC:
            isESC = true;
            return;
        case F4:
            delete list.nodes[pos];
            for (int i = pos; i < list.CountNV - 1; i++)
            {
                list.nodes[i] = list.nodes[i + 1];
            }
            list.CountNV--;
            isSaved = true;
            return;
        }
    }
}

void nhapNhanVien(dsNhanVien &list, int x, int y)
{
    if (list.CountNV >= MaxNhanVien)
    {
        string errorMessage = "So luong nhan vien da dat toi da!";
        drawTableErrors(5, 2, errorMessage);
        Sleep(1500);
        return;
    }

    nhanVien input;
    input.MANV = "";
    input.HO = "";
    input.TEN = "";
    input.PHAI = "";
    string errorMessage;
    int currentRow = 0;
    bool hasError;
    string result;
    bool moveNext;
    string tempInput;

    while (true)
    {
        // Hiển thị tất cả các trường
        displayField(x + 87, y + 4, input.MANV, currentRow == 0, 10);
        displayField(x + 87, y + 6, input.HO, currentRow == 1, 20);
        displayField(x + 87, y + 8, input.TEN, currentRow == 2, 10);
        displayField(x + 87, y + 10, input.PHAI, currentRow == 3, 3);

        switch (currentRow)
        {
        case 0:
        {
            result = inputString(x + 87, y + 4, input.MANV, 10, "Ma nhan vien", moveNext);
            if (result == "ESC")
                goto escButton;
            if (result == "F4")
                goto saveButton;

            tempInput = normalizeString(result, hasError);
            if (hasError)
            {
                errorMessage = "Ma nhan vien chua ky tu khong hop le";
                drawTableErrors(5, 2, errorMessage);
                continue;
            }

            // Kiểm tra mã nhân viên đã tồn tại
            if (searchNhanVien(list, tempInput) != -1)
            {
                errorMessage = "Ma nhan vien da ton tai";
                drawTableErrors(5, 2, errorMessage);
                continue;
            }
            errorMessage = "";
            drawTableErrors(5, 2, errorMessage);
            input.MANV = tempInput;
            formatInputNV(input.MANV, input.HO, input.TEN, input.PHAI);
            break;
        }
        case 1:
        {
            result = inputString(x + 87, y + 6, input.HO, 20, "Ho nhan vien", moveNext);
            if (result == "ESC")
                goto escButton;
            if (result == "F4")
                goto saveButton;

            tempInput = normalizeString(result, hasError);
            if (hasError)
            {
                errorMessage = "Ho nhan vien chua ky tu khong hop le";
                drawTableErrors(5, 2, errorMessage);
                continue;
            }
            input.HO = tempInput;
            formatInputNV(input.MANV, input.HO, input.TEN, input.PHAI);
            break;
        }
        case 2:
        {
            result = inputString(x + 87, y + 8, input.TEN, 10, "Ten nhan vien", moveNext);
            if (result == "ESC")
                goto escButton;
            if (result == "F4")
                goto saveButton;

            tempInput = normalizeString(result, hasError);
            if (hasError)
            {
                errorMessage = "Ten nhan vien chua ky tu khong hop le";
                drawTableErrors(5, 2, errorMessage);
                continue;
            }
            input.TEN = tempInput;
            formatInputNV(input.MANV, input.HO, input.TEN, input.PHAI);
            break;
        }
        case 3:
        {
            result = inputString(x + 87, y + 10, input.PHAI, 3, "Gioi tinh (nam/nu)", moveNext);
            if (result == "ESC")
                goto escButton;
            if (result == "F4")
                goto saveButton;

            tempInput = normalizeString(result, hasError);
            if (hasError || (tempInput != "Nam" && tempInput != "Nu"))
            {
                errorMessage = "Gioi tinh khong hop le (Nam/Nu)";
                drawTableErrors(5, 2, errorMessage);
                continue;
            }
            input.PHAI = tempInput;
            formatInputNV(input.MANV, input.HO, input.TEN, input.PHAI);
            break;
        }
        escButton:
        {
            ShowCur(false);
            errorMessage = "Dang thoat chuong trinh...";
            drawTableErrors(5, 2, errorMessage);
            Sleep(1500);
            errorMessage = "";
            drawTableErrors(5, 2, errorMessage);
            fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
            return;
        }
        saveButton:
        {
            ShowCur(false);
            if (!moveNext && !input.MANV.empty() && !input.HO.empty() &&
                !input.TEN.empty() && !input.PHAI.empty())
            {
                nhanVien *nv = new nhanVien(input);
                if (list.CountNV == 0)
                {
                    list.nodes[list.CountNV] = nv;
                }
                else
                {
                    chenNhanVien(list, nv);
                }
                list.CountNV++;

                errorMessage = "Them nhan vien thanh cong";
                drawTableErrors(5, 2, errorMessage);
                Sleep(1500);
                errorMessage = "";
                drawTableErrors(5, 2, errorMessage);
                fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                return;
            }
            else
            {
                errorMessage = "Thieu thong tin. Chua them nhan vien";
                drawTableErrors(5, 2, errorMessage);
                Sleep(1500);
                errorMessage = "";
                drawTableErrors(5, 2, errorMessage);
            }
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
    }
}
// Hàm sửa nhân viên
void suaNhanVien(dsNhanVien &list, string MANV, int x, int y, bool &isESC, bool &isSaved)
{
    if (nhanVienEmpty(list))
    {
        string errorMessage = "Danh sach nhan vien trong!";
        drawTableErrors(5, 2, errorMessage);
        Sleep(1500);
        return;
    }

    nhanVien input;
    input.MANV = "";
    input.HO = "";
    input.TEN = "";
    input.PHAI = "";
    string errorMessage;
    int currentRow = 1;
    bool hasError;
    string result;
    bool moveNext;
    string tempInput;
    isESC = false;
    isSaved = false;

    int pos = searchNhanVien(list, MANV);
    if (pos == -1)
    {
        errorMessage = "Khong tim thay nhan vien voi ma " + MANV;
        drawTableErrors(5, 2, errorMessage);
        Sleep(1500);
        return;
    }
    input.MANV = list.nodes[pos]->MANV;
    input.HO = list.nodes[pos]->HO;
    input.TEN = list.nodes[pos]->TEN;
    input.PHAI = list.nodes[pos]->PHAI;
    while (true)
    {
        displayField(x + 87, y + 4, input.MANV, false, 10);
        displayField(x + 87, y + 6, input.HO, currentRow == 1, 20);
        displayField(x + 87, y + 8, input.TEN, currentRow == 2, 10);
        displayField(x + 87, y + 10, input.PHAI, currentRow == 3, 3);

        switch (currentRow)
        {
        case 1:
        {
            result = inputString(x + 87, y + 6, input.HO, 20, "Ho nhan vien", moveNext);
            if (result == "ESC")
                goto escButton;
            if (result == "F4")
                goto saveButton;

            tempInput = normalizeString(result, hasError);
            if (hasError)
            {
                errorMessage = "Ho nhan vien chua ky tu khong hop le!";
                drawTableErrors(5, 2, errorMessage);
                continue;
            }
            input.HO = tempInput;
            formatInputNV(input.MANV, input.HO, input.TEN, input.PHAI);
            break;
        }
        case 2:
        {
            result = inputString(x + 87, y + 8, input.TEN, 10, "Ten nhan vien", moveNext);
            if (result == "ESC")
                goto escButton;
            if (result == "F4")
                goto saveButton;

            tempInput = normalizeString(result, hasError);
            if (hasError)
            {
                errorMessage = "Ten nhan vien chua ky tu khong hop le!";
                drawTableErrors(5, 2, errorMessage);
                continue;
            }
            input.TEN = tempInput;
            formatInputNV(input.MANV, input.HO, input.TEN, input.PHAI);
            break;
        }
        case 3:
        {
            result = inputString(x + 87, y + 10, input.PHAI, 3, "Gioi tinh (nam/nu)", moveNext);
            if (result == "ESC")
                goto escButton;
            if (result == "F4")
                goto saveButton;

            tempInput = normalizeString(result, hasError);
            if (hasError || (tempInput != "nam" && tempInput != "nu"))
            {
                errorMessage = "Gioi tinh khong hop le (nam/nu)!";
                drawTableErrors(5, 2, errorMessage);
                continue;
            }
            input.PHAI = tempInput;
            formatInputNV(input.MANV, input.HO, input.TEN, input.PHAI);
            break;
        }
        escButton:
        {
            isESC = true;
            return;
        }
        saveButton:
        {
            if (!moveNext && !input.MANV.empty() && !input.HO.empty() &&
                !input.TEN.empty() && !input.PHAI.empty())
            {
                bool needReorder = (list.nodes[pos]->HO != input.HO ||
                                    list.nodes[pos]->TEN != input.TEN);

                if (needReorder)
                {
                    // Lưu lại con trỏ node hiện tại
                    nhanVien *currentNode = list.nodes[pos];

                    // Cập nhật thông tin
                    currentNode->HO = input.HO;
                    currentNode->TEN = input.TEN;
                    currentNode->PHAI = input.PHAI;

                    // Xóa node khỏi vị trí hiện tại
                    for (int i = pos; i < list.CountNV - 1; i++)
                    {
                        list.nodes[i] = list.nodes[i + 1];
                    }
                    list.CountNV--;

                    // Chèn lại vào vị trí mới theo thứ tự
                    chenNhanVien(list, currentNode);
                    list.CountNV++;
                }
                else
                {
                    list.nodes[pos]->PHAI = input.PHAI;
                }
                isSaved = true;
                return;
            }
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

void xoaDSNV(dsNhanVien &list) // goi khi ket thuc
{
    if (nhanVienEmpty(list))
        return;

    for (int i = 0; i < list.CountNV; i++)
    {
        delete list.nodes[i];
        list.nodes[i] = NULL;
    }
    list.CountNV = 0;
}

void Write_CTHoaDon(ofstream &file, nodeChiTietHoaDon &cthd)
{
    file << "+" << cthd.MAVT << "|" << cthd.soLuong << "|" << cthd.donGia << "|" << cthd.VAT;
}

void Write_HoaDon(ofstream &file, nodeHoaDon &hd)
{
    file << "-" << hd.SoHD << "|" << hd.day << "|" << hd.month << "|" << hd.year << "|" << hd.loai << endl;

    // Ghi danh sách chi tiết hóa đơn
    ptr_DSCTHD current = hd.firstCTHD;
    while (current != nullptr)
    {
        Write_CTHoaDon(file, current->data_cthd);
        if (current->next != nullptr)
            file << " ";
        current = current->next;
    }
    file << endl;
}

void Write_NhanVien(ofstream &file, nhanVien &nv)
{
    file << nv.MANV << "|" << nv.HO << "|" << nv.TEN << "|" << nv.PHAI << endl;

    // Ghi danh sách hóa đơn của nhân viên
    ptr_DSHD current = nv.firstDSHD;
    while (current != nullptr)
    {
        Write_HoaDon(file, current->data_hd);
        current = current->next;
    }
    file << "\\" << endl;
}

void writeFile_dsNhanVien(dsNhanVien &dsNV)
{
    ofstream fileout;
    fileout.open(filePath_NV, ios_base::out);
    if (!fileout.is_open())
    {
        cerr << "Khong the mo file ghi!" << endl;
        return;
    }

    for (int i = 0; i < dsNV.CountNV; ++i)
    {
        Write_NhanVien(fileout, *dsNV.nodes[i]);
    }
    fileout.close();
    xoaDSNV(dsNV);
}

void Read_CTHoaDon(string cthdStr, nodeChiTietHoaDon &cthd)
{
    stringstream ss(cthdStr);

    getline(ss, cthd.MAVT, '|');
    string line;

    getline(ss, line, '|');
    cthd.soLuong = stoi(line);

    getline(ss, line, '|');
    cthd.donGia = stof(line);

    getline(ss, line);
    cthd.VAT = stof(line);
}

void Read_HoaDon(ifstream &file, nodeHoaDon &hd)
{
    string line;
    getline(file, line);

    if (line[0] != '-')
        return; // Kiểm tra dòng hóa đơn

    stringstream ss(line.substr(1)); // Bỏ qua dấu '-'

    getline(ss, hd.SoHD, '|');

    string temp;
    getline(ss, temp, '|');
    hd.day = stoi(temp);

    getline(ss, temp, '|');
    hd.month = stoi(temp);

    getline(ss, temp, '|');
    hd.year = stoi(temp);

    getline(ss, temp);
    hd.loai = temp[0];

    // Đọc chi tiết hóa đơn
    hd.firstCTHD = nullptr;
    ptr_DSCTHD *tail = &hd.firstCTHD;

    string chiTietLine;
    getline(file, chiTietLine);

    stringstream ctss(chiTietLine);
    string cthdStr;
    while (getline(ctss, cthdStr, ' '))
    {
        nodeChiTietHoaDon cthd;
        cthdStr = cthdStr.substr(1); // Bỏ qua dấu '+'
        Read_CTHoaDon(cthdStr, cthd);

        *tail = new dsChiTietHoaDon{cthd, nullptr};
        tail = &(*tail)->next;
    }
}

void Read_NhanVien(ifstream &file, nhanVien &nv)
{
    string line;
    getline(file, line);

    stringstream ss(line);

    getline(ss, nv.MANV, '|');
    getline(ss, nv.HO, '|');
    getline(ss, nv.TEN, '|');
    getline(ss, nv.PHAI);

    // Đọc danh sách hóa đơn
    nv.firstDSHD = nullptr;
    ptr_DSHD *tail = &nv.firstDSHD;

    while (true)
    {
        char peek = file.peek();
        if (peek == '\\' || peek == EOF)
            break;

        nodeHoaDon hd;
        Read_HoaDon(file, hd);

        *tail = new dsHoaDon{hd, nullptr};
        tail = &(*tail)->next;
    }

    // Đọc dấu '\' và xuống dòng
    string endLine;
    getline(file, endLine);
}

void readFile_dsNhanVien(dsNhanVien &dsNV)
{
    ifstream filein;
    filein.open(filePath_NV, ios_base::in);
    if (!filein.is_open())
    {
        cerr << "Khong the mo file doc!" << endl;
        return;
    }

    // Tạo một mảng tạm để lưu trữ các nhân viên
    nhanVien *tempNodes[MaxNhanVien];
    int tempCount = 0;
    string line;

    while (getline(filein, line))
    {
        // Nếu là dòng thông tin nhân viên
        if (line[0] != '-' && line[0] != '+' && line[0] != '\\')
        {
            // Tạo nhân viên mới
            tempNodes[tempCount] = new nhanVien;

            // Parse thông tin nhân viên
            stringstream ss(line);
            getline(ss, tempNodes[tempCount]->MANV, '|');
            getline(ss, tempNodes[tempCount]->HO, '|');
            getline(ss, tempNodes[tempCount]->TEN, '|');
            getline(ss, tempNodes[tempCount]->PHAI);

            // Khởi tạo con trỏ danh sách hóa đơn
            tempNodes[tempCount]->firstDSHD = nullptr;

            // Tăng số lượng nhân viên trong mảng tạm
            tempCount++;
        }
        // Nếu là dòng hóa đơn
        else if (line[0] == '-')
        {
            // Tạo hóa đơn mới cho nhân viên cuối cùng
            nodeHoaDon hd;
            stringstream ss(line.substr(1)); // Bỏ qua dấu '-'

            getline(ss, hd.SoHD, '|');
            string temp;
            getline(ss, temp, '|');
            hd.day = stoi(temp);
            getline(ss, temp, '|');
            hd.month = stoi(temp);
            getline(ss, temp, '|');
            hd.year = stoi(temp);
            getline(ss, temp);
            hd.loai = temp[0];

            // Khởi tạo con trỏ chi tiết hóa đơn
            hd.firstCTHD = nullptr;

            // Thêm hóa đơn vào danh sách hóa đơn của nhân viên cuối cùng
            ptr_DSHD newNode = new dsHoaDon{hd, nullptr};

            // Nếu danh sách rỗng
            if (tempNodes[tempCount - 1]->firstDSHD == nullptr)
            {
                tempNodes[tempCount - 1]->firstDSHD = newNode;
            }
            else
            {
                // Tìm nút cuối cùng
                ptr_DSHD current = tempNodes[tempCount - 1]->firstDSHD;
                while (current->next != nullptr)
                {
                    current = current->next;
                }
                current->next = newNode;
            }
        }
        // Nếu là dòng chi tiết hóa đơn
        else if (line[0] == '+')
        {
            // Thêm chi tiết hóa đơn vào hóa đơn cuối cùng của nhân viên cuối cùng
            nodeChiTietHoaDon cthd;
            Read_CTHoaDon(line.substr(1), cthd);

            // Tìm hóa đơn cuối cùng của nhân viên cuối cùng
            ptr_DSHD current_hd = tempNodes[tempCount - 1]->firstDSHD;
            while (current_hd->next != nullptr)
            {
                current_hd = current_hd->next;
            }

            // Thêm chi tiết hóa đơn vào hóa đơn
            ptr_DSCTHD newCTHD = new dsChiTietHoaDon{cthd, nullptr};

            // Nếu danh sách chi tiết hóa đơn rỗng
            if (current_hd->data_hd.firstCTHD == nullptr)
            {
                current_hd->data_hd.firstCTHD = newCTHD;
            }
            else
            {
                // Tìm nút cuối cùng
                ptr_DSCTHD current_cthd = current_hd->data_hd.firstCTHD;
                while (current_cthd->next != nullptr)
                {
                    current_cthd = current_cthd->next;
                }
                current_cthd->next = newCTHD;
            }
        }
    }
    filein.close();

    // Reset danh sách nhân viên hiện tại
    dsNV.CountNV = 0;

    // Chèn từng nhân viên vào danh sách chính theo thứ tự
    for (int i = 0; i < tempCount; i++)
    {
        if (dsNV.CountNV >= MaxNhanVien)
        {
            cout << "Danh sach nhan vien da day!" << endl;
            break;
        }
        chenNhanVien(dsNV, tempNodes[i]);
        dsNV.CountNV++;
    }
}
// ==============================================
void inDanhSachNhanVien(dsNhanVien &list, int pageNumber, int selectedRow, int x, string &errorMessage)
{
    int n = list.CountNV;
    if (n == 0)
    {
        errorMessage = "Khong co du lieu vat tu";
        drawTableErrors(5, 2, errorMessage);
        return;
    }
    int index = 0;
    int startIndex = (pageNumber - 1) * ROWS;
    int endIndex = min(startIndex + ROWS, n);
    int currentRow = 5;
    for (int i = startIndex; i < endIndex; i++)
    {
        // MAVT column - với highlight nếu được chọn
        gotoxy(x + 3, currentRow);
        if (selectedRow == -1)
            cout << list.nodes[i]->MANV;
        else if (i - startIndex == selectedRow)
        {
            Highlight(LIGHTBLUE);
            cout << list.nodes[i]->MANV;
            setColorByRequest(LIGHTGRAY, BLACK); // Reset về màu bình thường ngay sau khi in MAVT
        }
        else
        {
            cout << list.nodes[i]->MANV;
        }

        // TENVT column - không highlight
        gotoxy(x + 18, currentRow);
        cout << list.nodes[i]->HO;

        // DVT column - không highlight
        gotoxy(x + 43, currentRow);
        cout << list.nodes[i]->TEN;

        // SoLuongTon column - không highlight
        gotoxy(x + 54, currentRow);
        cout << list.nodes[i]->PHAI;
        currentRow++;
    }
    // in so trang
    int totalPages = ceil((float)n / ROWS);
    gotoxy(6, 26);
    cout << "TAB: Di chuyen den trang can tim";
    gotoxy(52, 26);
    cout << "<- Trang " << pageNumber << "/" << totalPages << " ->";
}
//======================HOA DON===================================
void lapHoaDon(dsNhanVien &ds_nv, treeVatTu &root)
{
    string ma_nv;
    cout << "Nhap ma nhan vien lap hoa don: ";
    cin >> ma_nv;
    nhanVien *nv = nullptr;
    for (int i = 0; i < ds_nv.CountNV; ++i) // Tìm  nhân viên trong danh sách
    {
        if (ds_nv.nodes[i]->MANV == ma_nv)
        {
            nv = ds_nv.nodes[i]; // Gán con trỏ nv đến nhân viên tìm được
            break;
        }
    }

    if (nv == nullptr) // Nếu không tìm được
    {
        cout << "Ma nhan vien khong ton tai!" << endl;
        return;
    }

    // Khởi tạo hóa đơn mới
    ptr_DSHD new_hd = new dsHoaDon;
    new_hd->data_hd.firstCTHD = nullptr;
    new_hd->next = nullptr;

    // Chọn loại hóa đơn
    int loai_hd;
    while (true)
    {
        cout << "1. Hoa Don nhap\n2. Hoa Don xuat\nNhap loai hoa don: ";
        cin >> loai_hd;
        if (loai_hd == 1 || loai_hd == 2)
        {
            new_hd->data_hd.loai = (loai_hd == 1) ? 'N' : 'X';
            break;
        }
        else
        {
            cout << "Loai hoa don khong hop le! Vui long nhap lai.\n";
        }
    }

    // Nhập thông tin cho hóa đơn
    cout << "Nhap so hoa don: ";
    cin >> new_hd->data_hd.SoHD;
    cout << "Nhap ngay lap hoa don (dd mm yyyy): ";
    cin >> new_hd->data_hd.day >> new_hd->data_hd.month >> new_hd->data_hd.year;

    // Thêm hóa đơn mới vào danh sách hóa đơn của nhân viên
    if (nv->firstDSHD == nullptr)
    {
        nv->firstDSHD = new_hd;
    }
    else
    {
        ptr_DSHD temp = nv->firstDSHD;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = new_hd;
    }

    cout << "Lap hoa don thanh cong! Hoa don moi da duoc them vao danh sach." << endl;

    // Bắt đầu thêm chi tiết hóa đơn
    while (true)
    {
        ptr_DSCTHD new_cthd = new dsChiTietHoaDon;
        treeVatTu temp = nullptr;
        while (temp == nullptr)
        {
            cout << "Nhap ma vat tu: ";
            cin >> new_cthd->data_cthd.MAVT;
            temp = search(root, new_cthd->data_cthd.MAVT);
        }
        cout << "Nhap so luong: ";
        cin >> new_cthd->data_cthd.soLuong;
        cout << "Nhap don gia: ";
        cin >> new_cthd->data_cthd.donGia;
        cout << "Nhap VAT (%): ";
        cin >> new_cthd->data_cthd.VAT;

        bool checkMAVT;
        if (temp == nullptr) // Không tìm thấy mã vật tư
            checkMAVT = false;
        else // Tìm thấy mã vật tư
            checkMAVT = true;

        if (checkMAVT == true)
        {
            if (nv->firstDSHD->data_hd.loai == 'N') // Nếu hóa đơn là hóa đơn nhập
            {
                temp->data_vt.soLuongTon += new_cthd->data_cthd.soLuong;
            }
            else if (nv->firstDSHD->data_hd.loai == 'X') // Nếu hóa đơn là hóa đơn xuất
            {
                if (temp->data_vt.soLuongTon < new_cthd->data_cthd.soLuong) // Số lượng vật tư lấy ra nhiều hơn kho hiện cos
                {
                    cout << "Loi: Vui long nhap them vat tu vao kho!" << endl;
                }
                else
                {
                    temp->data_vt.soLuongTon -= new_cthd->data_cthd.soLuong;
                }
            }
        }
        // Thêm chi tiết hóa đơn vào danh sách chi tiết của hóa đơn hiện tại
        if (new_hd->data_hd.firstCTHD == nullptr)
        {
            new_hd->data_hd.firstCTHD = new_cthd;
            new_cthd->next = nullptr;
        }
        else
        {
            ptr_DSCTHD temp_cthd = new_hd->data_hd.firstCTHD;
            while (temp_cthd->next != nullptr)
            {
                temp_cthd = temp_cthd->next;
            }
            temp_cthd->next = new_cthd;
            new_cthd->next = nullptr;
        }
        // Kiểm tra tiếp tục thêm chi tiết hóa đơn
        char choice;
        cout << "Ban co muon them chi tiet hoa don khac? (y/n): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y')
        {
            break;
        }
    }
}
void inHoaDon(dsNhanVien &ds_nv)
{
    string so_hd;
    cout << "Nhap so hoa don: ";
    cin >> so_hd;

    // Tìm hóa đơn với số hóa đơn đã nhập
    nhanVien *nv = nullptr;
    ptr_DSHD found_hd = nullptr;

    for (int i = 0; i < ds_nv.CountNV; ++i)
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
        cout << "Khong tim thay hoa don voi so hoa don " << so_hd << "!" << endl;
        return;
    }

    // In thông tin hóa đơn
    cout << "\n=============================\n";
    cout << "So Hoa Don: " << found_hd->data_hd.SoHD << endl;
    cout << "Loai: " << (found_hd->data_hd.loai == 'N' ? "Nhap" : "Xuat") << endl;
    cout << "Ngay Lap: " << setw(2) << setfill('0') << found_hd->data_hd.day << "/"
         << setw(2) << setfill('0') << found_hd->data_hd.month << "/"
         << found_hd->data_hd.year << endl;
    cout << "Nhan vien lap: " << nv->HO << " " << nv->TEN << " (Ma NV: " << nv->MANV << ")" << endl;

    ptr_DSCTHD current_cthd = found_hd->data_hd.firstCTHD;
    cout << "\nChi Tiet Hoa Don:\n";
    // cout << setw(15) << left << "Ma Vat Tu" << setw(10) << "So Luong"
    //      << setw(15) << "Don Gia" << setw(10) << "VAT" << endl;

    while (current_cthd != nullptr)
    {
        cout << "Ma Vat Tu " << current_cthd->data_cthd.MAVT << endl;
        cout << "So Luong  " << current_cthd->data_cthd.soLuong << endl;
        cout << "Don Gia   " << current_cthd->data_cthd.donGia << endl;
        cout << "VAT       " << current_cthd->data_cthd.VAT << endl;
        current_cthd = current_cthd->next;
    }

    cout << "=============================\n";
}
