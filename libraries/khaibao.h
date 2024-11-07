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
#define YeuCauVatTu 4
#define YeuCauNhanVien 4
#define YeuCauHoaDon 2
#define YeuCauThongKe 3
#define SoNut 5
// ================ others ======================
char keyGuides[SoNut][50] = {
    "F1: Them VT",
    "F2: Sua VT",
    "F3: Xoa VT",
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
    "1. Them vat tu",
    "2. Sua vat tu",
    "3. Xoa vat tu",
    "4. In danh sach vat tu theo ten tang dan"};

char MenuNhanVien[YeuCauNhanVien][100] = {
    "1. Them nhan vien",
    "2. Sua nhan vien",
    "3. Xoa nhan vien (theo ma)",
    "4. In danh sach nhan vien ten tang dan neu trung thi ho tang dan"};

char MenuHoaDon[YeuCauHoaDon][100] = {
    "1. Lap hoa don (N/X)",
    "2. In hoa don theo so hoa don (SoHD)"};

char MenuThongKe[YeuCauThongKe][100] = {
    "1. Thong ke cac hoa don trong 1 khoang thoi gian",
    "2. Thong ke 10 vat tu co doanh thu cao nhat trong 1 khoang thoi gian",
    "3. Thong ke doanh thu tung thang thuoc 1 nam do user nhap vao"};

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
    float donGia;
    float VAT;
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
    string loai;   // N or X
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
    float doanhThu;
};