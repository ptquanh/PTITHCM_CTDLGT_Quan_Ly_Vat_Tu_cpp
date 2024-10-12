#include "../libraries/khaibao.h"
#define filePath_Nv "../databases/ds_NhanVien.txt"
// void readFile_dsNhanVien(dsNhanVien ds_nv)
// {
//     ifstream filein;
//     filein.open(filePath_Nv, ios_base::in);
//     if (!filein.is_open())
//     {
//         cout << "Khong the mo file ds_VatTu.txt" << endl;
//         return;
//     }
//     else
//     {
//         cout << "da mo" << endl;
//     }

//     while (filein.eof() != true)
//     {
//         ds_nv.nodes[ds_nv.CountNV] = new nhanVien;
//         getline(filein, ds_nv.nodes[ds_nv.CountNV]->MANV, ',');
//         getline(filein, ds_nv.nodes[ds_nv.CountNV]->HO, ',');
//         getline(filein, ds_nv.nodes[ds_nv.CountNV]->TEN, ',');
//         filein >> ds_nv.nodes[ds_nv.CountNV]->PHAI;
//         filein.ignore();
//         // cout << ds_nv.nodes[ds_nv.CountNV]->MANV << endl;
//         // cout << ds_nv.nodes[ds_nv.CountNV]->HO << endl;
//         // cout << ds_nv.nodes[ds_nv.CountNV]->TEN << endl;
//         // cout << ds_nv.nodes[ds_nv.CountNV]->PHAI << endl;
//         ds_nv.CountNV++;
//     }
//     filein.close();
// }
// void writeNodeToFile(treeVatTu node, ofstream &fileout)
// {
//     // ofstream fileout;
//     // fileout.open(filePath, ios_base::trunc);
//     if (node == nullptr)
//         return;

//     // Ghi các node bên trái
//     writeNodeToFile(node->left, fileout);

//     // Ghi dữ liệu của node hiện tại vào file
//     fileout << node->data_vt.MAVT << ","
//             << node->data_vt.TENVT << ","
//             << node->data_vt.DVT << ","
//             << node->data_vt.soLuongTon << endl;

//     // Ghi các node bên phải
//     writeNodeToFile(node->right, fileout);
// }
// void writeFile_dsVatTu(treeVatTu root)
// {
//     ofstream fileout;
//     fileout.open(filePath_Nv, ios_base::out); // Sử dụng filePath đã định nghĩa

//     if (!fileout.is_open())
//     {
//         cout << "Khong the mo file de ghi ds_VatTu.txt" << endl;
//         return;
//     }

//     // Hàm đệ quy duyệt cây theo thứ tự giữa (In-Order Traversal)
//     if (root == nullptr)
//     {
//         cout << "Cay nhap lieu rong, khong co du lieu de ghi." << endl;
//         return;
//     }

//     // Ghi toàn bộ cây bắt đầu từ gốc
//     if (root != NULL)
//     {
//         cout << endl;
//     }
//     writeNodeToFile(root, fileout);
//     fileout.close();
// }
bool NhanVienEmpty(dsNhanVien list)
{
    if (list.CountNV != 0)
    {
        return false;
    }
    else
    {
        cout << "Danh sách nhân viên rỗng!" << endl;
        return true;
    }
}

int SearchNhanVien(dsNhanVien list, string manv)
{
    int pos = -1;
    for (int i = 0; i < list.CountNV; i++)
    {
        if (list.nodes[i]->MANV == manv)
        {
            pos = i;
        }
    }

    if (pos = -1)
    {
        cout << "Không tìm thấy nhân viên" << endl;
        return -1;
    }

    return pos;
}

bool CheckMANV(dsNhanVien &list,string maso)
{
    for (int i = 0; i < list.CountNV; i++)
    {
        if (list.nodes[i]->MANV == maso)
        {
            return true;
        }
    }
    return false;
}

void ChenNhanVien(dsNhanVien &list, nhanVien *nhanvienmoi)
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
        if (nhanvienmoi->TEN == list.nodes[pos]->TEN)
            ;
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

void NhapNhanVien(dsNhanVien &list)
{
    if (list.CountNV >= MaxNhanVien)
    {
        cout << "so luong nv toi da" << "\n";
        return;
    }

    nhanVien *nv = new nhanVien();

    do
    {
        cout << "Nhập mã nhân viên (10 ký tự):";
        cin >> nv->MANV;
        if (CheckMANV(list, nv->MANV))
        {
            cout << "Mã đã tồn tại, vui lòng nhập mã khác" << endl;
        }
    } while (nv->MANV.length() == 0 || CheckMANV(list, nv->MANV));

    do
    {
        cout << "nhap ho nv ";
        cin >> nv->HO;
    } while (nv->HO.empty());

    // nhập tên
    do
    {
        cout << "nhap ten nv ";
        getline(cin, nv->TEN);
    } while (nv->TEN.empty());

    // nhập giới tính
    do
    {
        cout << "Nhập giới tính (nam hoặc nu)";
        cin >> nv->PHAI;
        // cout << nv->PHAI;
        if (nv->PHAI == "nam")
            break;
        if (nv->PHAI == "nu")
            break;
    } while (true);
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

void DeleteNV(dsNhanVien &list)
{

    if (NhanVienEmpty(list))
        return;

    char manv[50];
    cout << "Mã nhân viên: ";
    cin >> manv;

    int pos = SearchNhanVien(list, manv);
    if (pos == -1)
        return;
    for (int i = 0; i < list.CountNV; i++)
    {
        if (list.nodes[i]->MANV == manv)
        {
            pos = i;
        }
    }

    if (pos = -1)
    {
        cout << "Không có nhân viên" << endl;
        return;
    }

    delete list.nodes[pos];

    for (int i = pos; i < list.CountNV - 1; i++)
    {
        list.nodes[i] = list.nodes[i + 1];
    }

    // Giảm số lượng nhân viên
    list.CountNV--;
}

void ChinhSuaNhanVien(dsNhanVien &list)
{

    if (NhanVienEmpty(list))
        return;

    char manv[50];
    cout << "Mã nhân viên: ";
    cin >> manv;

    int pos = SearchNhanVien(list, manv);
    if (pos == -1)
        return;

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

    cout << "Nhập giới tính sinh viên mới(nam/nữ)(Enter để giữ nguyên): ";
    string newPHAI;
    do
    {
        getline(cin, newPHAI);
        if (newPHAI == "nam" || newPHAI == "nữ")
        {
            list.nodes[pos]->PHAI = newPHAI;
            break;
        }
    } while (!newPHAI.empty());

    cout << "Da cap nhat thong tin vat tu." << endl;
}

void DeleteDSNV(dsNhanVien &list)
{
    if (NhanVienEmpty(list))
        return;
    list.CountNV = 0;
}

void InNhanVien(dsNhanVien list)
{
    if (NhanVienEmpty(list))
        return;

    for (int i = 0; i < list.CountNV; i++)
    {
        cout << "Mã nhân viên:" << list.nodes[i]->MANV << endl;
        cout << "Họ nhân viên: " << list.nodes[i]->HO << endl;
        cout << "Tên nhân viên:" << list.nodes[i]->TEN << endl;
        cout << "Giới tính: " << list.nodes[i]->PHAI << endl;
    }
};

// int main()
// {
//     SetConsoleOutputCP(CP_UTF8);
//     nhanVien nv;
//     dsNhanVien danhsach;
//     // readFile_dsNhanVien(danhsach);
//     int choice;
//     do
//     {
//         cin >> choice;
//         switch (choice)
//         {
//         case 1:
//             NhapNhanVien(danhsach);
//             break;
//         case 2:
//             InNhanVien(danhsach);
//             break;
//         case 3:
//             if(CheckMANV(danhsach,"nv1")) cout << "ton tai";
//             else cout << "ko ton tai";
//             break;
//         }
//     } while (1);
// };
