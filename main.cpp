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

int transferUang() {
    int noRek, jumlahUang;
    cout <<  "\t\t      Masukan No. Rek yang di tuju \n\n"
             "\t\t               "; cin >> noRek;
    system("cls");
    header();
    cout <<  "\t\t      Masukan Nominal Uangnya \n\n"
             "\t\t               "; cin >> jumlahUang;

    system("cls");
    header();

    if (jumlahUang>=saldo) {
       cout << "\n\t\t===================================\n\n";
        cout <<  "\t\t Sisa Saldo : Rp. "<<saldo<<"\n\n";

    } else {
        saldo -= jumlahUang;
        cout <<  "\t\t      Anda Berhasil Mentransfer \n\n"
                 "\t\t              : "<<noRek<<"\n"
                 "\t\t Nominal Uang : Rp. "<<jumlahUang<<"\n\n";

    }

    cout << "\n\t\t===================================\n\n";


}

void cekSaldo () {
    cout <<  "\t\t Sisa Saldo Anda : Rp. " <<saldo<<"\n\n";
    cout << "\n\t\t===================================\n\n";
}

void tarikUang() {
    int tarik,nominal;
    cout << "\t\t     [1] 100.000     [3] 500.000\n\n"
            "\t\t     [2] 200.000     [4] 1.000.000\n\n"
            "\t\t            [5] Tilis Nominal  \n\n"
            "\n\t\t===================================\n\n";
            "\t\t  pilih : "; cin >> tarik;

    if (tarik==1) {
        tarik = 100000;
    } else if (tarik==2) {
        tarik = 200000;
    } else if (tarik==3) {
        tarik = 300000;
    } else if (tarik==4) {
        tarik = 1000000;
    } else if (tarik==5) {
        system("cls");
        header();
        cout << "\t\t Masukan Nominal : Rp. "; cin >> nominal;
        tarik = nominal;
    }


    system("cls");
    header();
    if (saldo<=tarik) {
        cout << "\t\t      Saldo Kamu Tidak Mencukupi \n\n"
                "\t\t===================================\n\n";
        cout << "\t\t Sisa Saldo : Rp. :"<<saldo<<"\n\n"
                "\t\t===================================\n\n";
    } else {
        saldo-=tarik;
        cout << "\t\t      Anda Berhasil Menarik Uang \n\n"
                "\t\t===================================\n\n";
                "\t\t Nominal Uang : Rp. :"<<tarik<<"\n\n"
                "\t\t===================================\n\n";
    }
}

void setorUang() {
    int nominalUang;

    cout << "\t\t Masukan nominal uang : Rp. "; cin >> nominalUang;
    saldo += nominalUang;

    system("cls");
    header();
    cout << "\t\t===================================\n\n";
    cout << "\t\t      Anda Berhasil Setor Uang \n\n"
            "\t\t===================================\n\n";
            "\t\t Nominal Uang : Rp. "<<nominalUang<<"\n\n"
            "\t\t===================================\n\n";

}

int main()
{
    int pilihMenu;

    inputPin();

    menuUlang:
    system("cls");
    pilihMenu=menu();

    do{
    system("cls");
    header();
    if (pilihMenu==1) {
        transferUang();
    } else if(pilihMenu==2) {
        cekSaldo();
    } else if(pilihMenu==3) {
        tarikUang();
    } else if(pilihMenu==4) {
        setorUang();
    }
    } while (pilihMenu>4);

    system("pause");
    system("cls");

    header();
    int pilih;
    cout << "\t\t Ingin melakukan transaksi kembali? \n\n"
         << "\t\t      1. Ya        2. Tidak  \n\n"
         << "\t\t===================================\n\n";
         << "\t\t pilih : "; cin>>pilih;
    if (pilih==1) {
        goto menuUlang;
    } else {
        exit (0);
    }

    return 0;

}
