#include "../sources/vatTu.h"

int main()
{
    ShowCur(false);
    treeVatTu root = nullptr;
    readFile_dsVatTu(root);
    int x = 2;
    int y = 2;
    handleNavigation(root);
    while (1)
    {
        getch();
    }
}