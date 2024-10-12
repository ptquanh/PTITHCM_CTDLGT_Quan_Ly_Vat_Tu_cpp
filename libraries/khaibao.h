#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <conio.h>
#include <windows.h>
#include <fstream>
using namespace std;
#pragma once

#define MaxNhanVien 500
#define YeuCauChinh 5
#define YeuCauVatTu 4
#define YeuCauNhanVien 4
#define YeuCauHoaDon 2
#define YeuCauThongKe 3
#define MAX_VAT_TU 500
bool check = false;
// ================ MENU ========================
char MenuChinh[YeuCauChinh][50] = {
    "1. Nhập vật tư", // sửa ở đây luôn à
    "2. In danh sách vật tư tồn kho",
    "3. Quản lý nhân viên",
    "4. Quản lý hóa đơn",
    "5. Thống kê"};

char MenuVatTu[YeuCauVatTu][50] = {
    "1. Nhập vật tư",
    "2. In vật tư tồn kho",
    "3. Sửa vật tư",
    "4. Xóa vật tư"};

char MenuNhanVien[YeuCauNhanVien][50] = {
    "1. Thêm nhân viên",
    "2. Xóa nhân viên(theo mã)",
    "3. Chỉnh sửa nhân viên",
    "4. In ra danh sách nhân viên"};

char MenuHoaDon[YeuCauHoaDon][50] = {
    "1. Lập hóa đơn",
    "2. In hóa đơn"};

char MenuThongKe[YeuCauThongKe][50] = {
    "1. Thống kê hóa đơn theo quãng thời gian",
    "2. Thống kê 10 vật tư doanh thu cao nhất",
    "3. Thống kê doanh thu theo từng tháng"
};
// =============== danh sach vat tu =================
// ======= cay nhi phan tim kiem can bang ===========
struct nodeVatTu
{
    char MAVT[11];
    string TENVT;
    string DVT;
    int soLuongTon;
};
struct dsVatTu
{
    nodeVatTu data_vt;
    int height;
    int bf;
    dsVatTu *left, *right;
};
typedef dsVatTu *treeVatTu;
// ============= danh sach chi tiet hoa don ===========
// ============= danh sach lien ket don ===============
struct nodeChiTietHoaDon
{
    char MAVT[10];
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
    string SoHD;
    string Loai; // N or X
    int day, month, year;
    dsChiTietHoaDon *ptr_DSCTHD;
};
struct dsHoaDon
{
    nodeHoaDon data_hd;
    dsHoaDon *next;
};
typedef dsHoaDon *ptr_DSHD;
// ============= danh sach nhan vien ===============
// ================ mang con tro ===================
struct Nhanvien
{
    string MANV;         // mã nhân viên
    string HO;              // họ nhân viên
    string TEN;             // tên nhân viên
    string PHAI;          // Giới tính nhân viên
    dsHoaDon *dshd = nullptr; // danh sách hóa đơn, do nhân viên ban đầu nhập vô không có hóa đơn
};
struct dsNhanVien
{
    Nhanvien *nodes[MaxNhanVien];
    int CountNV = 0;
};
