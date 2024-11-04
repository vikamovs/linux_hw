#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

class ComplexNumber
{
private:
	double r;
	double i;
public:
	ComplexNumber(double r_ = 0.0, double i_ = 0.0);
	ComplexNumber operator+(const ComplexNumber& other) const;
	ComplexNumber operator-(const ComplexNumber& other) const;
	ComplexNumber operator*(double cnst) const;
	double abs() const;
	void print() const;
};

#endif
