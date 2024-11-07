#include "../libraries/khaibao.h"

#define MAX_VATTU 1000

struct DoanhThuVatTu
{
    std::string MAVT;
    float doanhThu;
};

time_t to_time_t(int day, int month, int year)
{
    struct tm t = {0};
    t.tm_mday = day;
    t.tm_mon = month - 1;    // Tháng được lưu trong mảng với index từ 0 đến 11
    t.tm_year = year - 1900; // Năm được tính từ 1900
    return mktime(&t);
}

int Partition(DoanhThuVatTu arr[], int low, int high)
{
    float pivot = arr[high].doanhThu; // Chọn pivot ở cuối
    int i = (low - 1);
    for (int j = low; j < high; j++)
    {
        if (arr[j].doanhThu > pivot) // Đưa những vật tư doanh thu cao lên đầu mảng
        {
            i++;
            DoanhThuVatTu temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    DoanhThuVatTu temp = arr[i + 1]; // Đưa pivot cuối lên vị trí mà nó nhỏ hơn tất cả phần tử trước nó
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}
void QuickSort(DoanhThuVatTu arr[], int low, int high)
{
    if (low < high)
    {
        int pi = Partition(arr, low, high); // Thực hiện phân chia từ low đến high ở vị trí pivot
        QuickSort(arr, low, pi - 1);        // Đệ quy sắp xếp bên trái
        QuickSort(arr, pi + 1, high);       // Đệ quy sắp xếp bên phải
    }
}

float TinhToanChiPhiCuaHoaDon(ptr_DSCTHD ct)
{
    float price = 0;
    while (ct != nullptr) // duyệt qua từng vật tư trong hóa đơn
    {
        price += ct->data_cthd.soLuong * ct->data_cthd.donGia * (1 - ct->data_cthd.VAT / 100);
        ct = ct->next;
    }
    return price;
}

void TinhToanDoanhThu(ptr_DSCTHD ct, DoanhThuVatTu doanhThu[], int &countVatTu, char loai)
{
    while (ct != nullptr)
    {
        bool found = false;
        for (int j = 0; j < countVatTu; ++j) // Kiểm tra xem MAVT này đã có tồn tại trong mảng hay chưa
        {
            if (doanhThu[j].MAVT == ct->data_cthd.MAVT) // Nếu tìm thấy vật tư đã tồn tại trong mảng
            {
                if (loai == 'X')
                {
                    doanhThu[j].doanhThu += ct->data_cthd.soLuong * ct->data_cthd.donGia * (1 + ct->data_cthd.VAT / 100);
                }
                else if (loai == 'N')
                {
                    doanhThu[j].doanhThu -= ct->data_cthd.soLuong * ct->data_cthd.donGia * (1 + ct->data_cthd.VAT / 100);
                }
                found = true; // Đánh dấu đã tìm thấy
                break;
            }
        }
        if (!found) // Nếu chưa tìm thấy
        {
            doanhThu[countVatTu].MAVT = ct->data_cthd.MAVT; // Ghi nhận MAVT mới
            if (loai == 'X')
            {
                doanhThu[countVatTu].doanhThu = ct->data_cthd.soLuong * ct->data_cthd.donGia * (1 + ct->data_cthd.VAT / 100);
            }
            else if (loai == 'N')
            {
                doanhThu[countVatTu].doanhThu = -(ct->data_cthd.soLuong * ct->data_cthd.donGia) * (1 + ct->data_cthd.VAT / 100);
            }
            countVatTu++; // Đưa index tới vị trí tiếp theo của mảng doanh thu
        }
        ct = ct->next;
    }
}

void LayDoanhThu(dsNhanVien &dsnv, DoanhThuVatTu doanhThu[], int &countVatTu, time_t start, time_t end)
{
    for (int i = 0; i < dsnv.CountNV; ++i)
    {
        ptr_DSHD p = dsnv.nodes[i]->firstDSHD;
        while (p != nullptr)
        {
            time_t hdTime = to_time_t(p->data_hd.day, p->data_hd.month, p->data_hd.year);
            if (hdTime >= start && hdTime <= end)
            {
                TinhToanDoanhThu(p->data_hd.firstCTHD, doanhThu, countVatTu, p->data_hd.loai);
            }
            p = p->next;
        }
    }
}

void Top10VTT(int day1, int month1, int year1, int day2, int month2, int year2, dsNhanVien &dsnv)
{
    DoanhThuVatTu doanhThu[MAX_VATTU];
    int countVatTu = 0;

    time_t start = to_time_t(day1, month1, year1);
    time_t end = to_time_t(day2, month2, year2);

    LayDoanhThu(dsnv, doanhThu, countVatTu, start, end);

    QuickSort(doanhThu, 0, countVatTu - 1); // Sắp xếp bằng thuật toán quick sort
    // In Thử thôi
    std::cout << "Top 10 vật tư có doanh thu cao nhất từ " << day1 << "/" << month1 << "/" << year1
              << " đến " << day2 << "/" << month2 << "/" << year2 << ":\n";
    for (int i = 0; i < 10 && i < countVatTu; ++i)
    {
        std::cout << doanhThu[i].MAVT << ": " << doanhThu[i].doanhThu << std::endl;
    }
}

float TinhTriGiaHoaDon(ptr_DSCTHD ct) // Tính trị giá của một hóa đơn
{
    float totalValue = 0;
    while (ct) // duyệt qua  các chi tiết hóa đơn
    {
        totalValue += ct->data_cthd.soLuong * ct->data_cthd.donGia * (1 + ct->data_cthd.VAT / 100);
        ct = ct->next;
    }
    return totalValue;
}

void InThongKeHoaDon(int day1, int month1, int year1, int day2, int month2, int year2, dsNhanVien &dsnv)
{
    time_t start = to_time_t(day1, month1, year1); // thời gian bắt đầu
    time_t end = to_time_t(day2, month2, year2);   // thời gian kết thúc

    std::cout << "Danh sách các hóa đơn từ " << day1 << "/" << month1 << "/" << year1
              << " đến " << day2 << "/" << month2 << "/" << year2 << ":\n";

    // In thử thôi
    for (int i = 0; i < dsnv.CountNV; ++i) // duyệt qua từng nhân viên
    {
        ptr_DSHD p = dsnv.nodes[i]->firstDSHD;
        while (p != nullptr) // duyệt qua từng hóa đơn trong nhân viên
        {
            time_t invoiceTime = to_time_t(p->data_hd.day, p->data_hd.month, p->data_hd.year); // ngày lập hóa đơn
            if (invoiceTime >= start && invoiceTime <= end)                                    // phạm vi thời gian hóa đơn lập
            {
                float trigiahoadon = TinhTriGiaHoaDon(p->data_hd.firstCTHD);
                std::cout << "SoHD: " << p->data_hd.SoHD
                          << ", Ngay lap: " << p->data_hd.day << "/" << p->data_hd.month << "/" << p->data_hd.year
                          << ", Loai: " << p->data_hd.loai
                          << ", Ho ten NV: " << dsnv.nodes[i]->HO << " " << dsnv.nodes[i]->TEN
                          << ", Tri gia: " << trigiahoadon << "\n";
            }
            p = p->next;
        }
    }
}

void DoanhThuNam(dsNhanVien danhsach, int year)
{
    float doanhthuthang[12] = {0};             // chứa doanh thu 12 tháng
    for (int i = 0; i < danhsach.CountNV; i++) // duyệt qua từng nhân viên
    {
        ptr_DSHD hoadon = danhsach.nodes[i]->firstDSHD;
        while (hoadon != nullptr) // duyệt qua hết danh sách hóa đơn của nhân viên[i]
        {
            if (hoadon->data_hd.year == year)
            {
                float trigiahoadon = TinhTriGiaHoaDon(hoadon->data_hd.firstCTHD);
                if (hoadon->data_hd.loai == 'N') // nếu hóa đơn nhập
                {
                    doanhthuthang[hoadon->data_hd.month - 1] -= trigiahoadon;
                }
                else if (hoadon->data_hd.loai == 'X') // nếu hóa đơn xuất
                {
                    doanhthuthang[hoadon->data_hd.month - 1] += trigiahoadon;
                }
            }
            hoadon = hoadon->next;
        }
    }
}

void InThuDoanhThuThang(int year, float doanhthuthang[12]) // In thử thoi
{
    std::cout << "BẢNG THỐNG KÊ DOANH THU NĂM " << year << "\n";
    std::cout << "THÁNG\tDOANH THU\n";
    for (int i = 0; i < 12; ++i)
    {
        std::cout << (i + 1) << "\t" << doanhthuthang[i] << "\n";
    }
}

bool KiemTraNamNhuan(int year) // Kiêm tra năm nhuận
{
    if (year % 4 == 0 && year % 100 != 0)
        return true;
    if (year % 400 == 0)
        return true;
    return false;
}

bool ThoiGianHopLe(int day, int month, int year) // kiểm tra thời gian hợp lệ hay không
{
    int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (day < 1 || month < 1 || month > 12) // Nếu ngày nhập và tháng nhập nằm ngoài giới hạn
        return false;
    if (KiemTraNamNhuan(year) && month == 2) // Nếu tháng nhập và năm nhập rơi vào tháng 2 năm nhuận
    {
        if (day <= 29 && day > 0)
            return true;
        return false;
    }
    if (day > 0 && day <= days_in_month[month]) // Nếu ngày nhập phù hợp với ngày trong tháng nhập
        return true;
    return false;
}

bool XungDotThoiGian(int day1, int month1, int year1, int day2, int month2, int year2)
{
    if (year1 > year2) // Nếu năm khời đầu lớn hơn năm kết thúc
        return true;
    if (year1 == year2) // Nếu năm khởi đầu và năm kết thúc bằng nhau
    {
        if (month1 > month2) // Nếu tháng khởi đầu lớn hơn tháng kết thúc
            return true;
        if (month1 == month2) // Nếu tháng khởi đầu bằng tháng kết thúc
        {
            if (day1 > day2) // Nếu  ngày khởi đầu lớn hơn ngày kết thúc
                return true;
            else
                return false;
        }
    }
    return false;
}

void InputTime()
{
    int day1, month1, year1, day2, month2, year2;
    do
    {
        std::cout << "Nhập thời gian bắt đầu (dd mm yy)";
        std::cin >> day1 >> month1 >> year1;

        if (!ThoiGianHopLe(day1, month1, year1))
        {
            std::cout << "Thời gian không hợp lệ" << std::endl;
        }
    } while (!ThoiGianHopLe(day1, month1, year1));
    do
    {
        std::cout << "Nhập thời gian kết thúc (dd mm yy)";
        std::cin >> day2 >> month2 >> year2;

        if (!ThoiGianHopLe(day2, month2, year2))
        {
            std::cout << "Thời gian không hợp lệ" << std::endl;
        }
        if (XungDotThoiGian(day1, month1, year1, day2, month2, year2))
        {
            std::cout << "Thời gian không hợp lệ" << std::endl;
        }
    } while (!ThoiGianHopLe(day2, month2, year2) || XungDotThoiGian(day1, month1, year1, day2, month2, year2));
}