#include <iostream>

#include "CMatrix.h"
#include "CVector.h"

using namespace std;

int main() {
  cout << "============= TEST MA TRAN & VECTOR =============\n";

  CMatrix m1, m2;
  CVector v;

  cout << "\n[1] NHAP MA TRAN M1:\n";
  cin >> m1;
  cout << "=> M1:" << m1;

  cout << "\n[2] NHAP MA TRAN M2 (De test tich M1 * M2, nen nhap so dong M2 = "
          "so cot M1):\n";
  cin >> m2;
  cout << "=> M2:" << m2;

  cout << "\n[3] NHAP VECTOR V (De test tich M1 * V, nen nhap so chieu V = so "
          "cot M1):\n";
  cin >> v;
  cout << "=> V = " << v << "\n";

  cout << "\n==================== KET QUA ====================\n";
  cout << "[+] Tong (M1 + M2):" << (m1 + m2);
  cout << "[-] Hieu (M1 - M2):" << (m1 - m2);

  cout << "\n[*] Tich 2 ma tran (M1 * M2):" << (m1 * m2);

  cout << "\n[*] Tich Ma tran va Vector (M1 * V): " << (m1 * v) << "\n";
  cout << "=================================================\n";

  return 0;
}