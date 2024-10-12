#pragma once
#include "./vatTu.cpp"

void lap_hoa_don(dsNhanVien &ds_nv)
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
    new_hd->data_hd.ptr_DSCTHD = nullptr;
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
    if (nv->dshd == nullptr)
    {
        nv->dshd = new_hd;
    }
    else
    {
        ptr_DSHD temp = nv->dshd;
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
        if (new_hd->data_hd.ptr_DSCTHD == nullptr)
        {
            new_hd->data_hd.ptr_DSCTHD = new_cthd;
            new_cthd->next = nullptr;
        }
        else
        {
            ptr_DSCTHD temp_cthd = new_hd->data_hd.ptr_DSCTHD;
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
void in_hoa_don(dsNhanVien &ds_nv)
{
    string ma_nv;
    cout << "nhap mv: " <<endl;
    cin >> ma_nv;
    nhanVien *nv = nullptr;
    //duyệt mã nv
    for (int i = 0; i < ds_nv.CountNV; ++i)
    {
        if (ds_nv.nodes[i] != nullptr)
        {
            cout << "Kiem tra nhan vien: " << ds_nv.nodes[i]->MANV << endl; // In ra MANV

            // Kiểm tra mã nhân viên
            if (ds_nv.nodes[i]->MANV == ma_nv)
            {
                nv = ds_nv.nodes[i];
                break;
            }
        }
    }
    if (nv == nullptr)
    {
        cout << "Ma nhan vien khong ton tai!" << endl;
        return;
    }
    

    // Phần còn lại của hàm in hóa đơn như trước
    if (nv->dshd == nullptr)
    {
        cout << "Nhan vien khong co hoa don nao!" << endl;
        return;
    }

    // Tiếp tục in hóa đơn
    ptr_DSHD current_hd = nv->dshd;
    while (current_hd != nullptr)
    {
        cout << "\n=============================\n";
        cout << "So Hoa Don: " << current_hd->data_hd.SoHD << endl;
        cout << "Loai: " << (current_hd->data_hd.loai == 'N' ? "Nhap" : "Xuat") << endl;
        cout << "Ngay Lap: " << setw(2) << setfill('0') << current_hd->data_hd.day << "/"
             << setw(2) << setfill('0') << current_hd->data_hd.month << "/"
             << current_hd->data_hd.year << endl;

        ptr_DSCTHD current_cthd = current_hd->data_hd.ptr_DSCTHD;
        cout << "\nChi Tiet Hoa Don:\n";
        // cout << setw(15) << left << "Ma Vat Tu" << setw(10) << "So Luong"
        //      << setw(15) << "Don Gia" << setw(10) << "VAT" << endl;

        while (current_cthd != nullptr)
        {
            cout << "Ma Vat Tu: " << current_cthd->data_cthd.MAVT << endl;
            cout << "So Luong: " << current_cthd->data_cthd.soLuong << endl;
            cout << "Don Gia: " << current_cthd->data_cthd.donGia << endl;
            cout << "VAT: " << current_cthd->data_cthd.VAT << endl;
            current_cthd = current_cthd->next;
        }

        current_hd = current_hd->next;
    }
}

// int main()
// {
//     SetConsoleOutputCP(CP_UTF8);
//     dsNhanVien ds_nv;
//     treeVatTu ds_vt = nullptr;
//     string manv;
//     // Menu chính
//     int choice;
//     do
//     {
//         system("cls");
//         for (int i = 0; i < YeuCauChinh; i++)
//         {
//             cout << MenuChinh[i] << endl;
//         }
//         cout << "Nhap lua chon (0 de thoat): ";
//         cin >> choice;

//         switch (choice)
//         {
//         case 2:
//             InNhanVien(ds_nv);
//             break;
//         case 3:
//             NhapNhanVien(ds_nv);
//             break;
//         case 5:
//             lap_hoa_don(ds_nv);
//             break;
//         case 6:
//             in_hoa_don(ds_nv);
//             break;
//             // Thêm các case khác cho menu chính
//         }

//         system("pause");
//     } while (choice != 0);

//     return 0;
// }