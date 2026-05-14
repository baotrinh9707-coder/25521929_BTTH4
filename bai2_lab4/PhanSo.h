#ifndef PHANSO_H
#define PHANSO_H

#include <iostream>

class PhanSo {
 private:
  int tu;
  int mau;
  void rutGon();

 public:
  PhanSo(int t = 0, int m = 1);

  // Các phép toán cơ bản
  friend PhanSo operator+(const PhanSo& a, const PhanSo& b);
  friend PhanSo operator-(const PhanSo& a, const PhanSo& b);
  friend PhanSo operator*(const PhanSo& a, const PhanSo& b);
  friend PhanSo operator/(const PhanSo& a, const PhanSo& b);

  // Các phép toán so sánh
  friend bool operator==(const PhanSo& a, const PhanSo& b);
  friend bool operator>(const PhanSo& a, const PhanSo& b);
  friend bool operator<(const PhanSo& a, const PhanSo& b);

  // Xuất nhập
  friend std::istream& operator>>(std::istream& is, PhanSo& ps);
  friend std::ostream& operator<<(std::ostream& os, const PhanSo& ps);
};

#endif