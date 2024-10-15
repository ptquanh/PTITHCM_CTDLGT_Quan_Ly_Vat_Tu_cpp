// #include "./libraries/khaibao.h"
#include "./sources/vatTu.h"
#include "./sources/nhanVien.h"
// #pragma once

int main()
{
    treeVatTu root = NULL;
    nhanVien nv;
    dsNhanVien ds_nv;
    int choice;
    readFile_dsVatTu(root);
    readFile_dsNhanVien(ds_nv);
    do
    {
        cout << "\n--- Menu ---\n";
        for (int i = 0; i < YeuCauChinh; i++)
        {
            cout << MenuChinh[i] << endl;
        }
        cout << "0. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            nhapVatTu(root);
            break;
        case 2:
            chinhSuaVatTu(root);
            break;
        case 3:
            xoaVatTu(root);
            break;
        case 4:
            inDanhSachVatTu(root);
            break;
        case 5:
            NhapNhanVien(ds_nv);
            break;
        case 6:
            ChinhSuaNhanVien(ds_nv);
            break;
        case 7:
            DeleteNV(ds_nv);
            break;
        case 8:
            InNhanVien(ds_nv);
            break;
        case 9:
            lap_hoa_don(ds_nv);
            break;
        case 10:
            in_hoa_don(ds_nv);
            break;
        case 11:

            break;
        case 12:

            break;
        case 13:

            break;
        case 0:
            cout << "Thoat\n";
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }
        writeFile_dsVatTu(root);
        writeFile_dsNhanVien(ds_nv);
    } while (choice != 0);
   
    return 0;
}