#include "CDaThuc.h"

#include <algorithm>  // Để dùng std::max
#include <cmath>

// === NHÓM 1: QUẢN LÝ BỘ NHỚ ===
CDaThuc::CDaThuc() {
  bac = 0;
  heSo = new double[1];
  heSo[0] = 0;
}

CDaThuc::CDaThuc(int b) {
  bac = b;
  heSo = new double[bac + 1];
  for (int i = 0; i <= bac; i++) heSo[i] = 0;
}

CDaThuc::CDaThuc(const CDaThuc& other) {
  bac = other.bac;
  heSo = new double[bac + 1];
  for (int i = 0; i <= bac; i++) heSo[i] = other.heSo[i];
}

CDaThuc::~CDaThuc() {
  delete[] heSo;  // Xóa mảng động để chống Memory Leak
}

CDaThuc& CDaThuc::operator=(const CDaThuc& other) {
  if (this != &other) {
    delete[] heSo;  // Vứt cái cũ đi
    bac = other.bac;
    heSo = new double[bac + 1];  // Cấp phát cái mới
    for (int i = 0; i <= bac; i++) heSo[i] = other.heSo[i];
  }
  return *this;
}

// === NHÓM 2: PHÉP TOÁN ===
CDaThuc operator+(const CDaThuc& d1, const CDaThuc& d2) {
  int maxBac = std::max(d1.bac, d2.bac);
  CDaThuc kq(maxBac);
  for (int i = 0; i <= maxBac; i++) {
    double heSo1 = (i <= d1.bac) ? d1.heSo[i] : 0;
    double heSo2 = (i <= d2.bac) ? d2.heSo[i] : 0;
    kq.heSo[i] = heSo1 + heSo2;
  }
  return kq;
}

CDaThuc operator-(const CDaThuc& d1, const CDaThuc& d2) {
  int maxBac = std::max(d1.bac, d2.bac);
  CDaThuc kq(maxBac);
  for (int i = 0; i <= maxBac; i++) {
    double heSo1 = (i <= d1.bac) ? d1.heSo[i] : 0;
    double heSo2 = (i <= d2.bac) ? d2.heSo[i] : 0;
    kq.heSo[i] = heSo1 - heSo2;
  }
  return kq;
}

CDaThuc operator*(const CDaThuc& d1, const CDaThuc& d2) {
  CDaThuc kq(d1.bac + d2.bac);  // Bậc kết quả = tổng 2 bậc
  for (int i = 0; i <= d1.bac; i++) {
    for (int j = 0; j <= d2.bac; j++) {
      kq.heSo[i + j] += d1.heSo[i] * d2.heSo[j];
    }
  }
  return kq;
}

// === NHÓM 3: NHẬP XUẤT ===
std::istream& operator>>(std::istream& is, CDaThuc& d) {
  std::cout << "  - Nhap bac cua da thuc: ";
  int b;
  is >> b;

  // Nếu bậc thay đổi, phải cấp phát lại bộ nhớ
  CDaThuc temp(b);
  for (int i = temp.bac; i >= 0; i--) {
    std::cout << "  - He so cua x^" << i << ": ";
    is >> temp.heSo[i];
  }
  d = temp;  // Dùng toán tử gán đã định nghĩa ở trên
  return is;
}

std::ostream& operator<<(std::ostream& os, const CDaThuc& d) {
  bool isAllZero = true;
  bool isFirst = true;

  for (int i = d.bac; i >= 0; i--) {
    if (d.heSo[i] == 0) continue;  // Bỏ qua hệ số 0

    isAllZero = false;

    // Xử lý dấu
    if (isFirst) {
      if (d.heSo[i] < 0) os << "-";
    } else {
      os << (d.heSo[i] > 0 ? " + " : " - ");
    }
    isFirst = false;

    // Xử lý con số (không in số 1 trừ khi là bậc 0)
    double val = std::abs(d.heSo[i]);
    if (val != 1 || i == 0) {
      os << val;
    }

    // Xử lý biến x và mũ
    if (i > 0) {
      os << "x";
      if (i > 1) os << "^" << i;
    }
  }

  if (isAllZero) os << "0";
  return os;
}