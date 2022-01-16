#include <iostream>
#include "header.h"
using namespace std;

int main()
{
    int jumlah;
    menuInput();
    cin >> jumlah;
    int arrSort[jumlah];
    createArray(arrSort,jumlah);
    system("PAUSE");
    system("CLS");







    int pilihan;
    do{
        mainmenu();
        cin >> pilihan;
        pilih(pilihan,arrSort,jumlah);
        system("PAUSE");
        system("CLS");
    }while (pilihan!=0);

    system("PAUSE");
    return 0;
}
