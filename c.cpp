#include <iostream>
#include <iomanip>
#include <windows.h>
#include "./khaibao.h"
using namespace std;

// ----------------------------

int SearchNhanVien(listNV list, char manv[50]){
    int pos = -1;
    for (int i = 0; i < list.CountNV; i++)
    {
        if (strcmp(list.nodes[i]->MANV, manv) == 0)
        {
            pos = i;
        }
    }

    if(pos = -1){
        cout << "Khong co nhan vien"; return -1;
    }
    
    return pos;
    
}


bool CheckMANV(listNV &list, char *maso)
{
    for (int i = 0; i < list.CountNV; i++)
    {
        if (strcmp(list.nodes[i]->MANV, maso) == 0)
        {
            return true;
        }
    }
    return false;
}

void ChenNhanVien(listNV &list, Nhanvien *nhanvienmoi)
{
    int compare;
    int pos;
    for (pos = 0; pos < list.CountNV; pos++)
    {
        compare = strcmp(nhanvienmoi->TEN, list.nodes[pos]->TEN);
        // so sánh tên
        if (compare < 0)
        {
            break;
        }

        // so sánh họ
        if (compare == 0)
        {
            compare = strcmp(nhanvienmoi->HO, list.nodes[pos]->HO);
            // nếu họ nhỏ hơn thì không cần tăng tiếp nữa
            if (compare < 0)
            {
                break;
            }
        }
    }

    for (int i = list.CountNV; i > pos; i--)
    {
        list.nodes[i] = list.nodes[i - 1];
    }
    list.nodes[pos] = nhanvienmoi;
}

void NhapNhanVien(listNV &list)
{
    if (list.CountNV >= MaxNhanVien)
    {
        cout << "so luong nv toi da" << "\n";
        return;
    }

    Nhanvien *nv = new Nhanvien();

    do
    {
        cout << "nhap ma nv ";
        cin >> nv->MANV;
        if (CheckMANV(list, nv->MANV))
        {
            cout << "ma da ton tai, nhap ma khac" << "\n";
        }
    } while (strlen(nv->MANV) == 0 || CheckMANV(list, nv->MANV));

    do
    {
        cout << "nhap ho nv ";
        cin >> nv->HO;
    } while (strlen(nv->HO) == 0);

    // nhập tên
    do
    {
        cout << "nhap ten nv ";
        cin >> nv->TEN;
    } while (strlen(nv->TEN) == 0);

    // nhập giới tính
    do
    {
        cout << "nhap gioi tinh nam hoac nu ";
        cin >> nv->PHAI;
        // cout << nv->PHAI;
        if (strcmp(nv->PHAI, "nam") == 0)
            break;
        if (strcmp(nv->PHAI, "nu") == 0)
            break;
    } /*while (strcmp(nv->PHAI, "nam") == 0 || strcmp(nv->PHAI, "nu") == 0);*/
    while (true);
    // chèn sinh viên có thứ tự tăng dần theo tên
    if (list.CountNV == 0)
    { // nếu danh sách rỗng
        list.nodes[list.CountNV] = nv;
    }
    else
    { // nếu danh sách không có rỗng thì ta chèn có thứ tự
        ChenNhanVien(list, nv);
    }
    // tăng số lượng sinh viên sau khi chèn;
    list.CountNV++;
}

void DeleteNV(listNV& list)
{

    char manv[50];
    cout << "Mã nhân viên: "; cin >> manv;

    
    int pos = SearchNhanVien(list, manv);
    if(pos == -1 ) return;
    for (int i = 0; i < list.CountNV; i++)
    {
        if (strcmp(list.nodes[i]->MANV, manv) == 0)
        {
            pos = i;
        }
    }

    if(pos = -1){
        cout << "Khong co nhan vien"; return;
    }

    delete list.nodes[pos];

    for (int i = pos; i < list.CountNV - 1; i++) 
    {
        list.nodes[i] = list.nodes[i + 1];
    }

    // Giảm số lượng nhân viên
    list.CountNV--;

    
}

void InNhanVien(listNV list)
{
    for (int i = 0; i < list.CountNV; i++)
    {
        cout << "MaNV" << list.nodes[i]->MANV << "\n";
        cout << "Họ: " << list.nodes[i]->HO << "\n";
        cout << "Ten:" << list.nodes[i]->TEN << "\n";
        cout << "Phai: " << list.nodes[i]->PHAI << "\n";
    }
};



void ChinhSuaNhanVien(listNV& list){
    char manv[50];
    cout << "Mã nhân viên: "; cin >> manv;

    int pos = SearchNhanVien(list, manv);
    if(pos == -1 ) return;
    
    cout << "Thong tin hien tai:" << endl;
    cout << "Mã sinh viên " << list.nodes
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

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    Nhanvien nv;
    listNV danhsach;
    NhapNhanVien(danhsach);
    InNhanVien(danhsach);
};