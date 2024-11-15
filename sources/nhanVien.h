#pragma once
#include "vatTu.h"
#include "../screens/vatTuScreen.h"
#include "../screens/hoaDonScreen.h"
void drawTableUpdateChiTietHoaDon(int x, int y);
void clearTablePrintChiTietHoaDon(int x);
#define MAX_VATTU 1000

bool nhanVienEmpty(dsNhanVien &list)
{
    return list.countNV == 0;
}
bool isMANV(dsNhanVien &list, string maso)
{
    for (int i = 0; i < list.countNV; i++)
    {
        if (list.nodes[i]->MANV == maso)
        {
            return true;
        }
    }
    return false;
}

// bool checkThongTin(string type, string value, nhanVien *&nv, dsNhanVien &list)
// {
//     if (type == "MANV")
//     {
//         if (value.empty())
//         {
//             cout << "Loi: Ma nhan vien khong duoc rong!" << endl;
//             return true;
//         }

//         // Xóa khoảng trắng
//         string result;
//         for (const char c : value)
//         {
//             if (c != ' ')
//             {
//                 result += c;
//             }
//         }
//         value = result;

//         if (value.length() > 10)
//         {
//             cout << "Loi: Ma nhan vien khong duoc qua 10 ky tu!" << endl;
//             return true;
//         }

//         if (isMANV(list, value))
//         {
//             cout << "Loi: Ma nhan vien da ton tai!" << endl;
//             return true;
//         }

//         nv->MANV = value;
//     }
//     else if (type == "HO")
//     {
//         if (value.empty())
//         {
//             cout << "Loi: Ho nhan vien khong duoc rong!" << endl;
//             return true;
//         }

//         bool hasError;
//         value = normalizeString(value, hasError);
//         if (hasError)
//         {
//             return true;
//         }

//         nv->HO = value;
//     }
//     else if (type == "TEN")
//     {
//         if (value.empty())
//         {
//             cout << "Loi: Ten nhan vien khong duoc rong!" << endl;
//             return true;
//         }

//         bool hasError;
//         value = normalizeString(value, hasError);
//         if (hasError)
//         {
//             return true;
//         }

//         for (char c : value)
//         {
//             if (c == ' ')
//             {
//                 cout << "Loi: Ten nhan vien khong duoc chua khoang trang!" << endl;
//                 return true;
//             }
//         }

//         nv->TEN = value;
//     }
//     else if (type == "PHAI")
//     {
//         if (value.empty() || (value != "Nam" && value != "Nu"))
//         {
//             cout << "Loi: Gioi tinh khong hop le!" << endl;
//             return true;
//         }

//         nv->PHAI = value;
//     }

//     return false;
// }

int searchNhanVien(dsNhanVien &list, string manv)
{
    for (int i = 0; i < list.countNV; i++)
    {
        if (list.nodes[i]->MANV == manv)
        {
            return i;
        }
    }
    cout << "Khong tim thay nhan vien!" << endl;
    return -1;
}
int TimViTriChen(dsNhanVien &list, nhanVien *nhanvienmoi)
{
    int low = 0;                 // Vị trí đầu danh sách
    int high = list.countNV - 1; // Vị trí cuối danh sách
    while (low <= high)
    {
        int mid = (low + high) / 2;                  // Tìm trung điểm
        if (nhanvienmoi->TEN < list.nodes[mid]->TEN) // Nếu vị trí cần chèn nhỏ hơn trung điểm
        {
            high = mid - 1;
        }
        else if (nhanvienmoi->TEN == list.nodes[mid]->TEN) // Nếu đã tìm ra khoảng chèn;
        {
            if (nhanvienmoi->HO < list.nodes[mid]->HO) // Nếu vị trí chèn lệch phải
                high = mid - 1;
            else if (nhanvienmoi->HO > list.nodes[mid]->HO) // Nếu vị trí chèn lệch trái
                low = mid + 1;
        }
        else // Nếu vị trí cần chèn lớn hơn trung điểm
        {
            low = mid + 1;
        }
    }
    return low; // Vị trí cần chèn
}

void chenNhanVien(dsNhanVien &list, nhanVien *nhanvienmoi)
{
    if (list.countNV >= MaxNhanVien)
    {
        cout << "Loi: So luong nhan vien da dat toi da. Khong the them nhan vien moi!" << endl;
        return;
    }

    // int pos = TimViTriChen(list, nhanvienmoi);
    int pos = 0;
    while (pos < list.countNV && (nhanvienmoi->TEN > list.nodes[pos]->TEN ||
                                  (nhanvienmoi->TEN == list.nodes[pos]->TEN && nhanvienmoi->HO >= list.nodes[pos]->HO)))
    {
        pos++;
    }
    for (int i = list.countNV; i > pos; i--)
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
        case F10:
            delete list.nodes[pos];
            for (int i = pos; i < list.countNV - 1; i++)
            {
                list.nodes[i] = list.nodes[i + 1];
            }
            list.countNV--;
            isSaved = true;
            return;
        }
    }
}

void nhapNhanVien(dsNhanVien &list, int x, int y)
{
    if (list.countNV >= MaxNhanVien)
    {
        string errorMessage = "So luong nhan vien da dat toi da!";
        drawTableErrors(errorMessage, true);
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
            result = inputString(x + 87, y + 4, input.MANV, 10, "Ma nhan vien", moveNext, true);
            if (result == "ESC")
                goto escButton;
            if (result == "F10")
                goto saveButton;
            tempInput = normalizeString(result, hasError);
            if (hasError)
            {
                errorMessage = "Ma nhan vien chua ky tu khong hop le";
                drawTableErrors(errorMessage, true);
                continue;
            }
            if (searchNhanVien(list, tempInput) != -1)
            {
                errorMessage = "Ma nhan vien da ton tai";
                drawTableErrors(errorMessage, true);
                continue;
            }
            for (char &c : tempInput)
            {
                c = std::toupper(c);
            }
            drawTableErrors("", true);
            input.MANV = tempInput;
            formatInputNV(input.MANV, input.HO, input.TEN, input.PHAI);
            break;
        }
        case 1:
        {
            result = inputString(x + 87, y + 6, input.HO, 20, "Ho nhan vien", moveNext, true);
            if (result == "ESC")
                goto escButton;
            if (result == "F10")
                goto saveButton;
            tempInput = normalizeString(result, hasError);
            if (hasError)
            {
                errorMessage = "Ho nhan vien chua ky tu khong hop le";
                drawTableErrors(errorMessage, true);
                continue;
            }
            drawTableErrors("", true);
            input.HO = tempInput;
            formatInputNV(input.MANV, input.HO, input.TEN, input.PHAI);
            break;
        }
        case 2:
        {
            result = inputString(x + 87, y + 8, input.TEN, 10, "Ten nhan vien", moveNext, true);
            if (result == "ESC")
                goto escButton;
            if (result == "F10")
                goto saveButton;
            tempInput = normalizeString(result, hasError);
            if (hasError)
            {
                errorMessage = "Ten nhan vien chua ky tu khong hop le";
                drawTableErrors(errorMessage, true);
                continue;
            }
            drawTableErrors("", true);
            input.TEN = tempInput;
            formatInputNV(input.MANV, input.HO, input.TEN, input.PHAI);
            break;
        }
        case 3:
        {
            result = inputString(x + 87, y + 10, input.PHAI, 3, "Phai (Nam/Nu)", moveNext, true);
            if (result == "ESC")
                goto escButton;
            if (result == "F10")
                goto saveButton;
            tempInput = normalizeString(result, hasError);
            if (hasError || (tempInput != "Nam" && tempInput != "Nu"))
            {
                errorMessage = "Gioi tinh khong hop le (Nam/Nu)";
                drawTableErrors(errorMessage, true);
                continue;
            }
            drawTableErrors("", true);
            input.PHAI = tempInput;
            formatInputNV(input.MANV, input.HO, input.TEN, input.PHAI);
            break;
        }
        escButton:
        {
            ShowCur(false);
            errorMessage = "Dang thoat chuong trinh...";
            drawTableErrors(errorMessage, true);
            Sleep(1500);
            drawTableErrors("", true);
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
                if (list.countNV == 0)
                {
                    list.nodes[list.countNV] = nv;
                }
                else
                {
                    chenNhanVien(list, nv);
                }
                list.countNV++;

                errorMessage = "Them nhan vien thanh cong";
                drawTableErrors(errorMessage, true);
                Sleep(1500);
                drawTableErrors("", true);
                fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                return;
            }
            else
            {
                errorMessage = "Thieu thong tin. Chua them nhan vien";
                drawTableErrors(errorMessage, true);
                Sleep(1500);
                drawTableErrors("", true);
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
        drawTableErrors(errorMessage, true);
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
        drawTableErrors(errorMessage, true);
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
            result = inputString(x + 87, y + 6, input.HO, 20, "Ho nhan vien", moveNext, true);
            if (result == "ESC")
                goto escButton;
            if (result == "F10")
                goto saveButton;
            tempInput = normalizeString(result, hasError);
            if (hasError)
            {
                errorMessage = "Ho nhan vien chua ky tu khong hop le";
                drawTableErrors(errorMessage, true);
                continue;
            }
            drawTableErrors("", true);
            input.HO = tempInput;
            formatInputNV(input.MANV, input.HO, input.TEN, input.PHAI);
            break;
        }
        case 2:
        {
            result = inputString(x + 87, y + 8, input.TEN, 10, "Ten nhan vien", moveNext, true);
            if (result == "ESC")
                goto escButton;
            if (result == "F10")
                goto saveButton;
            tempInput = normalizeString(result, hasError);
            if (hasError)
            {
                errorMessage = "Ten nhan vien chua ky tu khong hop le";
                drawTableErrors(errorMessage, true);
                continue;
            }
            drawTableErrors("", true);
            input.TEN = tempInput;
            formatInputNV(input.MANV, input.HO, input.TEN, input.PHAI);
            break;
        }
        case 3:
        {
            result = inputString(x + 87, y + 10, input.PHAI, 3, "Phai (Nam/Nu)", moveNext, true);
            if (result == "ESC")
                goto escButton;
            if (result == "F10")
                goto saveButton;
            tempInput = normalizeString(result, hasError);
            if (hasError || (tempInput != "Nam" && tempInput != "Nu"))
            {
                errorMessage = "Gioi tinh khong hop le (Nam/Nu)!";
                drawTableErrors(errorMessage, true);
                continue;
            }
            drawTableErrors("", true);
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
                    for (int i = pos; i < list.countNV - 1; i++)
                    {
                        list.nodes[i] = list.nodes[i + 1];
                    }
                    list.countNV--;

                    // Chèn lại vào vị trí mới theo thứ tự
                    chenNhanVien(list, currentNode);
                    list.countNV++;
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

    for (int i = 0; i < list.countNV; i++)
    {
        delete list.nodes[i];
        list.nodes[i] = NULL;
    }
    list.countNV = 0;
}

void Write_CTHoaDon(ofstream &file, nodeChiTietHoaDon &cthd)
{
    file << "+" << cthd.MAVT << "|" << cthd.soLuong << "|" << cthd.VAT << "|" << cthd.donGia;
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
            file << "\n";
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

    for (int i = 0; i < dsNV.countNV; ++i)
    {
        Write_NhanVien(fileout, *dsNV.nodes[i]);
    }
    fileout.close();
    xoaDSNV(dsNV);
}

void readFile_dsNhanVien(dsNhanVien &dsNV, bool &isOpened)
{
    bool hasError;
    ifstream filein;
    filein.open(filePath_NV, ios_base::in);
    if (!filein.is_open())
    {
        isOpened = false;
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
            for (char &c : tempNodes[tempCount]->MANV)
            {
                c = std::toupper(c);
            }
            getline(ss, tempNodes[tempCount]->HO, '|');
            tempNodes[tempCount]->HO = normalizeString(tempNodes[tempCount]->HO, hasError);
            getline(ss, tempNodes[tempCount]->TEN, '|');
            tempNodes[tempCount]->TEN = normalizeString(tempNodes[tempCount]->TEN, hasError);
            getline(ss, tempNodes[tempCount]->PHAI);
            tempNodes[tempCount]->PHAI = normalizeString(tempNodes[tempCount]->PHAI, hasError);
            formatInputNV(tempNodes[tempCount]->MANV, tempNodes[tempCount]->HO, tempNodes[tempCount]->TEN, tempNodes[tempCount]->PHAI);
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
            for (char &c : hd.SoHD)
            {
                c = std::toupper(c);
            }
            string temp;
            getline(ss, temp, '|');
            string day = temp;
            getline(ss, temp, '|');
            string month = temp;
            getline(ss, temp, '|');
            string year = temp;
            getline(ss, temp);
            hd.loai = temp[0];
            hd.loai = normalizeString(hd.loai, hasError);
            formatInputHD(hd.SoHD, day, month, year, hd.loai);
            hd.day = stoi(day);
            hd.month = stoi(month);
            hd.year = stoi(year);
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
            stringstream ss(line.substr(1));

            getline(ss, cthd.MAVT, '|');
            for (char &c : cthd.MAVT)
            {
                c = std::toupper(c);
            }
            string line;
            getline(ss, line, '|');
            string soLuong = line;
            getline(ss, line, '|');
            string VAT = line;
            getline(ss, line);
            string donGia = line;
            formatInputCTHD(cthd.MAVT, soLuong, donGia, VAT);
            cthd.soLuong = stoi(soLuong);
            cthd.donGia = stof(donGia);
            cthd.VAT = stof(VAT);
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
    dsNV.countNV = 0;

    // Chèn từng nhân viên vào danh sách chính theo thứ tự
    for (int i = 0; i < tempCount; i++)
    {
        if (dsNV.countNV >= MaxNhanVien)
        {
            cout << "Danh sach nhan vien da day!" << endl;
            break;
        }
        chenNhanVien(dsNV, tempNodes[i]);
        dsNV.countNV++;
    }
}
// ==============================================
void inDanhSachNhanVien(dsNhanVien &list, int pageNumber, int selectedRow, int x, string &errorMessage)
{
    int n = list.countNV;
    if (n == 0)
    {
        errorMessage = "Khong co du lieu vat tu";
        drawTableErrors(errorMessage, true);
        return;
    }
    int startIndex = (pageNumber - 1) * ROWS;
    int endIndex = min(startIndex + ROWS, n);
    int currentRow = 5;
    for (int i = startIndex; i < endIndex; i++)
    {
        gotoxy(x + 3, currentRow);
        if (selectedRow == -1)
            cout << list.nodes[i]->MANV;
        else if (i - startIndex == selectedRow)
        {
            Highlight(LIGHTBLUE);
            cout << list.nodes[i]->MANV;
            setColorByRequest(LIGHTGRAY, BLACK);
        }
        else
        {
            cout << list.nodes[i]->MANV;
        }
        gotoxy(x + 18, currentRow);
        cout << list.nodes[i]->HO;
        gotoxy(x + 43, currentRow);
        cout << list.nodes[i]->TEN;
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
int countSearchResults(dsNhanVien &ds, const string &kyTu)
{
    int count = 0;
    for (int i = 0; i < ds.countNV; i++)
    {
        if (hasCharacter(kyTu, ds.nodes[i]->HO + " " + ds.nodes[i]->TEN))
        {
            count++;
        }
    }
    return count;
}

// Hàm lưu kết quả tìm kiếm vào mảng
void storeSearchResults(dsNhanVien &ds, const string &kyTu, nhanVien *results[], int &index)
{
    index = 0;
    for (int i = 0; i < ds.countNV; i++)
    {
        if (hasCharacter(kyTu, ds.nodes[i]->HO + " " + ds.nodes[i]->TEN))
        {
            results[index++] = ds.nodes[i];
        }
    }
}
void displaySearchResults(nhanVien *results[], int n, int pageNumber, int selectedRow, int x, const string &searchStr)
{
    bool hasError;
    setColorByRequest(LIGHTGRAY, BLACK);
    int currentRow = 5;
    int startIndex = (pageNumber - 1) * ROWS;
    int endIndex = min(startIndex + ROWS, n);

    for (int i = startIndex; i < endIndex; i++)
    {
        gotoxy(x + 3, currentRow);
        if (selectedRow == -1)
            cout << results[i]->MANV;
        else if (i - startIndex == selectedRow)
        {
            Highlight(LIGHTBLUE);
            cout << results[i]->MANV;
            setColorByRequest(LIGHTGRAY, BLACK);
        }
        else
        {
            cout << results[i]->MANV;
        }

        setColorByRequest(LIGHTGRAY, BLACK);
        gotoxy(x + 18, currentRow);
        string hoTen = results[i]->HO + " " + results[i]->TEN;
        string normalizedSearch = normalizeString(searchStr, hasError);
        if (!hasError)
        {
            printHighlightedText(hoTen, normalizedSearch);
        }
        else
        {
            cout << hoTen;
        }

        gotoxy(x + 43, currentRow);
        cout << results[i]->PHAI;
        currentRow++;
    }

    int totalPages = ceil((float)n / ROWS);
    gotoxy(52, 26);
    cout << "<- Trang " << pageNumber << "/" << totalPages << " ->";
    setColorByRequest(LIGHTGRAY, BLACK);
}
void timKiemTenNhanVien(dsNhanVien &ds, int x, int y, nhanVien *&selectedResult, bool &isESC)
{
    static string searchHistory[10];
    static int historyCount = 0;
    static int historyIndex = -1;
    static string searchStr = "";
    string currentInput = searchStr;
    int cursorPos = currentInput.length();
    bool hasError;
    bool isSearching = true;
    int selectedRow = -1;
    bool isViewingResults = false;
    nhanVien **results = new nhanVien *[ds.countNV];
    int resultCount = 0;
    int currentPage = 1;

    while (isSearching)
    {
        int totalPages = ceil((float)resultCount / ROWS);
        int startIndex = (currentPage - 1) * ROWS;
        int itemsOnPage = min(ROWS, resultCount - startIndex);

        ShowCur(true);
        setColorByRequest(BLACK, WHITE);
        gotoxy(x + 88, y + 4);
        cout << string(20, ' ');
        gotoxy(x + 88, y + 4);
        cout << currentInput;
        gotoxy(x + 88 + cursorPos, y + 4);

        int key = _getch();
        if (key == 224 || key == 0)
        {
            key = _getch();
            switch (key)
            {
            case LEFT:
                if (!isViewingResults && cursorPos > 0)
                    cursorPos--;
                else if (isViewingResults && currentPage > 1)
                {
                    currentPage--;
                    selectedRow = 0;
                    clearTablePrint(x);
                }
                break;

            case RIGHT:
                if (!isViewingResults && cursorPos < currentInput.length())
                    cursorPos++;
                else if (isViewingResults && currentPage < totalPages)
                {
                    currentPage++;
                    selectedRow = 0;
                    clearTablePrint(x);
                }
                break;

            case UP:
                if (isViewingResults && resultCount > 0)
                {
                    if (selectedRow > 0)
                        selectedRow--;
                    else if (selectedRow <= 0)
                        selectedRow = itemsOnPage - 1;
                }
                else if (!isViewingResults && historyCount > 0)
                {
                    if (historyIndex < historyCount - 1)
                    {
                        historyIndex++;
                        currentInput = searchHistory[historyIndex];
                        cursorPos = currentInput.length();
                        searchStr = currentInput;
                    }
                }
                break;

            case DOWN:
                if (isViewingResults && resultCount > 0)
                {
                    if (selectedRow < itemsOnPage - 1)
                        selectedRow++;
                    else if (selectedRow >= itemsOnPage - 1)
                        selectedRow = 0;
                }
                else if (!isViewingResults && historyCount > 0)
                {
                    if (historyIndex > 0)
                    {
                        historyIndex--;
                        currentInput = searchHistory[historyIndex];
                        cursorPos = currentInput.length();
                        searchStr = currentInput;
                    }
                    else if (historyIndex == 0)
                    {
                        historyIndex = -1;
                        currentInput = "";
                        cursorPos = 0;
                        searchStr = "";
                    }
                }
                break;

            case HOME:
                if (!isViewingResults)
                    cursorPos = 0;
                break;

            case END:
                if (!isViewingResults)
                    cursorPos = currentInput.length();
                break;

            case DEL:
                if (!isViewingResults && cursorPos < currentInput.length())
                {
                    currentInput.erase(cursorPos, 1);
                    searchStr = currentInput;
                }
                break;
            }

            if (isViewingResults)
            {
                displaySearchResults(results, resultCount, currentPage, selectedRow, x, currentInput);
            }
            continue;
        }

        switch (key)
        {
        case ENTER:
            if (isViewingResults && resultCount > 0)
            {
                int actualIndex = (currentPage - 1) * ROWS + selectedRow;
                if (actualIndex < resultCount)
                {
                    selectedResult = results[actualIndex];
                    delete[] results;
                    return;
                }
            }
            else if (!currentInput.empty())
            {
                bool isDuplicate = false;
                selectedRow = 0;
                for (int i = 0; i < historyCount; i++)
                {
                    if (searchHistory[i] == currentInput)
                    {
                        isDuplicate = true;
                        break;
                    }
                }

                if (!isDuplicate)
                {
                    for (int i = historyCount; i > 0; i--)
                    {
                        if (i < 10)
                        {
                            searchHistory[i] = searchHistory[i - 1];
                        }
                    }
                    searchHistory[0] = currentInput;
                    if (historyCount < 10)
                        historyCount++;
                }
                historyIndex = -1;
                isViewingResults = true;
            }
            break;

        case ESC:
            if (isViewingResults)
            {
                isViewingResults = false;
                selectedRow = -1;
                ShowCur(false);
                drawTableErrors("Dang thoat che do xem...", true);
                Sleep(1500);
                drawTableErrors("", true);
                ShowCur(true);
            }
            else
            {
                delete[] results;
                isESC = true;
                return;
            }
            break;

        case BACKSPACE:
            if (!isViewingResults && cursorPos > 0)
            {
                currentInput.erase(cursorPos - 1, 1);
                cursorPos--;
                searchStr = currentInput;
            }
            break;

        case TAB:
            if (resultCount > 0)
            {
                isViewingResults = !isViewingResults;
                if (!isViewingResults)
                    selectedRow = 0;
            }
            break;

        default:
            if (!isViewingResults && currentInput.length() < 20 && isValidChar(key))
            {
                if (cursorPos == currentInput.length())
                {
                    currentInput += (char)key;
                }
                else
                {
                    currentInput.insert(cursorPos, 1, (char)key);
                }
                cursorPos++;
                searchStr = currentInput;
            }
        }

        clearTablePrint(x);

        string tempInput = normalizeString(searchStr, hasError);
        if (hasError)
        {
            drawTableErrors("Du lieu nhap khong hop le", true);
            continue;
        }
        drawTableErrors("", true);

        if (!searchStr.empty())
        {
            resultCount = countSearchResults(ds, tempInput);

            if (resultCount == 0)
            {
                drawTableErrors("Khong tim thay '" + searchStr + "'", true);
                continue;
            }

            storeSearchResults(ds, tempInput, results, resultCount);
            // Có thể thêm hàm sắp xếp ở đây nếu cần
            displaySearchResults(results, resultCount, currentPage, selectedRow, x, currentInput);
        }
    }
    delete[] results;
}
//======================HOA DON===================================
nhanVien *layMANV(dsNhanVien &ds_nv, treeVatTu &root, string MANV, int x, int y, bool &isESC, bool &isSaved)
{
    for (int i = 0; i < ds_nv.countNV; ++i)
    {
        if (ds_nv.nodes[i]->MANV == MANV)
        {
            return ds_nv.nodes[i];
        }
    }
    return nullptr;
}

// int searchHoaDon(dsNhanVien &ds_nv, string so_hd, ptr_DSHD &found_hd)
// {
//     for (int i = 0; i < ds_nv.countNV; ++i)
//     {
//         if (ds_nv.nodes[i] != nullptr)
//         {
//             ptr_DSHD current_hd = ds_nv.nodes[i]->firstDSHD;
//             while (current_hd != nullptr)
//             {
//                 if (current_hd->data_hd.SoHD == so_hd)
//                 {
//                     found_hd = current_hd;
//                     return i; // Trả về chỉ số của nhân viên
//                 }
//                 current_hd = current_hd->next;
//             }
//         }
//     }

//     found_hd = nullptr;
//     return -1; // Không tìm thấy
// }

ptr_DSHD searchHoaDon(dsNhanVien &ds_nv, string soHD, ptr_DSHD &found_hd)
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
void lapHoaDon(dsNhanVien &ds_nv, treeVatTu &root, nhanVien *nv, ptr_DSHD &new_hd, int x, int y, bool &isESC, bool &isSaved)
{
    if (nv == nullptr)
    {
        cout << "Ma nhan vien khong ton tai!" << endl;
        return;
    }

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
    layNgayThangNam(input.day, input.month, input.year);
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
            if (numResult < 1000 || numResult > 9999)
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
            errorMessage = "Dang thoat chuong trinh...";
            drawTableErrors(errorMessage, false);
            Sleep(1500);
            drawTableErrors("", false);
            fillAreaColor(x + 76, y, 41, 17, LIGHTGRAY);

            return;
        saveButton:
            ShowCur(false);
            if (!moveNext && !input.SoHD.empty() && !input.loai.empty() && input.day != 0 && input.month != 0 && input.year != 0)
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
                return;
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

void nhapChiTietHoaDon(dsNhanVien &ds_nv, treeVatTu &root, nhanVien *nv, ptr_DSHD &hd, int x, int y, bool &isESC, bool &isSaved)
{
    if (hd == nullptr)
    {
        cout << "Hoa don khong ton tai!" << endl;
        return;
    }

    nodeChiTietHoaDon input;
    input.MAVT = "";
    input.soLuong = 0;
    input.donGia = 0;
    input.VAT = 0;
    string TENVT;
    string DVT;
    string errorMessage;
    int currentRow = 0;
    bool hasError;
    string result;
    double numResult;
    bool moveNext;
    string tempInput;
    string donGia;
    treeVatTu found_vt = nullptr;
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
                    Sleep(1500);
                    drawTableErrors("", false);
                    ShowCur(true);
                    numResult = inputNumber(x + 94, y + 6, input.soLuong, 10, "So luong", moveNext, false);
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
                    ShowCur(false);
                    drawTableErrors("", false);
                    input.soLuong = numResult;
                    drawTableErrors("Dang den trang tao vat tu...", false);
                    Sleep(1500);
                    drawTableErrors("", false);
                    fillAreaColor(x + 76, y, 41, 15, LIGHTGRAY);
                    drawTableAddVatTuInCTHD(x + 7, y);
                    nhapVatTu(root, x + 7, y, tempInput, input.soLuong, false, true);
                    treeVatTu node = search(root, tempInput);
                    SetColor(WHITE);
                    gotoxy(0, 0);
                    cout << node->data_vt.MAVT << " " << node->data_vt.TENVT;
                    fillAreaColor(x + 76, y, 41, 17, LIGHTGRAY);
                    drawTableUpdateChiTietHoaDon(x, y);
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
                TENVT = found_vt->data_vt.TENVT;
                DVT = found_vt->data_vt.DVT;
            }

            drawTableErrors("", false);
            input.MAVT = tempInput;
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
                if (hd->data_hd.loai == "N")
                {
                    if (vt != nullptr)
                    {
                        vt->data_vt.soLuongTon += input.soLuong;
                    }
                }
                else if (hd->data_hd.loai == "X")
                {
                    vt->data_vt.soLuongTon -= input.soLuong;
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
                errorMessage = "Thieu thong tin. Chua them chi tiet hoa don";
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
    }
}

// Hàm xóa chi tiết hóa đơn
void xoaChiTietHoaDon(dsNhanVien &ds_nv, treeVatTu &root, nhanVien *nv, ptr_DSHD &hd, string MAVT, int x, int y, bool &isESC, bool &isSaved)
{
    if (hd == nullptr || hd->data_hd.firstCTHD == nullptr)
    {
        cout << "Hoa don khong ton tai hoac khong co chi tiet!" << endl;
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
        cout << "Khong tim thay chi tiet hoa don voi ma vat tu nay!" << endl;
        return;
    }
    // string errorMessage;
    // int currentRow = 1; // Bắt đầu từ số lượng (không cho sửa mã vật tư)
    // bool hasError;
    // double numResult;
    // bool moveNext;
    char key;
    treeVatTu vt = search(root, MAVT);

    displayField(x + 94, y + 4, vt->data_vt.TENVT, false, 10);
    displayField(x + 94, y + 6, current->data_cthd.MAVT, false, 10);
    displayField(x + 94, y + 8, to_string(current->data_cthd.soLuong), false, 10);
    displayField(x + 94, y + 10, to_string(current->data_cthd.VAT), false, 3);
    displayField(x + 94, y + 12, to_string(current->data_cthd.donGia), false, 10);
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
        cout << "Hoa don khong ton tai hoac khong co chi tiet!" << endl;
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
        cout << "Khong tim thay chi tiet hoa don voi ma vat tu nay!" << endl;
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
        displayField(x + 94, y + 4, result->data_vt.TENVT, false, 10);
        displayField(x + 94, y + 6, input.MAVT, false, 10);
        displayField(x + 94, y + 8, input.soLuong > 0 ? to_string(input.soLuong) : "", currentRow == 1, 10);
        displayField(x + 94, y + 10, input.VAT > 0 ? to_string(input.VAT) : "", currentRow == 2, 3);
        displayField(x + 94, y + 12, input.donGia > 0 ? to_string(input.donGia) : "", currentRow == 3, 10);

        switch (currentRow)
        {
        case 1: // Sửa số lượng
            numResult = inputNumber(x + 94, y + 8, input.soLuong, 10, "So luong", moveNext, false);
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
            numResult = inputNumber(x + 94, y + 12, input.donGia, 10, "Don gia", moveNext, false);
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

// int searchHoaDon(dsNhanVien &ds_nv, string so_hd, ptr_DSHD &found_hd)
// {
//     for (int i = 0; i < ds_nv.countNV; ++i)
//     {
//         if (ds_nv.nodes[i] != nullptr)
//         {
//             ptr_DSHD current_hd = ds_nv.nodes[i]->firstDSHD;
//             while (current_hd != nullptr)
//             {
//                 if (current_hd->data_hd.SoHD == so_hd)
//                 {
//                     found_hd = current_hd;
//                     return i; // Trả về chỉ số của nhân viên
//                 }
//                 current_hd = current_hd->next;
//             }
//         }
//     }

//     found_hd = nullptr;
//     return -1; // Không tìm thấy
// }

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

void inChiTietHoaDon(dsNhanVien &ds_nv, treeVatTu &root, ptr_DSHD &found_hd, int pageNumber, int selectedRow, int &totalPages, int x, int y, string &errorMessage, bool &isESC, bool &isSaved, bool &isEmpty)
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
    if (current_cthd == nullptr)
    {
        isEmpty = true;
        return;
    }
    for (int i = 0; i < n && current_cthd != nullptr; i++)
    {
        arrCTHD[i].triGia = 0;
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
            arrCTHD[i].triGia = arrCTHD[i].soLuong * arrCTHD[i].donGia * (1 + (float)(arrCTHD[i].VAT) / 100);
        }
        current_cthd = current_cthd->next;
    }
    int startIndex = (pageNumber - 1) * HDROWS;
    int endIndex = min(startIndex + HDROWS, n);
    int currentRow = 12;
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
        cout << arrCTHD[i].triGia;
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
    isSaved = true;
}

void inHoaDon(dsNhanVien &ds_nv, treeVatTu &root, int pageNumber, int selectedRow, int &totalPages, int x, int y, string &errorMessage, bool &isESC, bool &isSaved, bool &isInputting)
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
            result = inputString(x + 95, y + 4, so_hd, 10, "So hoa don", moveNext, false);
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
    }
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
    float triGiaHD = tinhTriGiaHoaDon(found_hd->data_hd.firstCTHD);
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
    for (int i = 0; i < n && current_cthd != nullptr; i++)
    {
        arrCTHD[i].triGia = 0;
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
            arrCTHD[i].triGia += arrCTHD[i].soLuong * arrCTHD[i].donGia * (1 + (float)arrCTHD[i].VAT / 100);
        }
        current_cthd = current_cthd->next;
    }
    int startIndex = (pageNumber - 1) * HDROWS;
    int endIndex = min(startIndex + HDROWS, n);
    int currentRow = 12;
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
        cout << arrCTHD[i].triGia;
        currentRow++;
    }
    gotoxy(x + 18, y + 23);
    string triGia = formatMoney(triGiaHD);
    cout << triGia << " VND";
    totalPages = ceil((float)n / HDROWS);
    gotoxy(6, 26);
    cout << "TAB: Di chuyen den trang can tim";
    gotoxy(52, 26);
    cout << "<- Trang " << pageNumber << "/" << totalPages << " ->";
    delete[] arrCTHD;
    delete[] arrVT;
    if (isInputting)
    {
        isInputting = false;
        isSaved = true;
        return;
    }
}
//================THONG KE=======================
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

void inputTime(int &day1, int &month1, int &year1, int &day2, int &month2, int &year2)
{
    do
    {
        cout << "Nhap thoi gian bat dau (dd mm yy): ";
        cin >> day1 >> month1 >> year1;

        if (!isValidTime(day1, month1, year1))
        {
            cout << "Thoi gian khong hop le" << endl;
        }
    } while (!isValidTime(day1, month1, year1));

    do
    {
        cout << "Nhap thoi gian ket thuc (dd mm yy): ";
        cin >> day2 >> month2 >> year2;

        if (!isValidTime(day2, month2, year2))
        {
            cout << "Thoi gian khong hop le" << endl;
        }
        if (timeConflict(day1, month1, year1, day2, month2, year2))
        {
            cout << "Thoi gian khong hop le" << endl;
        }
    } while (!isValidTime(day2, month2, year2) || timeConflict(day1, month1, year1, day2, month2, year2));
}

void tinhToanDoanhThu(ptr_DSCTHD ct, doanhThuVatTu doanhThu[], int &countVatTu, string loai)
{
    while (ct != nullptr)
    {
        bool found = false;
        for (int j = 0; j < countVatTu; ++j)
        {
            if (doanhThu[j].MAVT == ct->data_cthd.MAVT)
            {
                if (loai == "X")
                {
                    doanhThu[j].doanhThu += ct->data_cthd.soLuong * ct->data_cthd.donGia * (1 + ct->data_cthd.VAT / 100);
                }
                else if (loai == "N")
                {
                    doanhThu[j].doanhThu -= ct->data_cthd.soLuong * ct->data_cthd.donGia * (1 + ct->data_cthd.VAT / 100);
                }
                found = true;
                break;
            }
        }
        if (!found)
        {
            doanhThu[countVatTu].MAVT = ct->data_cthd.MAVT;
            if (loai == "X")
            {
                doanhThu[countVatTu].doanhThu = ct->data_cthd.soLuong * ct->data_cthd.donGia * (1 + ct->data_cthd.VAT / 100);
            }
            else if (loai == "N")
            {
                doanhThu[countVatTu].doanhThu = -(ct->data_cthd.soLuong * ct->data_cthd.donGia) * (1 + ct->data_cthd.VAT / 100);
            }
            countVatTu++;
        }
        ct = ct->next;
    }
}

void layDoanhThu(dsNhanVien &dsnv, doanhThuVatTu doanhThu[], int &countVatTu, time_t start, time_t end)
{
    for (int i = 0; i < dsnv.countNV; ++i)
    {
        ptr_DSHD p = dsnv.nodes[i]->firstDSHD;
        while (p != nullptr)
        {
            time_t hdTime = to_time_t(p->data_hd.day, p->data_hd.month, p->data_hd.year);
            if (hdTime >= start && hdTime <= end)
            {
                tinhToanDoanhThu(p->data_hd.firstCTHD, doanhThu, countVatTu, p->data_hd.loai);
            }
            p = p->next;
        }
    }
}

void inTop10DTVT(dsNhanVien &dsnv)
{
    doanhThuVatTu doanhThu[MAX_VATTU];
    int countVatTu = 0;
    char key;
    int day1, month1, year1, day2, month2, year2;
    inputTime(day1, month1, year1, day2, month2, year2);
    time_t start = to_time_t(day1, month1, year1);
    time_t end = to_time_t(day2, month2, year2);

    layDoanhThu(dsnv, doanhThu, countVatTu, start, end);

    quickSortDoanhThu(doanhThu, 0, countVatTu - 1);

    cout << "Top 10 vat tu co doanh thu cao nhat tu " << day1 << "/" << month1 << "/" << year1
         << " den " << day2 << "/" << month2 << "/" << year2 << ":\n";
    for (int i = 0; i < 10 && i < countVatTu; ++i)
    {
        cout << doanhThu[i].MAVT << ": " << doanhThu[i].doanhThu << endl;
    }
    while (1)
    {
        key = getch();
        if (key == ESC)
            return;
    }
}

void inThongKeHoaDon(dsNhanVien &dsnv)
{
    int day1, month1, year1, day2, month2, year2;
    char key;
    inputTime(day1, month1, year1, day2, month2, year2);
    time_t start = to_time_t(day1, month1, year1);
    time_t end = to_time_t(day2, month2, year2);

    cout << "Danh sach cac hoa don tu " << day1 << "/" << month1 << "/" << year1
         << " den " << day2 << "/" << month2 << "/" << year2 << ":\n";

    for (int i = 0; i < dsnv.countNV; ++i)
    {
        ptr_DSHD p = dsnv.nodes[i]->firstDSHD;
        while (p != nullptr)
        {
            time_t invoiceTime = to_time_t(p->data_hd.day, p->data_hd.month, p->data_hd.year);
            if (invoiceTime >= start && invoiceTime <= end)
            {
                float triGiaHoaDon = tinhTriGiaHoaDon(p->data_hd.firstCTHD);
                cout << "SoHD: " << p->data_hd.SoHD
                     << ", Ngay lap: " << p->data_hd.day << "/" << p->data_hd.month << "/" << p->data_hd.year
                     << ", Loai: " << p->data_hd.loai
                     << ", Ho ten NV: " << dsnv.nodes[i]->HO << " " << dsnv.nodes[i]->TEN
                     << ", Tri gia: " << triGiaHoaDon << "\n";
            }
            p = p->next;
        }
    }
    while (1)
    {
        key = getch();
        if (key == ESC)
            return;
    }
}

void inThuDoanhThuThang(int year, float doanhThuThang[12])
{
    cout << "BANG THONG KE DOANH THU NAM " << year << "\n";
    cout << "THANG\tDOANH THU\n";
    for (int i = 0; i < 12; ++i)
    {
        cout << (i + 1) << "\t" << doanhThuThang[i] << "\n";
    }
}

void inDoanhThuNam(dsNhanVien danhSach)
{
    int year;
    char key;
    cin >> year;
    float doanhThuThang[12] = {0};
    for (int i = 0; i < danhSach.countNV; i++)
    {
        ptr_DSHD hoaDon = danhSach.nodes[i]->firstDSHD;
        while (hoaDon != nullptr)
        {
            if (hoaDon->data_hd.year == year)
            {
                float triGiaHoaDon = tinhTriGiaHoaDon(hoaDon->data_hd.firstCTHD);
                if (hoaDon->data_hd.loai == "N")
                {
                    doanhThuThang[hoaDon->data_hd.month - 1] -= triGiaHoaDon;
                }
                else if (hoaDon->data_hd.loai == "X")
                {
                    doanhThuThang[hoaDon->data_hd.month - 1] += triGiaHoaDon;
                }
            }
            hoaDon = hoaDon->next;
        }
    }
    inThuDoanhThuThang(year, doanhThuThang);
    while (1)
    {
        key = getch();
        if (key == ESC)
            return;
    }
}