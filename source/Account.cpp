#include "Account.h"

//----------BANK----------
BankAccount::BankAccount() {
    // do nothing
}
BankAccount::BankAccount(string name, long long balance) {
    this->_bankName = name;
    this->_balance = balance;
}
long long BankAccount::tinhGiaTri() {
    return _balance;
}
void BankAccount::hienThongTin() {
    cout << left << setw(15) << "[BANK]" 
         << setw(20) << _bankName 
         << " | So du: " << _balance << " VND" << endl;
}
string BankAccount::getType() {
    return "BANK";
}


//----------STOCK----------
StockAccount::StockAccount() {
    // do nothing
}
StockAccount::StockAccount(string symbol, int quantity, long long price) {
    this->_symbol = symbol;
    this->_quantity = quantity;
    this->_price = price;
}
long long StockAccount::tinhGiaTri() {
    return _quantity * _price;
}
void StockAccount::hienThongTin() {
    cout << left << setw(15) << "[STOCK]" 
         << setw(20) << _symbol 
         << " | So luong: " << _quantity
         << " | Gia: " << _price << endl;
}
string StockAccount::getType() {
    return "STOCK";
}


//----------CRYPTO----------
CryptoAccount::CryptoAccount() {
    // do nothing
}
CryptoAccount::CryptoAccount(string code, long long balance, double rate) {
    this->_code = code;
    this->_balance = balance;
    this->_exchangeRate = rate;
}
long long CryptoAccount::tinhGiaTri() {
    return _balance * _exchangeRate;
}
void CryptoAccount::hienThongTin() {
    cout << left << setw(15) << "[CRYPTO]" 
         << setw(20) << _code
         << " | So du: " << _balance 
         << " | Ti gia: " << _exchangeRate << endl;
}
string CryptoAccount::getType() {
    return "CRYPTO";
}