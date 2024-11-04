#include <iostream>
#include <cmath>
#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(double r_, double i_) : r(r_), i(i_) {}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& other) const {
	return ComplexNumber(r + other.r,i + other.i);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& other) const {
	return ComplexNumber(r - other.r, i- other.i);
}

ComplexNumber ComplexNumber::operator*(double cnst) const {
	return ComplexNumber(r * cnst, i *cnst);
}

double ComplexNumber::abs() const {
	return sqrt(r * r + i * i);
}

void ComplexNumber::print() const {
	std::cout << "(" << r << "+" << i << "i)" << std::endl;
}
