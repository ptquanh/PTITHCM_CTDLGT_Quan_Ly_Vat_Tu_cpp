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
#define filePath_VT "./databases/ds_VatTu.txt"
#define filePath_NV "./databases/ds_NhanVien.txt"
#define MaxNhanVien 500
#define YeuCauChinh 13
#define YeuCauVatTu 4
#define YeuCauNhanVien 4
#define YeuCauHoaDon 2
#define YeuCauThongKe 3
#define MAX_VAT_TU 500
// ================ MENU ========================
char MenuChinh[YeuCauChinh][100] = {
    "1. Them vat tu",
    "2. Sua vat tu",
    "3. Xoa vat tu",
    "4. In danh sach vat tu theo ten tang dan",
    "5. Them nhan vien",
    "6. Sua nhan vien",
    "7. Xoa nhan vien",
    "8. In danh sach nhan vien ten tang dan neu trung thi ho tang dan",
    "9. Lap hoa don",
    "10. In hoa don theo so hoa don (SoHD)",
    "11. Thong ke cac hoa don trong 1 khoang thoi gian",
    "12. In 10 vat tu co doanh thu cao nhat trong 1 khoang thoi gian",
    "13. Thong ke doanh thu cua cua hang theo tung thang thuoc 1 nam do user nhap vao"};

char MenuVatTu[YeuCauVatTu][50] = {
    "1. Nhap vat tu",
    "2. In vat tu ton kho",
    "3. Sua vat tu",
    "4. Xoa vat tu"};

char MenuNhanVien[YeuCauNhanVien][50] = {
    "1. Them nhan vien",
    "2. Xoa nhan vien (theo ma)",
    "3. Chinh sua nhan vien",
    "4. In ra danh sach nhan vien"};

char MenuHoaDon[YeuCauHoaDon][50] = {
    "1. Lap hoa don",
    "2. In hoa don"};

char MenuThongKe[YeuCauThongKe][50] = {
    "1. Thong ke hoa don theo quang thoi gian",
    "2. Thong ke 10 vat tu doanh thu cao nhat",
    "3. Thong ke doanh thu theo tung thang"};

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
    char loai;   // N or X
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
