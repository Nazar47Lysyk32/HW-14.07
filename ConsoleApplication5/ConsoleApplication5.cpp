#include <iostream>
#include <ostream>
#include "fraction.h"
using namespace std;




// Конструктор
Fraction::Fraction(int integer, unsigned short fractional)
    : integerPart(integer), fractionalPart(fractional) {}

// Оператор додавання
Fraction Fraction::operator+(const Fraction& other) const {
    int newInteger = integerPart + other.integerPart;
    unsigned short newFractional = fractionalPart + other.fractionalPart;

    if (newFractional > 9999) {
        newInteger += 1;
        newFractional -= 10000;
    }

    return Fraction(newInteger, newFractional);
}

// Оператор віднімання
Fraction Fraction::operator-(const Fraction& other) const {
    int newInteger = integerPart - other.integerPart;
    unsigned short newFractional = fractionalPart - other.fractionalPart;

    if (fractionalPart < other.fractionalPart) {
        newInteger -= 1;
        newFractional += 10000;
    }

    return Fraction(newInteger, newFractional);
}

// Оператор множення
Fraction Fraction::operator*(const Fraction& other) const {
    int newInteger = integerPart * other.integerPart;
    unsigned long long product = (static_cast<unsigned long long>(fractionalPart) * static_cast<unsigned long long>(other.fractionalPart)) / 10000;
    unsigned short newFractional = static_cast<unsigned short>(product);

    return Fraction(newInteger, newFractional);
}

// Оператор порівняння (>)
bool Fraction::operator>(const Fraction& other) const {
    double thisValue = static_cast<double>(integerPart) + (static_cast<double>(fractionalPart) / 10000);
    double otherValue = static_cast<double>(other.integerPart) + (static_cast<double>(other.fractionalPart) / 10000);

    return thisValue > otherValue;
}

// Оператор порівняння (<)
bool Fraction::operator<(const Fraction& other) const {
    double thisValue = static_cast<double>(integerPart) + (static_cast<double>(fractionalPart) / 10000);
    double otherValue = static_cast<double>(other.integerPart) + (static_cast<double>(other.fractionalPart) / 10000);

    return thisValue < otherValue;
}

// Виведення дробового числа
    ostream& operator<<(ostream& os, const Fraction& fraction) {
    os << fraction.integerPart << '.' << fraction.fractionalPart;
    return os;
}


int main() {
    Fraction f1(2, 5000);
    Fraction f2(1, 3000);

    Fraction sum = f1 + f2;
    Fraction difference = f1 - f2;
    Fraction product = f1 * f2;

    cout << "f1: " << f1 << endl;
    cout << "f2: " << f2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << difference << endl;
    cout << "Product: " << product << endl;

    if (f1 > f2) {
        cout << "f1 is greater than f2" << endl;
    }
    else if (f1 < f2) {
        cout << "f1 is less than f2" << endl;
    }
    else {
        cout << "f1 is equal to f2" << endl;
    }

    return 0;
}