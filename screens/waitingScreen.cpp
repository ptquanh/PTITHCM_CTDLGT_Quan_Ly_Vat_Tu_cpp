#include "../screens/graphic.h"



const int Collums = 20;
const int Rows = 7;
const int Header_x = 20;
const int Header_y = 6; 


const int Key_up = 72;
const int Key_down = 80;
const int Key_enter = 13;




void Normal(){
    SetBGColor(BLACK);
    SetColor(WHITE);
}
void Highlight(int Color){
    SetBGColor(Color);
    SetColor(WHITE);
}

int menuChinhDong(char menuchinh[YeuCauChinh][50])
{
    Normal();
    int choice = 0;
    system("cls");
    gotoxy(Header_x, Header_y); cout << "MENU CHÍNH";

    for(int i = 0; i < YeuCauChinh; i++){
        gotoxy(Collums, Rows + i);
        cout << menuchinh[i];
    }

    Highlight(LIGHTBLUE);
    gotoxy(Collums, Rows + choice);
    cout << menuchinh[choice];

    char direction;
    do
    {
        direction = getch();

        switch(direction){
            case Key_up:
                if( choice + 1 > 1){
                    Normal();
                    gotoxy(Collums, Rows + choice);
                    cout << menuchinh[choice];
                    
                    choice --;
                    Highlight(LIGHTBLUE);
                    gotoxy(Collums, Rows + choice);
                    cout << menuchinh[choice];
                    break;
                }
            case Key_down:
                if(choice < YeuCauChinh ){
                    Normal();
                    gotoxy(Collums, Rows + choice);
                    cout << menuchinh[choice];
                    
                    choice++;
                    Highlight(LIGHTBLUE);
                    gotoxy(Collums, Rows + choice);
                    cout << menuchinh[choice];
                    break;
                }
            case ENTER:  Normal() ; return choice + 1;
        }    
    } while (true);
    

}

int MenuVatTuDong(char menuvattu[YeuCauVatTu][50])
{
    Normal();
    int choice = 0;
    system("cls");
    Highlight(LIGHTGREEN);
    gotoxy(Header_x,Header_y); cout << "MENU VẬT TƯ";
    Normal();
    for(int i = 0; i < YeuCauVatTu; i++){
        gotoxy(Collums, Rows + i);
        cout << menuvattu[i];
    }

    Highlight(LIGHTBLUE);
    gotoxy(Collums, Rows + choice);
    cout << menuvattu[choice];

    char direction;
    do
    {
        direction = getch();

        switch(direction){
            case Key_up:
                if( choice + 1 > 1){
                    Normal();
                    gotoxy(Collums, Rows + choice);
                    cout << menuvattu[choice];
                    
                    choice --;
                    Highlight(LIGHTBLUE);
                    gotoxy(Collums, Rows + choice);
                    cout << menuvattu[choice];
                    break;
                }
            case Key_down:
                if(choice < YeuCauVatTu ){
                    Normal();
                    gotoxy(Collums, Rows + choice);
                    cout << menuvattu[choice];
                    
                    choice++;
                    Highlight(LIGHTBLUE);
                    gotoxy(Collums, Rows + choice);
                    cout << menuvattu[choice];
                    break;
                }
            case ENTER:  Normal() ; return choice + 1;
        }    
    } while (true);
}

int MenuNhanVienDong(char menunhanvien[YeuCauNhanVien][50])
{
    Normal();
    int choice = 0;
    system("cls");
    gotoxy(Header_x, Header_y); cout << "MENU NHÂN VIÊN";

    for(int i = 0; i < YeuCauNhanVien; i++){
        gotoxy(Collums, Rows + i);
        cout << menunhanvien[i];
    }

    Highlight(LIGHTBLUE);
    gotoxy(Collums, Rows + choice);
    cout << menunhanvien[choice];

    char direction;
    do
    {
        direction = getch();

        switch(direction){
            case Key_up:
                if( choice + 1 > 1){
                    Normal();
                    gotoxy(Collums, Rows + choice);
                    cout << menunhanvien[choice];
                    
                    choice --;
                    Highlight(LIGHTBLUE);
                    gotoxy(Collums, Rows + choice);
                    cout << menunhanvien[choice];
                    break;
                }
            case Key_down:
                if(choice < YeuCauNhanVien ){
                    Normal();
                    gotoxy(Collums, Rows + choice);
                    cout << menunhanvien[choice];
                    
                    choice++;
                    Highlight(LIGHTBLUE);
                    gotoxy(Collums, Rows + choice);
                    cout << menunhanvien[choice];
                    break;
                }
            case ENTER:  Normal() ; return choice + 1;
        }    
    } while (true);
    

}

int MenuHoaDonDong(char menuhoadon[YeuCauHoaDon][50])
{
    Normal();
    int choice = 0;
    system("cls");
    gotoxy(Header_x, Header_y); cout << "MENU HÓA ĐƠN";

    for(int i = 0; i < YeuCauHoaDon; i++){
        gotoxy(Collums, Rows + i);
        cout << menuhoadon[i];
    }

    Highlight(LIGHTBLUE);
    gotoxy(Collums, Rows + choice);
    cout << menuhoadon[choice];

    char direction;
    do
    {
        direction = getch();

        switch(direction){
            case Key_up:
                if( choice + 1 > 1){
                    Normal();
                    gotoxy(Collums, Rows + choice);
                    cout << menuhoadon[choice];
                    
                    choice --;
                    Highlight(LIGHTBLUE);
                    gotoxy(Collums, Rows + choice);
                    cout << menuhoadon[choice];
                    break;
                }
            case Key_down:
                if(choice < YeuCauHoaDon ){
                    Normal();
                    gotoxy(Collums, Rows + choice);
                    cout << menuhoadon[choice];
                    
                    choice++;
                    Highlight(LIGHTBLUE);
                    gotoxy(Collums, Rows + choice);
                    cout << menuhoadon[choice];
                    break;
                }
            case ENTER:  Normal() ; return choice + 1;
        }    
    } while (true); 
}

int MenuThongKeDong(char menuthongke[YeuCauThongKe][50])
{
    Normal();
    int choice = 0;
    system("cls");
    gotoxy(Header_x, Header_y); cout << "MENU THỐNG KÊ";

    for(int i = 0; i < YeuCauThongKe; i++){
        gotoxy(Collums, Rows + i);
        cout << menuthongke[i];
    }

    Highlight(LIGHTBLUE);
    gotoxy(Collums, Rows + choice);
    cout << menuthongke[choice];

    char direction;
    do
    {
        direction = getch();

        switch(direction){
            case Key_up:
                if( choice + 1 > 1){
                    Normal();
                    gotoxy(Collums, Rows + choice);
                    cout << menuthongke[choice];
                    
                    choice --;
                    Highlight(LIGHTBLUE);
                    gotoxy(Collums, Rows + choice);
                    cout << menuthongke[choice];
                    break;
                }
            case Key_down:
                if(choice < YeuCauThongKe){
                    Normal();
                    gotoxy(Collums, Rows + choice);
                    cout << menuthongke[choice];
                    
                    choice++;
                    Highlight(LIGHTBLUE);
                    gotoxy(Collums, Rows + choice);
                    cout << menuthongke[choice];
                    break;
                }
            case ENTER:  Normal() ; return choice + 1;
        }    
    } while (true);
    

}


const int CTNNV = 4;
void HeaderPrint(char header[CTNNV][50]){
    system("cls");
    Normal();
    box(1,1,53,2);
    SetCP437();
    gotoxy(5,2);    cout << char(179);
    gotoxy(22,2);   cout << char(179);
    gotoxy(48,2);   cout << char(179);
    SetUTF8();
    gotoxy(2,2);    cout << header[0];
    gotoxy(8,2);    cout << header[1];
    gotoxy(31,2);   cout << header[2];
    gotoxy(49,2);   cout << header[3];




}
void PrintNhanien(dsNhanVien list){
    char Header[CTNNV][50] =
    {
        "STT",
        "MÃ NHÂN VIÊN",
        "HỌ VÀ TÊN",
        "PHÁI",
    };
    HeaderPrint(Header);

}




int main()
{
    SetConsoleOutputCP(CP_UTF8);

    // int choice = 0;
    // system("cls"); cout << choice;

    char Header[CTNNV][50] =
    {
        "STT",
        "Mã nhân viên",
        "Họ và Tên",
        "Phái",
    };

    
    HeaderPrint(Header);

    cout << endl << endl;
    system("pause");
    return 0;
}