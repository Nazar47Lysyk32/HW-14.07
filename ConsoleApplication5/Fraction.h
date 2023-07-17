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
    // Конструктор
    Fraction(int integer = 0, unsigned short fractional = 0);

    // Оператор додавання
    Fraction operator+(const Fraction& other) const;

    // Оператор віднімання
    Fraction operator-(const Fraction& other) const;

    // Оператор множення
    Fraction operator*(const Fraction& other) const;

    // Оператор порівняння (>)
    bool operator>(const Fraction& other) const;

    // Оператор порівняння (<)
    bool operator<(const Fraction& other) const;

    // Виведення дробового числа
    friend ostream& operator<<(ostream& os, const Fraction& fraction);
};

#endif