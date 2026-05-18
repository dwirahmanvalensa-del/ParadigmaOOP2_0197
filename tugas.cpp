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

