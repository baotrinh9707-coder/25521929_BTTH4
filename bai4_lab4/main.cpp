#include <iomanip>
#include <iostream>

#include "CDate.h"

using namespace std;

// Hàm demo: Tự nhập ngày để kiểm tra các toán tử
void demoTuNhapCacPhepToan() {
  CDate d, originalD;
  int days;

  cout << "========================================================\n";
  cout << "      CAC PHEP TOAN CDate\n";
  cout << "========================================================\n";
  cout << "1. Nhap mot ngay bat ky ban muon (Dinh dang dd/mm/yyyy):\n";
  cin >> d;

  // Lưu lại ngày gốc để phục vụ các test sau
  originalD = d;

  cout << "-> Ngay ban da nhap: " << d << "\n\n";

  cout << "--------------------------------------------------------\n";
  cout << "2. Tang/Giam 1 ngay (++, --)\n";

  CDate currentTest = originalD;
  cout << "   - Ban dau:      " << currentTest << "\n";

  CDate banDau = originalD;

  CDate testTang = banDau;
  testTang++;
  cout << "Sau khi tang 1 ngay: " << testTang << endl;

  CDate testGiam = banDau;
  testGiam--;  // 19 giảm xuống 18
  cout << "Sau khi giam 1 ngay: " << testGiam << endl;

  cout << "--------------------------------------------------------\n";
  cout << "3. Cong them mot so ngay (+)\n";
  cout << "   - Nhap so ngay muon cong them: ";
  cin >> days;
  cout << "   - Result (" << originalD << " + " << days
       << " ngay): " << (originalD + days) << "\n\n";

  cout << "--------------------------------------------------------\n";
  cout << "4. Tru di mot so ngay (-)\n";
  cout << "   - Nhap so ngay muon tru di: ";
  cin >> days;
  cout << "   - Result (" << originalD << " - " << days
       << " ngay): " << (originalD - days) << "\n";
  cout << "========================================================\n\n\n";
}

// Giải bài toán lãi suất ngân hàng
void calculateBankInterest() {
  CDate depositDate, withdrawDate;
  double principal, annualRate;

  cout << "========================================================\n";
  cout << "          BAI TOAN TINH LAI SUAT NGAN HANG\n";
  cout << "========================================================\n";
  cout << "Nhap ngay gui (dd/mm/yyyy): \n";
  cin >> depositDate;
  cout << "Nhap ngay rut (dd/mm/yyyy): \n";
  cin >> withdrawDate;

  int daysDeposited =
      withdrawDate - depositDate;  // Phép trừ 2 CDate lấy số ngày

  if (daysDeposited <= 0) {
    cout << "Loi: Ngay rut phai xay ra sau ngay gui!" << endl;
    return;
  }

  cout << "Nhap so tien gui (VND): ";
  cin >> principal;
  cout << "Nhap lai suat nam (%): ";
  cin >> annualRate;

  // Công thức tính lãi suất đơn
  double interest = principal * (annualRate / 100.0) * (daysDeposited / 365.0);
  double totalAmount = principal + interest;

  cout << "\n--- KET QUA ---\n";
  cout << "So ngay thuc gui: " << daysDeposited << " ngay\n";
  cout << fixed << setprecision(0);  // Không in phần thập phân VND
  cout << "Tien lai nhan duoc: " << interest << " VND\n";
  cout << "Tong tien von + lai: " << totalAmount << " VND\n";
  cout << "========================================================\n";
}

int main() {
  demoTuNhapCacPhepToan();

  calculateBankInterest();

  return 0;
}