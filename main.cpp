#include "include/Account.h"
#include "include/User.h"

void salute(string message);
void bye();

int main() {
    salute("Day la chuong trinh quan ly tai chinh ca nhan\n");

    IUser* currentUser = loadFile("input.txt");

    if (currentUser != nullptr) {
        
        currentUser->thongKeDanhSach();

        VIPUser* vipPtr = dynamic_cast<VIPUser*>(currentUser);
        if (vipPtr != nullptr) {
            vipPtr->thongKeTheoLoaiTaiKhoan();
        }

        delete currentUser;
    }


    bye();
    return 0;
}

void salute(string message) {
    cout << message << "\n";
}

void bye() {
    cout << "\nChuong trinh dang ket thuc...Bam Enter de thoat...\n";
    cin.get();
}