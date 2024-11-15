#include "./screens/mainScreen.h"

int main()
{
    ShowCur(false);
    dsNhanVien dsnv;
    treeVatTu root = nullptr;
    string errorMessage;
    bool isVTOpened = true, isNVOpened = true;
    int smallX = 5, smallY = 2;
    int bigX = 1, bigY = 1;
    int mainMenu = 0, contentMenu = 0;
    readFile_dsVatTu(root, isVTOpened);
    readFile_dsNhanVien(dsnv, isNVOpened);
    if (!isVTOpened)
    {
        errorMessage = "Khong the mo file ds_VatTu.txt";
        drawTableErrors(errorMessage, true);
        return 0;
    }
    if (!isNVOpened)
    {
        errorMessage = "Khong the mo file ds_NhanVien.txt";
        drawTableErrors(errorMessage, true);
        return 0;
    }
    // fillConsoleWithColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
    // drawTableUpdateVatTu(smallX, smallY);
    // drawTableSuggestVatTu(smallX, smallY);
    while (true)
    {
        mainMenu = menuChinhDong(MenuChinh);
        fillConsoleWithColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
        switch (mainMenu)
        {
        case 1:
            contentMenu = menuVatTuDong(MenuVatTu);
            system("cls");
            fillConsoleWithColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
            switch (contentMenu)
            {
            case 0:
                menuVatTu(root, smallX, smallY);
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
                inThongKeHoaDon(dsnv);
                break;
            case 1:
                inTop10DTVT(dsnv);
                break;
            case 2:
                inDoanhThuNam(dsnv);
                break;
            }
            break;
        }
    };
    return 0;
}