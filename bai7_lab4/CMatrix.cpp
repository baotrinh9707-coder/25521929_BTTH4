#include "CMatrix.h"

#include <iomanip>  // Để in ma trận cho thẳng hàng

// === NHÓM 1: QUẢN LÝ BỘ NHỚ ===
CMatrix::CMatrix() : rows(0), cols(0), data(nullptr) {}

CMatrix::CMatrix(int r, int c) : rows(r), cols(c) {
  if (rows > 0 && cols > 0) {
    data = new double*[rows];  // Cấp phát mảng chứa các con trỏ dòng
    for (int i = 0; i < rows; ++i) {
      data[i] = new double[cols];  // Cấp phát từng ô trong dòng
      for (int j = 0; j < cols; ++j) {
        data[i][j] = 0;  // Khởi tạo bằng 0
      }
    }
  } else {
    data = nullptr;
  }
}

CMatrix::CMatrix(const CMatrix& other) : rows(other.rows), cols(other.cols) {
  if (rows > 0 && cols > 0) {
    data = new double*[rows];
    for (int i = 0; i < rows; ++i) {
      data[i] = new double[cols];
      for (int j = 0; j < cols; ++j) {
        data[i][j] = other.data[i][j];
      }
    }
  } else {
    data = nullptr;
  }
}

CMatrix::~CMatrix() {
  if (data != nullptr) {
    for (int i = 0; i < rows; ++i) {
      delete[] data[i];  // Xóa từng dòng
    }
    delete[] data;  // Xóa mảng quản lý dòng
  }
}

CMatrix& CMatrix::operator=(const CMatrix& other) {
  if (this != &other) {
    // Dọn dẹp nhà cũ
    if (data != nullptr) {
      for (int i = 0; i < rows; ++i) delete[] data[i];
      delete[] data;
    }
    // Xây nhà mới
    rows = other.rows;
    cols = other.cols;
    if (rows > 0 && cols > 0) {
      data = new double*[rows];
      for (int i = 0; i < rows; ++i) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; ++j) {
          data[i][j] = other.data[i][j];
        }
      }
    } else {
      data = nullptr;
    }
  }
  return *this;
}

// === NHÓM 2: PHÉP TOÁN ===
CMatrix operator+(const CMatrix& m1, const CMatrix& m2) {
  if (m1.rows != m2.rows || m1.cols != m2.cols) {
    std::cout << "\n[!] LOI: Khong the cong hai ma tran khac kich thuoc!\n";
    return CMatrix();
  }
  CMatrix kq(m1.rows, m1.cols);
  for (int i = 0; i < m1.rows; ++i)
    for (int j = 0; j < m1.cols; ++j)
      kq.data[i][j] = m1.data[i][j] + m2.data[i][j];
  return kq;
}

CMatrix operator-(const CMatrix& m1, const CMatrix& m2) {
  if (m1.rows != m2.rows || m1.cols != m2.cols) {
    std::cout << "\n[!] LOI: Khong the tru hai ma tran khac kich thuoc!\n";
    return CMatrix();
  }
  CMatrix kq(m1.rows, m1.cols);
  for (int i = 0; i < m1.rows; ++i)
    for (int j = 0; j < m1.cols; ++j)
      kq.data[i][j] = m1.data[i][j] - m2.data[i][j];
  return kq;
}

// Tích 2 Ma trận (Thuật toán vòng lặp 3 lớp)
CMatrix operator*(const CMatrix& m1, const CMatrix& m2) {
  // Điều kiện: Số cột M1 phải bằng số dòng M2
  if (m1.cols != m2.rows) {
    std::cout
        << "\n[!] LOI: So cot cua ma tran 1 phai bang so dong cua ma tran 2!\n";
    return CMatrix();
  }
  CMatrix kq(m1.rows, m2.cols);
  for (int i = 0; i < m1.rows; ++i) {
    for (int j = 0; j < m2.cols; ++j) {
      kq.data[i][j] = 0;
      for (int k = 0; k < m1.cols; ++k) {
        kq.data[i][j] += m1.data[i][k] * m2.data[k][j];
      }
    }
  }
  return kq;
}

// Tích Ma trận và Vector (Trả về một Vector)
CVector operator*(const CMatrix& m, const CVector& v) {
  // Điều kiện: Số cột của Ma trận phải bằng số chiều của Vector
  if (m.cols != v.getSize()) {
    std::cout
        << "\n[!] LOI: So cot ma tran phai bang so chieu vector de nhan!\n";
    return CVector();
  }
  CVector kq(m.rows);  // Kết quả là vector có số chiều = số dòng của ma trận
  for (int i = 0; i < m.rows; ++i) {
    double sum = 0;
    for (int j = 0; j < m.cols; ++j) {
      sum += m.data[i][j] * v[j];  // Dùng operator[] vừa nâng cấp
    }
    kq[i] = sum;  // Lưu vào vector kết quả
  }
  return kq;
}

// === NHÓM 3: NHẬP XUẤT ===
std::istream& operator>>(std::istream& is, CMatrix& m) {
  int r, c;
  do {
    std::cout << "  - Nhap so dong r (>0): ";
    is >> r;
    std::cout << "  - Nhap so cot c (>0): ";
    is >> c;
    if (r <= 0 || c <= 0) std::cout << "    [!] Kich thuoc phai lon hon 0!\n";
  } while (r <= 0 || c <= 0);

  CMatrix temp(r, c);
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      std::cout << "    + Nhap phan tu [" << i << "][" << j << "]: ";
      is >> temp.data[i][j];
    }
  }
  m = temp;
  return is;
}

std::ostream& operator<<(std::ostream& os, const CMatrix& m) {
  if (m.rows == 0 || m.cols == 0) {
    os << "(Ma tran rong)\n";
    return os;
  }
  os << "\n";
  for (int i = 0; i < m.rows; ++i) {
    os << "    | ";
    for (int j = 0; j < m.cols; ++j) {
      double val = m.data[i][j];
      if (val == 0) val = 0;
      os << std::setw(6) << val
         << " ";  // Setw(6) để in cho cột thẳng tắp đẹp mắt
    }
    os << "|\n";
  }
  return os;
}