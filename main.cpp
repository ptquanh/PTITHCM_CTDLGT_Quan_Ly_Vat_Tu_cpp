#pragma once
// #include "./libraries/khaibao.h"
#include "./sources/vatTu.h"
// #include "./sources/nhanVien.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    treeVatTu root = NULL;
    nhanVien nv;
    dsNhanVien ds_nv;
    readFile_dsVatTu(root);
    int choice;
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
            
            break;
        case 6:
            
            break;
        case 7:
            
            break;
        case 8:
            
            break;
        case 9:
            
            break;
        case 10:
            
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
    } while (choice != 0);
    writeFile_dsVatTu(root);
    return 0;
}
