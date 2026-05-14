#include "PhanSo.h"

#include <cmath>  // Dùng cho std::abs

// Hàm tìm Ước chung lớn nhất (UCLN) để rút gọn
int UCLN(int a, int b) {
  a = std::abs(a);
  b = std::abs(b);
  while (b > 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

void PhanSo::rutGon() {
  if (mau == 0) {
    mau = 1;  // Chống crash nếu nhập mẫu = 0
  }
  // Đưa dấu trừ lên tử số (VD: 1/-2 -> -1/2, -1/-2 -> 1/2)
  if (mau < 0) {
    tu = -tu;
    mau = -mau;
  }
  // Rút gọn bằng UCLN
  if (tu != 0) {
    int ucln = UCLN(tu, mau);
    tu /= ucln;
    mau /= ucln;
  } else {
    mau = 1;  // Nếu tử = 0 thì quy chuẩn về 0/1
  }
}

// Constructor gọi luôn hàm rutGon() để chuẩn hóa ngay từ lúc sinh ra
PhanSo::PhanSo(int t, int m) : tu(t), mau(m) { rutGon(); }

PhanSo operator+(const PhanSo& a, const PhanSo& b) {
  return PhanSo(a.tu * b.mau + b.tu * a.mau, a.mau * b.mau);
}

PhanSo operator-(const PhanSo& a, const PhanSo& b) {
  return PhanSo(a.tu * b.mau - b.tu * a.mau, a.mau * b.mau);
}

PhanSo operator*(const PhanSo& a, const PhanSo& b) {
  return PhanSo(a.tu * b.tu, a.mau * b.mau);
}

PhanSo operator/(const PhanSo& a, const PhanSo& b) {
  if (b.tu == 0) {
    std::cout << "[Loi] Khong the chia cho 0! Tra ve mac dinh: ";
    return PhanSo(0, 1);
  }
  return PhanSo(a.tu * b.mau, a.mau * b.tu);
}

bool operator==(const PhanSo& a, const PhanSo& b) {
  // Vì phân số luôn được rút gọn, ta chỉ cần so sánh tử và mẫu
  return (a.tu == b.tu) && (a.mau == b.mau);
}

bool operator>(const PhanSo& a, const PhanSo& b) {
  return (a.tu * b.mau) > (b.tu * a.mau);
}

bool operator<(const PhanSo& a, const PhanSo& b) {
  return (a.tu * b.mau) < (b.tu * a.mau);
}

std::istream& operator>>(std::istream& is, PhanSo& ps) {
  std::cout << "  - Nhap tu so: ";
  is >> ps.tu;

  do {
    std::cout << "  - Nhap mau so (khac 0): ";
    is >> ps.mau;
    if (ps.mau == 0) {
      std::cout << "    [Loi] Mau so phai khac 0! Vui long nhap lai.\n";
    }
  } while (ps.mau == 0);

  ps.rutGon();
  return is;
}

std::ostream& operator<<(std::ostream& os, const PhanSo& ps) {
  if (ps.mau == 1 || ps.tu == 0) {
    os << ps.tu;
  } else {
    os << ps.tu << "/" << ps.mau;
  }
  return os;
}