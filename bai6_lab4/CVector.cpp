#include "CVector.h"

// === NHÓM 1: QUẢN LÝ BỘ NHỚ ===
CVector::CVector() : n(0), v(nullptr) {}

CVector::CVector(int size) : n(size) {
  if (n > 0) {
    v = new double[n];
    for (int i = 0; i < n; ++i) v[i] = 0;
  } else {
    v = nullptr;
  }
}

CVector::CVector(const CVector& other) : n(other.n) {
  if (n > 0) {
    v = new double[n];
    for (int i = 0; i < n; ++i) v[i] = other.v[i];
  } else {
    v = nullptr;
  }
}

CVector::~CVector() { delete[] v; }

CVector& CVector::operator=(const CVector& other) {
  if (this != &other) {
    delete[] v;  // Xóa mảng cũ
    n = other.n;
    if (n > 0) {
      v = new double[n];
      for (int i = 0; i < n; ++i) v[i] = other.v[i];
    } else {
      v = nullptr;
    }
  }
  return *this;
}

// === NHÓM 2: CÁC PHÉP TOÁN ===
CVector operator+(const CVector& v1, const CVector& v2) {
  if (v1.n != v2.n) {
    std::cout << "\n[!] LOI: Khong the cong hai vector khac so chieu!\n";
    return CVector();  // Trả về vector rỗng
  }
  CVector kq(v1.n);
  for (int i = 0; i < v1.n; ++i) {
    kq.v[i] = v1.v[i] + v2.v[i];
  }
  return kq;
}

CVector operator-(const CVector& v1, const CVector& v2) {
  if (v1.n != v2.n) {
    std::cout << "\n[!] LOI: Khong the tru hai vector khac so chieu!\n";
    return CVector();
  }
  CVector kq(v1.n);
  for (int i = 0; i < v1.n; ++i) {
    kq.v[i] = v1.v[i] - v2.v[i];
  }
  return kq;
}

// Tích vô hướng
double operator*(const CVector& v1, const CVector& v2) {
  if (v1.n != v2.n) {
    std::cout
        << "\n[!] LOI: Khong the nhan vo huong hai vector khac so chieu!\n";
    return 0;
  }
  double kq = 0;
  for (int i = 0; i < v1.n; ++i) {
    kq += v1.v[i] * v2.v[i];
  }
  return kq;
}

// Nhân vector với số thực (v * k)
CVector operator*(const CVector& vec, double k) {
  CVector kq(vec.n);
  for (int i = 0; i < vec.n; ++i) {
    kq.v[i] = vec.v[i] * k;
  }
  return kq;
}

// Nhân số thực với vector (k * v) - Tính chất giao hoán
CVector operator*(double k, const CVector& vec) { return vec * k; }

// === NHÓM 3: NHẬP XUẤT ===
std::istream& operator>>(std::istream& is, CVector& vec) {
  int size;
  do {
    std::cout << "  - Nhap so chieu cua vector (n > 0): ";
    is >> size;
    if (size <= 0)
      std::cout << "    [!] So chieu phai lon hon 0. Vui long nhap lai!\n";
  } while (size <= 0);

  CVector temp(size);
  for (int i = 0; i < size; ++i) {
    std::cout << "    + Nhap toa do thu " << i + 1 << ": ";
    is >> temp.v[i];
  }
  vec = temp;  // Dùng toán tử gán
  return is;
}
std::ostream& operator<<(std::ostream& os, const CVector& vec) {
  if (vec.n == 0) {
    os << "(Rong)";
    return os;
  }
  os << "(";
  for (int i = 0; i < vec.n; ++i) {
    double val = vec.v[i];
    if (val == 0)
      val =
          0;  // THẦN CHÚ KHỬ -0: Vì -0 == 0 là True, nên nó sẽ gán lại thành +0

    os << val;

    if (i < vec.n - 1) os << ", ";
  }
  os << ")";
  return os;
}