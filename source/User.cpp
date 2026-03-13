#include "User.h"

IUser::IUser() {
    // do nothing
}
IUser::IUser(string id) {
    this->_id = id;
}

double IUser::tinhTongGiaTri() {
    double tong = 0;
    for(int i = 0; i < _accountList.size(); i++) {
        tong += _accountList[i]->tinhGiaTri();
    }
    return tong;
}

void IUser::thongKeDanhSach() {
    cout << "\n>>> DANH SACH TAI KHOAN CHI TIET <<<" << endl;
    cout << string(60, '-') << endl; // Kẻ đường gạch ngang cho đẹp

    if (_accountList.empty()) {
        cout << "(Nguoi dung chua co tai khoan nao)" << endl;
        return;
    }

    int stt = 1;
    for (IAccount* acc : _accountList) {
        cout << stt++ << ". "; 
        acc->hienThongTin();
    }
    
    cout << string(60, '-') << endl;
}

IUser::~IUser() {
    for (IAccount* acc : _accountList) {
        delete acc;
    }
    _accountList.clear();
}


//---------Normal User--------
NormalUser::NormalUser(string id) {
    this->_id = id;
}

void NormalUser::addAccount(IAccount* acc) {
    if(_accountList.size() < 10) {
        _accountList.push_back(acc);
    }
}


//---------VIP User----------
VIPUser::VIPUser(string id) {
    this->_id = id;
}

void VIPUser::addAccount(IAccount* acc) {
    _accountList.push_back(acc);
}

void VIPUser::thongKeTheoLoaiTaiKhoan() {
    double sumBank = 0;
    double sumStock = 0;
    double sumCrypto = 0;
    for(IAccount* acc : _accountList) {
        if(acc->getType() == "BANK") {
            sumBank += acc->tinhGiaTri();
        } else if(acc->getType() == "STOCK") {
            sumStock += acc->tinhGiaTri();
        } else if(acc->getType() == "CRYPTO") {
            sumCrypto += acc->tinhGiaTri();
        }
    }

    cout << "----THONG KE THEO TUNG LOAI TAI KHOAN----\n";
    cout << "[BANK]:   " << (long long)sumBank << "\n";
    cout << "[STOCK]:  " << (long long)sumStock << "\n";
    cout << "[CRYPTO]: " << (long long)sumCrypto << "\n";
}

//--------Ham doc file--------
IUser* loadFile(const char* path) {
    ifstream fIn;
    fIn.open(path);
    if(fIn.is_open()) {
        string buffer;
        fIn >> buffer;

        string username;
        fIn >> username;

        IUser* currentUser = nullptr;
        if(buffer == "VIP") {
            currentUser = new VIPUser(username);
        } else {
            currentUser = new NormalUser(username);
        }
        

        string accType;
        while (fIn >> accType) {
            IAccount* acc = nullptr;

            if (accType == "BANK") {
                string bankName;
                double balance;
                fIn >> bankName >> balance;
                acc = new BankAccount(bankName, balance);

            } else if (accType == "STOCK") {
                string symbol;
                int qty;
                double price;
                fIn >> symbol >> qty >> price;
                acc = new StockAccount(symbol, qty, price);

            } else if (accType == "CRYPTO") {
                string symbol;
                double balance, rate;
                fIn >> symbol >> balance >> rate;
                acc = new CryptoAccount(symbol, balance, rate);
            }

            if (acc != nullptr) {
                currentUser->addAccount(acc);
            }
        }

        fIn.close();

        return currentUser;
    } else {
        cout << "Khong the mo file\n";
        return nullptr;
    }
}