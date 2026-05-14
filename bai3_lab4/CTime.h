#ifndef CTIME_H
#define CTIME_H

#include <bits/stdc++.h>

class CTime {
 private:
  int hour, minute, second;
  void chuanHoa();

 public:
  CTime(int h = 0, int m = 0, int s = 0);

  // Cộng/Trừ với một số nguyên giây
  friend CTime operator+(const CTime& t, int s);
  friend CTime operator-(const CTime& t, int s);

  // Toán tử ++, -- (thêm/bớt 1 giây)
  CTime& operator++();    // Tiền tố: ++t
  CTime operator++(int);  // Hậu tố: t++
  CTime& operator--();    // Tiền tố: --t
  CTime operator--(int);  // Hậu tố: t--

  friend std::istream& operator>>(std::istream& is, CTime& t);
  friend std::ostream& operator<<(std::ostream& os, const CTime& t);

  void runClock() const;
};

#endif