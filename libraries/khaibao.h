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
#include <math.h>
using namespace std;
#define filePath_VT "../databases/ds_VatTu.txt"
#define filePath_NV "../databases/ds_NhanVien.txt"
#define MaxNhanVien 500
#define YeuCauChinh 5
#define YeuCauVatTu 2
#define YeuCauNhanVien 2
#define YeuCauHoaDon 2
#define YeuCauThongKe 3
#define SoNut 5
// ================ others ======================
char keyGuides[SoNut][50] = {
    "F3: Them VT",
    "F4: Sua VT",
    "DEL: Xoa VT",
    "F5: Tim kiem",
    "ESC: Thoat"};
// ================ MENU ========================
char MenuChinh[YeuCauChinh][100] = {
    "MENU CHINH",
    "VAT TU",
    "NHAN VIEN",
    "HOA DON",
    "THONG KE"};

char MenuVatTu[YeuCauVatTu][100] = {
    "Cap nhat vat tu",
    "In danh sach vat tu theo ten"};

char MenuNhanVien[YeuCauNhanVien][100] = {
    "Cap nhat nhan vien",
    "In danh sach nhan vien theo ten"};

char MenuHoaDon[YeuCauHoaDon][100] = {
    "Lap hoa don (N/X)",
    "In hoa don theo so hoa don"};

char MenuThongKe[YeuCauThongKe][100] = {
    "Hoa don trong 1 khoang thoi gian",
    "Top 10 vat tu doanh thu cao nhat",
    "Doanh thu tung thang thuoc 1 nam"};

// =============== danh sach vat tu =================
// ======= cay nhi phan tim kiem can bang ===========
struct nodeVatTu
{
    string MAVT; // max C10
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
    int donGia;
    int VAT;
    float triGia;
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

    string SoHD; // max C20
    string loai; // N or X
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
    int countNV = 0;
};
// ================== khac ======================
time_t to_time_t(int day, int month, int year)
{
    struct tm t = {0};
    t.tm_mday = day;
    t.tm_mon = month - 1;    // Tháng được lưu trong mảng với index từ 0 đến 11
    t.tm_year = year - 1900; // Năm được tính từ 1900
    return mktime(&t);
}

struct doanhThuVatTu
{
    string MAVT;
    string TENVT;
    int soluong;
    float doanhThu;
};