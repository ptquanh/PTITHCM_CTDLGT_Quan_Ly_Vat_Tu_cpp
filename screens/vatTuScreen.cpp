#include "../sources/vatTu.h"
void handleNavigationListVatTu(treeVatTu root, int x, int y, int w, int h);
void handleNavigationUpdateVatTu(treeVatTu root, int x, int y, int w, int h);
void handleNavigationAddVatTu(treeVatTu root, int x, int y, int w, int h);

void drawTableUpdateVatTu(int x, int y)
{
    drawHCN(x + 69, y, 41, 13);
    SetColor(GREEN);
    gotoxy(x + 71, y + 5);
    cout << "Toi da 10 ki tu";
    gotoxy(x + 71, y + 7);
    cout << "Toi da 20 ki tu";
    gotoxy(x + 71, y + 9);
    cout << "Toi da 6 ki tu";
    gotoxy(x + 71, y + 11);
    cout << "Toi da 6 chu so";
    SetColor(BLACK);
    gotoxy(x + 82, y + 2);
    cout << "CAP NHAT VAT TU";
    gotoxy(x + 71, y + 4);
    cout << "MA VAT TU      :";
    gotoxy(x + 71, y + 6);
    cout << "TEN VAT TU     :";
    gotoxy(x + 71, y + 8);
    cout << "DON VI TINH    :";
    gotoxy(x + 71, y + 10);
    cout << "SO LUONG TON   :";
    // to mau trang
    for (int i = x + 87; i < x + 109; i++)
    {
        SetBGColor(BLACK);
        gotoxy(i, y + 4);
        cout << " ";
        gotoxy(i, y + 6);
        cout << " ";
        gotoxy(i, y + 8);
        cout << " ";
        gotoxy(i, y + 10);
        cout << " ";
    }
}

void drawTablePrintVatTu(int x, int y, int w, int h)
{
    setColorByRequest(LIGHTGRAY, DARKGRAY);
    drawHCN(x, y, (w * 4) + 2, h);
    horizontalLine(x + 1, y + 2, ((w * 4) + 2) - 1);
    // ve vien
    gotoxy(x, y + 2);
    cout << tRight;
    gotoxy(x + (w * 4) + 2, y + 2);
    cout << tLeft;
    gotoxy(x + (((w * 4)) - 45), y);
    cout << tDown;
    gotoxy(x + (((w * 4)) - 45), y + h);
    cout << tUp;
    gotoxy(x + (((w * 4) + 2) - 22), y);
    cout << tDown;
    gotoxy(x + (((w * 4) + 2) - 22), y + h);
    cout << tUp;
    gotoxy(x + (((w * 4) + 2) - 11), y);
    cout << tDown;
    gotoxy(x + (((w * 4) + 2) - 11), y + h);
    cout << tUp;
    verticalLine(x + (((w * 4)) - 45), y + 1, h - 1);
    verticalLine(x + (((w * 4) + 2) - 22), y + 1, h - 1);
    verticalLine(x + (((w * 4) + 2) - 11), y + 1, h - 1);
    gotoxy(x + (((w * 4)) - 45), y + 2);
    cout << cross;
    gotoxy(x + (((w * 4) + 2) - 22), y + 2);
    cout << cross;
    gotoxy(x + (((w * 4) + 2) - 11), y + 2);
    cout << cross;
    // ve header 0
    setColorByRequest(LIGHTGRAY, RED);
    gotoxy(x + 20, y - 1);
    cout << "---DANH SACH VAT TU---";
    gotoxy(x + 3, y + 1);
    cout << "MA VT";
    // ve header 1
    gotoxy(x + 18, y + 1);
    cout << "TEN VT";
    // ve header 2
    gotoxy(x + 43, y + 1);
    cout << "DVT";
    // ve header 3
    gotoxy(x + 54, y + 1);
    cout << "SL";
}

void handleNavigationAddVatTu(treeVatTu root, int x, int y)
{
    drawTableUpdateVatTu(x, y);
    nhapVatTu(root, x, y);
    clearTablePrint(x);
}

void handleNavigationUpdateVatTu(treeVatTu root, int x, int y)
{
    string errorMessage;
    int n = countNodes(root);
    treeVatTu *arr = new treeVatTu[n];
    int index = 0;
    storeInorder(root, arr, &index);
    quickSort(arr, 0, n - 1);
    string currentMAVT;
    int totalPages = ceil((float)n / ROWS);
    int currentPage = 1;
    int selectedRow = 0;
    char key;
    int currentChoice = -1;
    drawTableUpdateVatTu(x, y);
    while (true)
    {
        bool isESC, isSaved = false;
        inDanhSachVatTu(root, currentPage, selectedRow, x, errorMessage);
        key = getch();
        switch (key)
        {
        case LEFT:
            if (currentPage > 1)
            {
                currentPage--;
                selectedRow = 0;
                clearTablePrint(x);
            }
            break;
        case RIGHT:
            if (currentPage < totalPages)
            {
                currentPage++;
                selectedRow = 0;
                clearTablePrint(x);
            }
            break;
        case UP:
            if (selectedRow > 0)
            {
                selectedRow--;
            }
            else
            {
                // Get number of items on current page
                int itemsOnPage = min(ROWS, n - (currentPage - 1) * ROWS);
                selectedRow = itemsOnPage - 1;
            }
            break;
        case DOWN:
        {
            // Get number of items on current page
            int itemsOnPage = min(ROWS, n - (currentPage - 1) * ROWS);
            if (selectedRow < itemsOnPage - 1)
            {
                selectedRow++;
            }
            else
            {
                selectedRow = 0;
            }
        }
        break;
        case ENTER:
            currentChoice = (currentPage - 1) * ROWS + selectedRow;
            for (int i = x + 87; i < x + 109; i++)
            {
                SetBGColor(BLACK);
                gotoxy(i, y + 4);
                cout << " ";
                gotoxy(i, y + 6);
                cout << " ";
                gotoxy(i, y + 8);
                cout << " ";
                gotoxy(i, y + 10);
                cout << " ";
            }
            setColorByRequest(BLACK, WHITE);
            currentMAVT = arr[currentChoice]->data_vt.MAVT;
            chinhSuaVatTu(root, currentMAVT, x, y, isESC, isSaved);
            delete[] arr;
            ShowCur(false);
            if (isESC == true)
            {
                errorMessage = "Dang thoat chuong trinh...";
                drawTableErrors(5, 2, errorMessage);
                Sleep(1500);
                errorMessage = "";
                drawTableErrors(5, 2, errorMessage);
                fillAreaColor(x + 69, y, 41, 13, LIGHTGRAY);
                return;
            }
            if (isSaved == true)
            {
                errorMessage = "Sua vat tu thanh cong";
                drawTableErrors(5, 2, errorMessage);
                Sleep(1500);
                errorMessage = "";
                drawTableErrors(5, 2, errorMessage);
                clearTablePrint(x);
                fillAreaColor(x + 69, y, 41, 13, LIGHTGRAY);
                return;
            }
            n = countNodes(root);   // Đếm lại số node
            arr = new treeVatTu[n]; // Tạo mảng mới
            index = 0;
            storeInorder(root, arr, &index); // Lưu lại các node vào mảng
            quickSort(arr, 0, n - 1);        // Sắp xếp lại mảng

            // Cập nhật lại số trang và điều chỉnh trang hiện tại nếu cần
            totalPages = ceil((float)n / ROWS);
            if (currentPage > totalPages)
            {
                currentPage = totalPages;
            }
            if (selectedRow >= min(ROWS, n - (currentPage - 1) * ROWS))
            {
                selectedRow = min(ROWS, n - (currentPage - 1) * ROWS) - 1;
            }

            clearTablePrint(x); // Xóa bảng cũ
            setColorByRequest(LIGHTGRAY, BLACK);
            
            break;
        case TAB:
            currentPage = pageSearchByTab(x, currentPage, totalPages, errorMessage);
            break;
        case ESC:
            errorMessage = "Dang thoat chuong trinh...";
            drawTableErrors(5, 2, errorMessage);
            Sleep(1500);
            errorMessage = "";
            drawTableErrors(5, 2, errorMessage);
            fillAreaColor(x + 69, y, 41, 13, LIGHTGRAY);
            delete[] arr;
            return;
        }
    }
}

int handleNavigationDeleteVatTu(treeVatTu root, int x, int y)
{
    // ShowCur(false);
    string errorMessage;
    int n = countNodes(root);
    treeVatTu *arr = new treeVatTu[n];
    int index = 0;
    storeInorder(root, arr, &index);
    quickSort(arr, 0, n - 1);

    int totalPages = ceil((float)n / ROWS);
    int currentPage = 1;
    int selectedRow = 0; // Track selected row
    char key;
    int currentChoice = -1;
    drawTablePrintVatTu(x, y, 15, 23);
    while (true)
    {
        inDanhSachVatTu(root, currentPage, selectedRow, x, errorMessage);
        key = getch();
        switch (key)
        {
        case LEFT:
            if (currentPage > 1)
            {
                currentPage--;
                selectedRow = 0; // Reset selection when changing page
                clearTablePrint(x);
            }
            break;
        case RIGHT:
            if (currentPage < totalPages)
            {
                currentPage++;
                selectedRow = 0; // Reset selection when changing page
                clearTablePrint(x);
            }
            break;
        case UP:
            if (selectedRow > 0)
            {
                selectedRow--;
            }
            else
            {
                // Get number of items on current page
                int itemsOnPage = min(ROWS, n - (currentPage - 1) * ROWS);
                selectedRow = itemsOnPage - 1;
            }
            break;
        case DOWN:
        {
            // Get number of items on current page
            int itemsOnPage = min(ROWS, n - (currentPage - 1) * ROWS);
            if (selectedRow < itemsOnPage - 1)
            {
                selectedRow++;
            }
            else
            {
                selectedRow = 0;
            }
        }
        break;
        case ENTER:
            currentChoice = (currentPage - 1) * ROWS + selectedRow;
            for (int i = x + 87; i < x + 109; i++)
            {
                SetBGColor(BLACK);
                gotoxy(i, y + 4);
                cout << " ";
                gotoxy(i, y + 6);
                cout << " ";
                gotoxy(i, y + 8);
                cout << " ";
                gotoxy(i, y + 10);
                cout << " ";
            }
            setColorByRequest(BLACK, WHITE);
            gotoxy(x + 88, y + 4);
            cout << arr[currentChoice]->data_vt.MAVT;
            gotoxy(x + 88, y + 6);
            cout << arr[currentChoice]->data_vt.TENVT;
            gotoxy(x + 88, y + 8);
            cout << arr[currentChoice]->data_vt.DVT;
            gotoxy(x + 88, y + 10);
            cout << arr[currentChoice]->data_vt.soLuongTon;
            setColorByRequest(LIGHTGRAY, BLACK);
            break;
        case TAB:
            currentPage = pageSearchByTab(x, currentPage, totalPages, errorMessage);
            break;
        case ESC:
            system("cls");
            cout << "Exit";
            return -1;
        }
    }
    delete[] arr;
    // return currentChoice;
}
void handleNavigationListVatTu(treeVatTu root, int x, int y)
{
    string errorMessage;
    int n = countNodes(root);
    treeVatTu *arr = new treeVatTu[n];
    int index = 0;
    storeInorder(root, arr, &index);
    quickSort(arr, 0, n - 1);

    int totalPages = ceil((float)n / ROWS);
    int currentPage = 1;
    int selectedRow = -1;
    char key;
    int currentChoice = -1;
    drawTablePrintVatTu(x, y, 15, 23);
    while (true)
    {
        setColorByRequest(LIGHTGRAY, BLACK);
        inDanhSachVatTu(root, currentPage, selectedRow, x, errorMessage);
        key = getch();
        switch (key)
        {
        case LEFT:
            if (currentPage > 1)
            {
                currentPage--;
                clearTablePrint(x);
            }
            break;
        case RIGHT:
            if (currentPage < totalPages)
            {
                currentPage++;
                clearTablePrint(x);
            }
            break;
        case TAB:
            currentPage = pageSearchByTab(x, currentPage, totalPages, errorMessage);
            break;
        case F1:
            handleNavigationAddVatTu(root, x, y);
            break;
        case F2:
            handleNavigationUpdateVatTu(root, x, y);
            break;
        case F3:
            gotoxy(0, 0);
            cout << "F3";
            break;
        case F4:
            gotoxy(0, 0);
            cout << "F4";
            break;
        case ESC:
            system("cls");
            cout << "Exit";
        }
    }
    delete[] arr;
}
void drawKeysGuideVatTu(int x, int y, char nutDieuHuong[SoNut][50])
{
    int space = 7;
    int w;
    setColorByRequest(LIGHTGRAY, BLACK);
    for (int i = 1; i <= SoNut; i++)
    {
        w = strlen(nutDieuHuong[i - 1]) + 1;
        drawHCN(x + 4 + i * 12 + i * space, y + 25, w, 2);
        gotoxy(x + i * 12 + i * space + 5, y + 26);
        cout << nutDieuHuong[i - 1];
    }
    w = 12;
    drawHCN(x, y + 25, w, 2);
    gotoxy(x + 1, y + 26);
    cout << "MENU VAT TU";
}
int main()
{
    ShowCur(false);
    treeVatTu root = nullptr;
    bool isOpened = true;
    string errorMessage;
    int x = 5;
    int y = 2;
    fillConsoleWithColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
    readFile_dsVatTu(root, isOpened);
    drawTableErrors(x, y, errorMessage);
    drawKeysGuideVatTu(x, y, keyGuides);
    handleNavigationListVatTu(root, x, y);
    // while (1)
    // {
    //     getch();
    // }
}