#pragma once
#include <ostream>
#include <iostream>
using namespace std;

#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
private:
    int integerPart;
    unsigned short fractionalPart;

public:
    // �����������
    Fraction(int integer = 0, unsigned short fractional = 0);

    // �������� ���������
    Fraction operator+(const Fraction& other) const;

    // �������� ��������
    Fraction operator-(const Fraction& other) const;

    // �������� ��������
    Fraction operator*(const Fraction& other) const;

    // �������� ��������� (>)
    bool operator>(const Fraction& other) const;

    // �������� ��������� (<)
    bool operator<(const Fraction& other) const;

    // ��������� ��������� �����
    friend ostream& operator<<(ostream& os, const Fraction& fraction);
};

#endif