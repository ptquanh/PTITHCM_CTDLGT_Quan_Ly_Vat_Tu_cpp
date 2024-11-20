#pragma once
#include "vatTu.h"

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
//             cout << "Loi: Ma nhan vien khong duoc rong" << endl;
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
//             cout << "Loi: Ma nhan vien khong duoc qua 10 ky tu" << endl;
//             return true;
//         }

//         if (isMANV(list, value))
//         {
//             cout << "Loi: Ma nhan vien da ton tai" << endl;
//             return true;
//         }

//         nv->MANV = value;
//     }
//     else if (type == "HO")
//     {
//         if (value.empty())
//         {
//             cout << "Loi: Ho nhan vien khong duoc rong" << endl;
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
//             cout << "Loi: Ten nhan vien khong duoc rong" << endl;
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
//                 cout << "Loi: Ten nhan vien khong duoc chua khoang trang" << endl;
//                 return true;
//             }
//         }

//         nv->TEN = value;
//     }
//     else if (type == "PHAI")
//     {
//         if (value.empty() || (value != "Nam" && value != "Nu"))
//         {
//             cout << "Loi: Gioi tinh khong hop le" << endl;
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
            else // Nếu tên trùng và họ trùng
                return mid;
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
        cout << "So luong nhan vien da dat toi da" << endl;
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
        cout << "Danh sach nhan vien rong";
        return;
    }
    int pos = searchNhanVien(list, MANV);
    if (pos == -1)
    {
        cout << "Khong tim thay ma nhan vien " << MANV << endl;
        return;
    }
    if (list.nodes[pos]->firstDSHD != nullptr)
    {
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
        string errorMessage = "So luong nhan vien da dat toi da";
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
            for (char &c : tempInput)
            {
                c = std::toupper(c);
            }
            if (searchNhanVien(list, tempInput) != -1)
            {
                errorMessage = "Ma nhan vien da ton tai";
                drawTableErrors(errorMessage, true);
                continue;
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
        string errorMessage = "Danh sach nhan vien trong";
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
void deleteChiTietHoaDon(ptr_DSCTHD &first)
{
    while (first != nullptr) // xóa đi node chi tiết hóa đơn
    {
        ptr_DSCTHD temp = first;
        first = first->next;
        delete temp;
    }
}
void deleteHoaDon(ptr_DSHD &first)
{
    while (first != nullptr)
    {

        deleteChiTietHoaDon(first->data_hd.firstCTHD); // xóa đi node chi tiết hóa đơn của hóa đơn

        ptr_DSHD temp = first;
        first = first->next;
        delete temp;
    }
}
void deleteDanhsachNhanVien(dsNhanVien &dsNV)
{
    if (nhanVienEmpty(dsNV) == true)
        return;
    for (int i = 0; i < dsNV.countNV; ++i)
    {
        deleteHoaDon(dsNV.nodes[i]->firstDSHD); // Xóa đi danh sách hóa đơn của nhân viên đó
        delete dsNV.nodes[i];                   // Xóa nhân viên
    }
    dsNV.countNV = 0; // Đặt lại số lượng nhân viên của danh sách
}

// Thoát khẩn cấp bằng nút "X" hay close trên terminal
dsNhanVien *globalDsNVPtr = nullptr; // biến tĩnh

void signalHandler(int signum)
{
    if (signum == SIGINT || signum == SIGTERM)
    {
        system("cls");
        cout << "Interrupt signal (" << signum << ") received. Cleaning up resources..." << endl;

        if (globalDsNVPtr != nullptr)
        {
            deleteDanhsachNhanVien(*globalDsNVPtr);
        }

        exit(signum);
    }
}

void setupSignalHandler(dsNhanVien *dsNVPtr)
{
    globalDsNVPtr = dsNVPtr;
    signal(SIGINT, signalHandler);  // Handle Ctrl+C
    signal(SIGTERM, signalHandler); // Handle termination request
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
    int n = dsNV.countNV;
    if (n == 0)
    {
        drawTableErrors("Khong co du lieu nhan vien", true);
        Sleep(1500);
        drawTableErrors("", true);
        return;
    }
    if (!fileout.is_open())
    {
        cerr << "Khong the mo file ghi" << endl;
        return;
    }

    for (int i = 0; i < dsNV.countNV; ++i)
    {
        Write_NhanVien(fileout, *dsNV.nodes[i]);
    }
    fileout.close();
    drawTableErrors("Luu nhan vien vao file thanh cong", true);
    Sleep(1500);
    drawTableErrors("", true);
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

    // Khởi tạo mảng tạm với nullptr
    for (int i = 0; i < MaxNhanVien; i++)
    {
        tempNodes[i] = nullptr;
    }

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
            cout << "Danh sach nhan vien da day" << endl;
            // Giải phóng những node chưa được chèn
            for (int j = i; j < tempCount; j++)
            {
                if (tempNodes[j] != nullptr)
                {
                    delete tempNodes[j];
                    tempNodes[j] = nullptr;
                }
            }
            break;
        }
        chenNhanVien(dsNV, tempNodes[i]);
        dsNV.countNV++;
        tempNodes[i] = nullptr; // Tránh double free vì node đã được chuyển sang dsNV
    }
}
// ==============================================
void inDanhSachNhanVien(dsNhanVien &list, int pageNumber, int selectedRow, int x, string &errorMessage)
{
    int n = list.countNV;
    if (n == 0)
    {
        errorMessage = "Khong co du lieu nhan vien";
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
        if (hasCharacter(kyTu, ds.nodes[i]->TEN))
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
        cout << results[i]->HO;
        gotoxy(x + 43, currentRow);
        string normalizedSearch = normalizeString(searchStr, hasError);
        if (!hasError)
        {
            printHighlightedText(results[i]->TEN, normalizedSearch);
        }
        else
        {
            cout << results[i]->TEN;
        }

        gotoxy(x + 54, currentRow);
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