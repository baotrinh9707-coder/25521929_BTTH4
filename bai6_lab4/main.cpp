#include <iostream>

#include "CVector.h"

using namespace std;

int main() {
  cout << "========== CHUONG TRINH TINH TOAN VECTOR ==========\n";

  CVector v1, v2;

  cout << "\n[1] NHAP VECTOR THU NHAT (v1):\n";
  cin >> v1;
  cout << "=> v1 = " << v1 << "\n";

  cout << "\n[2] NHAP VECTOR THU HAI (v2):\n";
  cin >> v2;
  cout << "=> v2 = " << v2 << "\n";

  cout << "\n=================== KET QUA ====================\n";
  cout << "  Tong v1 + v2 = " << (v1 + v2) << "\n";
  cout << "  Hieu v1 - v2 = " << (v1 - v2) << "\n";

  // Nhân vô hướng sẽ trả về một con số
  cout << "  Tich vo huong (v1 * v2) = " << (v1 * v2) << "\n";

  cout << "------------------------------------------------\n";
  cout << "\n[3] TEST NHAN VECTOR VOI SO THUC:\n";
  double k;
  cout << "  - Nhap mot so thuc k: ";
  cin >> k;
  cout << "  v1 * " << k << " = " << (v1 * k) << "\n";
  cout << "  " << k << " * v2 = " << (k * v2) << "\n";
  cout << "================================================\n";

  return 0;
}