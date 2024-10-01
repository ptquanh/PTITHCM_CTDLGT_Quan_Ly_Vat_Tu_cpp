#include "../libraries/khaibao.h"
#include "./a.cpp"
void compareName(){

}
void swap(){
    
}
void inOrder(treeVatTu root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << "Ma vat tu: " << root->data_vt.MAVT
             << ", Ten: " << root->data_vt.TENVT
             << ", DVT: " << root->data_vt.DVT
             << ", So luong ton: " << root->data_vt.soLuongTon << endl;
        inOrder(root->right);
    }
}
int main()
{
    treeVatTu root = NULL;
    int choice;
    do
    {
        cout << "\n--- Menu ---\n";
        for (int i = 0; i < YeuCauA; i++)
        {
            cout << MenuA[i] << endl;
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
            inOrder(root);
            break;
        case 3:
            chinhSuaVatTu(root);
            break;
        case 4:
            xoaVatTu(root);
            break;
        case 0:
            cout << "Thoat\n";
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }
    } while (choice != 0);

    return 0;
}
