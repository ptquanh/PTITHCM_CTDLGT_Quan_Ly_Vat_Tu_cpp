#include "doHoa.cpp"
#include "../libraries/khaibao.h"
int main(){
    int x = 2;
    int y = 2;
    drawTable(x, y, 15, 23,headerVatTuList);
    while(1){
        getch();
    }
}