#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MaxNhanVien 500
#define YeuCauChinh 7
#define YeuCauA 4
#define YeucauC 3
#define MAX_VAT_TU 500
// bool check = false;
// ================ MENU ========================
char MenuChinh[YeuCauChinh][50] = {
    "1. Nhập vật tư",
    "2. In danh sách vật tư tồn kho",
    "3. Nhập nhân viên",
    "4. In ra danh sách nhân viên",
    "5. Lập hóa đơn",
    "6. In hóa đơn",
    "7. Thống kê các hóa đơn"};

char MenuA[YeuCauA][50] = {
    "1. nhap vat tu",
    "2. in ds vt ton kho",
    "3. sua vt",
    "4. xoa vt"};

char MenuNhanVien[YeucauC][50] = {
    "1. Thêm nhân viên",
    "2. Xóa nhân viên(theo mã)",
    "3. Chỉnh sửa nhân viên"};
// =============== danh sach vat tu =================
// ======= cay nhi phan tim kiem can bang ===========
struct nodeVatTu
{
    string MAVT; //max C10
    string TENVT;
    string DVT;
    int soLuongTon;
};
struct dsVatTu
{
    nodeVatTu data_vt;
    int height;
    dsVatTu *left, *right;
};
typedef dsVatTu *treeVatTu;
// ============= danh sach chi tiet hoa don ===========
// ============= danh sach lien ket don ===============
struct nodeChiTietHoaDon
{
    string MAVT;
    int soLuong;
    float donGia;
    float VAT;
};
struct dsChiTietHoaDon
{
    nodeChiTietHoaDon data_cthd;
    dsChiTietHoaDon *next;
};
typedef dsChiTietHoaDon *ptr_DSCTHD;
// ========== danh sach hoa don ==================
// ============= danh sach lien ket don ==========

struct nodeHoaDon
{
    string SoHD; //max C20
    char loai; // N or X
    int day, month, year;
    ptr_DSCTHD firstCTHD = nullptr;
};
struct dsHoaDon
{
    nodeHoaDon data_hd;
    dsHoaDon *next;
};
typedef dsHoaDon *ptr_DSHD;
// ============= danh sach nhan vien ===============
// ================ mang con tro ===================
struct nhanVien
{
    string MANV;       
    string HO;
    string TEN;
    string PHAI;
    ptr_DSHD firstDSHD = nullptr;
};
struct dsNhanVien
{
    nhanVien *nodes[MaxNhanVien];
    int CountNV = 0;
};
