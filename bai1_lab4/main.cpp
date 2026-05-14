#include <iostream>

#include "SoPhuc.h"

using namespace std;

int main() {
  SoPhuc sp1, sp2;  // Khởi tạo 2 đối tượng rỗng (mặc định thuc=0, ao=0)

  cout << "--- NHAP DU LIEU SO PHUC ---" << endl;
  cout << "Nhap so phuc thu nhat:" << endl;
  cin >> sp1;  // Gọi hàm operator>> để nhập liệu

  cout << "\nNhap so phuc thu hai:" << endl;
  cin >> sp2;  // Gọi hàm operator>> để nhập liệu

  cout << "\n--- KET QUA VUA NHAP ---" << endl;
  cout << "So phuc 1: " << sp1 << endl;
  cout << "So phuc 2: " << sp2 << endl;

  cout << "\n--- THUC HIEN PHEP TOAN ---" << endl;
  cout << "Cong: (" << sp1 << ") + (" << sp2 << ") = " << (sp1 + sp2) << endl;
  cout << "Tru : (" << sp1 << ") - (" << sp2 << ") = " << (sp1 - sp2) << endl;
  cout << "Nhan: (" << sp1 << ") * (" << sp2 << ") = " << (sp1 * sp2) << endl;
  cout << "Chia: (" << sp1 << ") / (" << sp2 << ") = " << (sp1 / sp2) << endl;

  cout << "\n--- DEMO CONSTRUCTOR VOI SO THUC ---" << endl;
  double soThuc;
  cout << "Nhap vao mot so thuc bat ky: ";
  cin >> soThuc;
  SoPhuc sp3(soThuc);  // Khởi tạo số phức từ 1 số thực (phần ảo tự động = 0)
  cout << "So phuc tao tu so thuc " << soThuc << " la: " << sp3 << endl;
  cout << "Thu cong so thuc nay voi so phuc 1: " << sp1 << " + " << soThuc
       << " = " << (sp1 + soThuc) << endl;

  return 0;
}