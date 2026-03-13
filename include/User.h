#ifndef _USER_H_
#define _USER_H_

#include "Account.h"
#include <fstream>

class IUser {
protected:
    string _id;
    vector<IAccount*> _accountList;
public:
    IUser();
    IUser(string id);
    virtual void addAccount(IAccount* acc) = 0;
    void thongKeDanhSach();
    double tinhTongGiaTri();
    virtual ~IUser();
};

class NormalUser: public IUser {
public:
    NormalUser(string id);
    void addAccount(IAccount* acc) override;
};

class VIPUser: public IUser {
public:
    VIPUser(string id);
    void addAccount(IAccount* acc) override;
    void thongKeTheoLoaiTaiKhoan();
};

IUser* loadFile(const char* path);

#endif