#include <iostream>
#include <cstdlib>

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

    do {
        header();
        cout <<  "\t\t               Masukan PIN         \n\n"
                 "\t\t                  "; cin >> pin;

        if(pin == 123456) {
            system("cls"); // Perbaikan perintah sistem
            break; // Keluar dari loop jika PIN benar
        } else {
            cout << "\n\t\t===================================\n\n"
                 << "\t\t      Pin yang anda masukan salah!\n\n"
                 << "\t\t===================================\n\n";
            system("pause");
            system("cls");
            i += 1;
            if (i > 3) { // Perbaikan kondisi
                header();
                cout <<  "\n\n\t\t      ERROR - REK DI BLOKIR \n\n\n\n"
                         "\t\t===================================\n\n"
                         "\t\t      Kamu Salah Memasukan PIN 3x\n\n"
                         "\t\t===================================\n\n";
                system("pause");
                exit(0);
            }
        }
    } while(pin != 123456 && i <= 3);
}

void transferUang() {
    int noRek, jumlahUang;
    cout <<  "\t\t      Masukan No. Rek yang di tuju \n\n"
             "\t\t               "; cin >> noRek;
    system("cls");
    header();
    cout <<  "\t\t      Masukan Nominal Uangnya \n\n"
             "\t\t               "; cin >> jumlahUang;

    system("cls");
    header();

    if (jumlahUang > saldo) { // Perbaikan kondisi
       cout << "\n\t\t===================================\n\n";
       cout <<  "\t\t Sisa Saldo : Rp. " << saldo << "\n\n";
    } else {
        saldo -= jumlahUang;
        cout <<  "\t\t      Anda Berhasil Mentransfer \n\n"
                 "\t\t              : " << noRek << "\n"
                 "\t\t Nominal Uang : Rp. " << jumlahUang << "\n\n";
    }
    cout << "\n\t\t===================================\n\n";
}

void cekSaldo () {
    cout <<  "\t\t Sisa Saldo Anda : Rp. " << saldo << "\n\n";
    cout << "\n\t\t===================================\n\n";
}

void tarikUang() {
    int pilihanTarik, nominal;
    cout << "\t\t     [1] 100.000     [3] 500.000\n\n"
            "\t\t     [2] 200.000     [4] 1.000.000\n\n"
            "\t\t            [5] Tulis Nominal  \n\n"
            "\n\t\t===================================\n\n";
    cout << "\t\t  pilih : "; cin >> pilihanTarik;

    int tarik;
    if (pilihanTarik == 1) {
        tarik = 100000;
    } else if (pilihanTarik == 2) {
        tarik = 200000;
    } else if (pilihanTarik == 3) {
        tarik = 500000; // Perbaikan nilai tarik
    } else if (pilihanTarik == 4) {
        tarik = 1000000;
    } else if (pilihanTarik == 5) {
        system("cls");
        header();
        cout << "\t\t Masukan Nominal : Rp. "; cin >> nominal;
        tarik = nominal;
    } else {
        cout << "\t\t Pilihan tidak valid.\n\n";
        return; // Keluar dari fungsi jika pilihan tidak valid
    }

    system("cls");
    header();
    if (saldo < tarik) { // Perbaikan kondisi
        cout << "\t\t      Saldo Kamu Tidak Mencukupi \n\n"
                "\t\t===================================\n\n";
        cout << "\t\t Sisa Saldo : Rp. " << saldo << "\n\n"
                "\t\t===================================\n\n";
    } else {
        saldo -= tarik;
        cout << "\t\t      Anda Berhasil Menarik Uang \n\n"
                "\t\t===================================\n\n"
                << "\t\t Nominal Uang : Rp. " << tarik << "\n\n"
                << "\t\t===================================\n\n";
    }
}

void setorUang() {
    int nominalUang;

    cout << "\t\t Masukan nominal uang : Rp. "; cin >> nominalUang;
    saldo += nominalUang;

    system("cls");
    header();
    cout << "\t\t===================================\n\n";
    cout << "\t\t      Anda Berhasil Setor Uang \n\n";
    cout << "\t\t===================================\n\n";
    cout << "\t\t Nominal Uang : Rp. " << nominalUang << "\n\n";
    cout << "\t\t===================================\n\n";
}

int main()
{
    int pilihMenu;

    inputPin();

    bool transaksiLanjut = true;
    while (transaksiLanjut) {
        system("cls");
        pilihMenu = menu();

        system("cls");
        header();
        if (pilihMenu == 1) {
            transferUang();
        } else if(pilihMenu == 2) {
            cekSaldo();
        } else if(pilihMenu == 3) {
            tarikUang();
        } else if(pilihMenu == 4) {
            setorUang();
        } else {
            cout << "\t\t Pilihan menu tidak valid.\n\n";
            continue; // Kembali ke menu utama
        }

        system("pause");
        system("cls");

        header();
        int pilih;
        cout << "\t\t Ingin melakukan transaksi kembali? \n\n"
             << "\t\t      1. Ya        2. Tidak  \n\n"
             << "\t\t===================================\n\n";
        cout << "\t\t pilih : "; cin >> pilih;
        if (pilih != 1) {
            transaksiLanjut = false;
        }
    }

    return 0;
}
