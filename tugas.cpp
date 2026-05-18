#include <iostream>
using namespace std;

class RekeningBank {
protected:
    string noRek;
    double saldo;

public:
    RekeningBank(string no, double saldoAwal) {
        noRek = no;
        saldo = saldoAwal;
    }

    virtual void potongAdmin() = 0; 

    void tampilkanInfo() {
        cout << "No Rekening: " << noRek << " | Saldo: Rp " << saldo << endl;
    }
};

class RekeningSyariah : public RekeningBank {
public:
    RekeningSyariah(string no, double saldoAwal) : RekeningBank(no, saldoAwal) {}

    void potongAdmin() override {
        cout << "Rekening Syariah: Tidak ada potongan admin bulanan." << endl;
    }
};

class RekeningKonvensional : public RekeningBank {
public:
    RekeningKonvensional(string no, double saldoAwal) : RekeningBank(no, saldoAwal) {}

    void potongAdmin() override {
        double admin = 15000;
        saldo -= admin; 
        cout << "Rekening Konvensional: Dipotong biaya admin Rp " << admin << endl;
    }
};

class RekeningPremium : public RekeningBank {
public:
    RekeningPremium(string no, double saldoAwal) : RekeningBank(no, saldoAwal) {}

    void potongAdmin() override {
        double admin;
        if (saldo > 10000000) {
            admin = 0;
            cout << "Rekening Premium: Saldo di atas Rp 10.000.000 (Bebas biaya admin)." << endl;
        } else {
            admin = 50000;
            saldo -= admin;
            cout << "Rekening Premium: Saldo <= Rp 10.000.000. Dipotong biaya admin Rp " << admin << endl;
        }
    }
};

int main() {
    RekeningBank* akun;

    RekeningSyariah tabunganSyariah("CACA-001", 500000);
    akun = &tabunganSyariah;
    akun->tampilkanInfo();
    akun->potongAdmin();
    akun->tampilkanInfo();
    
    cout << "--------------------------------------------" << endl;

    RekeningKonvensional tabunganKonvensional("MARICA-002", 2000000);
    akun = &tabunganKonvensional;
    akun->tampilkanInfo();
    akun->potongAdmin();
    akun->tampilkanInfo();

    cout << "--------------------------------------------" << endl;

    RekeningPremium tabunganPremium("VALENSA-003", 5000000);
    akun = &tabunganPremium;
    akun->tampilkanInfo();
    akun->potongAdmin();
    akun->tampilkanInfo();

    return 0;
}