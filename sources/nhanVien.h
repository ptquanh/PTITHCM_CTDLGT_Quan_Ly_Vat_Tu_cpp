#pragma once
#include "vatTu.h"

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
    for (int i = 0; i < list.CountNV; i++)
    {
        if (list.nodes[i]->MANV == manv)
        {
            return i;
        }
    }
    cout << "Không tìm thấy nhân viên!" << endl;

    return -1;
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
    bool hasError;
    if (list.CountNV >= MaxNhanVien)
    {
        cout << "so luong nv toi da" << "\n";
        return;
    }

    nhanVien *nv = new nhanVien();

    do
    {
        cout << "Nhập mã nhân viên (10 ký tự):" ;
        cin >> nv->MANV;

        if (CheckMANV(list, nv->MANV)){
            cout << "Mã đã tồn tại, vui lòng nhập mã khác" << endl; continue;
        }

        if (nv->MANV.find_first_not_of(' ') == string::npos){
            cout << "Lỗi: Chuỗi không được rỗng hoặc chỉ chứa khoảng trắng" << endl; continue;
        }
        if(nv->MANV.size() > 10){
            nv->MANV.resize(10);
        }
    } while (nv->MANV.size() == 0 || CheckMANV(list, nv->MANV));

    do
    {
        cout << "Nhập họ nhân viên: ";
        cin >> nv->HO;
        nv->HO = normalizeString(nv->HO, hasError);
    } while (nv->HO.size() == 0);

    // nhập tên
    do
    {
        cout << "Nhập tên nhân viên: ";
        cin.ignore();
        getline(cin, nv->TEN);
        nv->TEN = normalizeString(nv->TEN, hasError);
    } while (nv->TEN.size() == 0);

    // nhập giới tính
    do
    {
        int inputPhai;
        cout << "Nhập giới tính ( 1 là nam || 0 là nữ): ";
        cin >> inputPhai;
        // cout << nv->PHAI;
        if (inputPhai == 1){
            nv->PHAI = "Nam";
            break;
        }
        if (inputPhai == 0){
            nv->PHAI = "Nữ";
            break;
        }
        if(inputPhai != 1 || inputPhai != 0){
            cout << "Lỗi: Giới tính không hợp lệ!" << endl; continue;
        }
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

    string manv;
    cout << "Mã nhân viên: ";
    cin >> manv;

    int pos = SearchNhanVien(list, manv);
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
        getline(cin,newPHAI);
        if(newPHAI == "nam" || newPHAI == "nữ"){
            list.nodes[pos]->PHAI = newPHAI;
            break;
        }
    }while(!newPHAI.empty());
    

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
        cout << "Mã nhân viên: " << list.nodes[i]->MANV << endl;
        cout << "Họ nhân viên: " << list.nodes[i]->HO << endl;
        cout << "Tên nhân viên: " << list.nodes[i]->TEN << endl;
        cout << "Giới tính: " << list.nodes[i]->PHAI << endl;
    }
};


void WriteCTHoaDon(dsChiTietHoaDon* danhsach, ofstream& fileout) {
    dsChiTietHoaDon* temp = danhsach;  // Không cần khởi tạo lại với new
    while (temp != nullptr) {
        fileout << temp->data_cthd.MAVT <<      "|" 
                 << temp->data_cthd.soLuong <<  "|" 
                 << temp->data_cthd.donGia <<   "|" 
                 << temp->data_cthd.VAT << endl;
        temp = temp->next;
    }
}

void WriteHoaDon(dsHoaDon* danhsach, ofstream& fileout) {
    dsHoaDon* temp = danhsach;  // Không cần khởi tạo lại với new
    while (temp != nullptr) {
        fileout << temp->data_hd.SoHD <<    "|" 
                 << temp->data_hd.loai <<   "|" 
                 << temp->data_hd.day <<    "|" 
                 << temp->data_hd.month <<  "|" 
                 << temp->data_hd.year << "\\\\" << endl;
        WriteCTHoaDon(temp->data_hd.firstCTHD, fileout); // Sửa ở đây
        temp = temp->next; 
    }
}
void WriteNhanVien(dsNhanVien danhsach) {
    ofstream fileout; 
    fileout.open(filePath_NV, ios_base::out);
    if (!fileout.is_open()) {
        cout << "Không thể mở file" << endl;
        return;
    }
    
    if (danhsach.CountNV == 0) {
        cout << "Danh sách nhân viên trống!" << endl;
        fileout.close();
        return;
    }
    for (int i = 0; i < danhsach.CountNV; i++) {
        fileout << danhsach.nodes[i]->MANV <<   "|" 
                 << danhsach.nodes[i]->HO <<    "|" 
                 << danhsach.nodes[i]->TEN <<   "|" 
                 << danhsach.nodes[i]->PHAI << "\\" << endl;
        cout << "Đã ghi nhân viên thứ " << i + 1 << endl; // Thông báo debug
        WriteHoaDon(danhsach.nodes[i]->firstDSHD, fileout);
        fileout << endl;
    }

    fileout.close(); // Đảm bảo file được đóng
}


void readFile_dsNhanVien(dsNhanVien ds_nv)
{
    ifstream filein;
    filein.open(filePath_NV, ios_base::in);
    if (!filein.is_open())
    {
        cout << "Khong the mo file ds_VatTu.txt" << endl;
        return;
    }
    else
    {
        cout << "da mo" << endl;
    }

    while (filein.eof() != true)
    {
        ds_nv.nodes[ds_nv.CountNV] = new nhanVien;

        getline(filein, ds_nv.nodes[ds_nv.CountNV]->MANV, ',');
        getline(filein, ds_nv.nodes[ds_nv.CountNV]->HO, ',');
        getline(filein, ds_nv.nodes[ds_nv.CountNV]->TEN, ',');
        getline(filein, ds_nv.nodes[ds_nv.CountNV]->PHAI, '\\');
        getline(filein, ds_nv.nodes[ds_nv.CountNV]->firstDSHD->data_hd.SoHD, '|');
        // getline(filein, ds_nv.nodes[ds_nv.CountNV]->firstDSHD->data_hd.loai, '|');
        // getline(filein, ds_nv.nodes[ds_nv.CountNV]->firstDSHD->data_hd.day, '|');

        filein.ignore();
        cout << ds_nv.nodes[ds_nv.CountNV]->MANV << endl;
        cout << ds_nv.nodes[ds_nv.CountNV]->HO << endl;
        cout << ds_nv.nodes[ds_nv.CountNV]->TEN << endl;
        cout << ds_nv.nodes[ds_nv.CountNV]->PHAI << endl;
        cout << ds_nv.nodes[ds_nv.CountNV]->firstDSHD->data_hd.SoHD << endl;
        cout <<ds_nv.nodes[ds_nv.CountNV]->firstDSHD->data_hd.loai << endl;
        ds_nv.CountNV++;
    }
    filein.close();
}





