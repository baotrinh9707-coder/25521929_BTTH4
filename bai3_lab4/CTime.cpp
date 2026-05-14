#include "CTime.h"

#include <bits/stdc++.h>
using namespace std;

void CTime::chuanHoa() {
  long long tongGiay = (long long)hour * 3600 + minute * 60 + second;
  tongGiay = (tongGiay % 86400 + 86400) % 86400;
  hour = tongGiay / 3600;
  minute = (tongGiay % 3600) / 60;
  second = tongGiay % 60;
}

CTime::CTime(int h, int m, int s) : hour(h), minute(m), second(s) {
  chuanHoa();
}

// Cộng/Trừ số nguyên giây
CTime operator+(const CTime& t, int s) {
  return CTime(t.hour, t.minute, t.second + s);
}
CTime operator-(const CTime& t, int s) {
  return CTime(t.hour, t.minute, t.second - s);
}

// Toán tử ++ (Tiền tố)
CTime& CTime::operator++() {
  second++;
  chuanHoa();
  return *this;
}
// Toán tử ++ (Hậu tố)
CTime CTime::operator++(int) {
  CTime temp = *this;
  second++;
  chuanHoa();
  return temp;
}

// Toán tử -- (Tiền tố)
CTime& CTime::operator--() {
  second--;
  chuanHoa();
  return *this;
}
// Toán tử -- (Hậu tố)
CTime CTime::operator--(int) {
  CTime temp = *this;
  second--;
  chuanHoa();
  return temp;
}

std::istream& operator>>(std::istream& is, CTime& t) {
  int h, m, s;
  bool hopLe = false;

  while (!hopLe) {
    std::cout << "  - Gio (0-23): ";
    is >> h;
    std::cout << "  - Phut (0-59): ";
    is >> m;
    std::cout << "  - Giay (0-59): ";
    is >> s;

    if (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60) {
      t.hour = h;
      t.minute = m;
      t.second = s;
      hopLe = true;
    } else {
      std::cout << "=> Du lieu khong hop le! Vui long nhap lai.\n";
    }
  }
  return is;
}

std::ostream& operator<<(std::ostream& os, const CTime& t) {
  os << std::setfill('0') << std::setw(2) << t.hour << ":" << std::setfill('0')
     << std::setw(2) << t.minute << ":" << std::setfill('0') << std::setw(2)
     << t.second;
  return os;
}

void CTime::runClock() const {
  CTime dongHo = *this;
  while (true) {
    std::cout << "\033[s\033[1;70H" << "[ DONG HO: " << dongHo++ << " ]"
              << "\033[u" << std::flush;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}