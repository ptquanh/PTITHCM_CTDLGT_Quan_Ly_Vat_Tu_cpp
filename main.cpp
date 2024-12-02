#include "./screens/mainScreen.h"
#include "./screens/vatTuScreen.h"
#include "./screens/nhanVienScreen.h"
#include "./screens/hoaDonScreen.h"
#include "./screens/thongKeScreen.h"

int main()
{
    ShowCur(false);
    SetConsoleTitleCustom("Chuong trinh quan ly vat tu");
    dsNhanVien dsnv;
    treeVatTu root = nullptr;
    bool isVTOpened = true, isNVOpened = true;
    int smallX = 5, smallY = 2;
    int bigX = 1, bigY = 1;
    int mainMenu = 0, contentMenu = 0;
    readFile_dsVatTu(root, isVTOpened);
    readFile_dsNhanVien(dsnv, isNVOpened);
    while (true)
    {
        fillConsoleWithColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
        if (!isVTOpened)
        {
            drawTableErrors("Khong the mo file ds_VatTu.txt", true);
            return 0;
        }
        if (!isNVOpened)
        {
            drawTableErrors("Khong the mo file ds_NhanVien.txt", true);
            return 0;
        }
        mainMenu = menuChinhDong(MenuChinh);
        switch (mainMenu)
        {
        case 1:
            contentMenu = menuVatTuDong(MenuVatTu);
            system("cls");
            fillConsoleWithColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
            switch (contentMenu)
            {
            case 0:
                menuVatTu(root, dsnv, smallX, smallY);
                break;
            case 1:
                handleNavigationListVatTu(root, smallX, smallY);
                break;
            }
            break;
        case 2:
            contentMenu = menuNhanVienDong(MenuNhanVien);
            system("cls");
            fillConsoleWithColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
            switch (contentMenu)
            {
            case 0:
                menuNhanVien(dsnv, smallX, smallY);
                break;
            case 1:
                handleNavigationListNhanVien(dsnv, smallX, smallY);
                break;
            }
            break;
        case 3:
            contentMenu = menuHoaDonDong(MenuHoaDon);
            system("cls");
            fillConsoleWithColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
            switch (contentMenu)
            {
            case 0:
                menuChiTietHoaDon(dsnv, root, bigX, bigY);
                break;
            case 1:
                handleNavigationListChiTietHoaDon(dsnv, root, bigX, bigY);
                break;
            }
            break;
        case 4:
            contentMenu = menuThongKeDong(MenuThongKe);
            system("cls");
            fillConsoleWithColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
            switch (contentMenu)
            {
            case 0:
                menuThongKeHoaDon(dsnv, smallX, smallY);
                break;
            case 1:
                menuThongKeTop10(dsnv, root, smallX, smallY);
                break;
            case 2:
                menuThongKeDoanhThuNam(dsnv, smallX, smallY);
                break;
            }
            break;
        }
    };
    return 0;
}