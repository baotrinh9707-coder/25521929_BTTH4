#include "SoPhuc.h"

#include <cmath>
SoPhuc::SoPhuc(double t, double a) {
  thuc = t;
  ao = a;
}

// Định nghĩa phép cộng
SoPhuc operator+(const SoPhuc& a, const SoPhuc& b) {
  return SoPhuc(a.thuc + b.thuc, a.ao + b.ao);
}

// Định nghĩa phép trừ
SoPhuc operator-(const SoPhuc& a, const SoPhuc& b) {
  return SoPhuc(a.thuc - b.thuc, a.ao - b.ao);
}

// Định nghĩa phép nhân
SoPhuc operator*(const SoPhuc& a, const SoPhuc& b) {
  return SoPhuc(a.thuc * b.thuc - a.ao * b.ao, a.thuc * b.ao + a.ao * b.thuc);
}

// Định nghĩa phép chia
SoPhuc operator/(const SoPhuc& a, const SoPhuc& b) {
  double mauSo = b.thuc * b.thuc + b.ao * b.ao;
  return SoPhuc((a.thuc * b.thuc + a.ao * b.ao) / mauSo,
                (a.ao * b.thuc - a.thuc * b.ao) / mauSo);
}

// Định nghĩa so sánh bằng
bool operator==(const SoPhuc& a, const SoPhuc& b) {
  return (a.thuc == b.thuc && a.ao == b.ao);
}

// Định nghĩa so sánh khác
bool operator!=(const SoPhuc& a, const SoPhuc& b) { return !(a == b); }

// Định nghĩa phép nhập (>>)
std::istream& operator>>(std::istream& is, SoPhuc& sp) {
  std::cout << "  - Nhap phan thuc: ";
  is >> sp.thuc;
  std::cout << "  - Nhap phan ao: ";
  is >> sp.ao;
  return is;
}

// Định nghĩa phép xuất (<<)
std::ostream& operator<<(std::ostream& os, const SoPhuc& sp) {
  // Trường hợp 1: Cả thực và ảo đều bằng 0
  if (sp.thuc == 0 && sp.ao == 0) {
    os << 0;
    return os;
  }

  // Trường hợp 2: In phần thực (nếu có)
  if (sp.thuc != 0) {
    os << sp.thuc;
    // In dấu nối nếu phần ảo có tồn tại
    if (sp.ao > 0)
      os << " + ";
    else if (sp.ao < 0)
      os << " - ";
  } else {
    // Nếu không có phần thực mà phần ảo âm, phải in dấu trừ trước
    if (sp.ao < 0) os << "-";
  }

  // Trường hợp 3: In phần ảo (nếu có)
  double giaTriAo = std::abs(sp.ao);
  if (giaTriAo != 0) {
    // Nếu phần ảo khác 1 và -1 thì mới in con số ra
    if (giaTriAo != 1) {
      os << giaTriAo;
    }
    os << "i";
  }

  return os;
}