#include "./libraries/khaibao.h"
#include "./sources/vatTu.h"
#include "./sources/nhanVien.h"

int main()
{
    treeVatTu root = NULL;
    nhanVien nv;
    dsNhanVien ds_nv;
    int choice;
    bool isOpened;
    // readFile_dsVatTu(root, isOpened);
    // readFile_dsNhanVien(ds_nv);
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
            // nhapVatTu(root);
            break;
        case 2:
            chinhSuaVatTu(root);
            break;
        case 3:
            xoaVatTu(root);
            break;
        case 4:
            timKiemVatTu(root);
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
            lapHoaDon(ds_nv);
            break;
        case 10:
            inHoaDon(ds_nv);
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
        // writeFile_dsVatTu(root);
        Write_dsNhanVien(ds_nv);
    return 0;
}