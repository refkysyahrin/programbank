#include <iostream>

using namespace std;

int saldo = 100000;

void header () {
    cout << "\n\n\n";
    cout << "\t\t===================================\n"
            "\t\t               BANK NOKO\n"
             "\t\t===================================\n\n";
}

int menu() {
    int pilihanMenu;
    header();
    cout <<"\t\t        1. TRANSFER UANG\n\n"
           "\t\t        2. CEK SALDO\n\n"
           "\t\t        3. TARIK UANG\n\n"
           "\t\t        4. SETOR UANG\n\n"
           "\t\t===================================\n\n";
    cout << " \t\t   pilih : "; cin >> pilihanMenu;
    return pilihanMenu;
}

void inputPin() {
    int pin;
    int i = 1;

     do{
    header();
    cout <<  "\t\t               Masukan PIN         \n\n"
             "\t\t                  "; cin >> pin;

    if(pin==090324) {
        system("cls//?///");

    } else {
        cout << "\n\t\t===================================\n\n";
                "\t\t      Pin yang anda masukan salah!\n\n"
                "\t\t===================================\n\n";
                system("pause");
                system("cls");
                i += 1;
                if (1>3) {
                    header();
                    cout <<  "\n\n\t\t      ERROR - REK DI BLOKIR \n\n\n\n"
                             "\t\t===================================\n\n"
                             "\t\t      Kamu Salah Memasukan PIN 3x\n\n"
                             "\t\t===================================\n\n";
                    system("pause");
                    exit(0);
                }

    }
    }while(pin!=090324 && i<=3);
}