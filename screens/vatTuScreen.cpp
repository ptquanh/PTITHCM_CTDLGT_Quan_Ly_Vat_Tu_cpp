#include "../sources/vatTu.h"
void handleNavigationListVatTu(treeVatTu root, int x, int y, int w, int h);
int handleNavigationUpdateVatTu(treeVatTu root, int x, int y, int w, int h);
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
        // SetBGColor(DARKGRAY);
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

void handleNavigationAddVatTu(treeVatTu root, int x, int y, int w, int h)
{
    string errorMessage;
    int currentPage = 1;
    int selectedRow = -1;
    char key;
    drawTableUpdateVatTu(x, y);
    // drawTablePrintVatTu(x, y, w, h, root);
    nhapVatTu(root, x, y);
    SetColor(WHITE);
    SetBGColor(BLACK);
    inDanhSachVatTu(root, currentPage, selectedRow, x, errorMessage);
    while (true)
    {
        key = getch();
        switch (key)
        {
            key = getch();
            switch (key)
            {
            case ESC:
                gotoxy(0, 0);
                cout << "ESC";
                fillAreaColor(x + 69, y, 41, 23, BLACK);
                handleNavigationListVatTu(root, x, y, w, h);
                break;
            }
        }
    }
}
int handleNavigationUpdateVatTu(treeVatTu root, int x, int y, int w, int h)
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
    drawTablePrintVatTu(x, y, w, h);
    while (true)
    {
        // Display list with highlighted MAVT
        inDanhSachVatTu(root, currentPage, selectedRow, x, errorMessage);

        key = getch();
        switch (key)
        {
        case LEFT:
            if (currentPage > 1)
            {
                currentPage--;
                selectedRow = 0; // Reset selection when changing page
                clearTableContent(x);
            }
            break;
        case RIGHT:
            if (currentPage < totalPages)
            {
                currentPage++;
                selectedRow = 0; // Reset selection when changing page
                clearTableContent(x);
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
            SetBGColor(WHITE);
            SetColor(BLACK);
            gotoxy(x + 88, y + 4);
            cout << arr[currentChoice]->data_vt.MAVT;
            gotoxy(x + 88, y + 6);
            cout << arr[currentChoice]->data_vt.TENVT;
            gotoxy(x + 88, y + 8);
            cout << arr[currentChoice]->data_vt.DVT;
            gotoxy(x + 88, y + 10);
            cout << arr[currentChoice]->data_vt.soLuongTon;
            SetBGColor(BLACK);
            SetColor(WHITE);
            break;
        case TAB:
            for (int i = x + 26; i < x + 33; i++)
            {
                gotoxy(i, 26);
                SetBGColor(BLACK);
                cout << " ";
            }
            for (int i = x + 26; i < x + 31; i++)
            {
                gotoxy(i, 26);
                SetBGColor(WHITE);
                cout << " ";
                SetBGColor(BLACK);
            }
            SetColor(BLACK);
            SetBGColor(WHITE);
            int goToPage;
            gotoxy(x + 27, 26);
            cin >> goToPage;
            SetColor(WHITE);
            SetBGColor(BLACK);
            while (goToPage > totalPages)
            {
                errorMessage = "Loi trang. Vui long nhap lai";
                drawTableErrors(5, 2, errorMessage);
                for (int i = x + 26; i < x + 31; i++)
                {
                    gotoxy(i, 26);
                    SetBGColor(WHITE);
                    cout << " ";
                    SetBGColor(BLACK);
                }
                SetColor(BLACK);
                SetBGColor(WHITE);
                gotoxy(x + 27, 26);
                cin >> goToPage;
                SetColor(WHITE);
                SetBGColor(BLACK);
            }
            errorMessage = " ";
            currentPage = goToPage;
            drawTableErrors(5, 2, errorMessage);
            break;
        case F1:
            handleNavigationUpdateVatTu(root, x, y, w, h);
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
void handleNavigationListVatTu(treeVatTu root, int x, int y, int w, int h)
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
    drawTablePrintVatTu(x, y, w, h);
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
                clearTableContent(x);
            }
            break;
        case RIGHT:
            if (currentPage < totalPages)
            {
                currentPage++;
                clearTableContent(x);
            }
            break;
        case TAB:
            currentPage = pageSearchByTab(x, currentPage, totalPages, errorMessage);
            break;
        case F1:
            handleNavigationAddVatTu(root, x, y, w, h);
            break;
        case F2:
            gotoxy(0, 0);
            cout << "F2";
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
    handleNavigationListVatTu(root, x, y, 15, 23);
    // while (1)
    // {
    //     getch();
    // }
}