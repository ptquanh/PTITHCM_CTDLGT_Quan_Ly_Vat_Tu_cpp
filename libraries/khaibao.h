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
    "1. Thêm vật tư",
    "2. Sửa vật tư",
    "3. Xóa vật tư",
    "4. In danh sách vật tư theo tên tăng dần",
    "5. Thêm nhân viên",
    "6. Sửa nhân viên",
    "7. Xóa nhân viên",
    "8. In danh sách nhân viên tên tăng dần nếu trùng thì họ tăng dần",
    "9. Lập hóa đơn",
    "10. In hóa đơn theo số hóa đơn (SoHD)",
    "11. Thống kê các hóa đơn trong 1 khoảng thời gian",
    "12. In 10 vật tư có doanh thu cao nhất trong 1 khoảng thời gian",
    "13. Thống kê doanh thu của cửa hàng theo từng tháng thuộc 1 năm do user nhập vào"};

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
    "3. Thống kê doanh thu theo từng tháng"};
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
