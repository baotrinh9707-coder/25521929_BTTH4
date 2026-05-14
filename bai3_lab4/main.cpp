#include <bits/stdc++.h>

#include "CTime.h"

using namespace std;

int main() {
  CTime t1;
  int s_add, s_sub;

  cout << "--- NHAP THOI GIAN BAN DAU ---" << endl;
  cin >> t1;
  cout << "Thoi gian hien tai: " << t1 << endl;

  // 1. Nhập số giây để cộng
  cout << "\n--- PHEP CONG/TRU SO GIAY TUY Y ---" << endl;
  cout << "Nhap so giay muon CONG: ";
  cin >> s_add;
  cout << "=> Ket qua (t1 + " << s_add << "): " << t1 + s_add << endl;

  // 2. Nhập số giây để trừ
  cout << "Nhap so giay muon TRU: ";
  cin >> s_sub;
  cout << "=> Ket qua (t1 - " << s_sub << "): " << t1 - s_sub << endl;

  // 3. Test toán tử ++ và -- (tăng/giảm 1 giây)
  cout << "\n--- TEST TOAN TU ++ VA -- (1 GIAY) ---" << endl;
  CTime t2 = t1;
  cout << "Thoi gian t2 ban dau  : " << t2 << endl;

  // Test tăng
  ++t2;
  cout << "Sau khi ++t2 (tang 1) : " << t2 << endl;

  // Test giảm
  --t2;  // Quay lại lúc đầu
  --t2;
  cout << "Sau khi --t2 (giam 1) : " << t2 << endl;

  cout << "\n=============================================" << endl;
  cout << "Chuong trinh se vao che do DONG HO..." << endl;
  cout << "Nhan Ctrl + C de thoat!" << endl;
  cout << "=============================================" << endl;

  std::this_thread::sleep_for(std::chrono::seconds(3));

  // Chạy đồng hồ dựa trên thời gian t1 ban đầu
  t1.runClock();

  return 0;
}