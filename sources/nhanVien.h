#pragma once
#include "../libraries/khaibao.h"
#include "vatTu.h"

bool NhanVienEmpty(dsNhanVien list)
{
    if (list.CountNV != 0)
    {
        return false;
    }
    else
    {
        cout << "Danh sach nhan vien rong!" << endl;
        return true;
    }
}
bool NhanVienEmpty(dsNhanVien list, int x, int y)
{
    if (list.CountNV != 0)
    {
        return false;
    }
    else
    {
        gotoxy(x, y);
        cout << "Danh sach nhan vien rong!";
        return true;
    }
}

bool CheckMANV(string manv, nhanVien *&nv, dsNhanVien list)
{
    if (manv.size() == 0)
        return false;
    if (isMANV(list, manv))
        cout << "Loi:Ma da ton tai" << endl;

    //  Kiểm tra kí tự space và xóa đi khỏi MANV;
    string result;
    for (const char c : manv)
    {
        if (c != ' ')
            result += c;
    }
    manv = result;

    if (manv.size() > 10)
    {
        cout << "Loi ma nhan vien khong duoc qua 10 ki tu - " << manv.size() << " ki tu" << manv << endl;
        cout << "Lay 10 ki tu hoac nhap lai (1 hoac 0) ";
        int n;
        cin >> n;
        while (true)
        {
            if (n == 1)
            {
                manv.resize(10);
                return true;
            }
            if (n == 0)
                return false;
        }
    }

    nv->MANV = manv;
    return true;
}
bool CheckHO(string ho, nhanVien *&nv, dsNhanVien list)
{
    if (ho.size() == 0)
        return false;
    bool hasError;
    ho = normalizeString(ho, hasError);
    if (hasError)
        return false;
    nv->HO = ho;
    return true;
}
bool CheckTEN(string ten, nhanVien *&nv, dsNhanVien list)
{
    if (ten.size() == 0)
        return false;
    bool hasError;
    ten = normalizeString(ten, hasError);
    if (hasError)
        return false;
    for (char c : ten)
    {
        if (c = ' ')
        {
            cout << "Loi: Khong the co khoang trang trong ten" << endl;
            return false;
        }
    }

    nv->TEN = ten;
    return true;
}
bool CheckPHAI(string phai, nhanVien *&nv, dsNhanVien list)
{
    if (phai.size() == 0 || phai.size() != 1)
        return false;
    if (phai == "0" || phai == "1")
    {
        nv->PHAI = phai;
        return true;
    }
    else
    {
        cout << "Loi: Phai khong hop le" << endl;
        return 0;
    }
}

int SearchNhanVien(dsNhanVien list, string manv)
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

void ChenNhanVien(dsNhanVien &list, nhanVien *nhanvienmoi)
{
    int compare;
    int pos;
    for (pos = 0; pos < list.CountNV; pos++)
    {
        if (nhanvienmoi->TEN < list.nodes[pos]->TEN)
        {
            break;
        }

        if (nhanvienmoi->TEN == list.nodes[pos]->TEN)
        {
            if (nhanvienmoi->HO < list.nodes[pos]->HO)
            {
                break;
            }
        }
    }

    for (int i = list.CountNV; i > pos; i--)
    {
        list.nodes[i] = list.nodes[i - 1];
    }
    list.nodes[pos] = nhanvienmoi;
}

void NhapNhanVien(dsNhanVien &list)
{
    bool hasError;
    if (list.CountNV >= MaxNhanVien)
    {
        cout << "so luong nv toi da" << "\n";
        return;
    }

    nhanVien *nv = new nhanVien();
    bool check = false;
    do
    {
        string manv;
        cout << "Nhap ma nhan vien (10 ky tu):";
        getline(cin, manv);
        check = CheckMANV(manv, nv, list);
    } while (check == true);

    do
    {
        string ho;
        cout << "Nhap ho nhan vien: ";
        cin.ignore();
        getline(cin, ho);
        check = CheckHO(ho, nv, list);
    } while (check == true);

    do
    {
        string ten;
        cout << "Nhap ten nhan vien: ";
        getline(cin, ten);
        check = CheckTEN(ten, nv, list);
    } while (check == true);

    do
    {
        string phai;
        cout << "Nhap gioi tinh (1 la nam || 0 la nu): ";
        getline(cin, phai);
        check = CheckPHAI(phai, nv, list);
    } while (check == true);

    if (list.CountNV == 0)
    {
        list.nodes[list.CountNV] = nv;
    }
    else
    {
        ChenNhanVien(list, nv);
    }
    list.CountNV++;
}

void DeleteNV(dsNhanVien &list)
{
    if (NhanVienEmpty(list))
        return;

    string manv;
    cout << "Ma nhan vien: ";
    cin >> manv;

    int pos = SearchNhanVien(list, manv);
    delete list.nodes[pos];

    for (int i = pos; i < list.CountNV - 1; i++)
    {
        list.nodes[i] = list.nodes[i + 1];
    }
    list.CountNV--;
}

void ChinhSuaNhanVien(dsNhanVien &list)
{
    if (NhanVienEmpty(list))
        return;

    char manv[50];
    cout << "Ma nhan vien: ";
    cin >> manv;

    int pos = SearchNhanVien(list, manv);
    if (pos == -1)
        return;

    cout << "Thong tin hien tai: " << endl;
    cout << "Ma nhan vien " << list.nodes[pos]->MANV;
    cout << "Nhap ho sinh vien moi (Enter de giu nguyen): ";
    string newHO;
    getline(cin, newHO);
    if (!newHO.empty())
        list.nodes[pos]->HO = newHO;

    cout << "Nhap ten sinh vien moi (Enter de giu nguyen): ";
    string newTEN;
    getline(cin, newTEN);
    if (!newTEN.empty())
        list.nodes[pos]->TEN = newTEN;

    cout << "Nhap gioi tinh sinh vien moi (nam/nu) (Enter de giu nguyen): ";
    string newPHAI;
    do
    {
        getline(cin, newPHAI);
        if (newPHAI == "nam" || newPHAI == "nu")
        {
            list.nodes[pos]->PHAI = newPHAI;
            break;
        }
    } while (!newPHAI.empty());

    cout << "Da cap nhat thong tin nhan vien." << endl;
}

void DeleteDSNV(dsNhanVien &list)
{
    if (NhanVienEmpty(list))
        return;
    list.CountNV = 0;
}

void InNhanVien(dsNhanVien list)
{
    if (NhanVienEmpty(list))
        return;

    for (int i = 0; i < list.CountNV; i++)
    {
        cout << "Ma nhan vien: " << list.nodes[i]->MANV << endl;
        cout << "Ho nhan vien: " << list.nodes[i]->HO << endl;
        cout << "Ten nhan vien: " << list.nodes[i]->TEN << endl;
        cout << "Gioi tinh: " << list.nodes[i]->PHAI << endl;
    }
}

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
        Write_HoaDon(file, current->data_hd);
        current = current->next;
    }
    file << "End_NhanVien" << endl; // Đánh dấu kết thúc nhân viên
}
void Write_dsNhanVien(const string &filename, dsNhanVien &dsNV)
{
    ofstream file(filename);
    if (!file)
    {
        cerr << "Không thể mở file để ghi!" << endl;
        return;
    }
    file << dsNV.CountNV << endl;
    for (int i = 0; i < dsNV.CountNV; ++i)
    {
        Write_NhanVien(file, *dsNV.nodes[i]);
    }
    file.close();
}
void Read_CTHoaDon(ifstream &file, nodeChiTietHoaDon &cthd)
{
    string line;

    getline(file, cthd.MAVT, '|'); // Đọc mã vật tư cho đến ký tự "|"
    getline(file, line, '|');      // Đọc và chuyển thành số nguyên cho `soLuong`
    cthd.soLuong = stoi(line);

    getline(file, line, '|'); // Đọc và chuyển thành số thực cho `donGia`
    cthd.donGia = stof(line);

    getline(file, line); // Đọc VAT
    cthd.VAT = stof(line);

    getline(file, line); // Đọc "End_ChiTietHoaDon"
}
void Read_HoaDon(ifstream &file, nodeHoaDon &hd)
{
    string line;

    getline(file, hd.SoHD, '|'); // Đọc số hóa đơn đến ký tự "|"

    getline(file, line, '|'); // Đọc loại hóa đơn dưới dạng chuỗi và lấy ký tự đầu
    hd.loai = line[0];

    getline(file, line, '|'); // Đọc ngày dưới dạng chuỗi và chuyển thành số nguyên
    hd.day = stoi(line);

    getline(file, line, '|'); // Đọc tháng dưới dạng chuỗi và chuyển thành số nguyên
    hd.month = stoi(line);

    getline(file, line); // Đọc năm dưới dạng chuỗi và chuyển thành số nguyên
    hd.year = stoi(line);

    // Đọc danh sách chi tiết hóa đơn
    hd.firstCTHD = nullptr;
    ptr_DSCTHD *tail = &hd.firstCTHD;

    while (getline(file, line) && line != "End_HoaDon")
    {
        if (line == "End_ChiTietHoaDon")
            continue; // Bỏ qua dòng "End_ChiTietHoaDon"

        nodeChiTietHoaDon cthd;
        // Sử dụng hàm trực tiếp mà không cần `istringstream`
        cthd.MAVT = line;
        Read_CTHoaDon(file, cthd);

        *tail = new dsChiTietHoaDon{cthd, nullptr};
        tail = &(*tail)->next;
    }
}
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
        Read_HoaDon(file, hd);

        *tail = new dsHoaDon{hd, nullptr};
        tail = &(*tail)->next;
    }
}
void Read_dsNhanVien(const string &filename, dsNhanVien &dsNV)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "Không thể mở file để đọc!" << endl;
        return;
    }

    // Đọc số lượng nhân viên
    string line;
    getline(file, line);
    dsNV.CountNV = stoi(line);

    // Đọc thông tin từng nhân viên
    for (int i = 0; i < dsNV.CountNV; ++i)
    {
        dsNV.nodes[i] = new nhanVien;
        Read_NhanVien(file, *dsNV.nodes[i]);
    }

    file.close();
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
