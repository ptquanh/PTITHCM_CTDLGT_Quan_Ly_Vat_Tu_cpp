#include "../libraries/khaibao.h"

int height(treeVatTu N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int getBalance(treeVatTu N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

treeVatTu newNode(nodeVatTu vt)
{
    treeVatTu node = new dsVatTu();
    node->data_vt = vt;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

treeVatTu rightRotate(treeVatTu y)
{
    treeVatTu x = y->left;
    treeVatTu T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

treeVatTu leftRotate(treeVatTu x)
{
    treeVatTu y = x->right;
    treeVatTu T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

treeVatTu insert(treeVatTu node, nodeVatTu vt)
{
    if (node == NULL)
        return newNode(vt);

    if (strcmp(vt.MAVT, node->data_vt.MAVT) < 0)
        node->left = insert(node->left, vt);
    else if (strcmp(vt.MAVT, node->data_vt.MAVT) > 0)
        node->right = insert(node->right, vt);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && strcmp(vt.MAVT, node->left->data_vt.MAVT) < 0)
        return rightRotate(node);

    if (balance < -1 && strcmp(vt.MAVT, node->right->data_vt.MAVT) > 0)
        return leftRotate(node);

    if (balance > 1 && strcmp(vt.MAVT, node->left->data_vt.MAVT) > 0)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && strcmp(vt.MAVT, node->right->data_vt.MAVT) < 0)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

treeVatTu minValueNode(treeVatTu node)
{
    treeVatTu current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

treeVatTu deleteNode(treeVatTu root, const char *MAVT)
{
    if (root == NULL)
        return root;

    if (strcmp(MAVT, root->data_vt.MAVT) < 0)
        root->left = deleteNode(root->left, MAVT);
    else if (strcmp(MAVT, root->data_vt.MAVT) > 0)
        root->right = deleteNode(root->right, MAVT);
    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            treeVatTu temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            delete temp;
        }
        else
        {
            treeVatTu temp = minValueNode(root->right);
            root->data_vt = temp->data_vt;
            root->right = deleteNode(root->right, temp->data_vt.MAVT);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

treeVatTu search(treeVatTu root, const char *MAVT)
{
    if (root == NULL || strcmp(root->data_vt.MAVT, MAVT) == 0)
    {
        return root;
    }
    if (strcmp(MAVT, root->data_vt.MAVT) < 0)
        return search(root->left, MAVT);

    return search(root->right, MAVT);
}

void nhapVatTu(treeVatTu &root)
{
    nodeVatTu vt;
    while (true)
    {
        cout << "Nhap ma vat tu: ";
        cin >> vt.MAVT;
        if (search(root, vt.MAVT) != NULL)
        {
            cout << "Ma vat tu da ton tai. Vui long nhap ma vat tu khac.\n";
        }
        else
        {
            break;
        }
    }
    cin.ignore();
    cout << "Nhap ten vat tu: ";
    getline(cin, vt.TENVT);
    cout << "Nhap don vi tinh: ";
    getline(cin, vt.DVT);
    cout << "Nhap so luong ton: ";
    cin >> vt.soLuongTon;

    root = insert(root, vt);
    cout << "Da them vat tu thanh cong!\n";
}

void chinhSuaVatTu(treeVatTu &root)
{
    char MAVT[11];
    cout << "Nhap Ma Vat Tu can chinh sua: ";
    cin >> MAVT;
    cin.ignore();
    treeVatTu node = search(root, MAVT);
    if (node == NULL)
    {
        cout << "Khong tim thay vat tu voi ma " << MAVT << endl;
        return;
    }

    cout << "Thong tin hien tai:" << endl;
    cout << "Ma vat tu: " << node->data_vt.MAVT << ", Ten: " << node->data_vt.TENVT
         << ", DVT: " << node->data_vt.DVT << ", So luong ton: " << node->data_vt.soLuongTon << endl;

    cout << "Nhap Ten Vat Tu moi (Enter de giu nguyen): ";
    string newName;
    getline(cin, newName);
    if (!newName.empty())
        node->data_vt.TENVT = newName;

    cout << "Nhap Don Vi Tinh moi (Enter de giu nguyen): ";
    string newDVT;
    getline(cin, newDVT);
    if (!newDVT.empty())
        node->data_vt.DVT = newDVT;

    cout << "Nhap So Luong Ton moi (Enter de giu nguyen): ";
    string newSoLuongTon;
    getline(cin, newSoLuongTon);
    if (!newSoLuongTon.empty())
        node->data_vt.soLuongTon = stoi(newSoLuongTon);

    cout << "Da cap nhat thong tin vat tu." << endl;
}

void xoaVatTu(treeVatTu &root)
{
    char MAVT[11];
    cout << "Nhap Ma Vat Tu can xoa: ";
    cin >> MAVT;
    cin.ignore();

    treeVatTu node = search(root, MAVT);
    if (node == NULL)
    {
        cout << "Khong tim thay vat tu voi ma " << MAVT << endl;
        return;
    }

    char confirm;
    cout << "Ban co chac chan muon xoa vat tu nay? (y/n): ";
    cin >> confirm;
    cin.ignore();

    if (confirm == 'y' || confirm == 'Y')
    {
        root = deleteNode(root, MAVT);
        cout << "Da xoa vat tu voi ma " << MAVT << endl;
    }
    else
    {
        cout << "Huy bo xoa vat tu." << endl;
    }
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
