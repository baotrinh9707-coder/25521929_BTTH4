#ifndef SOPHUC_H
#define SOPHUC_H

#include <iostream>

class SoPhuc {
private:
    double thuc;
    double ao;

public:
    SoPhuc(double t = 0, double a = 0);

    // Khai báo các phép toán (dùng hàm bạn - friend function)
    friend SoPhuc operator+(const SoPhuc& a, const SoPhuc& b);
    friend SoPhuc operator-(const SoPhuc& a, const SoPhuc& b);
    friend SoPhuc operator*(const SoPhuc& a, const SoPhuc& b);
    friend SoPhuc operator/(const SoPhuc& a, const SoPhuc& b);

    // Khai báo các phép so sánh
    friend bool operator==(const SoPhuc& a, const SoPhuc& b);
    friend bool operator!=(const SoPhuc& a, const SoPhuc& b);

    // Khai báo phép nhập/xuất
    friend std::istream& operator>>(std::istream& is, SoPhuc& sp);
    friend std::ostream& operator<<(std::ostream& os, const SoPhuc& sp);
};

#endif