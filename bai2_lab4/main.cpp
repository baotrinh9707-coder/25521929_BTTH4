#include <iostream>

#include "PhanSo.h"

using namespace std;

int main() {
  PhanSo ps1, ps2;  // Khởi tạo 2 phân số mặc định (0/1)

  cout << "--- NHAP DU LIEU PHAN SO ---" << endl;
  cout << "Nhap phan so thu nhat:" << endl;
  cin >> ps1;  // Gọi hàm operator>>

  cout << "\nNhap phan so thu hai:" << endl;
  cin >> ps2;  // Gọi hàm operator>>

  cout << "\n--- KET QUA VUA NHAP (DA TUDONG RUT GON) ---" << endl;
  cout << "Phan so 1: " << ps1 << endl;
  cout << "Phan so 2: " << ps2 << endl;

  cout << "\n--- THUC HIEN PHEP TOAN ---" << endl;
  cout << "Cong: (" << ps1 << ") + (" << ps2 << ") = " << (ps1 + ps2) << endl;
  cout << "Tru : (" << ps1 << ") - (" << ps2 << ") = " << (ps1 - ps2) << endl;
  cout << "Nhan: (" << ps1 << ") * (" << ps2 << ") = " << (ps1 * ps2) << endl;
  cout << "Chia: (" << ps1 << ") / (" << ps2 << ") = " << (ps1 / ps2) << endl;

  cout << "\n--- SO SANH ---" << endl;
  if (ps1 == ps2) cout << ps1 << " bang " << ps2 << endl;
  if (ps1 > ps2) cout << ps1 << " lon hon " << ps2 << endl;
  if (ps1 < ps2) cout << ps1 << " nho hon " << ps2 << endl;

  cout << "\n--- DEMO CONSTRUCTOR VOI SO NGUYEN ---" << endl;
  int soNguyen;
  cout << "Nhap vao mot so nguyen bat ky: ";
  cin >> soNguyen;

  PhanSo ps3(soNguyen);  // Khởi tạo phân số từ số nguyên
  cout << "Phan so tao tu so nguyen " << soNguyen << " la: " << ps3 << endl;
  cout << "Thu cong so nguyen nay voi Phan so 1: " << ps1 << " + " << soNguyen
       << " = " << (ps1 + soNguyen) << endl;

  return 0;
}