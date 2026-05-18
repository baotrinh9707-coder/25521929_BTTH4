#include <iostream>

#include "CDaThuc.h"

using namespace std;

int main() {
  cout << "========== CHUONG TRINH XU LY DA THUC ==========\n";

  CDaThuc d1, d2;

  cout << "\n[1] NHAP DA THUC THU NHAT (d1):\n";
  cin >> d1;
  cout << "=> d1 = " << d1 << "\n";

  cout << "\n[2] NHAP DA THUC THU HAI (d2):\n";
  cin >> d2;
  cout << "=> d2 = " << d2 << "\n";

  cout << "\n================ KET QUA ==================\n";
  cout << "  Tong d1 + d2 = " << (d1 + d2) << "\n";
  cout << "  Hieu d1 - d2 = " << (d1 - d2) << "\n";
  cout << "  Tich d1 * d2 = " << (d1 * d2) << "\n";
  cout << "===========================================\n";

  return 0;
}