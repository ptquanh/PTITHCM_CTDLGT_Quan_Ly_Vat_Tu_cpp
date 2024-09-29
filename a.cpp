#include <iostream>
#include <iomanip>
#include <string.h>
#include "../khaibao.h"
using namespace std;

// da duoc chuyen sang file khaibao.h

treeVatTu root = NULL;
// xoay trai
treeVatTu Rotate_Left(treeVatTu root)
{
    treeVatTu p;
    if (root == NULL)
        printf("Khong the xoay trai vi cay bi rong.");
    else if (root->right == NULL)
        printf("Khong the xoay trai vi khong co nut con ben phai.");
    else
    {
        p = root->right;
        root->right = p->left;
        p->left = root;
    }
    return p;
}
// xoay phai
treeVatTu Rotate_Right(treeVatTu ya)
{
    treeVatTu s;
    if (ya == NULL)
        printf("Khong the xoay phai vi cay bi rong.");
    else if (ya->left == NULL)
        printf("Khong the xoay phai vi khong co nut con ben trai.");
    else
    {
        s = ya->left;
        ya->left = s->right;
        s->right = ya;
    }
    return s;
}
//
treeVatTu Search(treeVatTu root, int key)
{
    if (root == NULL || root->key == key)
        return root;
    if (key < root->key)
        return Search(root->left, key);

    return Search(root->right, key);
}
//
void ChinhSuaVatTu(treeVatTu &root)
{
    int key;
    cout << "Nhap Ma Vat Tu can chinh sua: ";
    cin >> key;
    cin.ignore();

    treeVatTu node = Search(root, key);
    if (node == NULL)
    {
        cout << "Khong tim thay vat tu voi ma " << key << endl;
        return;
    }

    cout << "Thong tin hien tai:" << endl;
    cout << "Ma VT: " << node->vt.MAVT << ", Ten: " << node->vt.TENVT
         << ", DVT: " << node->vt.DVT << ", So luong ton: " << node->vt.soLuongTon << endl;

    cout << "Nhap Ten Vat Tu moi (Enter de giu nguyen): ";
    string newName;
    getline(cin, newName);
    if (!newName.empty())
        node->vt.TENVT = newName;

    cout << "Nhap Don Vi Tinh moi (Enter de giu nguyen): ";
    string newDVT;
    getline(cin, newDVT);
    if (!newDVT.empty())
        node->vt.DVT = newDVT;

    cout << "Da cap nhat thong tin vat tu." << endl;
}
//
treeVatTu minValueNode(treeVatTu node)
{
    treeVatTu current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

treeVatTu deleteNode(treeVatTu root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            treeVatTu temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            treeVatTu temp = root->left;
            delete root;
            return temp;
        }

        treeVatTu temp = minValueNode(root->right);
        root->key = temp->key;
        root->vt = temp->vt;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

//
void XoaVatTu(treeVatTu &root)
{
    int key;
    cout << "Nhap Ma Vat Tu can xoa: ";
    cin >> key;
    cin.ignore();

    treeVatTu node = Search(root, key);
    if (node == NULL)
    {
        cout << "Khong tim thay vat tu voi ma " << key << endl;
        return;
    }

    root = deleteNode(root, key);
    cout << "Da xoa vat tu voi ma " << key << endl;
}
// insert cua thay
void Insert(treeVatTu &pavltree, int x, vatTu vt)
{
    treeVatTu fp, p, q, fya, ya, s;
    int imbal;
    fp = NULL;
    p = pavltree;
    fya = NULL;
    ya = p;
    while (p != NULL)
    {
        if (x == p->key)
            return;
        if (x < p->key)
            q = p->left;
        else
            q = p->right;
        if (q != NULL)
            if (q->bf != 0)
            {
                fya = p;
                ya = q;
            }
        fp = p;
        p = q;
    }
    q = new nodeVatTu;
    q->key = x;
    q->bf = 0;
    q->vt = vt;
    q->left = NULL;
    q->right = NULL;
    if (x < fp->key)
        fp->left = q;
    else
        fp->right = q;

    if (x < ya->key)
        p = ya->left;
    else
        p = ya->right;
    s = p;
    while (p != q)
    {
        if (x < p->key)
        {
            p->bf = 1;
            p = p->left;
        }
        else
        {
            p->bf = -1;
            p = p->right;
        }
    }
    if (x < ya->key)
        imbal = 1;
    else
        imbal = -1;
    if (ya->bf == 0)
    {
        ya->bf = imbal;
        return;
    }
    if (ya->bf != imbal)
    {
        ya->bf = 0;
        return;
    }
    if (s->bf == imbal)
    {
        if (imbal == 1)
            p = Rotate_Right(ya);
        else
            p = Rotate_Left(ya);
        ya->bf = 0;
        s->bf = 0;
    }
    else
    {
        if (imbal == 1)
        {
            ya->left = Rotate_Left(s);
            p = Rotate_Right(ya);
        }
        else
        {
            ya->right = Rotate_Right(s);
            p = Rotate_Left(ya);
        }
        if (p->bf == 0)
        {
            ya->bf = 0;
            s->bf = 0;
        }
        else if (p->bf == imbal)
        {
            ya->bf = -imbal;
            s->bf = 0;
        }
        else
        {
            ya->bf = 0;
            s->bf = imbal;
        }
        p->bf = 0;
    }
    if (fya == NULL)
        pavltree = p;
    else if (ya == fya->right)
        fya->right = p;
    else
        fya->left = p;
}

void NhapVatTu(treeVatTu &root)
{
    char input[11];
    vatTu vt;
    treeVatTu p;

    do
    {
        cout << "Nhap Ma Vat Tu (nhap '0' de ket thuc): ";
        cin.getline(input, 11);

        if (strcmp(input, "0") != 0)
        {
            strncpy(vt.MAVT, input, 10);
            vt.MAVT[10] = '\0';

            cout << "Nhap Ten Vat Tu: ";
            getline(cin, vt.TENVT);

            cout << "Nhap Don Vi Tinh: ";
            getline(cin, vt.DVT);

            int khoa = atoi(vt.MAVT);

            if (root == NULL || Search(root, khoa) == NULL)
            {
                cout << "Nhap So Luong Ton: ";
                cin >> vt.soLuongTon;
                cin.ignore();
            }
            else
            {
                cout << "Vat tu da ton tai. Khong the nhap so luong ton." << endl;
                vt.soLuongTon = Search(root, khoa)->vt.soLuongTon;
            }

            if (root == NULL)
            {
                p = new nodeVatTu;
                p->key = khoa;
                p->vt = vt;
                p->bf = 0;
                p->left = NULL;
                p->right = NULL;
                root = p;
            }
            else
            {
                Insert(root, khoa, vt);
            }

            cout << "Da them/cap nhat vat tu thanh cong.\n"
                 << endl;
        }
    } while (strcmp(input, "0") != 0);
}
//
void inOrder(treeVatTu root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << "Ma VT: " << root->vt.MAVT
             << ", Ten: " << root->vt.TENVT
             << ", DVT: " << root->vt.DVT
             << ", So luong ton: " << root->vt.soLuongTon << endl;
        inOrder(root->right);
    }
}
// phan cmt nay la cua cau b: in
/*void swap(vatTu &a, vatTu &b)
{
    vatTu temp = a;
    a = b;
    b = temp;
}

Hàm so sánh để sắp xếp theo tên vật tư
bool compareByName(const vatTu &a, const vatTu &b)
{
    return strcmp(a.TENVT.c_str(), b.TENVT.c_str()) < 0;
}

bubble sort
void bubbleSort(vatTu arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (compareByName(arr[j + 1], arr[j]))
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

dua vat tu vao mang
int collectVatTu(treeVatTu root, vatTu arr[], int index = 0)
{
    if (root != NULL)
    {
        index = collectVatTu(root->left, arr, index);
        arr[index++] = root->vt;
        index = collectVatTu(root->right, arr, index);
    }
    return index;
}

void InDanhSachVatTuTheoTen(treeVatTu root)
{
    vatTu vatTuArr[MAX_VAT_TU];
    int count = collectVatTu(root, vatTuArr);

    bubbleSort(vatTuArr, count);

    cout << "Danh sach vat tu theo thu tu ten tang dan:" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << "Ten: " << vatTuArr[i].TENVT
             << ", Ma VT: " << vatTuArr[i].MAVT
             << ", DVT: " << vatTuArr[i].DVT
             << ", So luong ton: " << vatTuArr[i].soLuongTon << endl;
    }
}
*/
int main()
{
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
            NhapVatTu(root);
            break;
        case 2:
            inOrder(root);
            break;
        case 3:
            ChinhSuaVatTu(root);
            break;
        case 4:
            XoaVatTu(root);
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
