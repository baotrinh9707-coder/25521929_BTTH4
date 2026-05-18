#ifndef CVECTOR_H
#define CVECTOR_H

#include <iostream>

class CVector {
 private:
  int n;
  double* v;

 public:
  // Nhóm 1: Quản lý bộ nhớ (Big Three)
  CVector();
  CVector(int size);
  CVector(const CVector& other);
  ~CVector();

  CVector& operator=(const CVector& other);

  // Nhóm 2: Các phép toán Vector
  friend CVector operator+(const CVector& v1, const CVector& v2);
  friend CVector operator-(const CVector& v1, const CVector& v2);

  // Tích vô hướng (Vector * Vector = Số thực)
  friend double operator*(const CVector& v1, const CVector& v2);

  // Tích với một số thực (Vector * Số thực = Vector)
  friend CVector operator*(const CVector& vec, double k);
  friend CVector operator*(double k, const CVector& vec);

  // Nhóm 3: Nhập xuất
  friend std::istream& operator>>(std::istream& is, CVector& vec);
  friend std::ostream& operator<<(std::ostream& os, const CVector& vec);

  int getSize() const { return n; }
  double& operator[](int i) { return v[i]; }
  const double& operator[](int i) const { return v[i]; }
};

#endif