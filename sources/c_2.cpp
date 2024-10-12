#include "../libraries/khaibao.h"
#define filePath_Nv "../databases/ds_NhanVien.txt"
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

bool CheckMANV(dsNhanVien &list, string maso)
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
        nv->MANV.resize(10);
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
        cout << "Nhập giới tính (nam hoặc nữ)";
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

void WriteCTHoaDon(dsChiTietHoaDon *danhsach, ofstream &fileout)
{
    dsChiTietHoaDon *temp = new dsChiTietHoaDon;
    temp = danhsach;
    while (temp != nullptr)
    {
        fileout << "\\\\" << temp->data_cthd.MAVT << "|" << temp->data_cthd.soLuong << "|" << temp->data_cthd.donGia << "|" << temp->data_cthd.VAT << endl;
        temp = temp->next;
    }
}

void WriteHoaDon(dsHoaDon *danhsach, ofstream &fileout)
{
    dsHoaDon *temp = new dsHoaDon;
    temp = danhsach;
    while (temp != nullptr)
    {
        fileout << temp->data_hd.SoHD << "|" << temp->data_hd.loai << "|" << temp->data_hd.day << "|" << temp->data_hd.month << "|" << temp->data_hd.year << "\\\\" << endl;
        WriteCTHoaDon(danhsach->data_hd.ptr_DSCTHD, fileout);
        temp = temp->next;
    }
}

void WriteNhanVien(dsNhanVien danhsach)
{
    ofstream fileout;
    fileout.open("ds_NhanVien.txt", ios::out);
    if (!fileout.is_open())
    {
        cout << "Không thể mở file" << endl;
    }
    for (int i = 0; i < danhsach.CountNV; i++)
    {
        fileout << danhsach.nodes[i]->MANV << "|" << danhsach.nodes[i]->HO << "|" << danhsach.nodes[i]->TEN << "|" << danhsach.nodes[i]->PHAI << "\\" << endl;
        WriteHoaDon(danhsach.nodes[i]->dshd, fileout);
        fileout << endl;
    }
}
void readFile_dsNhanVien(dsNhanVien &ds_nv)
{
    ifstream filein;
    filein.open(filePath_Nv, ios_base::in);

    if (!filein.is_open())
    {
        cout << "Không thể mở file ds_NhanVien.txt" << endl;
        return;
    }
    else
    {
        cout << "Đã mở file ds_NhanVien.txt" << endl;
    }

    // Đọc từng dòng từ tệp cho đến khi hết dữ liệu
    string line;
    while (getline(filein, line))
    {
        if (line.empty()) // Bỏ qua dòng trống
            continue;

        // Tạo đối tượng nhân viên mới
        ds_nv.nodes[ds_nv.CountNV] = new nhanVien;
        nhanVien *nv = ds_nv.nodes[ds_nv.CountNV];

        stringstream ss(line);
        // string temp;

        // Đọc thông tin của nhân viên
        getline(ss, nv->MANV, '|');
        getline(ss, nv->HO, '|');
        getline(ss, nv->TEN, '|');
        getline(ss, nv->PHAI, '\\'); // Kết thúc nhân viên bằng dấu '\\'

        // Cấp phát bộ nhớ cho dshd (hóa đơn) của nhân viên nếu có
        nv->dshd = new dsHoaDon;

        // Đọc tiếp thông tin hóa đơn của nhân viên
        // if (getline(ss, temp, '|')) // Kiểm tra xem có hóa đơn không
        // {
            getline(ss, nv->dshd->data_hd.SoHD, '|');
            getline(ss, nv->dshd->data_hd.loai, '|');
            string str_day, str_month, str_year;
            getline(ss, str_day, '|');   // Ngày lập hóa đơn
            getline(ss, str_month, '|'); // Tháng lập hóa đơn (giữ nguyên '04')
            getline(ss, str_year); // Năm lập hóa đơn

            // Chuyển đổi ngày/tháng/năm thành số nguyên nếu cần cho tính toán
            nv->dshd->data_hd.day = stoi(str_day);
            nv->dshd->data_hd.month = stoi(str_month);
            nv->dshd->data_hd.year = stoi(str_year);

            // }

            cout << ds_nv.nodes[ds_nv.CountNV]->MANV << endl;
            cout << ds_nv.nodes[ds_nv.CountNV]->HO << endl;
            cout << ds_nv.nodes[ds_nv.CountNV]->TEN << endl;
            cout << ds_nv.nodes[ds_nv.CountNV]->PHAI << endl;
            cout << ds_nv.nodes[ds_nv.CountNV]->dshd->data_hd.SoHD << endl;
            cout << ds_nv.nodes[ds_nv.CountNV]->dshd->data_hd.loai << endl;
            cout << str_day << endl;
            cout << str_month << endl;
            cout << str_year;
            // Tăng số lượng nhân viên
            ds_nv.CountNV++;
    }

    filein.close();
}

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
//         getline(filein, ds_nv.nodes[ds_nv.CountNV]->MANV, '|');
//         getline(filein, ds_nv.nodes[ds_nv.CountNV]->HO, '|');
//         getline(filein, ds_nv.nodes[ds_nv.CountNV]->TEN, '|');
//         getline(filein, ds_nv.nodes[ds_nv.CountNV]->PHAI, '\\');
//         getline(filein, ds_nv.nodes[ds_nv.CountNV]->dshd->data_hd.SoHD, '|');
//         getline(filein, ds_nv.nodes[ds_nv.CountNV]->dshd->data_hd.loai, '|');
//         filein >> ds_nv.nodes[ds_nv.CountNV]->dshd->data_hd.day;
//         // filein >> ds_nv.nodes[ds_nv.CountNV]->dshd->data_hd.month;
//         // filein >> ds_nv.nodes[ds_nv.CountNV]->dshd->data_hd.year;
//         // getline(filein, ds_nv.nodes[ds_nv.CountNV]->dshd->data_hd.day, '|');

//         filein.ignore();
//         // cout << ds_nv.nodes[ds_nv.CountNV]->MANV << endl;
//         // cout << ds_nv.nodes[ds_nv.CountNV]->HO << endl;
//         // cout << ds_nv.nodes[ds_nv.CountNV]->TEN << endl;
//         // cout << ds_nv.nodes[ds_nv.CountNV]->PHAI << endl;
//         cout << ds_nv.nodes[ds_nv.CountNV]->dshd->data_hd.SoHD << endl;
//         cout << ds_nv.nodes[ds_nv.CountNV]->dshd->data_hd.loai << endl;
//         cout << ds_nv.nodes[ds_nv.CountNV]->dshd->data_hd.day << endl;
//         // cout << ds_nv.nodes[ds_nv.CountNV]->dshd->data_hd.month << endl;
//         // cout << ds_nv.nodes[ds_nv.CountNV]->dshd->data_hd.year << endl;
//         ds_nv.CountNV++;
//     }
//     filein.close();
// }

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    nhanVien nv;
    dsNhanVien danhsach;
    readFile_dsNhanVien(danhsach);
    int choice;
    do
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            NhapNhanVien(danhsach);
            break;
        case 2:
            InNhanVien(danhsach);
            break;
        case 3:
            if (CheckMANV(danhsach, "nv1"))
                cout << "ton tai";
            else
                cout << "ko ton tai";
            break;
        }
    } while (1);
};