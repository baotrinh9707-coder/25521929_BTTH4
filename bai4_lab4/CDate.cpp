#include "CDate.h"

#include <cmath>  // Để dùng hàm abs()
#include <iomanip>

// Kiểm tra năm nhuận (Chia hết cho 400, hoặc chia hết cho 4 nhưng không chia
// hết cho 100)
bool CDate::isLeapYear(int y) const {
  return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

// Lấy số ngày tối đa của 1 tháng
int CDate::daysInMonth(int m, int y) const {
  int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (m == 2 && isLeapYear(y)) {
    return 29;
  }
  return days[m];
}

// Chuyển đổi ngày hiện tại thành tổng số ngày tính từ 01/01/0001
int CDate::toAbsoluteDays() const {
  int total = day;
  for (int m = 1; m < month; ++m) {
    total += daysInMonth(m, year);
  }
  for (int y = 1; y < year; ++y) {
    total += isLeapYear(y) ? 366 : 365;
  }
  return total;
}

void CDate::chuanHoa() {
  // Nếu số ngày quá lớn, tiến lên tháng/năm sau
  while (day > daysInMonth(month, year)) {
    day -= daysInMonth(month, year);
    month++;
    if (month > 12) {
      month = 1;
      year++;
    }
  }
  // Nếu số ngày bị âm/bằng 0, lùi về tháng/năm trước
  while (day <= 0) {
    month--;
    if (month < 1) {
      month = 12;
      year--;
    }
    day += daysInMonth(month, year);
  }
}

CDate::CDate(int d, int m, int y) : day(d), month(m), year(y) { chuanHoa(); }

CDate operator+(const CDate& date, int days) {
  CDate temp = date;
  temp.day += days;
  temp.chuanHoa();
  return temp;
}

CDate operator-(const CDate& date, int days) {
  CDate temp = date;
  temp.day -= days;
  temp.chuanHoa();
  return temp;
}

int operator-(const CDate& d1, const CDate& d2) {
  return d1.toAbsoluteDays() - d2.toAbsoluteDays();
}

CDate& CDate::operator++() {
  day++;
  chuanHoa();
  return *this;
}
CDate CDate::operator++(int) {
  CDate temp = *this;
  day++;
  chuanHoa();
  return temp;
}
CDate& CDate::operator--() {
  day--;
  chuanHoa();
  return *this;
}
CDate CDate::operator--(int) {
  CDate temp = *this;
  day--;
  chuanHoa();
  return temp;
}

std::istream& operator>>(std::istream& is, CDate& date) {
  bool hopLe = false;
  do {
    std::cout << "  - Nhap ngay  : ";
    is >> date.day;
    std::cout << "  - Nhap thang : ";
    is >> date.month;
    std::cout << "  - Nhap nam   : ";
    is >> date.year;

    // 1. Kiểm tra năm và tháng trước để tránh lỗi tràn mảng days[]
    if (date.year > 0 && date.month >= 1 && date.month <= 12) {
      // 2. Nếu tháng hợp lệ, mới bắt đầu kiểm tra ngày xem có lố không
      if (date.day >= 1 &&
          date.day <= date.daysInMonth(date.month, date.year)) {
        hopLe = true;  // Vượt qua bài test, thoát vòng lặp!
      } else {
        std::cout << "  [!] LOI: Thang " << date.month << " chi co toi da "
                  << date.daysInMonth(date.month, date.year)
                  << " ngay. Vui long nhap lai!\n\n";
      }
    } else {
      std::cout << "  [!] LOI: Thang phai tu 1 den 12 va Nam phai > 0. Vui "
                   "long nhap lai!\n\n";
    }
  } while (!hopLe);

  return is;
}

std::ostream& operator<<(std::ostream& os, const CDate& date) {
  os << std::setfill('0') << std::setw(2) << date.day << "/"
     << std::setfill('0') << std::setw(2) << date.month << "/" << date.year;
  return os;
}