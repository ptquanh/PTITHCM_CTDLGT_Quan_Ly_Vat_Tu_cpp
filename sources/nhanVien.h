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

bool CheckMANV(dsNhanVien &list, string maso)
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

    do
    {
        cout << "Nhap ma nhan vien (10 ky tu):";
        cin >> nv->MANV;

        if (CheckMANV(list, nv->MANV))
        {
            cout << "Ma da ton tai, vui long nhap ma khac" << endl;
            continue;
        }

        if (nv->MANV.find_first_not_of(' ') == string::npos)
        {
            cout << "Loi: Chuoi khong duoc rong hoac chi chua khoang trang" << endl;
            continue;
        }
        if (nv->MANV.size() > 10)
        {
            nv->MANV.resize(10);
        }
    } while (nv->MANV.size() == 0 || CheckMANV(list, nv->MANV));

    do
    {
        cout << "Nhap ho nhan vien: ";
        cin >> nv->HO;
        nv->HO = normalizeString(nv->HO, hasError);
    } while (nv->HO.size() == 0);

    do
    {
        cout << "Nhap ten nhan vien: ";
        cin.ignore();
        getline(cin, nv->TEN);
        nv->TEN = normalizeString(nv->TEN, hasError);
    } while (nv->TEN.size() == 0);

    do
    {
        int inputPhai;
        cout << "Nhap gioi tinh (1 la nam || 0 la nu): ";
        cin >> inputPhai;
        if (inputPhai == 1)
        {
            nv->PHAI = "Nam";
            break;
        }
        if (inputPhai == 0)
        {
            nv->PHAI = "Nu";
            break;
        }
        if (inputPhai != 1 || inputPhai != 0)
        {
            cout << "Loi: Gioi tinh khong hop le!" << endl;
            continue;
        }
    } while (true);

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

// void WriteCTHoaDon(dsChiTietHoaDon *danhsach, ofstream &fileout)
// {
//     dsChiTietHoaDon *temp = danhsach;
//     while (temp != nullptr)
//     {
//         fileout << temp->data_cthd.MAVT << "|"
//                 << temp->data_cthd.soLuong << "|"
//                 << temp->data_cthd.donGia << "|"
//                 << temp->data_cthd.VAT << endl;
//         temp = temp->next;
//     }
// }

// void WriteHoaDon(dsHoaDon *danhsach, ofstream &fileout)
// {
//     dsHoaDon *temp = danhsach;
//     while (temp != nullptr)
//     {
//         fileout << temp->data_hd.SoHD << "|"
//                 << temp->data_hd.loai << "|"
//                 << temp->data_hd.day << "|"
//                 << temp->data_hd.month << "|"
//                 << temp->data_hd.year << "\\\\" << endl;
//         WriteCTHoaDon(temp->data_hd.firstCTHD, fileout);
//         temp = temp->next;
//     }
// }

void writeFile_dsNhanVien(dsNhanVien danhsach)
{
    ofstream fileout;
    fileout.open(filePath_NV, ios_base::out);
    if (!fileout.is_open())
    {
        cout << "Khong the mo file" << endl;
        return;
    }

    if (danhsach.CountNV == 0)
    {
        cout << "Danh sach nhan vien trong!" << endl;
        fileout.close();
        return;
    }
    for (int i = 0; i < danhsach.CountNV; i++)
    {
        fileout << danhsach.nodes[i]->MANV << "|"
                << danhsach.nodes[i]->HO << "|"
                << danhsach.nodes[i]->TEN << "|"
                << danhsach.nodes[i]->PHAI << "\\";
        cout << "Da ghi nhan vien thu " << i + 1 << endl;
        // WriteHoaDon(danhsach.nodes[i]->firstDSHD, fileout);
        fileout << endl;
    }
    fileout.close();
}
void readFile_dsNhanVien(dsNhanVien &ds_nv)
{
    bool hasError;
    ifstream filein;
    filein.open(filePath_NV, ios_base::in);
    if (!filein.is_open())
    {
        cout << "Khong the mo file " << filePath_NV << endl;
        return;
    }

    string line;
    while (getline(filein, line))
    {
        // Bỏ qua dòng trống
        if (line.empty() || line.find_first_not_of(" \t\n\v\f\r") == string::npos)
            continue;

        // Tạo stringstream để xử lý dòng dữ liệu
        stringstream ss(line);
        nhanVien *nv = new nhanVien();

        // Đọc thông tin nhân viên
        getline(ss, nv->MANV, '|');
        getline(ss, nv->HO, '|');
        nv->HO = normalizeString(nv->HO, hasError);
        getline(ss, nv->TEN, '|');
        nv->TEN = normalizeString(nv->TEN, hasError);
        getline(ss, nv->PHAI, '\\');
        nv->PHAI = normalizeString(nv->PHAI, hasError);

        // Kiểm tra xem còn dữ liệu hóa đơn không
        if (ss.peek() != EOF)
        {
            nv->firstDSHD = new dsHoaDon();
            ss.ignore(); // Bỏ qua ký tự '\'

            // Đọc thông tin hóa đơn
            getline(ss, nv->firstDSHD->data_hd.SoHD, '|');
            ss >> nv->firstDSHD->data_hd.loai;
            ss.ignore();
            ss >> nv->firstDSHD->data_hd.day;
            ss.ignore();
            ss >> nv->firstDSHD->data_hd.month;
            ss.ignore();
            ss >> nv->firstDSHD->data_hd.year;
            ss.ignore(2); // Bỏ qua '\\'

            // Đọc thông tin chi tiết hóa đơn
            nv->firstDSHD->data_hd.firstCTHD = new dsChiTietHoaDon();
            getline(ss, nv->firstDSHD->data_hd.firstCTHD->data_cthd.MAVT, '|');
            ss >> nv->firstDSHD->data_hd.firstCTHD->data_cthd.soLuong;
            ss.ignore();
            ss >> nv->firstDSHD->data_hd.firstCTHD->data_cthd.donGia;
            ss.ignore();
            ss >> nv->firstDSHD->data_hd.firstCTHD->data_cthd.VAT;
        }
        else
        {
            nv->firstDSHD = nullptr;
        }

        // Kiểm tra xem đọc dữ liệu có thành công không
        if (!ss.fail())
        {
            if (ds_nv.CountNV < MaxNhanVien)
            {
                if (ds_nv.CountNV == 0)
                {
                    ds_nv.nodes[ds_nv.CountNV] = nv;
                }
                else
                {
                    ChenNhanVien(ds_nv, nv);
                }
                ds_nv.CountNV++;
                cout << "Da doc thanh cong nhan vien: " << nv->MANV << endl;
            }
            else
            {
                cout << "Danh sach nhan vien da day. Khong the them nhan vien: " << nv->MANV << endl;
                if (nv->firstDSHD)
                {
                    delete nv->firstDSHD->data_hd.firstCTHD;
                    delete nv->firstDSHD;
                }
                delete nv;
            }
        }
        else
        {
            cout << "Loi: Khong the doc du lieu tu dong: " << line << endl;
            if (nv->firstDSHD)
            {
                delete nv->firstDSHD->data_hd.firstCTHD;
                delete nv->firstDSHD;
            }
            delete nv;
        }
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