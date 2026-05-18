#ifndef CDATE_H
#define CDATE_H

#include <iostream>

class CDate {
 private:
  int day;
  int month;
  int year;

  // Các hàm công cụ "giấu kín" không cho bên ngoài thấy
  bool isLeapYear(int y) const;
  int daysInMonth(int m, int y) const;
  int toAbsoluteDays() const;  // Tính tổng số ngày từ năm 1 công nguyên
  void chuanHoa();  // Tự động nhảy ngày/tháng/năm nếu bị tràn hoặc âm

 public:
  CDate(int d = 1, int m = 1, int y = 2026);

  // Cộng/Trừ với một số ngày (int)
  friend CDate operator+(const CDate& date, int days);
  friend CDate operator-(const CDate& date, int days);

  // Tăng/Giảm 1 ngày
  CDate& operator++();    // Tiền tố
  CDate operator++(int);  // Hậu tố
  CDate& operator--();
  CDate operator--(int);

  // Khoảng cách giữa 2 ngày (Trả về số nguyên)
  friend int operator-(const CDate& d1, const CDate& d2);

  friend std::istream& operator>>(std::istream& is, CDate& date);
  friend std::ostream& operator<<(std::ostream& os, const CDate& date);
};

#endif