#include "../libraries/khaibao.h"
using namespace std;

// ----------------------------

bool NhanVienEmpty(listNV list){
    if(list.CountNV != 0){
        return false;
    }else{
        cout << "Danh sách nhân viên rỗng!" << endl;
        return true;
    }
}


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
        cout << "Không tìm thấy nhân viên" << endl; return -1;
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
        // compare = strcmp(nhanvienmoi->TEN, list.nodes[pos]->TEN);
        // so sánh tên
        if (nhanvienmoi->TEN < list.nodes[pos]->TEN)
        {
            break;
        }

        // so sánh họ
        if (nhanvienmoi->TEN == list.nodes[pos]->TEN);
        {
            // compare = strcmp(nhanvienmoi->HO, list.nodes[pos]->HO);
            // nếu họ nhỏ hơn thì không cần tăng tiếp nữa
            if (nhanvienmoi->HO < list.nodes[pos]->HO)
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
        cout << "Nhập mã nhân viên ";
        cin >> nv->MANV;
        if (CheckMANV(list, nv->MANV))
        {
            cout << "Mã đã tồn tại, vui lòng nhập mã khác" << endl;
        }
    } while (strlen(nv->MANV) == 0 || CheckMANV(list, nv->MANV));

    do
    {
        cout << "nhap ho nv ";
        cin >> nv->HO;
    } while (nv->HO.empty());

    // nhập tên
    do
    {
        cout << "nhap ten nv ";
        cin >> nv->TEN;
    } while (nv->TEN.empty());

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
    }
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
    
    if(NhanVienEmpty(list)) return;


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





void ChinhSuaNhanVien(listNV& list)
{

    if(NhanVienEmpty(list)) return;

    char manv[50];
    cout << "Mã nhân viên: "; cin >> manv;

    int pos = SearchNhanVien(list, manv);
    if(pos == -1 ) return;
    
    cout << "Thông tin hiện tại: " << endl;
    cout << "Mã nhân viên " << list.nodes[pos]->MANV;
    cout << "Nhập họ sinh viên mới(Enter để giữ nguyên): ";
    string newHO;
    getline(cin, newHO);
    if (!newHO.empty())
        list.nodes[pos]->HO = newHO;
    
    cout << "Nhập tên sinh viên mới(Enter để giữ nguyên): ";
    string newTEN;
    getline(cin, newTEN);
    if (!newTEN.empty())
        list.nodes[pos]->TEN = newTEN;

    cout << "Nhập giới tính sinh viên mới(Enter để giữ nguyên): ";
    string newPHAI;
    getline(cin, newPHAI);
    if (!newPHAI.empty())
        strcpy(list.nodes[pos]->PHAI, "newPHAI");

    cout << "Da cap nhat thong tin vat tu." << endl;
   
}


void DeleteDSNV(listNV& list){
    if(NhanVienEmpty(list)) return;
    list.CountNV = 0;
}

void InNhanVien(listNV list)
{
    if(NhanVienEmpty(list)) return;

    for (int i = 0; i < list.CountNV; i++)
    {
        cout << "Mã nhân viên:" << list.nodes[i]->MANV << endl;
        cout << "Họ nhân viên: " << list.nodes[i]->HO << endl;
        cout << "Tên nhân viên:" << list.nodes[i]->TEN << endl;
        cout << "Giới tính: " << list.nodes[i]->PHAI << endl;
    }
};


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    Nhanvien nv;
    listNV danhsach;
    NhapNhanVien(danhsach);
    InNhanVien(danhsach);
};
