#include <iostream>
using namespace std;

void Initialize(PTR &head)
{
    head = nullptr;
}

PTR newNode(CT_HOADON cthddata)
{
    PTR p = new Node;
    p->cthddata = cthddata;
    p->next = nullptr;
    return p;
}

void hoaDon(CT_HOADON cthddata, HOADON hddata, PTR &head)
{

    check = false;
    cout << "so hd: ";
    cin >> hddata.SoHD;
    cout << hddata.SoHD << endl;
    cout << "ngay: ";
    cin >> hddata.day;
    cout << hddata.day << endl;
    cout << "so loai: ";
    cin >> hddata.Loai;
    if (hddata.Loai == 'n' || 'N' || 'Y' || 'y')
    {
        if (hddata.Loai == 'n' || 'N')
        {
            cout << "hoa don nhap";
        }
        else
            cout << "hoa don xuat";
    }
    else
        check = false;
    cout << check << endl;
    //
    cout << "Nhap vat tu: " << endl;
    PTR p = newNode(cthddata);
    if (!head || cthddata.MAVT < head->cthddata.MAVT)
    {
        p->next = head;
        head = p;
    }
    else
    {
        PTR current = head;
        while (current->next && current->next->cthddata.MAVT < cthddata.MAVT)
        {
            current = current->next;
        }
        p->next = current->next;
        current->next = p;
    }
}
void lietKe_TheoMaSo(PTR head)
{

    cout << "\n"
         << setw(10) << "Ma so" << setw(20) << "Ho" << setw(15) << "Ten" << endl;
    PTR current = head;
    while (current != nullptr)
    {
        cout << setw(10) << current->cthddata.MAVT
             << setw(20) << current->cthddata.soLuong
             << setw(15) << current->cthddata.ten << endl;
        current = current->next;
    }
}

int main()
{
    HOADON data;
    // hoaDon(data, );
}