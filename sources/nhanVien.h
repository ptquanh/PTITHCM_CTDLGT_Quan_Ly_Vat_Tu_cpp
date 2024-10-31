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

void xoaNhanVien(dsNhanVien &list)
{
    if (nhanVienEmpty(list))
    {
        cout << "Danh sach nhan vien trong!" << endl;
        return;
    }

    string manv;
    cout << "Nhap ma nhan vien can xoa: ";
    getline(cin, manv);

    int pos = searchNhanVien(list, manv);
    if (pos == -1)
    {
        return;
    }

    delete list.nodes[pos];
    for (int i = pos; i < list.CountNV - 1; i++)
    {
        list.nodes[i] = list.nodes[i + 1];
    }
    list.CountNV--;
    cout << "Da xoa nhan vien thanh cong!" << endl;
}
void nhapNhanVien(dsNhanVien &list)
{
    if (list.CountNV >= MaxNhanVien)
    {
        cout << "So luong nhan vien da dat toi da!" << endl;
        return;
    }

    nhanVien *nv = new nhanVien;
    string value;
    bool check;

    do
    {
        cout << "Nhap ma nhan vien (toi da 10 ky tu): ";
        getline(cin, value);
        check = checkThongTin("MANV", value, nv, list);
    } while (check);

    do
    {
        cout << "Nhap ho nhan vien: ";
        getline(cin, value);
        check = checkThongTin("HO", value, nv, list);
    } while (check);

    do
    {
        cout << "Nhap ten nhan vien: ";
        getline(cin, value);
        check = checkThongTin("TEN", value, nv, list);
    } while (check);

    do
    {
        cout << "Nhap gioi tinh (nam/nu): ";
        getline(cin, value);
        check = checkThongTin("PHAI", value, nv, list);
    } while (check);

    if (list.CountNV == 0)
    {
        list.nodes[list.CountNV] = nv;
    }
    else
    {
        chenNhanVien(list, nv);
    }
    list.CountNV++;
}

// Hàm sửa nhân viên
void suaNhanVien(dsNhanVien &list)
{
    if (nhanVienEmpty(list))
    {
        cout << "Danh sach nhan vien trong!" << endl;
        return;
    }

    string manv;
    cout << "Nhap ma nhan vien can sua: ";
    getline(cin, manv);

    int pos = searchNhanVien(list, manv);
    if (pos == -1)
    {
        return;
    }

    nhanVien *nv = list.nodes[pos];
    bool check;
    int choice;
    string value;

    do
    {
        cout << "\nChon thong tin can sua:" << endl;
        cout << "1. Ho nhan vien" << endl;
        cout << "2. Ten nhan vien" << endl;
        cout << "3. Gioi tinh" << endl;
        cout << "0. Thoat" << endl;
        cout << "Lua chon cua ban: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            do
            {
                cout << "Nhap ho nhan vien moi: ";
                getline(cin, value);
                check = checkThongTin("HO", value, nv, list);
            } while (check);
            break;

        case 2:
        {
            do
            {
                cout << "Nhap ten nhan vien moi: ";
                getline(cin, value);
                check = checkThongTin("TEN", value, nv, list);
            } while (check);

            // Sắp xếp lại sau khi sửa tên
            nhanVien *temp = list.nodes[pos];
            for (int i = pos; i < list.CountNV - 1; i++)
            {
                list.nodes[i] = list.nodes[i + 1];
            }
            list.CountNV--;
            chenNhanVien(list, temp);
            list.CountNV++;
            break;
        }

        case 3:
            do
            {
                cout << "Nhap gioi tinh moi (nam/nu): ";
                getline(cin, value);
                check = checkThongTin("PHAI", value, nv, list);
            } while (check);
            break;

        case 0:
            cout << "Da hoan tat chinh sua!" << endl;
            break;

        default:
            cout << "Lua chon khong hop le!" << endl;
        }
    } while (choice != 0);
}
void inNhanVien(dsNhanVien &list)
{
    if (nhanVienEmpty(list))
    {
        cout << "Danh sach nhan vien rong" << endl;
        return;
    }

    cout << "\n=== DANH SACH NHAN VIEN ===\n";
    for (int i = 0; i < list.CountNV; i++)
    {
        cout << "\nNhan vien " << i + 1 << ":\n";
        cout << "-------------------------\n";
        cout << "Ma nhan vien: " << list.nodes[i]->MANV << endl;
        cout << "Ho nhan vien: " << list.nodes[i]->HO << endl;
        cout << "Ten nhan vien: " << list.nodes[i]->TEN << endl;
        cout << "Gioi tinh: " << list.nodes[i]->PHAI << endl;
        cout << "-------------------------\n";
    }
    cout << "\nTong so nhan vien: " << list.CountNV << endl;
}

void xoaDSNV(dsNhanVien &list) //goi khi ket thuc
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

/*

void Write_CTHoaDon(ofstream &file, nodeChiTietHoaDon &cthd)
{
    file << cthd.MAVT << "|" << cthd.soLuong << "|" << cthd.donGia << "|" << cthd.VAT << endl;
    file << "End_ChiTietHoaDon" << endl;
}
void Write_HoaDon(ofstream &file, nodeHoaDon &hd)
{
    file << hd.SoHD << "|" << hd.loai << "|" << hd.day << "|" << hd.month << "|" << hd.year << endl;

    // Ghi danh sách chi tiết hóa đơn
    ptr_DSCTHD current = hd.firstCTHD;
    while (current != nullptr)
    {
        Write_CTHoaDon(file, current->data_cthd);
        current = current->next;
    }
    file << "End_HoaDon" << endl; // Đánh dấu kết thúc hóa đơn
}
void Write_NhanVien(ofstream &file, nhanVien &nv)
{
    file << nv.MANV << "|" << nv.HO << "|" << nv.TEN << "|" << nv.PHAI << endl;

    // Ghi danh sách hóa đơn của nhân viên
    ptr_DSHD current = nv.firstDSHD;
    while (current != nullptr)
    {
        // Write_HoaDon(file, current->data_hd);
        current = current->next;
    }
    file << "End_NhanVien" << endl; // Đánh dấu kết thúc nhân viên
}
void Write_dsNhanVien(dsNhanVien &dsNV)
{
    ofstream fileout;
    fileout.open(filePath_NV, ios_base::out);
    if (!fileout.is_open())
    {
        cerr << "Khong the mo file ghi!" << endl;
        return;
    }
    fileout << dsNV.CountNV << endl;
    for (int i = 0; i < dsNV.CountNV; ++i)
    {
        Write_NhanVien(fileout, *dsNV.nodes[i]);
    }
    fileout.close();
}
*/

// void Read_CTHoaDon(ifstream &file, nodeChiTietHoaDon &cthd)
// {
//     string line;

//     getline(file, cthd.MAVT, '|'); // Đọc mã vật tư cho đến ký tự "|"
//     getline(file, line, '|');      // Đọc và chuyển thành số nguyên cho `soLuong`
//     cthd.soLuong = stoi(line);

//     getline(file, line, '|'); // Đọc và chuyển thành số thực cho `donGia`
//     cthd.donGia = stof(line);

//     getline(file, line); // Đọc VAT
//     cthd.VAT = stof(line);

//     getline(file, line); // Đọc "End_ChiTietHoaDon"
// }
// void Read_HoaDon(ifstream &file, nodeHoaDon &hd)
// {
//     string line;

//     getline(file, hd.SoHD, '|'); // Đọc số hóa đơn đến ký tự "|"

//     getline(file, line, '|'); // Đọc loại hóa đơn dưới dạng chuỗi và lấy ký tự đầu
//     hd.loai = line[0];

//     getline(file, line, '|'); // Đọc ngày dưới dạng chuỗi và chuyển thành số nguyên
//     hd.day = stoi(line);

//     getline(file, line, '|'); // Đọc tháng dưới dạng chuỗi và chuyển thành số nguyên
//     hd.month = stoi(line);

//     getline(file, line); // Đọc năm dưới dạng chuỗi và chuyển thành số nguyên
//     hd.year = stoi(line);

//     // Đọc danh sách chi tiết hóa đơn
//     hd.firstCTHD = nullptr;
//     ptr_DSCTHD *tail = &hd.firstCTHD;

//     while (getline(file, line) && line != "End_HoaDon")
//     {
//         if (line == "End_ChiTietHoaDon")
//             continue; // Bỏ qua dòng "End_ChiTietHoaDon"

//         nodeChiTietHoaDon cthd;
//         // Sử dụng hàm trực tiếp mà không cần `istringstream`
//         cthd.MAVT = line;
//         Read_CTHoaDon(file, cthd);

//         *tail = new dsChiTietHoaDon{cthd, nullptr};
//         tail = &(*tail)->next;
//     }
// }
void Read_NhanVien(ifstream &file, nhanVien &nv)
{
    string line;

    getline(file, nv.MANV, '|'); // Đọc mã nhân viên
    getline(file, nv.HO, '|');   // Đọc họ
    getline(file, nv.TEN, '|');  // Đọc tên
    getline(file, nv.PHAI);      // Đọc phái (không có ký tự phân cách cuối)

    // Đọc danh sách hóa đơn của nhân viên
    nv.firstDSHD = nullptr;
    ptr_DSHD *tail = &nv.firstDSHD;

    while (getline(file, line) && line != "End_NhanVien")
    {
        if (line == "End_HoaDon")
            continue; // Bỏ qua dòng "End_HoaDon"

        nodeHoaDon hd;
        hd.SoHD = line;
        // Read_HoaDon(file, hd);

        *tail = new dsHoaDon{hd, nullptr};
        tail = &(*tail)->next;
    }
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

    // Đọc số lượng nhân viên
    string line;
    getline(filein, line);
    dsNV.CountNV = stoi(line);

    // Đọc thông tin từng nhân viên
    for (int i = 0; i < dsNV.CountNV; ++i)
    {
        dsNV.nodes[i] = new nhanVien;
        Read_NhanVien(filein, *dsNV.nodes[i]);
    }

    filein.close();
}

//======================HOA DON===================================
void lapHoaDon(dsNhanVien &ds_nv)
{
    string ma_nv;
    cout << "Nhap ma nhan vien lap hoa don: ";
    cin >> ma_nv;
    nhanVien *nv = nullptr;
    for (int i = 0; i < ds_nv.CountNV; ++i)
    {
        if (ds_nv.nodes[i]->MANV == ma_nv)
        {
            nv = ds_nv.nodes[i]; // Gán con trỏ nv đến nhân viên tìm được
            break;
        }
    }

    if (nv == nullptr)
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
        cout << "Nhap ma vat tu: ";
        cin >> new_cthd->data_cthd.MAVT;
        cout << "Nhap so luong: ";
        cin >> new_cthd->data_cthd.soLuong;
        cout << "Nhap don gia: ";
        cin >> new_cthd->data_cthd.donGia;
        cout << "Nhap VAT (%): ";
        cin >> new_cthd->data_cthd.VAT;

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
