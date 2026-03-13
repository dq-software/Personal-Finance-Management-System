#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

class IAccount {
public:
    virtual long long tinhGiaTri() = 0;
    virtual void hienThongTin() = 0;
    virtual string getType() = 0;
    virtual ~IAccount() = default;
};

class BankAccount: public IAccount {
private:
    string _bankName;
    long long _balance;
public:
    BankAccount();
    BankAccount(string name, long long balance);
    long long tinhGiaTri() override;
    void hienThongTin() override;
    string getType() override;
};

class StockAccount: public IAccount {
private:
    string _symbol;
    int _quantity;
    long long _price;
public:
    StockAccount();
    StockAccount(string symbol, int quantity, long long price);
    long long tinhGiaTri() override;
    void hienThongTin() override;
    string getType() override;
};

class CryptoAccount: public IAccount {
private:
    string _code;
    long long _balance;
    double _exchangeRate;
public:
    CryptoAccount();
    CryptoAccount(string code, long long balance, double rate);
    long long tinhGiaTri() override;
    void hienThongTin() override;
    string getType() override;
};

#endif