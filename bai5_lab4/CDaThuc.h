#ifndef CDATHUC_H
#define CDATHUC_H

#include <iostream>

class CDaThuc {
 private:
  int bac;       // Bậc của đa thức
  double* heSo;  // Mảng động chứa các hệ số (kích thước là bac + 1)

 public:
  // 1. Nhóm khởi tạo và hủy (Quan trọng nhất khi dùng mảng động)
  CDaThuc();                      // Mặc định
  CDaThuc(int b);                 // Khởi tạo với bậc b
  CDaThuc(const CDaThuc& other);  // Copy Constructor
  ~CDaThuc();                     // Destructor (Giải phóng bộ nhớ)

  // Toán tử gán (Assignment Operator)
  CDaThuc& operator=(const CDaThuc& other);

  // 2. Các phép toán cơ bản
  friend CDaThuc operator+(const CDaThuc& d1, const CDaThuc& d2);
  friend CDaThuc operator-(const CDaThuc& d1, const CDaThuc& d2);
  friend CDaThuc operator*(const CDaThuc& d1, const CDaThuc& d2);

  // 3. Nhập xuất
  friend std::istream& operator>>(std::istream& is, CDaThuc& d);
  friend std::ostream& operator<<(std::ostream& os, const CDaThuc& d);
};

#endif