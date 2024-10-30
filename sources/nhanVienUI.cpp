#include "nhanVien.h"
// #pragma once;
using namespace std;

const int       CT_Header   = 4;
const string    Bold_start  = "\033[1m";
const string    Bold_end    = "\033[10m";

char Header[CT_Header][50] = {
    "STT",
    "MANV",
    "HỌ VÀ TÊN",
    "PHÁI"
};

void ListPrint(dsNhanVien list, int x, int y){
    NhanVienEmpty(list);
    int locate = x;;
    const int border_0 = locate;
    locate += strlen(Header[0]) + 1;
    const int border_1 = locate;
    locate += strlen(Header[1]) + 1;
    const int border_2 = locate; 
    locate += strlen(Header[2]) + 1;
    const int border_3 = locate;
    for(int i = 0; i < list.CountNV; i++){
        gotoxy(border_0+1, i + y); cout << i +1;
        gotoxy(border_1+1, i + y); cout << list.nodes[i]->MANV;
        gotoxy(border_2+1, i + y); cout << list.nodes[i]->HO << " " << list.nodes[i]->TEN;
        gotoxy(border_3+1, i + y); cout << list.nodes[i]->PHAI;
    }
}


void HeaderPrint(dsNhanVien list, int x, int y){
    SetConsoleOutputCP(CP_UTF8);
    int cursor  = x;
    gotoxy(cursor, 0);   cout << "|";
    cout << Bold_start << Header[0] << Bold_end ;

    cursor += strlen(Header[0]) + 1;
    int border_1 = cursor;
    gotoxy(border_1, 0); cout << "|";
    cout << Bold_start << Header[1] << Bold_end ;

    cursor += strlen(Header[1]) + 1;
    int border_2 = cursor;
    gotoxy(border_2,0); cout << "|";
    gotoxy(border_2 + 5 + 1,0);
    cout << Bold_start << Header[2] << Bold_end ;

    cursor += 20 + 1;
    int border_3 = cursor;
    gotoxy(border_3,0); cout << "|";
    cout << Bold_start << Header[3] << Bold_end ;

    cout << "|";
}

int main(){
    cout << endl;

    dsNhanVien list;
    HeaderPrint(list, 5, 0);

    // gotoxy(119,0); cout << "a";
    
    cout << endl << strlen(Header[2]) <<  endl; system("pause");
    return 0;
}