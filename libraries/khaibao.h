#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <conio.h>
#include <windows.h>

using namespace std;
#define MaxNhanVien 500
#define YeuCauChinh 7
#define YeuCauA 4
#define YeucauC 3
#define MAX_VAT_TU 500
bool check = false;
char MenuChinh[YeuCauChinh][50] = {
    "1. Nhập vật tư", // sửa ở đây luôn à
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

char MenuNhanVien[YeucauC][50] =
{
    "1. Thêm nhân viên",
    "2. Xóa nhân viên(theo mã)",
    "3. Chỉnh sửa nhân viên"
};


struct vatTu
{
    char MAVT[11];
    string TENVT;
    string DVT;
    int soLuongTon;
};
struct nodeVatTu
{
    vatTu vt;
    int key;
    int bf;
    nodeVatTu *left, *right;
};
typedef nodeVatTu *treeVatTu;
//
struct CT_HOADON
{
    char MAVT[10];
    int soLuong;
    float donGia;
    float VAT;
};
struct Node
{
    CT_HOADON cthddata;
    Node *next;
};
typedef Node *PTR;

struct HOADON
{
    char SoHD[20];
    char Loai; // N or X
    int day, year, month;
    Node *PTR;
};


struct Nhanvien
{
    char MANV[50]; // mã nhân viên
    string HO;   // họ nhân viên
    string TEN;  // tên nhân viên
    char PHAI[10]; // Giới tính nhân viên
    HOADON *dshd = nullptr; // danh sách hóa đơn, do nhân viên ban đầu nhập vô không có hóa đơn
};
struct listNV{
    int CountNV = 0;
    Nhanvien* nodes [MaxNhanVien];
};
