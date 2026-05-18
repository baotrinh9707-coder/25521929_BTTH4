#ifndef CMATRIX_H
#define CMATRIX_H

#include <iostream>

#include "CVector.h"

class CMatrix {
 private:
  int rows;       // Số dòng
  int cols;       // Số cộtcd
  double** data;  // Con trỏ bậc 2 quản lý mảng động 2 chiều

 public:
  // Nhóm 1: Quản lý bộ nhớ (Big Three)
  CMatrix();
  CMatrix(int r, int c);
  CMatrix(const CMatrix& other);
  ~CMatrix();

  CMatrix& operator=(const CMatrix& other);

  // Nhóm 2: Các phép toán cơ bản
  friend CMatrix operator+(const CMatrix& m1, const CMatrix& m2);
  friend CMatrix operator-(const CMatrix& m1, const CMatrix& m2);

  // Phép nhân Ma trận với Ma trận
  friend CMatrix operator*(const CMatrix& m1, const CMatrix& m2);

  // Phép nhân Ma trận với Vector (Yêu cầu đặc biệt của đề)
  friend CVector operator*(const CMatrix& m, const CVector& v);

  // Nhóm 3: Nhập xuất
  friend std::istream& operator>>(std::istream& is, CMatrix& m);
  friend std::ostream& operator<<(std::ostream& os, const CMatrix& m);
};

#endif
